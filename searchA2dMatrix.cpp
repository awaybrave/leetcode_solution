#include<vector>
#include<iostream>
using namespace std;

class Solution{
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target){
		if(matrix.size() == 0 || matrix[0].size() == 0)
			return false;
		int row = matrix.size(), col = matrix[0].size();	
		for(int i = 0; i < row; i++){
			if(target >= matrix[i][0] && target <= matrix[i][col-1])
				return binarySearch(matrix[i], target);
		}
		return false;
	}
private:
	bool binarySearch(vector<int> list, int target){
		int head = 0, tail = list.size()-1;
		int mid;
		while(head < tail){
			mid = (head+tail)/2;
			if(target > list[mid])
				head = mid + 1;
			else
				tail = mid;
		}
		if(head == tail)
			return list[head] == target ? true : false;
		else
			return false;
	}
};

int main(){
	int a[][4] = {{1,3,5,7}, {10,11,16,20}, {23,30,34,50}};
	vector<vector<int> >input;
	int row = sizeof(a)/sizeof(int)/4;
	for(int i = 0; i < row; i++){
		vector<int> a_row(a[i], a[i]+sizeof(int));
		input.push_back(a_row);
	}
	Solution test;
	int target;
	while(cin >> target){
		cout << test.searchMatrix(input, target) << endl;
	}
}
