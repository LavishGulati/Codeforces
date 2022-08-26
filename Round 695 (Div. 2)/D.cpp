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

	ll n, k, q;
	cin >> n >> k >> q;

	ll *a = new ll[n];
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}

	ll **start = new ll *[n];
	for(ll i = 0; i < n; i++){
		start[i] = new ll[k+1];
		for(ll j = 0; j <= k; j++){
			start[i][j] = 0;
		}
	}
	for(ll i = 0; i < n; i++){
		start[i][0] = 1;
	}

	for(ll j = 1; j <= k; j++){
		for(ll i = 0; i < n; i++){
			if(i+1 < n){
				start[i][j] += start[i+1][j-1];
			}
			start[i][j] = (start[i][j]+MOD)%MOD;
			if(i-1 >= 0){
				start[i][j] += start[i-1][j-1];
			}
			start[i][j] = (start[i][j]+MOD)%MOD;

		}
	}

	ll **end = start;

	ll *dp = new ll[n];
	for(ll i = 0; i < n; i++){
		dp[i] = 0;
	}

	for(ll i = 0; i < n; i++){
		if(i-1 >= 0){
			dp[i] += end[i-1][k-1]+start[i-1][k-1];
		}
		dp[i] = (dp[i]+MOD)%MOD;
		if(i+1 < n){
			dp[i] += end[i+1][k-1]+start[i+1][k-1];
		}
		dp[i] = (dp[i]+MOD)%MOD;

		for(ll j = 0; j <= k-2; j++){
			if(i-1 >= 0){
				dp[i] += end[i-1][j]*start[i-1][k-2-j];
			}
			dp[i] = (dp[i]+MOD)%MOD;
			if(i+1 < n){
				dp[i] += end[i+1][j]*start[i+1][k-2-j];
			}
			dp[i] = (dp[i]+MOD)%MOD;
			if(i-1 >= 0 && i+1 < n){
				dp[i] += end[i+1][j]*start[i-1][k-2-j];
				dp[i] = (dp[i]+MOD)%MOD;
				dp[i] += end[i-1][j]*start[i+1][k-2-j];
			}
			dp[i] = (dp[i]+MOD)%MOD;
		}
	}

	ll total = 0;
	for(ll i = 0; i < n; i++){
		total += dp[i]*a[i];
		total = (total+MOD)%MOD;
	}

	ll id, x;
	for(ll i = 0; i < q; i++){
		cin >> id >> x;
		id--;
		total = (total-((dp[id]*a[id])%MOD)+MOD)%MOD;
		total = (total+dp[id]*x)%MOD;
		cout << total << endl;
		a[id] = x;
	}
}