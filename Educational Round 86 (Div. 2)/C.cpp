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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll a, b, q;
		cin >> a >> b >> q;

		if(a > b){
			swap(a, b);
		}

		ll lcm = (a*b)/__gcd(a, b);

		ll l, r;
		while(q--){
			cin >> l >> r;

			if(a == b || lcm == a || lcm == b){
				cout << 0 << " ";
			}
			else{
				ll ans = r-l+1;

				ll li, lj;
				if(l%li == 0){
					li = l;
				}
				else{
					li = (l/lcm)*lcm + lcm;
				}

				lj = (li-lcm+b-1);
				if(lj >= l){
					ans -= min(lj, r)-l+1;
				}

				ll ri = r - r%lcm;
				if(ri < li){
					ri += lcm;
				}

				// cout << li << " " << lj << " " << ri << " ";

				ans -= ((ri-li)/lcm)*b;

				if(ri <= r){
					ans -= min(r-ri+1, b);
				}
				
				cout << ans << " ";
				// cout << ans << endl;
			}
		}
		cout << endl;
	}
}