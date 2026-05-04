#include "15_05_Player.h"

namespace myGame
{
	Player::Player() : name("no name")
	{ /* Body intentionally left empty */ }

	Player::Player(const std::string& theName) : name(theName)
	{ /* Body intentionally left empty */ }

	void Player::setName(const std::string& theName) { name = theName; }

	const std::string& Player::getName() const { return name; }

} // myGame
