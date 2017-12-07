#pragma once
#include<DxLib.h>

#include"../Scene/SceneManager.h"
#include"Define.h"
#include"../Input/Keyboard.h"
#include"../Graphic/Sprite.h"

class MyGame {
public:
	// �R���X�g���N�^
	MyGame(int x=WINDOW_WIDTH,int y=WINDOW_HEIGHT, float rate = 1.0f, int window = TRUE, float fps = 60.0f) :
		mWidth(x), mHeight(y), mRate(rate), mWindow(window), mFps(fps), sceneManager_() {
	}
	~MyGame() {}
public:
	// ���s
	int run() {
		// �T�C�Y�w��
		SetGraphMode(mWidth, mHeight, 32);
		// �`��{��
		SetWindowSizeExtendRate(mRate);
		// �E�C���h�E���[�h�ɂ��邩�ǂ���
		ChangeWindowMode(mWindow);
		SetUseDirect3DVersion(DX_DIRECT3D_9);
		//DXLib����������
		if (DxLib_Init() == -1)return -1;//�G���[���N������I��
		SetDrawScreen(DX_SCREEN_BACK);
		SetUseBackCulling(TRUE);

		start();

		// �L�[���������܂Ń��[�v���܂�
		while (isRunning()) {
			update();
			draw();
			frameEnd();
			//Time::GetInstance().draw_fps();
			// ����ʂ̓��e��\��ʂɔ��f������
			ScreenFlip();
		}

		end();

		//DXLib�g�p�I������
		DxLib_End();

		return 0;	//�\�t�g�I��
	}

private:
	// �J�n
	void start() {
		Sprite::GetInstance().Initialize();
		sceneManager_.start();
	}
	// �X�V
	void update() {
		Keyboard::GetInstance().Update();
		sceneManager_.update(1.0f);
	}
	// �`��
	void draw() {
		sceneManager_.draw();
	}
	//�t���[���I��������
	void frameEnd() {
		sceneManager_.checkIsEnd();
	}
	// �I��
	void end() {

	}
	// ���s����
	bool isRunning() { return (ProcessMessage() == 0 && ClearDrawScreen() == 0); }

	// �R�s�[�֎~
	MyGame(const MyGame& other) = delete;
	MyGame& operator = (const MyGame& other) = delete;

private:
	// �E�B���h�E�̕�
	int mWidth;
	// �E�B���h�E�̍���
	int mHeight;
	// �E�C���h�E�̕`��䗦
	float mRate;
	// �E�C���h�E���[�h���H
	int mWindow;
	// FPS
	float mFps;
	//�V�[���Ǘ��N���X
	SceneManager sceneManager_;
};