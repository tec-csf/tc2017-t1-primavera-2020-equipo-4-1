#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std; 

/*ADAPTAR ESTE ALGORITMO AL MAIN E INCLUIR 
LA CONDICION DE QUE SI EL FOR TERMINA EN N-1
HACER QUE SEPARE EL MENOS UNO, COVERTIRLO EN
INT Y PONERLO EN LA SUMA DE TERMINA - INICIA +1

TAMBIEN ADAPTAR ESTO PARA QUE SE USE EN EL MAIN

DESPUES DE LOGRARLO, VER QUE IMPRIMA LA TABLA COMPLETA

DESPUES, USAR EL ARCHIVO DE POLYNOMIAL PARA PODER SUMAR LOS POLINOMIOS.

EL ARCHIVO FUNCIONA ASI:
a.set(1,1) va a ser igual a 1n^1 osea "n"
a.set(1,0) va a ser igual a 1n^0 osea "1"

LES DEJO LA PAGINA DE DONDE LA SAQUE PARA QUE VEAN COMO SE SUMA Y MULTIPLICA

https://www.daniweb.com/programming/software-development/code/217091/simple-polynomial-class

APROVECHEN QUE YA SE ORGANIZA SOLO PARA PONER EL EXPONENTE MAS ALTO AL PRINCIPIO



*/

// Function to remove all spaces from a given string 
string removeSpaces(string str)  
{ 
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); 
    return str; 
}  

void calc(string arr[2]){
  string str2;
  string str1;
  string str3;
  string signo;
  int str3Int;
  int posIni;
  int posTer;
  int numIni;
  int numTer;
  int suma;
  string line;
  int n = 2;
  bool sw = false;
  bool sumaResta = false;

  cout<<n<<endl;
  for (int i = 0; i < n; i++)
  {
    line = arr[i];
    cout<<line<<endl;
    stringstream file(line); 
    string word;
    while (file >> word){ 
      // Finds the line with the for
      if(word == "for"){
        //puts a position to the beggining and end of the for
        posIni = line.find("=")+2;

        if ((arr[i].at(posIni + 9) == '-') || (arr[i].at(posIni + 9) == '+')){
          str3 = line.substr((posIni + 9), 3);
          str3 = removeSpaces(str3);
          sumaResta = true;
          posTer = posIni + 7;
        }

        else {
          posTer = posIni + 7;
        }

        sw = true;
      }

      if(sw == true){
        //We got the substring via the positions (0 and N)
        str2 = line.substr(posIni,1); 
        str1 = line.substr(posTer,1);
        cout<<str2<<endl;
        cout<<str1<<endl;

        numIni = stoi(str2); //stoi() converts from string to int

        if (sumaResta == true){
          str3Int = stoi(str3);
          suma = (- numIni + str3Int + 1);
        }

        else {
          suma = (- numIni + 1); //This determines how much the for will repeat
        }
                
        // the conditions were made for the sign in the string
        if(suma>=0){
        string total = str1 + "+" + to_string(suma);

        cout<<total<<endl;
        }else{
          string total = str1 + "" + to_string(suma);
          cout<<total<<endl;
        }

        sw = false;
        sumaResta = false;
      }
    }
  }      
}

int main()
{
  string linea1 = "for (int i = 0; i < n; i++){"; 
  string linea2 = "int a = 0;";

  string arr[2] = {linea1, linea2};

  calc(arr);

  return 0;
}