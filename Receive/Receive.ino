int ReadFrom=0;
int x;
int WriteTo=0;
int a;
int buffer[11];
void setup() {
  Serial.begin(9600);

}

void loop() {
  for(a=1;a!=10;1)
  {
    Serial.print(buffer[a]);
    
  }
  Serial.println('a');
 if (buffer[ReadFrom]!=-1)
 {
   Serial.print(buffer[ReadFrom]);
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

