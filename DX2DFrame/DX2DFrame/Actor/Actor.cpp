#include "Actor.h"

Actor::Actor(IWorld* world, const Vector2& position):world_(world),position_(position)
{
}

Actor::~Actor()
{
	world_ = nullptr;
}

void Actor::initialize()
{
	isDead_ = false;
}

void Actor::update(float deltaTime)
{
}

void Actor::draw() const
{
}

bool Actor::isDead() const
{
	return isDead_;
}
