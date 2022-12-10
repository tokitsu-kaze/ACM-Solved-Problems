
n,k=map(int,raw_input().split())
v=map(int,raw_input().split())
s=raw_input()
r=[]
w=[]
o=[]

for i in range(0,len(s)):
	if s[i]=='R':
		r.append(v[i])
	if s[i]=='W':
		w.append(v[i])
	if s[i]=='O':
		o.append(v[i])

r.sort(),w.sort(),o.sort()
r.append(0),w.append(0),o.append(0)
r.reverse(),w.reverse(),o.reverse()

for i in range(1,len(r)):
	r[i]+=r[i-1]

for i in range(1,len(w)):
	w[i]+=w[i-1]

for i in range(1,len(o)):
	o[i]+=o[i-1]

ans=-1

for i in range(1,len(o)):
	if i>=k :
		break
	if k-i<len(r):
		ans=max(ans,o[i]+r[k-i])
	if k-i<len(w):
		ans=max(ans,o[i]+w[k-i])
print ans
