#include <iostream>
#include "ForwardList.h"
#include <stdexcept>
#include <string>

using namespace std;

int main(){
    char escolha_do_usuario;
    string senha = "admin";
    string senha_digitada_pelo_usuario;
    char escola_do_ADM;
    ForwardList myForwardList;
    string name;
    int id;

    char continueAdding;

    cout << "Seja bem-vindo(a) ao BussTotem\n"
         << "Escolha sua forma de ingresso em nosso sistema:\n "
         << "Cliente (Digite 1) \n"
         << "Administrador (Digite 2)\n";

    cin >> escolha_do_usuario;
    cin.ignore();

    if (escolha_do_usuario == '1') {
        // Lógica para a opção do cliente
    } else if (escolha_do_usuario == '2') {
        // Lógica para a opção do administrador
        cout << "Digite a senha de administrador para ganhar acesso ao controle de paradas: \n";
        cin >> senha_digitada_pelo_usuario;

        if (senha_digitada_pelo_usuario == senha) {
            cout << "Olá, administrador(a), seja bem-vindo(a) a central de controle de linhas e paradas BussTotem \n";
            cout <<"\n \n";
            cout << "O que você deseja modificar em nosso sistema?\n"
                 << "Incluir uma nova linha (DIGITE (1))\n"
                 << "Incluir uma parada numa linha (DIGITE (2))\n"
                 << "Alterar uma parada (DIGITE (3))\n"
                 << "Eliminar uma parada (DIGITE (4))\n"
                 << "Eliminar uma linha (DIGITE (5))\n";

            // Implementação by DIOGO
            if (escola_do_ADM == '1') {
                do {
                    cout << "Digite o nome: ";
                    getline(cin, name);

                    do {
                        cout << "Digite o ID (de até 5 dígitos): ";
                        cin >> id;
                        cin.ignore();
                    } while (id < 1 || id > 99999);

                    //myForwardList.append(name, id);

                    cout << "Deseja adicionar outro elemento? (S/N): ";
                    cin >> continueAdding;
                    cin.ignore();
                } while (continueAdding == 'S' || continueAdding == 's');

                cout << "Elementos da lista encadeada:\n";
                myForwardList.print();

                return 0;
            }
        } else {
            cout << "Senha incorreta, tente novamente!\n";
        }
    }

    return 0;
}
