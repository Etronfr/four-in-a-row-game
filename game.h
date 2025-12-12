/*
 * class.h
 *
 *  Created on: Nov 14, 2025
 *      Author: Medic
 */

#ifndef GAME_H_
#define GAME_H_
#define RESET 	"\033[0m"
#define BCYAN  	"\033[96m"
#define BRED   	"\033[91m"

#include <iostream>
#include "board.h"
using namespace std;

class game {
private:
	int choice;
	board theBoard;	//obj for placing in move

public:

	void p1Move();
	void p2Move();
	/*
	void colFull(int &choice);
	void range(int &choice);*/
};



#endif /* GAME_H_ */
