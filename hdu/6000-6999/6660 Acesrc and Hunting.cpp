#include<bits/stdc++.h>
using namespace std;
int T;
int n,m;
bool f;
vector<pair<int,int> >ans,exans;
void go_row(int bg,bool ex)
{
    if(!ex)
    {
        int nowx=bg;
        int nowy=0;
        ans.push_back(make_pair(nowx,nowy));
        for(int i=1;i<m;++i)
        {
            nowx^=1;
            ++nowy;
            ans.push_back(make_pair(nowx,nowy));
        }
        ans.push_back(make_pair(nowx^1,m-3));
        ans.push_back(make_pair(nowx^1,m-1));
        ans.push_back(make_pair(nowx,m-2));
        nowy=m-4;
        while(nowy>=0)
        {
            ans.push_back(make_pair(nowx,nowy));
            nowx^=1;
            --nowy;
        }
    }
    else
    {
        exans.clear();
        int lx=bg;
        if(lx&1)lx^=1;
        int nowx=lx;
        int nowy=0;
        exans.push_back(make_pair(nowx,nowy));
        for(int i=1;i<m;++i)
        {
            nowx^=1;
            ++nowy;
            exans.push_back(make_pair(nowx,nowy));
        }
        nowx=lx+2;
        nowy=m-1;
        if(nowy&1)nowy--;
        while(nowy>=0)
        {
            exans.push_back(make_pair(nowx,nowy));
            nowy-=2;
        }

        nowx=lx;
        nowy=1;
        exans.push_back(make_pair(nowx,nowy));
        for(int i=2;i<m;++i)
        {
            nowx^=1;
            ++nowy;
            exans.push_back(make_pair(nowx,nowy));
        }

        nowx=lx+2;
        nowy=m-1;
        if((nowy&1)==0)nowy--;
        while(nowy>=0)
        {
            exans.push_back(make_pair(nowx,nowy));
            nowy-=2;
        }
        exans.push_back(make_pair(lx+1,0));
        if(bg&1)
        {
            reverse(exans.begin(),exans.end());
        }
        for(auto &i:exans)
        {
            ans.push_back(i);
        }
    }
    return;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        ans.clear();
        scanf("%d %d",&n,&m);
        if(n==1&&m==1)
        {
            printf("YES\n1 1\n");
            continue;
        }
        if(n==1||m==1)
        {
            printf("NO\n");
            continue;
        }
        if(n==2&&m==2)
        {
            printf("NO\n");
            continue;
        }
        f=false;
        if(n>m)
        {
            swap(n,m);
            f=true;
        }
        int cur=0;
        for(int i=0;i<n;i+=2)
        {
            if(i+1<n)
            {
                go_row(i+cur,i+3==n);
                cur^=1;
            }
        }
        printf("YES\n");
        for(auto &i:ans)
        {
            if(f)
            {
                printf("%d %d\n",i.second+1,i.first+1);
            }
            else
            {
                printf("%d %d\n",i.first+1,i.second+1);
            }
        }
    }
    return 0;
}

