#ifndef NeoPixel_h
#define NeoPixel_h
#include <Adafruit_NeoPixel.h>
#include <LichessAPI.h>
#include <PhysicalBoard.h>

class NeoPixel{
  private: 
    static uint8_t neoSetup[][4];
    static uint8_t panelOrder[][2];
    static uint8_t boardLED[8][8];
    // Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
    static String oldLastMove; 

  public:
    static void initalizeBoardLED();
    static void setBrightness(uint8_t brightness);
    static void begin();
    static void illuminateCell(uint8_t x, uint8_t y);
    static void illuminateCell(uint8_t x, uint8_t y, uint32_t color);
    static void clear();
    static void highlightLastMove();
    static void illuminateBoard(uint8_t board[8][8]);
};

#endif