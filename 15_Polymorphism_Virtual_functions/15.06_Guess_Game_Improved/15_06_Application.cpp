/*
The computer player in Programming Project 15.5 does not play the number
guessing game very well, since it makes only random guesses. Modify the program
so that the computer plays a more informed game. The specific strategy is up to
you, but you must add function(s) to the Player and ComputerPlayer classes
so that the play(Player &player1, Player &player2) function can send
the results of a guess back to the computer player. In other words, the computer
must be told if its last guess was too high or too low, and it also must be told if
its opponent’s last guess was too high or too low. The computer can then use this
information to revise its next guess.
*/


#include <iostream>
#include <random>
#include "15_06_Player.h"
#include "15_06_Human_player.h"
#include "15_06_Computer_player.h"

using myGame::Player;
using myGame::ComputerPlayer;
using myGame::HumanPlayer;

bool checkForWin(int guess, int answer);
//   Postcondition: Checks if the guess is correct. 
// If the guess is correct, it outputs a winning message and returns true. 
// If the guess is incorrect, it outputs whether the guess is too high or too low and returns false.
void play(Player& player1, Player& player2);
//   Postcondition: The function simulates a guessing game between player1 and player2,
// where each player takes turns to guess a randomly generated number between 0 and 100 
// until one of the players wins by guessing the correct number.
void adjustGame(Player& player1, Player& player2, bool isLower, int theGuess);

int main( )
{
	HumanPlayer aPlayer, aPlayer2;
	ComputerPlayer aPc, aPc2;

	play(aPlayer, aPc);
	play(aPlayer, aPlayer2);
	play(aPc, aPc2);

	std::cout << '\n';
	return 0;
}

bool checkForWin(const int guess, const int answer)
{
	if (answer == guess)
	{
		std::cout << "You're right! You win!" << std::endl;
		std::cout << "---\n";
		return true;
	}
	if (answer < guess)
		std::cout << "Your guess is too high." << std::endl << "---\n";
	else
		std::cout << "Your guess is too low." << std::endl << "---\n";
	return false;
}

void play(Player& player1, Player& player2)
{
	player1.reset();	//	reset min-max at each play
	player2.reset();

	static std::mt19937 rng(std::random_device{}());
	std::uniform_int_distribution<int> dist(myGame::MIN_GUESS, myGame::MAX_GUESS);

	const int answer = dist(rng);
	int guess = 0;
	bool isLower = false;
	bool win = false;

	while (!win)
	{
		std::cout << "Player 1's turn to guess." << std::endl;
		guess = player1.getGuess();
		std::cout << "Player 1's guess: " << guess << '\n';
		win = checkForWin(guess, answer);
		if (win) return;
		
		isLower = (guess < answer) ? true : false;
		adjustGame(player1, player2, isLower, guess);
		
		std::cout << "Player 2's turn to guess." << std::endl;
		guess = player2.getGuess();
		std::cout << "Player 2's guess: " << guess << '\n';
		win = checkForWin(guess, answer);
		if (win) return;

		isLower = (guess < answer) ? true : false;
		adjustGame(player1, player2, isLower, guess);
	}
}

void adjustGame(Player& player1, Player& player2, const bool isLower, const int theGuess)
{
	// adjustGuess is virtual in Player base class.
	// We don't need dynamic_cast, but just call it through the interface.
	player1.adjustGuess(isLower, theGuess);
	player2.adjustGuess(isLower, theGuess);
}
