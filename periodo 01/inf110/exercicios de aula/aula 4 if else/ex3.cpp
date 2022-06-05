//informar se o aluno foi reprovado (<60)
#include <iostream>
using namespace std;

int main () {
    double nota;
    
    cout<<"Digite a nota do aluno:";
    cin>>nota;

    if (nota<60)
    cout<<"REPROVADO!"<<endl;
    else
    cout<<"APROVADO!"<<endl;
}