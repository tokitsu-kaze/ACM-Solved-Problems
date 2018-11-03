#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
char s1[MAXN],s2[MAXN],ins1[MAXN],ins2[MAXN];
int n,T,tot;
int Min(char s[])
{
    int l=strlen(s);
    int p1=0;int p2=1;
    while(p1<l&&p2<l)
    {
        int k=0;
        while(k<l&&s[(p1+k)%l]==s[(p2+k)%l])++k;
        if(k>=l)break;
        if(s[(p1+k)%l]>s[(p2+k)%l])
        {
            p1=p1+k+1;
        }
        else
        {
            p2=p2+k+1;
        }
        if(p1==p2)++p2;
    }
    return p1<p2?p1:p2;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        scanf("%s %s",ins1,ins2);
        tot=0;
        for(int i=0;i<n;++i)
        {
            if(ins1[i]!=ins2[i])
            {
                s1[tot]=ins1[i];
                s2[tot]=ins2[i];
                tot++;
            }
        }
        s1[tot]=s2[tot]='\0';
        bool flag=true;
        for(int i=0;i<tot;++i)
        {
            if(s2[i]!=s1[(i+1)%tot])flag=false;
        }
        if(flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}