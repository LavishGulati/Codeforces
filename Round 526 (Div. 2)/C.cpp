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

#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007

#define MAX 100005

string s;
ll memo[MAX][2][2];

ll find(ll id, bool chooseA, ll n, bool size){
    if(id == n){
        if(size){
            return 1;
        }
        else return 0;
    }

    ll x, y;

    if(chooseA) x = 1;
    else x = 0;

    if(size) y = 1;
    else y = 0;

    if(memo[id][x][y] != -1) return memo[id][x][y];

    if(chooseA){
        if(s[id] != 'a') memo[id][x][y] = find(id+1, true, n, size);
        else{
            ll a = find(id+1, false, n, true);
            ll b = find(id+1, true, n, size);
            memo[id][x][y] = (a+b)%MOD;
        }
    }
    else{
        if(s[id] == 'b') memo[id][x][y] = find(id+1, true, n, size);
        else memo[id][x][y] = find(id+1, false, n, size);
    }

    return memo[id][x][y];
}

int main(){
    cin >> s;
    ll n = s.length();

    for(ll i = 0; i < MAX; i++){
        for(ll j = 0; j < 2; j++){
            memo[i][j][0] = -1;
            memo[i][j][1] = -1;
        }
    }

    cout << find(0, true, n, false) << endl;
}
