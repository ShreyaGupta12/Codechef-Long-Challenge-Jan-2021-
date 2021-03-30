import sys
sys.setrecursionlimit(200000000)
from itertools import accumulate
    
for _ in range(int(input())):
    n,k= map(int,input().split())
    blo= list(map(int,input().split()))
    blo.sort(reverse= True)
    if n==1:
        print(-1)
        continue
    if blo[0]>=k and blo[1]>=k:
        print(2)
        continue
    if blo[0]>=k:
        ans=1
        t = 0
        for i in range(1,n):
            t+=blo[i]
            ans+=1
            if t>=k:
                print(ans)
                break
        if t<k:
            print(-1)
        continue
            
    prefix_blo= list(accumulate(blo))
    dp={}
    def get_an(current=0,total=0):
        z= dp.get((current,total),-1)
        if z!= -1:
            return z
        if current>=n:
            return float('inf')
        elif total>= k and prefix_blo[current] - total >= k :
            return current+1
        elif total >= k:
            v= get_an(current+1,total)
            dp[(current,total)]= v
            return v
        elif prefix_blo[current]- total >= k:
            v= get_an(current+1,total+blo[current])
            dp[(current,total)]= v
            return v
        else:
            v= min(get_an(current+1,total+blo[current]),get_an(current+1,total))
            dp[(current,total)]= v
            return v
        
    ans= get_an()
    if ans == float('inf'):
        print(-1)
    else:
        print(ans)
