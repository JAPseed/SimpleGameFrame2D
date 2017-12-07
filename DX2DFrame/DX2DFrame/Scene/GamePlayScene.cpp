#include "GamePlayScene.h"
#include"../Actor/ActorGroup.h"
#include"../Actor/Player.h"

//コンストラクタ
GamePlayScene::GamePlayScene() :world_{} {
}

//開始
void GamePlayScene::start() {
	world_.initialize();

	world_.addActor(ActorGroup::PLAYER_ACTOR, std::make_shared<Player>(&world_, Vector2{ 50.f,300.f }));
}

//更新
void GamePlayScene::update(float deltaTime) {
	world_.update(deltaTime);
}

//描画
void GamePlayScene::draw() const {
	world_.draw();
}

//終了
void GamePlayScene::end() {
}

