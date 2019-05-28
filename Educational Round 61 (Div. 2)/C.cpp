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

    int n, q;
    cin >> n >> q;
    pii painters[q];

    int numPainted[n];
    for(int i = 0; i < n; i++){
        numPainted[i] = 0;
    }

    for(int i = 0; i < q; i++){
        cin >> painters[i].f >> painters[i].s;
        (painters[i].f)--;
        (painters[i].s)--;
        for(int j = painters[i].f; j <= painters[i].s; j++){
            numPainted[j]++;
        }
    }


    int maxPainted = 0;
    int helper[n];
    for(int i = 0; i < q; i++){
        for(int j = 0; j < n; j++) helper[j] = numPainted[j];
        for(int j = painters[i].f; j <= painters[i].s; j++){
            helper[j]--;
        }

        int totalPainted = 0;
        for(int j = 0; j < n; j++){
            if(helper[j] > 0) totalPainted++;
            helper[j] = (helper[j] == 1) ? 1 : 0;
        }

        for(int j = 1; j < n; j++){
            helper[j] += helper[j-1];
        }

        int minLeft = INT_MAX;
        for(int j = 0; j < q; j++){
            if(i == j) continue;
            else if(painters[j].f == 0){
                minLeft = min(minLeft, helper[painters[j].s]);
            }
            else{
                minLeft = min(minLeft, helper[painters[j].s]-helper[(painters[j].f)-1]);
            }
        }

        maxPainted = max(maxPainted, totalPainted-minLeft);
    }

    cout << maxPainted << endl;
}
