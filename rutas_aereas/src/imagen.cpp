//
// Created by zapi24 on 29/11/23.
//

#include "../include/imagen.h"
#include "../include/imagenES.h"
void imagen::Borrar(){
    if (data != nullptr) { //Si ya es nullptr, no haria falta llamar al destructor
        for (int i = 0; i < nf; ++i) {
            delete[] data[i];
        }
        delete[] data;
        data = nullptr; // Establece data de vuelta a nullptr por si acaso
    }
}
void imagen::Copiar(const imagen &I){
    nf = I.nf;
    nc = I.nc;

    for(int i=0 ; i<nf ; i++){
        for( int j=0; j<nc ; j++){

            data[i][j] = I.data[i][j];      //SE PODRIA HACER?
        }
    }
}

imagen::imagen() {

    nf = nc = 0;
    data = nullptr;
}

imagen::imagen(int f, int c) {

    nf=f;
    nc=c;

    data = new Pixel*[nf];
    for(int i=0 ; i<nf ; i++){

        data[i] = new Pixel[nc];
        for( int j=0; j<nc ; j++){
            data[i][j].r = 255;
            data[i][j].b = 255;
            data[i][j].g = 255; //Como los 3 son 255
            data[i][j].transp = 0; //No se verá
        }
    }
}

imagen::imagen(const imagen &I ) {

    nf = I.nf;
    nc = I.nc;

    data = new Pixel*[nf];
    for(int i=0 ; i<nf ; i++){

        data[i] = new Pixel[nc];
        for( int j=0; j<nc ; j++){
            data[i][j].r = I.data[i][j].r;
            data[i][j].b = I.data[i][j].b ;
            data[i][j].g = I.data[i][j].g ; //Como los 3 son 255
            data[i][j].transp = I.data[i][j].transp; //No se verá

            //data[i][j] = I.data[i][j];      //SE PODRIA HACER? (sobrecargar operador= ?)
        }
    }
}

imagen & imagen::operator=(const imagen & I) {

    nf = I.nf;
    nc = I.nc;

    data = new Pixel*[nf];
    for(int i=0 ; i<nf ; i++){

        data[i] = new Pixel[nc];
        for( int j=0; j<nc ; j++){
            data[i][j].r = I.data[i][j].r;
            data[i][j].b = I.data[i][j].b ;
            data[i][j].g = I.data[i][j].g ; //Como los 3 son 255
            data[i][j].transp = I.data[i][j].transp; //No se verá

            //data[i][j] = I.data[i][j];      //SE PODRIA HACER?
        }
    }
    return *this; //Devuelve una copia del objeto actual
}

imagen::~imagen() {
    if (data != nullptr) { //Si ya es nullptr, no haria falta llamar al destructor
        for (int i = 0; i < nf; ++i) {
            delete[] data[i];
        }
        delete[] data;
        //data = nullptr; // Establece data de vuelta a nullptr por si acaso
    }
}
//set y get
Pixel & imagen::operator ()(int i,int j){ //POR QUE DOS VECES

    assert(i>=0 && i<nf && j>=0 && j<nc); //Comprueba que esta dentro de los limites disponibles

    return data[i][j];
}

const Pixel & imagen::operator()(int i,int j)const{

    assert(i>=0 && i<nf && j>=0 && j<nc); //Comprueba que esta dentro de los limites disponibles

    return data[i][j];
}



void imagen::EscribirImagen(const char * nombre){
    unsigned char * aux = new unsigned char [nf*nc*3];
    unsigned char * m = new unsigned char [nf*nc];

    int total = nf*nc*3;
    for (int i=0;i<total;i+=3){
        int posi = i /(nc*3);
        int posj = (i%(nc*3))/3;

        aux[i]=data[posi][posj].r;
        aux[i+1]=data[posi][posj].g;
        aux[i+2]=data[posi][posj].b;
        m[i/3]=data[posi][posj].transp;

    }

    if (!EscribirImagenPPM (nombre, aux,nf,nc)){
        cerr<<"Ha habido un problema en la escritura de "<<nombre<<endl;
    }
    delete[]aux;
    string n_aux = "mascara_";
    n_aux =n_aux+nombre;
    std::size_t found =n_aux.find(".ppm");
    if (found!=std::string::npos){
        n_aux =n_aux.substr(0,found);
    }
    n_aux =n_aux+".pgm";


    if (!EscribirImagenPGM (n_aux.c_str(), m,nf,nc)){
        cerr<<"Ha habido un problema en la escritura de "<<n_aux<<endl;
    }
    delete []m;

}

void imagen::LeerImagen(const char * nombre,const string &nombremascara){
    int f,c;
    unsigned char * aux,*aux_mask ;

    LeerTipoImagen(nombre, f, c);
    aux = new unsigned char [f*c*3];
    LeerImagenPPM (nombre, f,c,aux);
    if (!nombremascara.empty()){
        int fm,cm;
        LeerTipoImagen(nombremascara.c_str(), fm, cm);
        aux_mask = new unsigned char [fm*cm];
        LeerImagenPGM(nombremascara.c_str(), fm,cm,aux_mask);
    }
    else{
        aux_mask=nullptr;
    }

    imagen I(f,c);

    int total = f*c*3;
    for (int i=0;i<total;i+=3){
        int posi = i /(c*3);
        int posj = (i%(c*3))/3;
        //   cout<<posi<<" " <<posj<<endl;
        I.data[posi][posj].r=aux[i];
        I.data[posi][posj].g=aux[i+1];
        I.data[posi][posj].b=aux[i+2];
        if (aux_mask!=nullptr)
            I.data[posi][posj].transp=aux_mask[i/3];
        else
            I.data[posi][posj].transp=255;
    }

    *this = I;
    if (aux_mask!=0) delete[]aux_mask;
    delete []aux;
}
void imagen::LimpiarTransp(){

    for(int i=0; i < num_filas() ; i++){
        for(int j=0; j<num_cols() ; j++){

            data[i][j].transp = 255;    //Le quitamos los restos de trasparencia que pudiera tener
        }
    }

}

void imagen::PutImagen(int posi,int posj, const imagen &I,Tipo_Pegado tippegado){
    //assert(nf>=posi+I.nf && nc>=posj+I.nc);

    for (int i=0;i<I.nf;i++)
        for (int j=0;j<I.nc;j++)
            if (i+posi>=0 && i+posi<nf && j+posj>=0 && j+posj<nc){
                if (I.data[i][j].transp!=0){
                    if (tippegado==OPACO)
                        data[i+posi][j+posj]=I.data[i][j];
                    else{
                        data[i+posi][j+posj].r=(data[i+posi][j+posj].r+I.data[i][j].r)/2;
                        data[i+posi][j+posj].g=(data[i+posi][j+posj].r+I.data[i][j].g)/2;
                        data[i+posi][j+posj].b=(data[i+posi][j+posj].r+I.data[i][j].b)/2;
                    }

                }
            }

}

imagen imagen::ExtraeImagen(int posi, int posj, int dimi, int dimj){
    imagen out;

    for(int i=0 ; i<dimi ; i++){
        for(int j=0; j<dimj ; j++){
            if((i + posi >= 0) && (i + posi < nf) && (j + posj >= 0) && (j + posj < nc)){ //Comprueba que esta dentro de los limites disponibles

                out(i,j)=data[posi+i][posj+j];
            }
        }
    }
    return out;
}

