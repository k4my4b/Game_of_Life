# Game_of_Life
The Game of Life is set in an infinite two-dimensional grid inhabited by “cells”. Every cell interacts with up to eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent. From an initial seed grid the game "evolves" one iteration at a time.

# Download: 
Open up a terminal window and type the following command
> git clone https://github.com/k4my4b/Game_of_Life.git

# Compile:
> cd Game_of_Life/

> gcc -Wall -Werror -O3 src/*.c -o game

# Execute:
> ./game seed.txt 

# Assumptions
1- Grid is an N x N adjacency matrix, and that by "infinite" we simply mean N can be any number and so we should be able to accommodate for any size grid as long as we have the memory/space for it. 

2- The instructions state "given a game of life", here the method of delivery is not defined and open to interpretation. I have opted to use file I/O for this purpose. 

3- "Game of life" is indeed refering to Conway's Game of life. 

4- If the grid empty evolution still takes place (but nothing comes to life). 
