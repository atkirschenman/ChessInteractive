#include "PhysicalBoard.h"

int PhysicalBoard::HEsetup[4][4] = {
  {9, 8, 7, 5},
  {11, 10, 6, 4},
  {12, 14, 1, 3},
  {13, 15, 0, 2}  
};

int PhysicalBoard::currentBoard[8][8];
int PhysicalBoard::readBoard[8][8];
int PhysicalBoard::boardX = 0;
int PhysicalBoard::boardY = 0;

int PhysicalBoard::pickupLocation[2];
int PhysicalBoard::placeLocation[2];
bool PhysicalBoard::pickupLocationHasValue = false;
bool PhysicalBoard::placeLocationHasValue = false;

int PhysicalBoard::boardOrder[2][2] = {
  {3, 2},
  {0, 1}
};

Adafruit_MCP23X17 PhysicalBoard::mcp[4];


void PhysicalBoard::setupMCP(){
  for(int i = 0; i <= 3; i++){
    mcp[i].begin_I2C(32 + i); // 32 is 0x20 in hexidecimal and 33 will be 0x21 in hexidecimal
    for(int j = 0; j < 16; j++){
      mcp[i].pinMode(j, INPUT_PULLUP);
    }
  }
}

void PhysicalBoard::initalizeBoard(){
    for(int i = 0; i < 2; i++){ // panel rows
        for(int j = 0; j < 4; j++){ // cell rows
            for(int k = 0; k < 2; k++){ // panel columns
                for(int l = 0; l < 4; l++){ // cell columns
                    readBoard[boardY][boardX] = !mcp[boardOrder[i][k]].digitalRead(HEsetup[j][l]);
                    currentBoard[boardY][boardX] = readBoard[boardY][boardX];
                    //  Serial.print(readBoard[boardY][boardX]);
                    boardX++;
                }
            }
            boardY++;
            boardX = 0;
            //    Serial.println();
        }
    }
    boardY = 0;  
}

void PhysicalBoard::getBoardOutput(){
    for(int i = 0; i < 2; i++){ // panel rows
        for(int j = 0; j < 4; j++){ // cell rows
            for(int k = 0; k < 2; k++){ // panel columns
                for(int l = 0; l < 4; l++){ // cell columns
                    readBoard[boardY][boardX] = !mcp[boardOrder[i][k]].digitalRead(HEsetup[j][l]);
                    //  Serial.print(readBoard[boardY][boardX]);
                    boardX++;
                }
            }
            boardY++;
            boardX = 0;
            //    Serial.println();
        }
    }
    boardY = 0;

    // for(int i = 0; i < 8; i++){
    //     for(int j = 0; j < 8; j++){
    //         Serial.print(readBoard[i][j]);
    //     }

    //     Serial.print("\t\t\t\t\t");

    //     for(int j = 0; j < 8; j++){
    //         Serial.print(currentBoard[i][j]);
    //     }
    //     Serial.println();
    // }

    if(!boardsAreEqual(readBoard, currentBoard)){ // if boards are not equl then set them equal
        memcpy(currentBoard, readBoard, sizeof(readBoard)); // assignes the current board what is being read
        return;
    }
}
void PhysicalBoard::checkPickAndPlace(){
    if((pickupLocationHasValue  && placeLocationHasValue)  ||  (placeLocationHasValue && !pickupLocationHasValue)){
        if(pickupLocation == placeLocation){
            pickupLocationHasValue = false;
            placeLocationHasValue = false;
            Serial.println("you picked up and placed in the same spot so i am deleteing pickup and place values");
            return;
        }
        String messageToSend;
        messageToSend = String(intToCharOnBoard(pickupLocation[0])) + (8-pickupLocation[1]) + String(intToCharOnBoard(placeLocation[0])) + (8-placeLocation[1]);
        Serial.println(messageToSend);

        LichessAPI::makeABotMove(LichessAPI::getCurrentGameId(), messageToSend);

    
        pickupLocationHasValue = false;
        placeLocationHasValue = false;
    }
}

char PhysicalBoard::intToCharOnBoard(int x){
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
    return 'x';
}


bool PhysicalBoard::boardsAreEqual(int readBoard[8][8], int currentBoard[8][8]){
    bool boardsMatch = true; 
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (readBoard[i][j] != currentBoard[i][j]) {
                if(readBoard[i][j] < currentBoard[i][j]){
                    if(!pickupLocationHasValue){
                        pickupLocation[0] = j;
                        pickupLocation[1] = i;
                        pickupLocationHasValue = true;
                    }

                    Serial.print("piece picked up at x: ");
                    Serial.print(j);
                    Serial.print("and y: ");
                    Serial.println(i);
                }else{
                    placeLocation[0] = j;
                    placeLocation[1] = i;
                    placeLocationHasValue = true;

                    Serial.print("piece picked up at x: ");
                    Serial.print(placeLocation[0]);
                    Serial.print("and y: ");
                    Serial.println(placeLocation[1]);
                }
                checkPickAndPlace();
                boardsMatch =  false;
                // this is where you can get the x,y values for where the piece is moved
            }
        }
    }
    return  boardsMatch;
}


