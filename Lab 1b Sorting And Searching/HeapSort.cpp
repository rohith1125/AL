//Created by Sai Rohith on 2021-05-03
//Copyright © 2021 Sai Rohith. All rights reserved.

//Heap Sort

#include <iostream>
  using namespace std;
  int c=0;
  void makeHeap(int arr[], int n, int i) {
  c++;
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue makeHeaping if root is not largest
    if (largest != i) {
      swap(arr[i], arr[largest]);
      makeHeap(arr, n, largest);
    }
  }
  
  // main function to do heap sort
  void heapSort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--,c++)
      makeHeap(arr, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--,c++) {
      swap(arr[0], arr[i]);
  
      // makeHeap root element to get highest element at root again
      makeHeap(arr, i, 0);
    }
  }
  
  // Print an array
  void printArray(int arr[], int n) { 
    for (int i = 0; i < n; ++i,c++)
      cout << arr[i] << " ";
    cout << "\n";
  }
  
  // Driver code
  int main() {
    int arr[100];
    int n;
    cout<<"input n"<<endl;
    cin>>n;
    cout<<"enter array elements";
    for(int j =0;j<n;j++,c++)
    {
      cin>>arr[j];
    }
    
    heapSort(arr, n);
  
    cout << "Sorted array is \n";
    printArray(arr, n);
    
       cout << "Step count:" << c / n << "n+ " << c % n << "\n";
   cout << "Stepcount:";
    if (c >= n * n)
    {
        cout << c / (n * n) << "n^2+ ";
        c = c % (n * n);
    }
    cout << c / n << "n+ " << c % n << "\n";
  }