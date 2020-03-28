#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

int main(){
    int q, n, xmin, xmax, ymin, ymax, x, y, f;
    cin >> q;
    while(q--){
        xmin = -MAX; xmax = MAX;
        ymin = -MAX; ymax = MAX;

        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> x >> y;
            cin >> f;
            if(!f) xmin = max(xmin, x);
            cin >> f;
            if(!f) ymax = min(ymax, y);
            cin >> f;
            if(!f) xmax = min(xmax, x);
            cin >> f;
            if(!f) ymin = max(ymin, y);
        }

        if(ymin > ymax || xmin > xmax){
            cout << "0" << endl;
        }
        else{
            cout << "1 " << xmin << " " << ymin << endl;
        }
    }
}
