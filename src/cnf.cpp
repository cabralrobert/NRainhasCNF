#include "cnf.h"

CNF::CNF(int N) : N(N), qtd(0){
    ostringstream os;
    os << "data/instance_" << N << "x" << N << ".txt";
    this->locateFile = os.str();

    this->outFile.open(os.str());
}

int CNF::getPos(int i, int j){
    return (i * this->N + j + 1);
}

bool CNF::generate(){
    if(!outFile.is_open())
        return false;

    outFile << "         \0\r" << endl;
    outFile << "         \0\r" << endl;

    for(int i = 1;i <= N*N;i = i+N){
        for(int j = i;j < i+N;j++)
            outFile << j << " ";
        outFile << "0" << endl;
    }

    outFile << endl;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            for(int k = 0; k < N;k++){
                if(getPos(i,j)*-1 != getPos(i,k)*-1){
                    outFile << getPos(i,j)*-1 << " " << getPos(i,k)*-1 << " 0" << endl;
                    this->qtd++;
                }
                if(getPos(i,j)*-1 != getPos(k,j)*-1){
                    outFile << getPos(i,j)*-1 << " " << getPos(k,j)*-1 << " 0" << endl;
                    this->qtd++;
                }
            }
        }
    }

    for(int k = 0;k < N;k++){
        for(int z = 0;z < N;z++){

            for (int i=k, j=z; i>=0 && j>=0; i--, j--){
                if(getPos(i,j) != getPos(k,z)){
                    outFile << getPos(k,z)*-1 << " " << getPos(i,j)*-1 << " 0" << endl;
                    this->qtd++;
                }
            }

            for (int i=k, j=z; j>=0 && i<N; i++, j--){
                if(getPos(i,j) != getPos(k,z)){
                    outFile << getPos(k,z)*-1 << " " << getPos(i,j)*-1 << " 0" << endl;
                    this->qtd++;
                }
            }

            for (int i=k, j=z; j<N && i>=0; i--, j++){
                if(getPos(i,j) != getPos(k,z)){
                    outFile << getPos(k,z)*-1 << " " << getPos(i,j)*-1 << " 0" << endl;
                    this->qtd++;
                }
            }

            for (int i=k, j=z; j<N && i<N; i++, j++){
                if(getPos(i,j) != getPos(k,z)){
                    outFile << getPos(k,z)*-1 << " " << getPos(i,j)*-1 << " 0" << endl;
                    this->qtd++;
                }
            }
        }
    }

    outFile.seekp(0);
    outFile << "p cnf " << N*N << " " << this->qtd << endl;
    outFile.close();

    return true;
}

string CNF::getLocateFile(){
    return this->locateFile;
}


