// C++ implementation to read 
// file word by word 
#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

template <class T>  
class LeerArchivo{
    public:
        //Input of the file for reading
        void leer(T argv[]){
            ifstream file(argv);
            string str; 

            while (getline(file, str))
            {
                cout << str << endl;
            }
        }
};


int main(int argc, char * argv[]) 
{
    LeerArchivo<char> L;
    L.leer(argv[1]);
    return 0; 
}