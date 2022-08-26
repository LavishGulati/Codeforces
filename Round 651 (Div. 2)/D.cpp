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

bool possible(ll *a, ll x, ll n, ll k){
	ll cnt = 0;
	for(ll i = 0; i < n; i++){
		if(cnt%2){
			cnt++;
		}
		else if(a[i] <= x){
			cnt++;
		}
	}
	if(cnt >= k){
		return true;
	}

	cnt = 0;
	for(ll i = 0; i < n; i++){
		if(!(cnt%2)){
			cnt++;
		}
		else if(a[i] <= x){
			cnt++;
		}
	}
	if(cnt >= k){
		return true;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, k;
	cin >> n >> k;

	ll *a = new ll[n];
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}

	vector<ll> help;
	for(ll i = 0; i < n; i++){
		help.pb(a[i]);
	}

	sort(all(help));

	ll si = 0, ei = n-1, mid, ans = -1;
	while(si <= ei){
		mid = (si+ei)/2;
		if(possible(a, help[mid], n, k)){
			ans = help[mid];
			ei = mid-1;
		}
		else{
			si = mid+1;
		}
	}
	cout << ans << endl;
}