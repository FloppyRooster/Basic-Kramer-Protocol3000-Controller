#include <SoftwareSerial.h>
#include <Keypad.h>

//This next bit converts the keypad inputs into an array of chars for 1-G (single char only)
const byte ROWS = 4; 
const byte COLS = 4; 

int hexaKeys[ROWS][COLS] = {
  {1, 2, 3, 4},
  {5, 6, 7, 8},
  {9, 10, 11, 12},
  {13, 14, 15, 16}
};

byte rowPins[ROWS] = {5, 4, 3, 2}; 
byte colPins[COLS] = {6, 7, 8, 9}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

const byte rxPin = 11;
const byte txPin = 12;

// Set up a new SoftwareSerial object
SoftwareSerial mySerial (rxPin, txPin);

char commands[16][64] = {
  //Top Row, Hard Coded Presets
  "#VID 1>1,1>2,1>3,1>4\r", //All into 1
  "#VID 2>1,2>2,2>3,2>4\r", // All into 2
  "#VID 3>1,3>2,3>3,3>4\r", //All into 3
  "#VID 4>1,4>2,4>3,4>4\r", // All into 4

  //Second Row recall presets
  "#PRST-RCL 1\r", 
  "#PRST-RCL 2\r",
  "#PRST-RCL 3\r",
  "#PRST-RCL 4\r",

  //Third Row recall presets, 8 presets as maximum
  "#PRST-RCL 5\r",
  "#PRST-RCL 6\r",
  "#PRST-RCL 7\r",
  "#PRST-RCL 8\r",
  
  "#VID 0>1,0>2,0>3,0>4\r", //Blank
  "#VID 0>1,0>2,0>3,0>4\r", //Blank
  "#VID 0>1,0>2,0>3,0>4\r", //Blank
  "#VID 0>1,0>2,0>3,0>4\r", //Blank

  }

void setup(){
  // start communication with baud rate 9600
  mySerial.begin(9600);  

  // wait a moment to allow serial ports to initialize
  delay(100);

}

//Standard Protocol alignment v
//mySerial.write("#VID 1>1,2>2,3>3,4>4\r");
void loop(){
  char customKey = customKeypad.getKey();

  if (customKey){
    //Need to add something close to a switch case here
    mySerial.write("#VID 1>1,2>2,3>3,4>4\r");
  }
}
