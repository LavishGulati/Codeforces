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

	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;

		int *a = new int[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}

		int *cum = new int[n];
		cum[0] = cum[n-1] = 0;
		for(int i = 1; i < n-1; i++){
			if(a[i] > a[i-1] && a[i] > a[i+1]){
				cum[i] = 1;
			}
			else{
				cum[i] = 0;
			}
		}

		for(int i = 1; i < n; i++){
			cum[i] += cum[i-1];
		}

		int ans = 0, id = 0;
		for(int i = 0; i <= n-k; i++){
			if(cum[i+k-2]-cum[i] > ans){
				ans = cum[i+k-2]-cum[i];
				id = i;
			}
		}
		cout << ans+1 << " " << id+1 << endl;
	}
}