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

#define MAX 100005
#define MOD 1000000007

int a[MAX];
deque<pii> dq;
pii wins[MAX];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		dq.clear();

		int n, q;
		cin >> n >> q;

		for (int i = 0; i < n; i++) {
			wins[i] = mp(-1, -1);
		}

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			dq.pb(mp(i, a[i]));
		}

		int l = 0;
		while (1) {
			pii cur = dq.front();
			if (cur.s == n) {
				break;
			}

			dq.pop_front();
			pii next = dq.front();
			dq.pop_front();

			if (cur.s > next.s) {
				if (wins[cur.f].f == -1) {
					wins[cur.f].f = l + 1;
				}
				wins[cur.f].s = l + 1;
				dq.pb(next);
				dq.push_front(cur);
			} else {
				if (wins[next.f].f == -1) {
					wins[next.f].f = l + 1;
				}
				wins[next.f].s = l + 1;
				dq.pb(cur);
				dq.push_front(next);
			}

			l++;
		}

		int idx, num;
		while (q--) {
			cin >> idx >> num;
			--idx;
			int ans = 0;
			if (a[idx] == n && num > l) {
				ans += num-l;
			}
			if (wins[idx].f != -1) {
				if (num >= wins[idx].s) {
					ans += wins[idx].s - wins[idx].f + 1;
				} else if (num >= wins[idx].f) {
					ans += num - wins[idx].f + 1;
				}
			}
			cout << ans << endl;
		}
	}
}