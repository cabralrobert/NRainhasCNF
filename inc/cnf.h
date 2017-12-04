#ifndef CNF_H
#define CNF_H

#include <fstream>
#include <sstream>

using namespace std;

class CNF{
private:
    string locateFile;
    int N, qtd;
    ofstream outFile;
    int getPos(int i, int j);

public:
    CNF(int N);
    bool generate();
    string getLocateFile();
};

#endif // CNF_H
