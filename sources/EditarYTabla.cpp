string * editar(string *arr){
    int counter = 0;
    string str = " ";
    int z = 0;
    for (int u = 0; u < sizeof(arr); u++){
        str = arr[u];
        while(z < str.length()){
        if (str[z] == ' '){
            counter++;
        }//Close if 

        else {
            break;
        }//Close else 
        z++;
        }//Close for
        str.erase(0, counter);
        arr[u] = str;
    }//Close for
    return arr;
}//Close editar

void tabla(string *lineaCodigo){
    string tabla[4][sizeof(lineaCodigo)];

    cout<<"No. de linea\tCódigo\t\t\t\t\t\t\tOE\tPolinomio"<<endl;;

    for (int ty = 0; ty < sizeof(lineaCodigo); ty++)
    {

            cout<<ty+1<<"\t\t"<<lineaCodigo[ty]<<"\t\t\t\t";
        
        cout<<endl;
    }
}//Close editar