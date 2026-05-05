#include <random>
#include "15_06_Computer_player.h"

namespace myGame
{
	ComputerPlayer::ComputerPlayer() : Player(), minAnswer(MIN_GUESS), maxAnswer(MAX_GUESS)
	{
		Player::setName(name);
	}

	int ComputerPlayer::getGuess()
	{
		const int theGuess = minAnswer + (maxAnswer - minAnswer) / 2;
		return theGuess;
	}

	void ComputerPlayer::adjustGuess(const bool lowerGuess, const int theGuess)
	{
		// Due to integer division rounding down, we adjust the offset by 1
		if (lowerGuess)
			minAnswer = std::max(minAnswer, theGuess + 1);
		else
			maxAnswer = std::min(maxAnswer, theGuess - 1);
	}

	void ComputerPlayer::reset()
	{
		minAnswer = MIN_GUESS;
		maxAnswer = MAX_GUESS;
	}

} // myGame
