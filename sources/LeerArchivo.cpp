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
    
    return 0; 
}