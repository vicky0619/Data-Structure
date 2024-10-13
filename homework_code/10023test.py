from decimal import Decimal, getcontext
getcontext().prec = 1000

t = int(input())
for i in range(t):
    input()
    if i:
        print()
    print(int(int(Decimal(input())**Decimal('0.5'))))


