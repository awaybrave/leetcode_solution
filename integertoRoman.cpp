#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
	string intToRoman(int num){
		string result = "";

		int tr = num / 1000;
		num = num % 1000;
		for(int i = 0; i < tr; i++)
			result += 'M';

		int div = 100;
		//char fourth[] = {'V', 'L', 'D'};
		//char normal[] = {'I', 'X', 'C', 'M'};
		char fourth[] = {' ', 'D', 'L', 'V'};
		char normal[] = {'M', 'C', 'X', 'I'};
		for(int i = 1; i <= 3 && num > 0; i++, div /= 10){
			int temp  = num / div;
			num = num % div;
			if(temp == 9){
				result += normal[i];
				result += normal[i-1];
			}
			if(temp == 4){
				result += normal[i];
				result += fourth[i];
			}
			if(temp >= 5 && temp < 9){
				result += fourth[i];
				temp -= 5;
			}
			if(temp > 0 && temp < 4){
				for(int j = 0; j < temp; j++)
					result += normal[i];	
			}
		}
		return result;
	}
};

int main(){
	Solution test;
	int num;
	while(cin >> num){
		cout << test.intToRoman(num) << endl;
	}
}
