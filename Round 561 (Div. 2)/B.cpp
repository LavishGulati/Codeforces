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

    int k;
    cin >> k;
    bool IsPossible = false;
    int n, m;
    for(n = 5; n <= k; n++){
        if(k%n == 0 && k/n >= 5){
            IsPossible = true;
            break;
        }
    }

    if(!IsPossible){
        cout << -1 << endl;
        return 0;
    }

    char helper[5] = {'a', 'e', 'i', 'o', 'u'};

    m = k/n;
    string answer = "";
    if(m%5 == 0){
        int id = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                answer += helper[(j+id)%5];
            }
            id++;
        }
    }
    else{
        for(int i = 0; i < k; i++){
            answer += helper[i%5];
        }
    }

    cout << answer << endl;
}
