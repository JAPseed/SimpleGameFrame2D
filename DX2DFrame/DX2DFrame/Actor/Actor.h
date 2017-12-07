#pragma once
#include"../Math/Vector2.h"
#include"../World/IWorld.h"

//全キャラクターの基底クラス
class Actor {
public:
	//コンストラクタ
	Actor(IWorld* world,const Vector2& position);
	//デストラクタ
	~Actor();
	//初期化
	virtual	void initialize();
	//更新
	virtual void update(float deltaTime);
	//描画
	virtual void draw()const;
	//死んでるか
	bool isDead()const;
protected:
	IWorld* world_;
	Vector2 position_{ Vector2::Zero };//位置
	bool isDead_{ false };//死亡
};