#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void rec(int, int, int, int);
int lcm(int, int);

int lcm(int n1, int n2)
{
	// maximum value between n1 and n2 is stored in max
    int max = (n1 > n2) ? n1 : n2;
    do
    {
        if (max % n1 == 0 && max % n2 == 0)
        {
            return max;
        }
        else
            ++max;
    } while (true);
}

void print(std::vector<int> const &input)
{
	for (int i = 0; i < input.size(); i++) {
		std::cout << input.at(i) << ' ';
	}
}

vector<int> S_n_orders;
vector<int> A_n_orders;

void main()
{
	for (int i = 10; i <= 10; i++)
	{
	rec(i, 1, 1, 1);
	//cout << "S_" << i << " Length: " << S_n_orders.size() << " ";
	//print(S_n_orders);

	cout << "          A_" << i << " Length: " << A_n_orders.size() << " Orders:";
	print(A_n_orders);
	cout << endl;
	}

	int n;
	cin >> n;
}


void add(int lcm)
{
	bool is_found = false;
	for (int i = 0; i < S_n_orders.size(); i++)
	{
		if (lcm == S_n_orders.at(i))
		{
			is_found = true;
		}
	}

	if (!is_found)
	{
		S_n_orders.push_back(lcm);
	}
}

void add2(int lcm)
{
	bool is_found = false;
	for (int i = 0; i < A_n_orders.size(); i++)
	{
		if (lcm == A_n_orders.at(i))
		{
			is_found = true;
		}
	}

	if (!is_found)
	{
		A_n_orders.push_back(lcm);
	}
}

void rec(int n, int added, int lcm2, int sign)
{
	if (added <= n) // NOT PART
	{
		rec(n, added+1, lcm2, sign);
	}

	int j = 1;
	while (n - (added+1) * j >= 0) // PART
	{
		rec(n - (added+1) * j, added+1, lcm(lcm2, added+1), sign * (int)pow((double)-1, (double) j * (added)));
		j++;
	}

	if (n >= 0)
	{
		if (lcm2 == 20)
		{
			cout << "ORDER20";
		}
		//cout << lcm2;
		add(lcm2);
		if (sign == 1)
		{
		add2(lcm2);
		}
		//cout << endl;
	}
}
