#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	vector<string> generateParenthesis(int n){
		result.clear();
		recursive_generate(n, n, "", "");
		return result;
	}
private:
	vector<string> result;
	void recursive_generate(int left, int right, string temp, string cur){
		if(left == 0){
			for(int i = 0; i < right; i++)
				cur.push_back(')'); 
			result.push_back(cur);
		}
		else{
			if(temp.size() > 0 && temp[temp.size()-1] == '(')
				recursive_generate(
						left, right-1, temp.substr(0, temp.size()-1), cur+")"
				);	
			recursive_generate(left-1, right, temp+"(", cur+"(");
		}
	}
};

int main(){
	Solution test;
	vector<string> result = test.generateParenthesis(3);
	for(int i = 0; i < result.size(); i++)
		cout << result[i] << endl;
}
