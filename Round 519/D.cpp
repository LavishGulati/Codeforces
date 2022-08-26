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

ll a[10][MAX], id[10][MAX], len[10][MAX];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, m;
	cin >> n >> m;

	for(ll i = 0; i < m; i++){
		for(ll j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}

	umap<ll, ll> mp;
	for(ll i = 0; i < n; i++){
		mp[a[0][i]] = i;
	}

	for(ll i = 1; i < m; i++){
		for(ll j = 0; j < n; j++){
			a[i][j] = mp[a[i][j]];
			id[i][a[i][j]] = j;
		}
	}

	for(ll i = 1; i < m; i++){
		len[i][n-1] = 1;
		for(ll j = n-2; j >= 0; j--){
			if(a[i][j]+1 == a[i][j+1]){
				len[i][j] = len[i][j+1]+1;
			}
			else{
				len[i][j] = 1;
			}
		}
	}

	// for(ll i = 1; i < m; i++){
	// 	for(ll j = 0; j < n; j++){
	// 		cout << len[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	ll ans = 0, cur = 0, k;
	while(cur < n){
		k = n-cur;
		for(ll i = 1; i < m; i++){
			// cout << id[i][cur] << " ";
			k = min(k, len[i][id[i][cur]]);
		}
		// cout << cur << " " << k << endl;
		// if(!k){
		// 	break;
		// }
		ans += (k*(k+1))/2;
		cur += k;
	}
	cout << ans << endl;
}