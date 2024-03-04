# Asaphus Coding Challenge - The Box Game 

## Overview

The Box Game challenge aims to simulate a two player game with green and blue boxes that absorbs tokens, calculates scores, and compete against each other.
The game has the following rules as stated below:

### Game Rules

* There are two types of boxes: green and blue.
* Both boxes can absorb tokens, adding the token weight to their total weight.
* Each box is initialized with a given initial weight.
* After absorbing a token, a box outputs a score based on specific calculations.
* Green and blue boxes calculate scores differently.
* Green box: Square of the mean of the 3 most recent weights (square of the mean of all weights if fewer than 3).
* Blue box: Cantor's pairing function of the smallest and largest absorbed weights.
* The game is played with two green boxes (initial weights 0.0 and 0.1) and two blue boxes (initial weights 0.2 and 0.3).
* There is a list of input token weights, each used in one turn.
* Two players (A and B) alternate turns, starting with Player A.
* In each turn, the current player selects the box with the currently smallest weight to absorb the next input token weight.
* The result of the absorption is added to the current player's score.
* The game ends when all input token weights have been used, and the player with the highest score wins.

## Getting started

1. Clone the repository:
   
   ```
   git clone https://github.com/allwinn/Asaphus_Coding_Challenge.git
   cd Asaphus_Coding_Challenge
   ```
   
2. Build the repository:

   ```
   mkdir build
   cd build
   cmake ..
   make
   ```
   
3. Run the game

```
   ./challenge
```

