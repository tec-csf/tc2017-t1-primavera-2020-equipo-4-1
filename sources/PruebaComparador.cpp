
// C++ implementation to read 
// file word by word 
#include <iostream>
#include <fstream>
#include <string>
using namespace std; 

// driver code 
int main() 
{

    int contador = 0;
    // filestream variable file 
    fstream file; 
    string word, t, q, filename; 
  
    // filename of the file 
    filename = "example1.txt"; 
  
    // opening file 
    file.open(filename.c_str()); 
  
    // extracting words from the file 
    while (file >> word) 
    { 
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
    return 0; 
} 

/*for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
        resultado[i][j] = 0;

        for (int k = 0; k < N; k++){
            resultado[i][j] += matrizA[i][k] * matrizB[k][j];
        }
    }
}*/