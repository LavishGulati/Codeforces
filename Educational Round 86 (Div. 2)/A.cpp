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
		ll x, y, a, b;
		cin >> x >> y >> a >> b;

		ll ans = 0, z;
		if(x < 0 && y < 0){
			z = min(abs(x), abs(y));
			if(b < 2*a){
				ans += z*b;
			}
			else{
				ans += 2*a*z;
			}
			x += z;
			y += z;
		}

		if(x > 0 && y > 0){
			z = min(x, y);
			if(b < 2*a){
				ans += z*b;
			}
			else{
				ans += 2*a*z;
			}
			x -= z;
			y -= z;
		}

		ans += abs(x)*a;
		ans += abs(y)*a;
		cout << ans << endl;
	}
}