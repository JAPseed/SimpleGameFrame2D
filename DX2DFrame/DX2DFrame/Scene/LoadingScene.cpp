#include "LoadingScene.h"
#include<string>
#include"../Graphic/Sprite.h"

LoadingScene::LoadingScene() {
	next_ = SceneType::SCENE_GAMEPLAY;
}

void LoadingScene::start() {
	//�e�탊�\�[�X�̃��[�h���s��
	LoadSprite();
	isEnd_ = true;
}

void LoadingScene::update(float deltaTime) {

}

void LoadingScene::draw() const {

}

void LoadingScene::end() {

}

void LoadingScene::LoadSprite()
{
	std::string defaultPath = "res/Sprite/";//�S���\�[�X���ʃp�X
	Sprite::GetInstance().Load(defaultPath + "player.png", SPRITE_ID::PLAYER_SPRITE);
}
