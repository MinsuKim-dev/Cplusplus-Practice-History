#include <iostream>
using namespace std;

// ������ �ϴ� �Լ�
// 1) ���ڿ��� ����(ũ��)�� ����ϴ� �Լ�
// 2) ���ڿ� ���� �Լ�
// 3) ���ڿ��� �����̴� �Լ�
// 4) ���ڿ��� ���ϴ� �Լ�
// 5) ���ڿ��� ������ �Լ�

int StringLength(const char* str)
{
	int count = 0;
	while (str[count] != '\0')
		count++;
	return count;
}

#pragma warning(disable: 4996)
char* StringCopy(char* dest, char* src)
{
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return dest;
}

char* StringCat(char* dest, char* src)
{
	int i = 0;
	int size = StringLength(dest);
	while (src[i] != '\0')
	{
		dest[i + size] = src[i];
		i++;
	}
	dest[size + i] = '\0';
	return dest;
}

int StringCompare(char* cmp1, char* cmp2)
{
	int i = 0;
	while (cmp1[i] != '\0' || cmp2[i] != '\0')
	{
		 if (cmp1[i] < cmp2[i])
			 return -1;
		else if (cmp1[i] > cmp2[i])
			 return 1;
		 i++;
	}
	return 0;
}

void ReverseString(char* str)
{
	
	int strlen = StringLength(str);
	for (int i = 0; i < (strlen / 2); i++)
	{
		int tmep = str[i];
		str[i] = str[strlen - 1 - i];
		str[strlen - 1 - i] = tmep;
	}
}

int main()
{
	const int size = 20;
	char a[size] = "Hello";
	char b[size] = "World";
	char c[size] = "Hella";
}

