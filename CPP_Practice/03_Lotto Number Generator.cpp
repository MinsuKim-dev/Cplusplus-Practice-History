#include <iostream>
using namespace std;

// �ζ� ��ȣ ������ ���� ����

// 1) Swap �Լ� ����� (�� ���� �ٲ��ִ� �Լ�)
// 2) ���� �Լ� ����� (���ڰ� ���� ���� ���� ������)
// 3) 1 ~ 45�� ���� ���ڸ� ����� ���� �Լ� (�ߺ��� ����� ��)
// 4) ��ȣ�� ����ϴ� �Լ�

void Swap(int* a, int* b) // �ӽ� ���� ������ ����
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void Sort(int* number, int count) // ���� ���
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