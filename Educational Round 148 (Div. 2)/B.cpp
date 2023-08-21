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

ll a[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;

		for (ll i = 0; i < n; i++) {
			cin >> a[i];
		}

		sort(a, a+n);
		for (ll i = 1; i < n; i++) {
			a[i] += a[i-1];
		}

		ll ans = a[n-k-1];
		for (ll i = 1; i <= k; i++) {
			ans = max(ans, a[n-k-1+i]-a[2*i-1]);
		}
		cout << ans << endl;
	}
}