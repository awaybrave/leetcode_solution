#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

class Solution{
public:
	vector<string> restoreIpAddresses(string s){
		queue<pair<string, int> > q;
		queue<int> level;
		vector<string> result;
		q.push(make_pair("", 0));	
		level.push(0);
		while(!q.empty()){
			pair<string, int> cur = q.front();
			q.pop();
			int cur_level = level.front();
			level.pop();
			if(cur_level == 4){
				if(cur.first.size() == s.size()+3)
					result.push_back(cur.first);
				continue;
			}
			for(int i = 1; i <= 3; i++){
				if(cur.second+i > s.size())
					break;
				string token = s.substr(cur.second, i);
				if(isValid(token)){
					if(cur.first == "")
						q.push(make_pair(token, cur.second+i));
					else
						q.push(make_pair(cur.first+"."+token, cur.second+i));
					level.push(cur_level+1);
				}
			}
		}
		return result;
	}
private:
	bool isValid(string str){
		if(str.size() >= 1 && str.size() <= 3){
			if(str.size() > 1 && str[0] == '0')
				return false;
			int cur = 0;
			for(int i = 0; i < str.size(); i++)
				cur = cur * 10 + int(str[i] - '0');
			if(cur >= 0 && cur <= 255)
				return true;
		}
		return false;
	}
};

int main(){
	string input;
	Solution test;
	while(cin >> input){
		vector<string> r = test.restoreIpAddresses(input);
		for(int i = 0; i < r.size(); i++)
			cout << r[i] << endl;
	}
}
