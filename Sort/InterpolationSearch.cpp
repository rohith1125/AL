//Created by Sai Rohith on 2021-05-03
//Copyright © 2021 Sai Rohith. All rights reserved.

//Interpolation Search

#include<bits/stdc++.h>
using namespace std;


int interpolationSearch(int arr[], int n, int x)
{

	int Min = 0, Max = (n - 1);
     

	while (Min <= Max && x >= arr[Min] && x <= arr[Max])
	{    
	     
		if (Min == Max)
		{    
			if (arr[Min] == x) return Min;
			 
			return -1;
		}
		 
		 

		int pos = Min + (((double)(Max - Min) /
			(arr[Max] - arr[Min])) * (x - arr[Min]));
         

		if (arr[pos] == x){ 
			return pos;}


		if (arr[pos] < x){ 
			Min = pos + 1;}


		else{
			Max = pos - 1;}
	}
	return -1;
}


int main()
{
    int c=0;
	int arr[] = {10, 12, 13, 16, 18, 19, 20, 21,
				22, 23, 24, 33, 35, 42, 47};
	int n = sizeof(arr)/sizeof(arr[0]);

	int x = 18;
	int index = interpolationSearch(arr, n, x);


	if (index != -1)
		cout << "Element found at index " << index;
	else
		cout << "Element not found.";
	return 0;
}