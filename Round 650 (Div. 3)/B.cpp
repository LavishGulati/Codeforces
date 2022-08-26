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
		int n;
		cin >> n;

		int *a = new int[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
		}

		int even = 0, odd = 0;
		for(int i = 0; i < n; i++){
			if(i%2 != a[i]%2){
				if(i%2){
					odd++;
				}
				else{
					even++;
				}
			}
		}

		if(even == odd){
			cout << even << endl;
		}
		else{
			cout << -1 << endl;
		}
	}
}