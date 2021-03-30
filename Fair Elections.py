for _ in range(int(input())):
    t=-1
    n,m=map(int,input().split())
    A=list(map(int,input().split()))
    B=list(map(int,input().split()))
    if sum(A)>sum(B):
        t=0
    else :
        while(sum(A)<=sum(B) and t<min(n,m)) :
            A.sort()
            B.sort(reverse=True)
            if A[0]<B[0] :
                t=1 if t==-1 else t+1
                A[0],B[0]=B[0],A[0]
            else: break
    print(t if sum(A)>sum(B) else -1)
