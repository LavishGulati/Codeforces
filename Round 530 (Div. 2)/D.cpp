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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    bool isLeaf[n];
    bool isAssigned[n];
    for(int i = 0; i < n; i++){
        isLeaf[i] = true;
        isAssigned[i] = true;
    }

    int parent[n];
    parent[0] = -1;
    for(int i = 1; i < n; i++){
        cin >> parent[i];
        parent[i]--;
        isLeaf[parent[i]] = false;
    }

    int weight[n];
    for(int i = 0; i < n; i++){
        cin >> weight[i];
        if(weight[i] == -1) isAssigned[i] = false;
    }

    for(int i = 0; i < n; i++){
        if(isLeaf[i]){
            int v = i;
            int par;
            while(1){
                par = parent[v];
                if(par == -1) break;

                if(!isAssigned[par]){
                    if(weight[par] == -1) weight[par] = weight[v];
                    else weight[par] = min(weight[par], weight[v]);
                }

                v = par;
            }
        }
    }

    // for(int i = 0; i < n; i++) cout << weight[i] << " ";
    // cout << endl;

    for(int i = 0; i < n; i++){
        if(isLeaf[i])
    }

    // for(int i = 0; i < n; i++) cout << weight[i] << " ";
    // cout << endl;

    int total = 0;
    for(int i = 0; i < n; i++){
        total += weight[i];
    }
    cout << total << endl;
}
