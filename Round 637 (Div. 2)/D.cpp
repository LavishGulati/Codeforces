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

int mismatch(string &s, string &a){
	int cnt = 0;
	for(int i = 0; i < 7; i++){
		if(a[i] == '1' && s[i] == '0'){
			cnt++;
		}
		else if(a[i] == '0' && s[i] == '1'){
			return -1;
		}
	}
	return cnt;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	string *digits = new string[10];
	digits[0] = "1110111";
	digits[1] = "0010010";
	digits[2] = "1011101";
	digits[3] = "1011011";
	digits[4] = "0111010";
	digits[5] = "1101011";
	digits[6] = "1101111";
	digits[7] = "1010010";
	digits[8] = "1111111";
	digits[9] = "1111011";

	string *a = new string[n];
	for(int i = 0; i < n; i++){
		cin >> a[n-i-1];
	}

	int **dp = new int *[n+1];
	for(int i = 0; i <= n; i++){
		dp[i] = new int[k+1];
		for(int j = 0; j <= k; j++){
			dp[i][j] = -1;
		}
	}

	for(int j = 0; j < 10; j++){
		int x = mismatch(a[0], digits[j]);
		// cout << x << endl;
		if(x != -1 && x <= k){
			dp[0][x] = max(dp[0][x], j);
		}
	}

	for(int i = 1; i < n; i++){
		for(int j = 0; j < 10; j++){
			int x = mismatch(a[i], digits[j]);
			if(x != -1){
				for(int l = 0; l+x <= k; l++){
					if(dp[i-1][l] != -1){
						dp[i][l+x] = max(dp[i][l+x], j);
					}
				}
			}
		}
	}


	if(dp[n-1][k] == -1){
		cout << -1 << endl;
	}
	else{
		string out = "";
		for(int i = n-1; i >= 0; i--){
			out += '0'+dp[i][k];
			int x = mismatch(a[i], digits[dp[i][k]]);
			k -= x;
		}
		cout << out << endl;
	}
}