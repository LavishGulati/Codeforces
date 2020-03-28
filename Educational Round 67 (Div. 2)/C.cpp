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

#define MAX 1000000000

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    int t, l, r;
    vector<pii> first;
    vector<pii> zeroth;
    for(int i = 0; i < m; i++){
        cin >> t >> l >> r;
        if(t == 1) first.pb(mp(l-1, r-1));
        else zeroth.pb(mp(l-1, r-1));
    }

    int diff[n];
    for(int i = 1; i < n; i++) diff[i] = -1;

    for(int i = 0; i < first.size(); i++){
        for(int j = first[i].f+1; j <= first[i].s; j++){
            diff[j] = 0;
        }
    }

    for(int i = 0; i < zeroth.size(); i++){
        int j;
        for(j = zeroth[i].f+1; j <= zeroth[i].s; j++){
            if(diff[j] == -1) break;
        }

        if(j > zeroth[i].s){
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    int x = n;
    cout << x << " ";
    for(int i = 1; i < n; i++){
        x += diff[i];
        cout << x << " ";
    }
    cout << endl;
}
