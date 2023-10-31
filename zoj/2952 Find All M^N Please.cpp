#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <cmath>
#include <queue>
#include <iostream>
using namespace std;
typedef long long ll;
const ll N=2147483648;
ll quick(ll a,ll b)
{
    ll sum=1;
    while(b)
    {
        if(b%2) sum*=a;
        a*=a;
        b/=2;
    }
    return sum;
}
int main()
{
    set<ll> q;
    ll cnt=sqrt(N);
    for(ll i=2;i<=cnt;i++)
    {
        for(ll j=2;j<32;j++)
        {
            ll num=quick(i,j);
            if(num>=N) break;
            q.insert(num);
        }
    }
    for(set<ll>::iterator it=q.begin();it!=q.end();it++)
    {
        printf("%lld\n",*it);
    }
}