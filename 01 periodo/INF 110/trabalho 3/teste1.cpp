#include <iostream>
#include <cstring>
#include <cctype>
#include <ctime>
using namespace std;

void escreve(int mes, int dia){
    if((mes==1 && dia>=21) || (mes==2 && dia<=18)){ //AQUARIO
        cout<<"Aquario e o signo dos nascidos entre 21 de janeiro e 18 de fevereiro. \n";
        cout<<"E um signo regido por Urano.Por simbolizar a sintese do elemento Ar, \n";
        cout<<"o aquariano fortemente atraido pelos assuntos de vanguarda.Aquario e \n";
        cout<<"considerado o signo dos imprevisiveis,dos que tem atitudes desconcertantes \n";
        cout<<"em relacao as expectativas dos outros.De todos os signos, o aquariano \n";
        cout<<"e quem esta mais preparado para lidar com os imprevistos,pois estao cientes \n";
        cout<<"de que o impossivel acontece muito mais do que se possa pensar. \n";
        cout<<"Alguns famosos do signo Aquario sao Justin Timberlake, Oprah Winfrey e Caio Castro. \n"; 
    }

    else if((mes==2 && dia>=19) || (mes==3 && dia<=20)){ //PEIXES
        cout<<"Peixes e o signo dos nascidos entre 19 de fevereiro e 20 de março."<<endl;
        cout<<"E um signo regido por Netuno e Jupiter e tem agua como seu elemento."<<endl;
        cout<<"Os atributos positivos do signo de Peixes sao muito elevados,pois "<<endl;
        cout<<"representam o ultimo estagio de aprendizado da Escola da Vida e "<<endl;  
        cout<<"as mais raras virtudes humanas, tais como a compreensao, humildade,"<<endl; 
        cout<<"filantropia, compaixao, empatia, sensibilidade superior e amor devocional."<<endl;
        cout<<"Alguns famosos do signo de Peixes sao Rihanna,Drew Barrymore, Albert Einsten e Michelangelo."<<endl; 
    }
    
    else if((mes==3 && dia >=21) || (mes==4 && dia<=20)){ //ARIES
        cout<<"Aries e o signo dos nascidos entre 21 de marco e 20 de abril."<<endl;
        cout<<"E um signo regido por Marte e tem fogo como seu elemento."<<endl;
        cout<<"Os arianos se destacam pela coragem de sua afirmacoes e de  "<<endl;
        cout<<"sua conduta,pela espontaneidade de suas respostas e pelo  "<<endl;  
        cout<<"seu fiel compromisso com a verdade.Alguns famosos do"<<endl; 
        cout<<"signo de Aries sao Emma Watson, James Franco e Kourtney Kardashian."<<endl;
    }
    
    else if((mes==4 && dia>=21) || (mes==5 && dia<=20)){ //TOURO
        cout<<"Touro e o signo dos nascidos entre 21 de abril e 20 de maio."<<endl;
        cout<<"E um signo regido por Venus e tem terra como seu elemento."<<endl;
        cout<<"O simbolo de Touro e associado a plenitude e resistencia. "<<endl;
        cout<<"Traduz a ideia de grande forca de trabalho e do apuro de todos os sentidos,  "<<endl;  
        cout<<"principalmente do instinto de conservacao, de sensualidade e de enorme vocacao para os prazeres da vida."<<endl; 
        cout<<"Alguns famosos do signo de touro sao Adele, David Beckham e Al pacino."<<endl;
    }
    
    else if((mes==5 && dia>=21) || (mes==6 && dia<=20)){ //GEMEOS
        cout<<"Gemeos e o signo dos nascidos entre 21 de maio e 20 de junho. Tem ar como seu elemento. \n";
        cout<<"Regidos por Mercurio, os geminianos sao comunicativos, versateis e sociaveis. \n";
        cout<<"Gostam de criar linhas de raciocinio e especulacoes na tentativa de entender diversos assuntos.\n ";
        cout<<"Entretanto, podem focar mais do que o necessario no mundo das ideias,  \n";  
        cout<<"e acabar se chocando com a maneira com que as coisas acontecem na realidade.\n"; 
        cout<<"Alguns famosos de Gêmeos sao Bob Dylan, Angelina Jolie e Chris Evans.\n";
    }

    else if((mes==6 && dia>=21) || (mes==7 && dia<=22)){ //CANCER
        cout<<"Cancer e o signo dos nascidos entre 21 de junho e 22 de julho. \n";
        cout<<"E um signo regino por Venus e Jupiter e tem agua como seu elemento.\n";
        cout<<"Entre suas virtudes temos sua capacidade criativa (como todo signo de agua), \n ";
        cout<<"sua capacidade de amar profundamente e de empatia. \n";  
        cout<<"Entre seus pontos problematicos temos a instabilidade emocional, que como a Lua, e feito de fases, \n"; 
        cout<<"sua dificuldade em enfrentar conflitos ou confrontar problemas faz com que sua abordagem as situacoes\n";
        cout<<"e sempre indireta e sua dificuldade em perceber eventos de forma objetiva.\n "; 
        cout<<"Alguns famosos de Câncer são Klhoe Kardashian,Gisele Bundchen e Selena Gomez.\n"; 
        cout<<"\n";
    }

    else if((mes==7 && dia>=23) || (mes==8 && dia<=22)){ //LEAO
        cout<<"Leao e o signo dos nascidos entre 23 de julho e 22 de agosto. Tem fogo como elemento.";
        cout<<"regidos pelo Sol, as pessoas do signo de Leão brilham como o seu regente \n";
        cout<<"e se diferenciam dos demais signos pela sua capacidade inigualável de aquecer quem esta por perto.\n ";
        cout<<"Em sua manifestacao mais elevada, o leonino se torna o centro das atencoes fazendo com que aqueles que estao em sua presenca  \n";  
        cout<<"se sintam tao especiais, que nao querem dar atenção a nenhuma outra pessoa alem dele.\n"; 
        cout<<"Magneticos e extrovertidos, eles sabem entreter como ninguem.\n";
        cout<<"Alguns famosos de leão sao Tata Werneck, Bruna Marquezine e Sandra Bullock.\n "; 
    }

    else if((mes==8 && dia>=23) || (mes==9 && mes<=22)){ //VIRGEM
        cout<<"Virgem e o signo dos nascidos entre 23 de agosto e 22 de setembro. \n";
        cout<<"E um signo regido por Mercurio e tem terra como elemento.\n";
        cout<<"Quem nasce com o Sol no signo de Virgem pode muitas vezes ser visto como perfeccionista e critico. \n ";
        cout<<"No entanto, esse jeito de ser pode, muitas vezes, encobrir o medo de lidar com emocoes mais profundas. \n";  
        cout<<"Virginianos sao pessoas capazes de deixar tarefas e situacoes mais eficientes, \n"; 
        cout<<"ja que gostam de seguir metodos e deixar a vida mais pratica.\n";
        cout<<"Alguns famosos do signo de Virgem sao Blake Lively, Principe Harry e Adam Sandler.\n "; 
    }

    else if((mes==9 && dia>=23) || (mes==10 && dia<=22)){ //LIBRA
        cout<<"Libra e o signo dos nascidos entre 23 de setembro e 22 de outubro e tem ar como seu elemento. \n";
        cout<<"O signo de Libra e regido por Venus. Por isso foi isso presenteado com os dons da gentileza e conciliacao. \n";
        cout<<"Os librianos realmente podem comprometer a sua personalidade e se esforcam muito para manter a paz.\n ";
        cout<<"Alguns famosos do signo de Libra sao Claudia Abreu, Fernanda Montenegro e Kim Kardashian.\n";  
    }

    else if((mes==10 && dia>=23) || (mes==11 && dia<=22)){ //ESCORPIAO
        cout<<"Escorpiao e o signo dos nascidos entre 23 de outubro e 22 de novembro e tem Plutao como planeta regente.\n";
        cout<<"Algumas características de Escorpiao sao a autossuficiência e controladores, mas no fundo estao cheios de energia emocional.\n";
        cout<<"Esse e o segundo signo de Agua e, por isso, tem forte interesse pela natureza psicoemocional, \n ";
        cout<<"que leva a buscar um incessante autoconhecimento, assim como a busca por decifrar enigmas, misterios e segredos do ser humano.\n";  
        cout<<"Alguns famosos de Escorpiao sao Emma Stone, Leonardo DiCaprio e Ryan Renolds.\n"; 
    }

    else if((mes==11 && dia>=23) || (mes==12 && dia<=22)){ //SARGITARIO
        cout<<"Sargitario e o signo dos nascidos entre 23 de novembro e 22 de dezembro. \n";
        cout<<"Esse signo e regido por Jupiter e tem fogo como seu elemento.\n";
        cout<<"O signo de Sagitario e o mais otimista dos doze signos do Zodíaco. \n ";
        cout<<"Os nativos desse signo sao a prova de que se voce mentalizar e pensar positivo, as coisas comecam a andar.  \n";  
        cout<<"Sagitarianos nao discordam dos planos do Universo.\n"; 
        cout<<"Outra das caracteristicas de sagitario e que adoram viajar e se aventurar.\n";
        cout<<"Sao conhecidos pela alegria constante, por sua necessidade de liberdade e por serem visionarios.\n "; 
        cout<<"Alguns famosos sargitarianos sao Miley Cyrus, Scarlet Johansson e Taylor Swift.\n"; 
    }

    else if((mes==12 && dia>=23) || (mes==1 && dia<=20)){ //CAPRICORNIO
        cout<<"Capricornio e o signo dos nascidos entre 23 de dezembro e 20 de janeiro.\n";
        cout<<"Esse signo e regido por Saturno e tem terra como seu elemento.\n";
        cout<<"Capricornianos são de uma natureza criteriosa, honesta e coerente. Sao disciplinados, serios e costumam ter grande nocao de responsabilidade. \n ";
        cout<<"Alem disso, desenvolvem desde cedo uma maturidade que surpreende a todos. \n";  
        cout<<"Comunicar-se é uma arte bem difícil para os nativos deste signo, amantes do silencio e das interiorizacoes. \n"; 
        cout<<"A mente capricorniana e sobria, concentrada e logica. Falam pouco, num estilo bem objetivo.\n";
        cout<<"Alguns famosos desse signo sso Michelle Obama, Ellen DeGeneres e Bradley Cooper\n "; 
    }
}

int main(){
    cin>>mes>>dia;
}