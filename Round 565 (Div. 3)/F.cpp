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

ll helper[4][2];

void solve(vector<ll> **cards, ll id){
    for(ll i = 0; i < 4; i++){
        helper[i][0] = helper[i][1] = INT_MIN;
    }

    if(cards[id][1].size() > 0){
        helper[1][0] = max(helper[1][0], cards[id][1][0]);
        helper[1][1] = max(helper[1][1], cards[id][1][0]*2);
    }
    if(cards[id][2].size() > 0){
        helper[1][0] = max(helper[1][0], cards[id][2][0]);
        helper[1][1] = max(helper[1][1], cards[id][2][0]*2);
    }
    if(cards[id][3].size() > 0){
        helper[1][0] = max(helper[1][0], cards[id][3][0]);
        helper[1][1] = max(helper[1][1], cards[id][3][0]*2);
    }

    if(cards[id][1].size() >= 2){
        helper[2][0] = max(helper[2][0], cards[id][1][0]+cards[id][1][1]);
        helper[2][1] = max(helper[2][1], cards[id][1][0]*2+cards[id][1][1]);
    }
    if(cards[id][2].size() > 0 && cards[id][1].size() > 0){
        helper[2][0] = max(helper[2][0], cards[id][2][0]+cards[id][1][0]);
        helper[2][1] = max(helper[2][1], max(cards[id][1][0]*2+cards[id][2][0], cards[id][1][0]+2*cards[id][2][0]));
    }

    if(cards[id][1].size() >= 3){
        helper[3][0] = max(helper[3][0], cards[id][1][0]+cards[id][1][1]+cards[id][1][2]);
        helper[3][1] = max(helper[3][1], 2*cards[id][1][0]+cards[id][1][1]+cards[id][1][2]);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n, k, c, d;
    cin >> n;
    vector<ll> **cards = new vector<ll> *[n];
    for(ll i = 0; i < n; i++){
        cards[i] = new vector<ll>[4];
        cin >> k;
        while(k--){
            cin >> c >> d;
            cards[i][c].pb(d);
        }
        for(ll j = 1; j < 4; j++) sort(all(cards[i][j]), greater<ll>());
    }

    ll dp[n][10];
    dp[0][0] = 0;
    for(ll j = 1; j < 10; j++) dp[0][j] = INT_MIN;
    solve(cards, 0);
    for(ll j = 1; j < 4; j++) dp[0][j] = helper[j][0];

    for(ll i = 1; i < n; i++){
        solve(cards, i);
        for(ll j = 0; j < 10; j++) dp[i][j] = dp[i-1][j];
        for(ll j = 0; j < 10; j++){
            for(ll k = 1; k < 4; k++){
                if(j+k < 10){
                    dp[i][j+k] = max(dp[i][j+k], dp[i-1][j]+helper[k][0]);
                }
                else{
                    dp[i][(j+k)%10] = max(dp[i][(j+k)%10], dp[i-1][j]+helper[k][1]);
                }
            }
        }
    }

    // for(ll i = 0; i < n; i++){
    //     for(ll j = 0; j < 10; j++) cout << dp[i][j] << " ";
    //     cout << endl;
    // }

    ll total = 0;
    for(ll j = 0; j < 10; j++) total = max(dp[n-1][j], total);
    cout << total << endl;
}
