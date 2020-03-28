#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, bool> pib;

#define pb push_back
#define umap unordered_map
#define f first
#define s second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n;
	cin >> n;

	string s;
	cin >> s;

	int numLeft = 0;
	int numRight = 0;

	for(int i = 0; i < n; i++){
		if(s[i] == 'L'){
			numLeft++;
		}
		else{
			numRight++;
		}
	}

	cout << numLeft+numRight+1 << endl;
}