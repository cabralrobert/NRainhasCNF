#include <iostream>
#include "cnf.h"

using namespace std;

int main(int argc, char *argv[]){

    if(argc != 2){
        cout << "Please enter the size of the board." << endl;
        return -1;
    }

    int N = atoi(argv[1]);

    if(!(N >= 4)){
        cout << "The tray must be larger than 4x4." << endl;
        return -1;
    }

    CNF cnf(N);

    if(cnf.generate())
        cout << "File generated in: " << cnf.getLocateFile() << endl;
    else
        cout << "Error generating file." << endl;

    return 0;
}
