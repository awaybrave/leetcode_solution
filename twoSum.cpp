#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
	vector<int> twoSum(vector<int> &numbers, int target){
		sort(numbers.begin(), numbers.end());
		int size = numbers.size();
		int head = 0, tail = size-1;
		
		while(head <= size - 2){
			int max = numbers[head] + numbers[tail];
			int min = numbers[head] + numbers[head+1];
			if(target >= min && target <= max)
				break;
			head++;
		}
		
		while(numbers[head] + numbers[tail] != target)
			tail--;
	
		vector<int> result;
		result.push_back(head+1);
		result.push_back(tail+1);
		return result;
	}
};

int main(){
	//int a[] = {2, 7, 11, 15};
	//int targets[] = {9, 13, 17, 18, 22, 26};
	int a[] = {150, 24, 79, 50, 88, 345, 3};
	int targets[] = {200};

	vector<int> input(a, a+sizeof(a)/sizeof(int));
	Solution test;
	for(int i  = 0; i < sizeof(targets)/sizeof(int); i++){
		vector<int> result = test.twoSum(input, targets[i]);
		cout << result[0] << " " << result[1] << endl;
	}
}
