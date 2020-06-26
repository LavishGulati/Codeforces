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

#define MAX 100009

vector<ll> graph[MAX];
ll maxans;
bool same;

ll dfs(ll u, ll par){
	if(graph[u].size() == 1){
		return 1;
	}

	ll ans = 0;
	for(ll v : graph[u]){
		if(v != par){
			ans += dfs(v, u);
		}
	}

	if(ans >= 1){
		maxans -= (ans-1);
	}

	return 0;
}

ll dfs2(ll u, ll par){
	if(graph[u].size() == 1){
		return 1;
	}

	ll x = -1;

	for(ll v : graph[u]){
		if(v != par){
			ll y = dfs2(v, u);
			if(!same){
				return 0;
			}
			else if(x == -1){
				x = y;
			}
			else if(y != x){
				// cout << "FALSE: " << u << endl;
				same = false;
				return 0;
			}
		}
	}

	return 1^x;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;

	ll u, v;
	for(ll i = 0; i < n-1; i++){
		cin >> u >> v;
		graph[u].pb(v);
		graph[v].pb(u);
	}

	ll root = 1;
	while(graph[root].size() == 1){
		root++;
	}

	maxans = n-1;
	dfs(root, -1);

	same = true;
	// cout << "ROOT: " << root << endl;
	dfs2(root, -1);

	if(same){
		cout << "1 " << maxans << endl;
	}
	else{
		cout << "3 " << maxans << endl;
	}
}