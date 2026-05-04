#ifndef COMPUTER_PLAYER_15_05_H
#define COMPUTER_PLAYER_15_05_H

#include "15_05_Player.h"

namespace myGame
{
	class ComputerPlayer : public Player
	{
	public:
		ComputerPlayer();
		virtual int getGuess() override final;
		//   Postcondition: Randomly selects a number from 0 to 100 
		// and returns it as the computer player's guess.
	private:
		std::string name = "Computer";
	};

} // myGame

#endif // COMPUTER_PLAYER_15_05_H