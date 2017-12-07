#include "GamePlayScene.h"
#include"../Actor/ActorGroup.h"
#include"../Actor/Player.h"

//�R���X�g���N�^
GamePlayScene::GamePlayScene() :world_{} {
}

//�J�n
void GamePlayScene::start() {
	world_.initialize();

	world_.addActor(ActorGroup::PLAYER_ACTOR, std::make_shared<Player>(&world_, Vector2{ 50.f,300.f }));
}

//�X�V
void GamePlayScene::update(float deltaTime) {
	world_.update(deltaTime);
}

//�`��
void GamePlayScene::draw() const {
	world_.draw();
}

//�I��
void GamePlayScene::end() {
}

