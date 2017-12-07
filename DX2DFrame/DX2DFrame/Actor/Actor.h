#pragma once
#include"../Math/Vector2.h"
#include"../World/IWorld.h"

//�S�L�����N�^�[�̊��N���X
class Actor {
public:
	//�R���X�g���N�^
	Actor(IWorld* world,const Vector2& position);
	//�f�X�g���N�^
	~Actor();
	//������
	virtual	void initialize();
	//�X�V
	virtual void update(float deltaTime);
	//�`��
	virtual void draw()const;
	//����ł邩
	bool isDead()const;
protected:
	IWorld* world_;
	Vector2 position_{ Vector2::Zero };//�ʒu
	bool isDead_{ false };//���S
};