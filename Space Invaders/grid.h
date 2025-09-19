#pragma once
#include <vector>
#include <raylib.h>

class Grid
{
public:
	Grid();
	void Initalize();
	void Print();
	bool IsCellOutside(int row, int col);
	bool IsCellEmpty(int row, int col);
	int ClearFullRows(); 
	int grid[20][10];
	void Draw();


private:
	bool IsRowFull(int row);
	void MoveRowDown(int row, int numRows);
	void ClearRow(int row);
	int numRows;
	int numCols;
	int cellSize;
	std::vector<Color> colors;
};