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

#define MOD 1000000007

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, q;
	cin >> n >> q;
	ll *a = new ll[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a+n);

	ll k, ans, sum;
	while (q--) {
		cin >> k;
		sum = 0;
		ans = LLONG_MAX;
		if (k <= n) {
			for (ll i = 0; i < k; i++) {
				ans = min(ans, a[i] + k-i);
			}
			for (ll i = k; i < n; i++) {
				ans = min(ans, a[i]);
			}
			cout << ans << " ";
		} else if (n%2 == k%2) {
			for (ll i = 0; i < n; i++) {
				sum += a[i] + k-i;
				ans = min(ans, a[i] + k-i);
			}
			sum -= n * ans;
			ans -= ceil(1.0 * max(0LL, (k-n)/2 - sum) / n);
			cout << ans << " ";
		} else {
			for (ll i = 0; i < n-1; i++) {
				sum += a[i] + k-i;
				ans = min(ans, a[i] + k-i);
			}
			sum += a[n-1];
			ans = min(ans, a[n-1]);
			sum -= n * ans;
			ans -= ceil(1.0 * max(0LL, (k-n+1)/2 - sum) / n);
			cout << ans << " ";
		}
	}
	cout << endl;
}