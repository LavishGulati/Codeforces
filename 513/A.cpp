#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    int *digit = new int[10];
    for(int i = 0; i < 10; i++) digit[i] = 0;

    int total = 0;
    for(int i = 0; i < n; i++){
        total++;
        digit[s[i]-'0']++;
    }

    int count = 0;
    while(digit[8] > 0 && total >= 11){
        digit[8]--;
        total -= 11;
        count++;
    }

    cout << count << endl;
}
