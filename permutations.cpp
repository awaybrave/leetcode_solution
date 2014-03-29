#include<vector>
#include<iostream>
using namespace std;

class Solution{
public:
	vector<vector<int> > permute(vector<int> &num){
		visited.clear();	
		result.clear(); 

		size = num.size();
		for(int i = 0; i < num.size(); i++)
			visited.push_back(false);
		vector<int> temp;
		make_permute(temp, num);
		return result;
	}
private:
	vector<vector<int> >result;
	vector<bool> visited;
	int size;
	void make_permute(vector<int> &midResult, const vector<int> &orgin){
		if(midResult.size() < size){
			for(int i = 0; i < orgin.size(); i++){
				if(!visited[i]){
					vector<int> temp(midResult);
					midResult.push_back(orgin[i]);
					visited[i] = true;
					make_permute(midResult, orgin);
					midResult = temp;
					visited[i] = false;
				}
			}
		} 
		else
			result.push_back(midResult);
	}
};

int main(){
	Solution test;
	vector<int> orgin;
	int number;
	while(cin >> number){
		for(int i = 0; i < number; i++)
			orgin.push_back(i+1);
		test.permute(orgin);
		vector<vector<int> >result = test.permute(orgin);
		for(int i = 0; i < result.size(); i++){
			for(int j = 0; j < result[i].size(); j++){
				cout << result[i][j] << " ";
			}
			cout << endl;
		}
		orgin.clear();
	}
	
}
