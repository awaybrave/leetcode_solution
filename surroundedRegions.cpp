#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
public:
	void solve(vector<vector<char> > &board){
		if(board.size() == 0)
			return;
		int dir[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
		int row = board.size();
		int col = board[0].size();

		vector<int> region;
		vector<vector<bool> > visited;
		for(int i = 0; i < row; i++){
			vector<bool> temp(col, false);
			visited.push_back(temp);
		}

		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				if(board[i][j] == 'O' && !visited[i][j]){
					visited[i][j] = true;
					queue<int> surround;
					surround.push(i*col+j);
					region.push_back(i*col+j);
					bool flag = false;
					while(!surround.empty()){
						int cur = surround.front();
						surround.pop();
						int r = cur / col;
						int c = cur % col;
						if(isBoundary(row, col, r, c))
							flag = true;
						for(int k = 0; k < 4; k++){
							int nr = r+dir[k][0];
							int nc = c+dir[k][1];
							if(isValid(row, col, nr, nc) && board[nr][nc] == 'O' && !visited[nr][nc]){
								visited[nr][nc] = true;
								region.push_back(nr*col+nc);
								surround.push(nr*col+nc); 
							}
						}
					}
					if(!flag){
						board[i][j] = 'X';
						for(int k = 0; k < region.size(); k++)
							board[region[k]/col][region[k]%col] = 'X'; 
					}
					region.clear();
				}
			}
		}
	}
private:
	bool isValid(int row, int col, int r, int c){
		return r >= 0 && r < row && c >= 0 && c < col;
	}
	bool isBoundary(int row, int col, int r, int c){
		return r == 0 || c == 0 || r == row - 1  || c == col - 1;
	}
};

int main(){
	//char grid[][4] = {{'X', 'X', 'X', 'X'}, {'X', 'O', 'O', 'X'}, {'X', 'X', 'O', 'X'}, {'X', 'O', 'X', 'X'}};
	char grid[][6] = {{'X', 'O', 'X', 'O', 'X', 'O'}, {'O', 'X', 'O', 'X', 'O', 'X'}, 
					  {'X', 'O', 'X', 'O', 'X', 'O'}, {'O', 'X', 'O', 'X', 'O', 'X'}}; 
	vector<vector<char> > board;
	for(int i = 0; i < 4; i++){
		vector<char> temp(grid[i], grid[i]+6);
		board.push_back(temp);
	}
	Solution test;
	test.solve(board);
	for(int i = 0; i < board.size(); i++){
		for(int j = 0; j < board[0].size(); j++)
			cout << board[i][j];
		cout << endl;
	}
	return 0;
}
