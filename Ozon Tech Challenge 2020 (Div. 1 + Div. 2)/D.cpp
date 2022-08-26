#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define MOD 1000000007

int farthest(int u, vector<int> *graph, int n){
	bool *isVisited = new bool[n];
	for(int i = 0; i < n; i++){
		isVisited[i] = false;
	}

	queue<int> q;
	q.push(u);
	int ans = u;
	isVisited[u] = true;

	while(!q.empty()){
		int s = q.front();
		q.pop();
		for(int v : graph[s]){
			if(!isVisited[v]){
				ans = v;
				q.push(v);
				isVisited[v] = true;
			}
		}
	}

	return ans;
}

bool dfs(int u, int v, vector<int> &output, vector<int> *graph, int n, bool *isVisited){
	isVisited[u] = true;
	output.pb(u);

	if(u == v){
		return true;
	}

	for(int s : graph[u]){
		if(!isVisited[s]){
			// output.pb(s);
			if(dfs(s, v, output, graph, n, isVisited)){
				return true;
			}
			// output.pop_back();
		}
	}

	// isVisited[u] = false;
	output.pop_back();
	return false;
}

void dfs2(int u, vector<int> *graph, int n, set<int> &st, bool *isVisited){
	isVisited[u] = true;
	st.erase(st.find(u));
	for(int v : graph[u]){
		if(!isVisited[v]){
			// st.erase(st.find(v));
			dfs2(v, graph, n, st, isVisited);
		}
	}
}

vector<int> path(int u, int v, vector<int> *graph, int n){
	bool *isVisited = new bool[n];
	for(int i = 0; i < n; i++){
		isVisited[i] = false;
	}

	vector<int> output;
	dfs(u, v, output, graph, n, isVisited);
	return output;
}

void solve(vector<int> *graph, set<int> &st, int n){
	int cnt = 0;
	while(st.size() > 1){

		int u = *st.begin();
		int v = farthest(u, graph, n);

		cout << "? " << u+1 << " " << v+1 << endl;
		int s;
		cin >> s;
		s--;

		// Delete connecting edge s to u and s to v and remove vertices from set
		vector<int> path1 = path(s, u, graph, n);
		vector<int> path2 = path(s, v, graph, n);

		// for(int i = 0; i < path1.size(); i++){
		// 	cout << path1[i] << " ";
		// }
		// cout << endl;

		// for(int i = 0; i < path2.size(); i++){
		// 	cout << path2[i] << " ";
		// }
		// cout << endl;

		if(s != u){
			for(int i = 0; i < graph[s].size(); i++){
				if(graph[s][i] == path1[1]){
					graph[s].erase(graph[s].begin()+i);
					break;
				}
			}

			for(int i = 0; i < graph[path1[1]].size(); i++){
				if(graph[path1[1]][i] == s){
					graph[path1[1]].erase(graph[path1[1]].begin()+i);
					break;
				}
			}

			bool *isVisited = new bool[n];
			for(int i = 0; i < n; i++){
				isVisited[i] = false;
			}

			dfs2(u, graph, n, st, isVisited);
		}

		if(s != v){
			for(int i = 0; i < graph[s].size(); i++){
				if(graph[s][i] == path2[1]){
					graph[s].erase(graph[s].begin()+i);
					break;
				}
			}

			for(int i = 0; i < graph[path2[1]].size(); i++){
				if(graph[path2[1]][i] == s){
					graph[path2[1]].erase(graph[path2[1]].begin()+i);
					break;
				}
			}

			bool *isVisited = new bool[n];
			for(int i = 0; i < n; i++){
				isVisited[i] = false;
			}

			dfs2(v, graph, n, st, isVisited);
		}

		// for(int x : st){
		// 	cout << x << " ";
		// }
		// cout << endl;

		cnt++;
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
	}

	set<int> st;
	for(int i = 0; i < n; i++){
		st.insert(i);
	}

	solve(graph, st, n);
	cout << "! " << *st.begin()+1 << endl;
}