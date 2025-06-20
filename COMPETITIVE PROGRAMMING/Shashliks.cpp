#include <bits/stdc++.h>
using namespace std;

long long solve(long long k, long long a, long long b, long long x, long long y) {
    long long temp = k;
    long long ans = 0;

    pair<long long,long long>A , B; //A->small drop , B->large drop
    if(x<=y) {
        A = {a,x};
        B = {b,y};
    }
    else{
        A = {b,y};
        B = {a,x};
    }

    if(temp >= A.first){
        long long count = (temp - A.first) / A.second + 1;
        temp -= count * A.second;
        ans += count;
    }

    if(temp >= B.first){
        long long count = (temp - B.first) / B.second + 1;
        temp -= count * B.second;
        ans += count;
    }

    return ans;
}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long k, a, b, x, y;
        cin >> k >> a >> b >> x >> y;
        cout << solve(k, a, b, x, y) << "\n";
    }
    return 0;
}
