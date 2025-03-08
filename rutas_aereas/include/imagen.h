//
// Created by zapi24 on 29/11/23.
//

/**
 * @file imagen.h
 * @brief Definición de la clase imagen.
 */

#ifndef PRACTICAFINAL_IMAGEN_H
#define PRACTICAFINAL_IMAGEN_H

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cassert>
using namespace std;


/**
 * @brief Enumeración que define los tipos de pegado para la superposición de imágenes.
 */
enum Tipo_Pegado {
    OPACO, /**< Pegado opaco, pega una imagen por completo sobre otra. */
    BLENDING /**< Pegado blending, pegado débil, en el que el fondo de la imagen todavía se puede ver. */
};

/**
 * @brief Estructura que representa un píxel en una imagen.
 */
struct Pixel{
    unsigned char r,g,b; /**< Componentes RGB del píxel. */
    unsigned char transp; /**< Transparencia del píxel (0: no transparente, 255: completamente transparente). */
};

/**
 * @brief Clase que representa una imagen y sus operaciones básicas.
 */
class imagen{
private:
    Pixel ** data; /**< Matriz de píxeles que representa la imagen. */
    int nf,nc; /**< Número de filas y columnas de la imagen. */

    /**
     * @brief Libera la memoria ocupada por la imagen.
     */
    void Borrar();

    /**
     * @brief Copia los datos de una imagen a otra
     * @param I imagen sobre la que se va a copiar
     */
    void Copiar(const imagen &I);

public:
    /**
     * @brief Constructor vacio de la clase imagen
     */
    imagen();

    /**
     * @brief Constructor por parámetros de la clase imagen
     * @param f número de filas que se establece a la imagen
     * @param c número de columnas que se establece a la imagen
     */

    imagen(int f, int c);

    /**
     * @brief Constructor copia de la clase imagen
     * @param I imagen sobre la que se va a copiar
     */

    imagen(const imagen & I);

    /**
     * @brief Sobrecarga del operador igual
     * @param I imagen la cual se va a asignar a otra
     * @return imagen resultado de la asignación
     */

    imagen & operator=(const imagen & I);

    /**
     * @brief destructor de la clase imagen
     */
    ~imagen();

    /**
     * @brief sobrecarga del operador (), para funcionalidad de set
     * @param i fila sobre la que se realizaŕa la asignación
     * @param j columa sobre la que se realizará la asingación
     * @return pixel resultado de la asingación
     */
    Pixel & operator ()(int i,int j);

    /**
     * @brief sobrecarga del operador (), para funcionalidad de get
     * @param i fila sobre la que se realizaŕa la obtención del valor de data
     * @param j columa sobre la que se realizará la obtención del valor de data
     * @return pixel resultado de la obtención del valor de data
     */

    const Pixel & operator ()(int i,int j)const;

    /**
     * @brief Escribe la imagen guardandola en un dirección con formato PPM.
     * @param nombre Nombre del archivo de salida.
     */
    void EscribirImagen(const char * nombre);

    /**
     * @brief Lee una imagen desde un archivo PPM.
     * @param nombre Nombre del archivo de entrada.
     * @param nombremascara Nombre del archivo de la máscara (opcional).
     */
    void LeerImagen (const char *nombre,const string &nombremascara="");

    /**
    * @brief Se establece el máximo valor de transparencia a cada pixel.
    */
    void LimpiarTransp();

    /**
     * @brief Obtiene el número de filas de la imagen.
     * @return Número de filas de la imagen.
     */
    int num_filas()const{return nf;}

    /**
     * @brief Obtiene el número de columnas de la imagen.
     * @return Número de columnas de la imagen.
     */
    int num_cols()const{return nc;}

    /**
     * @brief Coloca una imagen sobre otra en la posición especificada.
     * @param posi Posición vertical de la esquina superior izquierda.
     * @param posj Posición horizontal de la esquina superior izquierda.
     * @param I Imagen que se colocará sobre la imagen actual.
     * @param tippegado Tipo de pegado (OPACO o BLENDING).
     */
    void PutImagen(int posi, int posj, const imagen &I, Tipo_Pegado tippegado=OPACO);

    /**
     * @brief Extrae una porción de la imagen especificada por las coordenadas y dimensiones.
     * @param posi Posición vertical de la esquina superior izquierda.
     * @param posj Posición horizontal de la esquina superior izquierda.
     * @param dimi Número de filas de la porción a extraer.
     * @param dimj Número de columnas de la porción a extraer.
     * @return Nueva imagen que representa la porción extraída.
     */
    imagen ExtraeImagen(int posi, int posj, int dimi, int dimj);
};




#endif //PRACTICAFINAL_IMAGEN_H
