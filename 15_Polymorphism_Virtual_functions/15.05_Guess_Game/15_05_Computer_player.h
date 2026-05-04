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
	private:
		std::string name = "Computer";
	};

} // myGame

#endif // COMPUTER_PLAYER_15_05_H