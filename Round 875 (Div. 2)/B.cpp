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
		unordered_map< int, vector<int> > mp1, mp2;
		mp1[a[0]].pb(1);
		for (int i = 1; i < n; i++) {
			if (a[i] == a[i-1]) {
				mp1[a[i]].back() += 1;
			} else {
				mp1[a[i]].pb(1);
			}
		}
		mp2[b[0]].pb(1);
		for (int i = 1; i < n; i++) {
			if (b[i] == b[i-1]) {
				mp2[b[i]].back() += 1;
			} else {
				mp2[b[i]].pb(1);
			}
		}

		for (auto it : mp1) {
			sort(all(mp1[it.f]));
		} 
		for (auto it : mp2) {
			sort(all(mp2[it.f]));
		}

		int ans = 0;
		for (auto it : mp1) {
			if (mp2.count(it.f)) {
				ans = max(ans, it.s.back() + mp2[it.f].back());
			} else {
				ans = max(ans, it.s.back());
			}
		}
		for (auto it : mp2) {
			if (!mp1.count(it.f)) {
				ans = max(ans, it.s.back());
			}
		}
		cout << ans << endl;
	}
}