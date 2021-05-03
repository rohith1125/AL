//Created by Sai Rohith on 2021-05-03
//Copyright © 2021 Sai Rohith. All rights reserved.

//Binary Search

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int *a, int n, int key)
{
	//static int count = 0;
	int first = 0, last = n - 1;
	while(first <= last)
	{
		int mid = (last + first) / 2;

		if(a[mid] == key)
			return mid;
		else if(a[mid] > key)
			last = mid -1;
		else
			first = mid + 1;
	}

	return -1;
}

int main()
{
	cout << "Enter size: ";
	int n, key;
	cin >> n;

	int a[n];
	cout << "Enter sorted array: ";
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];

	cout << "Enter key element: ";
	cin >> key;

	int pos = binarySearch(a, n, key);

	if(pos == -1)
		cout << "Element not found" << endl;
	else
		cout << "Found at position: " << pos + 1 << endl;

	return 0;
}
