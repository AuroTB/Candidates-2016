//Motores
const int lm1=8,  rm1=12;             //Hacia enfrente (l= motor izquierdo y r= motor derecho)
const int lm2=11, rm2=13;             //Hacia atrás
const int lms=9,  rms=10;             //Voltaje 

long duration;
int cm, i;                            //cm: centímetros de distancia; i=variable para ciclos;
int giros=1300;                       //"Giros" representa los milisegundos que se tarda en girar 90°
int laberinto = 190;
int reverse=0;

//Sensores de luz
int ii=0;                             //Sensor izquierdo
int dd=0;                             //Sensor derecho

//Sensor de color
#define S0 47
#define S1 45
#define S2 51
#define S3 53
#define sensorOut A2
int red=0, green=0, blue =0;

//RGB
int rgbA=23, rgbR=24, rgbG=22;

//Ultrasonicos
const int trig1=41;                   //supersónico derecha
const int trig2=39;                   //supersónico frente
const int trig3=37;                   //supersónico izquierda
int echo1=A3;
int echo2=A4;
int echo3=A5;

int verde=0;                          //Variable para saber si ya está en la entrada de la zona B
int negro=0;
bool regreso=false;                     //Variable para saber si ya esta en la zona C

void setup() {
  pinMode(lm1,OUTPUT);              //Motores
  pinMode(lm2,OUTPUT);
  pinMode(lms,OUTPUT);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(rms,OUTPUT);

  //configuran la frecuencia        //Sensor de color
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  
  //seleccionan el color
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  //salida
  pinMode(sensorOut, INPUT);
  
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);

  pinMode(rgbA,OUTPUT);              //RGB
  pinMode(rgbR,OUTPUT);
  pinMode(rgbG,OUTPUT);

  pinMode(trig1,OUTPUT);             //Ultrasónicos
  pinMode(A3,INPUT);
  pinMode(trig2,OUTPUT);
  pinMode(A4,INPUT);
  pinMode(trig3,OUTPUT);
  pinMode(A5,INPUT);

  Serial.begin(9600);
  adelante();
}

void loop(){
  while(getColor()==0||negro>=5){
  ZonaC();
  }
  
  while(verde<25){
    linea();
    if(getColor()==4){
      verde++;
    }
    Serial.println("Esta en linea");
    Serial.print(verde);
  }
  if(getDistance(2)<7){
    digitalWrite(lm1,LOW);
    digitalWrite(rm1,LOW);
    digitalWrite(lm2,HIGH);
    digitalWrite(rm2,HIGH);
    delay(700);
    derecha(giros);
    adelante(200);
    delay(700);
  }
  
  while(verde>=25&&negro<5){
    lab();
    Serial.println("Esta en lab");
    Serial.print("\t\t");
    Serial.println(negro);
  }
  
   while(verde>=25){
    lab();
    Serial.println("Esta en lab");
    Serial.print("\t\t");
    Serial.println(negro);
  }
  
}
