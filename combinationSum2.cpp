#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &nums, int target) {
        queue<vector<int> > q;
		queue<int> sum;
		vector<vector<int> >result;
		vector<int> can2 = nums;
		sort(can2.begin(), can2.end());
		for(int i = 0; i < can2.size(); i++){
			if(i > 0 && can2[i] == can2[i-1])
				continue;
			if(can2[i] < target){
				vector<int> list(1, i);
				q.push(list);
				sum.push(can2[i]);
			}
			if(can2[i] == target){
				vector<int> list(1, i);
				result.push_back(list);
				break;
			}
			if(can2[i] > target)
				break;
		}
		while(!sum.empty()){
			vector<int> curList = q.front();
			int curSum = sum.front();
			q.pop();
			sum.pop();
			int listSize = curList.size();
			for(int i = curList[listSize-1]+1; i < can2.size(); i++){
				if(can2[curList[listSize-1]] == can2[i] && curList[listSize-1]+1 != i)
					continue;
				if(can2[curList[listSize-1]] != can2[i] && can2[i] == can2[i-1])
					continue;
				if(can2[i] + curSum > target)
					break;
				if(can2[i] + curSum == target){
					curList.push_back(i);
					result.push_back(curList);
					break;
				}
				curList.push_back(i);
				q.push(curList);
				sum.push(curSum+can2[i]);
				curList.pop_back();
			}
		}
			
		for(int i = 0; i < result.size(); i++){
			for(int j = 0; j < result[i].size(); j++)
				result[i][j] = can2[result[i][j]]; 
		}
			
		return result;
    }
};

int main(){
	//int a[] = {2, 3, 6, 7};
	//int a[] = {10, 1, 2, 7, 6, 1, 5};
	//int a[] = {5,1,2,1,1,2};
	int a[] = {3,1,3,5,1,1};
	vector<int> input(a, a+sizeof(a)/sizeof(int));
	Solution test;
	vector<vector<int> > result = test.combinationSum2(input, 8);
	//cout << result.size() << endl;
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
}
