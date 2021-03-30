from sys import stdin, stdout
from bisect import bisect_left,bisect_right
from math import ceil
from copy import deepcopy
from collections import deque

for test in range(int(stdin.readline())):
    n = int(stdin.readline())
    voca = []
    doco = {}
    for i in range(n):
        ar = list(map(int,stdin.readline().split()))
        voca.append(sorted(ar[1:]))
        for j in voca[-1]:
            if abs(j) in doco:
                doco[abs(j)] += 1
            else:
                doco[abs(j)] = 1
    asdfe = 0
    for i in doco.values():
        if i > 1:
            asdfe += 1
    for i in range(n):
        '''
                sdsdf = {}
                for j in range(len(voca[i]) - 1 , -1,-1):
                    sdsdf[voca[i][j]] = i
                dub = {}
                for j in range(len(voca[i])):
                    dub[voca[i][j]] = i
        '''

        for j in range(len(voca[i])):
            if doco[abs(voca[i][j])] <= 1:
                if voca[i][j] > 0:
                    asdfe += bisect_left(voca[i],(-voca[i][j]))
                else:
                    asdfe += len(voca[i]) - bisect_right(voca[i],-voca[i][j])

            else:
                if voca[i][j] > 0:
                    asdfe += len(voca[i]) -(j + 1)
                else:
                    asdfe += j
    print(asdfe)
