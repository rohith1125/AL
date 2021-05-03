//Created by Sai Rohith on 2021-05-03
//Copyright © 2021 Sai Rohith. All rights reserved.

//Recursive binary Search

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int a[], int startIndex, int lastIndex, int key)
{
	if(startIndex > lastIndex)
		return -1;

	int mid = (lastIndex + startIndex) / 2;

	if(a[mid] == key)
		return mid;
	else if(a[mid] > key)
		return binarySearch(a, startIndex, mid - 1, key);
	else
		return binarySearch(a, mid + 1, lastIndex, key);

}

int main()
{
	cout << "Enter size: ";
	int n, key;
	cin >> n;

	int a[n];
	cout << "Enter sorted array elements: ";
	for(int i = 0 ; i < n ; i++)
		cin >> a[i];

	cout << "Enter element to be found: ";
	cin >> key;

	int pos = binarySearch(a, 0, n - 1, key);

	if(pos == -1)
		cout << "Element not found" << endl;
	else
		cout << "Found at: " << pos + 1 << endl;

	return 0;
}