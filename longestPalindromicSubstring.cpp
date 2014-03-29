#include<string>
#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	string longestPalindrome(string s){
		string newStr = "#"; 
		for(int i = 0; i < s.size(); i++){
			newStr += s[i];
			newStr += '#';
		}
		//cout << newStr << endl;
		vector<int> p(newStr.size(), 0);		
		int mx = 0, id = 0;
		for(int i = 0; i < newStr.size(); i++){
			if(mx > i){
				if(p[2*id-i] < mx-i)
					p[i] = p[2*id-i];
				else
					p[i] = mx-i;
			}
			while(i+p[i] < newStr.size() && newStr[i+p[i]] == newStr[i-p[i]])
				p[i]++;
			if(p[i] > p[id]){
				mx = i+p[i];
				id = i;
			}
		}
		//cout << id << " " << mx << endl;
		string result = "";
		for(int i = id-p[id]+1; i <= id+p[id]-1; i++){
			if(newStr[i] != '#')
				result += newStr[i];
		}
		return result;
	}
};

int main(){
	Solution test;
	string input;
	while(cin >> input){
		cout << test.longestPalindrome(input) << endl;
	}

}
