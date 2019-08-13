#include<bits/stdc++.h>
using namespace std;
const int MAXN=100010;
int T,a[MAXN],b[MAXN],c[MAXN],d[MAXN],la,lb,lc,ld,ansa,ansb,ansc;
char s[MAXN];
bool flag;
int diff(int *a,int la,int *b,int lb,int *c)
{
	int len=max(la,lb);
	for(int i=1;i<=len+2;++i)
	{
		c[i]=0;
	}
	for(int i=la+1;i<=len+2;++i)
	{
		a[i]=0;
	}
	 for(int i=lb+1;i<=len+2;++i)
	{
		b[i]=0;
	}
	reverse(a+1,a+1+la);
	reverse(b+1,b+1+lb);
	for(int i=1;i<=len;++i)
	{
		c[i]+=a[i]-b[i];
		if(i!=len&&c[i]<0)
		{
			c[i]+=10;
			c[i+1]--;
		}
	}
	reverse(a+1,a+1+la);
	reverse(b+1,b+1+lb);
	if(c[len]<0)
	{
		return -1;
	}
	else
	{
		while(len>1&&c[len]==0)--len;
		reverse(c+1,c+1+len);
		return len;
	}
}
int ck(int *a,int la,int *b,int lb)
{
	if(la<lb)return -1;
	for(int i=1;i<=lb;++i)
	{
		if(a[i]!=b[i])return -1;
	}
	for(int i=lb+1;i<=la;++i)
	{
		if(a[i]!=0)return -1;
	}
	return la-lb;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		flag=false;
		scanf("%s",s+1);
		la=strlen(s+1);
		for(int i=1;i<=la;++i)
		{
			a[i]=s[i]-'0';
		}
		scanf("%s",s+1);
		lb=strlen(s+1);
		for(int i=1;i<=lb;++i)
		{
			b[i]=s[i]-'0';
		}
		scanf("%s",s+1);
		lc=strlen(s+1);
		for(int i=1;i<=lc;++i)
		{
			c[i]=s[i]-'0';
		}
		int ml=max(max(la,lb),lc)+2;
		for(int i=lc+1;i<=ml;++i)
		{
			c[i]=0;
		}
		for(int i=la+1;i<=ml;++i)
		{
			a[i]=0;
		}
		for(int i=lb+1;i<=ml;++i)
		{
			b[i]=0;
		}
		ansc=ml-lc;
		lc=ml;

		ld=diff(c,lc,a,lc,d);
		if(ld!=-1)
		{
			int temp=ck(d,ld,b,lb);
			if(temp!=-1)
			{
				printf("%d %d %d\n",lc-la,temp,ansc);
				continue;
			}
		}

		ld=diff(c,lc,a,lc-1,d);
		if(ld!=-1)
		{
			int temp=ck(d,ld,b,lb);
			if(temp!=-1)
			{
				printf("%d %d %d\n",lc-la-1,temp,ansc);
				continue;
			}
		}

		ld=diff(c,lc,b,lc,d);
		if(ld!=-1)
		{
			int temp=ck(d,ld,a,la);
			if(temp!=-1)
			{
				printf("%d %d %d\n",temp,lc-lb,ansc);
				continue;
			}
		}

		ld=diff(c,lc,b,lc-1,d);
		if(ld!=-1)
		{
			int temp=ck(d,ld,a,la);
			if(temp!=-1)
			{
				printf("%d %d %d\n",temp,lc-lb-1,ansc);
				continue;
			}
		}

		printf("-1\n");

	}
	return 0;
}

