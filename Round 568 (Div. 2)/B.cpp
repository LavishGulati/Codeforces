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

    int t;
    cin >> t;
    string a, b;
    bool IsPossible;
    while(t--){
        IsPossible = true;
        cin >> a >> b;
        int n = a.length();
        int m = b.length();
        int i = 0, j = 0;
        char c;
        int num1, num2;
        while(i < a.length()){
            c = a[i];
            num1 = num2 = 0;
            while(i < n && a[i] == c){
                num1++;
                i++;
            }
            while(j < m && b[j] == c){
                j++;
                num2++;
            }
            if(num2 < num1){
                IsPossible = false;
                break;
            }
        }
        if(j < m) cout << "NO" << endl;
        else if(IsPossible) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
