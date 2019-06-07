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

    int n, x;
    cin >> n >> x;

    int input[n];
    vector<int> pos[x+1];
    int PrefMax[n+1];

    for(int i = 0; i < n; i++){
        cin >> input[i];
        pos[input[i]].pb(i);
        PrefMax[i] = max(input[i], (i > 0 ? PrefMax[i-1] : input[i]));
    }

    int suf = 1;
    int lst = n;
    for(int i = x; i >= 1; i--){
        if(pos[i].empty()){
            suf = i;
            continue;
        }

        if(pos[i].back() > lst) break;
        suf = i;
        lst = pos[i][0];
    }

    ll answer = 0;
    lst = -1;
    int s;
    for(int i = 1; i <= x; i++){
        s = max(i, suf-1);
        if(lst != -1) s = max(s, PrefMax[lst]);

        answer += x-s+1;
        if(!pos[i].empty()){
            if(pos[i][0] < lst) break;
            lst = pos[i].back();
        }
    }

    cout << answer << endl;
}
