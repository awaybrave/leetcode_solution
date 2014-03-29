#include<string>
#include<vector>
#include<iostream>

using namespace std;

class Solution{
public:
	int minDistance(string word1, string word2){
		visited.clear();
		for(int i = 0; i < word1.size()*word2.size(); i++)
			visited.push_back(-1);	
		return reMinDis(word1, word2, 0, 0);
	}
private:
	int reMinDis(string word1, string word2, int p1, int p2){
		if(p1 >= word1.size()){
			if(p2 >= word2.size())
				return 0;
			else
				return word2.size()-p2;
		}
		if(p2 >= word2.size()){
			if(p1 >= word1.size())
				return 0;
			else
				return word1.size()-p1;
		}
		if(word1[p1] == word2[p2]){
			if(visited[p1*word2.size()+p2] != -1)
				return visited[p1*word2.size()+p2];
			else{
				int result = reMinDis(word1, word2, p1+1, p2+1);
				visited[p1*word2.size()+p2] = result;
				return result;
			}
		}
		else{
			int t1,t2,t3;
			int celln;
			celln = (p1+1)*word2.size()+p2;
			if(celln < visited.size()){
				if(visited[celln] == -1){
					t1 = reMinDis(word1, word2, p1+1, p2);
					visited[celln] = t1;
				}
				else
					t1 = visited[celln];
			}
			else
				t1 = reMinDis(word1, word2, p1+1, p2);

			celln = p1*word2.size()+p2+1;
			if(celln < visited.size()){
				if(visited[celln] == -1){
					t2 = reMinDis(word1, word2, p1, p2+1);
					visited[celln] = t2;
				}
				else
					t2 = visited[celln];
			}
			else
				t2 = reMinDis(word1, word2, p1, p2+1);
			
			celln = (p1+1)*word2.size()+p2+1;
			if(celln < visited.size()){
				if(visited[celln] == -1){
					t3 = reMinDis(word1, word2, p1+1, p2+1);
					visited[celln] = t3;
				}
				else
					t3 = visited[celln];
			}
			else
				t3 = reMinDis(word1, word2, p1+1, p2+1);
			int min = t1 > t2 ? t2 : t1;
			return (t3 > min ? min : t3)+1;
		}
	}
	vector<int>visited;
};

int main(){
	Solution test;
	//string word1 = "jbva1";
	string word1;
	string word2;// = "java1a";
	while(cin >> word1 >> word2)
		cout << test.minDistance(word1,word2) << endl;
}
