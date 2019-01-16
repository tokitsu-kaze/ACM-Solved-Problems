#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
char s[100010],ans[100010];
int top;
int main()
{
	int len,i,cnt;
	scanf("%d",&len);
	scanf("%s",s);
	top=0;
	cnt=0;
	for(i=0;i<len;i++)
	{
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='y')
		{
			if(i>0&&s[i]==s[i-1]) cnt++;
			else
			{
				if(cnt>0)
				{
					if(cnt==2&&(s[i-1]=='e'||s[i-1]=='o'))
					{
						ans[top++]=s[i-1];
						ans[top++]=s[i-1];
					}
					else ans[top++]=s[i-1];
				}
				cnt=1;
			}
		}
		else
		{
			if(cnt>0)
			{
				if(cnt==2&&(s[i-1]=='e'||s[i-1]=='o'))
				{
					ans[top++]=s[i-1];
					ans[top++]=s[i-1];
				}
				else ans[top++]=s[i-1];
			}
			ans[top++]=s[i];
			cnt=0;
		}
	}
	i=len;
	if(cnt>0)
	{
		if(cnt==2&&(s[i-1]=='e'||s[i-1]=='o'))
		{
			ans[top++]=s[i-1];
			ans[top++]=s[i-1];
		}
		else ans[top++]=s[i-1];
	}
	ans[top]='\0';
	printf("%s\n",ans);
	return 0;
}