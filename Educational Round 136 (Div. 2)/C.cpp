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

#define MAX 64
#define MOD 998244353

ll power(ll x, ll n) {
	if (n == 0) {
		return 1;
	} else if (n == 1) {
		return x%MOD;
	}

	ll y = power(x, n/2);
	if (n%2) {
		return (x*((y*y)%MOD))%MOD;
	} else {
		return (y*y)%MOD;
	}
}

ll modInverse(ll x) {
	return power(x, MOD-2);
}

ll C(ll n, ll m) {
	ll ans = 1;
	for (ll i = 1; i <= n; i++) {
		ans = (ans*i)%MOD;
	}
	for (ll i = 1; i <= m; i++) {
		ans = (ans*modInverse(i))%MOD;
	}
	for (ll i = 1; i <= n-m; i++) {
		ans = (ans*modInverse(i))%MOD;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll dp[MAX];
	dp[2] = 1;
	for (int i = 4; i < MAX; i += 2) {
		dp[i] = C(i-1, i/2);
		dp[i] = (dp[i]+C(i-2, i/2-1))%MOD;
		dp[i] = (dp[i]-1+MOD)%MOD;
		dp[i] = (dp[i]-dp[i-2]+MOD)%MOD;
	}

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		ll lose = C(n, n/2);
		lose = (lose-1+MOD)%MOD;
		lose = (lose-dp[n]+MOD)%MOD;
		cout << dp[n] << " " << lose << " " << 1 << endl;
	}
}