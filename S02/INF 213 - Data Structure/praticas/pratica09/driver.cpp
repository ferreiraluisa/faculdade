#include <iostream>
#include <string>
#include "MyStack.h"
#include "MyQueue.h"
#include "Mediana.h"

using namespace std;


// Insira aqui o codigo para a etapa 1....

//Voce pode adicionar includes como o abaixo...
//#include "MyStack.h"


void etapa1() {
	MyStack<int> pilha;
	MyQueue<int> fila;
	int numAtual;
	for(int i=0;i<6;i++){
		cin>>numAtual;
		pilha.push(numAtual);
		fila.push(numAtual);
	}
	//imprimir conteudo da pilha
	for(int i=0;i<6;i++){
		cout<<pilha.top()<<" ";
		pilha.pop();
	}
	cout<<endl;
	//imprime conteudo da fila
	for(int i=0;i<6;i++){
		cout<<fila.front()<<" ";
		fila.pop();
	}
	cout<<endl;
	/* diferenca de impressao entre a fila e a pilha
		PILHA: imprimiu a lista "ao contrario" porque ela so consegue acessar o elemento que esta no topo
		FILA: imprimiu a lista igual tinha colocado, porque ela consegue tirar o elemento que esta no inicio*/
}

//---------------------------------------

// Insira aqui o codigo para a etapa 2....

void etapa2() {
	MyStack<char> caracteres;
	caracteres.push('x'); //pra lista nunca estar vazia
	char c;
	bool certo = true;
	while(cin>>c){
		if(c == '(' || c == '{' || c == '['){
			caracteres.push(c);
		}
		if(c == ')'){
			if(caracteres.top() != '('){
				certo = false;
				break;
			}
			caracteres.pop();
		}
		if(c == ']'){
			if(caracteres.top() != '['){
				certo = false;
				break;
			}
			caracteres.pop();
		}
		if(c == '}'){
			if(caracteres.top() != '{'){
				certo = false;
				break;
			}
			caracteres.pop();
		}
	}
	if(certo == false) cout<<"Inconsistente"<<endl;
	else{
		if(caracteres.size()>1) cout<<"Inconsistente"<<endl;
		else cout<<"Consistente"<<endl;
	}

}

//---------------------------------------

// Insira aqui o codigo para a etapa 3....


//#include "MedianaLenta.h" //use essa implementacao para fazer os primeiros testes (com o calculo lento da mediana...)
//#include "Mediana.h" //descomente esta linha para utilizar sua classe mais eficiente!
void etapa3() {
	//descomente o codigo abaixo ao fazer a etapa 3
	Mediana mediana;

	int n,elem;	
	cin >> n;
	for(int i=0;i<n;i++) {	
		cin >> elem;
		mediana.insere(elem);
		cout << mediana.getMediana() << " ";
	}
	cout << endl;
}

//---------------------------------------




int main() {
	int etapa;
	cin >> etapa;
	switch(etapa) {
		case 1:
			cout << "Etapa 1" << endl;
			etapa1();
			break;
		case 2:
			cout << "Etapa 2" << endl;
			etapa2();
			break;
		case 3:
			cout << "Etapa 3" << endl;
			etapa3();
			break;
	}
}