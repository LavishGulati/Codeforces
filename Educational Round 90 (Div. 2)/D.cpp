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
		ll n;
		cin >> n;

		ll *a = new ll[n];
		for(ll i = 0; i < n; i++){
			cin >> a[i];
		}

		if(n == 1){
			cout << a[0] << endl;
			continue;
		}
		else if(n == 2){
			cout << ll(max(a[0], a[1])) << endl;
			continue;
		}

		ll sum = 0;
		for(ll i = 0; i < n; i+=2){
			sum += a[i];
		}

		ll i = 0, j = 1;
		ll ans = sum;
		ll diff = a[1]-a[0];
		while(i < n && j < n){
			if(diff <= 0){
				diff += a[i];
				diff -= a[i+1];
				i += 2;
				if(i >= j){
					if(j+2 < n){
						diff -= a[j+1];
						diff += a[j+2];
					}
					else{
						diff -= a[j+1];
					}
					j += 2;
				}
			}
			else{
				ans = max(ans, sum+diff);
				if(j+2 < n){
					diff -= a[j+1];
					diff += a[j+2];
				}
				else{
					diff -= a[j+1];
				}
				j += 2;
			}
		}

		i = 1, j = 2;
		diff = a[1]-a[2];
		while(i < n && j < n){
			// cout << i << " " << j << endl;
			if(diff <= 0){
				diff -= a[i];
				diff += a[i+1];
				i += 2;
				if(i >= j){
					if(j+2 < n){
						diff += a[j+1];
						diff -= a[j+2];
					}
					else{
						diff += a[j+1];
					}
					j += 2;
				}
			}
			else{
				ans = max(ans, sum+diff);
				if(j+2 < n){
					diff += a[j+1];
					diff -= a[j+2];
				}
				else{
					diff += a[j+1];
				}
				j += 2;
			}
		}

		cout << ans << endl;
	}
}