#include <iostream>
#include "raylib.h"
#include "board.h"
#include "piece.h"

int main()
{
	std::cout << "Hello World!\n";

	const int screenWidth = 240;
	const int screenHeight = 400;

	SetConfigFlags(FLAG_MSAA_4X_HINT);
	InitWindow(screenWidth, screenHeight, "raylib [shapes] example - splines drawing");

	SetTargetFPS(60);   

	Board b = Board(0, -400);
	Board *board = &b;

	int framesCounter = 0;

	// game loop
	while (!WindowShouldClose())
	{
		// update
		framesCounter++;

		if (framesCounter > 30)
		{
			framesCounter = 0;
			board->Step();
		}

		// user input
		if (IsKeyPressed(KEY_A))
		{
			board->Left();
		}
		if (IsKeyPressed(KEY_D))
		{
			board->Right();
		}
		if (IsKeyDown(KEY_S))
		{
			board->Step();
		}

		if (IsKeyPressed(KEY_O))
		{
			board->TurnLeft();
		}
		if (IsKeyPressed(KEY_P))
		{
			board->TurnRight();
		}

		// render
		BeginDrawing();

		ClearBackground(RAYWHITE);
		board->Render();
		DrawText("ASD", 22, 2, 16, BLACK);
		DrawText("OP", 198, 2, 16, BLACK);

		EndDrawing();
	}

	CloseWindow();

	return 0;
}