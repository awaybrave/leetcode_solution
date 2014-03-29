#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution{
public:
	int longestConsecutive(vector<int> &num){
		if(num.size() == 0)
			return 0;
		map<int,int> len;
		int max = 0;
		int size = num.size();
		for(int i = 0; i < size; i++){
			len[num[i]] = 0;
		}
		map<int,int>:: iterator it;
		for(int i = 0; i < size; i++){
			int count = 0; 
			int start = num[i];
			if(len[start] == -1 || len[start] != 0)
				continue;
			while(true){
				it = len.find(start+count+1);
				if(it == len.end())
					break;
				if(it->second != 0){
					count += it->second+1;
					break;
				}	
				count++;	
				len[it->first] = -1;
			}
			len[start] = count;
			if(max < count)
				max = count;
		}
		return max+1;
	}
};

int main(){
	//int a[] = {100, 4, 200, 1, 3, 2, 0};
	//int a[] = {0,0,1,-1};
	int a[] = {1, -8, 7, -2, -4, -4, 6, 3, -4, 0, -7, -1, 5, 1, -9, -3};
	vector<int> num(a, a+sizeof(a)/sizeof(int));
	Solution test;
	cout << test.longestConsecutive(num) << endl;
}
