#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <iomanip>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
ll a[1000010];
int main()
{
    ll t,n,i,j,s,x,y,p;
    while(cin>>t)
    {
        while(t--)
        {
            cin>>n;
            s=p=x=y=0;
            mem(a,0);
            for(i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
                s^=a[i];
            }
            while(((s>>p)&1)!=1)
            {
                p++;
            }
            for(i=0;i<n;i++)
            {
                if((a[i]>>p)&1==1) x^=a[i];
                else y^=a[i];
            }
            printf("%d %d\n",min(x,y),max(x,y));
        }
    }
    return 0;
}