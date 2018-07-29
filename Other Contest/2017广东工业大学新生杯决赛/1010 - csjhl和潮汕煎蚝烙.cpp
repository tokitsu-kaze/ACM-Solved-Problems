#include<bits/stdc++.h>
using namespace std;
const double PI=3.14159;
typedef long long ll;
int a[22],ans;
void dfs(int x,int sum)
{
    if(x==5)
    {
        if(sum==24) ans++;
        return ;
    }
    dfs(x+1,sum+a[x]);
    dfs(x+1,sum-a[x]);
}
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        for(i=0;i<5;i++)
        {
            scanf("%d",&a[i]);
        }
        dfs(1,a[0]);
        printf("%d\n",ans);
    }
    return 0;
}
