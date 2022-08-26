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

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;

		if (k%2 == 1) {
			cout << "YES\n";
			for (ll i = 1; i <= n; i += 2) {
				cout << i << " " << i+1 << endl;
			}
		} else {
			if (k%4 == 0) {
				cout << "NO\n";
			} else {
				cout << "YES\n";
				for (ll i = 1; i <= n; i += 2) {
					if (i%4 == 1) {
						cout << i+1 << " " << i << endl;
					} else {
						cout << i << " " << i+1 << endl;
					}
				}
			}
		}
	}
}