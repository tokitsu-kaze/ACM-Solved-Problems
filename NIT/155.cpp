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
#define mem(a,b) memset(a,b,sizeof(a))
#define pi acos(-1.0) 
using namespace std;
typedef long long ll;
int main()
{
	ll t,n,i,j,l,num[21],x,y,k,flag,sum,s[21],f;
	char a[31],b[21],c[21],d[21];
	map<char,int> m;
	while(cin>>t)
	{
		for(l=1;l<=t;l++)
		{
			scanf("%lld",&n);
			mem(b,0);
			for(j=0;j<n;j++)
			{
				m.clear();
				scanf("%s",a);
				for(i=0;i<strlen(a);i++)
				{
					m[a[i]]=1;
				}
				if(m['a']&&m['b']&&m['g']&&m['o']&&m['p']&&m['c']&&m['h']&&m['l']&&m['m']&&m['n']) b[j]='8';
				else if(m['a']&&m['b']&&m['c']&&m['g']&&m['o']&&m['p']&&m['l']&&m['m']&&m['n']) b[j]='9';
				else if(m['a']&&m['b']&&m['c']&&m['o']&&m['p']&&m['l']&&m['m']&&m['n']&&m['h']) b[j]='6';
				else if(m['a']&&m['b']&&m['g']&&m['l']&&m['m']&&m['n']&&m['c']&&m['h']) b[j]='0';
				else if(m['a']&&m['b']&&m['g']&&m['p']&&m['o']&&m['h']&&m['m']&&m['n']) b[j]='2';
				else if(m['a']&&m['b']&&m['g']&&m['p']&&m['o']&&m['l']&&m['m']&&m['n']) b[j]='3';
				else if(m['b']&&m['a']&&m['c']&&m['o']&&m['p']&&m['l']&&m['m']&&m['n']) b[j]='5';
				else if(m['c']&&m['o']&&m['p']&&m['g']&&m['l']) b[j]='4';
				else if(m['d']&&m['k']&&m['f']&&m['i']) b[j]='*';
				else if(m['e']&&m['o']&&m['p']&&m['j']) b[j]='+';
				else if(m['a']&&m['b']&&m['g']) b[j]='7';
				else if(m['l']&&m['g']) b[j]='1';
				else if(m['o']&&m['p']) b[j]='-';
			}
	//		cout<<b<<endl;
			x=k=flag=0;
			y=1;
			mem(c,0);
			mem(d,0);
			for(i=0;i<n;i++)
			{
				if(b[i]=='+'||b[i]=='-'||b[i]=='*')
				{
					d[y++]=b[i];
					flag=1;
					sscanf(c,"%lld",&num[k++]);
					x=0;
					mem(c,0);
				}
				else c[x++]=b[i];
			}
			sscanf(c,"%lld",&num[k++]);
			if(!flag)
			{
				if(n==19&&b[0]!='0') printf("Case %lld: %s\n",l,b);
				else printf("Case %lld: %lld\n",l,num[0]);
				continue;
			}
	//		cout<<num[0]<<endl;
	/*		for(i=0;i<y;i++)
			{
				if(d[i]=='*')
				{
					num[i]*=num[i+1];
					num[i+1]=num[i];
				}
			}
			for(i=0;i<y;i++)
			{
				if(d[i]=='+')
				{
					num[i]+=num[i+1];
					num[i+1]=num[i];
				}
				else if(d[i]=='-')
				{
					num[i]-=num[i+1];
					num[i+1]=num[i];
				}
			}*/
			mem(s,0);
			f=0;
			s[f++]=num[0];
			for(i=1;i<k;i++)
			{
				switch(d[i])
				{
					case '+':s[f++]=num[i];break;
					case '-':s[f++]=-num[i];break;
					case '*':s[f-1]*=num[i];break;
				}
			}
			sum=0;
			for(i=0;i<f;i++)
			{
				sum+=s[i];
			}
			printf("Case %lld: %lld\n",l,sum);
		}
	}
	return 0;
} 