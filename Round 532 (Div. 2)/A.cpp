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

    int n, k, numEdu = 0, numSoc = 0;
    cin >> n >> k;
    int input[n];
    for(int i = 0; i < n; i++){
        cin >> input[i];
        if(input[i] == 1) numEdu++;
        else numSoc++;
    }

    int maxValue = 0, x, y;
    for(int i = 0; i < k; i++){
        x = numEdu;
        y = numSoc;
        int j = i;
        while(j < n){
            if(input[j] == 1) x--;
            else y--;
            j += k;
        }
        maxValue = max(maxValue, abs(x-y));
    }
    cout << maxValue << endl;
}
