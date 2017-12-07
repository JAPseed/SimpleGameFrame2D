#pragma once
#include"../Actor/ActorPtr.h"

enum class ActorGroup;
class IWorld {
public:
	virtual ~IWorld(){}
	// �A�N�^�[�̒ǉ�
	virtual void addActor(ActorGroup group, const ActorPtr& actor) = 0;

};