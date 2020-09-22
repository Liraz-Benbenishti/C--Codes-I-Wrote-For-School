#include <iostream>
#include <math.h>

using namespace std;

int factorial(int n)
{
	int result = 1;

	for (int i = 1; i <= n; i++)
	{
		result *= i;
	}

	return result;
}

void rec(int, int, int);

void main()
{
	int = 1234;
   permute(a, 0, 3);

	int n = 5;
	rec(3, 0, 0);
	/*int combinations_number = factorial(n); // 7
	for (int i = 0; i < combinations_number; i++)
	{
		int a = i / factorial(n-1) + 1;
		cout << a << " ";
		int b = ((i % factorial(n-1)) / factorial(n-2) + a) % n + 1;
		cout << b << " ";
		int c = ((i % factorial(n-2)) / factorial(n-3) + b) % n + 1;
		cout << c << " ";
		int d = ((i % factorial(n-3)) / factorial(n-4) + c) % n + 1;
		cout << c << endl;
	}*/

	 cin >> n;
}

void permute(int a, int i, int n)
{
   int j;
   if (i == n)
     cout << a << endl;
   else
   {
       for (j = i; j <= n; j++)
       {
		   int temp_i = (a / (pow((double) 10, (double) i))) % 10;
		   int temp_j = (a / (pow((double) 10, (double) j))) % 10;
          swap(a[i], a[j]);          
          permute(a, i+1, n);
          swap(a[i], a[j]);
       }
   }
} 
