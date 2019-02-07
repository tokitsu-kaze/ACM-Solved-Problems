n,m=map(int,input().split())
mod=1000000007
def pow2(a,b):
	res=1;
	while b>0:
		if b&1:
			res=res*a%mod
		a=a*a%mod
		b=b>>1
	return res
print(pow2(2,n%(mod-1)))