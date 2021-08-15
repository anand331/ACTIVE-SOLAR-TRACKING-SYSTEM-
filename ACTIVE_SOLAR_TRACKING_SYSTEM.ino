int ldr1;   //Variable for ldr1
int ldr2;   //variable for ldr2

void setup()
{
//put your setup code here, to run code once

Serial.begin(9600);  // For serial communication with pc

ldr1=analogRead(A0);  //Variable ldr1 stores the analog input at A0
ldr2=analogRead(A1);  //Variable ldr2 stores the analog input at A1

}
void loop() {
  //put your main code here, to run repeatedly

  Serial.println(ldr1); // Print the value stored in variable ldr1
  Serial.print("\t");   // Tab space
  Serial.print(ldr2);   // Print the value stored in variable ldr2
  Serial.println();     //new line
//assigning variables which point to pin nos,which control the motors

int base1 = 2;
int base2 = 3;
int top1 = 4;
int top2 = 5;

// assigning variables that point to pin number which recieve input from the sensors

int ldr1 = A0;
int ldr2 = A1;

int a = 850; // sensor 1 normal lighting value 
int c = 800; // sensor 2 normal lighting value
int b = 150; // sensor 1 maximum lighting value
int d = 300; // sensor 2 maximum lighting value 
//declaring variables to store current analog values at pins A0 and A1

int x;
int y;

// initialisation 
}
void setup()

{
  Serial.begin(9600); //baud rate

  // declaring pins connected to motor driver at output to motors

  pinMode(base1,OUTPUT);
  pinMode(base2,OUTPUT);
  pinMode(top1,OUTPUT);
  pinMode(top2,OUTPUT);
  
}
// writing instructions to execute 

void loop()
{
  // instructions to view analog value at pin A0 and A1 in the serial monitor 

  Serial.print(analogRead(ldr1));
  Serial.print("\t");
  Serial.print(analogRead(ldr2));
  Serial.println();

   delay(700); //delay for 700 milliseconds

  //using variables x and y to store values at pins A0 and A1

  x = analogRead(ldr1);  // analog voltage at A0 due to      sensor1
  y = analogRead(ldr2);  // analog voltage at A1 due to sensor2
// case1- if sensor1 detects lights,top motor should rotate clock wise
  if ((x>b) && (x<a))

  {
    digitalWrite(top1,LOW);
    digitalWrite(top2,HIGH);
    delay(200);
    digitalWrite(top1,LOW);
    digitalWrite(top2,LOW);
    delay(100);
  }
  //top motor should stop rotating when the sensor2 receives maximum incident light 

  if (x<b)
  {
    digitalWrite(top1,LOW);
    digitalWrite(top2,LOW);
    digitalWrite(base1,LOW);
    digitalWrite(base2,LOW);

  }
// Case2-if no light im=ncident on sensor 1, then check for light incident on sensor2 

  if (x>a)

  {
    if (y>c) //normal lighting condition , base motor rotates 

    digitalWrite(base1,HIGH);

    digitalWrite(base2,HIGH);

    delay(200);

    digitalWrite(base1,LOW);

    digitalWrite(base2,LOW);

    delay(100);

  }
// case3-if maximum intensity of light falls on th sensor 
  
  if (y<d)

  {
    digitalWrite(base1,LOW);
    digitalWrite(base2,LOW);
    
    while (x>b);

    {
      digitalWrite(top1,HIGH);
      digitalWrite(top1,LOW);
      delay(200);
      digitalWrite(top1,LOW);
      digitalWrite(top2,LOW);
      delay(200);

    }

  }

    }
