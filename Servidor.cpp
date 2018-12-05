#include <iostream>
#include <cctype>
#include <algorithm>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include "Mensaje.h"
#include "Respuesta.h"
#include <vector>

char cadena2[255];
using namespace std;

int aux = 0;
    int contador = 0;

string ReplaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}

int funcion(string texto, int n){

    string strReturn = "";

    

    char output[5000];
    string palindromo = "";

    ofstream myfile;
    myfile.open ("text.txt");
    myfile << texto << "\0";
    myfile.close();
    
    ifstream myReadFile;
    myReadFile.open("text.txt");
    if (myReadFile.is_open()) {

        aux = 0;
        contador = 0;

        while (!myReadFile.eof()) {
            myReadFile >> output;
            aux++;
            //cout << "[" << output << "]\n";

            palindromo += output;
            std::transform(palindromo.begin(), palindromo.end(),palindromo.begin(), ::toupper);

            if(aux == n){
                string invertida(palindromo.rbegin(),palindromo.rend());
                if(palindromo == invertida){
                    cout << "---> [" << palindromo << "] == [" << invertida << "]" << endl;
                    contador++;
                    strReturn += palindromo + "~";
                }else{
                    //cout << "---> [" << palindromo << "] <> [" << invertida << "]" << endl;
                }

                aux = 0;
                palindromo = "";
            }
        }
    }

    myReadFile.close();
    
    return contador;

}


string funcion2(string texto, int n){

	string strReturn = "";

	string output = "";
 	string palindromo = "";
 	
	vector<string> v;

 	ifstream myReadFile;
  	myReadFile.open("text.txt");
 	if (myReadFile.is_open()) {

 		aux = 0;
		contador = 0;

 		while (!myReadFile.eof()) {
    		myReadFile >> output;
    		std::transform(output.begin(), output.end(),output.begin(), ::toupper);
			output = ReplaceAll(string(output), std::string(","), std::string(""));
			output = ReplaceAll(string(output), std::string("."), std::string(""));
			output = ReplaceAll(string(output), std::string("á"), std::string("A"));
			output = ReplaceAll(string(output), std::string("Á"), std::string("A"));
			output = ReplaceAll(string(output), std::string("é"), std::string("E"));
			output = ReplaceAll(string(output), std::string("É"), std::string("E"));
			output = ReplaceAll(string(output), std::string("í"), std::string("I"));
			output = ReplaceAll(string(output), std::string("Í"), std::string("I"));
			output = ReplaceAll(string(output), std::string("ó"), std::string("O"));
			output = ReplaceAll(string(output), std::string("Ó"), std::string("O"));
			output = ReplaceAll(string(output), std::string("ú"), std::string("U"));
			output = ReplaceAll(string(output), std::string("Ú"), std::string("U"));
			v.push_back(output);
 		}
	}

	myReadFile.close();
	
	for(int i=0; i<v.size(); i++){
		for(int j=i; j<v.size(); j++){
			//cout << "Palabra: " << palabra.v[j] << endl;
			aux++;
			palindromo += v[j];
	
			if(aux == n){
				//cout << "Palindromo:" << palindromo << endl;
				string invertida(palindromo.rbegin(),palindromo.rend());
				if(palindromo == invertida){
					cout << "[" << palindromo << "] == [" << invertida << "]" << endl;
					contador++;
					strReturn += palindromo + "~";
				}else{
					//cout << "---> [" << palindromo << "] <> [" << invertida << "]" << endl;
				}
				aux = 0;
				palindromo = "";
				i = j;
			}
		}
		//cout << "------------------------" << endl;
	}

	cout << "\nNumero palindromos: " << contador << endl;

	return strReturn;

}

int main(int argc, char*argv[]) {
    
    Respuesta respuesta(7200);
    int nbd = 0;
    int id_paquete = 0;
    int num_paquetes = 0;

    printf("%s\n", "Servidor conectado...");
    while(true) {

        cout<<"\t->Esperando peticion..."<<endl;
        struct mensaje *msg = respuesta.getRequest();
        string cadenaRecibida = msg->arguments;

        cout << "Texto a revisar : " << cadenaRecibida << endl;

        int nu = 5; //funcion2(cadenaRecibida,4);

        string res = funcion2(cadenaRecibida,4);

        //cout<<"contador = " << nu << endl;
        string resu = "Palabras palindromas identificadas : " + std::to_string( nu );

        cout << "RECIBIDO: " << res << endl;

        
        cout<<"\t\t->Recibido: "<<cadenaRecibida<<endl;
        num_paquetes = msg->operationId;
       // respuesta.sendReply((char *) resu.c_str() , msg->IP, msg->puerto);
         respuesta.sendReply((char *) res.c_str() , msg->IP, msg->puerto);
        fflush(stdin);

    }

}

