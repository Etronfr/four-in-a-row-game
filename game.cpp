/*
 * game.cpp
 *
 *  Created on: Nov 14, 2025
 *      Author: Medic
 */

#include <iostream>
#include <windows.h>
#include "board.h"
#include "game.h"

using namespace std;



void game::p1Move() {
	char player = 'A';	// player id for unique chip color P1: A, P2: B
	while (69 == 69) {
		int colChoice;
		cout << "Player 1 select a Column 1-7: ";
		cin >> colChoice;
		cout << endl;
		if (colChoice < 1 || colChoice > 7) {
			cerr << "Please choose 1-7" << endl;
			continue;	//go back to start of loop
		}
		colChoice -= 1;
		if (theBoard.place(colChoice, player)) {
			p2Move();	//change back to break
		}
		else {
			cerr << "Column is full please make a different selection." << endl;
		}
	}
}

void game::p2Move() {
	char player = 'B';	// player id for unique chip color P1: A, P2: B
	while (69 == 69) {
		int colChoice;
		cout << "Player 2 select a Column 1-7: ";
		cin >> colChoice;
		cout << endl;
		if (colChoice < 1 || colChoice > 7) {
			cerr << "Please choose 1-7" << endl;
			continue;	//go back to start of loop
		}
		colChoice -= 1;
		if (theBoard.place(colChoice, player)) {
			p1Move();	//change back to break
		}
		else {
			cerr << "Column is full please make a different selection." << endl;
		}
	}
}

