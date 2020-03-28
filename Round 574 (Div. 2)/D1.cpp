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
#define MOD 998244353
#define PI acos(-1)

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;
    string *input = new string[n];
    for(ll i = 0; i < n; i++){
        cin >> input[i];
    }

    ll m = input[0].length();
    ll total = 0, x, helper = 1;
    for(ll i = 2*m-1; i >= 0; i--){
        x = 0;
        for(ll j = 0; j < n; j++){
            x = (x+(input[j][i/2]-'0'))%MOD;
        }
        x = (n*x)%MOD;
        x = (x*helper)%MOD;
        total = (total+x)%MOD;
        helper = (helper*10)%MOD;
    }

    cout << total << endl;
}
