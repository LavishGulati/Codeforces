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

		int num = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] != 0) {
				num++;
			}
		}

		if (num%2) {
			cout << -1 << endl;
			continue;
		}

		vector<pii> index;
		int last = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) {
				index.pb(mp(i, i));
			} else if (last == -1) {
				index.pb(mp(i, i));
				last = i;
			} else if (a[i] == a[last]) {
				index.back().s = i;
				last = -1;
			} else {
				index.pb(mp(i, i));
				last = -1;
			}
		}
		cout << index.size() << endl;
		for (const auto& [l, r] : index) {
			cout << l+1 << " " << r+1 << endl;
		}
	}
}