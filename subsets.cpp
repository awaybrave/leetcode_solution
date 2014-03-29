#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
	vector<vector<int> > subsets(vector<int> &S){
		result.clear();
		sort(S.begin(), S.end());
		int l = S.size();
		for(int i = 0; i <= l/2; i++){
			vector<int> temp;
			find(temp, i, 0, l);
		}
		
		for(int i = 0; i < result.size(); i++){
			for(int j = 0; j < result[i].size(); j++)
				result[i][j] = S[result[i][j]];
		}
		
		return result;
	}
private:
	vector<vector<int> >result;
	void find(vector<int> &cur, int num, int p, int total){
		if(cur.size() == num){
			// push it and its opposite set into result;
			result.push_back(cur);
			if(total % 2 == 0 && num == total/2)
				return;
			int last = -1;
			vector<int> temp;
			for(int i = 0; i < cur.size(); i++){
				for(int j = last+1; j < cur[i]; j++)
					temp.push_back(j);
				last = cur[i];
			}
			for(int i = last+1; i < total; i++)
				temp.push_back(i);
			result.push_back(temp);
			return;
		}
		for(int i = p; i < total; i++){
			cur.push_back(i);
			find(cur, num, i+1, total);
			cur.pop_back();
		}
	}
};

int main(){
	int a[] = {1,2,3,4,5};
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
