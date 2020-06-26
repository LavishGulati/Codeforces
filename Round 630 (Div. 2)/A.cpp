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
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		int x, y, x1, y1, x2, y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		if(x-a+b >= x1 && x-a+b <= x2 && y-c+d >= y1 && y-c+d <= y2){
			if(a > b && x1 > x-1){
				cout << "No" << endl;
			}
			else if(a < b && x2 < x+1){
				cout << "No" << endl;
			}
			else if(a == b && a > 0 && x1 > x-1 && x2 < x+1){
				cout << "No" << endl;
			}
			else if(c > d && y1 > y-1){
				cout << "No" << endl;
			}
			else if(c < d && y2 < y+1){
				cout << "No" << endl;
			}
			else if(c == d && c > 0 && y1 > y-1 && y2 < y+1){
				cout << "No" << endl;
			}
			else{
				cout << "Yes" << endl;
			}
		}
		else{
			cout << "No" << endl;
		}
	}
}