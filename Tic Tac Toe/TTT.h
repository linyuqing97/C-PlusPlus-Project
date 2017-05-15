#ifndef TTT_H
#define TTT_H


#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

class TTT
{
private:
	char board[9] = {'1','2','3','4','5','6','7','8','9'};
	char Blank;
	int  move;
	char gofirst;
	string playerinformation[2];
	char mark;
	int round = 1;
	int selection = 0;
	char decistion;

	string player1, player2;
public:
	//Default constructor                                                                       check list in TTT.cpp
	TTT();
	~TTT();
	void Display(); //Display Board                                                                line 62
	void reset();                                                                                //line 119
	bool isWinner(); //Check the winning condition, if yes then return true                        line 27
	void Go(int,char);     // Set X or O to the board                                              line 75
	bool isFree(int);    // Check the board is full or not                                         line 203
	char GetTurn(char);// Check Who's Turn                                                         line 171
	int getmove(char); //                                                                          line 178
	char whogofirst();   //Check who takes the first turn                                          line 194
	char SwitchMark(char);// Switch turn                                                           line 130
	bool isBlank();                     //                                                         line 143
	int whoisgoingtowin(char);// post win                                                          line 219
	void gamerules();        //show rules                                                          line 5
	char getmark();          //take mark
	int randomplay();        //random generation, computer randomly move                            line 50
	void Computergo(char,int);  // the perfect strategy                                             line 288
	int make2inrow(char);     //get tow in row                                                      line 252
	int getround();          //round counter control the perfect strategy function
	void gameselection();                                                                         //line 15
	void game_mode1();                                                                             //line 405
	void game_mode2();                                                                         //   line 452
	void game_mode3();                                                                             //line 519
	int getanyfreespace();    //free space checker                                                 // line 581
};


#endif // TTT_H
