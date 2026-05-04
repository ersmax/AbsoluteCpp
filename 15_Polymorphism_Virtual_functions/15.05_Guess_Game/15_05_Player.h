#ifndef PLAYER_15_05_H
#define PLAYER_15_05_H

#include <string>

namespace myGame
{
	constexpr int MIN_GUESS = 0;
	constexpr int MAX_GUESS = 100;

	class Player
	{
	public:
		Player();
		Player(const std::string& theName);
		virtual ~Player() = default;
		void setName(const std::string& theName);
		const std::string& getName() const;
		virtual int getGuess() = 0;
		//   Postcondition: Returns the player's guess as an integer.
	private:
		std::string name;
	};
	
} // myGame


#endif // PLAYER_15_05_H
