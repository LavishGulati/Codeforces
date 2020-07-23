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

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		int *a = new int[2*n];
		for(int i = 0; i < 2*n; i++){
			cin >> a[i];
		}

		int *maxcum = new int[2*n];
		maxcum[0] = a[0];
		for(int i = 1; i < 2*n; i++){
			maxcum[i] = max(a[i], maxcum[i-1]);
		}

		vector<int> v;
		int num = 0;
		for(int i = 2*n-1; i >= 0; i--){
			num++;
			if(maxcum[i] == a[i]){
				v.pb(num);
				num = 0;
			}
		}

		sort(all(v));
		int m = v.size();
		if(v[m-1] > n){
			cout << "NO" << endl;
			continue;
		}

		bool **dp = new bool *[m];
		for(int i = 0; i < m; i++){
			dp[i] = new bool[n+1];
			for(int j = 0; j <= n; j++){
				dp[i][j] = false;
			}
		}

		dp[0][0] = true;
		dp[0][v[0]] = true;
		for(int i = 1; i < m; i++){
			for(int j = 0; j <= n; j++){
				dp[i][j] = dp[i-1][j];
			}

			for(int j = v[i]; j <= n; j++){
				if(dp[i-1][j-v[i]]){
					dp[i][j] = true;
				}
			}
		}

		if(dp[m-1][n]){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
}