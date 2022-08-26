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

#define MOD 998244353

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, k;
	cin >> n >> k;

	ll *p = new ll[n];
	for(ll i = 0; i < n; i++){
		cin >> p[i];
	}

	ll maxval = (n*(n+1))/2;
	maxval -= ((n-k)*(n-k+1))/2;

	cout << maxval << " ";

	ll answer = 1, i;
	for(i = 0; i < n; i++){
		if(p[i] > n-k){
			break;
		}
	}

	i++;
	ll count = 0;
	for(; i < n; i++){
		if(p[i] > n-k){
			answer = (answer*(count+1))%MOD;
			count = 0;
		}
		else{
			count++;
		}
	}

	cout << answer << "\n";
}