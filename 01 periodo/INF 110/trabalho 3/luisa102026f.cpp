#include <iostream>
#include <cstring>
#include <cctype>
#include <ctime>
#include <locale.h>
using namespace std;

void tudolower(char frase[]){ //para deixar a resposta em minúsculo
    for(int i=0;i<strlen(frase);i++){
        frase[i] = tolower(frase[i]);
    }
}
void pegardia(int diasdomes,int m,int &dia,char nome[]){ //funcao para pegar o dia na string resposta
    int cont = 0;
    char mes[12][100]={{"Janeiro"},{"Fevereiro"},{"Março"},{"Abril"},{"Maio"},{"Junho"},{"Julho"},{"Agosto"},{"Setembro"},{"Outubro"},{"Novembro"},{"Dezembro"}};
    char frase[300],d[20];
    strcpy(d,""); //"limpar" a string dia
    strcpy(frase,""); //"limpar" a string frase
    cout<<nome<<" : ";
    cin.getline(frase,300);
    for(int i=0;i<strlen(frase);i++){ //rodar todos os caracteres da resposta dada pelo usuário
        if(isdigit(frase[i])){ //se o caracter for digito
            cont++;
            char aux[10] = {frase[i]}; //armanzenar ele numa string auxiliar para poder usar no strcat
            strcat(d,aux);
        }
    }
     if(cont==0){ //se o contador for 0, é porque o usuário não digitou nenhum número
        cout<<"CosmosBot : Você não digitou nenhum número, por favor, escreva um número novamente por meio de algarismos! "<<endl;
        pegardia(diasdomes,m,dia,nome); //chamar a função novamente pro usuário poder escrever de novo
    }
    else{
        if(atoi(d)>diasdomes){ //transformar a string d(com o numero do dia) em int com auxílio da funçãoo atoi para comparar se é um dia válido
            cout<<"CosmosBot : "<<mes[m-1]<<" não tem "<<atoi(d)<<" dias. Me fale um dia do mês de "<<mes[m-1]<<endl;
            pegardia(diasdomes,m,dia,nome); //chamar a função novamente pro usuário escrever de novo
        }
        else{ //se o dia for válido, armazenar o valor na variável dia
            dia = atoi(d);
        }
    }
}

void escreve(int mes, int dia){ //função para imprimir os textos de cada signo
    if((mes==1 && dia>=21) || (mes==2 && dia<=18)){ //AQUÁRIO
        cout<<"CosmosBot : Aquário é o signo dos nascidos entre 21 de Janeiro e 18 de Fevereiro. É\n";
        cout<<"um signo regido por Urano. Por simbolizar a síntese do elemento Ar, o aquariano é\n";
        cout<<"fortemente atraído pelos assuntos de vanguarda.Aquário é considerado o signo dos\n";
        cout<<"imprevisíveis,dos que tem atitudes desconcertantes em relação às expectativas dos\n";
        cout<<"outros. De todos os signos, o aquariano é quem está mais preparado para lidar com\n";
        cout<<"os imprevistos, pois estão cientes de que o impossível acontece muito mais do que\n";
        cout<<"se possa pensar. Alguns famosos do signo Aquario são Justin Timberlake, Oprah Winfrey e Caio Castro. \n ";
    }

    else if((mes==2 && dia>=19) || (mes==3 && dia<=20)){ //PEIXES
        cout<<"CosmosBot : Peixes é o signo dos nascidos entre 19 de Fevereiro e 20 de Março. É um "<<endl;
        cout<<"signo regido por Netuno e Júpiter e tem água como seu elemento. Os atributos positivos"<<endl;
        cout<<"do signo de Peixes são muito elevados, pois representam o último estágio de aprendizado"<<endl;
        cout<<"da Escola da Vida e as mais raras virtudes humanas, tais como a compreensão, humildade,"<<endl;  
        cout<<"filantropia, compaixão, empatia, sensibilidade superior e amor devocional. Alguns famosos"<<endl; 
        cout<<"do signo de Peixes são Rihanna, Drew Barrymore, Albert Einsten e Michelangelo."<<endl;
    }
    
    else if((mes==3 && dia >=21) || (mes==4 && dia<=20)){ //ARIES
        cout<<"CosmosBot : Áries é o signo dos nascidos entre 21 de Março e 20 de Abril. É regido"<<endl;
        cout<<"por Marte e tem fogo como seu elemento. Os arianos se destacam pela coragem de suas"<<endl;
        cout<<"afirmações e de sua conduta, pela espontaneidade de suas respostas e pelo seu fiel"<<endl;
        cout<<"compromisso com a verdade. Alguns famosos do signo de Áries são Emma Watson,James Franco e Kourtney Kardashian."<<endl;
    }
    
    else if((mes==4 && dia>=21) || (mes==5 && dia<=20)){ //TOURO
        cout<<"CosmosBot : Touro é o signo dos nascidos entre 21 de Abril e 20 de Maio. É um signo"<<endl;
        cout<<"regido por Vênus e tem terra como seu elemento. O simbolo de Touro é associado a"<<endl;
        cout<<"plenitude e resistência. Traduz a ideia de grande forca de trabalho e do apuro de todos"<<endl;
        cout<<"os sentidos, principalmente do instinto de conservação, de sensualidade e de enorme vocação"<<endl;  
        cout<<"para os prazeres da vida. Alguns famosos do signo de touro sao Adele, David Beckham e Al pacino."<<endl; 
    }
    
    else if((mes==5 && dia>=21) || (mes==6 && dia<=20)){ //GEMEOS
        cout<<"CosmosBot : Gêmeos é o signo dos nascidos entre 21 de Maio e 20 de Junho e tem ar como seu elemento. \n";
        cout<<"Regidos por Mercúrio, os geminianos são comunicativos, versateis e sociaveis.Gostam de criar linhas \n";
        cout<<"de raciocínio e especulações na tentativa de entender diversos assuntos. Entretanto,podem focar mais \n ";
        cout<<"do que o necessário no mundo das ideias,e acabar se chocando e acabar se chocando com a maneira com que \n";  
        cout<<"as coisas acontecem na realidade. Alguns famosos de Gêmeos são Bob Dylan, Angelina Jolie e Chris Evans\n"; 
    }

    else if((mes==6 && dia>=21) || (mes==7 && dia<=22)){ //CANCER
        cout<<"CosmosBot : Câncer é o signo dos nascidos entre 21 de Junho e 22 de Julho. É regido por Vênus e Júpiter \n";
        cout<<"e Júpiter e tem água como seu elemento. Entre suas virtudes temos sua capacidade criativa (como todo \n";
        cout<<"signo de água),sua capacidade de amar profundamente e de empatia. Entre seus pontos problemáticos temos \n";  
        cout<<"a instabilidade emocional, que como a Lua, é feito de fases, sua dificuldade em enfrentar conflitos ou \n"; 
        cout<<"confrontar problemas faz com que sua abordagem as situações é sempre indireta e sua dificuldade \n"; 
        cout<<"em perceber eventos de forma objetiva. Alguns famosos de Câncer são Klhoe Kardashian,Gisele Bundchen e Selena Gomez.\n"; 
    }

    else if((mes==7 && dia>=23) || (mes==8 && dia<=22)){ //LEAO
        cout<<"CosmosBot : Leão é o signo dos nascidos entre 23 de Julho e 22 de Agosto e tem fogo como seu elemento. Regidos";
        cout<<"pelo Sol as pessoas do signo de Leão brilham como o seu regente e se diferenciam dos demais signos pela sua capacidade\n";
        cout<<"sua capacidade inigualável de aquecer quem esta por perto. Em sua manifestação mais elevada, o leonino se torna \n ";
        cout<<"o centro das atenções fazendo com que aqueles que estão em sua presença se sintam tão especiais, que não querem \n";  
        cout<<"dar atenção a nenhuma outra pessoa além dele. Magnéticos e extrovertidos, eles sabem entreter como ninguém.\n"; 
        cout<<"Alguns famosos de leão são Tata Werneck, Bruna Marquezine e Sandra Bullock.\n "; 
    }

    else if((mes==8 && dia>=23) || (mes==9 && mes<=22)){ //VIRGEM
        cout<<"CosmosBot : Virgem é o signo dos nascidos entre 23 de Agosto e 22 de Setembro. É um signo regido por Mercúrio \n";
        cout<<"e tem terra como elemento. Quem nasce com o Sol no signo de Virgem pode muitas ser visto como perfeccionista \n";
        cout<<"e crítico. No entanto, esse jeito de ser pode, muitas vezes, encobrir o medo de lidar com emoções mais profundas.\n ";
        cout<<"Virginianos são pessoas capazes de deixar tarefas e situações mais eficientes, já que gostam de seguir métodos  \n";  
        cout<<"e deixar a vida mais prática. Alguns famosos do signo de Virgem sao Blake Lively, Principe Harry e Adam Sandler.\n"; 
    }

    else if((mes==9 && dia>=23) || (mes==10 && dia<=22)){ //LIBRA
        cout<<"CosmosBot : Libra é o signo dos nascidos entre 23 de Setembro e 22 de Outubro. O signo de Libra é \n";
        cout<<"regido por Vênus e tem ar como seu elemento. Por isso foi isso presenteado com os dons da gentileza\n";
        cout<<"e conciliação. Os librianos realmente podem comprometer a sua personalidade e se esforçam muito para\n ";
        cout<<"manter a paz. Alguns famosos librianos são Claudia Abreu, Fernanda Montenegro e Kim Kardashian.\n";  
    }

    else if((mes==10 && dia>=23) || (mes==11 && dia<=22)){ //ESCORPIAO
        cout<<"CosmosBot : Escorpião é o signo dos nascidos entre 23 de Outubro e 22 de Novembro e tem Plutão como planeta regente. Algumas \n";
        cout<<"características de Escorpião são a autossuficiência e que são controladores, mas no fundo estao cheios de energia emocional. \n";
        cout<<"Esse é o segundo signo de Água e, por isso, tem forte interesse pela natureza psicoemocional, que leva a buscar um \n ";
        cout<<"incessante autoconhecimento, assim como a busca por decifrar enigmas, misterios e segredos do ser humano. Alguns famosos\n";  
        cout<<"de Escorpião são Emma Stone, Leonardo DiCaprio e Ryan Renolds.\n"; 
    }

    else if((mes==11 && dia>=23) || (mes==12 && dia<=22)){ //SARGITARIO
        cout<<"CosmosBot : Sargitário é o signo dos nascidos entre 23 de Novembro e 22 De dezembro. Esse signo é regido por Júpiter \n";
        cout<<"e tem fogo como seu elemento. O signo de Sagitário é o mais otimista dos doze signos do Zodíaco. Os nativos \n";
        cout<<"desse signo são a prova de que se você mentalizar e pensar positivo, as coisas comecam a andar. Sagitarianos \n";  
        cout<<"não discordam dos planos do Universo. Outra das características de sagitário é que adoram viajar e se aventurar.\n"; 
        cout<<"São conhecidos pela alegria constante, por sua necessidade de liberdade e por serem visionários. Alguns famosos \n "; 
        cout<<"sargitarianos sao Miley Cyrus, Scarlet Johansson e Taylor Swift.\n"; 
    }

    else if((mes==12 && dia>=23) || (mes==1 && dia<=20)){ //CAPRICORNIO
        cout<<"CosmosBot : Capricórnio é o signo dos nascidos entre 23 de Dezembro e 20 de Janeiro.É regido por Saturno \n";
        cout<<"e tem terra como seu elemento. Capricornianos são de uma natureza criteriosa, honesta e coerente. São\n";
        cout<<"disciplinados, sérios e costumam ter grande noçãoo de responsabilidade. Além disso, desenvolvem desde cedo \n ";
        cout<<"uma maturidade que surpreende a todos. Comunicar-se é uma arte bem difícil para os nativos deste signo, amantes do \n";  
        cout<<"silêncio e das interiorizações. A mente capricorniana é sóbria, concentrada e lógica. Falam pouco, num estilo \n"; 
        cout<<"bem objetivo. Alguns famosos desse signo são Michelle Obama, Ellen DeGeneres e Bradley Cooper\n";
    }
}
int main(){
    char resposta[300];
    char nome[50] = {""};
    char inicializacao[3][100]={{"Olá! Me chamo CosmosBot, qual é seu nome? "},{"Seja bem vindo! Me chamo CosmosBot, como você se chama? "},{"Oi ! Meu nome e CosmosBot, qual é o seu? "}};
    char adeus[4][100]={{"Mas já? Espero que tenha gostado de saber um pouco mais sobre os signos do zodíaco!"},{"Até mais, qualquer outra dúvida sobre signos pode chamar :)"},{"Tchau! Sempre que quiser sobre sobre o zodíaco, estarei aqui!"},{"Tchau, espero que voce tenha gostado e que possamos nos encontrar novamente :)"}};
    int dia;
    bool achou;

    setlocale(LC_ALL, "Portuguese"); 

    srand(time(NULL));
    cout<<"CosmosBot : "<<inicializacao[rand()%3]<<endl; // escolher aleatoriamente uma das 3 opcoes de incializar o programa
    cout<<"Usuário : ";
    cin.getline(resposta,300); //pegar a resposta do usuário

    for(int i=0;i<strlen(resposta);i++){
        if(resposta[i]!=' '){ //se for diferente de espaço, é porque o resposta[i] faz parte de uma palavra! vai repetir ate armazenar a última palavra
            char aux[10] = {resposta[i]}; //fazer uma string auxiliar para armazenas as letras e poder usar na funcao strcat
            strcat(nome,aux);
        }
        else{ //quando der espaço, o que tinha sido armazenado no nome vai ser "limpado" para poder pegar a próxima palavra
            strcpy(nome,"");
        }
    }
    cout<<"CosmosBot : Olá "<<nome<<"! Fui criado para falar sobre os signos do zodíaco! Me fale um signo ou um mês do ano."<<endl;
    strcpy(resposta,"");
    cout<<nome<<" : ";
    cin.getline(resposta,300);
    tudolower(resposta);

    
    while(true){ //uma repetição que vai sempre se repetir exceto quando o usuário se despedir


        if(strstr(resposta,"aquário")!=NULL || strstr(resposta,"aquario")){ //se a resposta tiver o signo escrito na frase
            escreve(1,21); //vai escrever o texto do signo(botei uma data aleatória de uma pessoa nascida no signo específico para isso)
        }
        else if(strstr(resposta,"peixes")!=NULL){
            escreve(2,20);
        }
        else if(strstr(resposta,"áries")!=NULL || strstr(resposta,"aries")!=NULL || strstr(resposta,"Áries")!=NULL){
            escreve(3,25);
        }
        else if(strstr(resposta,"touro")!=NULL){
            escreve(5,2);
        }
        else if(strstr(resposta,"gêmeos")!=NULL || strstr(resposta,"gemeos")!=NULL || strstr(resposta,"gÊmeos")!=NULL){
            escreve(6,5);          
        }
        else if(strstr(resposta,"câncer")!=NULL || strstr(resposta,"cancer")!=NULL || strstr(resposta,"cÂncer")!=NULL){
           escreve(7,6);         
        }
        else if(strstr(resposta,"leão")!=NULL || strstr(resposta,"leao")!=NULL || strstr(resposta,"leÃo")!=NULL){
            escreve(7,30);          
        }
        else if(strstr(resposta,"virgem")!=NULL){
            escreve(9,22);        
        }
        else if(strstr(resposta,"libra")!=NULL ){
            escreve(10,4);           
        }
        else if(strstr(resposta,"escorpião")!=NULL || strstr(resposta,"escorpiao")!=NULL || strstr(resposta,"escorpiÃo")!=NULL){
            escreve(11,20);          
        }
        else if(strstr(resposta,"sargitário")!=NULL || strstr(resposta,"sargitario")!=NULL || strstr(resposta,"sargitÁrio")!=NULL){
            escreve(12,10);         
        }
        else if(strstr(resposta,"capricórnio")!=NULL || strstr(resposta,"capricornio")!=NULL || strstr(resposta,"capricÓrnio")!=NULL){
            escreve(1,10);      
        }
        else if(strstr(resposta,"janeiro")!=NULL || strcmp(resposta,"1")==0){ //se tiver o mes por extenso ou em número
            cout<<"CosmosBot : Me fale um dia desse mês!"<<endl;
            pegardia(31,1,dia,nome);
            escreve(1,dia);
        }
        else if(strstr(resposta,"fevereiro")!=NULL || strcmp(resposta,"2")==0){
            cout<<"Me fale um dia desse mês!"<<endl;
            pegardia(28,2,dia,nome);
            escreve(2,dia);

        }
        else if(strstr(resposta,"março")!=NULL || strstr(resposta,"marco")!=NULL || strcmp(resposta,"3")==0){
            cout<<"Me fale um dia desse mês!"<<endl;
            pegardia(31,3,dia,nome);
            escreve(3,dia);
        }
        else if(strstr(resposta,"abril")!=NULL ||  strcmp(resposta,"4")==0){
            cout<<"Me fale um dia desse mês!"<<endl;
            pegardia(30,4,dia,nome);
            escreve(4,dia);
        }
        else if(strstr(resposta,"maio")!=NULL  || strcmp(resposta,"5")==0){
            cout<<"Me fale um dia desse mês!"<<endl;
            pegardia(31,5,dia,nome);
            escreve(5,dia);
        }
        else if(strstr(resposta,"junho")!=NULL || strcmp(resposta,"6")==0){
            cout<<"Me fale um dia desse mês!"<<endl;
            pegardia(30,6,dia,nome);
            escreve(6,dia);
        }
        else if(strstr(resposta,"julho")!=NULL || strcmp(resposta,"7")==0){
            cout<<"Me fale um dia desse mês!"<<endl;
            pegardia(31,7,dia,nome);
            escreve(7,dia);
        }
        else if(strstr(resposta,"agosto")!=NULL || strcmp(resposta,"8")==0){
            cout<<"Me fale um dia desse mês!"<<endl;
            cin>>dia;
            pegardia(31,8,dia,nome);
            escreve(8,dia);
        }
        else if(strstr(resposta,"setembro")!=NULL  || strcmp(resposta,"9")==0){
            cout<<"Me fale um dia desse mês!"<<endl;
            pegardia(30,9,dia,nome);
            escreve(9,dia);
        }
        else if(strstr(resposta,"outubro")!=NULL  ||  strcmp(resposta,"10")==0){
            cout<<"Me fale um dia desse mês!"<<endl;
            cin>>dia;
            pegardia(31,10,dia,nome);
            escreve(10,dia);
        }
        else if(strstr(resposta,"novembro")!=NULL || strcmp(resposta,"11")==0){
            cout<<"Me fale um dia desse mês!"<<endl;
            cin>>dia;
            pegardia(30,11,dia,nome);
            escreve(11,dia);
        }
        else if(strstr(resposta,"dezembro")!=NULL || strcmp(resposta,"12")==0){
            cout<<"Me fale um dia desse mês!"<<endl;
            cin>>dia;
            pegardia(31,12,dia,nome);
            escreve(12,dia); 
        }
        else if(strstr(resposta,"tchau")!=NULL  || strstr(resposta,"até")!=NULL || strstr(resposta,"adeus")!=NULL  || strstr(resposta,"ate")!=NULL){
            cout<<"CosmosBot : "<<adeus[rand()%4]<<endl;
            break; //sair do laço
        }
        else {
            cout<<"CosmosBot : Desculpe! Você não disse nenhum signo ou mês do ano."<<endl;
        }
        strcpy(resposta,"");
        cout<<"CosmosBot : Me fale um signo ou mês do ano."<<endl;
        cout<<nome<<" : ";
        cin.getline(resposta,300);
        tudolower(resposta);
    }
    
    return 0;

}