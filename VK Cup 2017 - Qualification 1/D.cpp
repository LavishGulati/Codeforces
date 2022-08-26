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

#define MAX 10005
int freq[MAX];

int diff(int x, int y){
	int cnt = 0;
	while(x > 0 || y > 0){
		if((x&1) != (y&1)){
			cnt++;
		}
		x >>= 1;
		y >>= 1;
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	for(int i = 0; i < MAX; i++){
		freq[i] = 0;
	}

	int x;
	for(int i = 0; i < n; i++){
		cin >> x;
		freq[x]++;
	}

	ll ans = 0;
	if(k == 0){
		for(ll i = 0; i < MAX; i++){
			ans += (ll(freq[i])*(ll(freq[i]-1)))/2;
		}
	}
	else{
		for(int i = 0; i < MAX; i++){
			for(int j = i+1; j < MAX; j++){
				if(diff(i, j) == k){
					ans += ll(freq[i])*ll(freq[j]);
				}
			}
		}
	}
	cout << ans << endl;
}