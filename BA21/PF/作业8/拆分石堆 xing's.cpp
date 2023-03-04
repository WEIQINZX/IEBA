#include<iostream>
#include<fstream>
#include<math.h>
#include <string.h>
#include <string>
using namespace std;
int main()
{
	int N = 0;
	scanf("%d", &N);
	int *num = new int[N];
	int detla = 0;
	if (N % 2 == 0)
		bool comb = true;
	else
		bool comb = false;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
		detla += num[i];
	}
	int temp;
	for (int i = 0; i < N/2; i++)
	{
		for (int j = i; j < N; j++)
		{
			if (num[i] > num[j])
			{
				temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
		detla -= num[i] * 2;
	}
	cout << detla << endl;
	delete[] num;
	return 0;
}
