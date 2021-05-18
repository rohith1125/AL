//Created by Sai Rohith on 2021-05-18
//Copyright © 2021 Sai Rohith. All rights reserved.

//Knapsack greedy on profit
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, c;
    cout << "Enter no of items: ";
    cin >> n;
    cout << "Enter capacity of knapsack: ";
    cin >> c;

    cout << "Enter weights: ";
    double weights[n], index[n], costs[n];
    for(int i = 0 ; i < n ; i++)
    {
        index[i] = i + 1;
        cin >> weights[i];
    }

    cout << "Enter costs: ";
    for(int i = 0 ; i < n ; i++)
        cin >> costs[i];
    
    for(int i = 0 ; i < n ; i++)
        for(int j = 0; j < n - i - 1 ; j++)
            if(costs[j] <= costs[j + 1])
            {
                swap(index[j], index[j + 1]);
                swap(costs[j], costs[j + 1]);
                swap(weights[j], weights[j + 1]);
            }

    int k = 0, RemCapacity = 0;
    
    while(k < n && RemCapacity + weights[k] <= c)
    {
        RemCapacity += weights[k];
        k++;
    }

    cout << "Selected items are: ";
    for(int i = 0 ; i < k ; i++)
        cout << index[i] << " ";

    return 0;
}

/*
5
20
5 4 10 20 3
5 10 100 200 3
*/