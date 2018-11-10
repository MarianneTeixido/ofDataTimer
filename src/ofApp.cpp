#include "ofApp.h"


/*


// valor hardcodeado para
// limitar lecturas, para no salirnos del limite de lo que contiene CSV
// idealmente, deberia ser un valor distinto para cada curva, cuando se sepa
// la cantidad total de registros

int totalPasosLectura = 400;

int numeroCurvas = 3;

// 3a columna, flux
int indiceLecturaCSV = 2;

// arreglo de velocidades de lectura

int velocidadesLectura [ 39 ] = {
    1, 1, 1,
    2, 2, 2,
    3, 3, 3,
    4, 4, 4,
    5, 5, 5,
    6, 6, 6,
    7, 7, 7,
    8, 8, 8,
    9, 9 ,9,
    10, 10, 10,
    11, 11, 11,
    12, 12, 12,
    13, 13, 13
};




int valoresLeidos [ 39 ];



 */





//--------------------------------------------------------------
void ofApp::setup(){


    
    numeroDeFuentes = SOURCENUM;
    
    totalPasosLectura = 3;
    
    numeroCurvas = 3;
    
    // 3a columna, flux
    indiceLecturaCSV = 2;
    
    
    
    
    // cuantos frames de OF entre lectura y lectura
    frecuenciaDeLectura = 5;
    contadorGeneral = 0;
    contadorTicks = 0;
    
    // inicializar valores de pasosLectura a 0
    // par que todos empiecen en el primero
    
    for( int i = 0; i < numeroDeFuentes; i++ ) {
        pasosLectura[ i ] = 0;
        valoresLeidos[ i ] = 0;
    }
    
    
    // HARDCODEADO PARA PROBAR
    curvasDeLuz[0][0] = 1.0f;
    curvasDeLuz[0][1] = 1.0f;
    curvasDeLuz[0][2] = 0.4f;

    curvasDeLuz[1][0] = 1.0f;
    curvasDeLuz[1][1] = 1.0f;
    curvasDeLuz[1][2] = 2.6f;

    curvasDeLuz[2][0] = 1.0f;
    curvasDeLuz[2][1] = 1.0f;
    curvasDeLuz[2][2] = 1.0f;

    
    
}

//--------------------------------------------------------------
void ofApp::update(){

    
    
    // cada N cuadros, hacer un 'tick' de reloj
    // usnado el operador modulo '%' para alentar la lectura
    // pues OF corre muy rapidoç

    if( contadorGeneral % frecuenciaDeLectura == 0 ) {
        
        // lo siguiente ocurre cada 'tick'
        
        // leer un valor para de cada uno de los cuerpos celestes
        for( int indiceFuente = 0; indiceFuente < numeroDeFuentes; indiceFuente++ ) {

            if( contadorTicks % velocidadesLectura[ indiceFuente ] == 0 ) {
                
                // un 'tick' para cada una de las fuentes
                
                
                float valorLeido;
                
                // inicializar
                valorLeido = 0;

                // efectuar lectura
                
                // tomar tercer indice de ccada registro del csv:
                // el tercer indice es 'flux'
                
                indiceLecturaCSV = pasosLectura[ indiceFuente ];
                
                valorLeido = curvasDeLuz[ indiceFuente % numeroCurvas ][ indiceLecturaCSV ];

                
                cout << contadorTicks << " " << indiceFuente << " " << valorLeido << endl;

               
                // almacenar valor leido en un arreglo
                valoresLeidos[ indiceFuente ] = normalizarValor( valorLeido );
                
                
                
                // incrementar paso de cada fuente
                pasosLectura[ indiceFuente ]++;
                
                // limitar numero de pasos, para que no exceda
                // las dimensiones del array
                pasosLectura[ indiceFuente ] %= totalPasosLectura;
                
                
                // controlar paramaetros visuales
                // p.ej.,d cualquier funcion
                /*
                 estrella.cambiarColor( indiceLectura, valorLeido )
                 */
                
                
                // OSC
                
                // enviar mensaje OSC
                /* // resultado esperado
                 /curvasDeLuz, indiceLectura, valorLeido
                 */
                
            }
            

        }
        
        // incremenetar ocntador ticks
        contadorTicks++;
        // prevenir que se salga del limite de un int
        contadorTicks %= 10000;
        
    }
    
    
    // incrementar contador general
    contadorGeneral++;
    // prevenir que se salga del limite de un int
    contadorGeneral %= 10000;

    
    
    
    ofSetSmoothLighting(true);
    pointLight.setDiffuseColor( ofFloatColor(.85, .85, .55) );
    pointLight.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));
    
    pointLight2.setDiffuseColor( ofFloatColor( 238.f/255.f, 57.f/255.f, 135.f/255.f ));
    pointLight2.setSpecularColor(ofFloatColor(.8f, .8f, .9f));
    
    pointLight3.setDiffuseColor( ofFloatColor(19.f/255.f,94.f/255.f,77.f/255.f) );
    pointLight3.setSpecularColor( ofFloatColor(18.f/255.f,150.f/255.f,135.f/255.f) );
    
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    
    
    
    ofSetWindowTitle("reloj csv");
    ofBackground(0);
    ofSetColor(255);
    
    
    for( int indiceFuente = 0; indiceFuente < numeroDeFuentes; indiceFuente++ ) {
        
        
        
        float valorFuente = valoresLeidos[ indiceFuente ];
        
        // dibujar numeroDeFuentes objetos

        ofDrawSphere(
            // colocar numeroDeFuentes esferas distribuidas en una hilera
            // a la mitad de la altura de la pantalla
            ofPoint(
                    
            (ofGetWidth() * (float)((float)(1)/(float)(numeroDeFuentes))) * (indiceFuente+1),
            ofGetHeight()* .5),
            // valor de radio desde curva de luz
            valorFuente * 15
                     
        );

        
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}





float ofApp::normalizarValor( float input ) {
    
    cout << "normalizar " << input << endl;
    // falta escribir codigo de normalizacion
    float result = input;
    return result;
    
}

