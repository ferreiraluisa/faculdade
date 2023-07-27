#Aluna: Luísa de Souza Ferreira
# Matrícula: 102026
import socket
import threading
import os


HOST = ''
PORT = 2000

orig = (HOST, PORT)

udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
udp.bind(orig)

tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
tcp.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
tcp.bind(orig)
tcp.listen(1)


clientes_ativos = {}



def servidor_cliente(msg, cliente):
    msg = msg.decode()
    if(msg == 'LIST'):
        clientes = list(clientes_ativos.values())
        update = "Clientes conectados: " + str(clientes)
        udp.sendto(update.encode(), cliente)

    elif(msg == 'BYE'):
        for c in clientes_ativos:
            if(c != cliente):
                update = f"INFO:{clientes_ativos[cliente]} saiu"
                udp.sendto(update.encode(), c)
        udp.sendto("BYE".encode(), cliente)
        del clientes_ativos[cliente]

    else:
        comando, msg = msg.split(':')
        if(comando == 'USER'):
            print(f"Conectado com: {msg}")
            clientes_ativos[cliente] = msg
            for c in clientes_ativos:
                if(c != cliente):
                    update = f"INFO:{clientes_ativos[cliente]} entrou"
                    udp.sendto(update.encode(), c)

        elif(comando == 'MSG'):
            for c in clientes_ativos:
                if(c != cliente):
                    update = f"MSG:{clientes_ativos[cliente]}:{msg}"
                    udp.sendto(update.encode(), c)
        #file e get(transferência de arquivos) usando tcp!
        elif(comando == 'FILE'):
            nome_arquivo = msg.strip()

            con, tcpCli = tcp.accept()
            with open('arquivos/' + nome_arquivo, 'wb') as file:
                print(f'Recebendo {nome_arquivo}  de  {clientes_ativos[cliente]}')
                pacote = con.recv(1024)
                while pacote:
                    file.write(pacote)
                    pacote = con.recv(1024)
            con.close()
            print(f'{nome_arquivo} recebido :)')
            for c in clientes_ativos:
                if(c != cliente):
                    update = f"INFO:{clientes_ativos[cliente]} enviou {nome_arquivo}"
                    udp.sendto(update.encode(), c)

        elif(comando == 'GET'):
            nome_arquivo = msg.strip()
            files = os.listdir('arquivos') #se o servidor não tiver o arquivo, ele envia uma mensagem de erro porque nenhum dos usuários enviou para ele e nem chega a estabelecer uma conexão tcp com o cliente
            if not nome_arquivo in files:
                udp.sendto('FILE:ERRO'.encode(), cliente)
            else:
                udp.sendto((f'FILE:{nome_arquivo}').encode(), cliente)
                con, tcpCli = tcp.accept()
                with open('arquivos/'+nome_arquivo, 'rb') as file: #arquivos é a pasta que o servidor que tem os arquivos que o servidor recebeu dos clientes
                    pacote = file.read(1024)
                    while pacote:
                        con.send(pacote)
                        pacote = file.read(1024)
                con.close()
                print(f'{nome_arquivo} enviado')


print("Aguardando conexão...")
while True:  
    if os.path.isdir('arquivos') == False: #confirmo se existe uma pasta para armazenar os arquivos recebidos pelo servidor
        os.mkdir('arquivos')
    msg, cliente = udp.recvfrom(1024)
    t = threading.Thread(target=servidor_cliente, args=(msg, cliente))
    t.start()
udp.close()