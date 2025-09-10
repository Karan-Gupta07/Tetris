// Space Invaders.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <raylib.h>

int main()
{
	InitWindow(300, 600, "Tetris");
	Color darkBlue = { 44,44,127, 255 };
	SetTargetFPS(60);
	while(WindowShouldClose() == false)
	{
		BeginDrawing();

		ClearBackground(darkBlue);

		EndDrawing();
	}




	CloseWindow();


}