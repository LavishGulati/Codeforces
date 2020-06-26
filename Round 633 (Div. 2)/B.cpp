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

		sort(a, a+n);

		if(n%2){
			ll i = n/2;
			ll j = n/2 + 1;
			for(ll k = 0; k < n; k++){
				if(k%2){
					cout << a[j] << " ";
					j++;
				}
				else{
					cout << a[i] << " ";
					i--;
				}
			}
		}
		else{
			ll i = n/2 - 1;
			ll j = n/2;
			for(ll k = 0; k < n; k++){
				if(k%2){
					cout << a[j] << " ";
					j++;
				}
				else{
					cout << a[i] << " ";
					i--;
				}
			}
		}
		cout << endl;
	}
}