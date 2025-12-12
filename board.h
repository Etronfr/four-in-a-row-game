/*
 * board.h
 *
 *  Created on: Nov 14, 2025
 *      Author: Medic
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
using namespace std;

class board {
private:
	static constexpr int row = 6;	// 6 Rows
	static constexpr int col = 7;	// 7 columns

	char blank = 'x';
	char boardArr[row][col];


public:	//IDEA make animated falling chip
	board();	//Constructor

	void start();
	void print() const;	//Display
	void clearScreen(); //Clears Console

	bool place(int &colChoice, char &player);
	bool checkWin(int &row, int &colChoice, char& player);

};






#endif /* BOARD_H_ */

