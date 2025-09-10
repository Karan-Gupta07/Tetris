#include "grid.h"
#include <iostream>

Grid::Grid()
{
	numRows = 20;
	numCols = 10;
	cellSize = 30;
	Initalize();
}

void Grid::initalize()
{
	for (int row = 0; row < numRows; row = row + 1)
	{
		for (int column = 0; column < numCols; column = column + 1)
		{
			grid[row][column] = 0
		}
	}
}
void Grid::Print()
{
	for (int row = 0; row < numRows; row = row + 1)
	{
		for (int column = 0; column < numCols; column = column + 1)
		{
			std::cout < grid[row][column] << 
		}
	}
}