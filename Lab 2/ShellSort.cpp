//Created by Sai Rohith on 2021-05-03
//Copyright © 2021 Sai Rohith. All rights reserved.

//Shell Sort


#include <iostream>
using namespace std;
int c;
void shellSort(int array[], int n) {
  // Rearrange elements at each n/2, n/4, n/8, ... intervals
  for (int interval = n / 2; interval > 0; interval /= 2,c++) {
    for (int i = interval; i < n; i += 1,c++) {
      int temp = array[i];
      int j;
      for (j = i; j >= interval && array[j - interval] > temp; j -= interval,c++) {
        array[j] = array[j - interval];
      }
      array[j] = temp;
    }
  }
}

// Print an array
void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++,c++)
    cout << array[i] << " ";
  cout << endl;
}

// Driver code
int main() {
  int data[] = {9, 8, 3, 7, 5, 6, 4, 1};
  int size = sizeof(data) / sizeof(data[0]);
  shellSort(data, size);
  cout << "Sorted array: \n";
  printArray(data, size);
   cout << "Step count:" << c / n << "n+ " << c % n << "\n";
}