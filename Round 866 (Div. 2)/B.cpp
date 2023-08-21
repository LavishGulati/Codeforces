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
		string s;
		cin >> s;

		ll n = s.length();
		ll maxlen = 0, idx = 0;
		while (idx < n && s[idx] == '1') {
			idx++;
		}

		if (idx == n) {
			maxlen = n;
			ll ans = maxlen * maxlen;
			cout << ans << endl;
			continue;
		} else {
			ll len = 0, i = idx;
			do {
				if (s[i] == '0') {
					maxlen = max(len, maxlen);
					len = 0;
				} else {
					len++;
				}
				i = (i+1)%n;
			} while (i != idx);
			maxlen = max(len, maxlen);
		}

		bool add = false;
		if (!(maxlen%2)) {
			maxlen--;
			add = true;
		}

		maxlen = (maxlen+1)/2;
		ll ans = maxlen * maxlen + (add ? maxlen : 0);
		cout << ans << endl;
	}
}