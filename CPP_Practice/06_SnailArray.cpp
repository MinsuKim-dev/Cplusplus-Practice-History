#include <iostream>
using namespace std;
#include <iomanip>

const int SIZE = 100;
int board[SIZE][SIZE] = {};
int input;

void PrintBoard()
{
	for (int y = 0; y < input; y++)
	{
		for (int x = 0; x < input; x++)
		{
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		}
		cout << endl;
	}
}

// 방향 지정
enum Direction
{
	RIGHT = 0,
	DOWN = 1,
	LEFT = 2,
	UP =3,
};

// 갈 수 있는지 없는지
bool CanGo(int y, int x)
{
	if (y >= input || y < 0)
		return false;
	if (x >= input || x < 0)
		return false;
	if (board[y][x] != 0)
		return false;
	return true;
}

void SetBoard()
{
	int dir = RIGHT;
	int number = 1;
	int y = 0;
	int x = 0;

	int DirectionOfY[] = { 0, 1, 0, -1 };
	int DirectionOfX[] = { 1, 0, -1, 0 };

	while (true)
	{
		board[y][x] = number;

		if (number == input * input)
			break;

		int NEXT_Y = y + DirectionOfY[dir];
		int NEXT_X = x + DirectionOfX[dir];

		if (CanGo(NEXT_Y, NEXT_X) == true)
		{
			y = NEXT_Y;
			x = NEXT_X;
			number++;
		}
		else
		{
			dir = (dir + 1) % 4;
		}
	}
}

int main()
{
	cin >> input;
	SetBoard();
	PrintBoard();
}