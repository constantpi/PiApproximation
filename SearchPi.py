import math
import decimal
import itertools

decimal.getcontext().prec = 300
def check(n):
    m=decimal.Decimal(n-1)
    # print(type(m),m)
    if(m>0):
        x=int(m**decimal.Decimal(.5))
        if(m==x**2):
            return x
    return -1
    


ans=5+1j
ans**=4
ans*=237-1j
ans*=32807+1j
ans*=207137+1j
ans*=1279591682-1j
print(ans)
m=8473902840964684868464684654148904289042398042890384903894065484284893245809348509380528980324890890324890890423890
n=m**2+1
print(check(n),m)

sosu=[5,13,17,61,89]
ans=[]
sosu=list(map(int,input().split()))
saidai=1
sisu_jogen=10
for s in sosu:
    saidai*=s
print(len(str(saidai**10)))
for sisu in itertools.product(range(0,sisu_jogen),repeat=len(sosu)):
    kazu=1
    for i in range(len(sosu)):
        kazu*=sosu[i]**sisu[i]
    result=check(kazu)
    if(result>0):
        print(sisu,"×1",result)
        ans.append(result)
    
    result=check(kazu*2)
    if(result>0):
        print(sisu,"×2",result)
        ans.append(result)

ans.sort()
print(ans)