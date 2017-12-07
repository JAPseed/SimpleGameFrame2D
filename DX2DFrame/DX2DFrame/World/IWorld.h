#pragma once
#include"../Actor/ActorPtr.h"

enum class ActorGroup;
class IWorld {
public:
	virtual ~IWorld(){}
	// アクターの追加
	virtual void addActor(ActorGroup group, const ActorPtr& actor) = 0;

};