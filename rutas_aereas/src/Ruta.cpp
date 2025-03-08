//
// Created by zapi24 on 13/12/23.
//

#include "Ruta.h"

Ruta::Ruta() {

    code="";
}

void Ruta::Insertar(const Punto &n) {

    puntos.push_back(n);
    code = "patata";
}

void Ruta::Borrar(const Punto &n) {

    puntos.remove(n);
}

string Ruta::GetCode() const {

    return code;
}

void Ruta::SetCode(const std::string &code) {

    (*this).code = code;
}

bool Ruta::operator==(const Ruta &R) const {

    if(code != R.code || R.puntos.size() != puntos.size() ){ //Comprobamos el code y el numero de puntos

        return false;
    }

    list<Punto>::const_iterator it1,it2;
    it1 = puntos.begin();
    it2 = R.puntos.begin();

    while (it1 != puntos.end()){
        if ((*it1) != (*it2)){  //He implementado el operador != dentro de punto

            return false;
        }
        ++it1;
        ++it2;
    }

        return true;
}

bool Ruta::operator<(const Ruta &R) const {
    bool menor =false;

    //Primero comparamos el numero de puntos de cada ruta

    if(R.puntos.size() == puntos.size()){  // Si la cantidad de puntos es igual, comparar punto por punto
        list<Punto>::const_iterator it1,it2;
        it1 = puntos.begin();
        it2 = R.puntos.begin();

        while (it1 != puntos.end() && !menor){ //Cuando encuentre al primer punto menor, que pare de buscar
            if ((*it1) <(*it2)){

                menor = true;
            }
            ++it1;
            ++it2;
        }
    }
    else if(R.puntos.size() < puntos.size()){

        menor = true; //Es menor
    }
    else{

        menor = false;  //Es mayor
    }

    return menor;
}

Ruta::iterator &Ruta::iterator::operator++() {

    ++p;
    return *this;
}

Ruta::iterator &Ruta::iterator::operator--() {

    --p;
    return *this;
}

Punto &Ruta::iterator::operator*() {

    return *p;
}

bool Ruta::iterator::operator==(const Ruta::iterator &i) const {

    return i.p == p;
}

bool Ruta::iterator::operator!=(const Ruta::iterator &i) const {

    return i.p != p;
}

Ruta::const_iterator &Ruta::const_iterator::operator++() {

    ++p;
    return *this;
}

Ruta::const_iterator &Ruta::const_iterator::operator--() {

    --p;
    return *this;
}

const Punto &Ruta::const_iterator::operator*() {

    return *p;
}

bool Ruta::const_iterator::operator==(const Ruta::const_iterator &i) const {

    return i.p == p;
}

bool Ruta::const_iterator::operator!=(const Ruta::const_iterator &i) const {

    return i.p != p;
}

Ruta::iterator Ruta::begin() {

    iterator it;
    it.p = puntos.begin();
    return it;
}

Ruta::const_iterator Ruta::begin() const{

    const_iterator it;
    it.p = puntos.cbegin();
    return it;
}

Ruta::iterator Ruta::end() {

    iterator it;
    it.p = puntos.end();
    return it;
}

Ruta::const_iterator Ruta::end() const{

    const_iterator it;
    it.p = puntos.cend();
    return it;
}

Ruta::iterator Ruta::find(const Punto &p) {

    iterator it;
    list<Punto>::iterator i;

    for(i = puntos.begin() ; i != puntos.end() && !((*i) == p) ; ++i  ); //Busca el punto

    it.p = i;

    return it;
}

istream& operator>>(std::istream& is, Ruta& ruta) {

    is >> ruta.code;

    int cantidadPuntos;
    is >> cantidadPuntos;

    ruta.puntos.clear();  // Limpiar la lista actual de puntos

    for (int i = 0; i < cantidadPuntos; ++i) {
        Punto punto;
        is >> punto;
        ruta.puntos.push_back(punto);
    }

    return is;
}

ostream &operator<<(std::ostream &os, const Ruta &R){

    os << R.code << " " << R.puntos.size() << " ";

    auto it = R.puntos.begin();
    while (it != R.puntos.end()){

        os << *it <<" ";
        ++it;
    }

    os << endl;
    return os;
}




