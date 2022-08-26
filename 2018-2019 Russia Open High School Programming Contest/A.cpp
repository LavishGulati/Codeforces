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
#define f first
#define s second
#define MOD 1000000007

bool compare(pll a, pll b){
    return a.s < b.s;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll n;
    cin >> n;

    ll m, x, maxSalary;
    pll *input = new pll[n];
    for(ll i = 0; i < n; i++){
        cin >> m;
        maxSalary = 0;
        for(ll j = 0; j < m; j++){
            cin >> x;
            maxSalary = max(x, maxSalary);
        }
        input[i] = mp(m, maxSalary);
    }

    sort(input, input+n, compare);
    ll workers = 0;
    ll total = 0;
    for(ll i = 0; i < n-1; i++){
        workers += input[i].f;
        total += workers*(input[i+1].s - input[i].s);
    }

    cout << total << endl;
}
