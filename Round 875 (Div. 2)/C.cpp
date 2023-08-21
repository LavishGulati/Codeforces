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

unordered_map< int, unordered_map<int, int> > indexmap;
int ans;

void dfs(int u, int par, vector<int> *graph, int cur) {
	ans = max(ans, cur);
	for (int v : graph[u]) {
		if (v != par) {
			if (indexmap[min(u, v)][max(u, v)] > indexmap[min(u, par)][max(u, par)]) {
				dfs(v, u, graph, cur);
			} else {
				dfs(v, u, graph, cur+1);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		indexmap.clear();

		int n;
		cin >> n;
		vector<int> *graph = new vector<int>[n];
		int u, v;
		for (int i = 0; i < n-1; i++) {
			cin >> u >> v;
			graph[u-1].pb(v-1);
			graph[v-1].pb(u-1);
			indexmap[min(u-1, v-1)][max(u-1, v-1)] = i;
		}

		ans = 0;
		indexmap[-1][0] = -1;
		dfs(0, -1, graph, 0);
		cout << ans+1 << endl;
	}
}