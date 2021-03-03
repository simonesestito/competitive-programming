def max_prev(trees, elem):
    '''
    Max previous 
    '''
    prevs = [
        t
        for t in trees
        if t[0] < elem
    ]
    return max(
            prevs,
            key=lambda t: (t[1], -t[0]),
            default=None,
        )

def lis(seq):
    trees = []
    for elem in seq:
        prev = max_prev(trees, elem) # (value, cost, root tree)
        if prev is None:
            trees.append((elem, 1, None))
        else:
            trees.append((elem, prev[1]+1, prev))
    
    res = max(trees, key=lambda t: (t[1], -t[0]))
    print(res[1], end=' ')
    res_l = []
    while res is not None:
        res_l.append(res[0])
        res = res[2]
    res_l = list(map(str, res_l))
    print(' '.join(reversed(res_l)))

if __name__ == '__main__':
    l, *seq = input().split()
    l = int(l)
    while l > 0:
        seq = [ int(x) for x in seq ]
        lis(seq)
        l, *seq = input().split()
        l = int(l)