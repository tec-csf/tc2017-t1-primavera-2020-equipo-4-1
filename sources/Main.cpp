/* 
C++ implementation to read from a file line by line
and save the lines in an array.
*/

#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

using namespace std; 

template <class T> 
class Metodos{  
  public:
    string* declaracion(T *arr){
        int contador = 0;
        int n = sizeof(arr);
        string OE[n];
        string line;

        for (int i = 0; i < n; i++)
        {
            line = arr[i];
            stringstream file(line); 
            string word;

            while (file >> word){ 
                //cout << word << endl;
                // displaying content
                if(word.length()>1)
                {
                    int l = 0;
                    for(int j = 0; word.length()>j;j++)
                    {
                        if((word[j] == '+' && word[j+1] == '+') || (word[j] == '[') || (word[j] == '-' && word[j+1] == '-') || (word[j] == '>' && word[j+1] == '=') || (word[j] == '<' && word[j+1] == '='))
                        {
                            //cout << "aqui" << endl;

                            contador++;

                            list_EO[i]="contiene #EO "+to_string(contador);
                        }

                        if((word[j] == '+' && word[j+1] == '=') || (word[j] == '-' && word[j+1] == '='))
                        {
                            //cout << "aqui" << endl;

                            contador = contador + 2;

                            list_EO[i]="contiene #EO "+to_string(contador);
                        }
                    }
                }

                else if (word == "=" || word == "<" || word == ">" || word == "+" || word == "*" || word == "/" || word == "-")
                {
                    //cout << "aqui" << endl;

                    contador++;

                    list_EO[i]="contiene #EO "+to_string(contador);
                }
            } 

            //cout << word << endl;

            contador = 0;               
        }

        for (int i = 0; i < sizeof(list_EO) ; i++)
        {
            if ((list_EO[i] != " ") || (list_EO[i] != " "))
            {
                cout<<list_EO[i]<<endl;
            }
        }

        //returning list of elemental opertions
        //return list_EO;
    }                   
};

//Creating a template class
template <class T> 
class LeerArchivo{
    public:
        int i = 0;
        int a = 0;
        int s = 0;
        string* list;
        
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
                          //cout << list[s] << endl;
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
    M.declaracion(arr);

    return 0; 
}//Close main