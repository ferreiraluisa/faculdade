#include <iostream>
#include <cstring>
#include <cctype>
#include <ctime>
#include <locale.h>
using namespace std;

void escreve(int mes, int dia){ //funcao para imprimir os textos de cada signo
    setlocale(LC_ALL, "Portuguese");
    if((mes==1 && dia>=21) || (mes==2 && dia<=18)){ //AQUÁRIO
        cout<<"Aquário é o signo dos nascidos entre 21 de janeiro e 18 de fevereiro. É \n";
        cout<<"um signo regido por Urano.Por simbolizar a sintese do elemento Ar,o  \n";
        cout<<"aquariano fortemente atraído pelos assuntos de vanguarda.Aquário é \n";
        cout<<"considerado o signo dos imprevisíveis,dos que tem atitudes desconcertantes \n";
        cout<<"em relação as expectativas dos outros. De todos os signos, o aquariano \n";
        cout<<"é quem esta mais preparado para lidar com os imprevistos,pois estão cientes \n";
        cout<<"de que o impossível acontece muito mais do que se possa pensar. Alguns ";
        cout<<"famosos do signo Aquario são Justin Timberlake, Oprah Winfrey e Caio Castro. \n"; 
    }

    else if((mes==2 && dia>=19) || (mes==3 && dia<=20)){ //PEIXES
        cout<<"Peixes é o signo dos nascidos entre 19 de fevereiro e 20 de março. É um "<<endl;
        cout<<"signo regido por Netuno e Júpiter e tem agua como seu elemento. Os atributos"<<endl;
        cout<<"positivos do signo de Peixes são muito elevados,pois representam o último "<<endl;
        cout<<"estágio de aprendizado da Escola da Vida e as mais raras virtudes humanas, "<<endl;  
        cout<<"tais como a compreensão, humildade, filantropia, compaixão, empatia, sensibilidade"<<endl; 
        cout<<"superior e amor devocional. Alguns famosos do signo de Peixes são Rihanna, "<<endl;
        cout<<"Drew Barrymore, Albert Einsten e Michelangelo."<<endl; 
    }
    
    else if((mes==3 && dia >=21) || (mes==4 && dia<=20)){ //ARIES
        cout<<"Áries é o signo dos nascidos entre 21 de marco e 20 de abril. É um signo regido "<<endl;
        cout<<"por Marte e tem fogo como seu elemento. Os arianos se destacam pela coragem de "<<endl;
        cout<<"suas afirmações e de sua conduta, pela espontaneidade de suas respostas e pelo "<<endl;
        cout<<"seu fiel compromisso com a verdade. Alguns famosos do signo de Aries são Emma Watson "<<endl;  
        cout<<"James Franco e Kourtney Kardashian."<<endl;
    }
    
    else if((mes==4 && dia>=21) || (mes==5 && dia<=20)){ //TOURO
        cout<<"Touro é o signo dos nascidos entre 21 de abril e 20 de maio. É um signo "<<endl;
        cout<<"regido por Vênus e tem terra como seu elemento. O simbolo de Touro é "<<endl;
        cout<<"associado a plenitude e resistência. Traduz a ideia de grande forca de "<<endl;
        cout<<"trabalho e do apuro de todos os sentidos, principalmente do instinto de conservação, "<<endl;  
        cout<<"de sensualidade e de enorme vocação para os prazeres da vida. Alguns famosos "<<endl; 
        cout<<"do signo de touro sao Adele, David Beckham e Al pacino."<<endl;
    }
    
    else if((mes==5 && dia>=21) || (mes==6 && dia<=20)){ //GEMEOS
        cout<<"Gêmeos é o signo dos nascidos entre 21 de maio e 20 de junho e tem ar como seu elemento.Regidos por \n";
        cout<<"Mercúrio, os geminianos sao comunicativos, versateis e sociaveis.Gostam de criar linhas de raciocínio \n";
        cout<<"e especulações na tentativa de entender diversos assuntos. Entretanto,podem focar mais do que\n ";
        cout<<"o necessário no mundo das ideias,e acabar se chocando e acabar se chocando com a maneira com que as coisas  \n";  
        cout<<"acontecem na realidade. Alguns famosos de Gêmeos são Bob Dylan, Angelina Jolie e Chris Evans\n"; 
    }

    else if((mes==6 && dia>=21) || (mes==7 && dia<=22)){ //CANCER
        cout<<"Câncer é o signo dos nascidos entre 21 de junho e 22 de julho. É um signo regino por Vênus e Júpiter \n";
        cout<<"e tem agua como seu elemento. Entre suas virtudes temos sua capacidade criativa (como todo signo de agua),\n";
        cout<<"sua capacidade de amar profundamente e de empatia. Entre seus pontos problemáticos temos a instabilidade \n";  
        cout<<"emocional, que como a Lua, é feito de fases, sua dificuldade em enfrentar conflitos ou confrontar problemas \n"; 
        cout<<"faz com que sua abordagem as situacoes é sempre indireta e sua dificuldade em perceber eventos de forma objetiva.\n"; 
        cout<<"Alguns famosos de Câncer são Klhoe Kardashian,Gisele Bundchen e Selena Gomez.\n"; 
    }

    else if((mes==7 && dia>=23) || (mes==8 && dia<=22)){ //LEAO
        cout<<"Leao e o signo dos nascidos entre 23 de julho e 22 de agosto e tem fogo como seu elemento. Regidos pelo Sol";
        cout<<"as pessoas do signo de Leão brilham como o seu regente e se diferenciam dos demais signos pela sua capacidade\n";
        cout<<"inigualável de aquecer quem esta por perto. Em sua manifestação mais elevada, o leonino se torna o centro das\n ";
        cout<<"atenções fazendo com que aqueles que estão em sua presença se sintam tão especiais, que não querem dar atenção \n";  
        cout<<"a nenhuma outra pessoa alem dele. Magnéticos e extrovertidos, eles sabem entreter como ninguém.Alguns famosos\n"; 
        cout<<"de leão são Tata Werneck, Bruna Marquezine e Sandra Bullock.\n "; 
    }

    else if((mes==8 && dia>=23) || (mes==9 && mes<=22)){ //VIRGEM
        cout<<"Virgem é o signo dos nascidos entre 23 de agosto e 22 de setembro. É um signo regido por Mercúrio  \n";
        cout<<"e tem terra como elemento. Quem nasce com o Sol no signo de Virgem pode muitas ser visto como \n";
        cout<<"perfeccionista e crítico. No entanto, esse jeito de ser pode, muitas vezes, encobrir o medo de lidar\n ";
        cout<<"com emoções mais profundas. Virginianos sao pessoas capazes de deixar tarefas e situações mais  \n";  
        cout<<"eficientes, já que gostam de seguir metodos e deixar a vida mais pratica. Alguns famosos do signo \n"; 
        cout<<"de Virgem sao Blake Lively, Principe Harry e Adam Sandler.\n "; 
    }

    else if((mes==9 && dia>=23) || (mes==10 && dia<=22)){ //LIBRA
        cout<<"Libra é o signo dos nascidos entre 23 de setembro e 22 de outubro e tem ar como seu elemento. O signo de \n";
        cout<<"Libra é regido por Vênus. Por isso foi isso presenteado com os dons da gentileza e conciliacao. Os librianos \n";
        cout<<"realmente podem comprometer a sua personalidade e se esforcam muito para manter a paz. Alguns famosos \n ";
        cout<<"librianos são Claudia Abreu, Fernanda Montenegro e Kim Kardashian.\n";  
    }

    else if((mes==10 && dia>=23) || (mes==11 && dia<=22)){ //ESCORPIAO
        cout<<"Escorpião é o signo dos nascidos entre 23 de outubro e 22 de novembro e tem Plutão como planeta regente. Algumas\n";
        cout<<"características de Escorpião são a autossuficiência e controladores, mas no fundo estao cheios de energia emocional.\n";
        cout<<"Esse é o segundo signo de Água e, por isso, tem forte interesse pela natureza psicoemocional, que leva a buscar um \n ";
        cout<<"incessante autoconhecimento, assim como a busca por decifrar enigmas, misterios e segredos do ser humano. Alguns\n";  
        cout<<"famosos de Escorpião são Emma Stone, Leonardo DiCaprio e Ryan Renolds.\n"; 
    }

    else if((mes==11 && dia>=23) || (mes==12 && dia<=22)){ //SARGITARIO
        cout<<"Sargitário é o signo dos nascidos entre 23 de novembro e 22 de dezembro. Esse signo é regido por Júpiter  \n";
        cout<<"e tem fogo como seu elemento. O signo de Sagitário é o mais otimista dos doze signos do Zodíaco. Os nativos\n";
        cout<<"desse signo são a prova de que se você mentalizar e pensar positivo, as coisas comecam a andar. Sagitarianos \n";  
        cout<<"não discordam dos planos do Universo. Outra das características de sagitário e que adoram viajar e se aventurar.\n"; 
        cout<<"São conhecidos pela alegria constante, por sua necessidade de liberdade e por serem visionários. Alguns famosos\n "; 
        cout<<"sargitarianos sao Miley Cyrus, Scarlet Johansson e Taylor Swift.\n"; 
    }

    else if((mes==12 && dia>=23) || (mes==1 && dia<=20)){ //CAPRICORNIO
        cout<<"Capricórnio e o signo dos nascidos entre 23 de dezembro e 20 de janeiro.Esse signo é regido por Saturno \n";
        cout<<"e tem terra como seu elemento. Capricornianos são de uma natureza criteriosa, honesta e coerente. São\n";
        cout<<"disciplinados, sérios e costumam ter grande noçãoo de responsabilidade. Além disso, desenvolvem desde cedo \n ";
        cout<<"uma maturidade que surpreende a todos. Comunicar-se é uma arte bem difícil para os nativos deste signo, amantes do \n";  
        cout<<"silêncio e das interiorizações. A mente capricorniana é sóbria, concentrada e lógica. Falam pouco, num estilo \n"; 
        cout<<"bem objetivo. Alguns famosos desse signo são Michelle Obama, Ellen DeGeneres e Bradley Cooper\n";
        cout<<"\n "; 
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
    cout<<inicializacao[rand()%3]<<endl;;
    cin.getline(resposta,300);

    for(int i=0;i<strlen(resposta);i++){
        if(resposta[i]!=' '){
            char aux[10] = {resposta[i]};
            strcat(nome,aux);
        }
        else{
            strcpy(nome,"");
        }
    }
    cout<<"Olá "<<nome<<"! Fui criado para falar sobre os signos do zodíaco! Me fale um signo ou um mês do ano."<<endl;
    strcpy(resposta,"");
    cin.getline(resposta,200);