#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.empty())
            return 0;
        sum.clear();
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0; i < m; i++){
            vector<int> row;
            for(int j = 0; j < n; j++)
                row.push_back(0);
            sum.push_back(row);
        }
		sum[0][0] = grid[0][0];
        for(int i = 1; i < m; i++)
            sum[i][0] = sum[i-1][0] + grid[i][0];
        for(int j = 1; j < n; j++)
            sum[0][j] = sum[0][j-1] + grid[0][j];
		/*
		for(int i = 0; i < m; i++)
			for(int j = 0; j < n; j++)
				cout << sum[i][j] << " ";
		*/
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                sum[i][j] = grid[i][j] + (sum[i][j-1] <= sum[i-1][j] ? sum[i][j-1] : sum[i-1][j]);   
        return sum[m-1][n-1];
    }
private:
    vector<vector<int> > sum;
};

int main(){
	int a[] = {1,2,5};
	int b[] = {3,2,1};
	Solution test;
	vector<vector<int> > grid;
	vector<int>row;
	row.push_back(1);
	row.push_back(2);
	//row.push_back(5);
	grid.push_back(row);
	row.clear();
	row.push_back(1);
	row.push_back(1);
	//row.push_back(1);
	grid.push_back(row);
	cout << test.minPathSum(grid) << endl;
}
