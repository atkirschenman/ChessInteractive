#include "PhysicalBoard.h"

// some things are hard coded such as the size of oldBoard (8x8), newBoard (8x8), setupMPC (typed in 16 HE sensors and 4 panels), readBoard (typed in panel count and cell x,y count), checkPickAndPlace (has 8-xxx )

int PhysicalBoard::HEsetup[4][4] = { // This is the order of the I2C I/O as seen visually on the chess panel
  {9, 8, 7, 5},
  {11, 10, 6, 4},
  {12, 14, 1, 3},
  {13, 15, 0, 2}  
};

int PhysicalBoard::oldBoard[8][8]; // What the board value was from last pickup/placement of piece
int PhysicalBoard::newBoard[8][8]; // What is read from the HE sensors
int PhysicalBoard::pickupLocation[2]; // x,y of piece that is picked up
int PhysicalBoard::placeLocation[2]; // x,y of piece that is placed
bool PhysicalBoard::isPickedUp = false; // boolean if piece is picked up
bool PhysicalBoard::isPlaced = false; // boolean if piece is placed
bool PhysicalBoard::boardInitalized = false;

int PhysicalBoard::panelOrder[2][2] = { // order of how the panels are alligned to create the chess board (numbers represent the addresses)
  {3, 2},
  {0, 1}
};

Adafruit_MCP23X17 PhysicalBoard::mcp[4];  // instantiating the MCP20317 I2C bus

void PhysicalBoard::setupMCP(){ // Setting up I2C MCP23017 
  for(int i = 0; i < 4; i++){ // for how many panels we have (starting from 0)
    mcp[i].begin_I2C(32 + i); // 32 is 0x20 in hexidecimal and 33 will be 0x21 in hexidecimal
    for(int j = 0; j < 16; j++){ // for how many I/O we have per panel (starting from 0)
      mcp[i].pinMode(j, INPUT_PULLUP);
    }
  }
}

void PhysicalBoard::readBoard(){ // read the values of the chess board and assign to newBoard. use another private method to see if they are equal
    int boardX; // x index of what we are trying to assign what the board will read
    int boardY; // y index of what we are trying to assign what the board will read

    for(int i = 0; i < 2; i++){ // panel rows
        for(int j = 0; j < 4; j++){ // cell rows
            for(int k = 0; k < 2; k++){ // panel columns
                for(int l = 0; l < 4; l++){ // cell columns
                    newBoard[boardY][boardX] = !mcp[panelOrder[i][k]].digitalRead(HEsetup[j][l]);
                    boardX++; // next column
                }
            }
            boardY++; // move to the next row
            boardX = 0; // reset column number
        }
    }

    if(!boardInitalized){ // if board is not initalized, then set old board equal to new board
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                oldBoard[j][i] = newBoard[j][i];
            }
        }
        boardInitalized = true;
    }

    if(!boardsMatch(newBoard, oldBoard)){ // if boards are not equal then set them equal
        memcpy(oldBoard, newBoard, sizeof(newBoard)); // assignes the current board what is being read
    }
}

void PhysicalBoard::checkPickAndPlace(){ //
    if(isPickedUp  && isPlaced){ // if a piece is picked up and placed
        isPickedUp = false; // reset 
        isPlaced = false; // reset
        Serial.print("pickup location: ");
        Serial.print(pickupLocation[0]);
        Serial.print(", ");
        Serial.println(pickupLocation[1]);

        Serial.print("place location: ");
        Serial.print(placeLocation[0]);
        Serial.print(", ");
        Serial.println(placeLocation[1]);

        if(memcmp(pickupLocation, placeLocation, sizeof(pickupLocation)) == 0){ // if picked up and placed in the same location, return 
            return;
        }

        String messageToSend;
        messageToSend = String(intToCharOnBoard(pickupLocation[0])) + (8-pickupLocation[1]) + String(intToCharOnBoard(placeLocation[0])) + (8-placeLocation[1]);
        Serial.println(messageToSend);

        LichessAPI::makeABotMove(LichessAPI::getCurrentGameId(), messageToSend); // send move to lichess
    }else{
        // do nothing
    }
}

char PhysicalBoard::intToCharOnBoard(int x){ // translates int index to char letter value used in chess
    switch(x){
        case 0:
            return 'a';
        case 1:
            return 'b';
        case 2:
            return 'c';
        case 3:
            return 'd';
        case 4:
            return 'e';
        case 5:
            return 'f';
        case 6:
            return 'g';
        case 7:
            return 'h';
    }
    return 'x'; // send garbage value. i put this here because it gave warning  
}

bool PhysicalBoard::boardsMatch(int newBoard[8][8], int oldBoard[8][8]){ // check to see if newBoard and oldBoard are the same
    bool boardsMatch = true; 
    for (int i = 0; i < 8; i++) { // for every row
        for (int j = 0; j < 8; j++) { // for every column
            if (newBoard[i][j] != oldBoard[i][j]) { // if newBoard and oldBoard have a difference in values do the following
                if(newBoard[i][j] == 0){ // if 0, piece is picked up
                    if(!isPickedUp){  // needed so if other pieces are picked up, they are ignored. Example would be user picks up their piece then opponents piece to take that spot. 
                        pickupLocation[0] = j; // x index
                        pickupLocation[1] = i; // y index
                        isPickedUp = true; // piece picked up true
                    }

                    Serial.print("piece picked up at x: ");
                    Serial.print(j);
                    Serial.print("and y: ");
                    Serial.println(i);
                }else{ // if not picked up, then newBoard must have piece placed onto the board
                    placeLocation[0] = j; // x index
                    placeLocation[1] = i; // y index
                    isPlaced = true; // a piece has been placed3

                    Serial.print("piece placed up at x: ");
                    Serial.print(placeLocation[0]);
                    Serial.print("and y: ");
                    Serial.println(placeLocation[1]);
                }
                checkPickAndPlace();  
                boardsMatch =  false;
                break; // leave for loop since boards don't match

                // this is where you can get the x,y values for where the piece is moved
            }
        }
    }
    return  boardsMatch;
}