The computer player in Programming Project 15.5 does not play the number
guessing game very well, since it makes only random guesses. Modify the program
so that the computer plays a more informed game. The specific strategy is up to
you, but you must add function(s) to the Player and ComputerPlayer classes
so that the play(Player &player1, Player &player2) function can send
the results of a guess back to the computer player. In other words, the computer
must be told if its last guess was too high or too low, and it also must be told if
its opponent’s last guess was too high or too low. The computer can then use this
information to revise its next guess.

---

## Program Logic

This program implements a two-player number guessing game using object-oriented design and polymorphism. Each player (human or computer) tries to guess a randomly selected number between 0 and 100. The computer player uses feedback from previous guesses to improve its strategy.

### Main Flow
- The `play(Player& player1, Player& player2)` function manages the game loop, alternating turns between two players. After each guess, it provides feedback and allows computer players to adjust their guessing strategy.
- The game continues until one player guesses the correct number.

### Player Types
- `Player` is an abstract base class defining the interface for all players, including `getGuess()` and `adjustGuess()`.
- `HumanPlayer` prompts the user for input and validates the guess.
- `ComputerPlayer` uses a binary search strategy, adjusting its guess range based on feedback from previous guesses.

## Function Logic

**play(Player& player1, Player& player2):**
- Resets both players (for computer, resets guess range).
- Randomly selects the answer.
- Alternates turns, calling `getGuess()` for each player and checking for a win.
- Calls `adjustGuess()` after each guess to allow computer players to update their strategy.

**checkForWin(int guess, int answer):**
- Compares the guess to the answer, prints feedback, and returns true if the guess is correct.

**adjustGame(Player& player1, Player& player2, bool isLower, int theGuess):**
- Calls `adjustGuess()` on both players, passing feedback about the last guess.

**Player::getGuess():**
- Pure virtual function; implemented by derived classes to provide a guess.

**Player::adjustGuess(bool lowerGuess, int theGuess):**
- Virtual function; does nothing in the base class, but is overridden by `ComputerPlayer` to update its guessing range.

**ComputerPlayer::reset():**
- Resets the computer's guessing range to the full possible range.



