#include <iostream>
#include <cmath>
using namespace std;

double funcao(double); //prótotipo 
double treino(double,double); //prótotipo


int main(){
    double salario,emprestimo,z;

    cin>>salario>>emprestimo;

    z = treino(salario,emprestimo); // o "x" da função de ativação após o treinamento do neurônio

    if(funcao(z)>0.5){ // se a função de ativação for maior que 0.5, o empréstimo é concedido e o programa devolve 1 para simbolizar
        cout<<"1"<<endl;
    }
    else{  // caso contrário, o empréstimo é negado e o programa devolve 0 para simbolizar
        cout<<"0"<<endl;
    }
}

double funcao(double z){ //função ativação
    return 1/(1+pow(2.718281828459045235360287,-z));
}

double treino(double a,double b){ // treinamento do neurônio
    double z=0,erro;
	
	double x[2][10] = {{2.7 ,1.5 ,5.5 ,3.5 ,3.1 ,7.6 ,1.5,6.9,8.6,7.66 },{10.5,11.8,20.0,15.2,14.5,14.5,3.5,8.5,2.0,3.5 }};
    double y[10] ={0 ,0 ,0 ,0 ,0 ,1 ,1 ,1 ,1 , 1 };
    double w[2]={0.5,0.5};
		
	for(int i=0;i<1000;i++){
		for(int j=0;j<10;j++){
		z = x[0][j]*w[0]+ x[1][j]*w[1];
		funcao(z);
		erro = y[j] - funcao(z);
		w[0] = w[0] + 0.1 * erro * funcao(z)*(1 - funcao(z))*x[0][j];
		w[1] = w[1] + 0.1 * erro * funcao(z)*(1 - funcao(z))*x[1][j];
		}
	}
	
	z=a*w[0]+b*w[1]; //o somatório dos dados de entrada com os pesos corrigidos pelo neurônio

    return z;
}