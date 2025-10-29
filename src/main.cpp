int main(){
    char tablero[10][10]={
                        {' ', 'b', ' ', 'b',' ', 'b', ' ', 'b', ' ', 'b'},
                        {'b', ' ', 'b', ' ','b', ' ', 'b', ' ', 'b', ' '},
                        {' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b'},
                        {'b', ' ', 'b', ' ', 'b', ' ', 'b', ' ', 'b', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                        {' ', 'n', ' ', 'n', ' ', 'n', ' ', 'n', ' ', 'n'},
                        {'n', ' ', 'n', ' ', 'n', ' ', 'n', ' ', 'n', ' '},
                        {' ', 'n', ' ', 'n', ' ', 'n', ' ', 'n', ' ', 'n'},
                        {'n', ' ', 'n', ' ', 'n', ' ', 'n', ' ', 'n', ' '}
    };
    int jugador1 = 0, jugador2 = 0;
    std::string turno = "blancas";
    while(true){
        std::cout<<"\n Inicia el jugador de las fichas "<< turno;

        


        turno = (turno=="blancas")? "negras" : "blancas";
    }

    return 0;
}
