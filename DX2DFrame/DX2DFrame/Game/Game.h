#pragma once
#include<DxLib.h>

#include"../Scene/SceneManager.h"
#include"Define.h"
#include"../Input/Keyboard.h"
#include"../Graphic/Sprite.h"

class MyGame {
public:
	// コンストラクタ
	MyGame(int x=WINDOW_WIDTH,int y=WINDOW_HEIGHT, float rate = 1.0f, int window = TRUE, float fps = 60.0f) :
		mWidth(x), mHeight(y), mRate(rate), mWindow(window), mFps(fps), sceneManager_() {
	}
	~MyGame() {}
public:
	// 実行
	int run() {
		// サイズ指定
		SetGraphMode(mWidth, mHeight, 32);
		// 描画倍率
		SetWindowSizeExtendRate(mRate);
		// ウインドウモードにするかどうか
		ChangeWindowMode(mWindow);
		SetUseDirect3DVersion(DX_DIRECT3D_9);
		//DXLib初期化処理
		if (DxLib_Init() == -1)return -1;//エラーが起きたら終了
		SetDrawScreen(DX_SCREEN_BACK);
		SetUseBackCulling(TRUE);

		start();

		// キーが押されるまでループします
		while (isRunning()) {
			update();
			draw();
			frameEnd();
			//Time::GetInstance().draw_fps();
			// 裏画面の内容を表画面に反映させる
			ScreenFlip();
		}

		end();

		//DXLib使用終了処理
		DxLib_End();

		return 0;	//ソフト終了
	}

private:
	// 開始
	void start() {
		Sprite::GetInstance().Initialize();
		sceneManager_.start();
	}
	// 更新
	void update() {
		Keyboard::GetInstance().Update();
		sceneManager_.update(1.0f);
	}
	// 描画
	void draw() {
		sceneManager_.draw();
	}
	//フレーム終了時処理
	void frameEnd() {
		sceneManager_.checkIsEnd();
	}
	// 終了
	void end() {

	}
	// 実行中か
	bool isRunning() { return (ProcessMessage() == 0 && ClearDrawScreen() == 0); }

	// コピー禁止
	MyGame(const MyGame& other) = delete;
	MyGame& operator = (const MyGame& other) = delete;

private:
	// ウィンドウの幅
	int mWidth;
	// ウィンドウの高さ
	int mHeight;
	// ウインドウの描画比率
	float mRate;
	// ウインドウモードか？
	int mWindow;
	// FPS
	float mFps;
	//シーン管理クラス
	SceneManager sceneManager_;
};