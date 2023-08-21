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
#define MOD 998244353

int a[MAX];
ll dp[MAX];

ll power(ll x, ll n) {
	if (n == 0) {
		return 1;
	} else if (n == 1) {
		return x%MOD;
	}

	ll y = power(x, n/2);
	y = (y*y)%MOD;
	if (n%2) {
		return (x*y)%MOD;
	} else {
		return y;
	}
}

ll modInverse(ll x) {
	return power(x, MOD-2);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		int g = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] == 0) {
				g++;
			}
		}

		if (n == 1) {
			cout << 0 << endl;
			continue;
		}

		int o = 0;
		for (int i = 0; i < g; i++) {
			if (a[i] == 0) {
				o++;
			}
		}

		dp[g] = 0;
		for (int i = g-1; i >= o; i--) {
			ll help = 2;
			help = (help*(g-i))%MOD;
			help = (help*(g-i))%MOD;
			help = (help*modInverse(n))%MOD;
			help = (help*modInverse(n-1))%MOD;
			dp[i] = 1;
			dp[i] = (dp[i]+(dp[i+1]*help)%MOD)%MOD;
			dp[i] = (dp[i]*modInverse(help))%MOD;
		}
		cout << dp[o] << endl;
	}
}