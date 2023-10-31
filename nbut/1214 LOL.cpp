#include stdio.h
#include string.h
int main()
{
	int n,i,x,y;
	char a[101];
	while(~scanf(%d,&n))
	{
		for(i=0,x=0,y=0;in;i++)
		{
			getchar();
			scanf(%c,&a[i]);
			if(a[i]=='A'a[i]=='B'a[i]=='C'a[i]=='D'a[i]=='E') x++;
			else y++;
		}
		if(xy) printf(zeron);
		else if(x==y) printf(samen);
		else printf(enemyn);
	}
	return 0;
}