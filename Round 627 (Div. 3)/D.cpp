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

ll binary_search(ll *a, ll x, ll n){
	ll si = 0;
	ll ei = n-1;
	ll ans = 0;
	while(si <= ei){
		ll mid = (si+ei)/2;
		if(a[mid] < x){
			ans = mid+1;
			si = mid+1;
		}
		else{
			ei = mid-1;
		}
	}
	// cout << ans << endl;
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;

	pll *a = new pll[n];
	for(ll i = 0; i < n; i++){
		cin >> a[i].f;
	}
	for(ll i = 0; i < n; i++){
		cin >> a[i].s;
	}

	ll *help = new ll[n];
	for(ll i = 0; i < n; i++){
		help[i] = a[i].s-a[i].f;
	}

	sort(help, help+n);

	ll ans = 0;
	for(ll i = 0; i < n; i++){
		// cout << i << " ";
		ans += binary_search(help, a[i].f-a[i].s, n);
		if(a[i].f-a[i].s > a[i].s-a[i].f){
			ans--;
		}
	}
	cout << ans/2 << endl;
}