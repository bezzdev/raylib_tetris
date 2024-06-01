#include "piece.h"
#include <iostream>
#include "block_renderer.h"
#include <algorithm>
#include <iterator>

Piece::Piece() { }

Piece::Piece(int ax, int ay, int t) {
	x = ax + 0;
	y = ay + 0;
	type = t;

	if (type == 0) {
		int I[] = { 0, 1, 0, 0,  0, 1, 0, 0,  0, 1, 0, 0,  0, 1, 0, 0 };
		std::copy(std::begin(I), std::end(I), std::begin(cells));
	}
	else if (type == 1) {
		int L[] = { 0, 1, 0, 0,  0, 1, 0, 0,  0, 1, 1, 0,  0, 0, 0, 0 };
		std::copy(std::begin(L), std::end(L), std::begin(cells));
	}
	else if (type == 2) {
		int J[] = { 0, 0, 1, 0,  0, 0, 1, 0,  0, 1, 1, 0,  0, 0, 0, 0 };
		std::copy(std::begin(J), std::end(J), std::begin(cells));
	}
	else if (type == 3) {
		int O[] = { 0, 0, 0, 0,  0, 1, 1, 0,  0, 1, 1, 0,  0, 0, 0, 0 };
		std::copy(std::begin(O), std::end(O), std::begin(cells));
	}
	else if (type == 4) {
		int S[] = { 0, 0, 1, 0,  0, 1, 1, 0,  0, 1, 0, 0,  0, 0, 0, 0 };
		std::copy(std::begin(S), std::end(S), std::begin(cells));
	}
	else if (type == 5) {
		int Z[] = { 0, 1, 0, 0,  0, 1, 1, 0,  0, 0, 1, 0,  0, 0, 0, 0 };
		std::copy(std::begin(Z), std::end(Z), std::begin(cells));
	}
	else if (type == 6) {
		int T[] = { 0, 1, 0, 0,  0, 1, 1, 0,  0, 1, 0, 0,  0, 0, 0, 0 };
		std::copy(std::begin(T), std::end(T), std::begin(cells));
	}
}

void Piece::Up() {
	y++;
}
void Piece::Down() {
	y--;
}

void Piece::TurnLeft() {
	int temp[16];
	std::copy(std::begin(cells), std::end(cells), std::begin(temp));

	cells[12] = temp[0];
	cells[8] = temp[1];
	cells[4] = temp[2];
	cells[0] = temp[3];

	cells[13] = temp[4];
	cells[9] = temp[5];
	cells[5] = temp[6];
	cells[1] = temp[7];

	cells[14] = temp[8];
	cells[10] = temp[9];
	cells[6] = temp[10];
	cells[2] = temp[11];

	cells[15] = temp[12];
	cells[11] = temp[13];
	cells[7] = temp[14];
	cells[3] = temp[15];
}

void Piece::TurnRight() {
	int temp[16];
	std::copy(std::begin(cells), std::end(cells), std::begin(temp));

	cells[0] = temp[12];
	cells[1] = temp[8];
	cells[2] = temp[4];
	cells[3] = temp[0];

	cells[4] = temp[13];
	cells[5] = temp[9];
	cells[6] = temp[5];
	cells[7] = temp[1];

	cells[8] = temp[14];
	cells[9] = temp[10];
	cells[10] = temp[6];
	cells[11] = temp[2];

	cells[12] = temp[15];
	cells[13] = temp[11];
	cells[14] = temp[7];
	cells[15] = temp[3];
}
