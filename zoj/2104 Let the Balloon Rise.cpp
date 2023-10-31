#include <cstdio>
#include <string>
#include <cstring>
#include <map>
using namespace std;
int main()
{
	int n,max;
	char s[16],c[16];
	map<string ,int> a;
	while(~scanf("%d",&n))
	{
		if(n==0) break;
		max=0;
		a.clear();
		while(n--)
		{
			scanf("%s",s);
			a[s]++;
			if(a[s]>max)
			{
				max=a[s];
				strcpy(c,s);
			}
		}
		printf("%s\n",c);
	}
}