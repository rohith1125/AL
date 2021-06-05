//Created by Sai Rohith on 2021-06-04
//Copyright © 2021 Sai Rohith. All rights reserved.

//Multiplication Chains
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int c = 0;
int MatrixChainOrder(int p[], int i, int j)
{
 c++;
 if (i == j)
 return 0;
 int k;
 int min = INT_MAX;
 int count;
 c++;
 for (k = i; k < j; k++)
 {
 c++;
 count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[
i - 1] * p[k] * p[j];
 c++;
 if (count < min)
 min = count;
 }
 c++;
 return min;
}
int main()
{
 int size;
 cout << "Enter size " << endl;
 cin >> size;
 int arr[size];
 for (int i = 0; i < size; i++)
 cin >> arr[i];
 cout << "Minimum number of multiplications is " << MatrixChainOrder(arr, 1, size - 1);
 cout << "\nStep count " << c << endl;
}