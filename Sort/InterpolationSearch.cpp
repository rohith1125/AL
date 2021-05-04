#include<iostream>
using namespace std;
int interpolationSearch(int array[], int begin, int end, int key) {
   int dist, valRange, indexRange, predict;
   float fraction;
   while(begin <= end && key >= array[begin] && key <= array[end]) {
      dist = key - array[begin];
      valRange = array[end] - array[begin];     //range of value
      fraction = dist / valRange;
      indexRange = end - begin;
      predict = begin + (fraction * indexRange);      //predictd position of the key
      if(array[predict] == key)
         return predict;
      if(array[predict] < key)
         begin = predict +1;
      else
         end = predict - 1;
   }
   return -1;
}
int main() {
   int n, searchKey, loc;
   cout << "Enter number of items: ";
   cin >> n;
   int arr[n];      //create an array of size n
   cout << "Enter items: " << endl;
   for(int i = 0; i< n; i++) {
      cin >> arr[i];
   }
   cout << "Enter search key to search in the list: ";
   cin >> searchKey;
   if((loc = interpolationSearch(arr, 0, n-1, searchKey)) >= 0)
      cout << "Item found at location: " << loc << endl;
   else
      cout << "Item is not found in the list." << endl;
}