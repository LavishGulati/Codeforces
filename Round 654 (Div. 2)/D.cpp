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

	ll t;
	cin >> t;
	while(t--){
		ll n, k;
		cin >> n >> k;

		int **output = new int *[n];
		for(int i = 0; i < n; i++){
			output[i] = new int[n];
			for(int j = 0; j < n; j++){
				output[i][j] = 0;
			}
		}

		ll i = 0, j = 0;
		while(k > 0){
			ll a = i, b = j;
			while(k > 0 && a < n && b < n){
				output[a][b] = 1;
				a++; b++;
				k--;
			}

			if(j != 0){
				a = n-j, b = 0;
				while(k > 0 && a < n && b < n){
					output[a][b] = 1;
					a++; b++;
					k--;
				}
			}

			j++;
		}

		ll minRow = -1, maxRow = -1, minCol = -1, maxCol = -1;
		for(ll i = 0; i < n; i++){
			ll sum = 0;
			for(ll j = 0; j < n; j++){
				sum += output[i][j];
			}
			if(minRow == -1 || minRow > sum){
				minRow = sum;
			}
			if(maxRow == -1 || maxRow < sum){
				maxRow = sum;
			}
		}

		for(ll j = 0; j < n; j++){
			ll sum = 0;
			for(ll i = 0; i < n; i++){
				sum += output[i][j];
			}
			if(minCol == -1 || minCol > sum){
				minCol = sum;
			}
			if(maxCol == -1 || maxCol < sum){
				maxCol = sum;
			}
		}

		cout << (maxRow-minRow)*(maxRow-minRow) + (maxCol-minCol)*(maxCol-minCol) << endl;
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < n; j++){
				cout << output[i][j];
			}
			cout << endl;
		}
	}
}