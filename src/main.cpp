#include <iostream>

int main(){
    
    std::string tablero[10][10]={
                        {" ", "b", " ", "b", " ", "b", " ", "b", " ", "b"},
                        {"b", " ", "b", " ", "b", " ", "b", " ", "b", " "},
                        {" ", "b", " ", "b", " ", "b", " ", "b", " ", "b"},
                        {"b", " ", "b", " ", "b", " ", "b", " ", "b", " "},
                        {" ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
                        {" ", " ", " ", " ", " ", " ", " ", " ", " ", " "},
                        {" ", "n", " ", "n", " ", "n", " ", "n", " ", "n"},
                        {"n", " ", "n", " ", "n", " ", "n", " ", "n", " "},
                        {" ", "n", " ", "n", " ", "n", " ", "n", " ", "n"},
                        {"n", " ", "n", " ", "n", " ", "n", " ", "n", " "}
    };
    int jugador1 = 0, jugador2 = 0;
    //b = blancas, v = reina blancas
    //n = negras, m = reina negras
    std::string turno = "blancas";
    bool estado = true;
    int n = 1;
    while(estado){
        
        std::cout<<"\n Inicia el jugador de las fichas "<< turno<<std::endl<<std::endl;
        std::string copia[10][10];
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                copia[i][j]=tablero[i][j];
            }   
        }
        //Visualizar estado tablero
        for(int i=0;i<10;i++){
            if(i>=1&&i<=9){std::cout<<"----------------------------------------\n";}
            for(int j=0;j<10;j++){
                if(turno[0]=='b'&&tablero[i][j]=="b"){
                    copia[i][j]=std::to_string(n);
                    n++;
                }
                if(turno[0]=='n'&&tablero[i][j]=="n"){
                    copia[i][j]=std::to_string(n);
                    n++;
                }
                if(j>=1&&j<=9){std::cout<<"|";}
                std::cout<<" "<<copia[i][j]<<" ";   
            }
            std::cout<<"\n";  
        }
        //Escoge ficha que va a jugar 1 a 20 segun disponibilidad


        turno = (turno=="blancas")? "negras" : "blancas";
        if(turno=="blancas"){estado=false;}
    }

    return 0;
}
