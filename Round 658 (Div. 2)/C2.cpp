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
		int si = 0, ei = n-1;
		int inv = 0;
		for(int i = n-1; i >= 0; i--){
			// cout << a[ei] << " " << inv << " " << b[i] << endl;
			if(((a[ei]-'0')^inv) != (b[i]-'0')){
				if(a[ei] != a[si]){
					output.pb(1);
				}

				output.pb(i+1);
				if(si > ei){
					si--;
				}
				else{
					si++;
				}
				swap(si, ei);
				inv ^= 1;
			}
			else{
				if(ei > si){
					ei--;
				}
				else{
					ei++;
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