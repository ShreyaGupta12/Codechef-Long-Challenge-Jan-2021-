
al=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p']
for _ in range(int(input())):
    w=""
    p=0
    n=int(input())
    A=input()
    for i in range(0,n//4):
        c=A[((4*i)+0):((4*i)+4)]
        p=int(c,2)
        w+=al[p]
    print(w)
