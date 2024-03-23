#include <iostream>
using namespace std;

// 로또 번호 생성기 연습 문제

// 1) Swap 함수 만들기 (두 수를 바꿔주는 함수)
// 2) 정렬 함수 만들기 (숫자가 적을 수록 먼저 오도록)
// 3) 1 ~ 45의 랜덤 숫자를 만들어 내는 함수 (중복이 없어야 함)
// 4) 번호를 출력하는 함수

void Swap(int* a, int* b) // 임시 저장 데이터 생성
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Sort(int* number, int count) // 승자 방식
{
	for (int i = 0; i < count; i++)
	{
		int Winner = i;
		for (int j = i + 1; j < count; j++)
		{
			if(number[j] < number[Winner])
				Winner = j;
		}

		if (i != Winner)
			Swap(&number[i], &number[Winner]);
	}
}

void GeratorLottoNumber(int* number)
{
	int NumberCount = 0;

	while (NumberCount != 6)
	{
		int RandomNumber = 1 + (rand() % 45);
		bool isSameNumber = false;

		for (int i = 0; i < NumberCount; i++)
		{
			if (number[i] == RandomNumber)
			{
				isSameNumber = true;
				break;
			}
		}

		if (isSameNumber == false)
		{
			number[NumberCount] = RandomNumber;
			NumberCount++;
		}
		Sort(number, NumberCount);
	}
}

void PrintNumber(int* number)
{
	for (int i = 0; i < 6; i++)
	{
		cout << number[i] << " ";
	}
	cout << endl;
}

int main()
{
	srand((unsigned)time(nullptr));

	const int size = 6;
	int Number[size] = { };

	GeratorLottoNumber(Number);
	PrintNumber(Number);
}