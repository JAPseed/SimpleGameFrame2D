#include "ActorManager.h"
#include"ActorGroup.h"
#include"Actor.h"

ActorManager::ActorManager()
{
	initialize();
}

void ActorManager::initialize()
{
	actors_.clear();
	actors_[ActorGroup::PLAYER_ACTOR] = std::list<ActorPtr>();

}

void ActorManager::update(float deltaTime)
{
	for (auto& a : actors_) {
		for (auto& ap : a.second) {
			ap->update(deltaTime);
		}
	}

	for (auto& a : actors_) {
		a.second.remove_if([](ActorPtr& a) {return a->isDead(); });
	}

}

void ActorManager::draw() const
{
	for (auto& a : actors_) {
		for (auto& ap : a.second) {
			ap->draw();
		}
	}

}

void ActorManager::addActor(ActorGroup group, const ActorPtr & actor)
{
	actors_[group].push_back(actor);
	actor->initialize();
}
