#ifndef INF112_EXCECA0ACIMADEX_H
#define INF112_EXCECA0ACIMADEX_H
#include <stdexcept>

class ExcecaoAcimaX : public std::exception {
    public:
        virtual const char* what() const noexcept override;
};

#endif