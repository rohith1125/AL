//Created by Sai Rohith on 2021-05-03
//Copyright © 2021 Sai Rohith. All rights reserved.

//Bubble Sort

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cout << "Enter size: ";
	int n;
	cin >> n;

	int a[n];
	cout << "Enter array elements: ";
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];

	for(int i = 0 ; i < n ; i++)
		for(int j = 0; j < n - i - 1 ; j++)
			if(a[j] > a[j + 1])
				swap(a[j], a[j + 1]);

	cout << "Sorted array: ";
	for(int i = 0 ; i < n ; i++)
		cout << a[i] << "  ";	
	
	return 0;
}

