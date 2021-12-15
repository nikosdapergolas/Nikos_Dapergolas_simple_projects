import networkx as nx
import matplotlib.pyplot as plt
import copy
import random

#-------------------------------------------------------------------------------
    # tha prospathisw na kanw ton algorithmo havel hakimi
    # sigkekrimena se auto to block tha kanw ton elegxo
    # gia to an yparxei to grafima ths akolouthias pou tha mou dwsei o xristis

akolouthia = [6,3,3,3,3,3,3]
arxiki_akolouthia = [6,3,3,3,3,3,3]
print("Arxikh akolouthia: " + str(arxiki_akolouthia))

for i in range (len(akolouthia)): # elegxw na dw an ena stixio einai megalytero/iso  apo to mikos ths akolouthias
    if (akolouthia[i] >= len(akolouthia)): # an einai megalitero/iso Tote den yparxei kamia pithanothta na yparxei tetoio graphima
        there_is_a_chance = False # den tha mpei kan sto while
        print("there is no chance that there would be such a graph")
        break
    else:
        there_is_a_chance = True

if(there_is_a_chance == True):
    while (True): #auto to while einai h ylopoihsh tou algorithmou Havel hakimi
        noGraph = False
        akolouthia.sort(reverse=True)
        firstElement = akolouthia[0]
        akolouthia.pop(0)
        for i in range (firstElement):
            akolouthia[i]-= 1

        print("Curent akolouthia: " + str(akolouthia))

        akolouthiaIs0 = False
        stixia = 0
        for i in range(len(akolouthia)):
            if (akolouthia[i] < 0):
                noGraph = True
            stixia += akolouthia[i]


        if (stixia == 0): # Oi synthikes gia na teleiwsei to while loop
            akolouthiaIs0 = True
            break
        elif(noGraph == True):
            break

    if (stixia == 0):
        print("arxiki akolouthia was: " + str(arxiki_akolouthia) + " with length: " + str(len(arxiki_akolouthia)))
        print("There is a Graph with the given sequence")
        graphExists = True
    else:
        print("There is no such graph")
        graphExists = False




#-------------------------------------------------------------------------------
    # edw tha prospathisw na ylopoihsw ton algorithmo tou Havel hakimi anapoda
    # Skopos einai an parw graphExists = True tote na emfanisw to grafima
    # Prepei na thimithw na to kanw na epilegei tyxaia poion komvo tha enwnei kathe fora me allous komvous(pithanon me list.shufle())

    if (graphExists == True):
        G = nx.Graph()
        V = []
        copyOfArxikiAkolouthia = copy.deepcopy(arxiki_akolouthia) # work on a copy of arxiki akolouthia

        for i in range(len(arxiki_akolouthia)): #placing the empty nodes
            V.append(i)
        G.add_nodes_from(V)

        for i in range(len(copyOfArxikiAkolouthia)-1):
            copyOfArxikiAkolouthia, V = zip(*sorted(zip(copyOfArxikiAkolouthia,V),reverse = True))

            copyOfArxikiAkolouthia = list(copyOfArxikiAkolouthia) # the preveous sorting made these 2 lists into a tuple
            V = list(V) # so i am make them lists again

            randomNode = random.randint(0,len(copyOfArxikiAkolouthia)-1) # selecting a random node to connect
            valueOfSelectedNode = copyOfArxikiAkolouthia[randomNode]
            print("Value of selected node = "+ str(valueOfSelectedNode))
            position = V[randomNode]

            connectedEgdes = 0
            node = 0

            print("copyOfArxikiAkolouthia before connection: " + str(copyOfArxikiAkolouthia))

            while(connectedEgdes < valueOfSelectedNode):
                if V[node] != V[randomNode]:
                    G.add_edge(V[randomNode],V[node])
                    print("just connected [" + str(V[randomNode]) + " , " + str(V[node]) + "]")
                    connectedEgdes += 1
                    print("connectedEgdes = " + str(connectedEgdes))
                    copyOfArxikiAkolouthia[node] -= 1
                node += 1

            print("V before popping: " + str(V))
            print("copyOfArxikiAkolouthia before popping: " + str(copyOfArxikiAkolouthia))

            copyOfArxikiAkolouthia.pop(randomNode)
            V.pop(randomNode)


            print("V now is: " + str(V))
            print("copyOfArxikiAkolouthia now is: " + str(copyOfArxikiAkolouthia))



        nx.draw_networkx(G) #gia na mporei na to zwgrafisei

        plt.show() # me authn thn entolh bgainei parathiraki sto terminal pou deixnei to grafima pou eftiaksa
