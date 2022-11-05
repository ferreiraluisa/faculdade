# qlearningAgents.py
# ------------------
# Licensing Information:  You are free to use or extend these projects for
# educational purposes provided that (1) you do not distribute or publish
# solutions, (2) you retain this notice, and (3) you provide clear
# attribution to UC Berkeley, including a link to http://ai.berkeley.edu.
# 
# Attribution Information: The Pacman AI projects were developed at UC Berkeley.
# The core projects and autograders were primarily created by John DeNero
# (denero@cs.berkeley.edu) and Dan Klein (klein@cs.berkeley.edu).
# Student side autograding was added by Brad Miller, Nick Hay, and
# Pieter Abbeel (pabbeel@cs.berkeley.edu).

#Luísa de Souza Ferreira - 102026
#Para fazer esse trabalho vi esses vídeos como referência: https://www.youtube.com/watch?v=3T5eCou2erg, https://www.youtube.com/watch?v=bHeeaXgqVig&t=608s, https://www.youtube.com/watch?v=1XRahNzA5bE e https://www.youtube.com/watch?v=XrxgdpduWOU. Basicamente, eles explicam o q-learning
#Passo 03 - RESPOSTA: Não é possível. Como o número de episódios é pequeno para o tamanho da rede, eu imaginei que o melhor caso para que o agente aprenda a melhor política seria quando o epsilon é 1, ou seja, ele vai sempre escolher caminhos aleatórios* isso faz com que tenha mais chance de ele percorrer pela rede ao em vez de cair num "loop" e quando a taxa de aprendizagem for alta, mas fiz os testes da taxa de aprendizagem para vários valores e em nenhum desses casos ele encontrou a política ótima, por isso digo que não é possível.
#*na função getAction, com uma probabilidade epsilon ele escolhe uma ação aleatória e com uma probabilidade 1-epsilon ele escolhe a melhor ação. Logo se a epsilon é 1, ele sempre vai escolher a ação aleatória.
from asyncio.windows_events import NULL
from game import *
from learningAgents import ReinforcementAgent
from featureExtractors import *

import random,util,math
from mdp import MarkovDecisionProcess

class QLearningAgent(ReinforcementAgent):
    """
      Q-Learning Agent

      Functions you should fill in:
        - computeValueFromQValues
        - computeActionFromQValues
        - getQValue
        - getAction
        - update

      Instance variables you have access to
        - self.epsilon (exploration prob)
        - self.alpha (learning rate)
        - self.discount (discount rate)

      Functions you should use
        - self.getLegalActions(state)
          which returns legal actions for a state
    """
    def __init__(self, **args):
        "You can initialize Q-values here..."
        ReinforcementAgent.__init__(self, **args)

        "**** YOUR CODE HERE ****"
        self.qValue = util.Counter() #usei o Counter que tava disponível no arquivo util.py porque a chave dele são dois parametros, já que para armazenar o qValue levamos em conta a açãoe o estado, e porque todas as chaves são inicializados com 0.0

    def getQValue(self, state, action):
        """
          Returns Q(state,action)
          Should return 0.0 if we have never seen a state
          or the Q node value otherwise
        """
        
        return self.qValue[state, action]

    def computeValueFromQValues(self, state):
        """
          Returns max_action Q(state,action)
          where the max is over legal actions.  Note that if
          there are no legal actions, which is the case at the
          terminal state, you should return a value of 0.0.
        """
        "**** YOUR CODE HERE ****"
        legalActions = self.getLegalActions(state)
        qValues = []
        if not legalActions: #se não tiver nenhum ação possível, que é o caso do estado final, retorna 0
          return 0.0
        for action in legalActions:
          qValues.append(self.getQValue(state, action)) #calcula o qValue de todas as ações possíveis
          
        return max(qValues) #retorna a maior
        

    def computeActionFromQValues(self, state):
        """
          Compute the best action to take in a state.  Note that if there
          are no legal actions, which is the case at the terminal state,
          you should return None.
        """
        legalActions = self.getLegalActions(state)
        if not legalActions: #se não tiver nenhum ação possível, que é o caso do estado final, retorna None
          return None
        for action in legalActions:
          if(self.getQValue(state, action) == self.getValue(state)): #se o qValue da ação for igual ao maior qValue do estado calculado em getValue(), então essa é a melhor ação
            return action
        
        

    def getAction(self, state):
        """
          Compute the action to take in the current state.  With
          probability self.epsilon, we should take a random action and
          take the best policy action otherwise.  Note that if there are
          no legal actions, which is the case at the terminal state, you
          should choose None as the action.

          HINT: You might want to use util.flipCoin(prob)
          HINT: To pick randomly from a list, use random.choice(list)
        """
        # Pick Action
        legalActions = self.getLegalActions(state)
        if not legalActions: #se não tiver nenhuma ação possível, que é o caso do estado final, retorna None
          return None
        if util.flipCoin(self.epsilon): # se a probabilidade for epsilon, então a escolha é aleatória
          action = random.choice(legalActions)
        else: #se a probabilidade for 1 - epsilon, então escolhe a melhor ação
          action = self.getPolicy(state)
        return action 
        

    def update(self, state, action, nextState, reward):
        """
          The parent class calls this to observe a
          state = action => nextState and reward transition.
          You should do your Q-Value update here

          NOTE: You should never call this function,
          it will be called on your behalf
        """
        
        self.qValue[state,action] += self.alpha*(reward + self.discount *(self.getValue(nextState)) - self.getQValue(state, action)) #calcula o qValue, usei a equação que vi nesse vídeo https://www.youtube.com/watch?v=XrxgdpduWOU&t=582s(citei ele como referência no início)
    def getPolicy(self, state):
        return self.computeActionFromQValues(state)

    def getValue(self, state):
        return self.computeValueFromQValues(state)


class PacmanQAgent(QLearningAgent):
    "Exactly the same as QLearningAgent, but with different default parameters"

    def __init__(self, epsilon=0.05,gamma=0.8,alpha=0.2, numTraining=0, **args):
        """
        These default parameters can be changed from the pacman.py command line.
        For example, to change the exploration rate, try:
            python pacman.py -p PacmanQLearningAgent -a epsilon=0.1

        alpha    - learning rate
        epsilon  - exploration rate
        gamma    - discount factor
        numTraining - number of training episodes, i.e. no learning after these many episodes
        """
        args['epsilon'] = epsilon
        args['gamma'] = gamma
        args['alpha'] = alpha
        args['numTraining'] = numTraining
        self.index = 0  # This is always Pacman
        QLearningAgent.__init__(self, **args)

    def getAction(self, state):
        """
        Simply calls the getAction method of QLearningAgent and then
        informs parent of action for Pacman.  Do not change or remove this
        method.
        """
        action = QLearningAgent.getAction(self,state)
        self.doAction(state,action)
        return action


class ApproximateQAgent(PacmanQAgent):
    """
       ApproximateQLearningAgent

       You should only have to overwrite getQValue
       and update.  All other QLearningAgent functions
       should work as is.
    """
    def __init__(self, extractor='IdentityExtractor', **args):
        self.featExtractor = util.lookup(extractor, globals())()
        PacmanQAgent.__init__(self, **args)
        self.weights = util.Counter()

    def getWeights(self):
        return self.weights

    def getQValue(self, state, action):
        """
          Should return Q(state,action) = w * featureVector
          where * is the dotProduct operator
        """
        "*** YOUR CODE HERE ***"
        util.raiseNotDefined()

    def update(self, state, action, nextState, reward):
        """
           Should update your weights based on transition
        """
        "**** YOUR CODE HERE ****"
        util.raiseNotDefined()

    def final(self, state):
        "Called at the end of each game."
        # call the super-class final method
        PacmanQAgent.final(self, state)

        # did we finish training?
        if self.episodesSoFar == self.numTraining:
            # you might want to print your weights here for debugging
            "**** YOUR CODE HERE ****"
            pass
