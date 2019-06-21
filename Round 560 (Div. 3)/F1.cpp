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

#define MAX 200001

int n, m;
vector<int> k;
vector<pii> q(MAX);

bool possible(int day){
    vector<int> lst(n, -1);
    for(int i = 0; i < m; i++){
        if(q[i].f <= day){
            lst[q[i].s] = max(lst[q[i].s], q[i].f);
        }
    }

    vector< vector<int> > offer(MAX);
    for(int i = 0; i < n; i++){
        if(lst[i] != -1){
            offer[lst[i]].pb(i);
        }
    }

    vector<int> need = k;
    int burl = 0;
    for(int i = 0; i <= day; i++){
        burl++;
        if(i > MAX) continue;
        for(auto it : offer[i]){
            if(burl >= need[it]){
                burl -= need[it];
                need[it] = 0;
            }
            else{
                need[it] -= burl;
                burl = 0;
                break;
            }
        }
    }

    return accumulate(all(need), 0)*2 <= burl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> m;
    k = vector<int>(n);
    for(int i = 0; i < n; i++){
        cin >> k[i];
    }

    for(int i = 0; i < m; i++){
        cin >> q[i].f >> q[i].s;
        (q[i].f)--;
        (q[i].s)--;
    }

    int l = 0, r = 400000;
    while(r-l > 1){
        int mid = (l+r)>>1;
        if(possible(mid)) r = mid;
        else l = mid;
    }

    for(int i = l; i <= r; i++){
        if(possible(i)){
            cout << i+1 << endl;
            return 0;
        }
    }
}
