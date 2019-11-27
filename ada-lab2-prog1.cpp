/*
1. Using Dynamic Programming technique, write program for Printing Longest Common Subsequence (LCS): Given two sequences, 
print the longest subsequence present in both of them.
Examples:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.
*/

// Lab 7a-Longest Common Subsequece
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

//finds length of lcs and print it
void lcs(char *x, char *y, int m, int n){
	int L[m+1][n+1];
	int i,j;
	//buliding L[m+1][n+1] in bottom up fashion
	for(i = 0; i<=m;i++){
		for(j =0;j<=n;j++){
			if(i==0 || j==0) L[i][j] = 0;
			else if(x[i-1] == y[j-1])
				L[i][j] = L[i-1][j-1]+1;
			else
				L[i][j] = max(L[i-1][j],L[i][j-1]);
		}//end of for
	}//end of for
	cout<<"Length of LCS : "<<L[m][n]<<endl;
	
	// printing one of the lcs
	int index = L[m][n];
	char seq[index+1]; // stores the lcs
	seq[index] = '\0'; // setting terminating character
	i = m;
	j = n;
	while(i>0 && j>0){
		if(x[i-1] == y[j-1]){
			seq[index-1] = x[i-1];
			i--;
			j--;
			index--;
		}//end of if
		else if(L[i-1][j] > L[i][j-1]) i--; //move up
		else j--; // move right
	}//end of while
	cout<<"The Longest Common Subsequence is : ";
	for(i = 0; i<=L[m][n]; i++)
		cout<<seq[i];
	cout<<endl;
}//end of method

int main(){
	char *x, *y;
	string s1, s2;
	cout<<"Enter first string : ";
	cin>>s1;
	cout<<"Enter second string : ";
	cin>>s2;
	x = new char[s1.length()+1];
	strcpy(x,s1.c_str());
	y = new char[s2.length()+1];
	strcpy(y,s2.c_str());
	
	lcs(x,y, s1.length(), s2.length());
	
	return 0;
}// end of main

/*
OUTPUT :
Enter first string : bqdrcvefgh
Enter second string : abcvdefgh
Length of LCS : 7
The Longest Common Subsequence is : bcvefgh
*/
