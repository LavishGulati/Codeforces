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

#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;

		if(n == 1){
			cout << -1 << endl;
			continue;
		}

		string s = "";
		s += '3';
		for(int i = 0; i < n-1; i++){
			s += '2';
		}

		ll sum = 2*(n-1);
		if(sum%3 == 0){
			s[s.length()-1] = '3';
		}

		reverse(all(s));
		cout << s << endl;
	}
}