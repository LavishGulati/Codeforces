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

ll binarySearch(vector<pll> &v, ll x){
	ll si = 0, ei = v.size()-1, mid;
	ans = 0;
	while(si <= ei){
		mid = (si+ei)/2;
		if(v[mid] <= x){
			ans = mid;
			si = mid+1;
		}
		else{
			ei = mid-1;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, p;
	cin >> n >> p;
	
	ll *arr = new ll[n];
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(arr, arr+n);

	vector< vector<pll> > a;
	vector<pll> help;
	for(ll i = 0; i < n; i++){
		ll x = a[i];
		if(a.size() == 0){
			help.clear();
			help.pb(mp(x, i));
			a.pb(help);
		}
		else{
			if(x == a.back().back()+1){
				a.back().pb(mp(x, i));
			}
			else{
				help.clear();
				help.pb(mp(x, i));
				a.pb(help);
			}
		}
	}



	// for(ll i = 0; i < a.size(); i++){
	// 	for(ll j = 0; j < a[i].size(); j++){
	// 		cout << a[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	vector<pll> markers;
	for(ll i = 0; i < a.size(); i++){
		markers.pb(a[i][0]);
	}

	vector<ll> output;
	for(ll k = 0; k < markers.size(); k++){
		pll x = markers[k];
		ll i = binarySearch(markers, x.f-x.j);
		ll j = binarySearch(a[i], x.f-x.j);

		if(j >= p){
			continue;
		}

		ll m = a[k].size();
		if(m+1-j >= p){
			continue;
		}


	}
}