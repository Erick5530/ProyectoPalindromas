Cliente: Cliente.o PaqueteDatagrama.o SocketDatagrama.o Solicitud.o 
	g++ -std=c++11 SocketDatagrama.o PaqueteDatagrama.o Cliente.o Solicitud.o -o Cliente -lpthread
Cliente.o: Cliente.cpp
	g++ Cliente.cpp -c 
Respuesta.o: Respuesta.cpp
	g++ Respuesta.cpp -c 
Solicitud.o: Solicitud.cpp
	g++ Solicitud.cpp -c 
PaqueteDatagrama.o: PaqueteDatagrama.cpp
	g++ PaqueteDatagrama.cpp -c 
SocketDatagrama.o:SocketDatagrama.cpp 
	g++ SocketDatagrama.cpp -c 
