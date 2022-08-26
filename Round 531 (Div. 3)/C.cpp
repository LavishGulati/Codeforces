#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unordered_map<int, int> umapii;
typedef unordered_map<int, bool> umapib;
typedef unordered_map<string, int> umapsi;
typedef unordered_map<string, string> umapss;
typedef map<string, int> mapsi;
typedef map<pair<int, int>, int> mappiii;
typedef map<int, int> mapii;
typedef map<int, bool> mapib;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;
typedef set<int> seti;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()
#define f first
#define s second
#define MOD 1000000007

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, x, y, a;
	cin >> n >> x >> y;
	priority_queue< int, vector<int>, greater<int> > pq;
	for(int i = 0; i < n; i++){
		cin >> a;
		pq.push(a);
	}

	int answer = 0;
	if(x > y){
		answer = n;
	}
	else{
		while(!pq.empty()){
			a = pq.top();
			pq.pop();
			if(a-x <= 0){
				answer++;
				a = pq.top();
				pq.pop();
				pq.push(a+y);
			}
			else break;
		}
	}

	cout << answer << endl;
}