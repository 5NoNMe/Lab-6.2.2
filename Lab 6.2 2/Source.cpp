#include <iostream>
#include <iomanip>
#include <time.h>
#include <windows.h>

using namespace std;

void Input(int* a, const int size, int i) {
	cout << "a[" << i << "] = ";
	cin >> a[i];
	if (i < size - 1)
		Input(a, size, i + 1);
	else
		cout << endl;
}

void Print(int* a, const int size, int i)
{
	cout << a[i] << ' ';
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}

void indexLowwer(int* a, const int size, int min, int imin, int i, bool flag)
{
	if (i < size)
	{
		if ((a[i] % 2) != 0)
		{
			if (!flag)
			{
				flag = true;
				min = a[i];
				imin = i;
			}
			else if (min > a[i])
			{
				min = a[i];
				imin = i;
			}

		}
		indexLowwer(a, size, min, imin, i + 1, flag);
	}
	else
	{
		if (!flag)
		{
			cout << "Всі числа парні. " << endl;
		}
		else
		{
			cout << "Індекс найменшого непарного елемента масиву: " << imin << endl;
		}
	}

}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));

	int n = 0;
	cout << "Введіть розмір масиву: "; cin >> n;
	int* a = new int[n];

	Input(a, n, 0);
	Print(a, n, 0);
	indexLowwer(a, n, a[0], 0, 0, false);

	delete[] a;

	return 0;
}