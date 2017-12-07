#pragma once
#include"ActorPtr.h"
#include<map>
#include<list>

enum class ActorGroup;
class ActorManager {
public:
	ActorManager();

	// ������
	void initialize();
	// �X�V
	void update(float deltaTime);
	// �`��
	void draw() const;
	// �A�N�^�[�̒ǉ�
	void addActor(ActorGroup group, const ActorPtr& actor);
	// �R�s�[�֎~
	ActorManager(const ActorManager& other) = delete;
	ActorManager& operator = (const ActorManager& other) = delete;
private:
	//�A�N�^�[�ꗗ
	std::map<ActorGroup, std::list<ActorPtr>> actors_;
};