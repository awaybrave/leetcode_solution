#include<iostream>
#include<string>
#include<stack>
using namespace std;

//The algorithm is to find the space character.
//When meeting a space character, check whether it is before or after a 
//word I going to apply substr function on.
class Solution {
public:
    void reverseWords(string &s) {
        stack<string> reverse;
		bool start = false;
		int h;
		for(int i = 0; i < s.size(); i++){
			if(s[i] != char(32)){
				if(!start){
					h = i;
					start = true;
				}
			}
			else{
				if(i > 0 && s[i-1] != char(32)){
					reverse.push(s.substr(h, i-h));
					start = false;
				}
			}
		}
		if(start){
			int i = s.size()-1;
			while(i > 0 && s[i] == char(32))
				i--;
			reverse.push(s.substr(h, i-h+1));
		}
		s = ""; 
		while(reverse.size() > 1){
			//cout << reverse.top() << endl;
			s += reverse.top() + " ";
			reverse.pop();
		}
		if(!reverse.empty()){
			s += reverse.top();
			reverse.pop();
		}
    }
};

int main(){
	//string s = "  the   sky is blue";
	string s = "";
	Solution test;
	test.reverseWords(s);
	cout << s;
}
