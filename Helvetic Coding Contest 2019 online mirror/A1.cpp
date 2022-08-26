#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
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
typedef vector<int> vi;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define allp(x) (x)->begin(), (x)->end()
#define f first
#define s second
#define MOD 1000000007
#define PI acos(-1)

#define MAX 1000000

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll r, a, y;
    cin >> r;
    for(ll x = 1; x < MAX; x++){
        if((r-x*x-x-1) > 0 && (r-x*x-x-1)%(2*x) == 0){
            y = (r-x*x-x-1)/(2*x);
            cout << x << " " << y << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
