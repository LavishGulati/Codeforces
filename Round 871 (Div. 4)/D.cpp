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

	ll t;
	cin >> t;
	while (t--) {
		ll n, m;
		cin >> n >> m;
		if (n == m) {
			cout << "YES" << endl;
			continue;
		}

		ll cnt = 2, x = -1;
		while (n%3 == 0) {
			for (ll i = 0; i < cnt; i++) {
				x = (1<<i) * n / 3;
				if (x == m) {
					break;
				}
			}
			if (x == m) {
				break;
			}
			cnt++;
			n /= 3;
		}
		cout << (x == m ? "YES" : "NO") << endl;
	}
}