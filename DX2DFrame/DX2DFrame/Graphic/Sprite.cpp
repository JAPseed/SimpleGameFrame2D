#include "Sprite.h"
#include<DxLib.h>

Vector2 Sprite::GetSize(const SPRITE_ID & id) const
{
	int x,y;
	GetGraphSize(m_sprites.at(id), &x, &y);
	return Vector2{ (float)x,(float)y };
}

int Sprite::GetHandle(const SPRITE_ID & id) const
{
	return m_sprites.at(id);
}

Sprite::~Sprite()
{
	InitGraph();
	m_sprites.clear();
}

void Sprite::Initialize()
{
	InitGraph();
	m_sprites.clear();
}

void Sprite::Load(const std::string & filename, const SPRITE_ID & id)
{
	m_sprites[id] = LoadGraph(filename.c_str());
}

void Sprite::DeleteAll()
{
	std::unordered_map<SPRITE_ID, int>::iterator spritr = m_sprites.begin();
	while (spritr != m_sprites.end()) {
		DeleteGraph(spritr->second);
		++spritr;
	}
	m_sprites.clear();

}

void Sprite::Draw(const SPRITE_ID & id, const Vector2 & position, const Vector2 & origin, const Vector2 & scale, float angle)
{
	DrawRotaGraph3((int)position.x, (int)position.y, (int)origin.x, (int)origin.y,
		(double)scale.x, (double)scale.y, angle, m_sprites[id], true, false);

}
