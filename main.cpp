#include <iostream>
#include "ForwardList.h"
#include <stdexcept>
#include <string>

using namespace std;

int main() {
    char escolha_do_usuario;
    string senha = "admin";
    string senha_digitada_pelo_usuario;
    char escolha_do_ADM;
    ForwardList myForwardList;
    string name;
    int id;
    char continueAdding;

    bool sair = false; // Variável para controlar a saída do programa

    while (!sair) {
        cout << "Seja bem-vindo(a) ao BussTotem\n"
             << "Escolha sua forma de ingresso em nosso sistema:\n"
             << "Cliente (Digite 1) \n"
             << "Administrador (Digite 2)\n"
             << "Para sair do programa, digite 'S'.\n";

        cin >> escolha_do_usuario;
        cin.ignore();

        if (escolha_do_usuario == '1') {
            // Lógica para a opção do cliente
            bool sair_cliente = false;

            while (!sair_cliente) {
                cout << "Linhas disponíveis:\n";
                // Chame uma função que liste as linhas disponíveis (a ser implementada)
                myForwardList.printAll();

                cout << "Digite 'M' para voltar ao menu principal, 'S' para sair ou qualquer outra tecla para continuar: ";
                char voltar_menu;
                cin >> voltar_menu;
                cin.ignore();
                if (voltar_menu == 'M' || voltar_menu == 'm') {
                    break; // Retorna ao menu principal
                } else if (voltar_menu == 'S' || voltar_menu == 's') {
                    sair_cliente = true; // Sair da opção de cliente
                }
            }

        } else if (escolha_do_usuario == '2') {
            // Lógica para a opção do administrador
            int tentativas = 3; // Número de tentativas para a senha
            bool senha_correta = false;

            while (tentativas > 0) {
                cout << "Digite a senha de administrador para ganhar acesso ao controle de paradas: \n";
                cin >> senha_digitada_pelo_usuario;
                cin.ignore();

                if (senha_digitada_pelo_usuario == senha) {
                    senha_correta = true;
                    break; // Senha correta, sai do loop
                } else {
                    cout << "Senha incorreta. Tentativas restantes: " << tentativas - 1 << endl;
                    tentativas--;
                }
            }

            if (senha_correta) {
                cout << "Olá, administrador(a), seja bem-vindo(a) a central de controle de linhas e paradas BussTotem \n";
                cout << "\n \n";
                cout << "O que você deseja modificar em nosso sistema?\n"
                     << "Incluir uma nova linha (DIGITE (1))\n"
                     << "Incluir uma parada numa linha (DIGITE (2))\n"
                     << "Alterar uma parada (DIGITE (3))\n"
                     << "Eliminar uma parada (DIGITE (4))\n"
                     << "Eliminar uma linha (DIGITE (5))\n"
                     << "Para sair do modo administrador e voltar ao menu principal, digite 'M'.\n";
                cout << endl;

                while (true) {
                    cin >> escolha_do_ADM;
                    cin.ignore();

                    if (escolha_do_ADM == '1') {
                        do {
                            cout << "Digite o nome: ";
                            getline(cin, name);

                            do {
                                cout << "Digite o ID (de até 5 dígitos): ";
                                cin >> id;
                                cin.ignore();
                                
                                myForwardList.insert(id, name);
                            
                            } while (id < 1 || id > 99999);

                            cout << "Deseja adicionar outro elemento? (S/N): ";
                            cin >> continueAdding;
                            cin.ignore();
                        } while (continueAdding == 'S' || continueAdding == 's');

                        cout << "Linha adicionada com sucesso:\n";
                    } else if (escolha_do_ADM == '2') {
                        // Função para eliminar uma linha por ID
                        unsigned numeroParaRemover;
                        cout << "Número da Linha para Excluir: ";
                        cin >> numeroParaRemover;
                        cin.ignore();
                        
                        iterator_forwardList it = myForwardList.erase(numeroParaRemover);

                        if (it != myForwardList.end()) {
                            cout << "Linha com o número " << numeroParaRemover << " foi excluída com sucesso." << endl;
                        } else {
                            cout << "Linha com o número " << numeroParaRemover << " não foi encontrada na lista." << endl;
                        }
                        
                        // Aguardar o usuário pressionar uma tecla antes de retornar ao menu principal
                        cout << "Pressione qualquer tecla e Enter para voltar ao menu principal: ";
                        char voltar_menu_principal;
                        cin >> voltar_menu_principal;
                        cin.ignore();
                    } else if(escolha_do_ADM == '3') {
                        unsigned numeroLinha;
                        int numeroParada;
                        cout << "Digite o numero da linha: ";
                        cin >> numeroLinha;

                        cout << "Digite o numero do parada que deseja eliminar: ";
                        cin >> numeroParada;
                    } else if (escolha_do_ADM == 'M' || escolha_do_ADM == 'm') {
                        cout << "Saindo do modo administrador e voltando ao menu principal...\n";
                        break; // Saia do loop de administrador
                    } else {
                        cout << "Opção inválida. Por favor, escolha novamente (1 a 5 ou 'M' para voltar ao menu principal): ";
                    }
                }
            } else {
                cout << "Número máximo de tentativas excedido. Retornando ao menu principal.\n";
            }
        } else if (escolha_do_usuario == 'S' || escolha_do_usuario == 's') {
            cout << "Encerrando o programa...\n";
            sair = true; // Saia do programa
        } else {
            cout << "Opção inválida. Por favor, escolha novamente.\n";
        }
    }

    return 0;
}
