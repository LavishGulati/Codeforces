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

		vector<int> *choice = new vector<int>[n];
		int m, x;
		for(int i = 0; i < n; i++){
			cin >> m;
			for(int j = 0; j < m; j++){
				cin >> x;
				choice[i].pb(x);
			}
		}

		set<int> myset;
		for(int i = 0; i < n; i++){
			myset.insert(i+1);
		}

		bool filled[n];
		for(int i = 0; i < n; i++){
			filled[i] = false;
		}

		bool ans = true;
		int id = -1;

		for(int i = 0; i < n; i++){
			for(int j = 0; j < choice[i].size(); j++){
				auto it = myset.find(choice[i][j]);
				if(it != myset.end()){
					myset.erase(it);
					filled[i] = true;
					break;
				}
			}
			ans = ans & filled[i];
			if(!filled[i]){
				id = i;
			}
		}

		// for(auto it = myset.begin(); it != myset.end(); it++){
		// 	cout << *it << " ";
		// }
		// cout << endl;

		if(ans){
			cout << "OPTIMAL" << endl;
		}
		else{
			auto it = myset.begin();
			cout << "IMPROVE" << endl;
			cout << id+1 << " " << *it << endl;
		}
	}
}