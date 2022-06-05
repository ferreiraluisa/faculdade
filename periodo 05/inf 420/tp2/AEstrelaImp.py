# Nome: Luísa de Souza Ferreira
# Matricula: 102026
#Ferramentas para auxilio: https://deniz.co/8-puzzle-solver/
#Nesse link eu usei para fazer testes e comparar qual foram as escolhas de movimento do meu algoritmo e o do site, o do site tem uma eficiência melhor que o do meu porque a profundidade do ramo que ele escolhe da árvore é menor, tentei deixar o meu tão eficiente quanto mas não tive tempo. O resto eu explico ao longo do código.

import time
from Posicao import Posicao
from AEstrela import AEstrela
from QuebraCabeca import QuebraCabeca
from QuebraCabecaImp import QuebraCabecaImp


class AEstrelaImp(AEstrela):
    
    def getSolucao(self, qc):
        funcaoG = 0 #inicio com 0, minha funcao G é o número de vezes que movimentei a peça vazia
        qcCopy = QuebraCabecaImp()
        qcCopy.setTab(qc.getTab())
        posVazioAnterior = qcCopy.getPosVazio()
        posicoes = []

        while funcaoG < 100000: #coloco para fazer no máximo 100000 iterações, para no caso do exemplo sem solução não entrar num loop infinito
            if qcCopy.isOrdenado(): #se está ordenado, não precisa repetir o processo
                break
            qcAnterior = qcCopy.getTab()
            movimentos = qcCopy.getMovePossiveis() 
            vazio = qcCopy.getPosVazio()
            fscore = 9999 #uso a funcao heuristica como a distância Manhattan, então preciso procurar a MENOR função
            funcaoG += 1 #somo 1 a função G porque iremos mudar a posição do vazio

            for movimento in movimentos: #percorro os movimentos para ver todos os movimentos possíveis, em cada iteração eu calculo a função f(funcaoG + funcaoH) e a que for menor de todas até o momento, o tabuleiro passa a ser a melhor escolha para chegar no estado final.
                qcAux = QuebraCabecaImp()
                qcAux.setTab(qcAnterior)
                qcAux.move(vazio.getLinha(), vazio.getColuna(), movimento.getLinha(), movimento.getColuna()) #aqui já temos cada tabuleiro, com a peça vazia já mexida
                f = funcaoG + qcAux.getValor()
                if(f < fscore and not (posVazioAnterior.getLinha() == qcAux.getPosVazio().getLinha() and posVazioAnterior.getColuna() == qcAux.getPosVazio().getColuna())): #a posicao do vazio atual não pode ser igual a penúltima posição do vazio, não faz sentido ele voltar pra um lugar que ele acabou de estar, entra em loop caso isso aconteça
                    fscore = f
                    qcCopy.setTab(qcAux.getTab())
            posVazioAnterior = vazio #essa variavel serve para armazenar a o espaco vazio do penultimo movimento, fiz isso porque em alguns exemplos entrava num loop o espaço vazio ia e depois voltava pro mesmo lugar que estava, isso solucionou esse problema. Isso explica a condicional.
            posicoes.append(qcCopy.getPosVazio())
        if(not qcCopy.isOrdenado()):
            print('Tempo esgotado. Não foi possível chegar no resultado final, possivelmente não há solução para este problema.')
        return posicoes
