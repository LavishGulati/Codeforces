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
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef unordered_set<int> useti;
typedef set<int> seti;

#define uset unordered_set
#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007

int query(int a, int b){
    int answer;
    cout << "? " << a << " " << b << endl;
    cin >> answer;
    return answer;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int a = 0, b = 0;
    int big = query(0, 0);
    for(int i = 29; i >= 0; i--){
        int ans1 = query(a^(1<<i), b);
        int ans2 = query(a, b^(1<<i));
        if(ans1 == ans2){
            if(big == 1) a ^= (1<<i);
            else b ^= (1<<i);
            big = ans1;
        }
        else{
            if(ans2 == 1){
                a ^= (1<<i);
                b ^= (1<<i);
            }
        }
    }

    cout << "! " << a << " " << b << endl;
}
