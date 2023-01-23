from math import sqrt
from time import time
from igraph import plot
import igraph as ig

def plotarGrafo(arestas, pontos):
    g = ig.Graph()
    g.add_vertices(len(pontos))
    g.vs["name"] = pontos
    edges = []
    for aresta in arestas:
        edges.append((pontos.index(aresta[0]), pontos.index(aresta[1])))
    g.add_edges(edges)
    visual_style = {}
    visual_style["vertex_size"] = 50
    visual_style["vertex_color"] = "pink"
    visual_style["vertex_label"] = g.vs["name"]
    visual_style["layout"] = g.layout_drl()
    visual_style["bbox"] = (3000, 3000)
    visual_style["margin"] = 50
    plot(g,target="teste.png", **visual_style)




def distancia_euclideana(ponto1, ponto2):
    return sqrt((ponto1[0] - ponto2[0]) ** 2 + (ponto1[1] - ponto2[1]) ** 2)

def CombinaCiclos(s1,s2,dist1, dist2):
    menor = 99999999
    valor_1 = True
    arestas = []
    for i in s1:
        for j in s2:
            valor1 = distancia_euclideana(i[0], j[1]) + distancia_euclideana(i[1], j[0]) - distancia_euclideana(i[0], i[1]) - distancia_euclideana(j[0], j[1])
            if(valor1 < menor):
                menor = valor1
                valor_1 = True
                arestas = [i, j]	
            valor2 = distancia_euclideana(i[0], j[0]) + distancia_euclideana(i[1], j[1]) - distancia_euclideana(i[0], i[1]) - distancia_euclideana(j[0], j[1])	
            if(valor2 < menor):
                menor = valor2
                valor_1 = False
                arestas = [i, j]
    if(valor_1):
        s = s1 + s2 
        s.remove((arestas[0][0] , arestas[0][1]))
        s.remove((arestas[1][0] , arestas[1][1]))
        s.append((arestas[0][0] , arestas[1][1]))
        s.append((arestas[0][1] , arestas[1][0]))
    else:
        s = s1 + s2 
        s.remove((arestas[0][0] , arestas[0][1]))
        s.remove((arestas[1][0] , arestas[1][1]))
        s.append((arestas[0][0] , arestas[1][0]))
        s.append((arestas[0][1] , arestas[1][1]))
    dist = dist1 + dist2 + menor
    return s, dist

def DivConqPCV(p, l, r):
    if(r - l <= 2):
        if(r - l == 1):
            distancia = distancia_euclideana(p[l], p[r])
            return [(p[l],p[r]), (p[r],p[l])], 2 * distancia
        if(r - l == 2):
            distancia = distancia_euclideana(p[l], p[l + 1]) + distancia_euclideana(p[l + 1], p[r]) + distancia_euclideana(p[r], p[l])
            return [(p[l],p[l+1]), (p[l+1],p[r]), (p[r],p[l])], distancia
    else:
        m = (l + r) // 2
        s1, dist1 = DivConqPCV(p, l, m)
        s2, dist2 = DivConqPCV(p, m + 1, r)
        s, distS = CombinaCiclos(s1,s2,dist1, dist2)
        return s, distS

pontos = []
f = open("TSP_100.txt", "r")
with open('TSP_100.txt') as f:
    for j, line in enumerate(f):
        if(j == 0): continue
        res = [int(i) for i in  line.split() if i.isdigit()]
        pontos.append((res[0], res[1]))
start = time()
pontos.sort(key=lambda a: a[0])
s, dist = DivConqPCV(pontos, 0, len(pontos) - 1)
s.sort(key=lambda a: a[0][0])
# print("Ciclo Hamiltoniano: ", s)
end = time()
print("Distancia: {:.4f}".format(dist))
print("Tempo: {:.4f}".format(end - start))
for j,i in enumerate(s):
    print("Aresta {}: {} -> {}".format(j, i[0], i[1]))
plotarGrafo(s, pontos)
    


