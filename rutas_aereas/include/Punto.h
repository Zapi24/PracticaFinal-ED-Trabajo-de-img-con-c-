//
// Created by zapi24 on 5/12/23.
//

/**
 * @file Punto.h
 * @brief Definición de la clase Punto.
 */

#ifndef PRACTICAFINAL_PUNTO_H
#define PRACTICAFINAL_PUNTO_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cassert>
using namespace std;

/**
 * @brief Clase que representa un punto en el espacio definido por latitud y longitud.
 */
class Punto {
    private:
    double latitud; /**< Coordenada de latitud del punto. */
    double longitud; /**< Coordenada de longitud del punto. */
public:

    /**
     * @brief Constructor por defecto de la clase Punto.
     */
    Punto(){

        latitud=longitud=0;
    }

    /**
     * @brief Constructor por parámetros de la clase Punto.
     * @param l latitud del punto
     * @param L longitud del punto
     * @param breve descripcion del punto (irrelevante)
     */
    Punto(double l, double L, const string & d ) : latitud(l), longitud(L){};

    /**
    * @brief Obtiene la latitud del punto.
    * @return Valor de la latitud.
    */
    double getLatitud();

    /**
    * @brief Obtiene la longitud del punto.
    * @return Valor de la longitud.
    */
    double getLongitud();

    /**
     * @brief Establece la latitud del punto.
     * @param l Nuevo valor de la latitud.
     */
    void setLatitud(double l);

    /**
     * @brief Establece la longitud del punto.
     * @param L Nuevo valor de la longitud.
     */
    void setLongitud(double L);

    /**
     * @brief Sobrecarga del operador < para determinar el orden de los puntos por longitud.
     * @param p Punto a comparar.
     * @return True si el punto actual tiene una longitud menor que el punto p, False en caso contrario.
     */
    bool operator<(const Punto & p )const;

    /**
     * @brief Sobrecarga del operador == para comparar la igualdad de dos puntos.
     * @param p Punto a comparar.
     * @return True si ambos puntos son iguales, False en caso contrario.
     */
    bool operator==(const Punto & p )const;

    /**
     * @brief Sobrecarga del operador != para comparar la desigualdad de dos puntos.
     * @param p Punto a comparar.
     * @return True si ambos puntos son no son iguales, False en caso contrario.
     */
    bool operator!=(const Punto & p )const;

    /**
     * @brief Sobrecarga del operador >> para la lectura de un punto desde un flujo de entrada.
     * @param is Flujo de entrada.
     * @param p Referencia al objeto Punto que se actualizará con los datos leídos.
     * @return Referencia al flujo de entrada actualizado.
     */
    friend istream & operator>>(istream & is,Punto  &p);

    /**
     * @brief Sobrecarga del operador << para la escritura de un punto en un flujo de salida.
     * @param os Flujo de salida.
     * @param p Punto a escribir.
     * @return Referencia al flujo de salida actualizado.
     */
    friend ostream & operator<<(ostream & os,const Punto  &p);
};


#endif //PRACTICAFINAL_PUNTO_H
