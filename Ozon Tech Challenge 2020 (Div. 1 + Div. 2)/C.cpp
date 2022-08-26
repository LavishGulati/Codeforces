#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll n, m;
	cin >> n >> m;

	ll *A = new ll[n];
	for(ll i = 0; i < n; i++){
		cin >> A[i];
		// A[i] %= m;
	}

	if(n > m){
		cout << 0 << "\n";
		return 0;
	}

	ll ans = 1;
	for(ll i = 0; i < n; i++){
		for(ll j = i+1; j < n; j++){
			ans = (ans*abs(A[i]-A[j]))%m;
		}
	}

	cout << ans << endl;
}