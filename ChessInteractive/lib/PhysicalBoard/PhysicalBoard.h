#ifndef PhysicalBoard_h
#define PhysicalBoard_h
    #include <Adafruit_MCP23X17.h>  // I2C for physical board
    #include <LichessAPI.h>         // Jacobs api class for lichess

    class PhysicalBoard{
      private: 
        static int HEsetup[4][4];
        static int currentBoard[8][8];
        static int readBoard[8][8];
        static int boardX;
        static int boardY;
        static int boardOrder[2][2];
        static Adafruit_MCP23X17 mcp[4];
        static void onPickup();
        static bool boardsAreEqual(int readBoard[8][8], int currentBoard[8][8]);
        static int pickupLocation[2];
        static int placeLocation[2];
        static void checkPickAndPlace();
        static bool pickupLocationHasValue;
        static bool placeLocationHasValue;
        static char intToCharOnBoard(int x);
      public:
        static void setupMCP();
        static void getBoardOutput();
        static void initalizeBoard();

    };

#endif