#include <iostream>
#include <random>
#include "15_05_Player.h"
#include "15_05_Human_player.h"
#include "15_05_Computer_player.h"

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
		return true;
	}
	if (answer < guess)
		std::cout << "Your guess is too high." << std::endl;
	else
		std::cout << "Your guess is too low." << std::endl;
	return false;
}

void play(Player& player1, Player& player2)
{
	int answer = 0, guess = 0;
	answer = rand() % 100;
	bool win = false;

	while (!win)
	{
		std::cout << "Player 1's turn to guess." << std::endl;
		guess = player1.getGuess();
		win = checkForWin(guess, answer);
		if (win) return;
		std::cout << "Player 2's turn to guess." << std::endl;
		guess = player2.getGuess();
		win = checkForWin(guess, answer);
	}
}