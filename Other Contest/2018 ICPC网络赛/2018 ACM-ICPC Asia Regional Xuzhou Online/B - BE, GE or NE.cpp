#include<bits/stdc++.h>
const int happyend=1;
const int normalend=2;
const int badend=3;
using namespace std;
int state[1005][1005];
int h(int x)
{
    return x+105;
}
int n,m,k,l,a[1005],b[1005],c[1005];
int main()
{
    while(scanf("%d %d %d %d",&n,&m,&k,&l)!=EOF)
    {
        for(int i=1;i<=n;++i)
        {
            scanf("%d %d %d",&a[i],&b[i],&c[i]);
        }
        for(int i=-100;i<=l;++i)
        {
            state[n+1][h(i)]=badend;
        }
        for(int i=l+1;i<k;++i)
        {
            state[n+1][h(i)]=normalend;
        }
        for(int i=k;i<=100;++i)
        {
            state[n+1][h(i)]=happyend;
        }
        for(int i=n;i;--i)
        {
            if(i&1)
            {
                for(int j=-100;j<=100;++j)
                {
                    state[i][h(j)]=badend;
                    int nexts;
                    if(a[i])
                    {
                        nexts=min(j+a[i],100);
                        state[i][h(j)]=min(state[i][h(j)],state[i+1][h(nexts)]);
                    }
                    if(b[i])
                    {
                        nexts=max(j-b[i],-100);
                        state[i][h(j)]=min(state[i][h(j)],state[i+1][h(nexts)]);
                    }
                    if(c[i])
                    {
                        nexts=-j;
                        state[i][h(j)]=min(state[i][h(j)],state[i+1][h(nexts)]);
                    }
                }
            }
            else
            {
                for(int j=-100;j<=100;++j)
                {
                    state[i][h(j)]=happyend;
                    int nexts;
                    if(a[i])
                    {
                        nexts=min(j+a[i],100);
                        state[i][h(j)]=max(state[i][h(j)],state[i+1][h(nexts)]);
                    }
                    if(b[i])
                    {
                        nexts=max(j-b[i],-100);
                        state[i][h(j)]=max(state[i][h(j)],state[i+1][h(nexts)]);
                    }
                    if(c[i])
                    {
                        nexts=-j;
                        state[i][h(j)]=max(state[i][h(j)],state[i+1][h(nexts)]);
                    }
                }
            }
        }
        if(state[1][h(m)]==1)
        {
            printf("Good Ending\n");
        }
        else if(state[1][h(m)]==2)
        {
            printf("Normal Ending\n");
        }
        else
        {
            printf("Bad Ending\n");
        }
    }
    return 0;
}