#include <iostream>
#include <cmath>

using namespace std;

long NOD(long a, long b)
{
	while (a > 0 && b > 0)

		if (a > b)
			a %= b;

		else
			b %= a;

	return a + b;
}


int main()
{
	long n;
	cin >> n;
	long* pArrayX = new long[n];
	long* pArrayY = new long[n];

	for (int i = 0; i < n; i++)
	{
		cin >> pArrayX[i];
		cin >> pArrayY[i];
	}

	long summ = 0;

	for (int i = 0; i < n - 1; i++)
	{
		summ += pArrayX[i] * pArrayY[i + 1];
		summ -= pArrayX[i + 1] * pArrayY[i];
	}

	summ += pArrayX[n - 1] * pArrayY[0];
	summ -= pArrayX[0] * pArrayY[n - 1];


	bool bFlag = false;

	if (summ % 2 == 0)
		summ = 0.5 * fabs(summ);
	else
	{
		summ = 0.5 * (fabs(summ) - 1);
		bFlag = true;
	}

	long countPointInEdge = n;
	long nod;
	long size = 0;

	for (int i = 0; i < n - 1; i++)
	{
		nod = NOD(fabs(pArrayX[i + 1] - pArrayX[i]), fabs(pArrayY[i + 1] - pArrayY[i])) + 1;
		size += nod - 2;
	}
	
	nod = NOD(fabs(pArrayX[n - 1] - pArrayX[0]), fabs(pArrayY[n - 1] - pArrayY[0])) + 1;
	size += nod - 2;
	countPointInEdge += size;
	long countPointInSide;

	if (bFlag)
	{
		countPointInEdge -= 1;
		countPointInSide = summ + 1 - countPointInEdge / 2;
		countPointInEdge += 1;
	}
	else
		countPointInSide = summ + 1 - countPointInEdge / 2;
	

	cout << countPointInSide << " " << countPointInEdge << endl;
}