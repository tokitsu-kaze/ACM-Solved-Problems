#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <climits>
#include <map>
#include <iomanip>
using namespace std;
struct chat
{
	char a[25];
}chat[10001];
int cmp(const void *a,const void *b)
{
	struct chat *c=(struct chat *)a;
	struct chat *d=(struct chat *)b;
	return strcmp(c->a,d->a)>0?1:-1;
}
int main()
{
	int i,flag,count;
	char b[10010];
	map<string,int> m;
	while(~scanf("%s",chat[0].a))
	{
		count=1;
		m.clear();
/*		for(i=0,flag=0;i<10;i++)
		{
			if(chat[0].a[i]!='-') flag=1;
		}
		if(!flag) break;*/
		gets(b);
		m[chat[0].a]+=strlen(b)-1;
		while(~scanf("%s",chat[count++].a))
		{
			for(i=0,flag=0;i<10;i++)
			{
				if(chat[count-1].a[i]!='-') flag=1;
			}
			if(!flag) break;
			gets(b);
			m[chat[count-1].a]+=strlen(b)-1;
		}
		qsort(chat,count-1,sizeof(chat[0]),cmp);
		printf("%s %d\n",chat[0].a,m[chat[0].a]);
		for(i=1;i<count-1;i++)
		{
			if(strcmp(chat[i].a,chat[i-1].a)==0) continue;
			printf("%s %d\n",chat[i].a,m[chat[i].a]);
		}
		puts("----------");
	}
	return 0;
}