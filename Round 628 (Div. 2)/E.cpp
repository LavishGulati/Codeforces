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

#define MAX 1000000
ll lp[MAX+5], dist[MAX+5];
vector<ll> d[MAX+5], v[MAX+5], pr;
vector< vector<ll> > e;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	pr.pb(1);
	for(ll i = 2; i <= MAX; i++){
		if(!lp[i]){
			pr.pb(i);
			for(ll j = i; j <= MAX; j += i){
				lp[j] = i;
			}
		}

		d[i] = d[i/lp[i]];
		auto it = find(d[i].begin(), d[i].end(), lp[i]);
		if(it != d[i].end()){
			d[i].erase(it);
		}
		else{
			d[i].pb(lp[i]);
		}
	}

	ll n, ans = MAX;
	cin >> n;
	for(ll i = 0; i < n; i++){
		ll a;
		cin >> a;
		if(d[a].empty()){
			cout << 1 << endl;
			return 0;
		}

		if(d[a].size() == 1){
			d[a].pb(1);
		}
		e.pb({d[a][0], d[a][1]});
		v[d[a][0]].pb(i);
		v[d[a][1]].pb(i);
	}

	for(ll i : pr){
		if(i*i > MAX){
			break;
		}

		for(ll j : pr){
			dist[j] = 0;
		}
		queue<pll> q;
		for(ll j : v[i]){
			q.push(mp(j, (e[j][0]==i)));
			dist[e[j][0]^e[j][1]^i] = 1;
		}

		while(!q.empty()){
			auto p = q.front();
			q.pop();
			ll node = e[p.f][p.s];
			for(ll u : v[node]){
				if(u != p.f){
					pll np(u, (e[u][0]==node));
					ll nnode = e[np.f][np.s];
					if(!dist[nnode] && nnode != i){
						q.push(np);
						dist[nnode] = dist[node]+1;
					}
					else{
						ans = min(ans, dist[node]+dist[nnode]+1);
					}
				}
			}
		}
	}

	if(ans == MAX){
		ans = -1;
	}
	cout << ans << endl;
}