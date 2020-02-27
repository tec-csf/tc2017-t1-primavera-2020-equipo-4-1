/* 
C++ implementation to read from a file line by line
and save the lines in an array.
*/

#include <bits/stdc++.h> 
#include <fstream>
#include <string>

using namespace std; 
  
int main(int argc, char * argv[])
{
    //Declaring an ifstream file and opening our file
    ifstream file;
    file.open(argv[1], ios::in);

    string str; 
    int i = 0;
    int T = 0;

    //Reading from the file line by line 
    while (getline(file, str))
    {
        i++;
    }//Close while

    //Closing the file
    file.close();

    file.open(argv[1], ios::in);
    
    string list[i];

    while (getline(file, str))
    {
       list[T] = str; 
       T++;
    }//Close while 

    for (int s = 0; s < i; s++){
        cout << list[s] << endl;
    }//Close for 

    file.close();
}//Close main 