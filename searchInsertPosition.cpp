#include<iostream>
using namespace std;

class Solution{
public:
	int searchInsert(int A[], int n, int target){
		int head = 0;
		int tail = n-1;
		int mid;
		while(head < tail){
			mid = (head+tail)/2;
			if(target > A[mid])
				head = mid+1;
			else
				tail = mid;
		}
		if(head == tail){
			return A[head] < target ? head+1 : head;
		}
		else{
			if(target < A[tail])
				return tail-1;
			if(target > A[tail] && target < A[head])
				return head;
			if(target > A[head])
				return head+1;
		}
	}
};

int main(){
	Solution test;
//	int a[] = {1, 3, 9, 10, 13, 15, 19};
	int a[] = {1};
	int number;
	while(cin >> number){
		cout << test.searchInsert(a, sizeof(a)/sizeof(int), number) << endl; 
	}
}
