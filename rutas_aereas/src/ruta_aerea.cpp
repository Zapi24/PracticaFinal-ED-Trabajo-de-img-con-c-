//
// Created by zapi24 on 14/12/23.
//


#include "Paises.h"
#include "Almacen_rutas.h"
#include "Ruta.h"
#include "imagen.h"
#include <fstream>
#include <cstring>

//El mapa es de es de 1536 × 768 píxeles
static const int FILAS =768;
static const int COLUMNAS =1536;

imagen Rota(const imagen & Io, double angulo){  //Función ya incluida dentro de prueba_rotacion
    double rads=angulo;
    double coseno = cos(angulo);
    double seno = sin(angulo);
    //Para obtener las dimensiones de la imagen
    int rcorners[4],ccorners[4];
    int newimgrows,newimgcols;
    double new_row_min,new_col_min,new_row_max,new_col_max;
    double inter,inter1;

    rcorners[0]=0;
    rcorners[1]=0;
    ccorners[0]=0;
    ccorners[2]=0;
    rcorners[2]=Io.num_filas()-1;
    rcorners[3]=Io.num_filas()-1;
    ccorners[1]=Io.num_cols()-1;
    ccorners[3]=Io.num_cols()-1;
    new_row_min=0;
    new_col_min=0;
    new_row_max=0;
    new_col_max=0;
    newimgrows=0;
    newimgcols=0;
    for(int count=0;count<4;count++)
    {
        inter=rcorners[count]*coseno+ccorners[count]*seno;

        if(inter<new_row_min)
            new_row_min=inter;
        if(inter>new_row_max)
            new_row_max=inter;
        inter1=-rcorners[count]*seno+ccorners[count]*coseno;

        if(inter1<new_col_min)
            new_col_min=inter1;
        if(inter1>new_col_max)
            new_col_max=inter1;
    }

    newimgrows=(unsigned)ceil((double)new_row_max-new_row_min);
    newimgcols=(unsigned)ceil((double)new_col_max-new_col_min);

    imagen Iout(newimgrows, newimgcols);
    for(int rows=0;rows<newimgrows;rows++)
    {
        for(int cols=0;cols<newimgcols;cols++)
        {
            float oldrowcos=((float)rows+new_row_min)*cos(-rads);
            float oldrowsin=((float)rows+new_row_min)*sin(-rads);
            float oldcolcos=((float)cols+new_col_min)*cos(-rads);
            float oldcolsin=((float)cols+new_col_min)*sin(-rads);
            float old_row=oldrowcos+oldcolsin;
            float old_col=-oldrowsin+oldcolcos;
            old_row=ceil((double)old_row);
            old_col=ceil((double)old_col);
            if((old_row>=0) && (old_row<Io.num_filas())&& (old_col>=0)&&(old_col<Io.num_cols())) //Comprueba que esta dentro de los limites
            {
                Iout(rows,cols)=Io(old_row,old_col);

            }
            else
                Iout(rows,cols).r=Iout(rows,cols).g=Iout(rows,cols).b=255;
        }
    }
    return Iout;

}
//Funcionalidad del main pegar, pero echo función
void pegar_imagen(char *fondo, char *pegar, char *mascara,char *nombre, int fila, int columna, int tipo,bool quepegar){
    imagen I,Ip;

    I.LeerImagen(fondo);

    if(quepegar){ //Diferencia entre mapa y avion, para utilizar la mascara o no

        Ip.LeerImagen(pegar,mascara);
    }
    else{

        Ip.LeerImagen(pegar);
    }

    Tipo_Pegado tp=OPACO; //variable de tipo Tipo_Pegado que es un enumerado con los valores OPACO y 	BLENDING
    if (tipo!=0) tp=BLENDING;

    I.PutImagen(fila,columna,Ip,tp);
    I.EscribirImagen(nombre);
}

void rotar_imagen(char* avion,double angulo, char* salida){ //Funcionalidad del main rotar, pero echo función

    imagen I;

    string n_aux = "mascara_";
    n_aux =n_aux+avion;
    std::size_t found =n_aux.find(".ppm");
    if (found!=std::string::npos){
        n_aux =n_aux.substr(0,found);
    }
    n_aux =n_aux+".pgm";

    I.LeerImagen(avion,n_aux);

    angulo = angulo*(M_PI)/180;

    imagen Iout=Rota(I, angulo);
    Iout.EscribirImagen(salida);
}

char* concat(char* str1, const string& str2) { //Para concatenar char* con strings, util a la hora de seleccionar una bandera expecifica
    size_t len1 = std::strlen(str1);
    size_t len2 = str2.length();

    char* result = new char[len1 + len2 + 1];

    strcpy(result, str1);
    strcpy(result + len1, str2.c_str());

    return result;
}

float get_columna(int longitud){

    return float(COLUMNAS / 360) * (180 + longitud);
}

float get_fila(int latitud){

    return float(FILAS / 180) * (90 - latitud);
}

int calcularFilaMedia(int fila1, int fila2) {   //Calcular punto medio de dos en el espacio
    return (fila1 + fila2) / 2;
}

int calcularColumnaMedia(int columna1, int columna2) { //Calcular punto medio de dos en el espacio
    return (columna1 + columna2) / 2;
}

double calcularAngulo(int fila1, int columna1, int fila2, int columna2) {   //Calcular el angulo, que une dos puntos en el espacio
    return atan2(fila2 - fila1, columna2 - columna1) * (180.0 / M_PI);
}

int main(int argc, char * argv[]) {
    if (argc != 8) {
        cout << "Los parametros son:" << endl;
        cout << "1.-Fichero con la informacion de los paises" << endl;
        cout << "2.-Nombre de la imagen con el mapa del mundo" << endl;
        cout << "3.-Directorio con las banderas" << endl;
        cout << "4.-Fichero con el almacen de rutas" << endl;
        cout << "5.- Nombre de la imagen con el avion" << endl;
        cout << "6.- Nombre de la imagen de la mascara del avion" << endl;
        cout << "7.- Indice de la ruta seleccionada dentro del almacen de rutas" << endl;
        return 1;
    }

    //Obtenemos los argumentos
    char *paisestxt, *mapa, *banderas, *rutastxt,*avion,*mascara;
    ifstream fichero;

    paisestxt = argv[1];
    mapa = argv[2];
    banderas = argv[3];
    rutastxt = argv[4];
    avion = argv[5];
    mascara = argv[6];

    char* ag = "avion_girado.ppm" ;
    char* masc_ag = "mascara_avion_girado.pgm";

    char* out = "../salida.ppm";

    Paises paises = Paises();
    Almacen_rutas almacenRutas;

    //Obtenemos los paises
    fichero.open(paisestxt);
    fichero >> paises;
    //cout << paises <<endl;  //DEPURACION
    fichero.close();
    //Obtenemos las rutas
    fichero.open(rutastxt);
    fichero >> almacenRutas;
    //cout << almacenRutas << endl;   //DEPURACION

    //Obtenemos la ruta seleccionada a recorrer
    Ruta ruta;
    int indiceRuta = atoi(argv[7]);
    string s_indiceRuta = to_string(indiceRuta);

    ruta = almacenRutas.GetRuta("R"+s_indiceRuta);
    //cout << ruta << endl;   //DEPURACION

    auto it1 = ruta.begin(); ++it1;
    auto it2 = it1; --it1;            //Para recorrer cada par de puntos de la ruta

    rotar_imagen(avion,45,ag);
    bool primera_iteracion = true;
    while( it2 != ruta.end()){
        int fila1,columna1,fila2,columna2;
        double angulo;
        Pais Pais1, Pais2;

        //cout << *it1 <<" "<< *it2 <<endl;   //DEPURACION
        Pais1 = *paises.find(*it1); //Buscamos los paises con respecto los puntos
        Pais2 = *paises.find(*it2);

        //Obtenemos los puntos
        columna1 = get_columna((*it1).getLongitud());
        fila1 = get_fila((*it1).getLatitud());
        columna2 = get_columna((*it2).getLongitud());
        fila2 = get_fila((*it2).getLatitud());
        angulo = calcularAngulo(fila1,columna1,fila2,columna2);

        rotar_imagen(avion,angulo,ag);

        if(primera_iteracion){              //Para no repetir mas de un pegado

            pegar_imagen(mapa, ag,masc_ag,out,fila1,columna1,0,true); mapa = out;
            //cout << mapa << " " << concat(banderas,"/"+Pais1.GetBandera()) << " " << out << " " << fila1 << " " << columna1 <<endl;       //DEPURACION
            pegar_imagen(mapa,concat(banderas,"/"+Pais1.GetBandera()),"patata"
                    ,out,fila1,columna1,1,false); mapa = out;
                    primera_iteracion = false;
        }

        //Pegamos los aviones, debajo de cada bandera respectivamente
        pegar_imagen(mapa, ag,masc_ag,out,fila2,columna2,0,true); mapa = out;

        //Pegamos cada bandera en su respectiva posicion
        pegar_imagen(mapa,concat(banderas,"/"+Pais2.GetBandera()),"patata"
                ,out,fila2,columna2,1,false); mapa = out;

        int filaMedia = calcularFilaMedia(fila1, fila2);
        int columnaMedia = calcularColumnaMedia(columna1, columna2);
        //Pegamos los aviones intermedios
        pegar_imagen(mapa, ag,masc_ag,out,filaMedia,columnaMedia,0,true); mapa = out;

        ++it2;
        ++it1;
    }
    return 0;
}




//MAIN DE PRUEBA
/*Pais p;
Punto pr;
Paises ps;
pr=Punto(8.874174555928159,-79.77636344999996,"");  //Es el punto de Panama
p=Pais();
ps=Paises();
ifstream fichero;
fichero.open("../datos/paises.txt");
fichero >> ps;
cout << "PAISES (ordenados según su posicion en el Mapa): " << endl;
cout << ps << endl;         //Muestra los paises del fichero paises.txt

cout << "Primer pais: " <<  *ps.begin() << endl;
cout << "Buscamoss paises con respecto al punto " << *ps.find(pr) << endl;
p=ps.GetPais(Punto(34.520418555522845,69.20082090000005,""));   //Obtenemos el pais con respecto a un punto
cout << *ps.find(p) << endl;

Almacen_rutas a;
Ruta r;

ifstream fich;
r.Insertar(Punto(34.520418555522845,69.20082090000005,""));
r.Insertar(pr);
cout << "Mostramos una ruta" << r << endl;
fich.open("../datos/almacen_rutas.txt");
fich >> a;
cout <<"RUTAS: "<<endl;
cout << a << endl;

r=a.GetRuta("R5");
cout << "Mostramos una ruta seleccionandola con GetRuta: " << r << endl;*/