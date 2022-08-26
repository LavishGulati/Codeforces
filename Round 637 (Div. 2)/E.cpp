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

	ll *a = new ll[m];
	for(ll i = 0; i < m; i++){
		cin >> a[i];
	}

	ll g, r;
	cin >> g >> r;

	ll **dp = new ll *[m];
	for(ll i = 0; i < m; i++){
		dp[i] = new ll[g+1];
		for(ll j = 0; j <= g; j++){
			dp[i][j] = LLONG_MAX;
		}
	}

	dp[m-1][0] = 0;
	for(ll j = 1; j <= g; j++){
		for(ll i = 0; i < m; i++){
			if(i-1 >= 0 && j-(a[i]-a[i-1]) >= 0 && dp[i-1][j-(a[i]-a[i-1])] != LLONG_MAX){
				dp[i][j] = min(dp[i][j], dp[i-1][j-(a[i]-a[i-1])]+a[i]-a[i-1]);
			}
			else if(i+1 < m && j-(a[i+1]-a[i]) >= 0 && dp[i+1][j-(a[i+1]-a[i])] != LLONG_MAX){
				dp[i][j] = min(dp[i][j], dp[i+1][j-(a[i+1]-a[i])]+a[i+1]-a[j]);
			}
		}
	}

	// set<ll> **dp = new set<ll> *[m];
	// for(ll i = 0; i < m; i++){
	// 	dp[i] = new set<ll>[g+1];
	// }

	// for(ll i = 0; i < m; i++){
	// 	dp[i][0].insert(i);
	// }

	// for(ll j = 1; j <= g; j++){
	// 	for(ll i = 0; i < m; i++){
	// 		if(i == 0){
	// 			if(j-(a[1]-a[0]) >= 0){
	// 				dp[i][j].insert(dp[i+1][j-(a[1]-a[0])].begin(), dp[i+1][j-(a[1]-a[0])].end());
	// 			}
	// 		}
	// 		else if(i == m-1){
	// 			if(j-(a[m-1]-a[m-2]) >= 0){
	// 				dp[i][j].insert(dp[i-1][j-(a[m-1]-a[m-2])].begin(), dp[i-1][j-(a[m-1]-a[m-2])].end());
	// 			}
	// 		}
	// 		else{
	// 			if(j-(a[i]-a[i-1]) >= 0){
	// 				dp[i][j].insert(dp[i-1][j-(a[i]-a[i-1])].begin(), dp[i-1][j-(a[i]-a[i-1])].end());
	// 			}
	// 			if(j-(a[i+1]-a[i]) >= 0){
	// 				dp[i][j].insert(dp[i+1][j-(a[i+1]-a[i])].begin(), dp[i+1][j-(a[i+1]-a[i])].end());
	// 			}
	// 		}
	// 	}	
	// }

	ll ans = 0;

}