class Node:
    def __init__(self):
        self.value = 0;
        self.children = [];
        self.nodesNo = 0;
        self.total = 0;
    
    def calculateFields(self):
        if self.nodesNo:
            return
        
        self.nodesNo = 1
        self.total = self.value

        for node in self.children:
            node.calculateFields()
            self.nodesNo += node.nodesNo
            self.total += node.total

    def __str__(self):
        children = '\n'.join([ '  ' + l for c in self.children for l in str(c).split('\n') ])
        if children:
            children = '\n' + children
        return f'V: {self.value}, N: {self.nodesNo}, T: {self.total}{children}'

def solve(root):
    steps = 0

    for child in root.children:
        diff = child.nodesNo - child.total
        steps += abs(diff)
        child.value += diff
        root.value -= diff
        steps += solve(child)
    
    return steps

if __name__ == '__main__':
    n = int(input())
    while n:
        graph = [ Node() for _ in range(n) ]

        for i in range(n):
            _, v, __, *childrenId = [ int(x) for x in input().split() ]
            graph[i].children = [
                graph[childId-1]
                for childId in childrenId
            ]
            graph[i].value = v
        
        for node in graph:
            node.calculateFields()

        for node in graph:
            if node.nodesNo == n:
                print(solve(node))
                break

        n = int(input())