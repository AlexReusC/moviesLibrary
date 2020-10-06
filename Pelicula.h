#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED
#include <vector>
#include <ostream>
#include "Video.h"


class Pelicula:public Video{
  private:
    int anio;
  public:
    void mostrarAtribs(){
      std::cout << nombre << " " << anio << " "<< genero << " "<<
       duracion << " mins " << getCalificacion() << " puntos\n";
    }

    void mostrarAtribs(int i){
  
    }

    std::string mostrarPerteneciente(){
      return nombre;
    }

    Pelicula(std::string Inom, std::string Igen, std::string Iid, int Idura, std::vector<double> Icali, int Ianio):
    Video(Inom,Igen,Iid,Idura,Icali){
      tipo = "pelicula";
      anio=Ianio;
    }
};

#endif
