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

const int K = 1e9 + 1;

vector<int> calc(vector< vector<int> > a) {
	int n = a.size();
	vector<pii> l(n), r(n);
	for (int i = 0; i < n; i++) {
		l[i] = mp(a[i][0], i);
		r[i] = mp(a[i][1], i);
	}
	sort(all(l));
	sort(all(r));
	vector< vector<pii> > suf(n);
	vector<pii> cur;
	for (int i = n-1; i >= 0; i--) {
		int xr = r[i].f;
		int id = r[i].s;
		int xl = a[id][0];
		int c = a[id][2];
		if (cur.empty()) {
			cur.pb(mp(xl, c));
		} else if (cur.size() == 1) {
			if (cur[0].s == c) {
				cur[0].f = min(cur[0].f, xl);
			} else {
				cur.pb(mp(xl, c));
			}
		} else {
			if (cur[0].s == c) {
				cur[0].f = min(cur[0].f, xl);
			} else if (cur[1].s == c) {
				cur[1].f = min(cur[1].f, xl);
			} else {
				cur.pb(mp(xl, c));
			}
		}
		sort(all(cur));
		if (cur.size() == 3) {
			cur.pop_back();
		}
		suf[i] = cur;
	}

	vector<int> ans(n, 1e9);
	int j = 0;
	for (int i = 0; i < n; i++) {
		int xl = l[i].f, id = l[i].s;
		int xr = a[id][1], c = a[id][2];
		while (j < n && r[j].f < xl) {
			j++;
		}

		if (j < n) {
			vector<pii> s = suf[j];
			if (s[0].s != c) {
				ans[id] = min(ans[id], max(0, s[0].f-xr));
			} else if (s.size() == 2) {
				ans[id] = min(ans[id], max(0, s[1].f-xr));
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;

		vector< vector<int> > a(n, vector<int>(3)), b(n, vector<int>(3));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> a[i][j];
				if (j == 2) {
					b[i][j] = a[i][j];
				} else {
					b[i][1-j] = K - a[i][j];
				}
			}
		}

		vector<int> ans1 = calc(a), ans2 = calc(b);
		for (int i = 0; i < n; i++) {
			cout << min(ans1[i], ans2[i]) << " ";
		}
		cout << endl;
	}
}