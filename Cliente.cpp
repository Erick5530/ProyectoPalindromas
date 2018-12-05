#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <thread>
#include "Solicitud.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <streambuf>
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream, std::stringbuf



using namespace std;


string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

void tokenize(std::string const &str, const char delim,
			std::vector<std::string> &out)
{
	size_t start;
	size_t end = 0;

	while ((start = str.find_first_not_of(delim, end)) != std::string::npos)
	{
		end = str.find(delim, start);
		out.push_back(str.substr(start, end - start));
	}


}

void fnchilo1(string ip,int puerto,int operacion,char* consultas,int id){
	Solicitud cliente1;
	char *resp = cliente1.doOperation((char*)ip.c_str(), puerto, operacion, consultas, id);
	string resp1(resp);
	string aux="-1";

	const char delim = '~';

	std::vector<std::string> out;
	tokenize(resp1, delim, out);

	for (auto &resp1: out) {
		std::cout << resp1 << '\n';
	}
	
	/*if(aux.compare(resp1)==0){
		fnchilo1("127.0.0.1",puerto,operacion,consultas,id);
		cout << "si entro" << endl;

		printf("Si entro\n");

	}*/
	//cout<< resp1[0] <<endl;
}

void fnchilo2(string ip,int puerto,int operacion,char* consultas,int id){
	Solicitud cliente2;
	char *resp1 = cliente2.doOperation((char*)ip.c_str(), puerto, operacion, consultas, id);
	

	const char delim = '~';

	std::vector<std::string> out;
	tokenize(resp1, delim, out);

	for (auto &resp1: out) {
		std::cout << resp1 << '\n';
	}


	//cout<< resp <<endl;
}

void fnchilo3(string ip,int puerto,int operacion,char* consultas,int id){
	Solicitud cliente3;
	char *resp = cliente3.doOperation((char*)ip.c_str(), puerto, operacion, consultas, id);
	cout<< resp <<endl;
}

int main(int argc, char *argv[]) {


	

	string iperick,ipbarrios,ipManuel,iplocal;
	ipManuel="192.168.0.123";
	iplocal="127.0.0.1";
	int n = atoi(argv[2]);

	std::ifstream t("text.txt");
	std::stringstream buffer;
	buffer << t.rdbuf();

	string mensageOriginal = buffer.str();


	cout << mensageOriginal << endl;


	mensageOriginal = ReplaceAll(string(mensageOriginal), std::string("~"), std::string(""));
	int longitudCadena = (mensageOriginal.length())/2;
	string consultas = mensageOriginal.substr (0,longitudCadena) + "~" + std::to_string( n );
	string consultas2 = mensageOriginal.substr (longitudCadena,mensageOriginal.length()) + "~" + std::to_string( n );	


//	cout << "aqui 1 " << endl;
	//string consultas3 = mensageOriginal.substr (2*longitudCadena,mensageOriginal.length());	

	//cout << "Parte 1 : " << consultas << endl;
	//cout << "Parte 2 : " << consultas2 << endl;
	//cout << "Parte 3 : " << consultas3 << endl;

	int puerto = atoi(argv[1]);
	int operacion = 1;
	int id_mensaje = 1;
	int dbo = 0;

	thread th1(fnchilo1,ipManuel,puerto,operacion,(char*)consultas.c_str(),-11);
	//thread th2(fnchilo2,iplocal,puerto,operacion,(char*)consultas2.c_str(),-11);
	//thread th3(fnchilo3,iplocal,puerto,operacion,(char*)consultas3.c_str(),-11);

//cout << "aqui 2 " << endl;
	th1.join();
	//th2.join();
	//th3.join();
    return 0;
}
