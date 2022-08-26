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

vector<ll> graph[MAX];
ll path[MAX][3];
ll p[MAX];

void bfs(ll s, ll id){
	path[s][id] = 0;
	queue<ll> q;
	q.push(s);
	while(!q.empty()){
		ll u = q.front();
		q.pop();
		for(ll v : graph[u]){
			if(path[v][id] == -1){
				path[v][id] = path[u][id]+1;
				q.push(v);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n, m, a, b, c;
		cin >> n >> m >> a >> b >> c;

		for(ll i = 1; i <= n; i++){
			graph[i].clear();
		}

		for(ll i = 0; i < m; i++){
			cin >> p[i];
		}
		sort(p, p+m);
		for(ll i = 1; i < m; i++){
			p[i] += p[i-1];
		}


		ll u, v;
		for(ll i = 0; i < m; i++){
			cin >> u >> v;
			graph[u].pb(v);
			graph[v].pb(u);
		}

		for(ll j = 0; j < 3; j++){
			for(ll i = 1; i <= n; i++){
				path[i][j] = -1;
			}
		}


		bfs(a, 0);

		bfs(b, 1);

		bfs(c, 2);

		// for(ll j = 0; j < 3; j++){
		// 	for(ll i = 1; i <= n; i++){
		// 		cout << path[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }

		ll ans = LLONG_MAX;
		for(ll i = 1; i <= n; i++){
			ll x = path[i][0];
			ll y = path[i][1];
			ll z = path[i][2];
			if(y > 0 && x+y+z-1 < m && y-1 < m){
				// cout << i << " " << p[y-1] + p[x+y+z-1] << endl;
				ans = min(ans, p[y-1] + p[x+y+z-1]);
			}
			else if(x+y+z-1 < m){
				// cout << i << " " << p[x+y+z-1] << endl;
				ans = min(ans, p[x+y+z-1]);
			}
		}
		cout << ans << endl;
	}
}