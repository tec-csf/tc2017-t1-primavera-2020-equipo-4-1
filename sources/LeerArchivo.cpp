// C++ implementation to read 
// file word by word 
#include <bits/stdc++.h> 
#include <fstream>
#include <string>
using namespace std; 
  
// driver code 
int main(int argc, char * argv[]) 
{
    ifstream file(argv[1]);
    string str; 

    while (getline(file, str))
    {
        cout << str << endl;
    }

    /*// filestream variable file 
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
        cout << word << endl; 
    } */
  
    return 0; 
}