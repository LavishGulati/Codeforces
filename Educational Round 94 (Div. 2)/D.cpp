#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> tii;
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

		ll *a = new ll[n];
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}

		ll *left = new ll[n+1];
		ll *right = new ll[n+1];
		for(ll i = 0; i <= n; i++){
			left[i] = 0;
		}

		ll ans = 0;
		for(ll j = 0; j < n; j++){
			for(ll i = 0; i <= n; i++){
				right[i] = 0;
			}

			for(ll k = n-1; k > j; k--){
				ans += left[a[k]]*right[a[j]];
				right[a[k]]++;
			}
			left[a[j]]++;
		}

		cout << ans << endl;
	}
}