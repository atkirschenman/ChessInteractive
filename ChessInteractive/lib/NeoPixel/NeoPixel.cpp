#include "NeoPixel.h"

#define LED_PIN 15
#define LED_COUNT 64

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
String NeoPixel::oldLastMove; 

int NeoPixel::neoSetup[4][4] = {
  {3, 4, 11, 12},
  {2, 5, 10, 13},
  {1, 6, 9, 14},
  {0, 7, 8, 15}
};

int NeoPixel::panelOrder[2][2] = { // order of how the panels are alligned to create the chess board (numbers represent the addresses)
  {2, 3},
  {0, 1}
};

int NeoPixel::boardLED[8][8];

void NeoPixel::initalizeBoardLED(){
    int boardX;
    int boardY;

    for(int i = 0; i < 2; i++){ // panel rows
        for(int j = 0; j < 4; j++){ // cell rows
            for(int k = 0; k < 2; k++){ // panel columns
                for(int l = 0; l < 4; l++){ // cell columns
                    boardLED[boardY][boardX] = neoSetup[j][l] + panelOrder[i][k] * 16;
                    boardX++; // next column
                }
            }
            boardY++; // move to the next row
            boardX = 0; // reset column number
        }
    }
};

void NeoPixel::begin(){
    strip.begin();
    strip.show();
}

void NeoPixel::setBrightness(uint8_t brightness){ // constructor
    strip.setBrightness(brightness); // Set BRIGHTNESS to about 1/5 (max = 255)
}

// void NeoPixel::illuminateCell(int x, int y){
//     strip.setPixelColor(boardLED[y][x], strip.Color(255,   0,   0));         //  Set pixel's color (in RAM)
//     strip.show();
// }

void NeoPixel::illuminateCell(int x, int y){ // overloaded method where default value is red
    NeoPixel::illuminateCell(x, y, strip.Color(255, 0, 0));
}


void NeoPixel::illuminateCell(int x, int y, uint32_t color){
    strip.setPixelColor(boardLED[y][x], color);         //  Set pixel's color (in RAM)
    strip.show();
}


void NeoPixel::illuminateBoard(int board[8][8]){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board[j][i] == 1){
                illuminateCell(i, j);
            }
        }
    }
}

void NeoPixel::clear(){
    strip.clear();
}

void NeoPixel::highlightLastMove(){
    clear();
    Serial.println("highlightLastMoveMethod:");
    String lastMove = LichessAPI::getLastMove();
    if(lastMove == "" || lastMove == oldLastMove){ // if no last move, game just started or lastMove is that same as the previous last move. 
        Serial.println("last moves are the same");
        // clear();
        return;
    }
    Serial.println("moves not the same, setting old move to last move");

    oldLastMove = lastMove; 

    int myArray[4];
    
    for(int i = 0; i < lastMove.length(); i++){
        switch (lastMove[i]){
            case 'a':
                myArray[i] = 0;
                break;
            case 'b':
                myArray[i] = 1;
                break;
            case 'c':
                myArray[i] = 2;
                break;
            case 'd':
                myArray[i] = 3;
                break;
            case 'e':
                myArray[i] = 4;
                break;
            case 'f':
                myArray[i] = 5;
                break;
            case 'g':
                myArray[i] = 6;
                break;
            case 'h':
                myArray[i] = 7;
                break;
            default:
                myArray[i] = 8 - (lastMove[i] - '0');
        }
        // Serial.print(myArray[i]);
    }
        
    for(int i = 0; i < lastMove.length(); i++){
        PhysicalBoard::cellsToIgnore[i] = myArray[i];
    }
    
    illuminateCell(myArray[0], myArray[1], strip.Color(255, 0, 0)); // from 
    illuminateCell(myArray[2], myArray[3], strip.Color(0, 255, 0)); // to
}


