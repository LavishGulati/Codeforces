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

		if (x < y) {
			swap(x, y);
		}

		if (x == 0 & y == 0) {
			cout << -1 << endl;
			continue;
		} else if (!(x == 0 || y == 0)) {
			cout << -1 << endl;
			continue;
		} else if (!((n-1)%x == 0)) {
			cout << -1 << endl;
			continue;
		}

		int help = 1;
		for (int i = 1; i < n; i += x) {
			for (int j = 0; j < x; j++) {
				cout << help << " ";
			}
			if (help == 1) {
				help++;
			}
			help += x;
		}
		cout << endl;
	}
}