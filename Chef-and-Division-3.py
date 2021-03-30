for _ in range(int(input())):
    N,K,D=  map(int,input().split())
    A=map(int,input().split())
    ans=sum(A)//K
    print(ans if ans<=D else D)
