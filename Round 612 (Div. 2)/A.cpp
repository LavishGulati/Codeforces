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
#define all(x) x.begin(), x.end()

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t, n;
	cin >> t;
	string s;
	while(t--){
		cin >> n;
		cin >> s;

		int answer = 0;
		int x = 0;
		int i = 0;
		while(i < n){
			int j = i+1;
			if(s[i] == 'A'){
				j = i+1;
				while(j < n && s[j] == 'P'){
					j++;
				}
				answer = max(answer, j-i-1);
			}
			i = j;
		}

		cout << answer << endl;
	}
}