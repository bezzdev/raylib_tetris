#include "block_renderer.h"
#include "raylib.h"
#include "tetris_constants.h"

void BlockRenderer::RenderBlock(int x, int y, Color color)
{
	DrawRectangle(x, y - PIECE_SIZE, PIECE_SIZE, PIECE_SIZE, color);
}
