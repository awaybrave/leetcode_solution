#include<string>
#include<iostream>
using namespace std;

class Solution{
public:
	string multiply(string num1, string num2){
		string result = "";
		if(num2.size() > num1.size()){
			string temp = num1;
			num1 = num2;
			num2 = temp;
		}
		int carry;
		for(int i = 0; i < num2.size(); i++){
			string level_result = "";
			carry = 0;
			if(num2[num2.size()-1-i] == '0')
				continue;
			for(int j = 0; j < num1.size(); j++){
				int midr = (num1[num1.size()-1-j] - '0') * (num2[num2.size()-1-i] - '0'); 	
				level_result = char((carry + midr) % 10 + '0') + level_result;
				carry  = (carry + midr) / 10;
			}
			if(carry != 0)
				level_result = char(carry + '0') + level_result; 
			string tail(i, '0');
			result = addStrings(level_result+tail, result);
		}
		if(result == "")
			result = "0";
		return result;
	}
private:
	string addStrings(string num1, string num2){
		string result = "";
		if(num2.size() > num1.size()){
			string temp = num1;
			num1 = num2;
			num2 = temp;
		} 
		int carry = 0;
		for(int i = 0; i < num2.size(); i++){
			int midr = (num1[num1.size()-1-i] - '0') + (num2[num2.size()-1-i] - '0'); 
			result = char((carry + midr) % 10 + '0') + result;
			carry = (carry + midr) / 10;
		}
		for(int i = num2.size(); i < num1.size(); i++){
			int midr = (num1[num1.size()-1-i] - '0'); 
			result = char((carry + midr) % 10 + '0') + result;
			carry = (carry + midr) / 10; 
		}
		if(carry != 0)
			result = char(carry + '0') + result;
		return result;
	}
};

int main(){
	//cout << char('B' + 3) << endl;
	Solution test;
	string add1 = "0";
	string add2 = "4524";
	//string add3(0, '0');
	//cout << add3 << endl;
	cout << test.multiplyStrings(add1, add2) << endl;
}
