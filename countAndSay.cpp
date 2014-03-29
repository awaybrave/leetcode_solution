#include<string>
#include<iostream>
using namespace std;

class Solution{
public:
	string countAndSay(int n){
		string str = "1";
		for(int i = 1; i < n; i++){
			int count = 0;
			string next = "";
			while(count < str.size()){
				int i = 1;
				while(count+i < str.size() && str[count] == str[count+i])
					i++;
				next += char('0'+i);//+str[count];
				next += str[count];
				count += i;
			}
			str = next;
		} 
		return str;
	}
};

int main(){
	//cout << char('0'+2+1);
	Solution test;
	for(int i = 0; i < 200; i++){
		cout << test.countAndSay(i+1) << endl;
	}
}
