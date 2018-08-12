#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int N=1000;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int flag=0;
        for(int i=n;i>=0;i--)
        {
            int a;
            scanf("%d",&a);
            if(i==0)
            {
				if(n==0) printf("0");
				break;
			}
            if(a==0)
            {
                if(!flag) printf("0");
                else printf(" 0");
                flag++;
            }
            else
            {
//                printf("a=%d i=%d\n",a,i);
                if(!flag)printf("%d",a*i);
                else printf(" %d",a*i);
                flag++;
            }
        }
        puts("");
    }
}