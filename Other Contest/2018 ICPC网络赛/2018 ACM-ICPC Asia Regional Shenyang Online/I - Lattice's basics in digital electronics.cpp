#include<bits/stdc++.h>
using namespace std;
char mp[4096],s[4096],inputs[400005];
int T,c,n,m,nowcnt,iter,nowpos,temp[15],nowhash;
int hexs(char ch)
{
    if(ch>='0'&&ch<='9')return ch-'0';
    if(ch>='a'&&ch<='f')return ch-'a'+10;
    return ch-'A'+10;
}
int get_bit(int pos)
{
    int b=pos/4;
    pos=pos-b*4;
    return !!(hexs(inputs[b])&(1<<(3-pos)));
}
void debug2(int x)
{
    for(int i=30;~i;--i)
    {
        cout<<!!(x&(1<<i));
    }
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        nowcnt=iter=0;
        memset(mp,0,sizeof(mp));
        scanf("%d %d",&n,&m);
        for(int i=1;i<=m;++i)
        {
            scanf("%d %s",&c,s);
            int keys=1;
            for(int i=0;s[i]!='\0';++i)
            {
                if(s[i]=='0')
                keys=keys<<1;
                else
                keys=(keys<<1)|1;
            }
            mp[keys]=char(c);
        }
        scanf("%s",inputs);
        nowpos=8;
        iter=0;
        nowhash=1;
        while(nowcnt<n)
        {
            if(nowpos==8)
            {
                bool flag=true;
                while(flag)
                {
                    int jy=0;
                    for(int i=0;i<9;++i)
                    {
                        temp[i]=get_bit(iter++);
                        jy^=temp[i];
                    }
                    if(jy==1)flag=false;
                }
                nowpos=0;
            }
            nowhash=(nowhash<<1)|temp[nowpos++];
            if(mp[nowhash])
            {
                printf("%c",mp[nowhash]);
                nowhash=1;
                ++nowcnt;
            }
        }
        printf("\n");
    }
    return 0;
}