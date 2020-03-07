#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <string>
using namespace std; 


void calc(string arr[2]){
        string str2;
        string str1;
        int posIni;
        int posTer;
        int numIni;
        string line;
        int n = 2;
        bool sw = false;
        cout<<n<<endl;
            for (int i = 0; i < n-1; i++)
            {
                    line = arr[i];
                    cout<<line<<endl;
                    stringstream file(line); 
                    string word;
                    while (file >> word){ 
                      cout<<word<<endl;
                    // Finds the line with the for
                    if(word == "for"){
                      //puts a position to the beggining and end of the for
                      posIni = line.find("=")+2;
                      posTer = posIni + 7;
                      sw = true;
                    }else{
                      cout<<"no jalo"<<endl;
                    }
                  }
                  if(sw == true){
                      //We got the substring via the positions (0 and N)
                       str2 = line.substr(posIni,1); 
                       str1 = line.substr(posTer,1); 
                      cout<<str2<<endl;
                      cout<<str1<<endl;

                      numIni = stoi(str2); //stoi() converts from string to int

                      int suma = (- numIni + 1);
                      // the conditions were made for the sign in the string
                      if(suma>=0){
                      string total = str1 + "+" + to_string(suma);

                      cout<<total<<endl;
                      }else{
                        string total = str1 + "" + to_string(suma);
                        cout<<total<<endl;
                      }

                  

                  }
               

            }
        
}

  
   

             



int main()
{
    string linea1 = "for (int i = 0; i < n; i++){";
    string linea2 = "int a = 0";

    string arr[2] = {linea1, linea2};


    calc(arr);



   return 0;
}