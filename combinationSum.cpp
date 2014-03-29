#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target){
		queue<vector<int> > q;
		queue<int> sum;
		vector<vector<int> >result;
		vector<int> can2 = candidates;
		for(int i = 0; i < can2.size(); i++){
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
			for(int i = curList[listSize-1]; i < can2.size(); i++){
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
	int a[] = {2, 3, 6, 7};
	vector<int> input(a, a+sizeof(a)/sizeof(int));
	Solution test;
	vector<vector<int> > result = test.combinationSum(input, 7);
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
}
