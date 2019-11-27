/*
5. Using Dynamic Programming technique, write Program to solve Minimum Coin Changing Problem. 
In this problem the goal is to make change for an amount using least number of coins from the available denominations. 
*/

/*
Question 9a : Minimum coin change problem using Dynamic Programming
*/

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int *C, *d, *S;
/*
 d[] contains denominations;
 C[] contains the minimum coin change for an amount p, 0<=p<=A;
 S[] contains the coins selected to give minimum change
*/ 

void minCoinChange(int A, int n){
	C = new int[A+1];
	S = new int[A+1];
	
	int min;
	C[0] = 0; // base case
	S[0] = 0; 
	for(int p = 1; p<=A ;p++){
		min = INT_MAX;
		for(int i =0; i<n; i++)
			if(d[i]<=p)
				if(1+C[p-d[i]] < min){
					min = 1+C[p-d[i]];
					C[p] = min;
					S[p]= i;
				}//end of if
	}//end of outer loop
	cout<<"Minimum number of coins : "<<C[A]<<endl;
	cout<<"Coins in the optimal solution :\n";
	int a = A;
	while(a>0){
		cout<<d[S[a]]<<"\t";
		a = a - d[S[a]];
	}//end of loop	
	cout<<endl;
}//end of method

int main(){
	int A,n;
	cout<<"Enter number of denominations :";
	cin>>n;
	
	d = new int[n];
	cout<<"Enter the denominations in ascending order :";
	for(int i =0; i<n;i++) cin>>d[i];
	
	cout<<"Enter the amount : ";
	cin>>A; 
	
	minCoinChange(A,n);
	
	return 0;
}//end of main

/*
OUTPUT:
Enter number of denominations :3
Enter the denominations in ascending order :1 2 5
Enter the amount : 11
Minimum number of coins : 3
Coins in the optimal solution :
1	5	5	
*/
