#pragma once
#include "grid.h"
#include "block.h"

class Game {
public:
	Game();
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	Grid grid;
	void HandleInput();
	void Draw();
	void Reset();
	void MoveBlockLeft();

	void MoveBlockRight();

	void MoveBlockDown();

	bool gameOver;

private:
	bool IsBlockOutside();
	void RotateBlock();
	void LockBlock();
	bool BlockFits();
	std::vector<Block> blocks; 
	Block currentBlock;
	Block nextBlock;
};