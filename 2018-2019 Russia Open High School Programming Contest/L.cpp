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

    ll t, n, a, b, k;
    cin >> t >> n >> a >> b >> k;

    if(k > n){
        cout << 0 << endl;
        return 0;
    }

    ll si = 0;
    ll ei = t+1;
    ll mid;
    while(si+1 < ei){
        mid = (si+ei)/2;
        if(min(mid*k, min(mid, a)*((n+1)/2) + min(mid, b)*(n/2)) == mid*k){
            si = mid;
        }
        else ei = mid;
    }

    cout << si << endl;
}
