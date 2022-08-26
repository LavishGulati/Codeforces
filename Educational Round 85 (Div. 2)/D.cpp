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

ll binary_search(ll x, ll n){
	ll si = 0;
	ll ei = n-1;

	ll ans = -1;
	while(si <= ei){
		ll mid = (si+ei)/2;

		if(x-(2*mid*n-mid*(mid+1)) > 0){
			ans = mid;
			si = mid+1;
		}
		else{
			ei = mid-1;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n, l, r;
		cin >> n >> l >> r;

		ll i = binary_search(l, n);
		ll j = binary_search(r, n);

		l -= 2*i*n-i*(i+1);
		r -= 2*j*n-j*(j+1);

		// cout << i << " " << j << " " << l << " " << r << endl;

		if(i < n-1){
			if(i == j){
				for(ll m = l; m <= r; m++){
					if(m%2){
						cout << 1+i << " ";
					}
					else{
						cout << m/2 + i +1 << " ";
					}
				}
			}
			else{
				for(ll m = l; m <= 2*(n-i-1); m++){
					if(m%2){
						cout << 1+i << " ";
					}
					else{
						cout << m/2 + i + 1 << " ";
					}
				}

				for(ll k = i+1; k < j; k++){
					for(ll m = 1; m <= 2*(n-k-1); m++){
						if(m%2){
							cout << 1+k << " ";
						}
						else{
							cout << m/2 + k +1 << " ";
						}
					}
				}

				if(j < n-1){
					for(ll m = 1; m <= r; m++){
						if(m%2){
							cout << 1+j << " ";
						}
						else{
							cout << m/2 + j +1 << " ";
						}
					}
				}
				else{
					cout << 1 << " ";
				}
			}

			cout << endl;
			
		}
		else{
			cout << 1 << endl;
		}
	}
}