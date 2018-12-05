#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <thread>
#include "Solicitud.h"

using namespace std;

void fnchilo1(string ip,int puerto,int operacion,char* consultas,int id){
	Solicitud cliente1;
	char *resp = cliente1.doOperation((char*)ip.c_str(), puerto, operacion, consultas, id);
	string resp1(resp);
	string aux="-1";
	if(aux.compare(resp1)==0){
		fnchilo1("127.0.0.1",puerto,operacion,consultas,id);
		cout << "si entro" << endl;

		printf("Si entro\n");

	}
	cout<< resp1 <<endl;
}

void fnchilo2(string ip,int puerto,int operacion,char* consultas,int id){
	Solicitud cliente2;
	char *resp = cliente2.doOperation((char*)ip.c_str(), puerto, operacion, consultas, id);
	cout<< resp <<endl;
}

void fnchilo3(string ip,int puerto,int operacion,char* consultas,int id){
	Solicitud cliente3;
	char *resp = cliente3.doOperation((char*)ip.c_str(), puerto, operacion, consultas, id);
	cout<< resp <<endl;
}

int main(int argc, char *argv[]) {
	

	string iperick,ipbarrios,ipmanuel,iplocal;
	iperick="127.0.0.1";
	//memcpy(iperick)
	//ipbarrios="10.100.76.233";
	//iplocal="10.100.65.94";
	iplocal="127.0.0.1";

	
	string mensageOriginal = "Anita lava la tina asd fgh hgf dsa qw er re wq"; 
	int longitudCadena = (mensageOriginal.length())/1;
	string consultas = mensageOriginal.substr (0,longitudCadena);
	//string consultas2 = mensageOriginal.substr (longitudCadena,2*longitudCadena);	
	//string consultas3 = mensageOriginal.substr (2*longitudCadena,mensageOriginal.length());	

	//cout << "Parte 1 : " << consultas << endl;
	//cout << "Parte 2 : " << consultas2 << endl;
	//cout << "Parte 3 : " << consultas3 << endl;

	int puerto = atoi(argv[1]);
	int operacion = 1;
	int id_mensaje = 1;
	int dbo = 0;

	thread th1(fnchilo1,iperick,puerto,operacion,(char*)consultas.c_str(),-11);
	//thread th2(fnchilo2,iplocal,puerto,operacion,(char*)consultas2.c_str(),-11);
	//thread th3(fnchilo3,iplocal,puerto,operacion,(char*)consultas3.c_str(),-11);


	th1.join();
	//th2.join();
	//th3.join();
    return 0;
}
