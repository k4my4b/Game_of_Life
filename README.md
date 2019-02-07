# Game_of_Life
The Game of Life is set in an infinite two-dimensional grid inhabited by “cells”. Every cell interacts with up to eight neighbours, which are the cells that are horizontally, vertically, or diagonally adjacent. From an initial seed grid the game "evolves" one iteration at a time.

# Download 
Open up a terminal window and type the following command
> git clone https://github.com/k4my4b/Game_of_Life.git

# Compile
> cd Game_of_Life/

> gcc -Wall -Werror -O3 src/*.c -o game

# Execute
> ./game seed.txt 

# Usage
The program requires that a file containing the seed grid is present. 
You may provide the file URI via a launch argument e.g. ./game seed.txt or simply launch the program on its own i.e. ./game, in which case you will then be asked to provide a valid file URI. 
(you will also be asked to provide the number of iterations to evolve the grid) 

Seed file is expected to have the following format

>             3           // size/width of the grid 
>             0 0 0       // 1st row
>             1 1 1       // nth row
>             0 0 0       // last row, each consists of columns of 1s and 0s (seperated by white space) where 1 = live cell and 0 = dead

Modify the example seed.txt file to your liking, making sure you adhere to the format described above. 

# Assumptions
1- Grid is an N x N adjacency matrix, and that by "infinite" we simply mean N can be any number and so we should be able to accommodate for any size grid as long as we have the memory/space for it. 

2- The instructions state "given a game of life", here the method of delivery is not defined and open to interpretation. I have opted to use file I/O for this purpose. 

3- "Game of life" is indeed refering to Conway's Game of life. 

4- If the grid is empty (all cells are dead) evolution still takes place (but nothing comes to life). 

5- Number of evolutions is not defined, I assumed this is variable and ask for it at runtime. 
