//
// Created by zapi24 on 13/12/23.
//

/**
 * @file Ruta.h
 * @brief Definición de la clase Ruta.
 */

#ifndef PRACTICAFINAL_RUTA_H
#define PRACTICAFINAL_RUTA_H


#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <list>
#include "Punto.h"
using namespace std;

/**
 * @brief Clase que representa una ruta compuesta por puntos en el espacio.
 */
class Ruta{
    private:
    list<Punto> puntos; /**< Lista de puntos que forman la ruta. */
    string code; /**< Código único de la ruta. */

public:

    /**
     * @brief Constructor por defecto de la clase Ruta.
     */
    Ruta();

    /**
    * @brief Inserta un nuevo punto en la ruta.
    * @param n Punto a insertar.
    */
    void Insertar(const Punto & n);

    /**
    * @brief Borra un punto de la ruta.
    * @param n Punto a borrar.
    */
    void Borrar(const Punto & n);

    /**
     * @brief Obtiene el código único de la ruta.
     * @return Código de la ruta.
     */
    string GetCode() const;

    /**
     * @brief Establece el código único de la ruta.
     * @param code nuevo código de la ruta.
     */
    void SetCode(const string & code);

    /**
     * @brief Compara si dos rutas son iguales.
     * @param R Ruta a comparar.
     * @return True si las rutas son iguales, False en caso contrario.
     */
    bool operator==(const Ruta & R) const;

    /**
     * @brief Compara el orden son iguales.
     * @param R Ruta a comparar.
     * @return True si la ruta actual es menor que la ruta R, False en caso contrario.
     */
    bool operator<(const Ruta & R) const;

    /**
     * @brief Iterador constante para la clase Ruta.
     */
    class const_iterator;

    /**
     * @brief Iterador no constante para la clase Ruta.
     */
    class iterator{
    private:
        list<Punto>::iterator p; /**< Iterador a la lista de puntos de la ruta. */

    public:
        /**
         * @brief Constructor por defecto del iterador.
         */
        iterator(){}

        /**
         * @brief Constructor por parametros del iterador.
         * @param it iterador de la clase iterator
         */
        iterator(list<Punto>::iterator &it) : p(it) {}

        // Operadores de iterador
        /**
         * @brief Sobrecarga del operador de incremento (++it).
         * @return Iterador incrementado.
         */
        iterator &operator++();

        /**
         * @brief Sobrecarga del operador de decrementado (--it).
         * @return Iterador decrementado.
         */
        iterator &operator--();

        /**
         * @brief Sobrecarga del operador asterisco (*it).
         * @return El Punto en esa posición del iterador.
         */
        Punto &operator*();

        /**
         * @brief Sobrecarga del operador de igualdad.
         * @param i iterador sobre el cual se va a realizar la igualdad
         * @return True si ambos iteradores apuntan al mismo punto, False en caso contrario.
         */
        bool operator == (const iterator & i)const;

        /**
         * @brief Sobrecarga del operador de desigualdad.
         * @param i iterador sobre el cual se va a realizar la desigualdad
         * @return True si ambos iteradores  NO apuntan al mismo punto, False en caso contrario.
         */
        bool operator != (const iterator & i)const;
        friend class Ruta;
        friend class const_iterator;
    };

    /**
     * @brief Iterador constante para la clase Ruta.
     */
    class const_iterator {
    private:
        list<Punto>::const_iterator p; /**< Iterador constante a la lista de puntos de la ruta. */

    public:

        /**
         * @brief Constructor por defecto del iterador constante.
         */
        const_iterator(){}

        /**
         * @brief Constructor por parametros del iterador constante.
         * @param it iterador de la clase iterator
         */
        const_iterator(const list<Punto>::const_iterator &it) : p(it) {}

        // Operadores de iterador
        /**
         * @brief Sobrecarga del operador de incremento (++it).
         * @return Iterador incrementado.
         */
        const_iterator &operator++();
        /**
         * @brief Sobrecarga del operador de decremento (--it).
         * @return Iterador decrementado.
         */
        const_iterator &operator--();

        /**
         * @brief Sobrecarga del operador asterisco (*it).
         * @return El Punto en esa posición del iterador.
         */
        const Punto &operator*() ;

        /**
         * @brief Sobrecarga del operador de igualdad.
         * @param i iterador sobre el cual se va a realizar la igualdad
         * @return True si ambos iteradores apuntan al mismo punto, False en caso contrario.
         */
        bool operator == (const const_iterator & i)const;

        /**
         * @brief Sobrecarga del operador de desigualdad.
         * @param i iterador sobre el cual se va a realizar la desigualdad
         * @return True si ambos iteradores NO apuntan al mismo punto, False en caso contrario.
         */
        bool operator != (const const_iterator & i)const;

        friend class Ruta;
    };

    /**
     * @brief Obtiene un iterador al inicio de la lista de puntos.
     * @return Iterador al inicio de la lista de puntos.
     */
    iterator begin();

    /**
     * @brief Obtiene un iterador constante al inicio de la lista de puntos.
     * @return Iterador constante  al inicio de la lista de puntos.
     */
    const_iterator begin() const;

    /**
     * @brief Obtiene un iterador al final de la lista de puntos.
     * @return Iterador al final de la lista de puntos.
     */
    iterator end();

    /**
     * @brief Obtiene un iterador constante al final de la lista de puntos.
     * @return Iterador constante al final de la lista de puntos.
     */
     const_iterator end() const;

    /**
    * @brief Busca un punto en la ruta y devuelve un iterador.
    * @param p Punto a buscar.
    * @return Iterador apuntando al punto encontrado o al final si no se encuentra.
    */
    iterator find(const Punto &p);

    /**
     * @brief Sobrecarga del operador de entrada para leer una ruta desde un flujo de entrada.
     * @param is Flujo de entrada.
     * @param R Ruta que se actualizará con los datos leídos.
     * @return Referencia al flujo de entrada actualizado.
     */
    friend std::istream &operator>>(std::istream &is, Ruta &R);

    /**
     * @brief Sobrecarga del operador de salida para escribir una ruta en un flujo de salida.
     * @param os Flujo de salida.
     * @param R Ruta que se escribirá.
     * @return Referencia al flujo de salida actualizado.
     */
    friend std::ostream &operator<<(std::ostream &os, const Ruta &R);

};


#endif //PRACTICAFINAL_RUTA_H
