#ifndef INF112_KEYWORDS_H
#define INF112_KEYWORDS_H

#include <string>

class KeyWords{
    private:
        std::string nome_do_arquivo;

    public:
        KeyWords(std::string nome);
        void find_keywords();
};

#endif