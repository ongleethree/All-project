#include <stdio.h>
#include <iostream>
#include <ctime>


using namespace std;

// define typedef struct of player_1
typedef struct
{
	int choose;
	char space[9];
	char select_symbol;

}player_1;

// define typedef struct of player_bot
typedef struct
{
	int choose;
	char space[9];
	char select_symbol_bot;

}player_2;

// define typedef struct of Board_system
typedef struct
{
	bool running;
	char space[9];
	char winner;

}Board_system;

// Define funtion board to collect a number of space 
void drawnBoard(char* space);

// Define funtion play game inside funtion together with struct of player_1 point Robin_plyer
// In this funtion Robin_player can use any valueable in player_1 struct
//We can say Robin_player Return a value of choose type intiger

void play(player_1* Robin_player, Board_system* drawn);

//Define funtion of borad system for Define a number of index in space

void system_of_board(Board_system* drawn);

// Define player_1 is a datatype of Robin That Robin can use any data in player_1 function

void bot_play(player_2* Robin_bot, Board_system* drawn);

bool check_winner(player_1* Robin_player,player_2* Robin_bot, Board_system* drawn);

player_1 Robin;
player_2 Bot;
Board_system board;


int main()
{
	//Define a member of Robin name select_symbol that collect type char value = X
	Robin.select_symbol = 'X';
	Bot.select_symbol_bot = 'O';
	board.running = true;
	
	system_of_board(&board);

	while (board.running)
	{
		drawnBoard(board.space);
		play(&Robin, &board);
		drawnBoard(board.space);
		
		
		if (check_winner(&Robin, &Bot, &board))
		{
			board.running = false;
		
	    }
		bot_play(&Bot, &board);
		drawnBoard(board.space);
		if (check_winner(&Robin, &Bot, &board))
		{

			board.running = false;

		}
	}


}

//Define board funtion for print out from teminal show the reasult

void drawnBoard(char* space)
{

	cout << "     |     |     " << "\n";
	cout << "  " << space[0] << "  |  " << space[1] << "  |  " << space[2] << "   \n";
	cout << "_____|_____|_____" << "\n";
	cout << "     |     |     " << "\n";
	cout << "  " << space[3] << "  |  " << space[4] << "  |  " << space[5] << "   \n";
	cout << "_____|_____|_____" << "\n";
	cout << "     |     |     " << "\n";
	cout << "  " << space[6] << "  |  " << space[7] << "  |  " << space[8] << "   \n";
	cout << "     |     |     " << "\n";


}

void play(player_1* Robin_player, Board_system* drawn)
{


	bool choice = true;

	while (choice)
	{
		cout << "enter number for spot 0-8 = ";
		cin >> Robin_player->choose;

		if (Robin_player->choose > 8 || Robin_player->choose > 0)
		{
			Robin_player->choose--;
			if (drawn->space[Robin_player->choose] == ' ')
			{
				drawn->space[Robin_player->choose] = Robin_player->select_symbol;
				break;
			}
		}
		else 
		{
			cout << "Error choice choose a new one ";
		}
			
			
		
	}
}

void system_of_board(Board_system* drawn)
{
	for (int i = 0; i < 9; i++)
	{
		drawn->space[i] = ' ';
	}
}

void bot_play(player_2* Robin_bot, Board_system* drawn)
{
	bool bot_choice = true;

	srand(time(0));

	while (bot_choice)
	{
		Robin_bot->choose = rand() % 9;
		if (drawn->space[Robin_bot->choose] == ' ')
		{
			drawn->space[Robin_bot->choose] = Robin_bot->select_symbol_bot;
			break;
		}
	}
}


bool check_winner(player_1* Robin_player, player_2* Robin_bot, Board_system* drawn)
{

	if (drawn->space[0] != ' ' && drawn->space[0] == drawn->space[1] && drawn->space[1] == drawn->space[2])

	{

		drawn->space[0] == Robin_player->select_symbol ? cout << "YOU WIN \n" : cout << "YOU  LOSE\n";

	}
	else

	if (drawn->space[0] != ' ' && drawn->space[0] == drawn->space[3] && drawn->space[3] == drawn->space[6])

	{

		drawn->space[0] == Robin_player->select_symbol ? cout << "YOU WIN \n" : cout << "YOU  LOSE\n";

	}
	else

	if (drawn->space[1] != ' ' && drawn->space[1] == drawn->space[4] && drawn->space[4] == drawn->space[7])

	{

		drawn->space[1] == Robin_player->select_symbol ? cout << "YOU WIN \n" : cout << "YOU  LOSE\n";

	}
	else

	if (drawn->space[2] != ' ' && drawn->space[2] == drawn->space[5] && drawn->space[5] == drawn->space[8])

	{

		drawn->space[2] == Robin_player->select_symbol ? cout << "YOU WIN \n" : cout << "YOU  LOSE\n";

	}
	else

	if (drawn->space[6] != ' ' && drawn->space[6] == drawn->space[7] && drawn->space[7] == drawn->space[8])

	{

		drawn->space[6] == Robin_player->select_symbol ? cout << "YOU WIN \n" : cout << "YOU  LOSE\n";

	}
	else

	if (drawn->space[3] != ' ' && drawn->space[3] == drawn->space[4] && drawn->space[4] == drawn->space[5])

	{

		drawn->space[3] == Robin_player->select_symbol ? cout << "YOU WIN \n" : cout << "YOU  LOSE\n";

	}
	else

	if (drawn->space[0] != ' ' && drawn->space[0] == drawn->space[4] && drawn->space[4] == drawn->space[8])

	{

			drawn->space[0] == Robin_player->select_symbol ? cout << "YOU WIN \n" : cout << "YOU  LOSE\n";

	}
	else

	if (drawn->space[2] != ' ' && drawn->space[2] == drawn->space[4] && drawn->space[4] == drawn->space[6])

	{

		drawn->space[2] == Robin_player->select_symbol ? cout << "YOU WIN \n" : cout << "YOU  LOSE\n";

	}
	else

	return(0);
}