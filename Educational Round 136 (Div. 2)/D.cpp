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

int cut;

int find(vector<int> *graph, int u, int par, int n, int maxh) {
	int h = 0;
	for (int v : graph[u]) {
		if (v != par) {
			h = max(h, find(graph, v, u, n, maxh));
		}
	}
	if (u != 0) {
		if (par != 0 && h == maxh-1) {
			cut++;
			return 0;
		} else if (par == 0 && h == maxh) {
			cut++;
			return 0;
		}
	}
	return h+1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;

		vector<int> *graph = new vector<int>[n];
		int u;
		for (int v = 1; v < n; v++) {
			cin >> u;
			graph[u-1].pb(v);
			graph[v].pb(u-1);
		}

		int si = 1, ei = n, mid, ans = 1;
		while (si <= ei) {
			mid = (si+ei)/2;
			cut = 0;
			find(graph, 0, -1, n, mid);
			if (cut <= k) {
				ans = mid;
				ei = mid-1;
			} else {
				si = mid+1;
			}
		}
		cout << ans << endl;
	}
}