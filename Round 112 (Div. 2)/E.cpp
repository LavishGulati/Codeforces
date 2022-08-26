#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

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

	int n;
	cin >> n;
	int *a = new int[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int *dp = new int[(1<<22)];
	for(int i = 0; i < (1<<22); i++){
		dp[i] = -1;
	}
	for(int i = 0; i < n; i++){
		dp[a[i]] = a[i];
	}

	for(int i = 0; i < 22; i++){
		for(int mask = 0; mask < (1<<22); mask++){
			if(mask&(1<<i) && dp[mask^(1<<i)] != -1){
				dp[mask] = dp[mask^(1<<i)];
			}
		}
	}

	for(int i = 0; i < n; i++){
		if(dp[((1<<22)-1)^a[i]] != -1){
			cout << dp[((1<<22)-1)^a[i]] << " ";
		}
		else{
			cout << -1 << " ";
		}
	}
	cout << endl;
}