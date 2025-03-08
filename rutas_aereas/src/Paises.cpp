//
// Created by zapi24 on 6/12/23.
//

#include "Paises.h"

Paises::Paises() : datos(){}

void Paises::Borrar(const Pais &P) {

    datos.erase(P);
}

void Paises::Insertar(const Pais &P) {

    datos.emplace(P);
}

Pais Paises::GetPais(const Punto &p) {

    if (find(p) != end()){ //Verificamos que el find, no nos devuelva el end del set

        return *find(p);        //Devuelve el pais con respecto al set
    }
}

Paises::iterator &Paises::iterator::operator++() {

    ++p;
    return *this;
}

Paises::iterator &Paises::iterator::operator--() {

    --p;
    return *this;
}

const Pais & Paises::iterator::operator*() const{ //Pais es constante

    return *p;
}

bool Paises::iterator::operator==(const Paises::iterator &i) const {

    return p == i.p;
}

bool Paises::iterator::operator!=(const Paises::iterator &i) const {

    return p != i.p;
}

Paises::const_iterator &Paises::const_iterator::operator++() {

    ++p;
    return *this;
}

Paises::const_iterator &Paises::const_iterator::operator--() {

    --p;
    return *this;
}

const Pais &Paises::const_iterator::operator*() const {

    return *p;
}

bool Paises::const_iterator::operator==(const Paises::const_iterator &i) const {

    return p == i.p;
}

bool Paises::const_iterator::operator!=(const Paises::const_iterator &i) const {

    return p != i.p;
}

Paises::iterator Paises::begin() {

    iterator it;
    it.p = datos.begin();
    return it;
}

Paises::const_iterator Paises::begin() const {

    const_iterator it;
    it.p = datos.cbegin();
    return it;
}

Paises::iterator Paises::end(){

    iterator it;
    it.p = datos.end();
    return it;
}

Paises::const_iterator Paises::end() const{

    const_iterator it;
    it.p = datos.end();
    return it;
}

Paises::iterator Paises::find(const Pais &p) {

    iterator it;
    set<Pais>::iterator i;

    for (i=datos.begin(); i!=datos.end() && !((*i)==p);++i); //Busca el pais gracias a la condicion !((*i)==p)

    it.p=i;
    return it; //Si no encuentra nada, devolveria la posicion end

}

Paises::iterator Paises::find(const Punto &p) {

    iterator it;
    set<Pais>::iterator i;

    for(i = datos.begin() ; i != datos.end() && !((*i).GetPunto() == p) ; ++i  ); //Busca el punto

    it.p=i;
    return it; //Si no encuentra nada, devolveria la posicion end
}

istream &operator>>(std::istream &is, Paises &R){
    Paises rlocal;
    //leemos el comentario
    if (is.peek()=='#'){
        string a;
        getline(is,a);
    }

    Pais P;
    while (is>>P){
        rlocal.Insertar(P);

    }
    R=rlocal;
    return is;
}

ostream & operator<<(ostream & os, const Paises &R){

    Paises::const_iterator it;
    for (it=R.begin(); it!=R.end(); ++it){
        os<<*it;
    }
    return os;
}