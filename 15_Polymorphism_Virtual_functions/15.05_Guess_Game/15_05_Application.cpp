/*
The following shows code to play a guessing game in which two players attempt
to guess a number. Your task is to extend the program with objects that represent
either a human player or a computer player.
bool checkForWin(int guess, int answer)
{
if (answer == guess)
{
cout << "You're right! You win!" << endl;
return true;
}
else if (answer < guess)
cout << "Your guess is too high." << endl;
else
cout << "Your guess is too low." << endl;
return false;
}
void play(Player &player1, Player &player2)
{
int answer = 0, guess = 0;
answer = rand( ) % 100;
bool win = false;

while (!win)
{
cout << "Player 1's turn to guess." << endl;
guess = player1.getGuess( );
win = checkForWin(guess, answer);
if (win) return;
cout << "Player 2's turn to guess." << endl;
guess = player2.getGuess( );
win = checkForWin(guess, answer);
}
}
The play function takes as input two Player objects. Define the Player class with a
virtual function named getGuess( ). The implementation of Player::getGuess(
) can simply return 0. Next, define a class named HumanPlayer derived from
Player. The implementation of HumanPlayer::getGuess( ) should prompt the
user to enter a number and return the value entered from the keyboard. Next,
define a class named ComputerPlayer derived from Player. The implementation
of ComputerPlayer::getGuess( ) should randomly select a number from 0 to
100. Finally, construct a main function that invokes play(Player &player1,
Player &player2) with two instances of a HumanPlayer (human versus human),
an instance of a HumanPlayer and ComputerPlayer (human versus computer),
and two instances of ComputerPlayer (computer versus computer).
*/

#include <iostream>
#include <random>
#include "15_05_Player.h"
#include "15_05_Human_player.h"
#include "15_05_Computer_player.h"

using myGame::Player;
using myGame::ComputerPlayer;
using myGame::HumanPlayer;

bool checkForWin(int guess, int answer);
void play(Player& player1, Player& player2);

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