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

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> *graph = new vector<int>[n];
		int u, v;
		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			graph[u-1].pb(v-1);
			graph[v-1].pb(u-1);
		}

		int single = 0;
		for (int i = 0; i < n; i++) {
			if (graph[i].size() == 1) {
				single++;
			}
		}

		int x = m - single;
		cout << x << " " << single/x << endl;
	}
}