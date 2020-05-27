//Erick Antonio Diaz Guzmán   3190-12-16419 
//Rony Misael Paz Juárez      3190-17-5011
//David Steve Monzón Reyes    3190-17-2298
//Jose Manuel Urbina Avila    3190-17-10153

//UMG
//ARQUITECTURA
//SEGUIDOR DE LINEAS

//CODIGO SEGUIR DE LINEAS    
int Velocidad;                                        // DECLARAMOS VARIABLE VELOCIDAD


boolean sensorDerecho;                                //DECLARMOS DE TIPO BOOLEANO EL SENSOR DERECHO
boolean sensorIzquierdo;                              //DECLARAMOS DE TIPO BOOLEANO EL SENSOR IZQUIERDO

int entrada_A=10;                                          
int in1=9;
int in2=8;
int in3=6;
int in4=7;
int entrada_B=3;

void setup()                                          //DECLARMOS Y DEFINIMOS LOS PINES A UTILIZAR
{
pinMode(10, OUTPUT);  
pinMode(9, OUTPUT);
pinMode(8, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(3, OUTPUT);
pinMode(11, INPUT);
pinMode(12, INPUT);
Velocidad = 50;                                     //DECLARMOS E INICIAMOS LA VARIABLE VELOCIDAD
}

void loop()
{

    sensorDerecho = digitalRead(11);             //INSTANCIAMOS LA VARIABLE SENSOR DERECHO
        
    sensorIzquierdo = digitalRead(12);            //INSTANCIAMOS LA VARIABLE SENSOR IZQUIERDO
    
  

 
 // SENTENCIAS IF PARA DETECCION DE LINEA
 
 if ((sensorDerecho && (!sensorIzquierdo))) {
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      analogWrite(entrada_B,(Velocidad));
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      analogWrite(entrada_A,(0));

    }
    if (((!sensorDerecho) && sensorIzquierdo)) {
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      analogWrite(entrada_A,(Velocidad));
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      analogWrite(entrada_B,(0));

    }
  if (((!sensorDerecho) && (!sensorIzquierdo))) {
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      analogWrite(entrada_B,(0));
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      analogWrite(entrada_A,(0));

    }
    if ((sensorDerecho && sensorIzquierdo)) {
      digitalWrite(in3,LOW);
      digitalWrite(in4,HIGH);
      analogWrite(entrada_B,(Velocidad));
      digitalWrite(in1,LOW);
      digitalWrite(in2,HIGH);
      analogWrite(entrada_A,(Velocidad));
    }
}
  
  
