#include "board.h"
#include <iostream>
#include "block_renderer.h"
#include <raylib.h>

Board::Board (int ax, int ay) {
	x = ax;
	y = ay;
	rows = BOARD_HEIGHT;
	columns = BOARD_WIDTH;

	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < columns; x++) {
			int i = x + (y * columns);
			if (y == 0 || x == 0 || x == columns - 1)
				cells[i] = 1;
			else
				cells[i] = 0;
		}
	}

	p = Piece(4, 15, 1);
	piece = &p;
}

void Board::Step() {

	std::cout << "Step\n";
	// std::cout << piece->y;

	// move piece down
	p.Down();

	// detect collision
	if (Collide()) {
		// move back up
		p.Up();
		
		// place
		Place();

		// get new piece
		int type = piece->type;
		type += 1;
		if (type > 6)
			type = 0;

		p = Piece(4, 20, type);
		piece = &p;
	}
}

bool Board::Collide()
{
	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < columns; x++) {
			int i = x + (y * columns);
			int v = cells[i];
			
			int pi = -1;
			for (int py = piece->y + 4; py > piece->y; py--) {
				for (int px = piece->x; px < piece->x + 4; px++) {
					pi++;
					if (x == px && y == py) {
						int pv = piece->cells[pi];

						if (v != 0 && pv != 0) {
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

void Board::Place() {
	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < columns; x++) {
			int i = x + (y * columns);
			int v = cells[i];

			int pi = -1;
			for (int py = piece->y + 4; py > piece->y; py--) {
				for (int px = piece->x; px < piece->x + 4; px++) {
					pi++;

					if (x == px && y == py) {
						int pv = piece->cells[pi];

						if (pv != 0) {
							cells[i] = pv;
						}
					}
				}
			}
		}
	}
}

void Board::Left() {
	piece->x -= 1;
	if (Collide()) {
		piece->x += 1;
	}
}
void Board::Right() {
	piece->x += 1;
	if (Collide()) {
		piece->x -= 1;
	}
}

void Board::TurnLeft() {
	piece->TurnLeft();
	if (Collide()) {
		piece->TurnRight();
	}
}

void Board::TurnRight() {
	piece->TurnRight();
	if (Collide()) {
		piece->TurnLeft();
	}
}


void Board::Render()
{
	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < columns; x++) {
			int i = x + (y * columns);
			int v = cells[i];

			if (v == 1) {
				BlockRenderer::RenderBlock(this->x + (x * PIECE_SIZE), -this->y + (-y * PIECE_SIZE), BLACK);
			}
		}
	}

	int pi = -1;
	for (int py = piece->y + 4; py > piece->y; py--) {
		for (int px = piece->x; px < piece->x + 4; px++) {
			pi++;
			int v = piece->cells[pi];

			if (v == 1)
				BlockRenderer::RenderBlock(this->x + (px * PIECE_SIZE), -this->y + (-py * PIECE_SIZE), BLACK);
			else 
				BlockRenderer::RenderBlock(this->x + (px * PIECE_SIZE), -this->y + (-py * PIECE_SIZE), RED);
		}
	}
}
