int buffer[10];
const byte interruptPin = 13;
bool stopwatchRunning = 0;
int nextBuffer = 1;
int nextReadBuffer = 0;
const byte ledPin = 13;
int tempBuffer[2];

void setup()
{
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), sendInfo, CHANGE);
  byte arduino_Number = 1; // change for each arduino
  Wire.begin(); // join i2c bus (address optional for master)
  //TWBR = 12; //Increase i2c speed if you have Arduino MEGA2560, not suitable for Arduino UNO
  Serial.begin(57600);  // start serial for output
  Serial.flush();

  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

}
int readBuffer()
{
  if (nextReadBuffer != nextBuffer)
  {
    tempBuffer[1]=buffer[nextReadBuffer];
    tempBuffer[2]=0;
    nextReadBuffer++;
  }
  else
  {
    tempBuffer[1]=0;
    tempBuffer[2]=1;
  }
}
void addToBuffer( int number )
{
  buffer[nextBuffer] = number;
  nextBuffer++;
  if (nextBuffer > 10)
  {
    nextBuffer = 1;
  }
}
void sendInfo()
{
  addToBuffer(Arduino_Number);
}
void loop()
{
  if (Serial.available() > 0)
  {
    addToBuffer(Serial.read());
  }
  sendInfo();
  if (tempBuffer[2] = 0)
  {
    serial.write(tempBuffer[1]);
  }
}


