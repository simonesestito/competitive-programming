'''
https://open.kattis.com/problems/narrowartgallery
'''

def debug_print(*args):
    # print(*args) # Uncomment to print debug info
    pass

class Node:
    '''
    Node class
    They should be considered different even if the weight is the same
    '''

    def __init__(self, weight):
        if type(weight) == str:
            weight = int(weight)
        self.weight = weight
        self.linked = []
    
    def __str__(self):
        others = ', '.join([ str(node.weight) for node in self.linked ])
        return f'{self.weight} -> {others}'

class Route:
    '''
    An immutable possible route
    '''

    def __init__(self, tot_weight: int, nodes: list):
        self.tot_weight = tot_weight
        self.nodes = nodes

    def __str__(self):
        path = '-'.join([ str(node.weight) for node in self.nodes ])
        return f'(W: {self.tot_weight}, N: {len(self.nodes)}) {path}'

    def add_node(self, node: Node):
        return Route(self.tot_weight + node.weight, self.nodes + [ node ])


def find_route(from_node: Node, to_nodes: list, steps: int):
    routes = [ Route(from_node.weight, [ from_node ]) ]
    completed_routes = []

    while len(routes) > 0:
        route_candidate = max(routes, key=lambda r: r.tot_weight)
        node_candidate = route_candidate.nodes[-1]

        # Remove the current route
        routes.remove(route_candidate)

        debug_print('\n\nCorrente:')
        debug_print(route_candidate)

        if len(route_candidate.nodes) < steps:
            # Add another step
            for node in node_candidate.linked:
                if node not in route_candidate.nodes:
                    new_route = route_candidate.add_node(node)
                    routes.append(new_route)
                    debug_print(' ', new_route)
        elif node_candidate in to_nodes:
            # Number of steps is ok and a destination node has been reached
            completed_routes.append(route_candidate)
        
    return completed_routes
            

# INPUT
rows_no, to_close = ( int(x) for x in input().split() )

# First row
node_begin_1, node_begin_2 = ( Node(x) for x in input().split() )
# Link them each other
node_begin_1.linked.append(node_begin_2)
node_begin_2.linked.append(node_begin_1)

# Keep a reference to the lastest inserted nodes
# It's going to be used in next inputs
last_node_1, last_node_2 = node_begin_1, node_begin_2

for _ in range(rows_no - 1): # - 1 => first line already read
    new_node_1, new_node_2 = ( Node(x) for x in input().split() )
    # Link new nodes
    new_node_1.linked += [ new_node_2, last_node_1 ]
    new_node_2.linked += [ new_node_1, last_node_2 ]
    last_node_1.linked.append(new_node_1)
    last_node_2.linked.append(new_node_2)

    last_node_1, last_node_2 = new_node_1, new_node_2

necessary_steps = 2 * rows_no - to_close

# We need to connect node_begin_1/2 to last_node_1/2,
# having the max total weight,
# in exactly "necessary_steps" amount of steps

debug_print(node_begin_2)

routes = [
    *find_route(node_begin_1, [ last_node_1, last_node_2 ], necessary_steps),
    *find_route(node_begin_2, [ last_node_1, last_node_2 ], necessary_steps),
]

print(max([ r.tot_weight for r in routes ]))