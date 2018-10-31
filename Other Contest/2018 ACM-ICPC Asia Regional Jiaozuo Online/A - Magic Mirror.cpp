#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
char s[MAXN];
int T;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        int l=strlen(s);
        for(int i=0;i<l;++i)
        {
            if(s[i]>='A'&&s[i]<='Z')s[i]^=' ';
        }
        if(strcmp(s,"jessie")==0)
        {
            printf("Good guy!\n");
        }
        else
        {
            printf("Dare you say that again?\n");
        }
    }
    return 0;
}