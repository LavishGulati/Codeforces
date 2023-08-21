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

#define MAX 105
#define MOD 1000000007

bool dp[MAX][MAX][2][2];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	dp[0][0][0][0] = dp[0][0][0][1] = true;
	dp[0][0][1][0] = dp[0][0][1][1] = false;
	for (int i = 1; i < MAX; i++) {
		dp[i][0][0][0] = dp[i][0][0][1] = true;
		dp[i][0][1][0] = dp[i][0][1][1] = false;
	}
	for (int j = 1; j < MAX; j++) {
		if (j%2) {
			if ((j/2+1)%2 == 0) {
				dp[0][j][0][0] = true;
				dp[0][j][1][0] = false;
			} else {
				dp[0][j][0][0] = false;
				dp[0][j][1][0] = true;
			}
		} else {
			if ((j/2)%2 == 0) {
				dp[0][j][0][0] = true;
				dp[0][j][1][0] = false;
			} else {
				dp[0][j][0][0] = false;
				dp[0][j][1][0] = true;
			}
		}
		dp[0][j][0][1] = dp[0][j-1][0][0];
		dp[0][j][1][1] = dp[0][j-1][1][0];
	}

	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			if (dp[i-1][j][0][1] || dp[i][j-1][1][1]) {
				dp[i][j][0][0] = true;
			} else {
				dp[i][j][0][0] = false;
			}
			if (dp[i-1][j][1][1] || dp[i][j-1][0][1]) {
				dp[i][j][1][0] = true;
			} else {
				dp[i][j][1][0] = false;
			}

			if (!dp[i-1][j][0][0] || !dp[i][j-1][0][0]) {
				dp[i][j][0][1] = false;
			} else {
				dp[i][j][0][1] = true;
			}
			if (!dp[i-1][j][1][0] || !dp[i][j-1][1][0]) {
				dp[i][j][1][1] = false;
			} else {
				dp[i][j][1][1] = true;
			}
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n, even = 0, odd = 0, x;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> x;
			if (abs(x)%2) {
				odd++;
			} else {
				even++;
			}
		}

		cout << (dp[even][odd][0][0] ? "Alice" : "Bob") << endl;
	}
}