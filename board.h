#ifndef BOARD_H
#define BOARD_H

#include "tetris_constants.h"
#include "piece.h"

class Board {
	public:
		int x;
		int y;
		
		int rows;
		int columns;

		int cells[240];
		Piece p;
		Piece *piece;

		Board(int ax, int ay);
		void Step();
		bool Collide();
		void Break();
		void Place();
		void Left();
		void Right();
		void TurnLeft();
		void TurnRight();
		void Render();
};

#endif