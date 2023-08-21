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
 
	int t;
	cin >> t;
	while (t--) {
		int n, x, y;
		cin >> n >> x >> y;
		string a, b;
		cin >> a >> b;
 
		int para = 0, parb = 0;
		int parity = 0;
		bool consec = false;
		for (int i = 0; i < n; i++) {
			if (a[i] == '1') {
				para++;
			}
			if (b[i] == '1') {
				parb++;
			}
			if (a[i] != b[i]) {
				if (i+1 < n && a[i+1] != b[i+1]) {
					consec = true;
				}
				parity++;
			}
		}
 
		if (para%2 != parb%2) {
			cout << -1 << endl;
			continue;
		}
 
		ll ans;
		if (parity > 2) {
			ans = (1LL*y*parity)/2;
		} else if (parity == 0) {
			ans = 0;
		}
		else if (consec) {
			ans = min(2LL*y, 1LL*x);
		} else {
			ans = y;
		}
		cout << ans << endl;
	}
}