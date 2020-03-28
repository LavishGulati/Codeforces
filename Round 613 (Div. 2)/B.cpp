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

ll maxSubArraySum(ll *a, ll size) 
{ 
    ll max_so_far = INT_MIN, max_ending_here = 0; 
  
    for (ll i = 0; i < size; i++) 
    { 
        max_ending_here = max_ending_here + a[i]; 
        if (max_so_far < max_ending_here) 
            max_so_far = max_ending_here; 
  
        if (max_ending_here < 0) 
            max_ending_here = 0; 
    } 
    return max_so_far; 
} 

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	ll t;
	cin >> t;
	while(t--){
		ll n;
		cin >> n;

		ll *input = new ll[n];
		ll sum = 0;
		for(ll i = 0; i < n; i++){
			cin >> input[i];
			sum += input[i];
		}

		ll maxSumR = maxSubArraySum(input+1, n-1);
		ll maxSumL = maxSubArraySum(input, n-1);
		if(sum > max(maxSumR, maxSumL)){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
}