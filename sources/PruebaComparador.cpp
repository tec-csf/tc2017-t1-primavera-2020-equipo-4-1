
// C++ implementation to read 
// file word by word 
#include <iostream>
#include <sstream>
#include <string>
using namespace std; 

// driver code 
int main() 
{

    int contador = 0;
    string ar[] = {"for int = ;", "int = 0"};
    string line;
    int n = sizeof(ar)/sizeof(ar[0]);

     cout << n << endl;

   for (int i = 0; i < n; i++)
   {
       line = ar[i];
        stringstream file(line); 
        string word;
        while (file >> word){ 
        // displaying content
                if(word.length()>1)
                {
                    int l = 0;
                    for(int i = 0; word.length()>i;i++)
                    {
                        if(word[i] == '+' && word[i+1] == '+')
                        {
                            contador++;
                        }
                    }
                }
                else if (word == "=" || word == "<" || word == "+")
                {

                    contador++;
                }
                cout << word << endl;
            } 
            cout<<"OE: "<<contador;
            
            } 

            return 0; 
   }
   
  
  
    // filename of the file 
  
    // opening file 

  
    // extracting words from the file 
    

/*for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
        resultado[i][j] = 0;

        for (int k = 0; k < N; k++){
            resultado[i][j] += matrizA[i][k] * matrizB[k][j];
        }
    }
}*/