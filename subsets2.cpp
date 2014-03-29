#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S){
		result.clear();
		dup.clear();
		sort(S.begin(), S.end());
		int l = S.size();

		dup.push_back(0);
		for(int i = 1; i < l; i++){
			if(S[i] == S[i-1])
				dup.push_back(dup[i-1]+1);
			else
				dup.push_back(0);
			//cout << dup[i] << " ";
		}
		//cout << endl;

		for(int i = 0; i <= l; i++){
			vector<int> temp;
			find(temp, i, 0, S);
		}
		
		for(int i = 0; i < result.size(); i++){
			for(int j = 0; j < result[i].size(); j++)
				result[i][j] = S[result[i][j]];
		}
		
		return result;
	}
private:
	vector<vector<int> >result;
	vector<int> dup;
	void find(vector<int> &cur, int num, int p, vector<int> &S){
		if(cur.size() == num){
			result.push_back(cur);
			return;
		}
		int total = S.size();
		int t = cur.size()-1;
		for(int i = p; i < total; i++){
			if(dup[i] > 0){
				if(t >= 0){
					if(S[cur[t]] != S[i] && dup[i] > 0)
						continue;
					if(S[cur[t]] == S[i] && dup[cur[t]]+1 != dup[i])
						continue;
				}
				if(t == -1 && dup[i] > 0)
					continue;
			}
			cur.push_back(i);
			find(cur, num, i+1, S);
			cur.pop_back();
		}
	}
};

int main(){
	int a[] = {1,1,1,1};
	vector<int> input(a, a+sizeof(a)/sizeof(int));
	Solution test;
	vector<vector<int> >result = test.subsets(input);
	for(int i = 0; i < result.size(); i++){
		cout << "Subset " << i << ": " << endl;
		for(int j = 0; j < result[i].size(); j++){
			cout << result[i][j] << " ";	
		}
		cout << endl;
	}
}
