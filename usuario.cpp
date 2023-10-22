#include "usuario.h"

Usuario::Usuario(const std::string& senha) : senha(senha) {}

bool Usuario::verificarSenha(const std::string& senhaDigitada) const {
    return senha == senhaDigitada;
}
