#include <iostream>
#include "ForwardList.h"
#include <exception>
#include <string>

using namespace std;

int main() {
    int escolha_do_usuario;
    string senha = "admin";
    string senha_digitada_pelo_usuario;
    int escola_do_ADM;
    ForwardList myForwardList;
    string name;
    int id;

    char continueAdding;

    cout << "Seja bem-vindo(a) ao BussTotem" << endl
         << "Escolha sua forma de ingresso em nosso sistema: " << endl
         << "Cliente (Digite 1)" << endl
         << "Administrador (Digite 2)" << endl;

    cin >> escolha_do_usuario;
    cin.ignore();

    if (escolha_do_usuario == 1) {
        // Lógica para a opção do cliente
    } else if (escolha_do_usuario == 2) {
        // Lógica para a opção do administrador
        cout << "Digite a senha de administrador para ganhar acesso ao controle de paradas: " << endl;
        cin >> senha_digitada_pelo_usuario;

        if (senha_digitada_pelo_usuario == senha) {
            cout << "Olá, administrador(a), seja bem-vindo(a) a central de controle de linhas e paradas BussTotem " << endl;
            cout << endl << endl;
            cout << "O que você deseja modificar em nosso sistema?" << endl
                 << "Incluir uma nova linha (DIGITE (1))" << endl
                 << "Incluir uma parada numa linha (DIGITE (2))" << endl
                 << "Alterar uma parada (DIGITE (3))" << endl
                 << "Eliminar uma parada (DIGITE (4))" << endl
                 << "Eliminar uma linha (DIGITE (5))" << endl;

            // Implementação by DIOGO
            if (escola_do_ADM == 1) {
                do {
                    cout << "Digite o nome: ";
                    getline(cin, name);

                    do {
                        cout << "Digite o ID (de até 5 dígitos): ";
                        cin >> id;
                        cin.ignore();
                    } while (id < 1 || id > 99999);

                    myForwardList.append(name, id);

                    cout << "Deseja adicionar outro elemento? (S/N): ";
                    cin >> continueAdding;
                    cin.ignore();
                } while (continueAdding == 'S' || continueAdding == 's');

                cout << "Elementos da lista encadeada:" << endl;
                myForwardList.display();

                return 0;
            }
        } else {
            cout << "Senha incorreta, tente novamente!" << endl;
        }
    }

    return 0;
}
