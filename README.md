# Chess-Game


Welcome to my console-based Chess game! This game offers a rich and engaging experience with three unique modes: Simple Chess, Tal's Gambit, and King Rush. Each mode provides a different challenge and a fresh take on the traditional game of chess. Here's a detailed guide on how to play each mode and how to set up the game:

>>Game Setup

Download Files: First, download all the necessary files from the repository.
Build the Game: Compile the source code. The main function is in Filename.cpp.
Run the Game: Execute the compiled file to start the game.

>>Game Modes

1. Simple Chess
In Simple Chess, you play according to the standard chess rules. Here’s how to make a move:
Identify the Piece: Use the first letter of the piece you want to move:

P for Pawn
K for King
N for Knight
R for Rook
Q for Queen
B for Bishop

Specify the Current Position: Use the column letter (a, b, c, etc.) followed by the row number (1 to 8).
Specify the Target Position: Follow the same format as the current position.
Example: To move a pawn from e2 to e4, you will write Pe2 Pe4.

2. Tal's Gambit
Tal's Gambit adds a twist to traditional chess by introducing a new piece called the Camel. The Camel combines the moves of a Knight and a Rook.

Camel Piece: Use the letter 'C' to represent the Camel.
All Other Rules: Follow the same rules as Simple Chess for other pieces.
Example: Moving a Camel from d2 to e4 is written as Cd2 Ce4.

3. King Rush
King Rush is a fast-paced variation where the goal is to get your King to the 8th rank. However, checks are not allowed, and giving a check results in an immediate loss.

No Checks: Ensure that you never place your opponent’s King in check.
Winning Condition: The first player to move their King to the 8th rank wins the game.

>>Game Setup and Instructions

Game Start: Launch the game in your console to start.
Choose Game Mode: Select Simple Chess, Tal's Gambit, or King Rush.
Enter Moves: Input moves as described for each game mode.
Game End: The game ends when checkmate is achieved, a King reaches the 8th rank in King Rush, or a player gives a check in King Rush.
