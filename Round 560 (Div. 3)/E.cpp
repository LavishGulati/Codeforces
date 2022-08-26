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
#define MOD 998244353
#define PI acos(-1)

bool compare(ll a, ll b){
    return a > b;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;

    ll *A = new ll[n];
    for(ll i = 0; i < n; i++) cin >> A[i];

    ll *B = new ll[n];
    for(ll i = 0; i < n; i++) cin >> B[i];

    ll helper[n];
    for(ll i = 0; i < n; i++){
        helper[i] = (i+1)*(n-i)*A[i];
    }
    sort(helper, helper+n);

    sort(B, B+n);
    ll total = 0;
    for(ll i = 0; i < n; i++){
        total = (total+(((helper[i]%MOD)*B[n-1-i])%MOD))%MOD;
    }
    cout << total << endl;
}
