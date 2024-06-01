#ifndef PIECE_H
#define PIECE_H

#include "tetris_constants.h"

class Piece {
	public:
		int x;
		int y;

		int type;
		int cells[16];
		
		Piece();
		Piece(int ax, int ay, int t);
		void Up();
		void Down();
		void TurnLeft();
		void TurnRight();
};

#endif