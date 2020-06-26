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

		string s;
		cin >> s;

		string out2 = "";
		string out1 = "";
		int i = n-1;
		while(i >= 0 && s[i] == '1'){
			out2 += '1';
			i--;
		}

		int k = 0;
		while(k <= i && s[k] == '0'){
			out1 += '0';
			k++;
		}

		if(k < i){
			out1 += '0';
		}

		out1 += out2;
		cout << out1 << endl;
	}
}