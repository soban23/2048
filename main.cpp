#include <iostream>
#include <ctime>
#include <cstdlib>
#include <conio.h>
using namespace std;

int Score = 0;

void Start_Random(int array[][4])
{
	int i, j;
	i = (rand() % 4);
	j = (rand() % 4);
	array[i][j] = 1;
	int x, y;
	x = (rand() % 4);
	y = (rand() % 4);
	while (i == x && j == y)
	{
		x = (rand() % 4);
		y = (rand() % 4);
	}
	array[x][y] = 1;
}

int gameover(int array[][4])
{
	int count = 0;
	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 4; y++)
		{
			if (array[x][y] != 0)
			{
				count++;
			}
		}
	}
	if (count == 16)
	{
		cout << endl
			 << "Move not possible" << endl;
		return 0;
	}
}

int random(int array[][4])
{
	int x;

	while (true)
	{
		int i, j;
		i = (rand() % 4);
		j = (rand() % 4);
		if (array[i][j] == 0)
		{
			array[i][j] = 1;
			break;
		}

		x = gameover(array);
		if (x == 0)
		{
			return 0;
		}
	}
}

void print(int array[][4])
{
	int row = 3, col = 6, x = 0, y = 0;

	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			if (i == row && j == col)
			{
				int num = array[x][y];
				if (num != 0)
				{
					cout << num;
				}
				else
				{
					cout << " ";
				}

				if (num > 9)
				{
					j += 1;
				}

				if (num > 99)
				{
					j += 1;
				}

				if (col == 42)
				{
					col = 6;
					y = 0;
					row += 6;
					x++;
				}
				else
				{
					col += 12;
					y++;
				}
			}
			else if (i == 0 || i == 24 || j == 0 || j == 49 || j == 12 || j == 24 || j == 36 || i == 6 || i == 12 || i == 18)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}
void shift_left(int array[][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (array[i][j] == 0 && array[i][j + 1] != 0)
			{
				array[i][j] = array[i][j + 1];
				array[i][j + 1] = 0;
				j = -1;
			}
		}
	}
}
void left(int array[][4])
{
	shift_left(array);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (array[i][j] == array[i][j + 1] && array[i][j] != 0)
			{
				array[i][j] = array[i][j] * 2;
				Score += array[i][j];
				array[i][j + 1] = 0;
				shift_left(array);
			}
		}
	}
}
void shift_up(int array[][4])
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (array[i][j] == 0 && array[i + 1][j] != 0)
			{
				array[i][j] = array[i + 1][j];
				array[i + 1][j] = 0;
				i = -1;
			}
		}
	}
}
void up(int array[][4])
{
	shift_up(array);
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (array[i][j] == array[i + 1][j] && array[i][j] != 0)
			{
				array[i][j] = array[i][j] * 2;
				Score += array[i][j];
				array[i + 1][j] = 0;
				shift_up(array);
			}
		}
	}
}

void shift_down(int array[][4])
{
	for (int j = 0; j < 4; j++)
	{
		for (int i = 3; i > 0; i--)
		{
			if (array[i][j] == 0 && array[i - 1][j] != 0)
			{
				array[i][j] = array[i - 1][j];
				array[i - 1][j] = 0;
				i = 4;
			}
		}
	}
}

void down(int array[][4])
{
	shift_down(array);
	for (int j = 0; j < 4; j++)
	{
		for (int i = 3; i > 0; i--)
		{
			if (array[i][j] == array[i - 1][j] && array[i][j] != 0)
			{
				array[i][j] = array[i][j] * 2;
				Score += array[i][j];
				array[i - 1][j] = 0;
				shift_down(array);
			}
		}
	}
}

void shift_right(int array[][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j > 0; j--)
		{
			if (array[i][j] == 0 && array[i][j - 1] != 0)
			{
				array[i][j] = array[i][j - 1];
				array[i][j - 1] = 0;
				j = 4;
			}
		}
	}
}

void right(int array[][4])
{
	shift_right(array);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j > 0; j--)
		{
			if (array[i][j] == array[i][j - 1] && array[i][j] != 0)
			{
				array[i][j] = array[i][j] * 2;
				Score += array[i][j];
				array[i][j - 1] = 0;
				shift_right(array);
			}
		}
	}
}
void game_win(int array[][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (array[i][j] == 2048)
			{
				cout << "YOU WIN";
			}
		}
	}
}
void score()
{
	cout << "SCORE = " << Score;
}

int check_gameover(int array[][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (array[i][j] == array[i][j + 1] || array[i][j] == 0)
			{
				return 1;
			}
		}
	}
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (array[i][j] == array[i + 1][j])
			{
				return 1;
			}
		}
	}
	for (int j = 0; j < 4; j++)
	{
		for (int i = 3; i > 0; i--)
		{
			if (array[i][j] == array[i - 1][j])
			{
				return 1;
			}
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j > 0; j--)
		{
			if (array[i][j] == array[i][j - 1])
			{
				return 1;
			}
		}
	}

	return 0;
}

int main()
{
	srand(time(0));

	int array[4][4] = {0};
	Start_Random(array);
	print(array);
	char key;

	while (1)
	{
		if (check_gameover(array) == 0)
		{
			cout << endl
				 << "GAME OVER";
			break;
		}
		cout << endl
			 << "Enter a key W, A, S, D" << endl;
		key = _getch();

		if (key == 'w')
		{
			system("cls");
			cout << "Moved Up" << endl
				 << endl;
			up(array);
		   random(array);
			print(array);
			score();
		}
		else if (key == 'a')
		{
			system("cls");
			cout << "Moved Left" << endl
				 << endl;
			left(array);
			random(array);
			print(array);
			score();
		}
		else if (key == 's')
		{
			system("cls");
			cout << "Moved Down" << endl
				 << endl;
			down(array);
			random(array);
			print(array);
			score();
		}
		else if (key == 'd')
		{
			system("cls");
			cout << "Moved Right" << endl
				 << endl;
			right(array);
			random(array);
			print(array);
			score();
		}

	
		game_win(array);
	}
}
