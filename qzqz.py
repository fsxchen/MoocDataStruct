#!/usr/bin/env python
inputLine = raw_input()
A = inputLine.split(' ')
# A = ["+", "+", "2", "*", "3", "-", "7", "4", "/", "8", "4"]
ls = []
ln = []
sign = {'+':1,'-':1, '*':2, '/':2}
def docal(a, b, sign):
    if sign == '+': return a + b
    elif sign == '-': return a - b
    elif sign == '*': return a * b
    elif sign == '/': return a / float(b)
length = len(A)
for i in range(length):
    value = A[length - i - 1]
    if value in sign.keys():
        try:
            a = ln.pop()
            b = ln.pop()
            ln.append(docal(a, b, value))
        except Exception, e:
            pass
    else:
        try:
            ln.append(float(value))
        except Exception, e:
            print e
            pass
if len(ln) == 1:
    res = ln.pop()
    print "{0:1.1f}".format(res)
else:
    print "ERROR"
