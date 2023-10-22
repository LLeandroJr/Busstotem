#ifndef MANAGER_H
#define MANAGER_H

#include "usuario.h"
#include <vector>

class UserManager {
public:
    void adicionarUsuario(const Usuario& usuario);
    bool autenticarUsuario(const std::string& senha);

private:
    std::vector<Usuario> usuarios;
};

#endif
