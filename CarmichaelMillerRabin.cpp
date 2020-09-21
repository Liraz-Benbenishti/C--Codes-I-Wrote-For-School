#include <iostream>
#include <stdlib.h>     /* srand, rand */

using namespace std;

int gcd(int a, int b) { 
   if (b == 0) 
      return a; 
   return gcd(b, a % b);  
} 

long long int superpower(long long int x, long long int k, long long int n)
{
	long long int result;
	if (k == 1)
	{
		result = x;
		return result;
	}
	if (k % 2 == 0)
	{
		long long int result3 = superpower(x, k/2, n) % n;
		result = (result3 * result3) % n;
	}
	else if (k % 2 == 1)
	{
		long long int result3 = superpower(x, k/2, n) % n;
		long long int result2 = (result3 * result3) % n;
		result = (x * result2) % n;		
	}
	return result;
}

bool isCarmichaelNumber(int n)
{
	for (int b = 1; b <= n; b++)
	{
		if (gcd(b,n) == 1)  // Check if they are co-prime.
		{
			if (superpower(b, n-1, n) != 1)
			{
				return false;
			}
		}
	}
	return true;
}

bool MillerRabinAlgo(int n, int k)
{
	int s = 0;
	int M;
	int temp = n-1;
	while (temp % 2 == 0)
	{
		s++;
		temp/=2;
	}
	M = temp;

	for (int i = 1; i <= k; i++)
	{
		int a = rand() % (n - 3) + 2; // [0+2,n-4+2] -> [2, n-2]
		int x = superpower(a, M, n); // x <- a^M		
		if (x == 1 || x == n-1)
		{
			cout << a << " is strong witness for prime" << endl;
			continue;
		}

		bool is_strong_witness = false;
		for (int j = 1; j <= s - 1; j++)
		{
			x = superpower(x, 2, n);
			if (x == 1)
			{
				//cout << x << "=" << a << "^(2^" << j << "*" << M << ") (mod" << n << ")=" << 1 << endl;
				cout << a << " is witness for composition (non-prime)" << endl;
				return false;
			}
			else if (x == n - 1)
			{
				cout << a << " is strong witness for prime" << endl;
				is_strong_witness = true;
			}
		}
		if (is_strong_witness)
		{
			continue;
		}
		else
		{
			//cout << x << "=" << a << "^(2^" << s << "*" << M << ") (mod" << n << ")" << endl;
			cout << a << " is witness for composition (non-prime)" << endl;
			return false;
		}
	}
	cout << "Maybe prime" << endl;
	return true;
}

void main()
{
	cout << "Is 41041 a carmichael number? " << isCarmichaelNumber(41041) << endl;
	int counter_for_witness = 0;
	while (counter_for_witness < 5)
	{
		if (!MillerRabinAlgo(41041, 1))
		{
			counter_for_witness++;
		}
	}
int n;
cin >> n;
}
