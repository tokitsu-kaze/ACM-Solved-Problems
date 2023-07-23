#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int MAX=1e6+10;
ull st[MAX];
int main()
{
	int t,n,i,top;
	ull x;
	char op[11];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		top=0;
		while(n--)
		{
			scanf("%s",op);
			if(op[0]=='p'&&op[1]=='u')
			{
				scanf("%llu",&x);
				st[top++]=x;
			}
			else if(op[0]=='p'&&op[1]=='o')
			{
				if(top) top--;
				else puts("Empty");
			}
			else if(op[0]=='q')
			{
				if(top) printf("%llu\n",st[top-1]);
				else puts("Anguei!");
			}
			else if(op[0]=='s') printf("%d\n",top);
			else assert(0);
		}
	}
	return 0;
}
