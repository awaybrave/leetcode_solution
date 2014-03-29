#include<iostream>
#include<string>
#include<vector>

using namespace std;

int base[] = {1, 5, 10, 50, 100, 500, 1000};

class Solution{
public:
	int romanToInt(string s){
		vector<int> num;	
		for(int i = 0; i < s.size(); i++){
			switch(s[i]){
				case 'I':
					num.push_back(0);
					break;
				case 'V':
					num.push_back(1);
					break;
				case 'X':
					num.push_back(2);
					break; 
				case 'L':
					num.push_back(3);
					break; 
				case 'C':
					num.push_back(4);
					break; 
				case 'D':
					num.push_back(5);
					break; 
				case 'M':
					num.push_back(6);
					break; 
			}
		}
		int c = 0;
		int result = 0;
		int size = num.size();
		while(c < size){
			switch(num[c]){
				case 0:
				case 2:
				case 4:
					if(c != size-1){
						if(num[c+1] == num[c]+1){
							result += 4*base[num[c]];
							c += 2;
						}
						else{
							if(num[c+1] == num[c]+2){
								result += 9*base[num[c]];
								c += 2;
							}
							else{
								int m = num[c];
								while(c < size-1 && num[c] == m){
									result += base[m];
									c++;
								}
							}
						}
					}
					else{
						result += base[num[c]]; 
						c++;
					}
					break;
				case 6:
					while(c < size && num[c] == 6){
						result += 1000; 
						c++;
					}
					break;
				case 1:
				case 3:
				case 5:
					result += base[num[c]];
					int m = num[c];
					c++;
					while(c < size && num[c] == m-1){
						result += base[m-1];
						c++;
					}
			}
		}
		return result;
	}
};

int main(){
	Solution test;
	string a;
	while(cin >> a){
		cout << test.romanToInt(a) << endl; 
	}
}
