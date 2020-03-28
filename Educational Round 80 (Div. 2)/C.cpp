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

#define MAX 2000

ll power(ll x, ll n){
	if(n == 0){
		return 1;
	}
	else if(n == 1){
		return x%MOD;
	}

	ll y = power(x, n/2);
	if(n%2){
		ll ans = (y*y)%MOD;
		return (ans*x)%MOD;
	}
	else{
		return (y*y)%MOD;
	}
}

ll modInverse(ll x){
	return power(x, MOD-2);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, m;
	cin >> n >> m;

	ll fact[MAX];
	fact[0] = 1;
	for(ll i = 1; i < MAX; i++){
		fact[i] = (i*fact[i-1])%MOD;
	}

	ll helper[n+1];
	for(ll i = 1; i <= n; i++){
		helper[i] = (fact[m+i-1]*modInverse(fact[i-1]))%MOD;
		helper[i] = (helper[i]*modInverse(fact[m]))%MOD;
	}

	ll helper2[n+1];
	for(ll i = 1; i <= n; i++){
		helper2[i] = (fact[m+n-i-1]*modInverse(fact[n-i]))%MOD;
		helper2[i] = (helper2[i]*modInverse(fact[m-1]))%MOD;
	}

	// for(ll i = 0; i < n; i++){
	// 	cout << helper[i] << " ";
	// }
	// cout << endl;

	ll ans = 0;
	for(ll i = 1; i <= n; i++){
		ll y = (helper[i]*helper2[i])%MOD;
		ans = (ans+y)%MOD;
	}

	cout << ans << endl;
}