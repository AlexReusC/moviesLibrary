#ifndef VIDEO_H_INCLUDED
#define VIDEO_H_INCLUDED
#include <vector>
#include <string>
#include <ostream>


class Video{
  protected:
    std::string tipo;
    std::string nombre;
    std::string genero;
    std::string id;
    int duracion;
    std::vector<double> calificacion;
  public:
    Video(std::string Inom, std::string Igen, std::string Iid, int Idura, std::vector<double> Icali){
      nombre = Inom;
      genero =  Igen;
      id = Iid;
      duracion = Idura;
      calificacion = Icali;
    }

    std::string getTipo(){
      return tipo;
    }

    std::string getGenero(){
      return genero;
    }

    double getCalificacion(){
      double promCalif = 0;
      for(int i=0; i<calificacion.size(); i++){
        promCalif+=calificacion[i];
      }
      return promCalif/calificacion.size();
    }

    virtual void AddCalificacion(double calificacionNueva){
      calificacion.push_back(calificacionNueva);
    }

    virtual void mostrarAtribs()=0;

    virtual void mostrarAtribs(int i)=0;

    virtual std::string mostrarPerteneciente()=0;

    friend std::ostream& operator<<(std::ostream& os, Video &tn){
      return os <<"Tipo: " << tn.tipo << " Nombre: " << tn.nombre << " Genero: " << tn.genero << " Id: " <<
      tn.id << " Duracion: " << tn.duracion <<" Calificacion: " << tn.getCalificacion() << "\n";
    }

};



#endif
