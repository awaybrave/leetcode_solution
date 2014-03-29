#include<string>
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class Solution{
public:
	vector<string> letterCombinations(string digits){
		vector<vector<char> > l2d;
		vector<string> result;

		char start = 'a';
		int count;
		for(int i = 2; i <= 9; i++){
			if(i == 7 || i == 9)
				count = 4;
			else
				count = 3;
			vector<char> anumber;
			for(int j = 0; j < count; j++)
				anumber.push_back(start+j);
			start = start + count;
			l2d.push_back(anumber);
		}
		
		queue<string> q;
		q.push("");
		q.push("0");

		for(int i = 0; i < digits.size(); i++){
			int letter = digits[i] - '0';
			while(q.front() != "0"){
				string temp = q.front();
				q.pop();
				for(int j = 0; j < l2d[letter-2].size(); j++){
					if(i < digits.size()-1){
						q.push(temp + l2d[letter-2][j]); 
					}
					else
						result.push_back(temp + l2d[letter-2][j]);
				}
			}
			q.pop();
			q.push("0");
		}
		return result;
	}
};

int main(){
	string input;
	Solution test;
	while(cin >> input){
		vector<string> result = test.letterCombinations(input);
		for(int i = 0; i < result.size(); i++)
			cout << result[i] << endl;
	}
	return 0;
}
