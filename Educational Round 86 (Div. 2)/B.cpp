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
		string s;
		cin >> s;

		int n = s.length();

		bool same = true;
		for(ll i = 1; i < n; i++){
			if(s[i] != s[i-1]){
				same = false;
				break;
			}
		}

		if(same){
			cout << s << endl;
			continue;
		}

		string out = "";
		for(ll i = 0; i < n; i++){
			out += "01";
		}
		cout << out << endl;
	}
}