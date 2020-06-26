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

	ll n, k;
	cin >> n >> k;

	ll *arr = new ll[k+1];
	for(ll i = 0; i <= k; i++){
		arr[i] = 0;
	}

	for(ll i = 0; i < n; i++){
		cin >> x;
		arr[x]++;
	}

	ll *cum = new ll[k+1];
	cum[k] = arr[k];
	for(ll i = k-1; i > 0; i--){
		cum[i] = cum[i+1]+arr[i];
	}

	ll *c = new ll[k+1];
	for(ll i = 1; i <= k; i++){
		cin >> c[i];
	}

	ll maxLines = LLONG_MAX;
	for(ll i = 1; i <= k; i++){
		maxLines = min(maxLines, ll(ceil(cum[i]/double(c[i]))));
	}

	vector< vector<ll> > out(maxLines);
	map<ll, pll> map2;

	cout << maxLines << endl;
	for(ll i = k; i > 1; i--){
		for(ll j = 0; j < maxLines; j++){
			for(ll a = 0; a < c[i] && arr[i] >= 0; a--){
				maxLines.pb()
			}
		}
	}

	for(ll i = 0; i < maxLines; i++){
		cout << out[i].size() << " ";
		for(ll j = 0; j < out[i].size(); j++){
			cout << out[i][j] << " ";
		}
		cout << endl;
	}
}