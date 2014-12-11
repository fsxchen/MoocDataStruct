#!/usr/bin/env python
#coding:utf-8

def getDaoShu(A):
    res = []
    try:
        for i in range(0, len(A), 2):
            cx, zx = A[i], A[i+1]
            if cx* zx != 0:
                res.append(str(cx*zx))
                res.append(str(zx-1))
            else:
                if cx == zx:
                    res.append('0')
                    res.append('0')
        return res
    except Exception, e:
        pass


if __name__ == '__main__':
    inputLine = raw_input()
    A = [int(a) for a in inputLine.split(' ')]
    res = getDaoShu(A)
    print " ".join(res)
