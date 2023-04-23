#include<bits/stdc++.h>
using namespace std;
int i,i0,n,m,k,ans;
vector<pair<int,string>>v,vv;
int main()
{
    scanf("%d %d %d",&n,&m,&k);
    if(4*n*m-2*n-2*m<k)printf("NO\n");
    else
    {
        printf("YES\n");
        if(n==1)
        {
            if(k<=m-1)printf("1\n%d R",k);
            else printf("2\n%d R\n%d L\n",m-1,k-m+1);
            return 0;
        }
        if(m==1)
        {
            if(k<=n-1)printf("1\n%d D",k);
            else printf("2\n%d D\n%d U\n",n-1,k-n+1);
            return 0;
        }
        v.push_back({n-1,"D"});
        v.push_back({m-1,"R"});
        for(int i=m;i>1;i--)
        {
            v.push_back({n-1,"U"});
            v.push_back({n-1,"D"});
            v.push_back({1,"L"});
        }
        for(int i=n;i>1;i--)
        {
            v.push_back({1,"U"});
            v.push_back({m-1,"R"});
            v.push_back({m-1,"L"});
        }
        for(auto x:v)
        {
            if(k>=x.first)
            {
                k-=x.first;
                vv.push_back(x);
            }
            else
            {
                vv.push_back({k,x.second});
                k=0;
            }
            if(!k)break;
        }
        printf("%d\n",vv.size());
        for(auto x:vv)
        {
            cout<<x.first<<" "<<x.second<<endl;
        }
    }
    return 0;
}

