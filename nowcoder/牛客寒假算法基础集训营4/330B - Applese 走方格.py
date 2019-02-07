def go():
	n,m=map(int,input().split())
	if n==1 and m==2:
		print("RL")
		return
	if n==2 and m==1:
		print("DU")
		return
	if n*m%2==1 or n==1 or m==1:
		print("-1")
		return
	ans=""
	if m%2==0:
		for i in range(n-1):
			ans+="D"
		dir=-1;
		now=n
		for i in range(m-1):
			ans+="R"
			if dir==-1:
				while now>2:
					ans+="U"
					now+=dir
			else:
				while now<n:
					ans+="D"
					now+=dir
			dir*=-1
		ans+="U"
		now=m-1
		while now>=1:
			ans+="L"
			now-=1
	else:
		for i in range(m-1):
			ans+="R"
		dir=-1;
		now=m
		for i in range(n-1):
			ans+="D"
			if dir==-1:
				while now>2:
					ans+="L"
					now+=dir
			else:
				while now<m:
					ans+="R"
					now+=dir
			dir*=-1
		ans+="L"
		now=n-1
		while now>=1:
			ans+="U"
			now-=1
	print(ans)

go()