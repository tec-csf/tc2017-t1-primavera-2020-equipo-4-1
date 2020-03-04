// C++ implementation to read 
// file word by word 
#include <iostream>
#include <regex> 
#include <fstream>
#include <string>
#include <sstream>
using namespace std; 

template <class T>  
class Complejidad{
  public:
    int i = 0;
    int a = 0;
    int s = 0;
  
    //Method to check if the array has a declaration
    void declaracion(T argv[]){
         //Input of the file for reading
            string str;

            //Declaring an ifstream file and opening our file
            ifstream file;
            file.open(argv, ios::in);             

            //Reading from the file line by line 
            while (getline(file, str))
            {
                i++;
            }//Close while

            //Closing the file
            file.close();

            //Opening the file again
            file.open(argv, ios::in);
                
            string list[i];

            //Saving the text file line by line in an array
            while (getline(file, str))
            {
                list[a] = str; 
                a++;
            }//Close while 

            //Printing
            for (s = 0; s < i; s++){
                cout << list[s] << endl;
            }//Close for 

            //Reading the algorythm line by line
        for (int j = 0; j < s; j++)
        {
          //Puting in a string each part of the array
          smatch s;
          string match;
          
          //Objects for regex
          regex str("[^for]string.+[a-zA-Z] =");
          regex integer("[^for]int.+[a-zA-Z] =");
          regex flt("[^for]float+.+[a-zA-Z] =");
          regex dbl("[^for]double+.+[a-zA-Z] =");
          regex bol("[^for]bool+.+[a-zA-Z] =");

          regex_search (list[j],s,integer);
          for(auto x:s){
            match = x;
            }
          
          //Comparing the regex objects with each line
          if(regex_match(match,str)||regex_match(match,integer)||regex_match(match,flt)||regex_match(match,dbl)||regex_match(match,bol) ){
            //If it matches, it overwrites with an EO (elemental operation)
            list[j] = "1";
          }else{
             list[j] = "no es";
          }// Close condition
        }//Close for

        for (int s = 0; s < i; s++){
                cout << list[s] << endl;
            }//Close for 

            //Closing the file again
            file.close();
        }//Close leerGuardar     
    
};//Close class 

int main(int argc, char * argv[])
{
    Complejidad<char> C;
    C.declaracion(argv[1]);
    return 0; 
}//Close main