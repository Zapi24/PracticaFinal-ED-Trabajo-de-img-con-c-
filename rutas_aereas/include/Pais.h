//
// Created by zapi24 on 6/12/23.
//

/**
 * @file Pais.h
 * @brief Definición de la clase Pais.
 */
#ifndef PRACTICAFINAL_PAIS_H
#define PRACTICAFINAL_PAIS_H

#include "Punto.h"

/**
 * @brief Clase que representa un país en el mapa, caracterizado por un punto en el espacio, un nombre y una bandera.
 */
class Pais{
private:
    Punto p; /**< Punto en el espacio que representa la ubicación del país. */
    string pais; /**< Nombre del país. */
    string bandera; /**< Ruta o identificador de la bandera del país. */

public:

    /**
     * @brief Constructor por defecto de la clase Pais.
     */
    Pais();

    /**
     * @brief Obtiene el punto en el espacio que representa la ubicación del país.
     * @return Punto en el espacio.
     */
    Punto GetPunto()const;

    /**
     * @brief Obtiene el nombre del pais.
     * @return Nombre del pais.
     */
    string GetPais()const;

    /**
     * @brief Obtiene el nombre del archivo de la bandera del pais.
     * @return El nombre del archivo de la bandera del pais.
     */
    string GetBandera()const;

    /**
     * @brief Sobrecarga del operador < para determinar el orden de los paises, determinado por el orden de los puntos.
     * @param P Pais a comparar.
     * @return True si el país actual es menor que el país P, False en caso contrario.
     */
    bool operator<(const Pais &P)const;

    /**
     * @brief Compara si dos países son iguales.
     * @param P Otro país a comparar.
     * @return True si ambos países son iguales, False en caso contrario.
     */
    bool operator==(const Pais &P)const;

    /**
     * @brief Compara si el punto de un pais es igual a un punto en el espacio.
     * @param P Punto a comparar.
     * @return True si el país tiene el mismo punto que el punto P, False en caso contrario.
     */
    bool operator==(const Punto &P)const;   //Dos paises son iguales si tienen el mismo punto

    /**
     * @brief Sobrecarga del operador de entrada para leer un país desde un flujo de entrada.
     * @param is Flujo de entrada.
     * @param P País que se actualizará con los datos leídos.
     * @return Referencia al flujo de entrada actualizado.
     */
    friend istream & operator>>(istream & is, Pais & P);

    /**
     * @brief Sobrecarga del operador de salida para escribir un país en un flujo de salida.
     * @param os Flujo de salida.
     * @param P País que se escribirá.
     * @return Referencia al flujo de salida actualizado.
     */
    friend ostream & operator<<(ostream & os, const Pais &P);

};

#endif //PRACTICAFINAL_PAIS_H
