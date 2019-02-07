import math

a,b,c=map(float,input().split())
c=180-c
print(math.sqrt(a*a+b*b-2*a*b*math.cos(c/180*math.pi)))