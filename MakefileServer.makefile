Servidor: Servidor.o PaqueteDatagrama.o SocketDatagrama.o Respuesta.o
	g++ SocketDatagrama.o PaqueteDatagrama.o Servidor.o Respuesta.o -o Servidor
Servidor.o: Servidor.cpp
	g++ Servidor.cpp -c 
Respuesta.o: Respuesta.cpp
	g++ Respuesta.cpp -c 
Solicitud.o: Solicitud.cpp
	g++ Solicitud.cpp -c 
PaqueteDatagrama.o: PaqueteDatagrama.cpp
	g++ PaqueteDatagrama.cpp -c 
SocketDatagrama.o:SocketDatagrama.cpp 
	g++ SocketDatagrama.cpp -c 
