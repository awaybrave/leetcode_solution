#include<iostream>
using namespace std;

class Solution{
public:
	int maxSubArray(int A[], int n){
		/*int cur_max = A[0], max = A[0];
		for(int i = 1; i < n; i++){
			if(cur_max < 0){
				if(A[i] > 0){
					cur_max = A[i];
					max = cur_max > max ? cur_max : max; 
				}
				else{
					cur_max = A[i] > cur_max ? A[i] : cur_max;
					max = cur_max > max ? cur_max : max; 
				}
				continue;
			}
			cur_max += A[i];
			if(cur_max > 0){
				if(cur_max > max){
					max = cur_max;
				}
			}
			else{
				cur_max = 0;
			}
		}
		*/
		int cur_max = 0, max = 0;
		for(int i = 0; i < n; i++){
			cur_max += A[i];
			if(cur_max > 0){
				if(cur_max > max)
					max = cur_max;
			}
			else
				cur_max = 0; 
		}
		if(max == 0){
			int nav_max = A[0];
			for(int i = 1; i < n; i++){
				if(nav_max < A[i])
					nav_max = A[i];
			}
			return nav_max;
		}
		return max;
	}
};

int main(){
	//int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
	int A[] = {-2, 1};
	Solution test;
	cout << test.maxSubArray(A, sizeof(A)/sizeof(int)) << endl;
}
