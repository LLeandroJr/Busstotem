#include "manager.h"

void UserManager::adicionarUsuario(const Usuario& usuario) {
    usuarios.push_back(usuario);
}

bool UserManager::autenticarUsuario(const std::string& senha) {
    for (const Usuario& usuario : usuarios) {
        if (usuario.verificarSenha(senha)) {
            return true; // Autenticação bem-sucedida
        }
    }
    return false; // Autenticação falhou
}
