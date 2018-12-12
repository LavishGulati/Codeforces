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

#define it iterator
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define f first
#define s second
#define MOD 1000000007

int main(){
    int n;
    cin >> n;

    int *input = new int[n];
    for(int i = 0; i < n; i++) cin >> input[i];

    int minElec = INT_MAX;
    for(int i = 0; i < n; i++){
        int totalElec = 0;
        for(int j = 0; j < n; j++){
            totalElec += input[j]*(abs(i-j)+abs(j)+abs(i));
        }
        minElec = min(minElec, totalElec);
    }

    cout << minElec*2 << endl;
}
