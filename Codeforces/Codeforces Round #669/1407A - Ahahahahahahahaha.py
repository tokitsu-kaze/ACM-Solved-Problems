t=int(input())
while t>0:
    t-=1
    n=int(input())
    a=list(map(int,input().split()))
    cnt0=0
    cnt1=0
    for i in range(n):
        if a[i]==0:
            cnt0+=1
        else:
            cnt1+=1
    if cnt0>=cnt1:
        print(n//2)
        print("0",end="")
        print((n//2-1)*" 0")
    else:
        if (n//2)%2==1:
            print(n//2+1)
            print("1",end="")
            print((n//2)*" 1")
        else:
            print(n//2)
            print("1",end="")
            print((n//2-1)*" 1")
