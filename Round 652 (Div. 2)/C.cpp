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

	ll t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;

		ll *a = new ll[n];
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}

		ll *w = new ll[k];
		for(ll i = 0; i < k; i++){
			cin >> w[i];
		}

		sort(a, a+n);
		sort(w, w+k);

		ll ones = 0;
		for(ll i = 0; i < k; i++){
			if(w[i] == 1){
				ones++;
			}
			else{
				break;
			}
		}

		ll sum = 0;
		ll i;
		for(i = n-1; i >= max(0LL, n-ones); i--){
			sum += 2*a[i];
		}

		ll j = 0;
		for(ll r = k-1; r >= ones; r--){
			sum += a[j];
			sum += a[i];
			i--;
			while(w[r]-1 > 0){
				j++;
				w[r]--;
			}
		}
		cout << sum << endl;
	}
}