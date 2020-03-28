#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
#define f first
#define s second
#define pb push_back
#define mp make_pair

#define MOD 998244353

bool compare(pll a, pll b){
    return a.s < b.s;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    pll *input = new pll[n];
    for(ll i = 0; i < n; i++){
        cin >> input[i].f >> input[i].s;
    }

    ll fact[n+1];
    fact[0] = 1;
    for(ll i = 1; i <= n; i++){
        fact[i] = (fact[i-1]*i)%MOD;
    }

    ll total = fact[n];
    sort(input, input+n);

    // cout << total << endl;

    ll x = 1;
    ll helper = 1;
    for(ll i = 1; i < n; i++){
        if(input[i].f == input[i-1].f) x++;
        else{
            helper = (helper*fact[x])%MOD;
            x = 1;
        }
    }
    helper = (helper*fact[x])%MOD;

    total = (total-helper+MOD)%MOD;

    // cout << total << endl;


    sort(input, input+n, compare);
    x = 1;
    helper = 1;
    for(ll i = 1; i < n; i++){
        if(input[i].s == input[i-1].s) x++;
        else{
            helper = (helper*fact[x])%MOD;
            x = 1;
        }
    }
    helper = (helper*fact[x])%MOD;

    total = (total-helper+MOD)%MOD;

    // cout << total << endl;


    sort(input, input+n);

    for(ll i = 1; i < n; i++){
        if(!(input[i].f >= input[i-1].f && input[i].s >= input[i-1].s)){
            cout << total << endl;
            return 0;
        }
    }

    x = 1;
    helper = 1;
    for(ll i = 1; i < n; i++){
        if(input[i].s == input[i-1].s && input[i].f == input[i-1].f) x++;
        else{
            helper = (helper*fact[x])%MOD;
            x = 1;
        }
    }
    helper = (helper*fact[x])%MOD;

    total = (total+helper)%MOD;
    cout << total << endl;
}
