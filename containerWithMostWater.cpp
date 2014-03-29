#include<vector>
#include<iostream>
using namespace std;

class Solution{
public:
	int maxArea(vector<int> &height){
		int result = 0;
		int size = height.size();

		for(int i = 1; i < size; i++){
			if()	
		}
			
		for(int i = 0; i < size-1; i++){
			for(int j = i+1; j < size; j++){
				int temp = (height[i] > height[j] ? height[j] : height[i]) * (j-i);
				if(result < temp)
					result = temp;
			}
		}
		return result;
	}
};

int main(){
	int a[] = {4,2,6,3,4,1,2};
	vector<int> input;
	for(int i = 0; i < sizeof(a)/sizeof(int); i++)
		input.push_back(a[i]);
	Solution test;
	cout << test.maxArea(input) << endl;
}
