//Created by Sai Rohith on 2021-05-03
//Copyright © 2021 Sai Rohith. All rights reserved.

//Selection Sort

#include <bits/stdc++.h>
int c = 0;
using namespace std;

int main()
{
    cout << "Enter size: ";
    int n;
    cin >> n;

    int a[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++, c++)
        cin >> a[i];

    for (int i = 0; i < n - 1; i++, c++)
    {
        int min = a[i], least = i;

        for (int j = i + 1; j < n; j++, c++)
        {
            if (a[j] < min)
            {
                min = a[j];
                least = j;
            }
        }
        int temp = a[i];
        a[i] = a[least];
        a[least] = temp;
        c += 3;
    }

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++, c++)
        cout << a[i] << "  ";

    cout << "Step count:" << c / n << "n+ " << c % n << "\n";
    
    
    cout << "Stepcount:";
    if (c >= n * n)
    {
        cout << c / (n * n) << "n^2+ ";
        c = c % (n * n);
    }
    cout << c / n << "n+ " << c % n << "\n";
    return 0;
}