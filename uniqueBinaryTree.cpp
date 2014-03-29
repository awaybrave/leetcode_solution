#include<vector>
#include<iostream>
using namespace std;

class Solution{
public:
	int numTrees(int n){
		for(int i = 0; i < n+1; i++){
			visited.push_back(0);
		}
		int result = cal(0, n-1);
		visited.clear();
		return result;
	}
private:
	int cal(int head, int tail){
		if(head >= tail)
			return 1;
		if(visited[tail-head+1] != 0)
			return visited[tail-head+1];
		int sum = 0;
		for(int i = head; i <= tail; i++){
			int leftResult = cal(head, i-1);	
			if(head >= 0 && head < i-1)
				visited[i-head] = leftResult;
			int rightResult = cal(i+1, tail);
			if(i+1 < tail)
				visited[tail-i] = rightResult;
			sum += leftResult * rightResult;
		}
		return sum;
	}
	vector<int> visited;
};

int main(){
	Solution test;
	int number;
	while(cin >> number){ 
		cout << test.numTrees(number) << endl;
	}
}
