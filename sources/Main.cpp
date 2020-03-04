/* 
C++ implementation to read from a file line by line
and save the lines in an array.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <regex> 
#include <sstream>
using namespace std; 

template <class T> 
class Metodos{  
  public:
  
    
};

//Creating a template class
template <class T> 
class LeerArchivo{
    public:
        int i = 0;
        int a = 0;
        int s = 0;
        string *list;
        
        //Input of the file for reading
        string * leerGuardar(T argv1[], T argv2[]){
            if (*argv1 == '-')
                    {
                      string path = argv2;
                      string str;
                      //Declaring an ifstream file and opening our file
                      ifstream file;
                      file.open(path, ios::in);             

                      //Reading from the file line by line 
                      while (getline(file, str))
                      {
                          i++;
                      }//Close while

                      //Closing the file
                      file.close();

                      //Opening the file again
                      file.open(path, ios::in);
                          
                      list= new string[i];

                      //Saving the text file line by line in an array
                      while (getline(file, str))
                      {
                          list[a] = str; 
                          a++;
                      }//Close while 

                      //Printing
                      for (int s = 0; s < i; s++){
                          cout << list[s] << endl;
                      }//Close for 
                      
                      //returning list of strings
                      return list;

                      
                      //Closing the file again
                      file.close();
                      
                    }else{
                      cout<<"no introduciste la ruta correctamente"<<endl;
                    }
                    return list;
        }//Close leerGuardar    
};//Close leerArchivo

int main(int argc, char * argv[])
{
    LeerArchivo<char> L;
    Metodos<string> M;
    string *arr = L.leerGuardar(argv[1],argv[argc-1]);

    return 0; 
}//Close main