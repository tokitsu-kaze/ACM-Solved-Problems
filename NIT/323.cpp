#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) x.size()
#define all(x) x.begin(),x.end()
using namespace std;
#define _GLIBCXX_PERMIT_BACKWARD_HASH
#include <ext/hash_map>
using namespace __gnu_cxx;
struct str_hash{size_t operator()(const string& str)const{return __stl_hash_string(str.c_str());}};
typedef long long ll;
typedef unsigned long long ull;
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PDD pair<double,double>
const int INF=0x3f3f3f3f;
const ll LLINF=0x3f3f3f3f3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e6+10;
const ll mod=1e9+7;
/*
ull llrand()
{
	return (
	(((ull)rand()<<24)&0xFF000000ul)|
	(((ull)rand()<<12)&0x00FFF000ul)|
	(((ull)rand()    )&0x00000FFFul));
}
int main()
{
	freopen("in.txt","w",stdout);
	srand(time(0));
	int t=1000,len,i,x;
	printf("%d\n",t);
	puts("0");
	t--;
	while(t>900)
	{
		t--;
		len=rand()%3+1;
		for(i=0;i<len;i++)
		{
			if(!i) x=rand()%8+1;
			else x=rand()%10;
			printf("%d",x);
		}
		puts("");
	}
	while(t>50)
	{
		t--;
		int ng[3];
		ng[0]=rand()%10;
		ng[1]=rand()%10;
		while(ng[1]==ng[0]) ng[1]=rand()%10;
		ng[2]=rand()%10;
		while(ng[2]==ng[0]||ng[2]==ng[1]) ng[2]=rand()%10;
		len=rand()%100+1;
		for(i=0;i<len;i++)
		{
			x=rand()%10;
			while(x==ng[0]||x==ng[1]||x==ng[2]||x==0) x=rand()%10;
			printf("%d",x);
		}
		puts("");
	}
	while(t--)
	{
		len=rand()%100+1;
		for(i=0;i<len;i++)
		{
			if(!i) x=rand()%8+1;
			else x=rand()%10;
			printf("%d",x);
		}
		puts("");
	}
	return 0;
}
*/
struct node
{
	char s[11];
	friend bool operator<(node a,node b)
	{
		if(a.s[0]==b.s[0])
		{
			if(a.s[1]==b.s[1]) return a.s[2]<b.s[2];
			return a.s[1]<b.s[1];
		}
		return a.s[0]<b.s[0];
	}
}a[133];
bool cmp(char a,char b){return a>b;}
int tot;
void init()
{
	int i;
	tot=0;
	for(i=0;i<1000;i+=8)
	{
		sprintf(a[tot++].s,"%03d",i);
		sort(a[tot-1].s,a[tot-1].s+3,cmp);
		a[tot-1].s[3]='\0';
//		puts(a[tot-1].s);
	}
	sort(a,a+tot);
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int t,len,i,j,bit[11],pos,x;
	char s[1111],temp[11],ans[11];
	init();
	scanf("%d",&t);
	while(t--)
	{
		mem(s,0);
		scanf("%s",s);
		mem(bit,0);
		len=strlen(s);
		if(len<=3)
		{
			int res=-1;
			sort(s,s+len);
			do
			{
				x=atoi(s);
				if(x%8==0) res=x;
			}
			while(next_permutation(s,s+len));
			printf("%d\n",res);
			continue;
		}
		for(i=0;i<len;i++)
		{
			bit[s[i]-'0']++;
		}
		if(bit[0]>=3)
		{
			for(i=9;i>=0;i--)
			{
				while(bit[i]>0)
				{
					bit[i]--;
					printf("%d",i);
				}
			}
			puts("");
			continue;
		}
		pos=-1;
		for(i=0;i<tot;i++)
		{
			int tag=0;
			for(j=0;j<3;j++) bit[a[i].s[j]-'0']--;
			for(j=0;j<3;j++)
			{
				if(bit[a[i].s[j]-'0']<0) tag=1;
				bit[a[i].s[j]-'0']++;
			}
			if(!tag)
			{
				pos=i;
				break;
			}
		}
		if(pos==-1)
		{
			puts("-1");
			continue;
		}
		strcpy(temp,a[pos].s);
		sort(temp,temp+3);
		temp[3]='\0';
		for(i=0;i<3;i++) bit[temp[i]-'0']--;
		for(i=9;i>=0;i--)
		{
			while(bit[i]--)
			{
				printf("%d",i);
			}
		}
		do
		{
			x=atoi(temp);
			if(x%8==0) strcpy(ans,temp);
		}
		while(next_permutation(temp,temp+3));
		ans[3]='\0';
		puts(ans);
	} 
	return 0;
}
/*
2
666
1256
*/