#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
int a,b,c;
int main()
{
    while(scanf("%d %d %d",&a,&b,&c)!=EOF)
    {
        if((a&1)&&(b&1)&&(c&1))
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n");
        }
    }
    return 0;
}