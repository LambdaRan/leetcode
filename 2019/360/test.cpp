import sys
import math
lines = sys.stdin.readlines()
n = int(lines[0].strip())
a = list(map(int, lines[1].strip().split(" ")))
def pan(n,a):
    if n<3 or len(a)<3:
        return -1
    elif n==3 or len(a)==3:
        return "3"
    else:
        for i in range(3, len(a) + 1):
            lin = a[:i]
            lin.sort(reverse=False)
            side1 = lin[0]
            side2 = lin[1]
            side3 = lin[-1]
            if (side1 + side2 > side3) and (side2 + side3 > side1) and (side3 + side1 > side2):
                return i
            elif len(a)>3:
                for j in lin[2:-1]:
                    side1+=j
                    side=[side1,side2,side3]
                    side.sort(reverse=False)
                    side1 = side[0]
                    side2 = side[1]
                    side3 = side[-1]
                    if (side1+side2>side3)and(side2+side3>side1)and(side3+side1>side2):
                        return i
                    else:
                        continue
                else:
                    continue
        return -1
print(pan(n,a))