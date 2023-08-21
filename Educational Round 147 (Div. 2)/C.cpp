#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
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

#define MAX 200005
#define MOD 1000000007

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int *dp = new int[MAX];
	dp[0] = 0; dp[1] = 1;
	for (int i = 2; i < MAX; i++) {
		dp[i] = dp[i/2]+1;
	}

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		int n = s.length(), si, ei, ans = INT_MAX, smallans;
		for (int j = 0; j < 26; j++) {
			si = 0; ei = 0;
			smallans = 0;
			while (si < n) {
				while (ei < n && s[ei] != 'a'+j) {
					ei++;
				}

				if (si == ei) {
					si++;
					ei = si;
					continue;
				}

				smallans = max(smallans, dp[ei-si]);
				si = ei;
				ei = si;
			}
			ans = min(ans, smallans);
		}
		cout << ans << endl;
	}
}