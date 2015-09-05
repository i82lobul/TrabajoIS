#ifndef AGENDA_H
#define AGENDA_H

#include"contacto.h"
#include<fstream>
#include<list>
#include<cstdlib>

class Agenda
{
	private:

		list<Contacto> _lcontactos;

	public:

		Agenda()
		{
			//abre el fichero y si tiene datos los almacena en la lista	
			Contacto c;
			char DNI[50], email[50], nombre[50], apellidos[50], telefono[50]; 
			struct cita citas;
			struct redSocial red;
			struct direccion dir;

			ifstream f;
  			f.open("contactos.txt", ios::in); 

 			 if(f)
			{
				while (f.getline(DNI,256,',')) 
   				 { 
					f.getline(nombre,256,',');
					f.getline(apellidos,256,',');
					f.getline(dir.tipoVia,256,',');
					f.getline(dir.nombre,256,',');	
					f.getline(dir.numero,256,',');
					f.getline(dir.codigoPostal,256,',');
					f.getline(dir.ciudad,256,',');
					f.getline(dir.provincia,256,',');
					f.getline(email,256,',');
					f.getline(telefono,256,',');
					f.getline(citas.fecha,256,',');
					f.getline(citas.hora,256,',');
					f.getline(citas.motivo,256,',');
					f.getline(red.facebook,256,',');
					f.getline(red.twitter,256,',');
					f.getline(red.instagram,256,'\n');


					c.setDNI(DNI);
					c.setNombre(nombre);
					c.setApellidos(apellidos);
					c.setEmail(email);
					c.setTelefono(atoi(telefono));
					c.setCita(citas);
					c.setRed(red);
					c.setDireccion(dir);
					
					
					
					_lcontactos.push_back(c);
				}

			f.close(); 	

			}
   				 
		}

		void insertarContacto()
		{
			
			Contacto c;

			c.leerContacto(c);

			if(!buscarContacto(c.getDNI(),c))
			{
				_lcontactos.push_back(c);
			}		
		}

		void mostrarAgenda()
		{

			list<Contacto>::iterator i;
	
			for(i=_lcontactos.begin(); i != _lcontactos.end(); ++i)
			{
				cout<<endl<<"CONTACTO:"<<endl;
				(*i).mostrarContacto();
			}

		}

		void modificar(string dni)
		{
			Contacto c;
			struct cita aux;
			struct direccion dir;
			if(buscarContacto(dni,c))
			{
				list<Contacto>::iterator i;
				int n,opcme;
				char res;
				string var;
				
	
				for(i=_lcontactos.begin(); i != _lcontactos.end(); ++i)
				{
					if((*i).getDNI()==dni)
					{
						do{
						cout<<"Que desea modificar "<<endl;
						cout<<"1. Dni\n"<<endl;
						cout<<"2. Nombre\n"<<endl;
						cout<<"3. Apellidos\n"<<endl;
						cout<<"4. Telefono\n"<<endl;
						cout<<"5. Direccion\n"<<endl;
						cout<<"6. Correo\n"<<endl;
						cout<<"7. Cita\n"<<endl;
						cin>>opcme;
						switch(opcme){

						case 1:
							cout<<"Introduzca el dni: "<<endl;
							cin>>var;
							(*i).setDNI(var);
						break;
						case 2:
							cout<<"Introduzca el nombre: "<<endl;
							cin>>var;
							(*i).setNombre(var);
						break;

						case 3:
							cout<<"Introduzca los apellidos: "<<endl;
							cin>>var;
							(*i).setApellidos(var);
						break;

						case 4:
							cout<<"Introduzca el telefono: "<<endl;
							cin>>var;
							(*i).setTelefono(n);
						break;

						case 5:
							cout<<"Introduzca tipo de via "<<endl;
							cin>>dir.tipoVia;
							
							cout<<"Introduzca el nombre de la via "<<endl;
							cin>>dir.nombre;
							

							cout<<"Introduzca el numero del domicilio "<<endl;
							cin>>dir.numero;

							cout<<"Introduzca el codigo postal "<<endl;
							cin>>dir.codigoPostal;
							
							cout<<"Introduzca la ciudad"<<endl;
							cin>>dir.ciudad;

							cout<<"Introduzca la provincia"<<endl;
							cin>>dir.provincia;
							


							(*i).setDireccion(dir);
						break;

						case 6:
							cout<<"Introduzca el correo: "<<endl;
							cin>>var;
							(*i).setEmail(var);
						break;

						case 7:
							cout<<"Introduzca la nueva fecha: "<<endl;
							cin>>aux.fecha;
							while(getchar()!='\n');
							cout<<"Introduzca la nueva hora: "<<endl;
							cin>>aux.hora;
							while(getchar()!='\n');

							cout<<"Introduzca el nuevo motivo: "<<endl;
							cin>>aux.motivo;

							(*i).setCita(aux);
							
						break;
						}
						cout<<"Teclee S si desea modificar otro campo, es caso contrario teclee N"<<endl;
						cin>>res;

						}while(res=='s' || res=='S');
					}	
				}		
			}
			else
			{
				cout<<"ERROR contacto no encontrado en la agenda"<<endl;
			}	
			
		}

		int buscarContacto(string dni, Contacto &c)
		{
			if(_lcontactos.empty())
				return 0;
			else
			{
				list<Contacto>::iterator i;
	
				for(i=_lcontactos.begin(); i != _lcontactos.end(); ++i)
				{
					if((*i).getDNI()==dni)
					{
						c=*i;
						return 1;
					}
				}	
				return 0;
			}
		}

		void eliminar(string dni)
		{
			Contacto c;
			int enc=0;
			if(buscarContacto(dni,c))
			{
	
				list<Contacto>::iterator i;
	
				for(i=_lcontactos.begin(); i != _lcontactos.end()&&enc==0; ++i)
				{
					if((*i).getDNI()==dni)
					{
						enc=1;
						_lcontactos.erase(i);
						cout<<"Contacto borrado"<<endl;
					}	
				}	
				
			}
			else
			{
				cout<<"ERROR contacto no existente"<<endl;
			}
		}

		~Agenda()
		{
			/*Utilizo el destructor para asegurarme la persistencia de la agenda ya que cada vez que cerremos el programa, este mismo se encargara de actualizar nuestro fichero txt*/
			
		 	if(!_lcontactos.empty())
			{
				
				list<Contacto>::iterator i;
				ofstream f;
  				f.open("contactos.txt", ios::out); 
				for(i=_lcontactos.begin(); i != _lcontactos.end(); ++i)
				{
					f<<(*i).getDNI()<<","<<(*i).getNombre()<<","<<(*i).getApellidos()<<","<<(*i).getDireccion().tipoVia<<","<<(*i).getDireccion().nombre<<","<<(*i).getDireccion().numero<<","<<(*i).getDireccion().codigoPostal<<","<<(*i).getDireccion().ciudad<<","<<(*i).getDireccion().provincia<<","<<(*i).getEmail()<<","<<(*i).getTelefono()<<","<<(*i).getCita().fecha<<","<<(*i).getCita().hora<<","<<(*i).getCita().motivo<<","<<(*i).getRed().facebook<<","<<(*i).getRed().twitter<<","<<(*i).getRed().instagram<<"\n";
						
				}

				f.close();	
				
			}
		}

};

#endif
