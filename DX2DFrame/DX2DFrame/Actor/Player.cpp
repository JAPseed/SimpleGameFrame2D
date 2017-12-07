#include "Player.h"
#include"../Input/Keyboard.h"
#include"../Graphic/Sprite.h"

Player::Player(IWorld* world,const Vector2& position):
	Actor(world,position)
{
}

Player::~Player()
{
}

void Player::initialize()
{
}

void Player::update(float deltaTime)
{
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::W))position_.y--;
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::A))position_.x--;
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::S))position_.y++;
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::D))position_.x++;
	if (Keyboard::GetInstance().KeyStateDown(KEYCODE::Z))isDead_ = true;
	
}

void Player::draw() const
{
	Vector2 origin = Sprite::GetInstance().GetSize(SPRITE_ID::PLAYER_SPRITE);
	Sprite::GetInstance().Draw(SPRITE_ID::PLAYER_SPRITE, position_, origin);
}
