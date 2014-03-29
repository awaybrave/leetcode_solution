#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

class Solution{
public:
	int evalRPN(vector<string> &tokens){
		stack<int> operand;
		int result;
		for(int i = 0; i < tokens.size(); i++){
			if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
				int operand2 = operand.top();
				operand.pop();
				int operand1 = operand.top();
				operand.pop();
				int midResult = cal(operand1, operand2, tokens[i]);
				operand.push(midResult);
			}
			else{
				int currentNum = stringToInt(tokens[i]);
				operand.push(currentNum);
			}
		}
		result = operand.top();
		operand.pop();
		return result;
	}
private:
	int stringToInt(string num){
		int result = 0; 
		bool nav = false;
		for(int i = 0; i < num.size(); i++){
			if(i == 0 && num[0] == '-'){
				nav = true;
				continue;
			}
			result *= 10;
			result += int(num[i]-'0');
		}
		return nav ? -result : result;
	}
	int cal(int op1, int op2, string oper){
		if(oper == "+")
			return op1 + op2;
		if(oper == "-")
			return op1 - op2;
		if(oper == "*")
			return op1 * op2;
		if(oper == "/")
			return op1 / op2;
	}
};

int main(){
	Solution test;
	vector<string> input;
	string i;
	while(cin >> i){
		input.push_back(i);	
	}
	cout << test.evalRPN(input) << endl;
}
