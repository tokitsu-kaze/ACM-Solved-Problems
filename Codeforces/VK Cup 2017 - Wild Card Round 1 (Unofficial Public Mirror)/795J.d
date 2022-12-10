import std.stdio;
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	int n,k,i,l,flag,tag,cnt,mx;
	char[111] s,tmp;
	scanf("%d %d ",&n,&k);
	for(i=0;i<n;i++) scanf("%c",&s[i]);
	s[n]='\0';
	flag=0;
	for(l=0;l+k-1<n;l++)
	{
		tag=0;
		for(i=0;i<n;i++) tmp[i]=s[i];
		tmp[n]='\0';
		for(i=0;i<k;i++)
		{
			if(s[l+i]=='?') tmp[l+i]='N';
			else tmp[l+i]=s[l+i];
			if(tmp[l+i]=='Y') tag=1;
		}
		if(tag) continue;
		mx=cnt=0;
		for(i=0;i<n;i++)
		{
			if(tmp[i]=='?') tmp[i]='Y';
			if(tmp[i]=='N') cnt++;
			else cnt=0;
			mx=max(mx,cnt);
		}
		mx=max(mx,cnt);
		if(mx==k)
		{
			flag=1;
			break;
		}
	}
	if(flag) printf("YES\n");
	else printf("NO\n");
	return 0;
}