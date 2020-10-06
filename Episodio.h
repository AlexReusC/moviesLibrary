#ifndef EPISODIO_H_INCLUDED
#define EPISODIO_H_INCLUDED
#include "Video.h"
#include <string>
#include <ostream>


class Episodio: public Video{
  private:
    std::string serie;
    int episodio;
    int temporada;
  public:

    void mostrarAtribs(){
      std::cout << serie << " " <<temporada << " " << episodio<< " " << nombre << " " << " " << genero <<
      " " << duracion << " mins " << getCalificacion() << " puntos\n";
    }

    void mostrarAtribs(int i){
      std::cout <<temporada << " " << episodio<< " " << nombre << " " << " " << genero <<
      " " << duracion << " mins " << getCalificacion() << " puntos\n";

    }

    std::string mostrarPerteneciente(){
      return serie;
    }


    std::string getSerie(){
      return serie;
    }

    Episodio(std::string Inom, std::string Igen, std::string Iid, int Idura, std::vector<double> Icali, std::string Iserie, int Itemporada, int Iepisodio):
    Video(Inom,Igen,Iid,Idura,Icali){
      tipo = "serie";
      serie = Iserie;
      temporada = Itemporada;
      episodio = Iepisodio;
    }
};




#endif
