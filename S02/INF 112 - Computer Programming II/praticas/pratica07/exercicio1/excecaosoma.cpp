#include <stdexcept>
#include <limits>
#include <iostream>
#include "excecaosoma.h"
#include "excecaoacimax.h"

Excecao::Excecao(int n){
    _n = n;
    _soma = 0;
    _vezes = 0;
}
Excecao:: ~Excecao(){
    delete[] _numeros;
}

int Excecao::excecaoX(int _x){
    if(std::cin.fail()){
        throw std::invalid_argument("ERRO!Um numero nao foi digitado. ");
    }
    if(_x>100){
        throw "Numero deve ser menor que 100. Digite novamente.";
    }
    else{
        return _x;
    }
}

int Excecao::excecao_numeros(int n) {
    if(std::cin.fail()){
        throw std::invalid_argument("ERRO!Um numero nao foi digitado. ");
    }
    if(n<=0){
        throw "Numero deve ser maior que 0.Digite novamente";
    }
    else {
        return n;
    }
}

int Excecao::excecaoacimadeX() throw(ExcecaoAcimaX){
    if(_soma>_x){
        throw ExcecaoAcimaX();
    }
    else{
        return _soma;
    }
}

void Excecao::le_numeros(){
    while(true){
        std::cout<<"Digite o numero max da soma: ";
        std::cin>>_x;
        try{
            excecaoX(_x);
            break;
        } catch(std::invalid_argument &erro){
                std::cerr<<erro.what()<<std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }catch(const char *e){
            std::cerr<<"ERRO: "<<e<<std::endl;
        }
    }

    for(int i=0;i<_n;i++){
        while(true){
            std::cout<<"Digite o "<<i+1<<" numero: ";
            std::cin>>_numeros[i];
            try{
                excecao_numeros(_numeros[i]);
                break;
            }catch(const char *er){
                std::cerr<<"ERRO: "<<er<<std::endl;
            }catch(std::invalid_argument &erro){
                std::cerr<<erro.what()<<std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        _soma += _numeros[i];
        _vezes++;   
        _media = _soma/_vezes;

        try{
            excecaoacimadeX();
        } catch(ExcecaoAcimaX &e){
            std::cerr<<e.what()<<std::endl;
            _soma = _soma - _numeros[i];
            _vezes--;
            _media = _soma / _vezes;
            break;
        }

    }
}

        
