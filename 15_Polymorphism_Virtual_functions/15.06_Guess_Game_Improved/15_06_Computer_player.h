#ifndef COMPUTER_PLAYER_15_06_H
#define COMPUTER_PLAYER_15_06_H

#include "15_06_Player.h"

namespace myGame
{
	class ComputerPlayer : public Player
	{
	public:
		ComputerPlayer();
		virtual int getGuess() override final;
		//   Postcondition: Randomly selects a number from 0 to 100 
		// and returns it as the computer player's guess.
		virtual void adjustGuess(bool lowerGuess, int theGuess) override final;
		virtual void reset() override final;
	private:
		std::string name = "Computer";
		int minAnswer;
		int maxAnswer;
	};

} // myGame

#endif // COMPUTER_PLAYER_15_06_H