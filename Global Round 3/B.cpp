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

    int n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;

    int *AtoB = new int[n];
    for(int i = 0; i < n; i++){
        cin >> AtoB[i];
    }

    int *BtoC = new int[m];
    for(int i = 0; i < m; i++){
        cin >> BtoC[i];
    }

    if(k >= n){
        cout << -1 << endl;
        return 0;
    }

    int ReachB, id = 0;
    int MaxTime = INT_MIN;
    for(int i = 0; i <= k; i++){
        ReachB = AtoB[i]+ta;
        while(id < m && BtoC[id] < ReachB) id++;
        if(id+k-i >= m){
            MaxTime = INT_MAX;
            break;
        }

        MaxTime = max(MaxTime, BtoC[id+k-i]+tb);
    }

    if(MaxTime == INT_MAX) cout << -1 << endl;
    else cout << MaxTime << endl;
}
