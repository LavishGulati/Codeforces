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

	bool ans;
	while(t--){
		int n;
		cin >> n;

		int x;
		cin >> x;

		int y;
		ans = true;
		for(int i = 1; i < n; i++){
			cin >> y;
			if((x%2) != (y%2)){
				ans = false;
			}
		}

		if(ans){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
}