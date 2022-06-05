#ifndef INF112_CONTA_H
#define INF112_CONTA_H
#include <string>
class Conta{    
    private:
        std::string _nome;
        std::string _cpf;
        double _saldoatual;
    public:
        Conta(std::string nome, std::string cpf, double saldoatual); //construtor
        ~Conta(); //destrutor
        void set_saldo(double saldo);
        virtual double get_saldo();

};

#endif