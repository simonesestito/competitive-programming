from math import gcd

n, m = [ int(i) for i in input().split() ]

known = 360 # Full circle
for i in [ int(i) for i in input().split() ]:
    known = gcd(known, i)

print(*[ 
        'NO' if int(i) % known else 'YES'
        for i in input().split()
    ], sep='\n')