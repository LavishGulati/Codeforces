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
		ll n, x;
		cin >> n >> x;

		ll *a = new ll[n];
		ll sum = 0;
		for(ll i = 0; i < n; i++){
			cin >> a[i];
			sum += a[i];
		}

		ll i = 0, j = n-1, add = 0;
		while(i <= j){
			if(sum%x != 0){
				break;
			}
			else if(a[i]%x != 0){
				sum -= a[i];
				i++;
			}
			else if(a[j]%x != 0){
				sum -= a[j];
				j--;
			}
			else{
				sum -= a[i];
				sum -= a[j];
				i++; j--; add++;
			}
		}
		if(j >= i){
			cout << j-i+1+add << endl;
		}
		else{
			cout << -1 << endl;
		}
	}
}