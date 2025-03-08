//
// Created by zapi24 on 6/12/23.
//

/**
 * @file Paises.h
 * @brief Definición de la clase Paises.
 */

#ifndef PRACTICAFINAL_PAISES_H
#define PRACTICAFINAL_PAISES_H

#include "Pais.h"
#include <set>
using namespace std;

/**
 * @brief Clase que representa una colección de países.
 */
class Paises {
private:
    set<Pais> datos; /**< Conjunto que almacena la información de los países. */

public:

    /**
     * @brief Constructor por defecto de la clase Paises.
     */
    Paises();

    /**
     * @brief Inserta un nuevo país en la colección.
     * @param P País a insertar.
     */
    void Insertar(const Pais &P);

    /**
     * @brief Borra un nuevo país en la colección.
     * @param P País a borrar.
     */
    void Borrar(const Pais &P);

    /**
     * @brief Obtiene el país asociado a un punto en el espacio.
     * @param p Punto en el espacio.
     * @return País correspondiente al punto especificado.
     */
    Pais GetPais(const Punto & p);

    /**
     * @brief Iterador constante para la clase Paises.
     */
    class const_iterator;

    /**
     * @brief Iterador para la clase Paises.
     */
    class iterator {
    private:
        set<Pais>::iterator p; /**< Iterador interno para la colección de países. */

    public:

        /**
         * @brief Constructor por defecto del iterador.
         */
        iterator() {}

        /**
         * @brief Constructor por parametros del iterador.
         * @param it iterador de la clase iterator
         */
        iterator(set<Pais>::iterator &it) : p(it) {}

        // Operadores de iterador
        /**
         * @brief Sobrecarga del operador de incremento (++it).
         * @return Iterador incrementado.
         */
        iterator &operator++();

        /**
         * @brief Sobrecarga del operador de decremento (--it).
         * @return Iterador decrementado.
         */
        iterator &operator--();

        /**
         * @brief Sobrecarga del operador asterisco (*it).
         * @return El Pais en esa posición del iterador.
         */
        const Pais &operator*()const ;

        /**
         * @brief Sobrecarga del operador de igualdad.
         * @param i iterador sobre el cual se va a realizar la igualdad
         * @return True si ambos iteradores apuntan al mismo punto, False en caso contrario.
         */
        bool operator == (const iterator & i)const;

        /**
         * @brief Sobrecarga del operador de desigualdad.
         * @param i iterador sobre el cual se va a realizar la desigualdad
         * @return True si ambos iteradores NO apuntan al mismo punto, False en caso contrario.
         */
        bool operator != (const iterator & i)const;

        friend class Paises;
        friend class const_iterator;
    };

    class const_iterator {
    private:
         set<Pais>::const_iterator p; /**< Iterador constante para la colección de países. */

    public:

        /**
         * @brief Constructor por defecto del iterador constante.
         */
        const_iterator() {}

        /**
         * @brief Constructor por parametros del iterador constante.
         * @param it iterador de la clase const_iterator
         */
        const_iterator(const set<Pais>::const_iterator &it) : p(it) {}

        // Operadores de iterador constante

        /**
         * @brief Sobrecarga del operador de incremento (++it).
         * @return Iterador incrementado.
         */
        const_iterator &operator++();

        /**
         * @brief Sobrecarga del operador de decremento (-it).
         * @return Iterador decrementado.
         */
        const_iterator &operator--();

        /**
         * @brief Sobrecarga del operador asterisco (*it).
         * @return El Pais en esa posición del iterador.
         */
        const Pais &operator*() const;

        /**
         * @brief Sobrecarga del operador de igualdad.
         * @param i iterador sobre el cual se va a realizar la igualdad
         * @return True si ambos iteradores apuntan al mismo punto, False en caso contrario.
         */
        bool operator == (const const_iterator & i)const;

        /**
         * @brief Sobrecarga del operador de desigualdad.
         * @param i iterador sobre el cual se va a realizar la desigualdad
         * @return True si ambos iteradores apuntan NO al mismo punto, False en caso contrario.
         */
        bool operator != (const const_iterator & i)const;

        friend class Paises;
    };

    /**
     * @brief Obtiene un iterador al comienzo de la colección de países.
     * @return Iterador al comienzo de la colección.
     */
    iterator begin();

    /**
     * @brief Obtiene un iterador constante al comienzo de la colección de países.
     * @return Iterador constante al comienzo de la colección.
     */
    const_iterator begin() const;

    /**
     * @brief Obtiene un iterador al final de la colección de países.
     * @return Iterador al final de la colección.
     */
    iterator end();

    /**
     * @brief Obtiene un iterador constante al final de la colección de países.
     * @return Iterador constante al final de la colección.
     */
    const_iterator end() const;

    /**
     * @brief Busca un país en la colección.
     * @param p País a buscar.
     * @return Iterador al país encontrado o al final si no se encontró.
     */
    iterator find(const Pais &p);

    /**
     * @brief Busca un país en la colección a través de un punto en el espacio.
     * @param p Punto en el espacio a buscar.
     * @return Iterador al país encontrado o al final si no se encontró.
     */
    iterator find(const Punto &p);

    /**
     * @brief Sobrecarga del operador de entrada para leer la colección de países desde un flujo de entrada.
     * @param is Flujo de entrada.
     * @param R Colección de países que se actualizará con los datos leídos.
     * @return Referencia al flujo de entrada actualizado.
     */
    friend std::istream &operator>>(std::istream &is, Paises &R);

    /**
     * @brief Sobrecarga del operador de salida para escribir la colección de países en un flujo de salida.
     * @param os Flujo de salida.
     * @param R Colección de países que se escribirá en el flujo de salida.
     * @return Referencia al flujo de salida actualizado.
     */
    friend std::ostream &operator<<(std::ostream &os, const Paises &R);
};

#endif //PRACTICAFINAL_PAISES_H
