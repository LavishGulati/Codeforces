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
#define allp(x) (x)->begin(), (x)->end()
#define f first
#define s second
#define MOD 1000000007

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    bool flag = true;
    int n;
    cin >> n;
    string *input = new string[2*n-2];

    string a = "", b = "";
    for(int i = 0; i < 2*n-2; i++){
        cin >> input[i];
        if(input[i].length() == n-1){
            if(a.length() == 0) a = input[i];
            else b = input[i];
        }
    }

    unordered_map<string, bool> m;
    string s;
    string answer = "";

    if(a.substr(1) == b.substr(0, n-2)) s = a+b[n-2];
    else s = b+a[n-2];
    int L = s.length();

    for(int i = 0; i < 2*n-2; i++){
        int l = input[i].length();
        if(input[i] == s.substr(0, l) && m.find(input[i]) == m.end()){
            answer += 'P';
            m[input[i]] = true;
        }
        else if(input[i] == s.substr(L-l)) answer += 'S';
        else flag = false;
    }

    if(!flag){
        s = b+a[n-2];
        answer = "";
        m.clear();

        for(int i = 0; i < 2*n-2; i++){
            int l = input[i].length();
            if(input[i] == s.substr(0, l) && m.find(input[i]) == m.end()){
                answer += 'P';
                m[input[i]] = true;
            }
            else answer += 'S';
        }
    }

    cout << answer << endl;
}
