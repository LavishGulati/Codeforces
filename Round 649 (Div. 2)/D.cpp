#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

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

#define MAX 100005

int start = 0, len = 0;
int cycle[MAX];

bool dfs(int u, int par, vector<int> *graph, bool *visited){
	visited[u] = true;
	cycle[len++] = u;

	vector<int> neigh;
	for(int v : graph[u]){
		if(!visited[v]){
			neigh.pb(v);
		}
		else if(v != par){
			for(int i = 0; i < len; i++){
				if(cycle[i] == v){
					start = i;
					break;
				}
			}
			return true;
		}
	}

	for(int v : neigh){
		if(dfs(v, u, graph, visited)){
			return true;
		}
	}

	len--;
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<int> *graph = new vector<int>[n];
	int u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		graph[u-1].pb(v-1);
		graph[v-1].pb(u-1);
	}

	bool *visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}
	bool isCycle = dfs(0, -1, graph, visited);

	if(isCycle){
		if(len-start <= k){
			cout << "2\n" << len-start << endl;
			for(int i = start; i < len; i++){
				cout << cycle[i]+1 << " ";
			}
			cout << endl;
		}
		else{
			cout << 1 << endl;
			for(int i = 0; i < ceil(k/double(2)); i++){
				cout << cycle[2*i]+1 << " ";
			}
			cout << endl;
		}
	}
	else{
		for(int i = 0; i < n; i++){
			visited[i]  = false;
		}
		bool *included = new bool[n];
		for(int i = 0; i < n; i++){
			included[i] = false;
		}

		queue<int> q;
		included[0] = true;
		len = 1;
		visited[0] = true;
		q.push(0);
		while(!q.empty()){
			int u = q.front();
			q.pop();
			for(int v : graph[u]){
				if(!visited[v]){
					q.push(v);
					visited[v] = true;
					if(!included[u]){
						included[v] = true;
						len++;
					}
				}
			}
		}

		if(len >= ceil(k/2.0)){
			cout << 1 << endl;
			len = 0;
			for(int i = 0; i < n && len < ceil(k/double(2)); i++){
				if(included[i]){
					cout << i+1 << " ";
					len++;
				}
			}
		}
		else{
			cout << 1 << endl;
			len = 0;
			for(int i = 0; i < n && len < ceil(k/double(2)); i++){
				if(!included[i]){
					cout << i+1 << " ";
					len++;
				}
			}
		}
	}
}