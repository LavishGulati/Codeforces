#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair< int, pair<int, int> > tii;
typedef pair< long long, pair<long long, long long> > tll;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define MOD 1000000007

string merge(string& a, string& b) {
	int n = a.length(), m = b.length();
	int i = 0, j = 0;
	string ans = "";
	while (i < n && j < m) {
		if (a[i] < b[j]) {
			ans += a[i];
			i++;
		} else {
			ans += b[j];
			j++;
		}
	}
	while (i < n) {
		ans += a[i];
		i++;
	}
	while (j < m) {
		ans += b[j];
		j++;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		int n = s.length();
		int *dp = new int[n];
		dp[n-1] = n-1;
		for (int i = n-2; i >= 0; i--) {
			if (s[i] <= s[dp[i+1]]) {
				dp[i] = i;
			} else {
				dp[i] = dp[i+1];
			}
		}

		string left = "", right = "";
		int i = 0;
		for (int i = 0; i < n; i++) {
			if (dp[i] == i) {
				left += s[i];
			} else {
				right += min(int('9'), s[i]+1);
			}
		}

		sort(all(right));
		string ans = merge(left, right);
		cout << ans << endl;
	}
}