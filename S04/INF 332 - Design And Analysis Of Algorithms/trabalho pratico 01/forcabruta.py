from cmath import sqrt
def distancia_euclideana(ponto1, ponto2):
    return sqrt((ponto1[0] - ponto2[0]) ** 2 + (ponto1[1] - ponto2[1]) ** 2)
def geraPermutacao(vetor, pontos, inicio, tamanho,melhorRota, menor):
    if inicio == tamanho:
        dist = 0.0
        dist +=  distancia_euclideana(pontos[0], pontos[vetor[0]])
        for i in range(tamanho):
            if(i == tamanho - 1):
                dist += distancia_euclideana(pontos[vetor[i]], pontos[vetor[0]])
            dist += distancia_euclideana(pontos[vetor[i]], pontos[vetor[i + 1]])
        if dist < menor:
            menor = dist
            melhorRota = vetor
    else:
        print(inicio, tamanho)
        for i in range(inicio, tamanho + 1):
            vetor[inicio], vetor[i] = vetor[i], vetor[inicio]
            geraPermutacao(vetor, pontos, inicio + 1, tamanho,melhorRota, menor)
            vetor[inicio], vetor[i] = vetor[i], vetor[inicio]


pontos = []
f = open("TSP_10.txt", "r")
with open('TSP_10.txt') as f:
    for j, line in enumerate(f):
        if(j == 0): continue
        res = [int(i) for i in  line.split() if i.isdigit()]
        pontos.append((res[0], res[1]))
melhorRota = []
vetor = []
for i in range(len(pontos)-1):
    vetor.append(i+1)
menor = 999999.9
geraPermutacao(vetor, pontos,0,len(pontos) - 2,melhorRota, menor)


# print('Melhor rota:', end=" ")
# for j, i in enumerate(melhorRota):
#     if(j == 0) print
#     print(i, end=" ")