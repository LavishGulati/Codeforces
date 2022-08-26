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
#define MAX 2000005

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll *dp = new ll[MAX];
	dp[1] = 0;
	dp[2] = 0;
	dp[3] = 4;
	for(ll i = 4; i < MAX; i++){
		if(i%3 == 0){
			dp[i] = (2*dp[i-2]+dp[i-1]+4)%MOD;
		}
		else{
			dp[i] = (2*dp[i-2]+dp[i-1])%MOD;
		}
	}


	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;

		cout << dp[n] << endl;		
	}
}