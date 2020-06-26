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

		map<int, int> mymap;
		bool ans = true;

		int *a = new int[n];
		for(int i = 0; i < n; i++){
			cin >> a[i];
			mymap[a[i]] = i;
		}

		bool *seen = new bool[n];
		for(int i = 0; i < n; i++){
			seen[i] = false;
		}

		int num = 1;
		while(num <= n){
			int id = mymap[num];
			num++;
			seen[id] = true;
			for(int i = id+1; i < n && !seen[i]; i++){
				if(a[i] != num){
					ans = false;
					break;
				}
				seen[i] = true;
				num++;
			}
			if(!ans){
				break;
			}
		}

		if(ans){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
}