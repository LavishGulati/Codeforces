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

vector<ll> sieve(ll n){ 

    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (ll p=2; p*p<=n; p++){ 
        if (prime[p] == true){ 
            for (int i=p*p; i<=n; i += p){
            	prime[i] = false; 
            }
        } 
    } 
  
    vector<ll> output;

    for (int p=2; p<=n; p++){
    	if (prime[p]){
    		output.pb(p);
    	}
    }

    return output; 
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<ll> primes = sieve(1009);
	// for(int i = 0; i < primes.size(); i++){
	// 	cout << primes[i] << " ";
	// }
	// cout << endl;

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		int *a = new int[n];
		set<int> myset;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			myset.insert(i);
		}
		// cout << myset.size() << endl;

		vector< vector<int> > output;
		for(int i = 0; i < primes.size() && primes[i]*primes[i] <= 1000 && !myset.empty(); i++){
			vector<int> v;
			vector<int> erased;
			for(int j : myset){
				if((a[j]%primes[i]) == 0){
					// cout << a[j] << " " << primes[i] << endl;
					v.pb(j);
					erased.pb(j);
				}
			}
			for(int j : erased){
				myset.erase(j);
			}
			if(v.size() != 0){
				output.pb(v);
			}
		}

		// cout << myset.size() << endl;

		cout << output.size() << endl;

		int *ans = new int[n];
		for(int i = 0; i < output.size(); i++){
			for(int j = 0; j < output[i].size(); j++){
				ans[output[i][j]] = i+1;
			}
		}
		for(int i = 0; i < n; i++){
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}