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

    string s;
    cin >> s;
    int n;
    cin >> n;

    int numCandy = 0, numFlake = 0;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '?') numCandy++;
        else if(s[i] == '*') numFlake++;
    }

    string helper;
    int i = 0;
    while(s.length()-numCandy-numFlake > n && i < s.length()){
        if(s[i] == '?' || s[i] == '*'){
            helper = s.substr(0, i-1) + s.substr(i+1);
            if(s[i] == '?') numCandy--;
            else numFlake--;

            s = helper;
        }
        else i++;
    }

    if(s.length()-numCandy-numFlake < n){
        int i = 0;
        for(; i < s.length(); i++){
            if(s[i] == '*') break;
        }

        if(i != s.length()){
            string a = "";
            for(int j = 0; j < i-1; j++){
                if(s[j] != '?' && s[j] != '*') a += s[j];
            }
            string b = "";
            for(int j = i+1; j < s.length(); j++){
                if(s[j] != '?' && s[j] != '*') b += s[j];
            }
            helper = "";
            while(helper.length() != n-a.length()-b.length()) helper += s[i-1];
            s = a+helper+b;
        }
    }

    helper = "";
    for(i = 0; i < s.length(); i++){
        if(s[i] != '?' && s[i] != '*') helper += s[i];
    }

    if(helper.length() == n) cout << helper << endl;
    else cout << "Impossible" << endl;
}
