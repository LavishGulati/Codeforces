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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    ll h1[n];
    ll h2[n];
    for(ll i = 0; i < n; i++) cin >> h1[i];
    for(ll i = 0; i < n; i++) cin >> h2[i];

    ll dp[2][n];
    dp[0][0] = h1[0];
    dp[1][0] = h2[0];
    for(ll i = 1; i < n; i++){
        dp[0][i] = dp[1][i-1]+h1[i];
        if(i >= 2) dp[0][i] = max(dp[0][i], max(h1[i]+dp[0][i-2], h1[i]+dp[1][i-2]));
        dp[1][i] = dp[0][i-1]+h2[i];
        if(i >= 2) dp[1][i] = max(dp[1][i], max(h2[i]+dp[0][i-2], h2[i]+dp[1][i-2]));
    }

    cout << max(dp[0][n-1], dp[1][n-1]) << endl;
}
