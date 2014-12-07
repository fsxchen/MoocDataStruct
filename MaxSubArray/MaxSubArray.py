#!/usr/bin/python
#coding:utf-8

def FIND_MAX_CROSSING_SUBARRAY(A, low, mid, high):
    left_Sum = -float("inf")
    Sum = 0
    for i in range(mid, low - 1, -1):
        Sum = Sum + A[i]
        if Sum > left_Sum:
            left_Sum = Sum
            max_left = i

    right_Sum = -float("inf")
    Sum = 0
    max_right = 0
    for j in range(mid + 1, high + 1):
        Sum = Sum + A[j]
        if Sum > right_Sum:
            right_Sum = Sum
            max_right = j
    return max_left, max_right, left_Sum + right_Sum

def FIND_MAXIMUM_SUBARRAY(A, low, high):
    if low == high:
        return (low, high, A[low])
    else:
        mid = int((low + high) / 2)
        left_low, left_high, left_Sum = \
            FIND_MAXIMUM_SUBARRAY(A, low, mid)
        right_low, right_high, right_Sum = \
            FIND_MAXIMUM_SUBARRAY(A, mid + 1, high)
        cross_low, cross_high, cross_Sum = \
            FIND_MAX_CROSSING_SUBARRAY(A, low, mid, high)

        if max([left_Sum, right_Sum, cross_Sum]) == left_Sum:
            return left_low, left_high, left_Sum
        elif max([left_Sum, right_Sum, cross_Sum]) == right_Sum:
            return right_low, right_high, right_Sum
        else:
            return cross_low, cross_high, cross_Sum

if __name__ == '__main__':
    K = input()
    inputLine = raw_input()
    A = [int(a) for a in inputLine.split(' ')]
    A = A[:K]

    res = FIND_MAXIMUM_SUBARRAY(A, 0, K-1)
    if res[2] < 0:
        print 0, A[0], A[K-1]
    else:
        print res[2], A[res[0]], A[res[1]]
