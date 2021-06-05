//Created by Sai Rohith on 2021-06-04
//Copyright © 2021 Sai Rohith. All rights reserved.

//Strassens Multiplication
#include<stdio.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;

int** create(int,int);
int** createNullMatrix(int);
int** strassensMultiplication(int **, int **,int);
int** standardMultiplication(int **,int **,int);
int** strassensMultRec(int **, int**,int n);
int** divide(int ** matrixA,int n, int row,int col);
void printMatrix(int **, int);
int ** add(int**,int**,int);
int** sub(int**,int**,int);
void compose(int**,int**,int,int,int);

int main() {
	int i=0,j=0,n=0;
	std::cout << "Enter n: ";
	std::cin >> n;
	if(n<1){
		printf("\nError: Invalid matrix dimension!\n\n");
		return 0;
	
	}
	int pow = 1;
	while(pow<n){
		pow=pow*2;
	}

	cout << "\nMatrix A: \n";
	int ** matrixA = new int*[n];
	for(int i = 0 ; i < n ; i++)
	{
		matrixA[i] = new int[n];
		for(int j = 0 ; j < n ; j++)
			cin >> matrixA[i][j];
	}
	
	cout << "\nMatrix B: \n";
		int ** matrixB = new int*[n];
	for(int i = 0 ; i < n ; i++)
	{
		matrixB[i] = new int[n];
		for(int j = 0 ; j < n ; j++)
			cin >> matrixB[i][j];
	}
	n = pow;
	int ** NormalResult,**StrassenResult;
	
	int ** stdRes = standardMultiplication(matrixA,matrixB,n);
	printf("\nStandard Multiplication Output:\n");
	printMatrix(stdRes,n);

	printf("\nStrassen's Multiplication Output:\n");
	int ** strassensRes = strassensMultiplication(matrixA,matrixB,n);
	printMatrix(strassensRes,n);
	cout<< "Time Complexity is O(n)"<< endl;
	return 0;
}
int ** create(int n,int pow){
	int ** array = createNullMatrix(pow);	
	int i,j;
	for(i = 0;i < n; i++) {
   	 	for(j = 0; j < n; j++) {
	    		array[i][j] = ((((int)rand())/((int)RAND_MAX) *10.0) - 5.0);
			}
	}
	return array;
} 
int ** createNullMatrix(int n){
	int ** array = (int**)malloc(n*sizeof(int *));	
	int i,j;
	for(i = 0;i < n; i++) {
	    	array[i] = (int*)malloc(n*sizeof(int));
   	 	for(j = 0; j < n; j++) {
	        	array[i][j] = 0.0;
	    	}
	}
	return array;
} 
void printMatrix(int ** matrix,int n) {
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cout << matrix[i][j] << " ";
		}
		printf("\n");
	}
}
int ** standardMultiplication(int ** matrixA,int ** matrixB,int n) {
	int ** result;
	int i,j,k;

	result = (int**)malloc(n*sizeof(int *));
	for(i=0;i<n;i++){
		result[i]=(int*)malloc(n*sizeof(int));
		for(j=0;j<n;j++){
			result[i][j]=0;
			for(k=0;k<n;k++) {
				result[i][j]=result[i][j]+(matrixA[i][k]*matrixB[k][j]);
			}		
		}
	}
	return result;
}

int ** strassensMultiplication(int ** matrixA, int** matrixB,int n){
	int ** result = strassensMultRec(matrixA,matrixB,n);
	return result;
}

int** strassensMultRec(int ** matrixA, int** matrixB,int n){
	int ** result = createNullMatrix(n);
	if(n>1) {
		//Divide the matrix
		int ** a11 = divide(matrixA, n, 0, 0);
		int ** a12 = divide(matrixA, n, 0, (n/2));
		int ** a21 = divide(matrixA, n, (n/2), 0);
		int ** a22 = divide(matrixA, n, (n/2), (n/2));	
		int ** b11 = divide(matrixB, n, 0, 0);
		int ** b12 = divide(matrixB, n, 0, n/2);
		int ** b21 = divide(matrixB, n, n/2, 0);
		int ** b22 = divide(matrixB, n, n/2, n/2);
		
		//Recursive call for Divide and Conquer
		int** m1= strassensMultRec(add(a11,a22,n/2),add(b11,b22,n/2),n/2);
		int** m2= strassensMultRec(add(a21,a22,n/2),b11,n/2);
		int** m3= strassensMultRec(a11,sub(b12,b22,n/2),n/2);
		int** m4= strassensMultRec(a22,sub(b21,b11,n/2),n/2);
		int** m5= strassensMultRec(add(a11,a12,n/2),b22,n/2);
		int** m6= strassensMultRec(sub(a21,a11,n/2),add(b11,b12,n/2),n/2);
		int** m7= strassensMultRec(sub(a12,a22,n/2),add(b21,b22,n/2),n/2);

		int** c11 = add(sub(add(m1,m4,n/2),m5,n/2),m7,n/2);
		int** c12 = add(m3,m5,n/2);
		int** c21 = add(m2,m4,n/2);
		int** c22 = add(sub(add(m1,m3,n/2),m2,n/2),m6,n/2);
		//Compose the matrix
		compose(c11,result,0,0,n/2);
		compose(c12,result,0,n/2,n/2);
		compose(c21,result,n/2,0,n/2);
		compose(c22,result,n/2,n/2,n/2);
	} 
	else {
		//This is the terminating condition for recurssion.
		result[0][0]=matrixA[0][0]*matrixB[0][0];
	}
	return result;
}

void compose(int** matrix,int** result,int row,int col,int n){
	int i,j,r=row,c=col;
	for(i=0;i<n;i++){
		c=col;
		for(j=0;j<n;j++){
			result[r][c]=matrix[i][j];	
			c++;	
		}
		r++;
	}
}

int** divide(int ** matrix,int n, int row,int col) {
	int n_new=n/2;	
	
	int ** array = createNullMatrix(n_new);	
	int i,j,r=row,c=col;
	for(i = 0;i < n_new; i++) {
		c=col;
   	 	for(j = 0; j < n_new; j++) {
        		array[i][j] = matrix[r][c];
			c++;
    		}
		r++;
	}
	return array;
}
int** add(int** matrixA,int** matrixB,int n){
	int ** result = createNullMatrix(n);
	int i,j;	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			result[i][j]=matrixA[i][j]+matrixB[i][j];
	
	return result;
}
int** sub(int** matrixA,int** matrixB,int n){
	int ** result = createNullMatrix(n);
	int i,j;	
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			result[i][j]=matrixA[i][j]-matrixB[i][j];
	
	return result;
}