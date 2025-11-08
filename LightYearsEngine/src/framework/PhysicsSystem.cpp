#include <box2d/b2_body.h>
#include <box2d/b2_contact.h>
#include <box2d/b2_fixture.h>
#include <box2d/b2_polygon_shape.h>
#include "framework/PhysicsSystem.h"
#include "framework/Actor.h"
#include "framework/MathUtility.h"
namespace LightYears
{
	unique<PhysicsSystem> PhysicsSystem::physicsSystem{ nullptr };

	PhysicsSystem& PhysicsSystem::get()
	{
		if (!physicsSystem)
		{
			physicsSystem = std::move(unique<PhysicsSystem> {new PhysicsSystem});
		}
		return *physicsSystem;
	}
	//equivalent of the update function for box2d
	void PhysicsSystem::step(float deltaTime)
	{
		mPhysicsWorld.Step(deltaTime, mVelocityIterations, mPositionIterations);
	}
	b2Body* PhysicsSystem::addListener(Actor* listener)
	{
		if (listener->isPendingDestroy())
			return nullptr;

		b2BodyDef bodyDef;
		bodyDef.type = b2_dynamicBody;
		// this pointer points to the listener or the owner of this body definition(in this case the actor that's been passed to this function)
		bodyDef.userData.pointer = reinterpret_cast<uintptr_t>(listener);
		bodyDef.position.Set(listener->getActorLocation().x * getPhysicsScale(), listener->getActorLocation().y* getPhysicsScale());
		bodyDef.angle = DegreesToRadians(listener->getActorRotation());

		b2Body* body = mPhysicsWorld.CreateBody(&bodyDef);
		b2PolygonShape shape;
		auto bounds = listener->getActorGlobalBounds();
		shape.SetAsBox(bounds.width/2.0 * getPhysicsScale(), bounds.height / 2.0 * getPhysicsScale());
		
		b2FixtureDef fixtureDef;
		fixtureDef.shape = &shape;
		fixtureDef.density = 1.0f;
		fixtureDef.friction = 0.3f;
		fixtureDef.isSensor = true;
		body->CreateFixture(&fixtureDef);

		return body;
	}
	void PhysicsSystem::removeListener(b2Body* bodyToRemove)
	{
		//TODO: implement removal of body
	}
	float PhysicsSystem::getPhysicsScale()
	{
		return mPhysicsScale;
	}
	PhysicsSystem::PhysicsSystem():
		mPhysicsWorld{b2Vec2{0.f,0.f}},
		mPhysicsScale {0.01f},
		mVelocityIterations{8},
		mPositionIterations{3},
		mContactListener{}
	{
		mPhysicsWorld.SetContactListener(&mContactListener);
		mPhysicsWorld.SetAllowSleeping(false);
	}
	void PhysicsContactListener::BeginContact(b2Contact* contact)
	{
		Actor* ActorA = reinterpret_cast<Actor*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
		Actor* ActorB = reinterpret_cast<Actor*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);
		
		if (ActorA && !ActorA->isPendingDestroy())
			ActorA->onActorBeginOverlap(ActorB);

		if (ActorB && !ActorB->isPendingDestroy())
			ActorB->onActorBeginOverlap(ActorA);

		
	}
	void PhysicsContactListener::EndContact(b2Contact* contact)
	{
		Actor* ActorA = nullptr;
		Actor* ActorB = nullptr;
		//since this is the end overlap there is a chance the body is destroyed according to the game logic so we will first check if the body is still there
		if(contact->GetFixtureA() && contact->GetFixtureA()->GetBody())
			ActorA = reinterpret_cast<Actor*>(contact->GetFixtureA()->GetBody()->GetUserData().pointer);
		if(contact->GetFixtureB() && contact->GetFixtureB()->GetBody())
			ActorB = reinterpret_cast<Actor*>(contact->GetFixtureB()->GetBody()->GetUserData().pointer);
		
		if (ActorA && !ActorA->isPendingDestroy())
			ActorA->onActorEndOverlap(ActorB);

		if (ActorB && !ActorB->isPendingDestroy())
			ActorB->onActorEndOverlap(ActorA);
	}
}