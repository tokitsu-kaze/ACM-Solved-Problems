#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
const int INF=1e9+7;
const long long mod=1e9+7;
int a[MAXN][MAXN],n,m,col[MAXN],cntc[MAXN],cntr[MAXN],row[MAXN];
int x;
int main()
{
    scanf("%d %d",&n,&m);
    swap(n,m);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=1;i<=n;++i)
    {
        row[i]=0;
        for(int j=1;j<=m;++j)
        {
            if(row[i]<a[i][j])
            {
                row[i]=a[i][j];
                cntr[i]=1;
            }
            else if(row[i]==a[i][j])
            {
                cntr[i]++;
            }
        }
    }
    for(int j=1;j<=m;++j)
    {
        col[j]=INF;
        for(int i=1;i<=n;++i)
        {
            if(col[j]>a[i][j])
            {
                col[j]=a[i][j];
                cntc[j]=1;
            }
            else if(col[j]==a[i][j])
            {
                cntc[j]++;
            }
        }
    }
    int ansx=0,ansy=0;
/*
    for(int i=1;i<=n;++i)
    {
        cout<<row[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=m;++i)
    {
        cout<<col[i]<<" ";
    }
    cout<<endl;
*/
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(cntr[i]==1&&cntc[j]==1&&row[i]==a[i][j]&&col[j]==a[i][j])
            {
                ansx=i;
                ansy=j;
                goto endd;
            }
        }
    }
    endd:;
    printf("%d %d\n",ansx,ansy);

    return 0;
}

