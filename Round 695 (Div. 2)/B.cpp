#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> tii;
typedef pair<long long, pair<long long, long long>> tll;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define uset unordered_set
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

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

		bool *pres = new bool[n];
		for(int i = 0; i < n; i++){
			pres[i] = false;
		}

		int num = 0;
		for(int i = 1; i < n-1; i++){
			if(a[i-1] > a[i] && a[i+1] > a[i]){
				pres[i] = true;
				num++;
			}
			if(a[i-1] < a[i] && a[i+1] < a[i]){
				pres[i] = true;
				num++;
			}
		}

		bool three = false, two1 = false, two2 = false;
		for(int i = 1; i < n-1; i++){
			if(pres[i-1] && pres[i] && pres[i+1]){
				three = true;
			}
			if(pres[i] && pres[i+1]){
				if(a[i] >= min(a[i-1], a[i+2]) && a[i] <= max(a[i-1], a[i+2])){
					two1 = true;
				}
				else if(a[i+1] >= min(a[i-1], a[i+2]) && a[i+1] <= max(a[i-1], a[i+2])){
					two1 = true;
				}
				else if(i-2 >= 0 && i+3 < n && a[i-2] != a[i-1] && a[i+2] != a[i+3]){
					two2 = true;
				}
				else{
					two1 = true;
				}
			}
			if(pres[i] && pres[i-1]){
				if(a[i-1] >= min(a[i-2], a[i+1]) && a[i-1] <= max(a[i-2], a[i+1])){
					two1 = true;
				}
				else if(a[i] >= min(a[i-2], a[i+1]) && a[i] <= max(a[i-2], a[i+1])){
					two1 = true;
				}
				else if(i-3 >= 0 && i+2 < n && a[i-3] != a[i-2] && a[i+1] != a[i+2]){
					two2 = true;
				}
				else{
					two1 = true;
				}
			}
		}

		if(three){
			cout << int(max(0, num-3)) << endl;
		}
		else if(two1){
			cout << int(max(0, num-2)) << endl;
		}
		else{
			cout << int(max(0, num-1)) << endl;
		}
	}
}