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

int a[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}

		int si = 1, ei = 1;
		ll ans = 0;
		while (si <= n) {
			while (ei <= n && a[ei] >= ei+1-si) {
				ei++;
			}

			ans += ei-si;
			si++;
			if (ei < si) {
				ei = si;
			}
		}

		cout << ans << endl;
	}
}