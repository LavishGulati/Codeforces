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

#define MAX 1000005

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

ll fact[MAX], ifact[MAX];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	
	fact[0] = 1;
	for(ll i = 1; i < MAX; i++){
		fact[i] = (i*fact[i-1])%MOD;
	}

	for(ll i = 0; i < MAX; i++){
		ifact[i] = modInverse(fact[i]);
	}

	ll d;
	cin >> d;

	ll x = d;
	vector<ll> primes;
	if(x%2 == 0){
		primes.pb(2);
		while(x%2 == 0){
			x /= 2;
		}
	}

	for(ll i = 3; i*i <= d; i += 2){
		if(x%i == 0){
			primes.pb(i);
			while(x%i == 0){
				x /= i;
			}
		}
	}
	if(x >= 2){
		primes.pb(x);
	}

	ll q;
	cin >> q;
	ll u, v;
	while(q--){
		cin >> u >> v;

		if(u > v){
			swap(u, v);
		}

		ll gcd = __gcd(u, v);
		ll iter = u/gcd;
		ll ans = 1, sum = 0;

		for(ll p : primes){
			ll cnt = 0;
			while(iter%p == 0){
				iter /= p;
				cnt++;
			}
			ans = (ans*ifact[cnt])%MOD;
			sum += cnt;
			// cout << p << " " << cnt << endl;
			if(iter == 1){
				break;
			}
		}
		// cout << sum << endl;
		ans = (ans*fact[sum])%MOD;

		sum = 0;
		iter = v / gcd;
		for(ll p : primes){
			ll cnt = 0;
			while(iter%p == 0){
				iter /= p;
				cnt++;
			}
			ans = (ans*ifact[cnt])%MOD;
			sum += cnt;
			// cout << p << " " << cnt << endl;
			if(iter == 1){
				break;
			}
		}
		// cout << sum << endl;
		ans = (ans*fact[sum])%MOD;
		cout << ans << endl;
	}
}