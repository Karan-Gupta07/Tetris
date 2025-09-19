#include "game.h"
#include <random>
#include "blocks.cpp"
#include <raylib.h>

Game::Game()
{
	grid = Grid();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	gameOver = false;
}

Block Game::GetRandomBlock()
{
	if (blocks.empty())
	{
		blocks = GetAllBlocks();
	}
	int randomIndex = rand() % blocks.size();
	Block block = blocks[randomIndex];
	blocks.erase(blocks.begin() + randomIndex);
	return block;
}

std::vector<Block> Game::GetAllBlocks()
{
	return { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
}

void Game::HandleInput()
{
	int keyPressed = GetKeyPressed();
	if(gameOver and keyPressed != 0) {
		gameOver = false;
		Reset();
	}
	switch (keyPressed)
	{
		case KEY_LEFT:
			MoveBlockLeft();
			break;
		case KEY_RIGHT:
			MoveBlockRight();
			break;
		case KEY_DOWN:
			MoveBlockDown();
			break;
		case KEY_UP:
			RotateBlock();
			break;



	}
}

void Game::Draw()
{
	grid.Draw();
	currentBlock.Draw();
}

void Game::Reset()
{
	grid.Initalize();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
}

void Game::MoveBlockLeft() {
	if (not gameOver) {
		currentBlock.Move(0, -1);
		if (IsBlockOutside() or BlockFits() == false) {
			currentBlock.Move(0, 1);
		}
	}

}

void Game::MoveBlockRight() {
	if (not gameOver) {
		currentBlock.Move(0, 1);
		if (IsBlockOutside() or BlockFits() == false) {
			currentBlock.Move(0, -1);
		}
	}

}

void Game::MoveBlockDown() {
	if (not gameOver) {
		currentBlock.Move(1, 0);
		if (IsBlockOutside() or BlockFits() == false) {
			currentBlock.Move(-1, 0);
			LockBlock();
		}
	}
}

bool Game::IsBlockOutside() {
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles) {
		if (grid.IsCellOutside(item.row, item.column)) {
			return true;
		}
	}
	return false;
}

void Game::RotateBlock()
{
	if (not gameOver) {
		currentBlock.Rotate();
		if (IsBlockOutside() or BlockFits() == false) {
			currentBlock.UndoRotation();
		}
	}
}

void Game::LockBlock()
{
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles) {
		grid.grid[item.row][item.column] = currentBlock.id;
	}
	currentBlock = nextBlock;
	if(BlockFits() == false) {
		gameOver = true;
	}
	nextBlock = GetRandomBlock();
	grid.ClearFullRows();
}

bool Game::BlockFits()
{
	std::vector<Position> tiles = currentBlock.GetCellPositions();
	for (Position item : tiles) {
		if(grid.IsCellEmpty(item.row, item.column) == false) {
			return false;
		}
	}return true;
}
