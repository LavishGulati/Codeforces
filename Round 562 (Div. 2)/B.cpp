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

    int n, m;
    cin >> n >> m;
    pii *input = new pii[m];
    for(int i = 0; i < m; i++){
        cin >> input[i].f >> input[i].s;
    }

    vector<int> developing;
    vector<pii> possible;
    developing.pb(input[0].f);
    developing.pb(input[0].s);
    vector<int> RemoveIndices;

    for(int i = 1; i < m; i++){
        for(int j = 0; j < possible.size(); j++){
            if(input[i].f == possible[j].f || input[i].s == possible[j].f || input[i].f == possible[j].s || input[i].s == possible[j].s){
                // do nothing
            }
            else{
                possible.erase(possible.begin()+j);
                j--;
            }
        }

        for(int j = 0; j < developing.size(); j++){
            if(developing[j] == input[i].f || developing[j] == input[i].s){
                // do nothing
            }
            else{
                possible.pb(mp(developing[j], input[i].f));
                possible.pb(mp(developing[j], input[i].s));
                developing.erase(developing.begin()+j);
                j--;
            }
        }
    }

    if(developing.size() > 0 || possible.size() > 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}
