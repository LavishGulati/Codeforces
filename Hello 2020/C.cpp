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

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, m;
	cin >> n >> m;

	ll fact[n+1];
	fact[0] = 1;
	for(ll i = 1; i <= n; i++){
		fact[i] = (i*fact[i-1])%m;
	}

	ll answer = 0, x;
	for(ll i = 0; i < n; i++){
		x = ((n-i)*(n-i))%m;
		x = (x*fact[i+1])%m;
		x = (x*fact[n-i-1])%m;
		// cout << i << " " << x << endl;
		answer = (answer+x)%m;
	}

	cout << answer << endl;
}