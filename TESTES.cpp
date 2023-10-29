#include <iostream>
#include "ForwardList.h"

int main() {
    char escolha_do_usuario;
    ForwardList myForwardList;

    bool sair = false; // Variável para controlar a saída do programa

    while (!sair) {
        std::cout << "Seja bem-vindo(a) ao BussTotem\n"
                  << "Escolha sua forma de ingresso em nosso sistema:\n"
                  << "Cliente (Digite 1)\n"
                  << "Administrador (Digite 2)\n"
                  << "Para sair do programa, digite 'S'.\n";

        std::cin >> escolha_do_usuario;
        std::cin.ignore();

        if (escolha_do_usuario == '1') {
            // Lógica para a opção do cliente
            bool sair_cliente = false;

            while (!sair_cliente) {
                std::cout << "Linhas disponíveis:\n";
                myForwardList.printAll();

                std::cout << "Digite 'M' para voltar ao menu principal, 'S' para sair ou qualquer outra tecla para continuar: ";
                char voltar_menu;
                std::cin >> voltar_menu;
                std::cin.ignore();
                if (voltar_menu == 'M' || voltar_menu == 'm') {
                    break; // Retorna ao menu principal
                } else if (voltar_menu == 'S' || voltar_menu == 's') {
                    sair_cliente = true; // Sair da opção de cliente
                }
            }

        } else if (escolha_do_usuario == '2') {
            // Lógica para a opção do administrador
            std::cout << "Olá, administrador(a), seja bem-vindo(a) a central de controle de linhas e paradas BussTotem \n";

            // Adicione aqui as funcionalidades do administrador com base na sua classe ForwardList
            // Por exemplo, adicionar linhas, adicionar paradas, excluir paradas, etc.

            std::cout << "Para sair do modo administrador e voltar ao menu principal, digite 'M'.\n";

            char voltar_menu_principal;
            std::cin >> voltar_menu_principal;
            std::cin.ignore();

            if (voltar_menu_principal == 'M' || voltar_menu_principal == 'm') {
                std::cout << "Saindo do modo administrador e voltando ao menu principal...\n";
            }

        } else if (escolha_do_usuario == 'S' || escolha_do_usuario == 's') {
            std::cout << "Encerrando o programa...\n";
            sair = true; // Sair do programa
        } else {
            std::cout << "Opção inválida. Por favor, escolha novamente.\n";
        }
    }

    return 0;
}
