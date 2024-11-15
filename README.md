# Word Hunt Solver

This is a program to find words in GamePigeon Word Hunt quickly so I can beat my friends. It takes a string of 16 characters describing the 4X4 grid and then outputs words that can be found in the grid by moving horizontally, vertically, and diagonally. It uses a recursive pathfinding algorithm to find these words and usually can find all words up to 10 letters long almost instantly.

This program uses the SOWPODS scrabble dictionary as its reference. I'm not sure what dictionary GamePigeon uses, but all of the words I've found so far seem to count for Word Hunt.

## Usage

To use the program, download the repo and build it using CMake. It's set up in a way where it should work out of the box. It runs on the command line and will prompt you to enter the grid. A grid with this configuration:

|a|b|c|d|
|e|f|g|h|
|i|j|k|l|
|m|n|o|p|

would be input as "a b c d e f g h i j k l m n o p". It will then search for words within the grid, starting from a length of 10 and then working backwards to a minimum length of 4. The program only outputs a maximum of 100 words of each length as any more would clog up the terminal and would be impossible to enter in under 90 seconds. I recommend entering the longest words first as they're worth the most points.
