import networkx as nx
import matplotlib.pyplot as plt
import random
import copy

#-------------------------------------------------------------------------------
    # ftiaxnw grafhma tokswn

G = nx.DiGraph() # arxikopoiw Directional Graph (tokswn)
V = [1,2,3,4,5,6,7,8,9]
U = [(4,1),(4,9),(3,8),(2,6),(2,9),(1,8),(8,7),(9,8),(7,5),(6,1),(6,8),(8,5)]

G.add_nodes_from(V)
G.add_edges_from(U)

#-------------------------------------------------------------------------------
    # Se ayto to block tha prospathisw na ftiaksw topologikh diataksh

if(nx.is_directed_acyclic_graph(G)):

    nodes = copy.deepcopy(V) # make a copy list with the numbers of nodes
    random.shuffle(nodes)
    topological_list = []

    # print(nodes)
    while nodes:
        for i in nodes:
            if G.in_degree(i) == 0:
                topological_list.append(i)
                G.remove_node(i)
                nodes.remove(i)
                break
        # print(nodes)

    print("The topological list of the graph you entered is:")
    print(topological_list)

else:
    print("contains a cycle")
