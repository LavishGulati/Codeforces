#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define MAX 100009

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n;
	cin >> n;
	vector<ll> arr[n];

	ll m, x;
	for(ll i = 0; i < n; i++){
		cin >> m;
		for(ll j = 0; j < m; j++){
			cin >> x;
			arr[i].pb(x);
		}
	}

	ll minArr[n];
	ll maxArr[n];

	vector<ll> isAscent;
	vector<ll> notAscent;

	for(int i = 0; i < n; i++){
		m = arr[i].size();
		minArr[i] = arr[i][0];
		maxArr[i] = arr[i][0];
		for(int j = 0; j < m; j++){
			minArr[i] = min(minArr[i], arr[i][j]);
			maxArr[i] = max(maxArr[i], arr[i][j]);
		}
	}

	for(ll i = 0; i < n; i++){
		m = arr[i].size();
		ll maxEl = arr[i][m-1];
		ll j;
		for(j = m-2; j >= 0; j--){
			if(arr[i][j] < maxEl){
				isAscent.pb(i);
				break;
			}
			maxEl = max(maxEl, arr[i][j]);
		}
		if(j < 0){
			notAscent.pb(i);
		}
	}

	ll answer = 2*(n-1)*isAscent.size() + isAscent.size() - (isAscent.size()*(isAscent.size()-1));

	// cout << answer << endl;

	vector<ll> minV;
	vector<ll> maxV;
	for(ll id : notAscent){
		minV.pb(minArr[id]);
		maxV.pb(maxArr[id]);
	}

	sort(all(minV));
	sort(all(maxV));

	ll i = 0;
	ll j = 0;
	while(i < minV.size()){
		while(j < maxV.size() && minV[i] >= maxV[j]){
			j++;
		}

		if(j >= maxV.size()){
			break;
		}

		answer += maxV.size()-j;
		i++;
	}

	cout << answer << endl;
}