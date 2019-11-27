/*
2. Using Dynamic Programming technique, write program to solve 0-1 knapsack problem. Given weights and values of n items, 
put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer 
arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an 
integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of 
this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (
0-1 property).
*/

// Lab 7b, Knapsack Problem
#include <iostream>
#include <cmath>
using namespace std;

void DPKnapsack(int *wt, int *val,int n, int W){
	// using bottom up approach to solve knapsack problem
	// wt must be a sorted array
	int i,j;
	int dp[n+1][W+1]; // matrix to store results
	for(i=0; i<=n; i++) dp[i][0] = 0;
	for(j=1 ; j<=W; j++) dp[0][j] = 0;
	//solving the knapsack problem
	for(i = 1; i<=n ; i++){
		for(j = 1; j<=W; j++){
			if(j-wt[i] >= 0)
				dp[i][j] = max(dp[i-1][j], val[i]+dp[i-1][j-wt[i]]);
			else
				dp[i][j] = dp[i-1][j];
		}//end of for
	}//end of for
	
	cout<<"\nMaximum value : "<<dp[n][W]<<endl;
	// printing items to be included
	cout<<"Include items with weight : ";
	i = n;
	j = W;
	int sum = 0;
	while(i>0 && j>0){
		if(dp[i-1][j] == dp[i][j]) i--;
		else{
			if(dp[i][j] == dp[i-1][j-wt[i]]+val[i]){
				cout<<"Wt :"<<wt[i]<<" Val :"<<val[i]<<"\t";
				sum += val[i];
				j = j-wt[i];
				i--;
			}//end of if
		}//end of else
	}//end of while
	if(sum == dp[n][W]) cout<<endl;
	else 
		cout<<"Wt :"<<wt[i]<<" Val :"<<val[i]<<"\n";
}//end of method

int main(){
	int *wt, *val, n, W;
	cout<<"Enter Knapsack capacity : ";
	cin>>W;
	cout<<"Enter number of items : ";
	cin>>n;
	wt = new int[n+1];
	val = new int[n+1];
	cout<<"Enter weight and value :\n";
	for(int i =1; i<=n; i++){
		cin>>wt[i];
		cin>>val[i];
	}// end of for
	DPKnapsack(wt, val, n, W);
}//end of main

/*
OUTPUT:
Enter Knapsack capacity : 5
Enter number of items : 4
Enter weight and value :
1 10
2 12
2 15
3 20

Maximum value : 37
Include items with weight : Wt :2 Val :15	Wt :2 Val :12	Wt :1 Val :10	
*/
