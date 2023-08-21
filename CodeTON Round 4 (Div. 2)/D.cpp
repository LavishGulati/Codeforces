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
		ll q;
		cin >> q;
		ll si = 1, ei = 1e18, type, a, b, n;
		ll start, end;
		while (q--) {
			cin >> type;
			if (type == 1) {
				cin >> a >> b >> n;
				start = (n-2)*(a-b) + a + 1;
				end = (n-1)*(a-b) + a;
				if (n == 1) {
					start = 1;
					end = a;
				}
				if (start > ei || end < si) {
					cout << 0 << endl;
				} else {
					si = max(si, start);
					ei = min(ei, end);
					cout << 1 << endl;
				}
			} else {
				cin >> a >> b;
				start = max(1LL, (si-b-1)/(a-b)+1);
				end = max(1LL, (ei-b-1)/(a-b)+1);
				if (start == end) {
					cout << start << endl;
				} else {
					cout << -1 << endl;
				}
			}
		}
	}
}