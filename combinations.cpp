#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	vector<vector<int> > combine(int n, int k){
		result.clear();
		temp.clear();
		recursive_cal(0, k, n);
		return result;
	}
private:
	vector<int> temp;
	vector<vector<int> > result;
	void recursive_cal(int start, int k, int num){
		if(temp.size() == k){
			result.push_back(temp);
			return;
		}
		if(num-start < k-temp.size()){
			return;
		}
		for(int i = 0; i < num-start; i++){ 
			temp.push_back(i+start+1);
			recursive_cal(start+i+1, k, num);
			temp.pop_back();
		}
	}
};

int main(){
	Solution test;
	vector<vector<int> >result = test.combine(4, 3);
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
}
