/* 
C++ implementation to read from a file line by line
and save the lines in an array.

ADAPTAR ESTE ALGORITMO AL MAIN E INCLUIR 
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

#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;  

template <class T> 
class Metodos{  
  public:
    //Function to remove all spaces from a given string 
    string removeSpaces(T str){ 
        str.erase(remove(str.begin(), str.end(), ' '), str.end()); 
        return str; 
    }//Close removeSpaces

    string calcFor(T line, bool increment){
        string str1;
        string str2;
        string str3;
        string total;
        string word;
        int str3Int;
        int posIni;
        int posTer;
        int numIni;
        int suma;
        bool sw = false;
        bool sumaResta = false;

        stringstream file(line);

        while (file >> word){ 
            //puts a position to the beggining and end of the for
            posIni = line.find("=") + 2;

            if ((line.at(posIni + 9) == '-') || (line.at(posIni + 9) == '+')){
                str3 = line.substr((posIni + 9), 3);
                str3 = removeSpaces(str3);
                sumaResta = true;
                posTer = posIni + 7;
            }//Close if 

            else {
                posTer = posIni + 7;
            }//Close else 

            sw = true;

            if (sw == true){
                //We got the substring via the positions (0 and N)
                str2 = line.substr(posIni, 1); 
                str1 = line.substr(posTer, 1);

                numIni = stoi(str2); //stoi() converts from string to int

                if (increment = true){
                    if (sumaResta == true){
                        str3Int = stoi(str3);
                        suma = (- numIni + str3Int);
                    }//Close if 

                    else {
                        suma = (- numIni); //This determines how much the for will repeat
                    }//Close else
                }//Close if

                else {
                    if (sumaResta == true){
                        str3Int = stoi(str3);
                        suma = (- numIni + str3Int + 1);
                    }//Close if 

                    else {
                        suma = (- numIni + 1); //This determines how much the for will repeat
                    }//Close else
                }//Close else 
                        
                // the conditions were made for the sign in the string
                if(suma >= 0){
                    total = str1 + "+" + to_string(suma);
                    //cout << total << endl;
                }//Close if 
                
                else {
                    total = str1 + "" + to_string(suma);
                    //cout << total << endl;
                }//Close else 

                sw = false;
                sumaResta = false;
            }//Close if        
        }//Close while

        return total;
    }//Close calcFor

    string* declaracion(T *arr){ 
        int n = sizeof(arr);
        int contador = 0;
        string OE[n];
        string line;
        string word;
        string pol;
        string pol2;
        bool thereIsPol = false;
        bool increment = false;

        for (int i = 0; i < n; i++){
            line = arr[i];
            stringstream file(line);

            while (file >> word){
                if (word.length() > 1){
                    if (word == "for"){ //Falta agregar condicion que solo deje que se haga una vez por line
                        increment = false;
                        pol = calcFor(line, increment);
                        thereIsPol = true; 
                    }//Close if

                    if ((word == "++" || word == "--") && thereIsPol == true){
                        increment = true;
                        pol2 = calcFor(line, increment);
                    }//Close if 

                    for (int j = 0; j < word.length(); j++){
                        if ((word[j] == '+' && word[j + 1] == '+') || (word[j] == '[') || 
                        (word[j] == '-' && word[j + 1] == '-') || (word[j] == '>' && word[j + 1] == '=') 
                        || (word[j] == '<' && word[j + 1] == '=')){
                            if (((word[j] == '+' && word[j + 1] == '+') || (word[j] == '-' && word[j + 1] == '-')) 
                            && (thereIsPol = true)){
                                contador++;
                                OE[i] = OE[i] + to_string(contador) + "(" + pol2 + ") + (" + pol2 + ")[";
                                contador = 0;
                            }//Close if

                            else {
                                contador++;
                                OE[i] = OE[i] + to_string(contador) + " + ";
                                contador = 0;
                            }//Close else 
                        }//Close if 

                        if ((word[j] == '+' && word[j + 1] == '=') || (word[j] == '-' && word[j + 1] == '=')){
                            contador = contador + 2;
                            OE[i] = OE[i] + to_string(contador) + " + ";
                        }//Close if
                    }//Close for          
                }//Close if

                else if (word == "=" || word == "<" || word == ">" || word == "+" || word == "*" || 
                word == "/" || word == "-"){
                    if ((word == "<" || word == ">") && (thereIsPol = true)){
                        contador++;
                        OE[i] = OE[i] + to_string(contador) + "(" + pol + ") + ";
                    }//Close if

                    else {
                        contador++;
                        OE[i] =  OE[i] + to_string(contador) + " + ";
                    }//Close else 
                }//Close else if

                contador = 0;
            }//Close while

            contador = 0;
            thereIsPol = false;
            increment = false;
        }//Close for

        for (int k = 0; k < n; k++){
            cout << OE[k] << endl;
        }//Close for 
    }//Close declaracion               
};//Close Metodos

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
            if (*argv1 == '-'){
                string path = argv2;
                string str;
                //Declaring an ifstream file and opening our file
                ifstream file;
                file.open(path, ios::in);             

                //Reading from the file line by line 
                while (getline(file, str)){
                    i++;
                }//Close while

                //Closing the file
                file.close();

                //Opening the file again
                file.open(path, ios::in);
                    
                list= new string[i];

                //Saving the text file line by line in an array
                while (getline(file, str)){
                    list[a] = str; 
                    a++;
                }//Close while 

                //Printing
                /*for (int s = 0; s < i; s++){
                    cout << list[s] << endl;
                }//Close for*/
                
                //returning list of strings
                return list;

                //Closing the file again
                file.close();
            }//Close if 
                    
            else{
                cout<<"no introduciste la ruta correctamente"<<endl;
            }//Close else 

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