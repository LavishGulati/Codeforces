#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll q, n, x, a, y, b, k;
    cin >> q;
    while(q--){
        cin >> n;
        ll price[n];
        for(ll i = 0; i < n; i++){
            cin >> price[i];
        }

        cin >> x >> a >> y >> b >> k;

        if(y > x){
            swap(x, y);
            swap(a, b);
        }

        sort(price, price+n);

        ll si = 1;
        ll ei = n;
        ll answer = -1;
        while(si <= ei){
            ll mid = (si+ei)/2;
            ll id = n-1;
            ll total = 0;
            ll lcm = (a*b)/(__gcd(a, b));
            ll pos = lcm;
            while(id >= 0 && pos <= mid){
                total += (price[id]/100)*(x+y);
                id--;
                pos += lcm;
            }
            ll pos2 = a;
            while(pos2 <= mid && (pos2%lcm == 0)) pos2 += a;
            while(pos2 <= mid && id >= 0){
                total += (price[id]/100)*x;
                id--;
                pos2 += a;
                while(pos2 <= mid && (pos2%lcm == 0)) pos2 += a;
            }

            pos2 = b;
            while(pos2 <= mid && (pos2%lcm == 0)) pos2 += b;
            while(pos2 <= mid && id >= 0){
                total += (price[id]/100)*y;
                id--;
                pos2 += b;
                while(pos2 <= mid && (pos2%lcm == 0)) pos2 += b;
            }

            if(total >= k){
                answer = mid;
                ei = mid-1;
            }
            else{
                si = mid+1;
            }
        }

        cout << answer << endl;
        // sort(price, price+n);
        // ll id = n-1;
        // ll total = 0;
        // ll num = 0;
        // for(ll i = 0; i < n; i++){
        //
        // }
        // ll lcm = (a*b)/(__gcd(a, b));
        // ll pos = lcm;
        // while(id >= 0 && pos <= n && total < k){
        //     total += (price[id]/100)*(x+y);
        //     id--;
        //     num++;
        //     pos += lcm;
        // }
        // if(id == -1){
        //     if(total < k){
        //         cout << -1 << endl;
        //         continue;
        //     }
        //     else{
        //         cout << num << endl;
        //         continue;
        //     }
        // }
        // if(total >= k){
        //     cout << num << endl;
        //     continue;
        // }
        //
        // if(y > x){
        //     swap(x, y);
        //     swap(a, b);
        // }
        //
        // ll pos2 = a;
        // while(pos2 <= n && (pos2%lcm == 0)) pos2 += a;
        // while(pos2 <= n && id >= 0 && total < k){
        //     total += (price[id]/100)*x;
        //     id--;
        //     num++;
        //     pos2 += a;
        //     while(pos2 <= n && (pos2%lcm == 0)) pos2 += a;
        // }
        // if(id == -1){
        //     if(total < k){
        //         cout << -1 << endl;
        //         continue;
        //     }
        //     else{
        //         cout << num << endl;
        //         continue;
        //     }
        // }
        // if(total >= k){
        //     cout << num << endl;
        //     continue;
        // }
        //
        // pos2 = b;
        // while(pos2 <= n && (pos2%lcm == 0)) pos2 += b;
        // while(pos2 <= n && id >= 0 && total < k){
        //     total += (price[id]/100)*y;
        //     id--;
        //     num++;
        //     pos2 += b;
        //     while(pos2 <= n && (pos2%lcm == 0)) pos2 += b;
        // }
        // if(id == -1){
        //     if(total < k){
        //         cout << -1 << endl;
        //         continue;
        //     }
        //     else{
        //         cout << num << endl;
        //         continue;
        //     }
        // }
        // if(total >= k){
        //     cout << num << endl;
        //     continue;
        // }
        // else{
        //     cout << -1 << endl;
        // }
    }
}
