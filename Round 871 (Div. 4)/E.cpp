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

#define MAX 1005
#define MOD 1000000007

int a[MAX][MAX];
bool vis[MAX][MAX];

int movex[4] = {1, -1, 0, 0};
int movey[4] = {0, 0, -1, 1};

int dfs(int u, int v, int n, int m) {
	vis[u][v] = true;
	int ans = a[u][v];
	for (int i = 0; i < 4; i++) {
		int x = u + movex[i];
		int y = v + movey[i];
		if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] > 0 && !vis[x][y]) {
			ans += dfs(x, y, n, m);
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
				vis[i][j] = false;
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] > 0 && !vis[i][j]) {
					ans = max(ans, dfs(i, j, n, m));
				}
			}
		}
		cout << ans << endl;
	}
}