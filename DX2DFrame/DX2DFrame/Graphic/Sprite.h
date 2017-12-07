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
	/// ����������
	///</summary>
	void Initialize();

	/// �ʏ�摜�̓ǂݍ���(�A�Z�b�g���AID�̎w��)
	void Load(const std::string& filename, const SPRITE_ID& id);
	/// �ǂݍ��񂾉摜�����ׂč폜����
	void DeleteAll();
	/// �ʏ�摜�̕`��
	void Draw(const SPRITE_ID& id, const Vector2& position, const Vector2& origin=Vector2::Zero, const Vector2& scale=Vector2::One,float angle=0.0f);

	/// �摜�̃T�C�Y���擾����
	Vector2 GetSize(const SPRITE_ID& id) const;
	//�n���h�����擾����
	int GetHandle(const SPRITE_ID& id) const;

private:
	// �ʏ�摜
	std::unordered_map<SPRITE_ID, int> m_sprites;
};