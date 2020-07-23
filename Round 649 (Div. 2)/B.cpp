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

		ll *p = new ll[n];
		for(ll i = 0; i < n; i++){
			cin >> p[i];
		}

		vector<ll> output;
		output.pb(p[0]);

		bool up;
		if(p[1] > p[0]){
			up = true;
		}
		else{
			up = false;
		}

		for(ll i = 1; i < n; i++){
			if(up && p[i] > p[i-1]){
				// nothing
			}
			else if(up && p[i] < p[i-1]){
				up = false;
				output.pb(p[i-1]);
			}
			else if(!up && p[i] < p[i-1]){
				// nothing
			}
			else{
				up = true;
				output.pb(p[i-1]);
			}
		}
		output.pb(p[n-1]);

		cout << output.size() << endl;
		for(ll i = 0; i < output.size(); i++){
			cout << output[i] << " ";
		}
		cout << endl;
	}
}