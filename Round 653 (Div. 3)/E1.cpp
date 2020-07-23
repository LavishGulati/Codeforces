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

	ll n, m;
	cin >> n >> m;

	vector<ll> a;
	vector<ll> b;
	vector<ll> common;

	ll x, u, v;
	for(ll i = 0; i < n; i++){
		cin >> x >> u >> v;
		if(u && v){
			common.pb(x);
		}
		else if(u){
			a.pb(x);
		}
		else if(v){
			b.pb(x);
		}
	}

	sort(all(a));
	sort(all(b));
	sort(all(common));

	ll i = 0, j = 0, k = 0;
	ll ans = 0, ak = 0, bk = 0;
	while(i < a.size() && j < b.size() && k < common.size() && ak < m && bk < m){
		if(common[k] <= a[i]+b[j]){
			ans += common[k];
			k++;
		}
		else{
			ans += a[i]+b[j];
			i++; j++;
		}
		ak++; bk++; 
	}

	while(ak < m && bk < m && k < common.size()){
		ans += common[k];
		k++; ak++; bk++;
	}

	while(ak < m && i < a.size() && k < common.size()){
		if(common[k] <= a[i]){
			ans += common[k];
			k++; bk++;
		}
		else{
			ans += a[i];
			i++;
		}
		ak++;
	}

	while(ak < m && i < a.size()){
		ans += a[i];
		i++; ak++;
	}

	while(ak < m && k < common.size()){
		ans += common[k];
		k++; ak++; bk++;
	}

	while(bk < m && j < b.size() && k < common.size()){
		if(common[k] <= b[j]){
			ans += common[k];
			k++; ak++;
		}
		else{
			ans += b[j];
			j++;
		}
		bk++;
	}

	while(bk < m && j < b.size()){
		ans += b[j];
		j++; bk++;
	}

	while(bk < m && k < common.size()){
		ans += common[k];
		k++; ak++; bk++;
	}

	if(ak < m || bk < m){
		cout << -1 << endl;
	}
	else{
		cout << ans << endl;
	}
}