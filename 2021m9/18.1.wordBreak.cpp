#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp = vector<bool>(n+1);
        set<string> ss = set<string>();
        int m = 0;
        for (int i=0; i<wordDict.size(); i++){
            ss.insert(wordDict[i]);
            if (wordDict[i].size()>m)m=wordDict[i].size();
        }
        dp[0] = true;
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=i&&j<=m; j++) {
                if (ss.find(s.substr(i-j, j))!=ss.end()){
                    dp[i] = dp[i-j];
                    if (dp[i])break;
                }
            }
        }
        return dp[n];
    }
};

int main(){
	vector<string> qs = vector<string>();
	vector< vector<string> > qw = vector< vector<string> >();
	// #question1
	qs.push_back("leetcode");
	string q1wa[2] = {"leet", "code"};
	vector<string> q1w = vector<string>();
	for (int i=0; i<q1w.size(); i++) {
		cout << q1w[i] << endl;
	}
	for (int i=0; i<2; i++) {
		q1w.push_back(q1wa[i]);
	}
	qw.push_back(q1w);

	Solution sol = Solution();
	for (int i=0; i<qs.size(); i++) {
		// printf("#%d:%s,[", i+1, qs[0]);
		printf("#%d:", i+1);
		cout<<qs[0]<<", [";
		for (int j=0; j<qw[i].size(); j++) {
			if (j>0)printf(",");
			// printf("\"%s\"", qw[i][j]);
			cout<<"\""+qw[i][j]+"\"";
		}
		printf("]\n");
		printf("ans:%d\n", sol.wordBreak(qs[i], qw[i]));
	}
	// cout << __cplusplus <<endl;
	return 0;
}
