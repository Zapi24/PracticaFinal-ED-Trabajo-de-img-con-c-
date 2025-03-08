//
// Created by zapi24 on 6/12/23.
//

#include "Pais.h"

Pais::Pais() {

    p = Punto(0,0,"");
    pais = "";
    bandera = "";
}

Punto Pais::GetPunto() const {

    return p;
}

string Pais::GetPais() const {

    return pais;
}

string Pais::GetBandera() const {

    return bandera;
}

bool Pais::operator<(const Pais &P) const {

    return p < P.p;     //Nos basamos en el operador < de Punto
}

bool Pais::operator==(const Pais &P) const {

    return pais == P.pais && bandera == P.bandera && p == P.p;
}

bool Pais::operator==(const Punto &P) const {

    return p == P;
}

istream & operator>>(istream & is, Pais & P){
    double lat,lng;

    is>>lat>>lng>>P.pais>>P.bandera;

    P.p=Punto(lat,lng,"");
    return is;
}

ostream & operator<<(ostream & os, const Pais &P){

    os<<P.p<<" "<<P.pais<<" "<<P.bandera<<endl;
    return os;
}




