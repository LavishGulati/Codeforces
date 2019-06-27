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

void solve(){
    int n, k, a, b;
    cin >> n >> k;
    int *input = new int[n];
    for(int i = 0; i < n; i++) cin >> input[i];

    a = input[0]-k;
    b = input[0]+k;
    for(int i = 1; i < n; i++){
        if(input[i]-k > b || input[i]+k < a){
            cout << -1 << endl;
            return;
        }
        else{
            a = max(input[i]-k, a);
            b = min(input[i]+k, b);
        }
    }

    if(b <= 0) cout << -1 << endl;
    else cout << b << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int q;
    cin >> q;
    while(q--){
        solve();
    }
}
