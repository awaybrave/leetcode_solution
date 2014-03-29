#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost){
		int left = 0;
		int size = gas.size();
		int last = size-1;
		int count = 0;
		for(int i = size-1; i >= 0; i--){
			while(count < size){
				if(gas[last]+left >= cost[last]){
					left += gas[last] - cost[last];
					last = (last+1)%size;
					count++;
				}
				else
					break;
			}
			if(count == size)
				return i;
			else{
				if(i == 0 || i-1 == last)
					return -1;
				left += gas[i-1] - cost[i-1];
				count++;
			}
		}
		return -1;
	}
};

int main(){
	int gas[] = {1,2,3,3};
	int cost[] = {2,1,5,1};

	vector<int> g(gas, gas+sizeof(gas)/sizeof(int));
	vector<int> c(cost, cost+sizeof(cost)/sizeof(int));
	
	Solution test;
	cout << test.canCompleteCircuit(g, c) << endl;
}
