#Aluna: Luísa de Souza Ferreira
# Matrícula: 102026

import socket
import threading
import sys
import os

HOST = '127.0.1.1'
PORT = 2000

dest = (HOST, PORT)

arquivo = ''
nome = ''

udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)



def receber_msgs(receive_thread_stop, udp_socket, nome):
    """ Função que recebe as mensagens do servidor e as exibe na tela. """
    while True:
        try:
            udp_socket.settimeout(3600) #coloquei esse timeout para não ficar esperando a mensagem do servidor para sempre e consegui finalizar o programa quando o usuario digita bye
            msg_serv, serv = udp_socket.recvfrom(1024)
            msg_serv = msg_serv.decode()

            if(msg_serv == 'BYE'):
                udp_socket.close()
                receive_thread_stop.set()
                break
            comando = msg_serv.split(':')[0]

            if(comando == 'INFO'):
                msg_serv = msg_serv.split(':')[1]
                print(msg_serv)
            
            elif(comando == 'MSG'):
                comando, remetente, conteudo = msg_serv.split(':')
                conteudo = conteudo.split('\n')[0]
                print(f'{remetente} disse: {conteudo}')
            
            elif(comando == 'FILE'):
                if msg_serv.split(':')[1] == 'ERRO':
                    print('Erro no recebimento de arquivo: nome inválido')
                else:   
                    nome_arquivo = msg_serv.split(':')[1]
                    tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
                    tcp.connect(dest)
                    with open(nome + '/' + nome_arquivo, 'wb') as file: #armazeno o arquivo recebido pelo servidor com o tcp, no diretório do cliente
                        print('Recebendo ' + nome_arquivo)
                        pacote = tcp.recv(1024)
                        while pacote:
                            file.write(pacote)
                            pacote = tcp.recv(1024)
                    tcp.close()
                    print(nome_arquivo + ' recebido')
                    nome_arquivo = ''
            else:
                print(msg_serv)
        except:
            # Caso ocorra algum erro na recepção da mensagem
            break


print("Caso deseja sair da conexão digite 'bye'")
nome_user = False
msg = input("Nome de usuário: ")

receive_thread_stop = threading.Event()

while True:
    if receive_thread_stop.is_set():
        receive_thread.join()
    
    if not nome_user:
        udp.sendto(("USER:" + msg).encode(), dest)
        nome_user = True
        nome = msg
        if not os.path.exists(nome): #criar o diretório do cliente
            os.makedirs(nome)
    
    else:
        if(msg == "/list"):
            udp.sendto(("LIST").encode(), dest)
        
        elif(msg.startswith("/file ")):
            comando, nome_arquivo = msg.split(' ')

            if not os.path.isfile(nome_arquivo):
                print('ERRO: arquivo pedido não existe. Tente novamente.')
                continue

            msg = msg.replace('/file ', 'FILE:', 1)
            udp.sendto(msg.encode(), dest)
            tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            tcp.connect(dest)
            with open(nome_arquivo, 'rb') as file:
                pacote = file.read(1024)
                while pacote:
                    tcp.send(pacote)
                    pacote = file.read(1024)
            tcp.close()
            print('Terminou de enviar ' + nome_arquivo)

        elif(msg.startswith("/get ")):
            comando, nome_arquivo = msg.split(' ')
            nome_arquivo = nome_arquivo
            msg = msg.replace('/get ', 'GET:', 1)
            udp.sendto(msg.encode(), dest)

        elif(msg == "bye"):
            udp.sendto(('BYE').encode(), dest)
            receive_thread_stop.set()  # Define a flag para encerrar a thread
            udp.close()  # fecha a conexão UDP
            break

        else:
            udp.sendto((f'MSG:{msg}\n').encode(), dest)

    receive_thread = threading.Thread(target=receber_msgs, args=(receive_thread_stop, udp,nome)) #cria a thread para receber as mensagens do servidor, para o cliente estar sempre disponível para receber msgs do servidor
    receive_thread.start()
    msg = input()
