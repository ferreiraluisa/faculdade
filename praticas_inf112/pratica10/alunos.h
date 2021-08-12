#include <string>
class Alunos{
    private:
        int _matricula;
        double _nota1;
        double _nota2;
    public:
        std::string _nome;
        double _media;
        Alunos(int matricula, std::string nome, double nota1, double nota2);
        ~Alunos();
        void matricula_binario_invertido();
        bool maior_media(Alunos comparacao);
};