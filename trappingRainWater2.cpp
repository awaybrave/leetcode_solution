#include<iostream>
using namespace std;

class Solution{
public:
	int trap(int A[], int n){
		int i = 0;
		int result = 0;
		while(i < n){
			int j = i+1;
			int mark = i+1;
			int heighest = 0;
			while(A[j] < A[i] && j < n){
				if(heighest <= A[j]){
					mark = j;
					heighest = A[j];
				}
				j++;
			}
			if(j < n){
				result += area(A, i, j);
				i = j;
			}
			else{
				result += area(A, i, mark);
				i = mark;
			}
		}
		return result;
	}
private:
	int area(int A[], int head, int tail){
		int line = A[head] < A[tail] ? A[head] : A[tail];
		int result = 0;
		for(int i = head+1; i < tail; i++)
			result += line - A[i];
		return result;
	}
};

int main(){
	//int a[] = {};
	//int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int a[] = {4,2,0,3,2,5};
	Solution test;
	cout << test.trap(a, sizeof(a)/sizeof(int)) << endl;
}
