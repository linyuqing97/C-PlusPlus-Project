#include "TTT.h"
#include "TTT.h"


void TTT::gamerules()//show rules
{
    	cout << "Welcome to my TicTacToe game" << endl;
	cout << "--------------------------------------------------Rules----------------------------------------------------" << endl;
	cout << "  The object of Tic Tac Toe is to get three in a row.You play on a three by three game board" << endl;
	cout << "  The first player is known as X and the second is O. Players alternate placing Xs and Os on " << endl;
	cout << "  the game board until either oppent has three in a row or all nine squares are filled." << endl;
	cout << "  X always goes first, and in the event that no one has three in a row, the stalemate is called a cat game." << endl;
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
}
void TTT::gameselection()//choice different game type
{
    cout << "Please select a mode" << endl;
	cout << "1:Human vs Human" << endl;
	cout << "2: Human vs AI" << endl;
	cout << "3: AI vs AI" << endl;
	cin >> selection;
	if(selection==1)game_mode1(); //line 348
	if(selection==2)game_mode2(); //line 394
	if(selection==3)game_mode3(); //line 436

}
bool TTT::isWinner()  //winning condition
{

	if (board[0] == board[1] && board[1] == board[2])   //check horizontally,vertically,inclined
		return true;
	else if (board[0] == board[3] && board[3] == board[6])
		return true;
	else if (board[0] == board[4] && board[4] == board[8])
		return true;
	else if (board[1] == board[4] && board[4] == board[7])
		return true;
	else if (board[2] == board[5] && board[5] == board[8])
		return true;
	else if (board[3] == board[4] && board[4] == board[5])
		return true;
	else if (board[6] == board[7] && board[7] == board[8])
		return true;
	else if (board[6] == board[4] && board[4] == board[2])
		return true;
	else
		return false;
}

int TTT::randomplay()
{
	srand(time(NULL));
	int m;//When done, m will hold the computer's random move
	do {
		m = rand() % 9+1; //random move(1-9)
	} while (isFree(m)==true);// make sure the move is legal;
	return m;

	//m has a compute move;
}

void TTT::Display()
{
// display board  separate each array item into different area on the Tic Tac Toe board
	cout << std::setw(70)  << endl;// style makes it look nicer
	cout <<"       " <<endl;
	cout << "     " << board[0] << "  |  " << board[1] << "  |  " << board[2] << endl;
	cout << "   _____|_____|_____   " << endl;
	cout << "        |     |        " << endl;
	cout << "     " << board[3] << "  |  " << board[4] << "  |  " << board[5] << endl;
	cout << "   _____|_____|_____   " << endl;
	cout << "        |     |        " << endl;
	cout << "     " << board[6] << "  |  " << board[7] << "  |  " << board[8] << endl << endl;
}
void TTT::Go(int move,char mark) //mark is X or O represent player
{
//move from 1-9 on board which is 0-8 on the array of board
	if (move == 1)
	{
		board[0] = mark;
	}
	else if (move == 2)
	{
		board[1] = mark;
	}
	else if (move == 3)
	{
		board[2] = mark;
	}
	else if (move == 4)
	{
		board[3] = mark;
	}
	else if (move == 5)
	{
		board[4] = mark;
	}
	else if (move == 6)
	{
		board[5] = mark;
	}
	else if (move == 7)
	{
		board[6] = mark;
	}
	else if (move == 8)
	{
		board[7] = mark;
	}
	else if (move == 9)
	{
		board[8] =mark;
	}


}


void TTT::reset()
{
	//reset board
	int values = 49; // '1' has value 49
	for (int i = 0; i <= 9; i++)//reset all the char number by using the reference number '1'=49,'2'=50 etc.
	{
		board[i] = values;
		values++;
	}

}
char TTT::SwitchMark(char mark)
{
	if (mark == 'X')  // Switch mark=Switch players X to O
	{
		return mark = 'O';

	}
	else if (mark == 'O')//O to X
	{

	return	mark = 'X';
	}
}
bool TTT::isBlank()
   {
// checking blank
      int n = 1;
      int counter = 0;
	  int const boardindex = 9;
         for(int j = 0; j < boardindex; j++ )
         {
            //Check to see if the board if full
            if(board[j] == '0'+n)

            {
               counter++;
            }
			n++;
         }


      if( counter < 1 )

      {

         return true;

      }
      else return false; //if False then the board is not full.

}
char TTT::GetTurn(char mark)// it's nothing, only used when I put them on main CPP
{

	if (mark == 'X')return 'X';
	if (mark == 'O')return 'O';
}

int TTT::getmove(char mark)
{
	//Get move;
	if (mark=='X')
	{
		cout << "X's turn,Please Enter the position you want to go: " << endl;// get where that X want to go(1-9)
		cin >> move;
		return move;
	}
	else if(mark=='O')
	{
		cout << "O's turn,Please Enter the position you want to go: " << endl;// get where that O want to go(1-9)
		cin >> move;
		return move;
	}
}
char TTT::whogofirst()
{
	cout << "Who want to go first?(X or O)" << endl;
	cin>>gofirst;
	gofirst = toupper(gofirst);
	return gofirst;

}

bool TTT::isFree (int move)
{
	if(0<move<=9)
	{
		int realmove = move - 1;   //get(1-9)but board[i]holing(0-8);
		if (board[realmove]=='X'||board[realmove]=='O')// If the board array element don't have 'X'and 'O' filled in, then it's blank
		{
		return true;
		}
		else
		{
		 return false;
		}
                    //return false if board is blank;
	}
}
int TTT::whoisgoingtowin(char mark)
{
	//Checking which position is going to win.
	//returning the position number if it's a key point to win
	if (mark)//mark=player
	{
		if (board[0]==mark&&board[1]==mark&&isFree(3)==false)return 3;   //b[o]==mark&&b[1]==mark&&board[2]!='X'||'O'
		else if (board[0] ==mark&&board[2]==mark&&isFree(2)==false)return 2;// check position 1 and 3 have same symbol or not. if yes then check position 2 is free?
		else if (board[0] ==mark&&board[4]==mark&&isFree(9)==false)return 9;// notice the array has position 0-8 corresponding the position 1-9 show on board
		else if (board[2] ==mark&&board[4]==mark&&isFree(1)==false)return 1;// when checking the board mark is checking the array but when checking it's free or not,it checking the board
		else if (board[3] ==mark&&board[6]==mark&&isFree(1)==false)return 1;// Which means the have 1 difference.
		else if (board[4] ==mark&&board[8]==mark&&isFree(1)==false)return 1;
		else if (board[7] ==mark&&board[4]==mark&&isFree(2)==false)return 2;
		else if (board[1] ==mark&&board[4]==mark&&isFree(8)==false)return 8;
		else if (board[5] ==mark&&board[8]==mark&&isFree(2)==false)return 2;
		else if (board[1] ==mark&&board[7]==mark&&isFree(5)==false)return 5;
		else if (board[2] ==mark&&board[6]==mark&&isFree(5)==false)return 5;
		else if (board[0] ==mark&&board[8]==mark&&isFree(5)==false)return 5;
		else if (board[1] ==mark&&board[7]==mark&&isFree(5)==false)return 5;
		else if (board[2] ==mark&&board[8]==mark&&isFree(6)==false)return 6;
		else if (board[0] ==mark&&board[3]==mark&&isFree(7)==false)return 7;
		else if (board[2] ==mark&&board[4]==mark&&isFree(7)==false)return 7;
		else if (board[8] ==mark&&board[7]==mark&&isFree(7)==false)return 7;
		else if (board[1] ==mark&&board[4]==mark&&isFree(8)==false)return 8;
		else if (board[6] ==mark&&board[8]==mark&&isFree(8)==false)return 8;
		else if (board[2] ==mark&&board[5]==mark&&isFree(9)==false)return 9;
		else if (board[0] ==mark&&board[4]==mark&&isFree(9)==false)return 9;
		else if (board[6] ==mark&&board[7]==mark&&isFree(9)==false)return 9;
        else if (board[0] ==mark&&board[6]==mark&&isFree(4)==false)return 4;
        else if (board[3]==mark&&board[4]==mark&&isFree(6)==false) return 6;
		else return -1;
	}
}
int TTT::make2inrow(char mark)
{ // get a new position near the old one                 // checking the array content is holding the array position 0-8 which corresponding on board value 1-9
	if (board[0] == mark&&isFree(2)==false)return 2;     // notice return value is return to the board so it number 1-9
	else if (board[0] == mark&&isFree(4)==false)return 4;
	else if (board[0] == mark&&isFree(5)==false)return 5;
	else if (board[1] == mark&&isFree(3)==false)return 3;
	else if (board[1] == mark&&isFree(1)==false)return 1;
	else if (board[1] == mark&&isFree(5)==false)return 5;
	else if (board[2] == mark&&isFree(2)==false)return 2;
	else if (board[2] == mark&&isFree(5)==false)return 5;
	else if (board[2] == mark&&isFree(6)==false)return 6;
	else if (board[3] == mark&&isFree(1)==false)return 1;
	else if (board[3] == mark&&isFree(5)==false)return 5;
	else if (board[3] == mark&&isFree(7)==false)return 7;
	else if (board[4] == mark&&isFree(2)==false)return 2;
	else if (board[4] == mark&&isFree(3)==false)return 3;
	else if (board[4] == mark&&isFree(1)==false)return 1;
	else if (board[4] == mark&&isFree(4)==false)return 4;
	else if (board[4] == mark&&isFree(6)==false)return 6;
	else if (board[4] == mark&&isFree(7)==false)return 7;
	else if (board[4] == mark&&isFree(8)==false)return 8;
	else if (board[4] == mark&&isFree(9)==false)return 9;  //end of the position 5
	else if (board[5] == mark&&isFree(5)==false)return 5;  //start of the position 6
	else if (board[5] == mark&&isFree(3)==false)return 3;
	else if (board[5] == mark&&isFree(9)==false)return 9;
	else if (board[6] == mark&&isFree(4)==false)return 4;
	else if (board[6] == mark&&isFree(5)==false)return 5;
	else if (board[6] == mark&&isFree(8)==false)return 8;
	else if (board[7] == mark&&isFree(5)==false)return 5;
	else if (board[7] == mark&&isFree(7)==false)return 7;
	else if (board[7] == mark&&isFree(9)==false)return 9;
	else if (board[8] == mark&&isFree(6)==false)return 6;
	else if (board[8] == mark&&isFree(5)==false)return 5;
	else if (board[8] == mark&&isFree(8)==false)return 8;

}
void TTT::Computergo(char mark,int round) //round is counting the computer move,so it's not going to mass up.
{
	// Computer would always hold X so every mark that passing to go function would equal to X.
	if(round==1)Go(7,'X');
	if (round == 2)
	{
		if (!isFree(5))//Because isfree function would auto reduce 1 so check the board[4]=5;
		{
			Go(5, 'X');
		}
		else Go(1, 'X');
	}
	///////////////////////////////////////////////////////
	if (round == 3)// step 3
	{
	    if(whoisgoingtowin('O')!=-1) //if "O" going to win then stop him
        {
            Go(whoisgoingtowin('O'),'X');
        }
		else if (!isFree(9))// if no one going to win then go position 9 board
		{
			Go(9, 'X');
		}

		else Go(3, 'X');   // if position 9 is full then go position 3 on board
	}
	////////////////////////////////////////////////////////
	if (round == 4)
	{
		if (whoisgoingtowin('X')!=-1)   //step 4     Check is is a winning possible?
		{
			Go(whoisgoingtowin('X'), 'X');          // then go to the position and win
		}
		else if(whoisgoingtowin('O')!=-1)           // check if 'O' is going to win or not, yes then stop it.
        {
           Go(whoisgoingtowin('O'), 'X');
        }
		else
		{
			Go(make2inrow('O'), 'X');              // no one going to win? Check  make two in a row
		}
	}
////////////////////////////////////////////////////////////
	if (round == 5)
	{
		if (whoisgoingtowin( 'X') != -1)// step 5
		{
			Go(whoisgoingtowin('X'), 'X');
		}
		else if (whoisgoingtowin('O') != -1)
		{
			Go(whoisgoingtowin('O'), 'X');
		}
		else if (isFree(7)==true) Go(7, 'X');
		else Go(3, 'X');
	}
	/////////////////////////////////////////////////////////
	if (round == 6)
	{
		if (whoisgoingtowin('O') != -1) //step 6
		{
			Go(whoisgoingtowin('O'), 'X');
		}
		else if (whoisgoingtowin('X') != -1)
		{
			Go(whoisgoingtowin('X'), 'X');
		}
		else
		{
			Go(make2inrow('X'), 'X');
		}
	}
    //////////////////////////////////////////////////
	if(round==7)
    {
        if(whoisgoingtowin('X')!=-1) //repeating step 6
        {
            Go(whoisgoingtowin('X'),'X');
        }
        else if (whoisgoingtowin('O') != -1) //step 7
		{
			Go(whoisgoingtowin('O'), 'X');
		}
		else{
            Go(getanyfreespace(),'X');
		}
    }
    //////////////////////////////////////////////////
    if(round==8)
    {
                if(whoisgoingtowin('X')!=-1)
        {
            Go(whoisgoingtowin('X'),'X');
        }
        else if (whoisgoingtowin('O') != -1) //step 7
		{
			Go(whoisgoingtowin('O'), 'X');
		}
		else{
            Go(getanyfreespace(),'X');
		}
    }
    if(round==9)
    {
                if(whoisgoingtowin('X')!=-1)
        {
            Go(whoisgoingtowin('X'),'X');
        }
        else if (whoisgoingtowin('O') != -1) //step 7
		{
			Go(whoisgoingtowin('O'), 'X');
		}
		else{
            Go(getanyfreespace(),'X');
		}
    }


}
void TTT::game_mode1()
{
	    while(true)
        {

		cout << "Please Enter Player1's name(Hold X)" << endl;// Get player one's information
		cin >> player1;

		cout << "Please Enter Player2's name(Hold O)" << endl;// Player two's information
		cin >> player2;

		reset();//Reset the board
		mark = whogofirst(); //Pick who go first
		cout<<mark;
		do
		{
			cout << player1 << "----Hold X" << "          " << player2 << "----Hold O" << endl; // display who holding X and who holding O(this line would display
			                                                                                    // to the end of the game;
			Display();                                  //Show Board

			int move = getmove(GetTurn(mark));//Passing X or O into Turn function

			Go(move, mark);// Passing move to the moving function

			if (isWinner())     break;                  //game over

			mark =SwitchMark(mark);                      //Switch Turn

		} while (!isBlank());
		if (isWinner())
		{
			//Display who is the winner
			if (mark == 'X')cout << player1 << " won" << endl;
			else if (mark == 'O')cout << player2 << " won" << endl;
		}
		else if (isBlank())// if Board is full than no winner
		{

			cout << "Draw" << endl; //Draw;
		}
		cout<<"Do you want to start another game(T/F)";
		cin>>decistion;
		if(decistion=='F')break;
        }
	}

void TTT::game_mode2()
{
    int counter1=0,counter2=0,draw=0;
     mark = 'X';
     cout<<"HaHaHaHa, You will never beat me!!!!!!"<<endl;
     cout<<"I am a lazy computer, I will not move if the game going to be a draw"<<endl;
     cout<<"I hate draw"<<endl;
    while(true)
    {
		cout << "Please Enter Player2's name(Hold O)" << endl; // Get player's information.
		cin >> player2;
		reset();//Reset the board
		do
		{

			cout << "Computer" << "----Hold X" << "          " << player2 << "----Hold O" << endl; // display who holding X and who holding O(this line would display
																					// to the end of the game;
			cout << whoisgoingtowin(mark) << " Is the Key point" << endl;
			Computergo(mark,round);

			if (isWinner())     break;                  //game over

			Display();//Show Board

			mark=SwitchMark(mark);// Switch to player's turn.

			int move = getmove(GetTurn(mark));//Passing X or O into Turn function

			Go(move,(mark));// Passing move to the moving function
			round++;        //control computer move

            if (isWinner())     break;                  //game over

			mark =SwitchMark(mark);// make sure it switch back to X as what it initialize.

		} while (!isBlank());
		if (isWinner())
		{
			//Display who is the winner
			if (mark == 'X')
            {
                cout << "Computer" << " won" << endl;
                counter1++;
            }
			else if (mark == 'O')
            {
                cout << player2 << " won" << endl;
            counter2++;
            }
		}
		else if (isBlank())// if Board is full than no winner
		{

			cout << "Draw" << endl; //Draw;
			draw++;  //draw counter++
		}
		cout<<"Computer won: "<<counter1<<"times"<<endl;
			cout<<"Player won: "<<counter2<<"times"<<endl;
			cout<<"Draw:"<<draw<<"times"<<endl;
			cout<<endl;
			cout<<"Do you want to start another round(T/F)";
			cin>>decistion;
			if(decistion=='F')break;
			else
            {
                round=1;
                cout<<round<<endl;
            }
    }

}
void TTT::game_mode3()
{
    char decistion;
	    int counter1=0,counter2=0,draw=0;
		int getmove=0;
		int controlmove;
		while(true)
        {
		reset();//Reset the board
		mark = 'X';
		do
		{
			Display();
			cout << "Enter 1 to continue each move" << endl;
			cin >> controlmove;
			cout << "Computer 1----Hold X" << "           Computer 2----Hold O" << endl; // display who holding X and who holding O(this line would display
																				// to the end of the game;                                                              //Show Board
			if (controlmove == 1)
			{

				Go(randomplay(), mark);// Passing move to the moving function

				if (isWinner())     break;                  //game over

				mark =SwitchMark(mark);                      //Switch Turn
			}
			else break;
			} while (!isBlank());
			if (isWinner())
			{
				//Display who is the winner
				if (mark == 'X')
				{
                        cout << "Computer1 won" << endl;
                        counter1++;   //player 1 counter
				}
				else if (mark == 'O')
				{
				    cout << "Computer2 won" << endl;
				    counter2++;

				}
			}
			else if (isBlank())// if Board is full than no winner
			{

				cout << "Draw" << endl;
				draw++; //Draw;
			}
			cout<<"Computer 1 won: "<<counter1<<"times"<<endl;
			cout<<"Computer 2 won: "<<counter2<<"times"<<endl;
			cout<<"Draw:"<<draw<<"times"<<endl;
			cout<<endl;
			cout<<"Do you want to start another round(T/F)";
			cin>>decistion;
			if(decistion=='F')break;
        }
}
char TTT::getmark()
{
	return mark;   //return the mark inside TTT  private class to Main.cpp
}
int TTT::getanyfreespace() // go through every element check if there is a free element.
{
for(int i=0;i<9;i++)
{
    if(isFree(i))return -1;
    else return i;break;
}

}
TTT::TTT() //default Construct
{

}

TTT::~TTT()
{
}



