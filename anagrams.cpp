#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
public:
	vector<string> anagrams(vector<string> &strs){
		vector<string> result;
		for(int i = 0; i < strs.size(); i++){
			bool flag = true;
			int s = strs[i].size();
			for(int j = 0; j <= s/2; j++){
				if(strs[i][j] != strs[i][s-j-1]){
					flag = false;
					break;
				}
			}
			if(flag)
				result.push_back(strs[i]);
		}
		return result;
	}
};

int main(){
	string a[] = {"abba", "b"};
	vector<string> input(a, a+2);
	Solution test;
	vector<string> result = test.anagrams(input);
	for(int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
}
