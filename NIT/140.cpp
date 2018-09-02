#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cctype>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#define mem(a,b) memset((a),(b),sizeof(a))
#define MP make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const double PI=acos(-1.0);
const double eps=1e-6;
const int MAX=1e5+10;
const ll mod=1e9+7;
int tag;
void change(int &a1,int &a2,int &b1,int &b2,int &c1,int &c2)
{
	int flag=0;
	if(((b1==6&&b1-b2<=1)||(b2==6&&b2-b1<=1))&&c1>=100000)
	{
//		puts("**");
		if(c1-c2>=2&&c1>=100007)
		{
			b1++;
			c1=c2=0;
		}
		else if(c2-c1>=2&&c2>=100007)
		{
			b2++;
			c1=c2=0;
		}
	}
	else
	{
		if(c1>=40&&c2>=40&&c1<50&&c2<50)
		{
			if(c1-c2==2)
			{
				b1++;
				c1=c2=0;
			}
			else if(c2-c1==2)
			{
				b2++;
				c1=c2=0;
			}
			else if(c1-c2==1) flag=1;
			else if(c2-c1==1) flag=2;
			else if(c1==c2) c1=c2=40;
		}
		else if(c1>40&&c1<50&&c2<50)
		{
			if(c2<40)
			{
				b1++;
				c1=c2=0;
			}
		}
		else if(c2>40&&c1<50&&c2<50)
		{
			if(c1<40)
			{
				b2++;
				c1=c2=0;
			}
		}
	}
	if((b1-b2>=2&&b1==6)||b1==7)
	{
		a1++;
		b1=b2=0;
	}
	else if((b2-b1>=2&&b2==6)||b2==7)
	{
		a2++;
		b1=b2=0;
	}
	if(b1==b2&&b1==6)
	{
		if(c1==c2&&c1==0) c1=c2=100000;
	}
	if(tag) puts("game over!");
	else
	{
		printf("%d:%d %d:%d",a1,a2,b1,b2);
		if(flag==1) printf(" AD:40\n");
		else if(flag==2) printf(" 40:AD\n");
		else
		{
			if(c1>=100000) printf(" %d:%d\n",c1%100000,c2%100000);
			else printf(" %d:%d\n",c1,c2);
		}
	}
	if(a1==2&&!tag)
	{
		tag=1;
		puts("XX win!");
		return ;
	}
	else if(a2==2&&!tag)
	{
		tag=1;
		puts("ZZ win!");
		return ;
	}
	
}
int main()
{
	int a1,a2,b1,b2,c1,c2,t,i,ad;
	char temp[111];
	while(~scanf("%d:%d %d:%d %s",&a1,&a2,&b1,&b2,temp))
	{
		tag=0;
		ad=0;
		for(i=0;i<strlen(temp);i++)
		{
			if(temp[i]=='A')
			{
				if(i==0)
				{
					c1=41;
					c2=40;
				}
				else
				{
					c1=40;
					c2=41;
				}
				ad=1;
				break;
			}
		}
		if(!ad)
		{
			sscanf(temp,"%d:%d",&c1,&c2);
	//		cout<<c1<<" "<<c2<<endl;
		}
		if(b1==b2&&b1==6)
		{
			c1+=100000;
			c2+=100000;
		}
		scanf("%d",&t);
		while(t--)
		{
			scanf("%s",temp);
			if(tag)
			{
				puts("game over!");
				continue;
			}
			if(temp[0]=='X')
			{
				if(b1==b2&&b1==6) c1++;
				else
				{
					if(c1==0) c1=15;
					else if(c1==15) c1=30;
					else if(c1==30) c1=40;
					else c1++;
				}
			}
			else
			{
				if(b1==b2&&b1==6) c2++;
				else
				{
					if(c2==0) c2=15;
					else if(c2==15) c2=30;
					else if(c2==30) c2=40;
					else c2++;
				}
			}
	//		cout<<c1<<" "<<c2<<endl;
			change(a1,a2,b1,b2,c1,c2);
		}
		
	}
	return 0;
}