#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
public:
	int canJump(int A[], int n){
		if(n == 0)
			return 0;
		vector<int> move(n, 0);
		int reach = 0; 
		int i = 0;
		do{
			if(A[i]+i > reach){
				for(int j = reach+1; j <= A[i] + i && j < n; j++)
					move[j] = move[i] + 1;
				reach = A[i] + i;
			}
			i++;
		}while(i < n && i <= reach && reach < n - 1);
		return move[n-1];
	}
};

int main(){
	//int A[] = {1,2,5,4,0,0,0,0,1};
	//int A[] = {1,2,3};
	//int A[] = {2,3,1,1,4};
	//int A[] = {1,2,1,1,1};
	int A[] = {7,0,9,6,1,7,9,0,1,2,9,3};
	Solution test;
	cout << test.canJump(A, sizeof(A)/sizeof(int)) << endl;
}
