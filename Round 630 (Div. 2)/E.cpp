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

#define MOD 998244353

ll power(ll x, ll n, ll mod){
	if(n == 0){
		return 1%mod;
	}
	else if(n == 1){
		return x%mod;
	}

	ll y = power(x, n/2, mod);
	if(n%2){
		return (((y*y)%mod)*x)%mod;
	}
	else{
		return (y*y)%mod;
	}
}

ll modInverse(ll x){
	return power(x, MOD-2, MOD);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, m, l, r;
	cin >> n >> m >> l >> r;

	if(r == l){
		cout << 1 << endl;
	}
	else if((n*m)%2){
		cout << ll(power(r-l+1, n*m, MOD)) << endl;
	}
	else{
		ll ans = power(r-l+1, n*m, MOD);
		if(!((r-l)%2)){
			ans = (ans+1+MOD)%MOD;
		}
		ans = (ans*modInverse(2))%MOD;
		cout << ans << endl;
	}
}