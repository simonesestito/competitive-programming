'''
https://open.kattis.com/problems/symmetricorder
'''

quant = int(input())
cnt = 1

while quant > 0:
    nomi = [ input() for _ in range(quant) ]
    print('SET', cnt)

    for i in range(0, quant, 2):
        print(nomi[i])

    for i in range(quant-1-(quant%2), -1, -2):
        print(nomi[i])

    cnt += 1
    quant = int(input())

