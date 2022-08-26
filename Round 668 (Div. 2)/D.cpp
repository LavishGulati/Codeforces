#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> tii;
typedef pair<long long, pair<long long, long long>> tll;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define MOD 1000000007

int dist, ans;

void dfs(int u, vector<int> *graph, bool *vis, int d){
	vis[u] = true;
	if(d > dist){
		dist = d;
		ans = u;
	}

	for(int v : graph[u]){
		if(!vis[v]){
			dfs(v, graph, vis, d+1);
		}
	}
}

int findMaxDist(vector<int> *graph, int n){
	bool *vis = new bool[n];
	for(int i = 0; i < n; i++){
		vis[i] = false;
	}

	dist = 0; ans = 0;
	dfs(0, graph, vis, 0);

	dist = 0;
	for(int i = 0; i < n; i++){
		vis[i] = false;
	}
	dfs(ans, graph, vis, 0);
	return dist;
}

int findDistAB(int u, vector<int> *graph, bool *vis, int dest, int d){
	if(u == dest){
		return 0;
	}
	vis[u] = true;
	for(int v : graph[u]){
		if(!vis[v]){
			int ans = findDistAB(v, graph, vis, dest, d+1);
			if(ans != -1){
				return ans+1;
			}
		}
	}
	return -1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n, a, b, da, db;
		cin >> n >> a >> b >> da >> db;
		--a; --b;

		vector<int> *graph = new vector<int>[n];
		int u, v;
		for(int i = 0; i < n-1; i++){
			cin >> u >> v;
			graph[u-1].pb(v-1);
			graph[v-1].pb(u-1);
		}

		bool *vis = new bool[n];
		for(int i = 0; i < n; i++){
			vis[i] = false;
		}

		int ab = findDistAB(a, graph, vis, b, 0);

		int d = findMaxDist(graph, n);
		if(ab <= da){
			cout << "Alice" << endl;
		}
		else if(db > 2*da && d > 2*da){
			cout << "Bob" << endl;
		}
		else{
			cout << "Alice" << endl;
		}
	}	
}