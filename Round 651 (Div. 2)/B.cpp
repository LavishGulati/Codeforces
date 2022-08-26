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

		vector<pii> even;
		vector<pii> odd;
		int x;
		for(int i = 0; i < 2*n; i++){
			cin >> x;
			if(x%2){
				odd.pb(mp(x, i));
			}
			else{
				even.pb(mp(x, i));
			}
		}

		int j = 0, k = 0;
		for(int i = 0; i < n-1; i++){
			if(j+1 < even.size()){
				cout << even[j].s+1 << " " << even[j+1].s+1 << endl;
				j += 2;
			}
			else{
				cout << odd[k].s+1 << " " << odd[k+1].s+1 << endl;
				k += 2;
			}
		}
	}
}