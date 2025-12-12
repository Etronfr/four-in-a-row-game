/*
 * board.cpp
 *
 *  Created on: Nov 14, 2025
 *      Author: Medic
 */
#include "board.h"
#include "game.h"
#include <iostream>

board::board() {start();}	//Start constructs the array to be empty

void board::start() {
	for (int k = 0; k < 6; k++) {	// make 6 rows

		for (int i = 0; i < 7; i++) {	//fills row by 7 for columns
			boardArr[k][i] = blank;
		}
	}
	cout << "Player 1: Cyan" << endl;
	cout << "Player 2: Red" << "\n" << endl;
	print();
	cout << endl;
}

void board::print() const {
	for (int k = 0; k < 6; k++) {	// print 6 rows
		for (int i = 0; i < 7; i++) {	//print rows across by 7 for columns
			if (boardArr[k][i] == 'A') {
				cout << BCYAN << 'O' << RESET << " ";
			}
			else if (boardArr[k][i] == 'B') {
				cout << BRED << 'O' << RESET << " ";
			}
			else {
				cout << boardArr[k][i] << " ";
			}
		}
		cout << endl;
		}
}

void board::clearScreen() {
	system("clear");
}



bool board::place(int &colChoice, char &player) {
	int row = 5; // start at bottom row

	if (boardArr[0][colChoice] != 'x') {	//check if full
		return false;
	}
	while (boardArr[row][colChoice] != 'x') {	//while bottom row and column of choice is empty
		if (row == 0) { break; }
		row--;	//goes row up
	}
	if (boardArr[row][colChoice] == 'x') {
		boardArr[row][colChoice] = player;
	}
	clearScreen();
	print();
	if (checkWin(row, colChoice, player)) {
 		if (player == 'A') { cout << "Player 1 Wins!" << endl; }
 		if (player == 'B') { cout << "Player 2 Wins!" << endl; }
 		start();

	}
	cout << endl;

	return true;
}

bool board::checkWin(int &row, int &colChoice, char &player) {	//Win Conditions: Up 4, Up Left 4/Down right, Up Right 4/Down left, Horizontal 4, Down 4 *given parameter gives row where chip was placed
	int chipCount = 1; //count = 4 = win!

	for (int i = 1; row - i >= 0 && boardArr[row - i][colChoice] == player; i++) { //check up
		chipCount++;
		if (chipCount >= 4) {
			return true;
		}
	}
	chipCount = 1;
	for (int i = 1; row + i > 6 && boardArr[row + i][colChoice] == player; i++) {	//check down
		chipCount++;
		if (chipCount >= 4) {
			return true;
		}
	}
	chipCount = 1;
	for (int i = 1; colChoice - i >= 0 && boardArr[row][colChoice - i] == player; i++) {	//check left
		chipCount++;
		if (chipCount >= 4) {
			return true;
		}
	}
	chipCount = 1;
	for (int i = 1; colChoice + i < 7 && boardArr[row][colChoice + i] == player; i++) {	//check right
			chipCount++;
			if (chipCount >= 4) {
				return true;
			}
		}
	chipCount = 1;
	for (int i = 1; row - i >= 0 && colChoice - i >= 0 && boardArr[row - i][colChoice - i] == player; i++) {	//check up left
		chipCount++;
		if (chipCount >= 4) {
			return true;
		}
	}
	chipCount = 1;
	for (int i = 1; row - i >= 0 && colChoice + i < 7 && boardArr[row - i][colChoice + i] == player; i++) {	//check up right
		chipCount++;
		if (chipCount >= 4) {
			return true;
		}
	}
	chipCount = 1;
	for (int i = 1; row + i < 6 && colChoice - i >= 0 && boardArr[row + i][colChoice - i] == player; i++) {	//check down left
		chipCount++;
		if (chipCount >= 4) {
			return true;
		}
	}
	chipCount = 1;
	for (int i = 1; row + i < 6 && colChoice + i > 7 && boardArr[row + i][colChoice + i] == player; i++) {		//check down right
		chipCount++;
		if (chipCount >= 4) {
			return true;
		}
	}

	return false;
}








