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

map< int, vector<int> > mymap;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	bool ans;

	while(t--){
		mymap.clear();
		ans = false;

		int n;
		cin >> n;

		int *a = new int[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
			mymap[a[i]].pb(i);
		}

		for(int i = 0; i < n; i++){
			for(int j : mymap[a[i]]){
				if(j > i+1){
					ans = true;
					break;
				}
			}
			if(ans){
				break;
			}
		}

		if(ans){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
}