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

#define MAX 10005
#define MOD 1000000007

ll a[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;

		for (ll i = 0; i < n*m; i++) {
			cin >> a[i];
		}
		sort(a, a+n*m);

		ll ans = (a[n*m-1]-a[0])*(m-1)*n + (a[n*m-2]-a[0])*(n-1);
		ans = max(ans, (a[n*m-1]-a[0])*(n-1)*m + (a[n*m-2]-a[0])*(m-1));
		ans = max(ans, (a[n*m-1]-a[0])*(n-1)*m + (a[n*m-1]-a[1])*(m-1));
		ans = max(ans, (a[n*m-1]-a[0])*(m-1)*n + (a[n*m-1]-a[1])*(n-1));
		cout << ans << endl;
	}
}