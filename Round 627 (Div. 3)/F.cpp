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

#define MAX 200005

map<int, int> color;
int output[MAX] = {0};
int answer[MAX] = {0};

int dfs1(int u, vector<int> *graph, bool *visited){
	visited[u] = true;

	int ans = 0;
	if(color[u]){
		ans = 1;
	}
	else{
		ans = -1;
	}

	int x;
	for(int v : graph[u]){
		if(!visited[v]){
			x = dfs1(v, graph, visited);
			ans += max(0, x);
		}
	}

	answer[u] = ans;
	output[u] = ans;
	return ans;
}

void dfs2(int u, vector<int> *graph, bool *visited){
	visited[u] = true;
	

	for(int v : graph[u]){
		if(!visited[v]){
			answer[u] -= max(0, answer[v]);
			answer[v] += max(0, answer[u]);

			output[u] = max(answer[u], output[u]);
			output[v] = max(answer[v], output[v]);

			dfs2(v, graph, visited);

			answer[v] -= max(0, answer[u]);
			answer[u] += max(0, answer[v]);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	int x;
	for(int i = 0; i < n; i++){
		cin >> x;
		color[i] = x;
	}

	vector<int> *graph = new vector<int>[n];
	int u, v;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v;

		graph[u-1].pb(v-1);
		graph[v-1].pb(u-1);
	}

	bool *visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}

	dfs1(0, graph, visited);

	// for(int i = 0; i < n; i++){
	// 	cout << output[i] << " ";
	// }
	// cout << endl;

	for(int i = 0; i < n; i++){
		visited[i] = false;
	}
	dfs2(0, graph, visited);

	for(int i = 0; i < n; i++){
		cout << output[i] << " ";
	}
	cout << endl;
}