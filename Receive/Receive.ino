int ReadFrom=0;
int x;
int WriteTo=0;
int buffer[11];
void setup() {
  

}

void loop() {
 if (buffer[ReadFrom]!=-1)
 {
   Serial.write(buffer[ReadFrom]);
   buffer[ReadFrom]=-1;
   ReadFrom++;
 }
 
  x=Serial.read();
  if (x!=-1)
  {
    buffer[WriteTo]=x;
    WriteTo++;
  }
}

