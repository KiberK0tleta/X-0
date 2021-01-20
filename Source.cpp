#include<iostream>
#include<conio.h>


using namespace std;

void PrintField(char field[], const int n, char player); //вывод поля
void Move(char field[], const int n, char player); //ходы
void Check(char field[], const int n, char player); //проверка на победу



#define OFFSET_TOP "\n\n\n\n\n\n"
#define OFFSET_LEFT "\t\t\t\t\t"
void main()
{
	setlocale(LC_ALL, "Rus");
	do
	{
		const int n = 9;
		char field[n] = {};
		PrintField(field, n, '0');
		cout << "Для выхода нажмите Esc, для того чтобы сыграть ещё раз нажмите любую клавишу \n";
	} while (_getch() != 27);
}
void PrintField(char field[], const int n, char player)
{
	system("CLS");
	//system("color E4");
	cout << OFFSET_TOP;
	for (int i = 6; i >= 0; i -= 3)
	{
		cout << OFFSET_LEFT << " ";

		for (int j = 0; j < 3; j++)
		{
			cout << " ";
			cout << field[i + j];
			if (j != 2) cout << " | ";
		}
		cout << endl;
		cout << OFFSET_LEFT;
		if (i != 0)
		{
			cout << "--- --- ---";
		}
		cout << endl;
	}
	Check(field, n, player);
}
void Move(char field[], const int n, char player)
{
	char key;
	bool busy;
	do
	{
		busy = false;
		do
		{
			key = _getch();
			if (key == 27)return;
			if ((key < '1' || key>'9') && key != 27)cout << "ERROR ";
		} while (key < '1' || key>'9');
		if (field[key - 49] != 0)
		{
			busy = true;
			cout << "Клетка уже занета \n";
		}
		else field[key - 49] = player;

	} while (busy);
	PrintField(field, n, player);
}
void Check(char field[], const int n, char player)
{
	bool game_over = false;
	//Диагонали
	if (
		field[0] == field[4] && field[4] == field[8] && field[8] != 0 ||
		field[2] == field[4] && field[4] == field[6] && field[6] != 0
		) game_over = true;
	//Горизонтали
	for (int i = 0; i < 7; i += 3)
	{
		if (field[i] == field[i + 1] && field[i] == field[i + 2] && field[i] != 0)game_over = true;
	}
	//Вертикали
	for (int i = 0; i < 3; i++)
	{
		if (field[i] == field[i + 3] && field[i] == field[i + 6] && field[i] != 0)game_over = true;
	}
	bool drow = true;
	for (int i = 0; i < n; i++)
	{
		if (field[i] == 0)
		{
			drow = false;
			break;
		}
	}
	
	if (!game_over && drow)
	{
		cout << "Ничья! \n";
		return;
	}
	{

	}
	if (game_over)
	{
		cout << player << " WIN!!!" << endl;
		return;
	}
	else
	{
		if (player == 'X')Move(field, n, '0');
		else Move(field, n, 'X');
	}
	
}