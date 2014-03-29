#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	int minimumTotal(vector<vector<int> > &triangle){
		minTotal.clear();
		int ts = triangle.size();
		if(ts == 0)
			return 0;
		vector<int> tail;
		for(int i = 0; i < triangle[ts-1].size(); i++)
			tail.push_back(triangle[ts-1][i]); 
		minTotal.push_back(tail);
		int rowc = 0;
		for(int i = ts-2; i >= 0; i--){
			vector<int> row;
			for(int j = 0; j < triangle[i].size(); j++){
				int minnum = minTotal[rowc][j] < minTotal[rowc][j+1] ?
							minTotal[rowc][j] : minTotal[rowc][j+1];		
				row.push_back(minnum+triangle[i][j]); 
			}
			minTotal.push_back(row);
			rowc++;
		}
		return minTotal[ts-1][0];
	}
private:
	vector<vector<int> > minTotal;
};

int main(){
	Solution test;
	int a[] = {2,3,4,6,5,7,4,1,8,3};
	vector<vector<int> > input;
	int count = 0;
	for(int i = 1; i <= 4; i++){
		vector<int> row;
		for(int j = 0; j < i; j++)
			row.push_back(a[count+j]);
		count += i;
		input.push_back(row);
	}
	/*
	for(int i = 0; i < input.size(); i++){
		for(int j = 0; j < input[i].size(); j++)
			cout << input[i][j] << " ";
		cout << endl;
	}
	*/
	cout << test.minimumTotal(input) << endl;
}
