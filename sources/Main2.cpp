#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std; 

class Polynomial
{
//define private member functions
private:
   int coef[100];  // array of coefficients
   // coef[0] would hold all coefficients of x^0
   // coef[1] would hold all x^1
   // coef[n] = x^n ...
   int deg;        // degree of polynomial (0 for the zero polynomial)
//define public member functions
public:
   Polynomial() //default constructor
   {
      for ( int i = 0; i < 100; i++ )
      {
         coef[i] = 0;
      }
   }

    Polynomial(int a, int b) //default constructor
   {
      for ( int i = 0; i < 100; i++ )
      {
         coef[i] = 0;
      }
      this->set(a,b);
   }
   void set ( int a , int b ) //setter function
   {
      //coef = new Polynomial[b+1];
      coef[b] = a;
      deg = degree();
   }
   int degree()
   {
      int d = 0;
      for ( int i = 0; i < 100; i++ )
         if ( coef[i] != 0 ) d = i;
      return d;
   }
   void print()
   {
      for ( int i = 99; i >= 0; i-- ) {
         if ( coef[i] != 0 ) {
            cout << coef[i] << "n^" << i << " ";
         }
      }
   }
   // use Horner's method to compute and return the polynomial evaluated at x
   int evaluate ( int x )
   {
      int p = 0;
      for ( int i = deg; i >= 0; i-- )
         p = coef[i] + ( x * p );
      return p;
   }
   // differentiate this polynomial and return it
   Polynomial differentiate()
   {
      if ( deg == 0 )  {
         Polynomial t;
         t.set ( 0, 0 );
         return t;
      }
      Polynomial deriv;// = new Polynomial ( 0, deg - 1 );
      deriv.deg = deg - 1;
      for ( int i = 0; i < deg; i++ )
         deriv.coef[i] = ( i + 1 ) * coef[i + 1];
      return deriv;
   }
   Polynomial plus ( Polynomial b )
   {
      Polynomial a = *this; //a is the poly on the L.H.S
      Polynomial c;
      for ( int i = 0; i <= a.deg; i++ ) c.coef[i] += a.coef[i];
      for ( int i = 0; i <= b.deg; i++ ) c.coef[i] += b.coef[i];
      c.deg = c.degree();
      return c;
   }
   Polynomial minus ( Polynomial b )
   {
      Polynomial a = *this; //a is the poly on the L.H.S
      Polynomial c;
      for ( int i = 0; i <= a.deg; i++ ) c.coef[i] += a.coef[i];
      for ( int i = 0; i <= b.deg; i++ ) c.coef[i] -= b.coef[i];
      c.deg = c.degree();
      return c;
   }
   Polynomial times ( Polynomial b )
   {
      Polynomial a = *this; //a is the poly on the L.H.S
      Polynomial c;
      for ( int i = 0; i <= a.deg; i++ )
         for ( int j = 0; j <= b.deg; j++ )
            c.coef[i+j] += ( a.coef[i] * b.coef[j] );
      c.deg = c.degree();
      return c;
   }
};



template <class T> 
class Metodos{  
  public:
    Polynomial pol;
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

                if (increment == true){
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

    string calcWhile(T line){
        string str1;
        string str2;
        string total;

        str1 = line.at(11);
        total = str1 + " + " + to_string(1);

        return total;
    }//Close calcWhile

    string* declaracion(T *arr, int n){ 
        int contador = 0;
        string OE[n];
        string line;
        string word;
        string pol;
        string pol2;
        string pol3;
        bool thereIsPol = false;
        bool thereIsPol2 = false;
        bool increment = false;

        for (int i = 0; i < n; i++){
            line = arr[i];
            stringstream file(line);

            while (file >> word){
                if (word.length() > 1){
                    if (word == "for"){
                        increment = false;
                        pol = calcFor(line, increment);
                        thereIsPol = true; 
                    }//Close if

                    else if ((word == "i++){" || word == "i--){" || word == "j++){" || word == "j--){" || word == "k++){" 
                    || word == "k--){") && thereIsPol == true){
                        increment = true;
                        pol2 = calcFor(line, increment);
                    }//Close else if 

                    else if (word == "while"){
                        pol3 = calcWhile(line);
                        thereIsPol2 = true;
                        cout << pol3 << endl;
                    }//Close else if 

                    for (int j = 0; j < word.length(); j++){
                        if ((word[j] == '+' && word[j + 1] == '+') || (word[j] == '[') || 
                        (word[j] == '-' && word[j + 1] == '-') || (word[j] == '>' && word[j + 1] == '=') 
                        || (word[j] == '<' && word[j + 1] == '=')){
                            if (((word[j] == '+' && word[j + 1] == '+') || (word[j] == '-' && word[j + 1] == '-')) 
                            && (thereIsPol == true)){
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
                    if ((word == "<" || word == ">") && (thereIsPol == true)){
                        contador++;
                        OE[i] = OE[i] + to_string(contador) + "(" + pol + ") + ";
                    }//Close if

                    else if ((word == "<" || word == ">") && (thereIsPol2 == true)){
                        contador++;
                        OE[i] = OE[i] + to_string(contador) + "(" + pol3 + ") + ";
                        
                    }//Close else if 

                    else {
                        contador++;
                        OE[i] = OE[i] + to_string(contador) + " + ";
                    }//Close else 
                }//Close else if

                contador = 0;
            }//Close while

            thereIsPol = false;
            thereIsPol2 = false;
            increment = false;
            contador = 0;
        }//Close for

        for (int k = 0; k < n; k++){
            cout << OE[k] << endl;
        }//Close for 
        return OE;
    }//Close declaracion 
                  
};//Close Metodos

class Conversion{
    public:
        //Variables to convert for Polynomial class
        vector<Polynomial*> polis;
    
        void calculo(string *pol, int size){
            int coef = 0;
            int exp = 0;
            char a = '0';
            for (int i = 0; i < size; i++)
            {
                string line = pol[i];
                stringstream file(line);
                string word;

                while(file >> word){
                    if(word.length() == 1 && word !="+"){
                        int num = stoi(word);
                        coef = coef + num;
                        exp = 0;   
                        polis.push_back(new Polynomial(coef,exp));  
                    }else{
                        if (word.length() > 1){{
                            for (int j = 0; j < word.length(); j++)
                            {
                                if(word[5]!='['){
                                    if (j == 0 && word.length() == 6)
                                    {
                                        int mul = word[0] - a;
                                        coef = mul;
                                        exp = 0;
                                        polis.push_back(new Polynomial(coef,exp));

                                    }else if(j == 0 && word.length() == 5){

                                    }

                                    if (j == 2 && word.length() == 6)
                                    {
                                        exp = 1;
                                        coef = 1;
                                        polis.push_back(new Polynomial(coef,exp));

                                    }else if(j == 1 && word.length() == 5){
                                        exp = 1;
                                        coef = 1;
                                        polis.push_back(new Polynomial(coef,exp));
                                    }

                                    if (j == 4 && word.length() == 6)
                                    {
                                        int num = word[4] - a;
                                        coef = num;
                                        exp = 0;
                                        polis.push_back(new Polynomial(coef,exp));

                                    }else if(j == 3 && word.length() == 5){
                                        int num = word[3] - a;
                                        coef = num;
                                        exp = 0;
                                        polis.push_back(new Polynomial(coef,exp));
                                    }
                                }else{
                                     if (j == 0 && word.length() == 7)
                                    {
                                        int mul = word[0] - a;
                                        coef = mul;
                                        exp = 0;
                                        polis.push_back(new Polynomial(coef,exp));

                                    }else if(j == 0 && word.length() == 6){

                                    }

                                    if (j == 2 && word.length() == 7)
                                    {
                                        exp = 1;
                                        coef = 1;
                                        polis.push_back(new Polynomial(coef,exp));

                                    }else if(j == 1 && word.length() == 6){
                                        exp = 1;
                                        coef = 1;
                                        polis.push_back(new Polynomial(coef,exp));
                                    }

                                    if (j == 4 && word.length() == 7)
                                    {
                                        int num = word[4] - a;
                                        coef = num;
                                        exp = 0;
                                        polis.push_back(new Polynomial(coef,exp));

                                    }else if(j == 3 && word.length() == 6){
                                        int num = word[3] - a;
                                        coef = num;
                                        exp = 0;
                                        polis.push_back(new Polynomial(coef,exp));
                                    }else{}
                                }
                                
                            } 
                        }
                    }
                }
                
            }
            
        }
        int x = 0;
         while (!polis.empty()) { 
             polis[x]->print();
            polis.pop_back(); 
            x++;
        } 
         
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
            a=0;
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
                    
                list = new string[i]();

                //Saving the text file line by line in an array
                while (getline(file, str)){
                    list[a] = str; 
                    a++;
                }//Close while 

                //Closing the file again
                file.close();
                
                //returning list of strings
                return list;
            }//Close if 
                    
            else{
                cout<<"no introduciste la ruta correctamente"<<endl;
            }//Close else 

            return list;
        }//Close leerGuardar    
};//Close leerArchivo

int main(int argc, char * argv[])
{
    int i = 0;
    LeerArchivo<char> L;
    Metodos<string> M;

    string *arr = L.leerGuardar(argv[1], argv[argc-1]);
    i = L.i;

    string *pol  = M.declaracion(arr, i);

    Conversion C;

    C.calculo(pol,i);
    


    return 0; 
}//Close main