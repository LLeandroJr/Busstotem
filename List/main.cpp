#include <iostream>
#include "List.h"

using namespace std;

int main(){
    list lst;

    for(int i=1;i<10;i++){
        lst.push_back(i);
    }

    lst.clear();

    cout << lst.empty() << endl;
    cout << lst.size() << endl;

}