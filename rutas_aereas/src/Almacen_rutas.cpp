//
// Created by zapi24 on 13/12/23.
//

#include "Almacen_rutas.h"

void Almacen_rutas::Insertar(const Ruta &r) {

    rutas.emplace(r.GetCode(),r); //Insertamos el code de la ruta y la ruta
}

void Almacen_rutas::Borrar(const Ruta &r) {

    rutas.erase(r.GetCode());   //Borramos la ruta con determinado Code
}

Ruta Almacen_rutas::GetRuta(const std::string &a) {

    auto it = rutas.find(a);    //Me devuelve la posicion del map donde se encuentra la ruta seleccionada

    return (*it).second; //Devuelvo la ruta
}



Almacen_rutas::iterator &Almacen_rutas::iterator::operator++() {
    ++p;
    return *this;
}

Almacen_rutas::iterator &Almacen_rutas::iterator::operator--() {

    ++p;
    return *this;
}

const pair<string,Ruta> &Almacen_rutas::iterator::operator*() {

    return *p;
}

bool Almacen_rutas::iterator::operator==(const Almacen_rutas::iterator &i) const {

    return i.p == p;
}

bool Almacen_rutas::iterator::operator!=(const Almacen_rutas::iterator &i) const {

    return i.p != p;
}

Almacen_rutas::const_iterator &Almacen_rutas::const_iterator::operator++() {

    ++p;
    return *this;
}

Almacen_rutas::const_iterator &Almacen_rutas::const_iterator::operator--() {

    --p;
    return *this;
}

const pair<string,Ruta> &Almacen_rutas::const_iterator::operator*() {

    return *p;
}

bool Almacen_rutas::const_iterator::operator==(const Almacen_rutas::const_iterator &i) const {

    return i.p == p;
}

bool Almacen_rutas::const_iterator::operator!=(const Almacen_rutas::const_iterator &i) const {

    return i.p == p;
}

Almacen_rutas::iterator Almacen_rutas::begin(){

    iterator it;
    it.p = rutas.begin();

    return it;
}

Almacen_rutas::iterator Almacen_rutas::end(){

    iterator it;
    it.p = rutas.end();

    return it;
}

Almacen_rutas::const_iterator Almacen_rutas::begin() const{

    const_iterator it;
    it.p = rutas.cbegin();

    return it;
}

Almacen_rutas::const_iterator Almacen_rutas::end() const{

    const_iterator it;
    it.p = rutas.cend();

    return it;
}

istream &operator>>(std::istream &is, Almacen_rutas & AR){
    Almacen_rutas rlocal;
    //leemos el comentario
    if (is.peek()=='#'){
        string a;
        getline(is,a);
    }

    Ruta r;

    while(is>>r){

        rlocal.Insertar(r);
    }
    AR = rlocal;
    return is;
}

ostream &operator<<(std::ostream &os, const Almacen_rutas & AR){

    for( auto it = AR.rutas.begin() ; it != AR.rutas.end() ; ++it){

        os << (*it).second; //La sintaxis de ruta es string, n_puntos, puntos

    }

    return os;
}
