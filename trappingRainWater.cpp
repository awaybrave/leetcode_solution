#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	int trap(int A[], int n){
		if(n == 0)
			return 0;
		int total = 0, head = 0, i = 0;
		vector<int> mark;
		while(i < n){
			while(A[i+1] < A[i] && i+1 < n)
				i++; 
			if(i == head){
				head++;
				i++;
				continue; 
			}
			if(i == n-1)
				break;
			while(A[head] >= A[i] && i+1 < n)
				i++; 
			if(mark.empty())
				mark.push_back(head);
			mark.push_back(i);
			head = i;
		}

		for(int i = 0; i < mark.size(); i++){
			cout << mark[i] << " " << A[mark[i]] << endl;
		}

		
		int h = 0;
		for(int i = 1; i < mark.size(); i++){
			int t = i; int height = A[mark[i]];
			if(A[mark[h]] > A[mark[i]]){
				for(int j = i+1; j < mark.size(); j++){
					if(height < A[mark[j]]){
						t = j;
						height = A[mark[j]];
					}
				}
				total += cal(A, mark[h], mark[t]);
				h = t;
				i = h;
			}
			else{
				total += cal(A, mark[h], mark[i]);
				h = i;
			}
		}
		
		return total;
	}
private:
	int cal(int A[], int head, int tail){
		int area = 0;
		int line = A[head] < A[tail] ? A[head] : A[tail];
		for(int i = head+1; i < tail; i++)
			area += line > A[i] ? line-A[i] : 0; 
		return area;
	}
};

int main(){
	//int a[] = {};
	//int a[] = {0,1,0,2,1,0,1,3,2,1,2,1}; //6
	//int a[] = {2,0,2}; // 2
	//int a[] = {4,2,0,3,2,5}; // 9
	//int a[] = {5,4,1,2}; //1 
	int a[] = {5,5,1,7,1,1,5,2,7,6}; // 23
	//int a[] = {6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3}; // 83
	//int a[] = {5,5,1,8,1,1,5,2,7,9}; // 28
	//int a[] = {8,8,1,5,6,2,5,3,3,9}; //31
	Solution test;
	cout << test.trap(a, sizeof(a)/sizeof(int)) << endl;
}
