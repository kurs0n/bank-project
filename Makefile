Lib_path = -Lmysql-connector-c\lib
Inc_path = -Imysql-connector-c\include
add_path = -lmysql
OBJS = Interfaceaboutme.o Underinterface.o Interfacetransfer.o Menu.o Logininterface.o Account.o Systembank.o Databasecontroller.o
LIB = $(Lib_path) $(Inc_path) $(add_path)

make: $(OBJS)
	g++ -o bank $(OBJS) bankproject.cpp -std=c++11 $(LIB)

Interfaceaboutme.o: Interfaceaboutme\Interfaceaboutme.cpp
	g++ -c Interfaceaboutme\Interfaceaboutme.cpp $(LIB)

Underinterface.o: Underinterfacebase\Underinterface.cpp
	g++ -c Underinterfacebase\Underinterface.cpp $(LIB)
	
Interfacetransfer.o: Interfacetransfer\Interfacetransfer.cpp
	g++ -c Interfacetransfer\Interfacetransfer.cpp $(LIB)

Menu.o: Menu\Menu.cpp
	g++ -c Menu\Menu.cpp $(LIB)

Logininterface.o: Logininterface\Logininterface.cpp
	g++ -c Logininterface\Logininterface.cpp $(LIB)

Account.o: Account\Account.cpp
	g++ -c Account\Account.cpp $(LIB)

Systembank.o: Systembank\Systembank.cpp
	g++ -c Systembank\Systembank.cpp $(LIB)

Databasecontroller.o: Databasecontroller\Databasecontroller.cpp
	g++ -c Databasecontroller\Databasecontroller.cpp $(LIB)
clean:
	rm *.o




