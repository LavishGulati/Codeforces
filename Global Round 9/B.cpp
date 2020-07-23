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

int check(int **grid, int i, int j, int n, int m){
	int pos = 0;
	if(i+1 < n){
		pos++;
	}
	if(i-1 >= 0){
		pos++;
	}
	if(j+1 < m){
		pos++;
	}
	if(j-1 >= 0){
		pos++;
	}
	return pos;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n, m;
		cin >> n >> m;

		int **grid = new int *[n];
		for(int i = 0; i < n; i++){
			grid[i] = new int[m];
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}

		bool ans = true;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				int pos = check(grid, i, j, n, m);

				if(grid[i][j] > pos){
					ans = false;
					break;
				}
				else{
					grid[i][j] = pos;
				}
			}
			if(!ans){
				break;
			}
		}

		if(!ans){
			cout << "NO" << endl;
		}
		else{
			cout << "YES" << endl;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < m; j++){
					cout << grid[i][j] << " ";
				}
				cout << endl;
			}
		}
	}
}