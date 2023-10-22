#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>

class Usuario {
public:
    Usuario(const std::string& senha);
    bool verificarSenha(const std::string& senhaDigitada) const;

private:
    std::string senha;
};

#endif
