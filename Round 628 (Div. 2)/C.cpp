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

#define MOD 1000000007

int minAllot, maxAllot;
map<pii, int> myMap;
vector<int> output;

int dfs(int u, vector<int> *graph, bool *isVisited){
	isVisited[u] = true;

	int x = u;
	for(int v : graph[u]){
		if(!isVisited[v]){
			x = dfs(v, graph, isVisited);
		}
	}

	return x;
}

void dfs2(int u, vector<int> *graph, bool *isVisited, int root){
	isVisited[u] = true;
	for(int v : graph[u]){
		if(!isVisited[v]){
			if(u == root){
				int id = myMap[mp(min(u, v), max(u, v))];
				output[id] = minAllot;
				minAllot++;
			}
			else{
				int id = myMap[mp(min(u, v), max(u, v))];
				output[id] = maxAllot;
				maxAllot--;
			}
			dfs2(v, graph, isVisited, root);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	vector<int> *graph = new vector<int>[n];
	int u, v;	
	for(int i = 0; i < n-1; i++){
		cin >> u >> v;
		graph[u-1].pb(v-1);
		graph[v-1].pb(u-1);
		myMap[mp(min(u, v)-1, max(u, v)-1)] = i;
		output.pb(-1);
	}

	bool *isVisited = new bool[n];
	for(int i = 0; i < n; i++){
		isVisited[i] = false;
	}
	int root = dfs(0, graph, isVisited);

	// cout << "ROOT: " << root+1 << endl;

	for(int i = 0; i < n; i++){
		isVisited[i] = false;
	}
	int id = myMap[mp(min(root, graph[root][0]), max(root, graph[root][0]))];
	output[id] = 0;
	isVisited[root] = true;
	root = graph[root][0];
	
	minAllot = 1;
	maxAllot = n-2;

	while(graph[root].size() == 2){
		int v = (isVisited[graph[root][0]]) ? graph[root][1] : graph[root][0];
		id = myMap[mp(min(root, v), max(root, v))];
		output[id] = maxAllot;
		maxAllot--;
		isVisited[root] = true;
		root = v;
	}

	
	dfs2(root, graph, isVisited, root);

	for(int i = 0; i < n-1; i++){
		cout << output[i] << "\n";
	}
}