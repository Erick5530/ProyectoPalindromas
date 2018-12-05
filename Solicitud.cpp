#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Solicitud.h"

Solicitud::Solicitud(){
	socketlocal = new SocketDatagrama(0);
}

char *Solicitud::doOperation(char *IP, int puerto, int operationId, char *arguments,  int ident){

	//cout<< arguments << endl;
    //Preparamos envio
	struct mensaje *msj = (struct mensaje *) malloc(sizeof(mensaje));
	msj->messageType = 0;
    msj->requestId = ident;
    memcpy(msj->IP, IP, strlen(IP));
    msj->puerto = puerto;
    msj->operationId = operationId;
    memcpy(msj->arguments, arguments, strlen(arguments));

    //Enviamos contenido
    PaqueteDatagrama paquete(sizeof(mensaje));
    paquete.inicializaIp(IP);
    paquete.inicializaPuerto(puerto);
    paquete.inicializaDatos((char *)msj);

    PaqueteDatagrama respuesta(sizeof(struct mensaje));
    int n;
	int intento = 0;
	while(intento < 5) {
		cout << "Paquete enviado..." << endl;
        socketlocal->envia(paquete);
		///cout<<"\t->Esperando respuesta..."<<endl;
		n = socketlocal->recibeTimeout(respuesta, 5, 100);	

		cout << "respuetsa recibida : " << respuesta.obtieneDatos() << endl;	
		if(n > 0){
			break;
		}
		else{
			if (errno == EWOULDBLOCK)
				fprintf(stderr, "\t->Tiempo para recepción transcurrido\n");
			else
				fprintf(stderr, "Error en recvfrom\n");
			intento++;
		}
	}
	if (intento >= 5){
		cout<<"\t\t->El servidor no está disponible e intente más tarde."<<endl;

		//exit(0);
		//struct mensaje *msj_respuesta = (struct mensaje *) malloc(sizeof(mensaje));
    	//msj_respuesta = (struct mensaje *) respuesta.obtieneDatos();
		//memcpy(datos, cadena, sizeof(char)*longitud);
    	char *mensaje2 = (char*)malloc(sizeof(char)*4);
    	memcpy(mensaje2,"-1",sizeof(mensaje2));
    	//return (char*)mensaje2.c_str();
    	return mensaje2;
		
	}


	//cout << "aloo" << endl;
    struct mensaje *msj_respuesta = (struct mensaje *) malloc(sizeof(mensaje));
    msj_respuesta = (struct mensaje *) respuesta.obtieneDatos();
    
    return msj_respuesta->arguments;
}







