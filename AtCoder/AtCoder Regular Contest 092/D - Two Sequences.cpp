#pragma comment(linker, "/STACK:10240000,10240000")
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
 
const int maxn = 2e5 + 7;
 
int n;
long long a[maxn], b[maxn];
 
void sort(long long *a, long long md) {
    int pos = n;
    for (int i = 0; i < n; i ++) {
        if (pos == n && a[i] >= md) pos = i;
        a[i] = a[i] & (md - 1);
    }
    inplace_merge(a, a + pos, a + n);
}
 
bool solve(long long limit) {
    long long ans = 0;
    int that = n - 1;
    for (int i = 0; i < n; i ++) {
        while (that >= 0 && a[i] + b[that] >= limit) that --;
        ans += n - 1 - that;
    }
    return ans & 1;
}
int main() {
#ifndef ONLINE_JUDGE
//    freopen("in.txt", "r", stdin);
#endif // ONLINE_JUDGE
    int T, cas = 0;
    {
        cin >> n;
        for (int i = 0; i < n; i ++) {
            scanf("%I64d", a + i);
        }
        for (int i = 0; i < n; i ++) {
            scanf("%I64d", b + i);
        }
        sort(a, a + n);
        sort(b, b + n);
        long long ans = 0;
        for (int i = 61; i >= 0; i --) {
            sort(a, (long long)2 << i);
            sort(b, (long long)2 << i);
            long long res =
                solve((long long)1 << i) ^
                solve((long long)2 << i) ^
                solve((long long)3 << i);
            ans |= res << i;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
