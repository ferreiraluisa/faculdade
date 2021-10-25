#include <algorithm>
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <vector>
#include <string>
using namespace std;


struct Pessoa {
	string nome;
	int cpf;
	double altura;
};

void ordenaNome(Pessoa *pessoas, int n){
	for (int i = 1; i < n; i++) {
        std::string elemInserir = pessoas[i].nome;
		Pessoa aux = pessoas[i];
        int j = i-1;
        while(j >= 0 && pessoas[j].nome > elemInserir) {
            pessoas[j+1] = pessoas[j];
            j--;
        }
        pessoas[j+1] = aux;
    }
}

void ordenaCPF(Pessoa *pessoas, int n){
	for (int i = 1; i < n; i++) {
        int elemInserir = pessoas[i].cpf;
		Pessoa aux = pessoas[i];
        int j = i-1;
        while(j >= 0 && pessoas[j].cpf > elemInserir) {
            pessoas[j+1] = pessoas[j];
            j--;
        }
        pessoas[j+1] = aux;
    }
}



void ordenaPessoas(Pessoa *pessoas,int n) {
	ordenaCPF(pessoas,n); //chama primeiro a de cpf porque como insertionSort é estável(ou seja, a ordem relativa entre a ordenação com base no CPF fica mantida e isso que o exercício pede visto que se o nome for igual o que será levado em conta é o CPF)
	ordenaNome(pessoas,n);
}

/*
Exemplo de entrada:
5
Dbc 123 1.8
Abc 194 1.7
Abc 125 1.9
Teste 100 1.1
Alto 300 3.2

Saida esperada:
Abc 125 1.9
Abc 194 1.7
Alto 300 3.2
Dbc 123 1.8
Teste 100 1.1
*/


//Não modifique nada daqui para baixo...
int main(int argc, char **argv) {
	//O arquivo de entrada contém um numero n. 
	//A seguir, há n linhas cada uma contendo o nome, cpf e altura de uma pessoa (separados por um espaço em branco)
	//O nome eh sempre composto de um unico token
	int n;
	cin >> n;
	Pessoa *pessoas = new Pessoa[n];
	for(int i=0;i<n;i++) {
		cin >> pessoas[i].nome >> pessoas[i].cpf >> pessoas[i].altura;
	}

	ordenaPessoas(pessoas,n);

	//imprime a saída ordenada
	for(int i=0;i<n;i++) {
		cout << pessoas[i].nome << " " <<  pessoas[i].cpf << " " <<  pessoas[i].altura << '\n';
	}


	delete []pessoas;
	return 0;
}