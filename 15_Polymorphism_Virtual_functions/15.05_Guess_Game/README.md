The following shows code to play a guessing game in which two players attempt
to guess a number. Your task is to extend the program with objects that represent
either a human player or a computer player.
```cpp
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
```

```cpp
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
		if (win) 
			return;
		cout << "Player 2's turn to guess." << endl;
		guess = player2.getGuess( );
		win = checkForWin(guess, answer);
	}
}
```

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

---

## Function Logic

### checkForWin(int guess, int answer)
This function compares the player's guess to the correct answer:
- If the guess is correct, it prints a winning message and returns true.
- If the guess is too high, it prints a message indicating so and returns false.
- If the guess is too low, it prints a message indicating so and returns false.

### play(Player &player1, Player &player2)
This function manages the main game loop:
- Generates a random answer between 0 and 100.
- Alternates turns between player1 and player2, prompting each to make a guess using their `getGuess()` method.
- After each guess, it calls `checkForWin()` to determine if the game is over.
- The loop continues until one player guesses the correct number.

### Player::getGuess()
- This is a pure virtual function in the Player base class, requiring derived classes to implement their own guessing logic.

### HumanPlayer::getGuess()
- Prompts the user to enter a number within the valid range.
- Validates the input and returns the entered value as the guess.

### ComputerPlayer::getGuess()
- Randomly selects and returns a number within the valid range as the computer's guess.

