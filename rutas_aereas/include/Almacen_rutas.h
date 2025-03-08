//
// Created by zapi24 on 13/12/23.
//



#ifndef PRACTICAFINAL_ALMACEN_RUTAS_H
#define PRACTICAFINAL_ALMACEN_RUTAS_H


#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <map>
#include "Ruta.h"

/**
 * @brief Clase que representa un almacén de rutas identificadas por códigos únicos.
 */
class Almacen_rutas{
private:
    map<string, Ruta> rutas; /**< Mapa que asocia códigos de rutas con las propias rutas. */

public:

    /**
     * @brief Constructor por defecto de la clase Almacen_rutas.
     */
    Almacen_rutas(){}

    /**
     * @brief Inserta una nueva ruta, dentro del map  de rutas.
     * @param r ruta a insertar.
     */
    void Insertar(const Ruta & r);

    /**
     * @brief Borra una ruta seleccionada, dentro del map  de rutas.
     * @param r ruta a borrar (no borraria nada, si la ruta no existiese).
     */
    void Borrar(const Ruta & r);

    /**
     * @brief Obtiene una ruta asociada a su código.
     * @param r código de la ruta a obtener.
     * @return Ruta correspondiente al código asociado
     */
    Ruta GetRuta(const string & a);

    /**
     * @brief Iterador constante para la clase Almacen_rutas.
     */
    class const_iterator;

    /**
     * @brief Iterador para la clase Almacen_rutas.
     */
    class iterator{
    private:
        map<string,Ruta>::iterator p; /**Iterador interno para la coleccion map de rutas */

    public:

        /**
         * @brief Constructor por defecto del iterador.
         */
        iterator(){}

        /**
         * @brief Constructor por parametros del iterador.
         * @param it iterador de la clase iterator
         */
        iterator(map<string,Ruta>::iterator &it) : p(it) {}

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
         * @return La pareja con el código de la ruta, y la ruta seleccionada.
         */
        const pair<string,Ruta> &operator*();

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

        friend class Almacen_rutas;
        friend class const_iterator;
    };

    class const_iterator{
    private:
        map<string,Ruta>::const_iterator p; /**Iterador constante interno para la coleccion map de rutas */

    public:

        /**
         * @brief Constructor por defecto del iterador constante.
         */
        const_iterator(){}

        /**
         * @brief Constructor por parametros del iterador constante .
         * @param it iterador de la clase const_iterator
         */
        const_iterator(const map<string,Ruta>::const_iterator &it) : p(it){};

        // Operadores de iterador
        /**
         * @brief Sobrecarga del operador de incremento (++it).
         * @return Iterador incrementado.
         */
        const_iterator &operator++();

        /**
         * @brief Sobrecarga del operador de incremento (--it).
         * @return Iterador decrementado.
         */
        const_iterator &operator--();

        /**
         * @brief Sobrecarga del operador asterisco (*it).
         * @return La pareja con el código de la ruta, y la ruta seleccionada.
         */
        const pair<string,Ruta> &operator*() ;

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

        friend class Almacen_rutas;
    };

    /**
     * @brief Obtiene un iterador al comienzo de la colección de rutas.
     * @return Iterador al comienzo de la colección.
     */
    iterator begin();

    /**
     * @brief Obtiene un iterador constante al comienzo de la colección de rutas.
     * @return Iterador constnte al comienzo de la colección.
     */
    const_iterator begin() const;

    /**
     * @brief Obtiene un iterador al final de la colección de rutas.
     * @return Iterador al final de la colección.
     */
    iterator end();

    /**
     * @brief Obtiene un iterador constante al final de la colección de rutas.
     * @return Iterador al final de la colección.
     */
    const_iterator end() const;

    /**
     * @brief Sobrecarga del operador de entrada para leer el almacén de rutas desde un flujo de entrada.
     * @param is Flujo de entrada.
     * @param AR Almacén de rutas que se actualizará con los datos leídos.
     * @return Referencia al flujo de entrada actualizado.
     */
    friend std::istream &operator>>(std::istream &is, Almacen_rutas & AR);

    /**
     * @brief Sobrecarga del operador de salida para escribir el almacén de rutas en un flujo de salida.
     * @param os Flujo de salida.
     * @param AR Almacén de rutas que se escribirá en el flujo de salida.
     * @return Referencia al flujo de salida actualizado.
     */
    friend std::ostream &operator<<(std::ostream &os, const Almacen_rutas & AR);



};



#endif //PRACTICAFINAL_ALMACEN_RUTAS_H
