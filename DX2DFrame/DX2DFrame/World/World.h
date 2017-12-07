#pragma once
#include"IWorld.h"
#include"../Actor/ActorManager.h"

//Actor���Ǘ�����N���X
class World :public IWorld {
public:
	World();
	~World();

	void initialize();
	void update(float deltaTime);
	void draw()const;

	virtual void addActor(ActorGroup group, const ActorPtr& actor) override;

private:
	ActorManager manager_;
};