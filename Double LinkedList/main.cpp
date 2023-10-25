#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;

int main() {
    DoublyLinkedList myList;

    char choice;
    do {
        string from;
        int arrival_hour, arrival_minute, departure_hour, departure_minute;

        cout << "Digite o nome da parada: ";
        cin >> from;

        cout << "Digite a hora de chegada (hora minuto): ";
        cin >> arrival_hour >> arrival_minute;

        cout << "Digite a hora de partida (hora minuto): ";
        cin >> departure_hour >> departure_minute;

        myList.append(from, arrival_hour, arrival_minute, departure_hour, departure_minute);

        cout << "Deseja adicionar outra parada? (S/N): ";
        cin >> choice;
    } while (choice == 'S' || choice == 's');

    cout << endl;
    myList.printForward();

    cout << endl;
    myList.printBackward();

    return 0;
}
