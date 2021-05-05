//Created by Sai Rohith on 2021-05-03
//Copyright © 2021 Sai Rohith. All rights reserved.

//Selection Sort

#include <bits/stdc++.h>
using namespace std;

void s(int a, int b)
{
	a = a + b;
	b = a - b;
	a = a - b;
}

int main()
{
	cout << "Enter size: ";
	int n;
	cin >> n;

	int a[n];
	cout << "Enter array elements: ";
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];

	for(int i = 0 ; i < n - 1 ; i++)
	{
		int min = a[i], least = i;

		for(int j = i + 1 ; j < n ; j++)
		{
			if(a[j] < min)
			{
				min = a[j];
				least = j;
			}
		}

		s(a[i], a[least]);
	}

	cout << "Sorted array: ";
	for(int i = 0 ; i < n ; i++)
		cout << a[i] << "  ";

	return 0;
}