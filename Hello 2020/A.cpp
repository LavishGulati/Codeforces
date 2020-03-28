#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;

#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define mp make_pair

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	string arr1[n];
	string arr2[m];
	for(int i = 0; i < n; i++){
		cin >> arr1[i];
	}
	for(int i = 0; i < m; i++){
		cin >> arr2[i];
	}

	int q, y;
	cin >> q;
	while(q--){
		cin >> y;

		cout << arr1[(y-1)%n] + arr2[(y-1)%m] << endl;
	}
}