#include <random>
#include "15_05_Computer_player.h"

namespace myGame
{
	ComputerPlayer::ComputerPlayer() : Player()
	{
		Player::setName(name);
	}

	int ComputerPlayer::getGuess()
	{
		static std::mt19937 rng(std::random_device{}());
		std::uniform_int_distribution<int> randomGuess(MIN_GUESS, MAX_GUESS);
		const int theGuess = randomGuess(rng);
		return theGuess;
	}

} // myGame
