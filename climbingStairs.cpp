// https://leetcode.com/problems/climbing-stairs/
// You are climbing a staircase. It takes n steps to reach the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
// Dynamic Programming
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")

using namespace std;

typedef long long ll;
typedef long double ld;
#define fast_cin()                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)

const int mod = 1e9 + 7;
void readInputFile()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

// Using recursion O(2^n)
int countSteps(int n)
{
	if (n == 0)
		return 1;
	if (n < 0)
	{
		return 0;
	}
	return countSteps(n - 1) + countSteps(n - 2);
}

// Using DP - memoization O(n)
int CS(int n, unordered_map<int, int> &memo)
{
	if (n == 0)
		return 1;
	if (n < 0)
	{
		return 0;
	}
	if (memo.find(n) != memo.end())
	{
		return memo[n];
	}
	return countSteps(n - 1) + countSteps(n - 2);
}

// Using DP Top-down O(n)
int CSTopDown(int n)
{
	vector<int> dp(n + 1);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	return dp[n];
}

void solve()
{
	int n;
	cin >> n;
	// cout << countSteps(n);
	unordered_map<int, int> memo;
	// cout << CS(n, memo);
	cout << CSTopDown(4);
}

signed main()
{
	fast_cin();
	readInputFile();
	int t = 1;
	/*is Single Test case?*/
	cin >> t;
	while (t--)
	{
		solve();
		cout << "\n";
	}

	return 0;
}
