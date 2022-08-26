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

		ll i = 0, j = 0, x;
		while(i < n && j < n){
			while(i < n && a[i] <= 0){
				i++;
			}
			j = max(j, i+1);
			while(j < n && a[j] >= 0){
				j++;
			}

			if(i < n && j < n){
				x = min(abs(a[i]), abs(a[j]));
				a[i] -= x;
				a[j] += x;
			}
		}

		ll ans = 0;
		for(ll i = 0; i < n; i++){
			ans += abs(a[i]);
		}
		cout << ans/2 << endl;
	}
}