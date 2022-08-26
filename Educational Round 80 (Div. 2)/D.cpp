#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define MOD 1000000007

#define MAX 1000000000

ll input[300009][10];

ll id;

bool compare(ll i, ll j){
	return input[i][id] < input[j][id];
}

ll binary_search(ll *arr, ll x, ll n){
	ll si = 0;
	ll ei = n-1;
	ll ans = -1;
	while(si <= ei){
		ll mid = (si+ei)/2;
		if(input[arr[mid]][id] >= x){
			ans = mid;
			ei = mid-1;
		}
		else{
			si = mid+1;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, m;
	cin >> n >> m;

	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < m; j++){
			cin >> input[i][j];
		}
	}

	ll **sorted = new ll *[m];
	for(ll i = 0; i < m; i++){
		sorted[i] = new ll[n];
		for(ll j = 0; j < n; j++){
			sorted[i][j] = j;
		}
	}

	for(ll i = 0; i < m; i++){
		id = i;
		sort(sorted[i], sorted[i]+n, compare);
	}

	// for(ll i = 0; i < m; i++){
	// 	for(ll j = 0; j < n; j++){
	// 		cout << sorted[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	ll si = 0;
	ll ei = MAX;

	ll ans = -1;
	ll x, y;

	bool possible;

	while(si <= ei){
		ll mid = (si+ei)/2;

		ll st[n];
		for(ll i = 0; i < n; i++){
			st[i] = 0;
		}

		possible = true;

		for(ll i = 0; i < m; i++){
			id = i;

			ll j = binary_search(sorted[i], mid, n);
			// cout << j << endl;
			if(j == -1){
				possible = false;
				// st[i].clear();
				break;
			}
			else{
				for(ll k = j; k < n; k++){
					// st[i].insert(sorted[i][k]);
					st[sorted[i][k]] += pow(2, i);
				}
				// set<ll> temp;
				// for(ll k = j; k < m; k++){
				// 	temp.insert(sorted[i][k]);
				// }
				// set<ll> final;
				// set_intersection(st.begin(), st.end(), temp.begin(), temp.end(), std::inserter(final,final.begin()));
				// st.clear();
				// st.insert(final.begin(), final.end());
			}
		}

		cout << mid << ": ";
		for(ll i = 0; i < n; i++){
			cout << st[i] << " ";
		}
		cout << endl;

		ll b = pow(2, m)-1;

		if(!possible){
			ei = mid-1;
			continue;
		}

		map<ll, ll> mp;
		for(ll i = 0; i < n; i++){
			mp[st[i]] = i;
		}

		possible = false;
		for(auto a : mp){
			cout << a.first << " " << b << " " << (a.first^b) << endl;
			if(mp.find(a.first^b) != mp.end()){
				possible = true;
				x = a.second;
				y = mp[a.first^b];
				break;
			}
		}

		
		if(!possible){
			ei = mid-1;
		}
		else{
			ans = mid;
			si = si+1;
		}
		// if(st.size() >= 1){
		// 	ans = mid;
		// 	x = st.begin();
		// 	y = st.begin();
		// 	si = mid+1;
		// }
		// else{
		// 	ei = mid-1;
		// }
	}

	cout << ans << endl;
	// cout << x << " " << y << endl;
}