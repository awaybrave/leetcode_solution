#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
public:
	vector<vector<string> > solveNQueens(int n){
		vector<vector<string> > result;
		sum = n;
		searchMaze(result, 0);
		return result;
	}
private:
	vector<int> visited;
	int sum;
	void searchMaze(vector<vector<string> > &result, int num){
		if(num == sum){
			vector<string> midResult;
			for(int i = 0; i < num; i++){
				string row = "";
				int pos = visited[i];
				for(int j = 0; j < num; j++)
					row.push_back('.');
				row[pos] = 'Q';
				midResult.push_back(row);
			}
			result.push_back(midResult);
			return;
		}
		for(int i = 0; i < sum; i++){
			bool flag = true;
			for(int j = 0; j < visited.size(); j++){
				if(visited[j] == i || j + 1 == num && (visited[j] == i + 1 || visited[j] == i - 1))
					flag = false;
			}
			if(flag){
				visited.push_back(i);
				searchMaze(result, num+1);
				visited.pop_back();
			}
		}
	}
};

int main(){
	Solution test;
	vector<vector<string> > result;// = test.solveNQueens(9);
	/*
	cout << result.size() << endl;
	result = test.solveNQueens(5);
	cout << result.size() << endl;
	*/
	/*
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << endl;
		cout << endl;
	}
	cout << result.size() * result[0].size() << endl;
	*/
	for(int i = 0; i < 15; i++){
		result = test.solveNQueens(i+1);
		cout << result.size() * result[0].size() << endl; 
	}
}
