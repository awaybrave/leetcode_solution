#include<iostream>
#include<cmath>
using namespace std;

class Solution{
public:
	int singleNumber(int A[], int n){
		// Note: The Solution object is instantiated only once and is resused by each test case.
		int result = 0;
		int bits[32];
		for(int i = 0; i < 32; i++){
			bits[i] = 0;
			for(int j = 0; j < n; j++){
				if(((A[j] >> i) & 1) == 1)	
					bits[i] = (bits[i] + 1)  % 3;
			}
			result |= (bits[i] << i);
		}
		
		return result;
		
	}
};

int main(){
	Solution test;
	int a[] = {-401451,-177656,-2147483646,-473874,-814645,-2147483646,-852036,-457533,-401451,-473874,-401451,-216555,-917279,-457533,-852036,-457533,-177656,-2147483646,-177656,-917279,-473874,-852036,-917279,-216555,-814645,2147483645,2147483645,-814645,2147483645,-216555,-2147483648};
//	int a[] = {-1,-3,-14,-23,-3,-14,-5,-14,-3,-1,-1,-23,-23};
	int b = -11;
	/*
	while(b != 0){
		int temp = b & 1;
		b = b >> 1;
		cout << temp << endl;
	}
	*/
	int result = test.singleNumber(a, 31);
	cout << result << endl;
}
