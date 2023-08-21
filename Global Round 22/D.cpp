#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// #pragma GCC optimize("O3")

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
	// ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);

		int *b = new int[n];
		unordered_map<int, vector<int>> graph;
		for (int i = 0; i < n; i++) {
			scanf("%d", b+i);
			graph[b[i]].pb(i+1);
		}

		int k = 1;
		while (k <= n && b[k-1] > k) {
			k++;
		}
		k--;
		printf("%d\n", k);

		int root = (graph[0].size() > 0 ? 0 : n+1);
		queue<pii> q;
		q.push(mp(root, -1));
		while (!q.empty()) {
			const auto& [u, par] = q.front();
			if (u != root) {
				printf("%d ", u);
			}
			q.pop();
			int nonleaf = -1;
			for (int v : graph[u]) {
				if (v != par) {
					if (graph[v].size() > 0) {
						nonleaf = v;
					} else {
						q.push(mp(v, u));
					}
				}
			}
			if (nonleaf != -1) {
				q.push(mp(nonleaf, u));
			}
		}
		printf("\n");
	}
}