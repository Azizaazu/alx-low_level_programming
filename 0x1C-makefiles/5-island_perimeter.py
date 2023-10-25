#!/usr/bin/python3
"""defines perimeter island."""

def island_perimeter(grid):
    """Calculate the perimeter of the island described in grid:

    Args:
    param grid: list representing the island grid
    return: Island perimeter
    """

    width, height = len(grid[0]), len(grid)
    edges = 0
    size = 0

    for i in range(height):
        for j in range(width):
            if grid[i][j] == 1:
                size += 1
                if (j > 0 and grid[i][j - 1] == 1):
                    edges += 1
                if (i > 0 and grid[i - 1][j] == 1):
                    edges += 1
    return size * 4 - edges * 2
