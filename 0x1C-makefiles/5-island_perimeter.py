#!/usr/bin/python3
"""defines perimeter island"""

def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in grid:

    param grid: list representing the island grid
    return: Island perimeter
    """

    if not grid:
        return 0

    perimeter = 0
    rows, cols = len(grid), len(grid[0])

    for r in range(rows):
        for c in range(cols):
            if grid[r][c] == 1:
                perimeter += 4
                if r > 0 and grid[r - 1][c] == 1:
                    perimeter -= 2
                if c > 0 and grid[r][c - 1] == 1:
                    perimeter -= 2

    return perimeter
