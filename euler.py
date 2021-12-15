#--EXPLANATION--
#   This is a program that takes as input from the user a number n,
#   and the program outputs a closed Euler road for the full graph Kn
#   where Kn is a graph that has M nodes, and every node has M-1 edges

import networkx as nx
import matplotlib.pyplot as plt
import copy
import random

n = int(input("Enter a number:")) # Eisodos apo to xristi gia ena plires grafima

print("------------------------------------------------------------------------------")
print("                           -- P R O C E D U R E --")

#-------------------------------------------------------------------------------
    # se auto to block 8a ftiaksw ena plires Graph n komvwn
    # opou n tha dwthei apo ton xristi


Kn = nx.Graph()

for i in range (n):
    Kn.add_node(i)
edges = []
for i in range (n):
    for j in range (n):
        if i < j:
            Kn.add_edge(i,j)
            if (not (([i,j] in edges) or ([j,i] in edges))): # adding the edges to a list
                edges.append([i,j])


#-------------------------------------------------------------------------------
    # se auto to block tha prospathisw na vrw(an yparxei) enan dromo euler

nodes = []
nodesPosition = []
for i in range (n):
    nodesPosition.append(i) # saving the position of each node in a list
    nodes.append(n-1)       # saving the value of each node in a list
#print("nodes = " + str(nodes))

#edgesForEulerRoad = copy.deepcopy(edges)
edgesForEulerRoad = []
eulerRoad = []
#print("edgesForEulerRoad == " + str(edgesForEulerRoad))

if ((n % 2 == 1) and n >= 3):

    start = random.randint(0,n-1) # selecting a random node to start the euler road
    print("start is: " + str(start))

    sumOfNodes = 0
    for i in nodes:
        sumOfNodes += i

    loops = 1
    print("sumOfNodes in the begining = " + str(sumOfNodes))
    eulerRoad.append(start)

    while sumOfNodes != 0:

        if loops == 1:
            firstNode = start
            secondNode = random.choice(nodesPosition)
        else:
            firstNode = secondNode
            while True:
                secondNode = random.choice(nodesPosition)
                print("second node will be chosen in the position: " + str(secondNode))
                if (([firstNode,secondNode] in edgesForEulerRoad) or ([secondNode,firstNode] in edgesForEulerRoad) or (secondNode == firstNode) or (nodes[secondNode] == 0)):
                    continue
                else:
                    break

        nodes[firstNode] -= 1
        nodes[secondNode] -= 1
        eulerRoad.append(secondNode)
        edgesForEulerRoad.append([firstNode,secondNode])

        sumOfNodes = 0
        for i in nodes:
            sumOfNodes+=i


        # if nodes[firstNode] == 0:
        #     nodes.pop(firstNode)
        #     nodesPosition.pop(firstNode)

        print("sumOfNodes = " + str(sumOfNodes))
        print("edgesForEulerRoad = " + str(edgesForEulerRoad))
        print("nodesPosition = " + str(nodesPosition))
        print("nodes =         " + str(nodes))
        print("eulerRoad = " + str(eulerRoad))
        loops += 1

        # if loops == 5:
        #     break

    print("------------------------------------------------------------------------------")
    print("                              --R E S U L T S--")
    print("road has been made!")
    print("Here's the euler road for the K" + str(n) + " Graph")
    print(eulerRoad)
    print("and for even more details, here's exactly the road with each edge sheperately")
    print(edgesForEulerRoad)




else:
    print("------------------------------------------------------------------------------")
    print("                              --R E S U L T S--")
    print("Sorry, this graph has no euler road")

#-------------------------------------------------------------------------------
