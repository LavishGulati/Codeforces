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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	bool ans;
	while(t--){
		ll n, d;
		ans = false;
		cin >> n >> d;

		ll x = floor(sqrt(d)-1);
		ll y = ceil(sqrt(d)-1);
		for(ll i = x; i >= max(0LL, ll(x-sqrt(d))); i--){
			if(i + double(d)/double(i+1) <= n){
				ans = true;
				break;
			}
		}

		for(ll i = y; i <= min(double(n), y+sqrt(d)); i++){
			if(i + double(d)/double(i+1) <= n){
				ans = true;
				break;
			}
		}

		if(ans){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
		// ll si = 0;
		// ll ei = n;
		// while(si <= ei){
		// 	ll mid = (si+ei)/2;

		// }
	}
}