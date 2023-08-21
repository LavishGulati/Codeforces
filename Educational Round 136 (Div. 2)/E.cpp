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

int dp[MAX][2][2];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<string> s(2);
	cin >> s[0] >> s[1];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			dp[i][j][0] = dp[i][j][1] = INT_MIN;
		}
	}

	dp[0][0][s[1][0] == '1'] = s[1][0] == '1';
	dp[0][0][0] = 0;
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < 2; j++) {
			int nxtj = s[j][i+1] == '1';
			int nxtj1 = s[j^1][i+1] == '1';
			dp[i+1][j^1][0] = max(dp[i+1][j^1][0], dp[i][j][1]+nxtj1);
			dp[i+1][j][nxtj1] = max(dp[i+1][j][nxtj1], dp[i][j][0]+nxtj1+nxtj);
			dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][0]+nxtj);
		}
	}
	cout << max({dp[n - 1][0][0], dp[n - 1][0][1], dp[n - 1][1][0], dp[n - 1][1][1]}) << endl;
}