'''
https://open.kattis.com/problems/speedlimit
'''

quant = int(input())

while quant > -1:
    speeds = [
        [ int(x) for x in input().split(' ') ]
        for _ in range(quant)
    ]

    last_hour = 0
    miles = 0

    for mph, hours in speeds:
        miles += mph * (hours - last_hour)
        last_hour = hours

    print(miles, 'miles')
    quant = int(input())
