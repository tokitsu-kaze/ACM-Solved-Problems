import sys
import random

def gcd(x, y):
    return x if y == 0 else gcd(y, x % y)

def isPrime(n):
    """
    Miller-Rabin primality test.

    A return value of False means n is certainly not prime. A return value of
    True means n is very likely a prime.
    """
    if n!=int(n):
        return False
    n=int(n)
    #Miller-Rabin test for prime
    if n==0 or n==1 or n==4 or n==6 or n==8 or n==9:
        return False
    if n==2 or n==3 or n==5 or n==7:
        return True
    s = 0
    d = n-1
    while d%2==0:
        d>>=1
        s+=1
    assert(2**s * d == n-1)

    def trial_composite(a):
        if pow(a, d, n) == 1:
            return False
        for i in range(s):
            if pow(a, 2**i * d, n) == n-1:
                return False
        return True

    for i in range(20):#number of trials
        a = random.randrange(2, n)
        if trial_composite(a):
            return False

    return True


if __name__=='__main__':
    n=int(input())
    divs=[n]
    while not all([isPrime(x) for x in divs]):
        x=random.randint(1,n-1)
        sys.stdout.write("sqrt %d\n"%(x*x%n))
        sys.stdout.flush()
        x+=int(input())
        tmp=[]
        for it in divs:
            g=gcd(x,it)
            if g!=1:
                tmp.append(g)
            if it//g!=1:
                tmp.append(it//g)
        divs=tmp

    divs=list(set(divs)-{1})
    sys.stdout.write("! %d"%len(divs))
    for it in divs:
        sys.stdout.write(" %d"%it)
    sys.stdout.write("\n")