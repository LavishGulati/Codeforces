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

string sum(string a, string b){
    string ans = "";
    ll carry = 0;
    ll x, y;
    char c;

    if(a.length() < b.length()){
        ll m = b.length()-a.length();
        string helper = "";
        for(ll i = 0; i < m; i++) helper += '0';
        a = helper+a;
    }
    if(b.length() < a.length()){
        ll m = a.length()-b.length();
        string helper = "";
        for(ll i = 0; i < m; i++) helper += '0';
        b = helper+b;
    }

    for(ll i = a.length()-1; i >= 0; i--){
        x = a[i]-'0';
        y = b[i]-'0';
        c = ((x+y+carry)%10) + '0';
        ans = c+ans;
        carry = (x+y+carry)/10;
    }

    c = carry+'0';
    ans = c+ans;

    for(ll i = 0; i < ans.length(); i++){
        if(ans[i] != '0' && i > 0){
            ans = ans.substr(i);
            break;
        }
    }

    return ans;
}

bool comp(string a, string b){
    if(a.length() < b.length()) return true;
    else if(a.length() > b.length()) return false;
    else return a < b;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int i = n/2;
    int j = n/2 + 1;
    while(i >= 0 && s[i] == '0') i--;
    while(j < n && s[j] == '0') j++;

    string answer = "";
    string helper;
    for(int k = i-1; k <= i+1; k++){
        if(k >= 0 && k < n && s[k] != '0'){
            helper = sum(s.substr(0, k), s.substr(k));
            if(answer == "" || comp(helper, answer)){
                answer = helper;
            }
        }
    }

    for(int k = j-1; k <= j+1; k++){
        if(k >= 0 && k < n && s[k] != '0'){
            helper = sum(s.substr(0, k), s.substr(k));
            if(answer == "" || comp(helper, answer)){
                answer = helper;
            }
        }
    }

    cout << answer << endl;
}
