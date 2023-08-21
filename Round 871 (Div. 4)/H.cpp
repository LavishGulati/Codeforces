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
#define MAXN 200005
#define MOD 1000000007

ll freq[MAX], help[MAX], dp[MAX];
ll power[MAXN];

ll digits(ll x) {
	ll ans = 0;
	for (ll i = 0; i < 6; i++) {
		if (x%2) {
			ans++;
		}
		x /= 2;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	power[0] = 1;
	for (ll i = 1; i < MAXN; i++) {
		power[i] = (2*power[i-1])%MOD;
	}

	ll t;
	cin >> t;
	while (t--) {
		ll n, k, x;
		cin >> n >> k;

		for (ll i = 0; i < MAX; i++) {
			freq[i] = help[i] = dp[i] = 0;
		}

		for (ll i = 0; i < n; i++) {
			cin >> x;
			freq[x]++;
		}

		for (ll i = 0; i < MAX; i++) {
			for (ll j = 0; j < MAX; j++) {
				help[j] = dp[j];
			}
			help[i] = (help[i] + power[freq[i]] - 1)%MOD;
			for (ll j = 0; j < MAX; j++) {
				help[j&i] = (help[j&i] + (dp[j]*(power[freq[i]]-1))%MOD)%MOD;
			}
			for (ll j = 0; j < MAX; j++) {
				dp[j] = help[j];
			}
		}

		ll ans = 0;
		for (ll i = 0; i < MAX; i++) {
			if (digits(i) == k) {
				ans = (ans+dp[i])%MOD;
			}
		}
		cout << ans << endl;
	}
}