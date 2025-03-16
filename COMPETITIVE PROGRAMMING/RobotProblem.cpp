#include <bits/stdc++.h>
using namespace std;

int compareString(string a, string b) {
    return (a.length() == b.length()) ? (a >= b) : (a.length() > b.length());
}

string doSum(string a, string b) {
    if (a.size() < b.size())
        swap(a, b);

    int j = a.size() - 1;
    for (int i = b.size() - 1; i >= 0; i--, j--)
        a[j] += (b[i] - '0');

    for (int i = a.size() - 1; i > 0; i--) {
        if (a[i] > '9') {
            int d = a[i] - '0';
            a[i - 1] = ((a[i - 1] - '0') + d / 10) + '0';
            a[i] = (d % 10) + '0';
        }
    }
    if (a[0] > '9') {
        string k;
        k += a[0];
        a[0] = ((a[0] - '0') % 10) + '0';
        k[0] = ((k[0] - '0') / 10) + '0';
        a = k + a;
    }
    return a;
}

string fn(long long n, long long x, long long k, string s) {
    // string ans = "0";
    // string currTime = "0";
    // long long counter = 0;

    // while (compareString(k, currTime)) {
    //     if (x == 0) {
    //         counter = 0;
    //         ans = doSum(ans, "1");
    //     }
    //     if (counter == n) return ans;
    //     if (s[counter] == 'L') {
    //         x--;
    //     } else {
    //         x++;
    //     }
    //     currTime = doSum(currTime, "1");
    //     counter++;
    // }
    // return ans;

    long long ans = 0;
    long long currTime = 0;
    long long counter = 0;

    if(x==0) ans++;

    for(int i=0 ; i<n , currTime<=k ; i++ , currTime++){
        if(s[i] == )
    }

}

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n, x , k;

        cin >> n >> x >> k;

        string s;
        cin >> s;

        cout << fn(n, x, k, s) << endl;
    }
    return 0;
}
