#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
public:
	void nextPermutation(vector<int> &num){
		//int max;
		int replace = num.size()-1;
		/*find the replaced position*/
		while(replace > 0){
			if(replace != num.size()-1){
			//	max = num[replace];
				bool flag = false;
				for(int i = replace+1; i < num.size(); i++){
					if(num[i] > num[replace]){
						flag = true;
						break;
					}
				}
				if(flag)
					break;
				if(replace > 0 && num[replace] > num[replace-1])
					replace--;
			}	
			replace--;
		}
		sort(num.begin()+replace+1, num.end());
		int i;
		for(i = replace+1; i < num.size(); i++){
			if(num[i] > num[replace])
				break;
		}
		if(i == num.size()){ 
			sort(num.begin(), num.end());
		}
		else{
			int temp = num[replace];
			num[replace] = num[i];
			num[i] = temp;
		}
	}
};

int main(){
	int a[] = {1,2,3,4,5,6,7,8,9};
	vector<int> myvector(a, a+sizeof(a)/sizeof(int));
	Solution test;
	while(true){
		cout << "wanna continue?" << endl;
		int answer;
		cin >> answer;
		if(answer == 1){
			test.nextPermutation(myvector);
			for(int i = 0; i < myvector.size(); i++)
				cout << myvector[i] << " ";
			cout << endl;
		}
		else
			break;
	}
}
