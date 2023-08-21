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

#define MAX 100005
#define MOD 1000000007

int a[MAX], b[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}

		vector<int> frost, fire;
		ll sum1 = 0, sum2 = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) {
				fire.pb(b[i]);
				sum2 += b[i];
			} else {
				frost.pb(b[i]);
				sum1 += b[i];
			}
		}

		sort(all(frost));
		sort(all(fire));
		int si = 0, sj = 0, ei = frost.size()-1, ej = fire.size()-1, id;
		ll ans = 0;
		if (si < frost.size() && sj < fire.size()) {
			if (frost.size() > fire.size()) {
				ans += frost[si];
				si++;
				id = 0;
			} else if (fire.size() > frost.size()){
				ans += fire[sj];
				sj++;
				id = 1;
			} else {
				if (frost[si] < fire[sj]) {
					ans += frost[si];
					si++;
					id = 0;
				} else {
					ans += fire[sj];
					sj++;
					id = 1;
				}
			}
		} else if (si < frost.size()) {
			ans += frost[si];
			si++;
			id = 0;
		} else if (sj < fire.size()) {
			ans += fire[sj];
			sj++;
			id = 1;
		}

		while (ei >= si && ej >= sj) {
			if (id == 0) {
				ans += 2*fire[ej];
				ej--;
				id = 1;
			} else if (id == 1) {
				ans += 2*frost[ei];
				ei--;
				id = 0;
			}
		}
		if (id == 0) {
			while (ej >= sj) {
				if (id == 0) {
					ans += 2*fire[ej];
					id = 1;
				} else {
					ans += fire[ej];
				}
				ej--;
			}
			while (ei >= si) {
				if (id == 1) {
					ans += 2*frost[ei];
					id = 0;
				} else {
					ans += frost[ei];
				}
				ei--;
			}
		} else {
			while (ei >= si) {
				if (id == 1) {
					ans += 2*frost[ei];
					id = 0;
				} else {
					ans += frost[ei];
				}
				ei--;
			}
			while (ej >= sj) {
				if (id == 0) {
					ans += 2*fire[ej];
					id = 1;
				} else {
					ans += fire[ej];
				}
				ej--;
			}
		}
		cout << ans << endl;
	}
}