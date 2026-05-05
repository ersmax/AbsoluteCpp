#ifndef PLAYER_15_06_H
#define PLAYER_15_06_H

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
		//   Postcondition: Sets the player's name to theName.
		virtual void adjustGuess(bool lowerGuess, int theGuess) {};
		//   Postcondition: Adjusts the player's guessing strategy based on
		// whether the last guess was too low or too high. The default implementation does nothing.
		virtual void reset() {};
		//   Postcondition: Adjusts the player's guessing strategy 
		// based on whether the last guess was too low or too high.
		const std::string& getName() const;
		virtual int getGuess() = 0;
		//   Postcondition: Returns the player's guess as an integer.
	private:
		std::string name;
	};
	
} // myGame


#endif // PLAYER_15_06_H
