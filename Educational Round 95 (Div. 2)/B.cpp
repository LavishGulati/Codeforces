#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> tii;
typedef pair<long long, pair<long long, long long>> tll;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;

		ll *a = new ll[n];
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}

		bool *l = new bool[n];
		for(ll i = 0; i < n; i++){
			cin >> l[i];
		}

		vector<ll> v;
		for(ll i = 0; i < n; i++){
			if(!l[i]){
				v.pb(a[i]);
			}
		}

		sort(all(v));
		ll j = 0;
		for(ll i = n-1; i >= 0; i--){
			if(!l[i]){
				a[i] = v[j];
				j++;
			}
		}

		for(ll i = 0; i < n; i++){
			cout << a[i] << " ";
		}
		cout << endl;
	}
}