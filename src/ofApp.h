#pragma once

#include "ofMain.h"


#define SOURCENUM 39
#define NUMFILES 3

class ofApp : public ofBaseApp{

	public:
    

		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        float normalizarValor( float valor );
    
    
    
        int numeroDeFuentes;
    
        // arreglo de numeroDeFuentes contadores de pasos de lectura
        // pasoLectura[ indice ] = pasoActualDeCadaCurva
        int pasosLectura[SOURCENUM];
    
    
        // valor hardcodeado para
        // limitar lecturas, para no salirnos del limite de lo que contiene CSV
        // idealmente, deberia ser un valor distinto para cada curva, cuando se sepa
        // la cantidad total de registros
    
        int totalPasosLectura;
    
        int numeroCurvas;
    
        // 3a columna, flux
        int indiceLecturaCSV;
    
        // arreglo de velocidades de lectura
    
        int velocidadesLectura[SOURCENUM] = {
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
    
    
    
    
    
        float valoresLeidos[SOURCENUM];
    
    
    
    
        // cuantos frames de OF entre lectura y lectura
        int frecuenciaDeLectura;
    
        int contadorGeneral;
        int contadorTicks;
    
    
    
        // TEMPORAL PARA PROBAR
        float curvasDeLuz[NUMFILES][NUMFILES];
    
    
    
    ofLight pointLight;
    ofLight pointLight2;
    ofLight pointLight3;
    

    
};
