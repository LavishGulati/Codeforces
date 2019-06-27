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

    ll n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    ll dp[n+1][n];
    ll helper[26];
    for(ll i = 0; i < 26; i++) helper[i] = 0;
    for(ll j = 0; j < n; j++) dp[0][j] = 1;

    dp[1][n-1] = 1;
    helper[s[n-1]-'a'] = 1;
    for(ll j = n-2; j >= 0; j--){
        dp[1][j] = dp[1][j+1];
        if(helper[s[j]-'a'] == 0){
            dp[1][j]++;
            helper[s[j]-'a'] = 1;
        }
    }

    for(ll i = 2; i <= n; i++){
        for(ll j = 0; j < 26; j++) helper[j] = 0;
        dp[i][n-1] = 0;
        for(ll j = n-2; j >= 0; j--){
            dp[i][j] = dp[i][j+1]+dp[i-1][j+1];
            dp[i][j] -= helper[s[j]-'a'];
            helper[s[j]-'a'] = dp[i-1][j+1];
        }
    }

    ll num, total = 0;
    for(ll i = n; i >= 0; i--){
        num = min(k, dp[i][0]);
        total += num*(n-i);
        k -= num;
        if(k == 0) break;
    }

    if(k > 0) cout << -1 << endl;
    else cout << total << endl;
}
