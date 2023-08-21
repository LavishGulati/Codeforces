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
		ll n, c, d, x;
		cin >> n >> c >> d;

		ll ans = 0;
		set<ll> st;
		for (ll i = 0; i < n; i++) {
			cin >> x;
			if (st.find(x) != st.end()) {
				ans += c;
			} else {
				st.insert(x);
			}
		}

		ll holes = 0, prev = 0;
		for (ll x : st) {
			holes += x-prev-1;
			prev = x;
		}

		ll smallans = LLONG_MAX;
		prev = INT_MAX;
		ll taken1 = 0, taken2 = 0;
		for (auto it = st.rbegin(); it != st.rend(); it++) {
			ll cur = *it;
			if (prev-cur > 1) {
				if (prev != INT_MAX) {
					taken1 += prev-cur-1;
				} 
				smallans = min(smallans, (holes - taken1) * d + taken2 * c);
			}
			prev = cur;
			taken2++;
		}

		smallans = min(smallans, ll(st.size()) * c + d);
		cout << ans + smallans << endl;
	}
}