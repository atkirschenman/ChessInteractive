#include "NeoPixel.h"

#define LED_PIN 15
#define LED_COUNT 64

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

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

void NeoPixel::illuminateCell(int x, int y){
    strip.setPixelColor(boardLED[y][x], strip.Color(255,   0,   0));         //  Set pixel's color (in RAM)
    strip.show();
}

void NeoPixel::clear(){
    strip.clear();
}

