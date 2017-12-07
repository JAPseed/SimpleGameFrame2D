#pragma once
#include"Actor.h"

class Player:public Actor{
public:
	Player(IWorld* world,const Vector2& position);
	~Player();

	virtual void initialize()override;
	virtual void update(float deltaTime)override;
	virtual void draw()const override;
};
