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
		int n, k;
		cin >> n >> k;

		string s;
		cin >> s;

		int i, cnt = 0, ans = 0;
		for(i = 0; i < n && s[i] == '0'; i++){
			cnt++;
		}

		if(cnt == n){
			cout << int(1 + (cnt-1)/(k+1)) << endl;
			continue;
		}

		ans += (cnt)/(k+1);
		cnt = 0;

		for(; i < n; i++){
			if(s[i] == '0'){
				cnt++;
			}
			else{
				ans += (cnt-k)/(k+1);
				cnt = 0;
			}
		}

		ans += cnt/(k+1);
		cout << ans << endl;
	}
}