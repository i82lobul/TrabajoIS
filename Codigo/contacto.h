#ifndef CONTACTO_H
#define CONTACTO_H

#include<iostream>
#include<cstdio>


using namespace std;

struct cita {
  char fecha[20];  
  char hora[20]; 
  char motivo[50];
};

struct redSocial{
  char facebook[50];
  char twitter[50];
  char instagram[50];		
};

struct direccion{
  char tipoVia[50];
  char nombre[50];
  char numero[50];
  char codigoPostal[50];
  char ciudad[50];
  char provincia[50];	


};

class Contacto
{
	private:
		string _DNI;
		string _nombre;
		string _apellidos;
		string _email;
		struct direccion _dir;
		int _telefono;
		struct cita _citas;
		struct redSocial _red;

	

	public:
	
	Contacto()
	{

	}
	struct direccion getDireccion() const
	{
		return _dir;
	}

	void setDireccion(struct direccion dir)
	{
		_dir=dir;
	}
	
	struct redSocial getRed() const
	{
		return _red;
	}

	void setRed(struct redSocial red)
	{
		_red=red;
	}

	struct cita getCita() const
	{
		return _citas;
	}

	void setCita(struct cita citas)
	{
		_citas=citas;
	}
	
	string getEmail() const
	{

		return _email;	
	}

	void setEmail(string email)		
	{

		_email=email;
	}


	int getTelefono() const
	{

		return _telefono;	
	}

	void setTelefono(int telefono)
	{

		_telefono=telefono;
	}
	
			
	string getDNI() const
	{
		return _DNI;
	}

	void setDNI(string DNI)
	{
		_DNI=DNI;
	}
	
	string getNombre() const
	{

		return _nombre;
	}

	void setNombre(string nombre)
	{
		_nombre=nombre;
	}
	
	string getApellidos() const
	{

		return _apellidos;
	}

	void setApellidos(string apellidos)
	{

		_apellidos=apellidos;
	}

	
	void mostrarContacto()
	{
		cout<<"dni:"<<getDNI()<<endl<<"nombre:"<<getNombre()<<endl<<"apellido:"<<getApellidos()<<endl<<"telefono:"<<getTelefono()<<endl<<"Direccion: "<<endl<<"Tipo de Via: "<<getDireccion().tipoVia<<" "<<"Nombre: "<<getDireccion().nombre<<" "<<"Numero: "<<getDireccion().numero<<endl<<"Codigo Postal: "<<getDireccion().codigoPostal<<" "<<"Poblacion: "<<getDireccion().ciudad<<" "<<"Provincia: "<<getDireccion().provincia<<endl<<"email:"<<getEmail()<<endl<<"Fecha de la Cita: "<<getCita().fecha<<endl<<"Hora de la Cita "<<getCita().hora<<endl<<"Motivo de la cita: "<<getCita().motivo<<endl<<"Facebook: "<<getRed().facebook<<endl<<"Twitter: "<<getRed().twitter<<endl<<"Instagram: "<<getRed().instagram<<endl;

	}
	void leerContacto(Contacto &c)
	{

	
		string DNI;
		char nombre[200];
		char apellidos[200];
		int telefono;
		struct direccion dir;
		string email;
		struct cita citas;
		struct redSocial red;

		cout<<"Introduzca el DNI del contacto"<<endl;
		cin>>DNI;
		while(getchar()!='\n');
		cout<<"Introduzca el nombre del contacto"<<endl;
		cin.getline(nombre,200); 
		cout<<"Introduzca los apellidos del contacto"<<endl;
		cin.getline(apellidos,200); 
		cout<<"Introduzca el telefono del contacto"<<endl;
		cin>>telefono;
			while(getchar()!='\n');
		cout<<"Tipo de via del domicilio--->Calle/Avenida/Plaza"<<endl;
		cin.getline(dir.tipoVia,200);
	
		cout<<"Indique el nombre de la via"<<endl;
		cin.getline(dir.nombre,200);

		cout<<"Numero"<<endl;
		cin.getline(dir.numero,200);

		cout<<"Codigo Postal"<<endl;
		cin.getline(dir.codigoPostal,200);

		cout<<"Poblacion"<<endl;
		cin.getline(dir.ciudad,200);

		cout<<"Provincia"<<endl;
		cin.getline(dir.provincia,200);
			

/* char tipoVia[50];
  char nombre[50];
  int  numero;
  int  codigoPostal;
  char ciudad[50];
  char provincia[50];*/


		cout<<"Introduzca el email del contacto"<<endl;
		cin>>email;
		while(getchar()!='\n');

		cout<<"Introduzca la fecha de la cita"<<endl;
		cin.getline(citas.fecha,200);

		cout<<"Introduzca la hora de la cita"<<endl;
		cin.getline(citas.hora,200);

		cout<<"Introduzca el motivo de la cita"<<endl;
		cin.getline(citas.motivo,200);

		cout<<"A continuacion indicanos si el contacto posee algunas de estas cuentas"<<endl;
		cout<<"En caso contrario escribe 'no'"<<endl;
		cout<<"facebook"<<endl;
		cin>>red.facebook;

		cout<<"twitter"<<endl;
		cin>>red.twitter;

		cout<<"instagram"<<endl;
		cin>>red.instagram;

			

		c.setDNI(DNI);
		c.setNombre(nombre);
		c.setApellidos(apellidos);
		c.setTelefono(telefono);
		c.setDireccion(dir);
		c.setEmail(email);
		c.setCita(citas);
		c.setRed(red);

		
	}



};
#endif
