#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

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
		string a, b;
		cin >> a >> b;

		vector<int> output;
		for(int i = n-1; i >= 0; i--){
			if(a[i] != b[i]){
				if(a[0] != a[i]){
					output.pb(1);
					a[0] = a[i];
				}
				output.pb(i+1);
				for(int j = 0; j <= i/2; j++){
					swap(a[j], a[i-j]);
					if(a[j] == '0'){
						a[j] = '1';
					}
					else{
						a[j] = '0';
					}
					if(j != i-j){
						if(a[i-j] == '0'){
							a[i-j] = '1';
						}
						else{
							a[i-j] = '0';
						}
					}
				}
			}
		}

		cout << output.size() << " ";
		for(int x : output){
			cout << x << " ";
		}
		cout << endl;
	}
}