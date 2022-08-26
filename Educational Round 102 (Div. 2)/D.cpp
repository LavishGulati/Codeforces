#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

typedef long long ll;
typedef pair<long long, long long> pll;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> tii;
typedef pair<long long, pair<long long, long long>> tll;
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
		int n, m;
		cin >> n >> m;
		string s;
		cin >> s;

		int *start = new int[n];
		int x = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == '+'){
				x++;
			}
			else{
				x--;
			}
			start[i] = x;
		}

		pii *pre = new pii[n];
		int l = 0, r = 0;
		for(int i = 0; i < n; i++){
			l = min(l, start[i]);
			r = max(r, start[i]);
			pre[i] = mp(l, r);
		}

		pii *suf = new pii[n];
		if(s[n-1] == '+'){
			suf[n-1] = mp(0, 1);
		}
		else{
			suf[n-1] = mp(-1, 0);
		}
		pii p;
		for(int i = n-2; i >= 0; i--){
			if(s[i] == '+'){
				x = 1;
				p = {0, 1};
			}
			else{
				x = -1;
				p = {-1, 0};
			}
			l = x+suf[i+1].f;
			r = x+suf[i+1].s;
			suf[i] = {min(p.f, l), max(p.s, r)};
		}

		pii a, b;
		for(int i = 0; i < m; i++){
			cin >> l >> r;
			l--;
			if(l > 0){
				a = pre[l-1];
				if(r < n){
					b = suf[r];
					b.f += start[l-1];
					b.s += start[l-1];
				}
				else{
					b = a;
				}
			}
			else{
				a = {0, 0};
				if(r < n){
					b = suf[r];
				}
				else{
					b = a;
				}
			}
			// cout << a.f << " " << a.s << " " << b.f << " " << b.s << " " << start[l] << endl;
			cout << max(b.s, a.s)-min(a.f, b.f)+1 << endl;
		}
	}
}