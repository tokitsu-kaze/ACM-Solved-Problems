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
using namespace std;
typedef long long ll;
char heng[]="xxxxx.";
char zuo[]="x.....";
char you[]="....x.";
char dou[]="x...x.";
char a[1001],b[1001],cc[1001],dd[1001],ee[1001],f[1001],g[1001];
void judge(int i,int z)
{
	if(z=='0')
	{
		strcpy((a+6*i),heng);
		strcpy((b+6*i),dou);
		strcpy((cc+6*i),dou);
		strcpy((dd+6*i),dou);
		strcpy((ee+6*i),dou);
		strcpy((f+6*i),dou);
		strcpy((g+6*i),heng);
	}
	if(z=='1')
	{
		strcpy((a+6*i),you);
		strcpy((b+6*i),you);
		strcpy((cc+6*i),you);
		strcpy((dd+6*i),you);
		strcpy((ee+6*i),you);
		strcpy((f+6*i),you);
		strcpy((g+6*i),you);
	}
	if (z=='2')
	{
		strcpy((a+6*i),heng);
		strcpy((b+6*i),you);
		strcpy((cc+6*i),you);
		strcpy((dd+6*i),heng);
		strcpy((ee+6*i),zuo);
		strcpy((f+6*i),zuo);
		strcpy((g+6*i),heng);
	}
	if (z=='3')
	{
		strcpy((a+6*i),heng);
		strcpy((b+6*i),you);
		strcpy((cc+6*i),you);
		strcpy((dd+6*i),heng);
		strcpy((ee+6*i),you);
		strcpy((f+6*i),you);
		strcpy((g+6*i),heng);
	}
	if (z=='4')
	{

		strcpy((a+6*i),dou);
		strcpy((b+6*i),dou);
		strcpy((cc+6*i),dou);
		strcpy((dd+6*i),heng);
		strcpy((ee+6*i),you);
		strcpy((f+6*i),you);
		strcpy((g+6*i),you);
	}
	if (z=='5')
	{

		strcpy((a+6*i),heng);
		strcpy((b+6*i),zuo);
		strcpy((cc+6*i),zuo);
		strcpy((dd+6*i),heng);
		strcpy((ee+6*i),you);
		strcpy((f+6*i),you);
		strcpy((g+6*i),heng);
	}
	if (z=='6')
	{
		strcpy((a+6*i),heng);
		strcpy((b+6*i),zuo);
		strcpy((cc+6*i),zuo);
		strcpy((dd+6*i),heng);
		strcpy((ee+6*i),dou);
		strcpy((f+6*i),dou);
		strcpy((g+6*i),heng);
	}
	if (z=='7')
	{
		strcpy((a+6*i),heng);
		strcpy((b+6*i),you);
		strcpy((cc+6*i),you);
		strcpy((dd+6*i),you);
		strcpy((ee+6*i),you);
		strcpy((f+6*i),you);
		strcpy((g+6*i),you);
	}
	if (z=='8')
	{
		strcpy((a+6*i),heng);
		strcpy((b+6*i),dou);
		strcpy((cc+6*i),dou);
		strcpy((dd+6*i),heng);
		strcpy((ee+6*i),dou);
		strcpy((f+6*i),dou);
		strcpy((g+6*i),heng);
	}
	if (z=='9')
	{

		strcpy((a+6*i),heng);
		strcpy((b+6*i),dou);
		strcpy((cc+6*i),dou);
		strcpy((dd+6*i),heng);
		strcpy((ee+6*i),you);
		strcpy((f+6*i),you);
		strcpy((g+6*i),heng);
	}
}
int main()
{
	int i,q,k,t1,t2,flag,len;
	ll sum;
	char a1[201],a2[201],a3[201],a4[201],a5[201],a6[201],a7[201];
	char b1[201],b2[201],b3[201],b4[201],b5[201],b6[201],b7[201];
	char c[201],d[201],e[201],n[201];
	while(cin>>a1+1>>a2+1>>a3+1>>a4+1>>a5+1>>a6+1>>a7+1)
	{
		k=0;
		for(i=0,q=1;i<=strlen(a1+1)+6;i++)
		{ 
			b1[q]=a1[i];
			b2[q]=a2[i];
			b3[q]=a3[i];
			b4[q]=a4[i];
			b5[q]=a5[i];
			b6[q]=a6[i];
			b7[q]=a7[i];
			if(i%6==0)
			{
				q=0;
				if(b2[1]=='.'&&b2[5]=='x'&&b4[3]=='.'&&b6[1]=='.'&&b6[5]=='x'&&b1[2]=='.') c[k++]='1';
				else if(b2[1]=='.'&&b2[5]=='x'&&b4[3]=='x'&&b6[1]=='x'&&b6[5]=='.') c[k++]='2';
				else if (b2[1]=='.'&&b2[5]=='x'&&b4[3]=='x'&&b6[1]=='.'&&b6[5]=='x') c[k++]='3';
				else if (b2[1]=='x'&&b2[5]=='x'&&b4[3]=='x'&&b6[1]=='.'&&b6[5]=='x'&&b1[2]=='.') c[k++]='4';
				else if (b2[1]=='x'&&b2[5]=='.'&&b4[3]=='x'&&b6[1]=='.'&&b6[5]=='x') c[k++]='5';
				else if (b2[1]=='x'&&b2[5]=='.'&&b4[3]=='x'&&b6[1]=='x'&&b6[5]=='x') c[k++]='6';
				else if (b2[1]=='.'&&b2[5]=='x'&&b4[3]=='.'&&b6[1]=='.'&&b6[5]=='x') c[k++]='7';
				else if (b2[1]=='x'&&b2[5]=='x'&&b4[3]=='x'&&b6[1]=='x'&&b6[5] =='x') c[k++]='8';
				else if (b2[1]=='x'&&b2[5]=='x'&&b4[3]=='x'&&b6[1]=='.'&&b6[5]=='x') c[k++]='9';
				else if (b2[1]=='x'&&b2[5]=='x'&&b4[3]=='.'&&b6[1]=='x'&&b6[5]=='x') c[k++]='0';
				else c[k++]='+';
			}
			q++;
		}
	//	cout<<c<<endl;
		flag=t1=t2=0;
		mem(d,0);
		mem(e,0);
		for(i=1;i<k;i++)
		{
			if(c[i]!='+'&&flag==0) d[t1++]=c[i];
			else if(c[i]=='+')
			{	
				flag=1;
				i++;
			}
			if(flag==1) e[t2++] = c[i];
		}
		mem(a,0);
		mem(b,0);
		mem(cc,0);
		mem(dd,0);
		mem(ee,0);
		mem(f,0);
		mem(g,0);
		sum=atoi(d)+atoi(e);
		mem(n,0);
		sprintf(n,"%lld",sum);
		len=strlen(n);
		for(i=0;i<len;i++)
		{
			judge(i,n[i]);
		}
		a[len*6-1]='\0';
		b[len*6-1]='\0';
		cc[len*6-1]='\0';
		dd[len*6-1]='\0';
		ee[len*6-1]='\0';
		f[len*6-1]='\0';
		g[len*6-1]='\0';
		printf("%s\n%s\n%s\n%s\n%s\n%s\n%s\n",a,b,cc,dd,ee,f,g);
	}
    return 0;
}
