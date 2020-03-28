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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k, m, t;
    cin >> n >> k >> m >> t;
    int type, i;
    int si = 1, ei = n;
    while(t--){
        cin >> type >> i;
        if(type == 0){
            if(k >= si && k <= si+i-1){
                ei = si+i-1;
            }
            else{
                si = si+i;
            }
        }
        else{
            if(si+i-1 <= k){
                si--;
            }
            else{
                ei++;
            }
        }
        cout << ei-si+1 << " " << k-si+1 << endl;
    }
}
