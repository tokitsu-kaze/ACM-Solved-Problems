#include <stdio.h>
int main()
{
    int n;
    char a[3],b[3],c;
    while(~scanf("%d",&n))
    {
		while(n--)
		{
			getchar();
			scanf("%c",&c);
			scanf("%s%s",a,b);
			if((a[1]==b[1]&&a[1]==c)||(a[1]!=c&&b[1]!=c))
			{
				if(a[0]=='K'&&b[0]!='K') printf("YES\n");
				else if(a[0]=='Q'&&b[0]!='K'&&b[0]!='Q') printf("YES\n");
				else if(a[0]=='J'&&b[0]!='K'&&b[0]!='Q'&&b[0]!='J') printf("YES\n");
				else if(a[0]>'2'&&a[0]<='9'&&b[0]>'2'&&b[0]<='9'&&a[0]>b[0]) printf("YES\n");
				else if(a[0]=='1'&&b[0]!='K'&&b[0]!='Q'&&b[0]!='J'&&b[0]!='1') printf("YES\n");
				else if(a[0]=='A') printf("NO\n");
				else printf("NO\n");
			}
			else if(a[1]==c&&b[1]!=c) printf("YES\n");
			else if(b[1]==c&&a[1]!=c) printf("NO\n");
		}
    }
    return 0;
}