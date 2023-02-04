#ifndef PhysicalBoard_h
#define PhysicalBoard_h
  #include <Adafruit_MCP23X17.h>  // I2C for physical board
  #include <LichessAPI.h>         // Jacobs api class for lichess

  class PhysicalBoard{
    private: 
      static int HEsetup[4][4];
      static int oldBoard[8][8];
      static int panelOrder[2][2];
      static Adafruit_MCP23X17 mcp[4];
      static void onPickup();
      static bool boardsMatch(int newBoard[8][8], int oldBoard[8][8]);
      static int pickupLocation[2];
      static int placeLocation[2];
      static void checkPickAndPlace();
      static bool isPlaced;
      static char intToCharOnBoard(int x);
      static bool boardInitalized;
    public:
      static void setupMCP();
      static void readBoard();
      static int newBoard[8][8];
      static int cellsToIgnore[4];
      static bool isPickedUp;
  };

#endif