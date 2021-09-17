#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int minOperations(vector<string>& logs) {
		int ans = 0;
		for (int i=0; i<logs.size(); i++) {
			if (logs[i][0]=='.'&&logs[i][1]=='.') {
				if (ans>0){ans--;}
			}else if (logs[i][0]!='.'){
				ans++;
			} 
		}
	   	return ans;
    }
};


int main() {
	vector<string> qs1 = vector<string>();
	qs1.push_back("d1/");
	qs1.push_back("d2/");
	Solution sol = Solution();
	printf("ans:%d\n", sol.minOperations(qs1));
	return 0;
}