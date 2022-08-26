#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()
#define pq priority_queue

#define MOD 1000000007

#define MAX 200009

int parent[MAX], tin[MAX], tout[MAX];
set<int> myset, newset;
map<int, int> dist;

void dfs(int u, vector<int> *graph, bool *visited){
	static int time = 0;
	visited[u] = true;
	tin[u] = ++time;

	for(int v : graph[u]){
		if(!visited[v]){
			parent[v] = u;
			dfs(v, graph, visited);
		}
	}

	tout[u] = ++time;
}

// int bfs(int u, vector<int> *graph, bool *visited){
void bfs(int u, vector<int> *graph){
	queue<pii> q;
	q.push(mp(u, 0));
	// visited[u] = true;
	// int ans = -1;
	// vector<int> output;

	while(!q.empty()){
		int v = q.front().f;
		int h = q.front().s;
		// output.pb(v);
		dist[v] = h;
		q.pop();
		// if(myset.find(v) != myset.end()){
		// 	ans = v;
		// }

		for(int adj : graph[v]){
			// if(!visited[adj]){
			if(parent[v] != adj){
				q.push(mp(adj, h+1));
				// visited[adj] = true;
			}
		}
	}

	// return output;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> *graph = new vector<int>[n];
	int u, v;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v;
		graph[u-1].pb(v-1);
		graph[v-1].pb(u-1);
	}

	parent[0] = -1;
	bool *visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}
	dfs(0, graph, visited);

	bool ans;

	bfs(0, graph);
	// vector<int> output = bfs(0, graph);
	int farthest;

	while(m--){
		myset.clear();

		int k;
		cin >> k;

		farthest = -1;

		for(int i = 0; i < k; i++){
			cin >> u;
			myset.insert(u-1);
			if(farthest == -1 || dist[u-1] > dist[farthest]){
				farthest = u-1;
			}
		}

		// for(int i = 0; i < n; i++){
		// 	visited[i] = false;
		// }
		// int farthestv = bfs(0, graph, visited);
		// int farthestv = bfs(0, graph);
		// cout << farthestv+1 << " ";

		newset.clear();
		for(int v : myset){
			if(v != farthest){
				newset.insert(parent[v]);
			}
		}

		ans = true;
		for(int v : newset){
			// cout << v << " " << tin[v] << " " << tout[v] << " " << tin[farthestv] << " " << tout[farthestv] << endl;
			if(v == -1 || (tin[farthest] >= tin[v] && tout[farthest] <= tout[v])){
				// correct
			}
			else{
				ans = false;
				break;
			}
		}
		if(ans){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}