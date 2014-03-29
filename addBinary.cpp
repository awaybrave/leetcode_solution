#include<string>
#include<iostream>
using namespace std;

class Solution{
public:
	string addBinary(string a, string b){
		int len1 = a.size();
		int len2 = b.size();
		int len;
		string temp = "";
		string result;
		if(len1 < len2){ 
			for(int i = 0; i < len2-len1; i++)
				temp.push_back('0');
			a = temp + a;
			len = len2;
		}
		else{
			for(int i = 0; i < len1-len2; i++)
				temp.push_back('0');
			b = temp + b;
			len = len1;
		}
		bool carry = false;
		for(int i = len-1; i >= 0; i--){
			result.push_back('0');	
		}
		for(int i = len-1; i >= 0; i--){
			if(a[i] == '0' && b[i] == '1' || a[i] == '1' && b[i] == '0'){
				if(!carry)
					result[i] = '1';	
			}
			if(a[i] == '0' && b[i] == '0'){
				if(carry){
					result[i] = '1';
					carry = false;
				}
			}
			if(a[i] == '1' && b[i] == '1'){
				if(!carry)
					carry = true;
				else
					result[i] = '1';
			}
		}
		if(carry)
			result = '1' + result;
		return result;
	}
};

int main(){
	string num1;
	string num2;
	Solution test;
	while(cin >> num1 >> num2){
		cout << test.addBinary(num1, num2) << endl;
	}
}
