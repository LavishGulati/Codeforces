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

	int n, h, l, r;
	cin >> n >> h >> l >> r;

	int *a = new int[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	int **dp = new int *[n];
	for(int i = 0; i < n; i++){
		dp[i] = new int[h];
		for(int j = 0; j < h; j++){
			dp[i][j] = 0;
		}
	}

	if(a[0] >= l && a[0] <= r){
		dp[0][a[0]] = 1;
	}
	if((a[0]-1) >= l && (a[0]-1) <= r){
		dp[0][a[0]-1] = 1;
	}

	vector<int> help;
	set<int> help2;
	help.pb(a[0]);
	help.pb(a[0]-1);

	for(int i = 1; i < n; i++){
		help2.clear();
		for(int j : help){
			help2.insert((j+a[i])%h);
			help2.insert((j+a[i]-1)%h);

			if((j+a[i])%h >= l && (j+a[i])%h <= r){
				dp[i][(j+a[i])%h] = max(dp[i][(j+a[i])%h], dp[i-1][j]+1);
			}
			else{
				dp[i][(j+a[i])%h] = max(dp[i][(j+a[i])%h], dp[i-1][j]);
			}

			if((j+a[i]-1)%h >= l && (j+a[i]-1)%h <= r){
				dp[i][(j+a[i]-1)%h] = max(dp[i][(j+a[i]-1)%h], dp[i-1][j]+1);
			}
			else{
				dp[i][(j+a[i]-1)%h] = max(dp[i][(j+a[i]-1)%h], dp[i-1][j]);
			}
		}
		help.clear();
		for(int j : help2){
			help.pb(j);
		}
	}

	// for(int i = 0; i < n; i++){
	// 	for(int j = 0; j < h; j++){
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	int ans = 0;
	for(int j : help){
		ans = max(ans, dp[n-1][j]);
	}
	cout << ans << endl;
}