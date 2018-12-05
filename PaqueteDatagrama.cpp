#include "PaqueteDatagrama.h"
#include <string>
#include <cstring>

PaqueteDatagrama::PaqueteDatagrama(char *cadena, unsigned int longitudDatagrama, char *direccionIP, int puertoPD){
	datos = new char[longitudDatagrama];
	longitud = longitudDatagrama;
	memcpy(datos, cadena, sizeof(char)*longitud);
	memcpy(ip, direccionIP, sizeof(char)*16);
	
	puerto = puertoPD;
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int longitudDatagrama){
	datos = new char[longitudDatagrama];
	longitud = longitudDatagrama;
}

PaqueteDatagrama::~PaqueteDatagrama(){
    //delete(datos);
}

//Inicializar para envio
void PaqueteDatagrama::inicializaPuerto(int puertoPD){
	puerto = puertoPD;
}

void PaqueteDatagrama::inicializaIp(char *direccionIP){
	memcpy(ip, direccionIP, sizeof(char)*16);
}

void PaqueteDatagrama::inicializaDatos(char *cadena){

	//string dat(cadena);
	//datos = (char*)dat.c_str();
    memcpy(datos, cadena, longitud);


}

//Obtenemos datos
char *PaqueteDatagrama::obtieneDireccion(){
	return ip;
}

int PaqueteDatagrama::obtienePuerto(){
	return puerto;
}

unsigned int PaqueteDatagrama::obtieneLongitud(){
	return longitud;
}

char *PaqueteDatagrama::obtieneDatos(){
	return datos;
}





