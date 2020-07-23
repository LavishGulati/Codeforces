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

	ll n, p;
	cin >> n >> p;

	ll *a = new ll[n];
	ll start = -1, end = -1;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a+n);
	start = a[0];
	end = a[n-1];

	vector<ll> output;
	for(ll i = start; i < end; i++){
		ll j = 0, cnt = 0, taken = 0;
		bool ans = true;
		while(j < n){
			ll cnt2 = cnt;

			while(j < n && i+cnt2 >= a[j]){
				j++;
			}

			if((j-taken)%p == 0){
				ans = false;
				break;
			}
			else{
				taken++;
				cnt2++;
			}

			if(cnt2 == cnt){
				break;
			}

			cnt = cnt2;
		}

		if(j < n){
			continue;
		}
		if(n-taken >= p){
			continue;
		}

		if(ans){
			output.pb(i);
		}
	}

	cout << output.size() << endl;
	for(ll x : output){
		cout << x << " ";
	}
	cout << endl;
}