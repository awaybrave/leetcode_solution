#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;

class Solution{
public:
	int divide(int dividend, int divisor){
		int result = 0;
		stack<int> s;
		bool pos = true;
		unsigned t;
		if(dividend < 0){
			dividend = -dividend;
			if(dividend < 0)
				t = dividend; 
			pos = !pos;
		}
		if(divisor < 0){
			divisor = -divisor;
			pos = !pos;
		}
		if(dividend	> 0){
			while(dividend > 0){
				s.push(dividend % 10);
				dividend /= 10;
			}
		}
		else{
			while(t > 0){
				s.push(t % 10);
				t /= 10;
			} 
		}
		int remain = 0;
		while(!s.empty()){
			int temp = remain * 10 + s.top();
			s.pop();
			result = result * 10 + temp / divisor;
			remain = temp % divisor;
		}
		return pos ? result : -result;
	}
};

int main(){
	//cout << labs(-2147483648);
	int dividend, divisor;
	Solution test; 
	while(cin >> dividend >> divisor){
		cout << test.divide(dividend, divisor) << endl;
	}
}
