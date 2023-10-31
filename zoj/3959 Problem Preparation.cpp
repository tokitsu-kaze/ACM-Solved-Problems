#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
const int N=100+7,INF=0x3f3f3f3f;
int a[N],vis[2007];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i],vis[1000+a[i]]++;
        sort(a,a+n);
        if(n<10||n>13) puts("No");
        else if(vis[1001]<2) puts("No");
        else
        {
            if(a[0]!=1) puts("No");
            else
            {
                int flag=0;
                for(int i=0;i<n-2;i++)
                    if(a[i+1]-a[i]>2)
                    {
                        flag=1;
                        break;
                    }
                if(flag) puts("No");
                else puts("Yes");
            }
        }
    }
}