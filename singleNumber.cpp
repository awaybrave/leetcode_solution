#include<iostream>
using namespace std;

class Solution{
	public:
		int singleNumber(int A[], int n){
			// Note: The Solution object is instantiated oly once and is reused by each test case.
			int result = 0;
			for(int i = 0; i < n; i++){
				result = result ^ A[i];
			}
			return result;
		}
};

int main(){
	Solution test;
	int a[]  = {1,4,3,1,5,4,5};
	cout << test.singleNumber(a, 7) << endl;
}
