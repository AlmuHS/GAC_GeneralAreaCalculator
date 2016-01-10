
#include <iostream>
#include <cstdlib>

class command_line{
    int num_argumentos;
    char *argumentos[];

    public:

    command_line();
    void evaluar_argumentos();
}
