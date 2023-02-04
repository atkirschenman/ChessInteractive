#include "NeoPixel.h"

#define LED_PIN 15 // has to be preprocessed
#define LED_COUNT 64 // has to be preprocessed
#define BOARD_WIDTH 8 // width of board

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
String NeoPixel::oldLastMove; // used to compare last move and see if they are different

uint8_t NeoPixel::neoSetup[][4] = { // locations of the HE I/O sensors on the panel
  {3, 4, 11, 12},
  {2, 5, 10, 13},
  {1, 6, 9, 14},
  {0, 7, 8, 15}
};

uint8_t NeoPixel::panelOrder[][2] = { // order of how the panels are alligned to create the chess board (numbers represent the addresses)
  {2, 3},
  {0, 1}
};

uint8_t NeoPixel::boardLED[BOARD_WIDTH][BOARD_WIDTH]; // Matrix of LED's need to change uint8_t if board larger than 16x16

void NeoPixel::initalizeBoardLED(){ // Rans once, read board I/O status
    uint8_t boardX; // x location of board matrix
    uint8_t boardY; // y location of board matrix

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

void NeoPixel::begin(){ // begin LED's
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

void NeoPixel::illuminateCell(uint8_t x, uint8_t y){ // overloaded method where default value is red
    NeoPixel::illuminateCell(x, y, strip.Color(255, 0, 0));
}

void NeoPixel::illuminateCell(uint8_t x, uint8_t y, uint32_t color){ // lights up 1 LED with custom color
    strip.setPixelColor(boardLED[y][x], color);         //  Set pixel's color (in RAM)
    strip.show();
}


void NeoPixel::illuminateBoard(uint8_t board[8][8]){ // illuminate whole board, given the matrix as an argument
    for(int i = 0; i < BOARD_WIDTH; i++){
        for(int j = 0; j < BOARD_WIDTH; j++){
            if(board[j][i] == 1){
                illuminateCell(i, j);
            }
        }
    }
}

void NeoPixel::clear(){ // turn off all LED's
    strip.clear();
}

void NeoPixel::highlightLastMove(){ // highlights the "from" square to the "to" square
    clear(); // turn off all LED's

    String lastMove = LichessAPI::getLastMove(); // get last move from lichess
    if(lastMove == "" || lastMove == oldLastMove){ // if no last move, game just started or lastMove is that same as the previous last move. 
        Serial.println("last moves are the same");
        // clear();
        return;
    }
    Serial.println("moves not the same, setting old move to last move");

    oldLastMove = lastMove; 

    uint8_t myArray[4]; // represents {from_x, from_y, to_x, to_y}
    
    for(uint8_t i = 0; i < lastMove.length(); i++){
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
    }
        
    for(int i = 0; i < lastMove.length(); i++){
        PhysicalBoard::cellsToIgnore[i] = myArray[i];
    }
    
    illuminateCell(myArray[0], myArray[1], strip.Color(255, 0, 0)); // from 
    illuminateCell(myArray[2], myArray[3], strip.Color(0, 255, 0)); // to
}


