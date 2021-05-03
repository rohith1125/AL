//Created by Sai Rohith on 2021-05-03
//Copyright © 2021 Sai Rohith. All rights reserved.

//Recursive binary Search

#include <bits/stdc++.h> 
using namespace std; 

/* Function to sort the array using insertion sort*/
void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
        
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}  

int main()  
{  
    int arr[10];
    int n;
    cout << "Enter array size : ";
    cin >> n;
    for(int j=0;j<n;j++)
    {
        cin >> arr[j];
    }
    insertionSort(arr, n);  
    int i;  
    for (i = 0; i < n; i++)  
        cout << arr[i] << " ";  
    cout << endl;  

    return 0;  
}  