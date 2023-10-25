0. make -f 0-Makefile
Create your first Makefile.

Requirements:

name of the executable: school
rules: all
The all rule builds your executable
variables: none
1. make -f 1-Makefile
Requirements:

name of the executable: school
rules: all
The all rule builds your executable
variables: CC, SRC
CC: the compiler to be used
SRC: the .c files
.
.
.
5. Island Perimeter
Technical interview preparation:

You are not allowed to google anything
Whiteboard first
Create a function def island_perimeter(grid): that returns the perimeter of the island described in grid:

grid is a list of list of integers:
0 represents a water zone
1 represents a land zone
One cell is a square with side length 1
Grid cells are connected horizontally/vertically (not diagonally).
Grid is rectangular, width and height don’t exceed 100
Grid is completely surrounded by water, and there is one island (or nothing).
The island doesn’t have “lakes” (water inside that isn’t connected to the water around the island).
Requirements:

First line contains #!/usr/bin/python3
You are not allowed to import any module
Module and function must be documented
