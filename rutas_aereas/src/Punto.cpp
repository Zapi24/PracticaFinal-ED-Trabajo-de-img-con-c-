//
// Created by zapi24 on 5/12/23.
//

#include "Punto.h"

double Punto::getLatitud() {

    return latitud;
}

double Punto::getLongitud() {

    return longitud;
}

void Punto::setLatitud(double l) {

    latitud=l;
}

void Punto::setLongitud(double L) {

    longitud=L;
}

bool Punto::operator<(const Punto &p) const { //Para determinar el orden de los puntos?

    return longitud < p.longitud; //Para poder determinar, que pais esta mas a la izquierda o a la derecha de otro
}

bool Punto::operator==(const Punto &p) const {

    return longitud == p.longitud && latitud == p.latitud;
}

bool Punto::operator!=(const Punto &p) const {

    return !(longitud == p.longitud && latitud == p.latitud);
}

istream &operator>>(istream &is, Punto &p) {
    char parenLeft, coma, parenRight;
    is >> parenLeft >>  p.latitud  >> coma >> p.longitud >> parenRight ;

    return is;
}

ostream &operator<<(ostream &os, const Punto &p) {

    os << "(" << p.latitud << "," << p.longitud << ")";
    return os;
}

