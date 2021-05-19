//Created by Sai Rohith on 2021-05-18
//Copyright © 2021 Sai Rohith. All rights reserved.

//Container Loading
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int c = 0;
void makeHeap(int arr[], int n, int i)
{
    c++;

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        makeHeap(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{

    for (int i = n / 2 - 1; i >= 0; i--, c++)
        makeHeap(arr, n, i);

    for (int i = n - 1; i >= 0; i--, c++)
    {
        swap(arr[0], arr[i]);

        makeHeap(arr, i, 0);
    }
}
bool *load_container(int max, int *weights, int n)
{
    heapSort(weights, n);
    int temp = max;
    bool *taken = new bool[n];
    int i = 0;
    while (i < n)
    {
        c++;
        if ((max - weights[i]) >= 0)
        {
            max -= weights[i];
            taken[i] = true;
        }
        else
            break;
        i++;
    }
    cout << "Weight used:" << temp - max << endl;
    return taken;
}

int main()
{
    int max = 0;
    int n;
    cout << "Enter number of objects:";
    cin >> n;
    int arr[n];
    cout << "Enter the weights of the objects";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (max < arr[i])
            max = arr[i];
    }

    bool *taken = load_container(max, arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << "-> " << taken[i] << endl;
    cout << "\nTotal no.of Steps:" << c << "\n";
    cout << "Time Complexity: ";
    if (c >= n * log2(n))
    {
        cout << c / ((int)(n * log2(n))) << "nlogn+ ";
        c = c % ((int)(n * log2(n)));
    }
    cout << c / n << "n+ " << c % n << "\n";
}