#ifndef PAQUETE_DATAGRAMA_H_
#define PAQUETE_DATAGRAMA_H_
#include <new>
#include <cstring>
#include <stdio.h>
using namespace std;

class PaqueteDatagrama {
    public:
        PaqueteDatagrama(char *, unsigned int, char *, int );
        PaqueteDatagrama(unsigned int );
        ~PaqueteDatagrama();
        
        void inicializaPuerto(int);
        void inicializaIp(char *);
        void inicializaDatos(char *);

        char *obtieneDireccion();
        unsigned int obtieneLongitud();
        int obtienePuerto();
        char *obtieneDatos();

    private:
        char *datos;            
        char ip[16];            
        unsigned int longitud;  
        //variable para puerto
        int puerto;             
};

#endif