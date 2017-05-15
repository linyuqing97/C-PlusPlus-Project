//Programmer: Yuqing Lin
//Contact:   linyuqing97@gmail.com
//Data:      4/30/2017
//This is a Tic Tac Toe game, it has 3 different mode 1 Human VS Human, 2 Human VS Unbreakable  AI, 3 Stupid AI VS Stupid AI
// Input positions, output Play Board.

#include<iostream>
#include "TTT.h"
using namespace std;

int main()
{
	TTT Mytttgame;                              //Call Class, variable named Mytttgame

	char mark = Mytttgame.getmark(); //get the mark from private Class
	Mytttgame.gamerules();                     // Show rules
    Mytttgame.gameselection();


	return 0;



}
