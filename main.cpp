/*
Internet Movie Dan Base(IMDB)
Proyecto Integrador
Alejandro Castro Reus
A01731065
*/


#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"
using namespace std;

vector<Video*> biblioteca;
vector<string> series;

int imprimir(){
  // Función para imprimir las opciones y regresar valores
  int operador;
  cout << "1) Cargar archivos de datos\n";
  cout << "2) Mostrar los videos con una cierta calificacion o de un genero\n";
  cout << "3) Mostrar los episodios de una determinada serie con una calificacion determinada \n";
  cout << "4) Mostrar las peliculas con cierta calificacion \n";
  cout << "5) Calificar un video\n";
  cout << "0) Salir\n";
  cout << "Escoge una opcion:  ";
  cin >> operador;
  cin.ignore();
  return operador;
}      //Mostrar menu

void openFiles(){
  string nombreArchivo;
  ifstream infile("pelis.txt");
  biblioteca.clear();
  series.clear();
  while (true){


    char tipo;
    string nombre, nomEp, genero, codigo;
    int duracion, anio, temporada, nuEp;
    double calificacion;
    vector<double> vecCalifs;

    infile >> tipo;
    if (tipo=='K')
      break;

    else if(tipo=='P'){
      infile >> nombre >> anio >> genero >> codigo >> duracion;
      while(infile >> calificacion){
        if (calificacion==-1)
          break;
        vecCalifs.push_back(calificacion);
      }
      biblioteca.push_back(new Pelicula(nombre, genero, codigo, duracion, vecCalifs, anio));

    }
    else if(tipo=='S'){
      infile>> nombre>> temporada>> nuEp>> nomEp>> genero>> codigo>> duracion;
      int serieExistente=0;
      for(int i=0; i<series.size(); i++){
        if (nombre==series[i]){
          serieExistente=1;
          break;
        }
      }
      if (serieExistente==0)
        series.push_back(nombre);
      while(infile >> calificacion){
        if (calificacion==-1)
          break;
        vecCalifs.push_back(calificacion);
      }
    biblioteca.push_back(new Episodio(nomEp, genero, codigo, duracion, vecCalifs, nombre, temporada, nuEp));
    }
  }
}    //Case 1: abrir archivos y crear objetos

void showVideos(){
  if(biblioteca.size()==0)
    cout<<"No se ha cargado ningun video en biblioteca, cargalos en el 1) del menu\n";
  else{
    while(true){
      int eleccion;
      cout << "Mostrar videos por 1)Genero, 2)Calificacion, 3)Volver al menu principal\n";
      cin >> eleccion;

      if (eleccion==1){
        string Genero;
        cout<< "1)Accion\n2)Drama\n3)Comedia\n";
        cin >> eleccion;
        if (eleccion==1)
          Genero="Accion";
        else if(eleccion==2)
          Genero="Drama";
        else if(eleccion==3)
          Genero="Comedia";
        string generoPel;
        for(int i=0; i<biblioteca.size();i++){
          if (biblioteca[i]->getGenero() == Genero)
            biblioteca[i]->mostrarAtribs();
        }
      }
      else if(eleccion==2){
        double calificacionMayor, calificacionMenor;
        cout<<"Escoge la calificacion minima:\n";
        cin >> calificacionMenor;
        cout<<"Calificacion maxima:\n";
        cin >> calificacionMayor;
        double calificacionVideo;
        for(int i=0; i<biblioteca.size();i++){
          calificacionVideo=biblioteca[i]->getCalificacion();
          if(calificacionVideo>=calificacionMenor && calificacionVideo <= calificacionMayor)
            biblioteca[i]->mostrarAtribs();
        }
      }
      else if(eleccion==3)
        break;
      else
        cout<< "No existe esa opcion, vuelve a intentarlo\n";
    }
  }
} //Case 2: Mostrar los videos de cierto genero o calificacion

void showEpisodes(){
  if(series.size()==0)
    cout<<"No se ha cargado ninguna serie, carga en el 1) del menu\n";
  else{
    int EleccionSerie;
    string serie;
    cout<<"Escoge el numero de la serie que quieras ver sus episodios\n";
    for(int i=0; i<series.size();i++){
      cout << i+1 << ") " << series[i] <<"\n";
    }
    cin>>EleccionSerie;
    EleccionSerie--;
    serie=series[EleccionSerie];
    int noInstance=0;
    double calificacionMayor, calificacionMenor;
    cout<<"Escoge la calificacion(1-5) minima:\n";
    cin >> calificacionMenor;
    cout<<"Calificacion maxima:\n";
    cin >> calificacionMayor;
    double calificacionVideo;
    for(int i=0; i<biblioteca.size();i++){
      if(biblioteca[i]->getTipo()=="serie"){
        calificacionVideo=biblioteca[i]->getCalificacion();
        if(biblioteca[i]->mostrarPerteneciente()==serie && calificacionVideo>=calificacionMenor && calificacionVideo<=calificacionMayor){
          noInstance=1;
          biblioteca[i]->mostrarAtribs(1);
        }

    }
  }
    if(noInstance==0)
      cout<<"No existe video con esas caracteristicas\n";
  }
} //mostrar episodios de una serie con una calificacion

void showMovies(){
  if(series.size()==0)
    cout<<"No se ha cargado ninguna pelicula, carga en el 1) del menu";
  else{
    int noInstance=0;
    double calificacionMayor, calificacionMenor, calificacionVideo;
    cout<<"Escoge la calificacion(1-5) minima:\n";
    cin >> calificacionMenor;
    cout<<"Calificacion maxima:\n";
    cin >> calificacionMayor;
    for(int i=0; i<biblioteca.size(); i++){
      if(biblioteca[i]->getTipo()=="pelicula"){
        calificacionVideo=biblioteca[i]->getCalificacion();
        if(calificacionVideo>=calificacionMenor && calificacionVideo<=calificacionMayor){
          noInstance=1;
          biblioteca[i]->mostrarAtribs();
        }
      }
    }
    if (noInstance==0){
      cout<<"No existe video con esas caracteristicas\n";
    }
  }
} //mostrar pelicula con una calificacion

void gradeVideo(){
  if(biblioteca.size()==0){
    cout<<"No se ha cargado ningun video, carga en el 1) del menu\n";
  }

  else{
    int eleccion;
    double calificacion;
    cout<<"Escoge un video:\n";
    for(int i=0; i<biblioteca.size(); i++){
      cout<<i+1<<") ";
      biblioteca[i]->mostrarAtribs();
    }
    cin>>eleccion;
    while(eleccion>biblioteca.size()){
      cout<<"No existe ese numero, vuelve a intentar\n";
      cin>>eleccion;
    }
    eleccion--;
    cout<<"Que calificacion le vas a dar (entre 1 y 5)?\n";
    cin>>calificacion;
    biblioteca[eleccion]->AddCalificacion(calificacion);
    biblioteca[eleccion]->mostrarAtribs();
  }

}

int main(){
  while(true){
    int eleccion=imprimir();
    switch(eleccion){
      //cargar archivos de datos
      case 1:
        openFiles();
        cout<<"Videos cargados: \n";
        for(int i=0; i<biblioteca.size(); i++)
          cout<<*biblioteca[i];
        break;
      case 2:
        showVideos();
        break;
      case 3:
        showEpisodes();
        break;
      case 4:
        showMovies();
        break;
      case 5:
        gradeVideo();
        break;
      case 0:
        cout<<"Programa terminado";
        return 0;
        break;
    }
  }
  return 0;
}
