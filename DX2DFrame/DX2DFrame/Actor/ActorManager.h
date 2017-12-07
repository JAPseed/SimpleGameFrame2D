#pragma once
#include"ActorPtr.h"
#include<map>
#include<list>

enum class ActorGroup;
class ActorManager {
public:
	ActorManager();

	// 初期化
	void initialize();
	// 更新
	void update(float deltaTime);
	// 描画
	void draw() const;
	// アクターの追加
	void addActor(ActorGroup group, const ActorPtr& actor);
	// コピー禁止
	ActorManager(const ActorManager& other) = delete;
	ActorManager& operator = (const ActorManager& other) = delete;
private:
	//アクター一覧
	std::map<ActorGroup, std::list<ActorPtr>> actors_;
};