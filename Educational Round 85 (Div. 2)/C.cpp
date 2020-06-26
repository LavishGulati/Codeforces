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
		ll n;
		cin >> n;

		pll *a = new pll[n];

		ll minEl = LLONG_MAX;

		for(ll i = 0; i < n; i++){
			cin >> a[i].f >> a[i].s;
			minEl = min(minEl, min(a[i].f, a[i].s));
		}

		// vector<ll> expa, expb;
		ll sum = 0;
		for(int i = 0; i < n; i++){
			if(a[i].f > a[(i-1+n)%n].s){
				sum += a[i].f;
				sum -= a[(i-1+n)%n].s;
			}
		}

		cout << ll(sum+minEl) << endl;
	}
}