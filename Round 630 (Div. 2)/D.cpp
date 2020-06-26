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

	int k;
	cin >> k;

	int x = 1;
	int y = 1;
	while(y+2*x <= 300000){
		x *= 2;
		y += x;
	}

	int z = k^y;

	// while(y != 0){
	// 	cout << (y%2);
	// 	y /= 2;
	// }
	// cout << y << endl;

	cout << 3 << " " << 3 << endl;
	cout << y << " " << k << " " << 0 << endl;
	cout << z << " " << y << " " << 0 << endl;
	cout << 0 << " " << y << " " << k << endl;

	// int a = (y&k)&y;
	// int b = (y&0)&y;
	// cout << a << " " << b << endl;
}