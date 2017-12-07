#include "World.h"

World::World(){
	initialize();
}

World::~World(){

}

void World::initialize(){
	manager_.initialize();
}

void World::update(float deltaTime){
	manager_.update(deltaTime);
}

void World::draw() const{
	manager_.draw();
}

void World::addActor(ActorGroup group, const ActorPtr & actor)
{
	manager_.addActor(group, actor);
}
