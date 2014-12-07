#!/usr/bin/env python
#coding:utf-8

def getDaoShu(A):
    try:
        for i in range(0, len(A), 2):
            cx, zx = A[i], A[i+1]
            if cx* zx != 0:
                print cx*zx, zx -1,
    except Exception, e:
        pass


if __name__ == '__main__':
    inputLine = raw_input()
    A = [int(a) for a in inputLine.split(' ')]
    getDaoShu(A)
