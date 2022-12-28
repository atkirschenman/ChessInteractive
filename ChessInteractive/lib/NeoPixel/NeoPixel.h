#ifndef NeoPixel_h
#define NeoPixel_h
    #include <Adafruit_NeoPixel.h>

    class NeoPixel{
      private: 
        static int neoSetup[4][4];
        static int panelOrder[2][2];
        static int boardLED[8][8];
        #define LED_PIN 15;
        #define LED_COUNT 64;
        // Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

      public:
        static void initalizeBoardLED();
        static void setBrightness(uint8_t brightness);
        static void begin();
        static void illuminateCell(int x, int y);
        static void clear();
    };

#endif