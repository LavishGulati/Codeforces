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
#define MAX 1005

vector<int> graph[MAX];
vector<int> dist(MAX);
vector<int> atdist[MAX];
int maxDepth;

void computeDist(int root, int n){
	bool *visited = new bool[n];
	for(int i = 0; i < n; i++){
		visited[i] = false;
	}

	queue<pii> q;
	q.push(mp(root, 0));
	visited[root] = true;
	while(!q.empty()){
		pii u = q.front();
		q.pop();
		atdist[u.s].pb(u.f);
		maxDepth = max(maxDepth, u.s);
		dist[u.f] = u.s;

		for(int v : graph[u.f]){
			if(!visited[v]){
				visited[v] = true;
				q.push(mp(v, u.s+1));
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		string output;

		for(int i = 0; i < n; i++){
			graph[i].clear();
			atdist[i].clear();
		}
		dist.clear();
		maxDepth = 0;

		int u, v;
		for(int i = 0; i < n-1; i++){
			cin >> u >> v;
			graph[u-1].pb(v-1);
			graph[v-1].pb(u-1);
		}

		cout << "? " << n << " ";
		for(int i = 0; i < n; i++){
			cout << i+1 << " ";
		}
		cout << endl;

		int root, sum;
		cin >> root >> sum;

		computeDist(root-1, n);

		int si = ((sum%2 == 0) ? sum/2 : sum/2 + 1);
		int ei = sum;
		int mid, ans, d;
		while(si <= ei){
			mid = (si+ei)/2;

			if(atdist[mid].size() == 0){
				ei = mid-1;
				continue;
			}

			cout << "? " << atdist[mid].size() << " ";
			for(int i = 0; i < atdist[mid].size(); i++){
				cout << atdist[mid][i]+1 << " ";
			}
			cout << endl;

			cin >> u >> d;

			if(d == sum){
				ans = u-1;
				si = mid+1;
			}
			else{
				ei = mid-1;
			}
		}

		for(int i = 0; i < n; i++){
			atdist[i].clear();
		}
		dist.clear();

		computeDist(ans, n);

		d = sum;
		vector<int> help;
		for(int i = 0; i < atdist[d].size(); i++){
			if(atdist[d][i] != ans){
				help.pb(atdist[d][i]+1);
			}
		}
		cout << "? " << help.size() << " ";
		for(int i = 0; i < help.size(); i++){
			cout << help[i] << " ";
		}
		cout << endl;

		int ans2;
		cin >> ans2 >> d;
		cout << "! " << ans+1 << " " << ans2 << endl;

		cin >> output;
	}
}