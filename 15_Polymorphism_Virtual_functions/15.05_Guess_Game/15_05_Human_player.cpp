#include <random>
#include "15_05_Human_player.h"
#include "15_05_Validation.h"

namespace myGame
{
	int HumanPlayer::numberPlayer = 0;

	HumanPlayer::HumanPlayer() : Player()
	{
		numberPlayer++;
		Player::setName(name + " " + std::to_string(numberPlayer));
	}

	int HumanPlayer::getGuess()
	{
		using myValidation::readNumber;
		int theGuess;
		while (true)
		{
			std::cout << "Enter a number (" << MIN_GUESS << "-" << MAX_GUESS << "):\n";
			readNumber(std::cin, theGuess);
			if (theGuess >= MIN_GUESS &&
				theGuess <= MAX_GUESS)
				break;
		}
		return theGuess;
	}

} // myGame
