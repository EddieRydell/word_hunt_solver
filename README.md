# Word Hunt Solver

This is a program to find words in GamePigeon Word Hunt quickly so I can beat my friends. It takes a string of 16 characters describing the 4X4 grid and then outputs words that can be found in the grid by moving horizontally, vertically, and diagonally. It uses a recursive pathfinding algorithm and can usually find all words up to 10 letters long almost instantly.

This program uses the SOWPODS scrabble dictionary as its reference. I'm not sure what dictionary GamePigeon uses, but most of the words I've found so far seem to count for Word Hunt.

## Usage

To use the program, download the repo and build it using CMake. It's set up in a way where it should work out of the box on the command line. When running, it will prompt you to enter the grid. A grid with this configuration:

```
A B C D
E F G H
I J K L
M N O P
```

would be input as `a b c d e f g h i j k l m n o p` (spacing doesn't matter, not case sensitive). It will then search for words within the grid, starting from a length of 10 and then working backwards to a minimum length of 4. The program only outputs a maximum of 20 words of each length as any more would clog up the terminal and would be impossible to enter in under 90 seconds. I recommend entering the longest words first as they're worth the most points.
