#include"contacto.h"
#include"agenda.h"

int main(){
	int opc;
	Agenda a;
	string dni;
	Contacto c;

	




	do{
		
		cout<<"------------------\n";
		cout<<"Agenda electronica\n";
		cout<<"------------------\n";
		cout<<"1. Agregar contacto \n";
		cout<<"2. Buscar contacto \n";
		cout<<"3. Modificar datos \n";
		cout<<"4. Imprimir listado \n";
		cout<<"5. Eliminar contacto \n";
		cout<<"6. Salir \n";

		cout<<"Ingrese la opcion deseada: ";
		cin>>opc;
		
		switch(opc){

			case 1: 
				a.insertarContacto();
				break;
			case 2:
				cout<<"Introduzca el dni a buscar"<<endl;
				cin>>dni;

				if(a.buscarContacto(dni,c))
				{
					cout<<"DATOS DEL CONTACTO:"<<endl;
					c.mostrarContacto();
				}
				else
					cout<<"Elemento no existente"<<endl;
				break;
			case 3:
				cout<<"Introduzca el dni a buscar"<<endl;
				cin>>dni;

				a.modificar(dni);
			break;
			case 4:
				a.mostrarAgenda();

			break;
			case 5:
				cout<<"Introduzca el dni a buscar"<<endl;
				cin>>dni;

				a.eliminar(dni);
			break;
		}
		
		}while (opc!=6);
return 0;
		

}
