#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class Solution{
public:
	vector<vector<int> > permute(vector<int> &num){
		visited.clear();	
		result.clear(); 
		sort(num.begin(), num.end()); 
		size = num.size();
		for(int i = 0; i < num.size(); i++)
			visited.push_back(-1);
		vector<int> temp;
		make_permute(temp, num);
		return result;
	}
private:
	vector<vector<int> >result;
	vector<int> visited;
	int size;
	void make_permute(vector<int> &midResult, const vector<int> &orgin){
		if(midResult.size() < size){
			for(int i = 0; i < orgin.size(); i++){
				if(visited[i] == -1){
					bool flag = true;
					int c = i-1;
					while(c >= 0 && orgin[c] == orgin[i]){
						if(visited[c] == -1){
							flag = false;
							break;
						}
						c--;
					}
					if(flag){
						vector<int> temp(midResult);
						midResult.push_back(orgin[i]);
						visited[i] = midResult.size()-1;
						make_permute(midResult, orgin);
						midResult = temp;
						visited[i] = -1;
					}
				}
			}
		}
		else
			result.push_back(midResult);
	}
};

int main(){
	Solution test;
	int a[] = {1,2,1,2};
	vector<int> orgin(a, a+sizeof(a)/sizeof(int));
	int number;
	/*
	while(cin >> number){
		for(int i = 0; i < number; i++)
			orgin.push_back(i+1);
		test.permute(orgin);
		orgin.clear();
	}
	*/
	vector<vector<int> >result = test.permute(orgin);
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	
}
