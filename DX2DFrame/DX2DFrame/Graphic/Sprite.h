#pragma once

#include <string>
#include <unordered_map>
#include <vector>
#include"SPRITE_ID.h"
#include"../Math/Vector2.h"

class Sprite
{
private:
	Sprite() = default;
	~Sprite();
public:
	static Sprite &GetInstance() {
		static Sprite s;
		return s;
	}

	///<summary>
	/// 初期化処理
	///</summary>
	void Initialize();

	/// 通常画像の読み込み(アセット名、IDの指定)
	void Load(const std::string& filename, const SPRITE_ID& id);
	/// 読み込んだ画像をすべて削除する
	void DeleteAll();
	/// 通常画像の描画
	void Draw(const SPRITE_ID& id, const Vector2& position, const Vector2& origin=Vector2::Zero, const Vector2& scale=Vector2::One,float angle=0.0f);

	/// 画像のサイズを取得する
	Vector2 GetSize(const SPRITE_ID& id) const;
	//ハンドルを取得する
	int GetHandle(const SPRITE_ID& id) const;

private:
	// 通常画像
	std::unordered_map<SPRITE_ID, int> m_sprites;
};