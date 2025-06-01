#include <SoftwareSerial.h>
#include <Keypad.h>

//This next bit converts the keypad inputs into an array of chars for 1-G (single char only)
const byte ROWS = 4; 
const byte COLS = 4; 

//This assigns each key to a unique identifier, done this way so the buttons can be easily rotated, swapped ect.
/*int hexaKeys[ROWS][COLS] = {
  {1, 2, 3, 4},
  {5, 6, 7, 8},
  {9, 10, 11, 12},
  {13, 14, 15, 16}
};*/

char hexaKeys[ROWS][COLS] = {
  {'0','1','2','3'},
  {'4','5','6','7'},
  {'8','9','A','B'},
  {'C','D','E','F'}
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

  //2nd Row More Customs
  "#VID 1>1,3>2,1>3,1>4\r", 
  "#VID 3>1,1>2,3>3,3>4\r", 
  "#VID 0>1,0>2,0>3,0>4\r", //Blank
  "#VID 0>1,0>2,0>3,0>4\r", //Blank

  //Third Row recall presets 1-4
  "#PRST-RCL 1\r", 
  "#PRST-RCL 2\r",
  "#PRST-RCL 3\r",
  "#PRST-RCL 4\r",

  //Third Row recall presets 5-8, 8 presets as maximum
  "#PRST-RCL 5\r",
  "#PRST-RCL 6\r",
  "#PRST-RCL 7\r",
  "#PRST-RCL 8\r",
};

void setup(){
  // start communication with baud rate 9600
  mySerial.begin(9600);  
  Serial.begin(9600);//USB deguging output
  // wait a moment to allow serial ports to initialize
  delay(100);
  
}

//Standard Protocol alignment v
//mySerial.write("#VID 1>1,2>2,3>3,4>4\r");
void loop(){
  char customKey = customKeypad.getKey();
  int commandIndex = customKey - '0'; //Becuase fuck you this converts char to int
  if (commandIndex > 9) {
    commandIndex -= 7; // Because there are 7 charachters between 9 and A in ascii 
  }
 
  
  //Literally just runs the command number as defined in the commands variable.
  if (customKey){
    //mySerial.write(commands[customKey]);
    Serial.println(commands[commandIndex]);
    //Serial.println(customKey);

  }
}
