#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector<long long> d(n);
		for (int i = 0; i < n; i++) {
			cin >> d[i];
		}
		// based from Kadane's Algorithm
		// calculate the maximum sum starting from the left side (contiguous subarray)
		auto LeftMaximum = [&]() {
			vector<long long> dp(n, 0);
			dp[0] = d[0];
			long long res = d[0];
			for (int i = 1; i < n; i++) {
				res = max(d[i], d[i] + res);
				dp[i] = max(dp[i - 1], res);
			}
			return dp;
		};
		// calculate the minimum sum starting from the left side (contiguous subarray)
		auto LeftMininum = [&]() {
			vector<long long> dp(n, 0);
			dp[0] = d[0];
			long long res = d[0];
			for (int i = 1; i < n; i++) {
				res = min(d[i], d[i] + res);
				dp[i] = min(dp[i - 1], res);
			}
			return dp;
		};
		// calculate the maximum sum starting from the right side (contiguous subarray)
		auto RightMaximum = [&]() {
			vector<long long> dp(n, 0);
			dp[n - 1] = d[n - 1];
			long long res = d[n - 1];
			for (int i = n - 2; i >= 0; i--) {
				res = max(d[i], d[i] + res);
				dp[i] = max(dp[i + 1], res);
			}
			return dp;
		};
		// calculate the minimum sum starting from the right side (contiguous subarray)
		auto RightMinimum = [&]() {
			vector<long long> dp(n, 0);
			dp[n - 1] = d[n - 1];
			long long res = d[n - 1];
			for (int i = n - 2; i >= 0; i--) {
				res = min(d[i], d[i] + res);
				dp[i] = min(dp[i + 1], res);
			}
			return dp;
		};
		vector<long long> left_max = LeftMaximum();
		vector<long long> left_min = LeftMininum();
		vector<long long> right_max = RightMaximum();
		vector<long long> right_min = RightMinimum();
		long long ans = 0;
		// calculate the maximum difference between getting the
		// maximum sum, starting from the left side, and starting from the right side
		for (int i = 0; i < n - 1; i++) {
			ans = max(ans, left_max[i] - right_min[i + 1]);
			ans = max(ans, right_max[i + 1] - left_min[i]);
		}
		cout << ans << '\n';
	}
	return 0;
}
