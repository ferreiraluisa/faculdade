import sys
import math

#Trabalho Prático 01
#Luísa de Souza Ferreira - 102026

my_team_id = int(input())  

if my_team_id == 0: #se for 0, é porque o gol é o da direta que tem o centro com as coordenadas (16000,3750), peguei essas informações nas regras
    goals = [16000, 3750]
else: #se for 1, é porque o gol é o da esquerda que tem o centro com as coordenadas(0,3750)
    goals = [0, 3750]

class Wizard: #classe para os meus players
    def __init__(self, x, y, vx, vy, state):
        self.x = x
        self.y = y
        self.vx = vx
        self.vy = vy
        self.state = state
class Opponent_Wizard: #classe para os meus oponente
    def __init__(self, x, y, vx, vy, state):
        self.x = x
        self.y = y
        self.vx = vx
        self.vy = vy
        self.state = state
class Snaffle: #classe para as snaffle, esse ultimo atributo taken eu que coloquei para controlar que meus dois jogadores não pegassem a mesma snaffle na rodada, ao longo do código eu explico onde uso
    def __init__(self, x, y, vx, vy, state, taken):
        self.x = x
        self.y = y
        self.vx = vx
        self.vy = vy
        self.state = state
        self.taken = taken


def snaffles_near_goals(snaffles): # criei essa função para ver as snaffles que estavam muito próximas ao gol, porque enquanto fui fazendo o trabalho tinham cenários em que tinha uma snaffle perto do jogador longe do gol e 3 que estavam muito perto do gol
    snaffles_near_goal = []
    for snaffle in snaffles: #percorre a lista de snaffles
        if(goals[0] == 0): #as coordenadas para ver se está no gol depende de qual lado eu estou na partida 
            if(snaffle.x < 3500 and snaffle.taken == 0): #se tiver perto do gol e o outro adversário não tiver pego ela na rodada, eu adiciono ela a lista de snaffles disponiveis perto do gol
                snaffles_near_goal.append(snaffle)
        else:
            if(snaffle.x > 12500 and snaffle.taken == 0): 
                snaffles_near_goal.append(snaffle)
    return snaffles_near_goal #retorno uma lista com todas mais próximas do gol

def get_distance(x1, y1, x2, y2): #pegar a distancia entre dois pontos
    return math.sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2))

def nearest_snaffle(snaffles, x_wizard, y_wizard):
    min_distance = float('inf')
    nearest = Snaffle(0,0,0,0,0,0)
    for snaffle  in snaffles:
        if(snaffle.state == 0 and snaffle.taken == 0): #se o opponent não tiver pego nenhuma e nem o meu outro jogador então ela está disponível para ser pega
            distance = get_distance(x_wizard, snaffle.x , y_wizard, snaffle.y) #pego a distancia entre o meu jogador e a snaffle
            if(distance < min_distance): 
                min_distance = distance
                nearest = snaffle 
    for snaffle  in snaffles:
        if(snaffle == nearest):
            snaffle.taken = 1 #qual for a mais próxima do momento, vai ser pega pelo jogador então na rodada meu outro jogador não pode pegá-la, por isso boto taken como 1, significa que na rodada ela já foi pega por um dos meus jogadores
    return nearest
        



# game loop
while True:
    my_score, my_magic = [int(i) for i in input().split()]
    opponent_score, opponent_magic = [int(i) for i in input().split()]
    entities = int(input())  # number of entities still in game
    wizards = []
    count_wizards = 0
    opponent_wizards = []
    count_opponent = 0
    snaffles = []
    count_snaffles = 0
    for i in range(entities): #percepcao do ambiente
        inputs = input().split()
        entity_id = int(inputs[0])  # entity identifier
        entity_type = inputs[1]  # "WIZARD", "OPPONENT_WIZARD" or "SNAFFLE" (or "BLUDGER" after first league)
        if(entity_type == "SNAFFLE"):
            x = int(inputs[2])  # position
            y = int(inputs[3])  # position
            vx = int(inputs[4])  # velocity
            vy = int(inputs[5])  # velocity
            state = int(inputs[6])  # 1 if the snaffle is holding a Snaffle, 0 otherwise
            snaffle = Snaffle( x, y, vx, vy, state, 0 )
            snaffles.append(snaffle)
            count_snaffles += 1
        if(entity_type == "WIZARD"):
            x = int(inputs[2])  # position
            y = int(inputs[3])  # position
            vx = int(inputs[4])  # velocity
            vy = int(inputs[5])  # velocity
            state = int(inputs[6])  # 1 if the snaffle is holding a Snaffle, 0 otherwise
            wizard = Wizard(x, y, vx, vy, state)
            wizards.append(wizard)
            count_wizards += 1
        if(entity_type == "OPPONENT_WIZARD"):
            x = int(inputs[2])  # position
            y = int(inputs[3])  # position
            vx = int(inputs[4])  # velocity
            vy = int(inputs[5])  # velocity
            state = int(inputs[6])  # 1 if the snaffle is holding a Snaffle, 0 otherwise
            opponent_wizard = Opponent_Wizard(x, y, vx, vy, state)
            opponent_wizards.append(opponent_wizard)
            count_opponent += 1
    for wizard in wizards: #acao dos agentes
        if(wizard.state == 1): #se um dos meus jogadores estiver com a snaffle, ele irá jogá-la para o gol
            print('THROW %s %s %s' % (goals[0], goals[1], 500))
        else:
            snaffles_near_goal = snaffles_near_goals(snaffles)
            snaffle = {}
            if(snaffles_near_goal == []): #se não tiver nenhuma bola próxima do gol, o jogador precisa verificar qual snaffle está mais próxima dele
                snaffle = nearest_snaffle(snaffles, wizard.x, wizard.y)
            else: #se tiver snaffles próximas ao gol, o jogador precisa verificar qual delas está mais próxima dele
                snaffle = nearest_snaffle(snaffles_near_goal, wizard.x, wizard.y)
            print('MOVE %s %s %s' % (snaffle.x,snaffle.y, 150)) #irá se mover em direção a snaffle que irá trazer melhor desempenho para equipe
                
    for snaffle in snaffles:
            snaffle.taken == 0 #como uma nova rodada irá começar, todas as snaffles que não estejam com outro jogador oponente(no caso, se state = 1 para snaffle) estarão disponíveis para tentar serem pegar por qualquer um dos meus jogadores
