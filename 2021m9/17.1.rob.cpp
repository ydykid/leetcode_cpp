#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
		// for (int i=0; i<nums.size(); i++) {
		// 	if (i>0){printf(" ");}
		// 	printf("%d", nums[i]);
		// }
		// printf("\n");
		int ans = 0;
		vector<int> dp = vector<int>(nums);
		for (int i=1; i<nums.size(); i++) {
			int x = 0;
			if (i>1){x+=dp[i-2];}
			dp[i] = max(dp[i-1], dp[i]+x);
		}
		// for (int i=0; i<dp.size(); i++) {
		// 	if (i>0){printf(" ");}
		// 	printf("%d", dp[i]);
		// }
		// printf("\n");
		ans = dp[nums.size()-1];
		return ans;
    }
};

int main() {
	printf("hello\n");
	vector< vector<int> > qs = vector< vector<int> >();
	int q1arr[4] = {1, 2, 3, 1};
	vector<int> q1 = vector<int>();
	for (int i=0; i<4; i++) {
		q1.push_back(q1arr[i]);
	}
	qs.push_back(q1);
	int q2arr[5] = {2, 7, 9, 3, 1};
	vector<int> q2 = vector<int>();
	for (int i=0; i<5; i++) {
		q2.push_back(q2arr[i]);
	}
	qs.push_back(q2);
	int q3arr[2] = {1, 2};
	vector<int> q3 = vector<int>();
	for (int i=0; i<2; i++) {
		q3.push_back(q3arr[i]);
	}
	qs.push_back(q3);
	Solution sol = Solution();
	for (int i=0; i<qs.size(); i++) {
		printf("#%d\n", i+1);
		int ans = sol.rob(qs[i]);
		printf("ans: %d\n", ans);
	}	
}