#ifndef HUMAN_PLAYER_15_05_H
#define HUMAN_PLAYER_15_05_H

#include "15_05_Player.h"

namespace myGame
{
	class HumanPlayer : public Player
	{
	public:
		HumanPlayer();
		virtual int getGuess() override final;
	private:
		std::string name = "Human";
		static int numberPlayer;
	};

} // myGame

#endif // HUMAN_PLAYER_15_05_H


