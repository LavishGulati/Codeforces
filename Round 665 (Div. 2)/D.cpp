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

vector<ll> w;
vector<ll> graph[MAX];

ll dfs(ll u, ll n, bool *vis){
	vis[u] = true;
	ll ans = 0;
	for(ll v : graph[u]){
		if(!vis[v]){
			ll cnt = dfs(v, n, vis);
			w.pb((n-cnt)*cnt);
			ans += cnt;
		}
	}

	return ans+1;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;

		for(ll i = 0; i < n; i++){
			graph[i].clear();
		}

		ll u, v;
		for(ll i = 0; i < n-1; i++){
			cin >> u >> v;
			graph[u-1].pb(v-1);
			graph[v-1].pb(u-1);
		}

		ll m;
		cin >> m;

		ll *p = new ll[m];
		for(ll i = 0; i < m; i++){
			cin >> p[i];
		}

		sort(p, p+m);
		w.clear();

		bool *vis = new bool[n];
		for(ll i = 0; i < n; i++){
			vis[i] = false;
		}

		dfs(0, n, vis);
		sort(all(w));

		ll ans = 0, x;
		if(m <= n-1){
			ll j = m-1;
			for(ll i = n-2; i >= 0; i--){
				if(j >= 0){
					x = (p[j]*w[i])%MOD;
				}
				else{
					x = w[i]%MOD;
				}
				ans = (ans+x)%MOD;
				j--;
			}
		}
		else{
			x = 1;
			ll i = m-1, j = n-3;
			ll num = 0;
			while(num < m-n+2){
				x = (x*p[i])%MOD;
				num++; i--;
			}
			ans = (ans+x*w[n-2])%MOD;

			while(i >= 0){
				x = (p[i]*w[j])%MOD;
				ans = (ans+x)%MOD;
				i--; j--;
			}
		}

		cout << ans << endl;
	}
}