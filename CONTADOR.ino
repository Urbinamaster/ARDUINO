
//Erick Antonio Diaz Guzmán   3190-12-16419 
//Rony Misael Paz Juárez      3190-17-5011
//David Steve Monzón Reyes    3190-17-2298
//Jose Manuel Urbina Avila    3190-17-10153

//UMG
//ARQUITECTURA



// INCLUIMOS LAS LIBRERIAS A UTILIZAR PUED

#include <LiquidCrystal.h>
#include <Wire.h>                                                 //INCLUIMOS LIBRERIA DEL DISPLAY
#include "Adafruit_TCS34725.h"                                    //INCLUIMOS LIBRERIA DEL SENSOR DE COLORES

 
//DECLARAMOS VARIABLES DEL CONTADOR DE VUELTAS
int numero=0;
int auxnumero=0;
int sensorPinLDR = A0;
int valorLDR = 0;

//DECLARAMOS Y DEFINIMOS LOS PINES DEL LED 

#define redpin 8                                                  //EN EL PIN 8 ESTARA EL POSITIVO DEL LED ROJO
#define greenpin 9                                                //EN EL PIN 9 ESTARA EL POSITIVO DEL LED VERDE
#define bluepin 10                                                //EN EL PIN 10 ESTAR EL POSITIVO DEL LED AZUL
 
 
 
#define commonAnode false                                         // SE ESTABLE EN FALSO SI USAMOS UN LED DE CATADO COMUN                   
 
 
 
byte gammatable[256];                                             //LOS COLORES RECONOCIDOS POR EL OJO EN RGB (LOS VALORES DE ROJO VERDE AZUL)
 
                                                                  
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);      //INSTANCIAMOS EL SENSOR PARA UTILIZARLO DESPUES




LiquidCrystal lcd(12, 11, 5, 4, 3, 2);//DECLARAMOS LOS PINES A UTILIZAR EN LA LCD (RS,E,D4,D5,D6,D7)

void setup() {
  
  lcd.begin(16, 2);//INICIAMOS LA PANTALLA Y LAS FILAS 16 ESPACIOS EN DOS FILAS 
  
  lcd.setCursor(5, 0);//LUGAR DONDE COMIENZA LA ESCRITURA EN PANTALLA
  lcd.print("UMG");//ESCRIBIMOS
  delay (2000);//TIEMPO EN PANTALLA 2 SEGUNDOS
  lcd.clear();//LIMPIAMOS LA PANTALLA
  lcd.setCursor(0, 0);
  lcd.print("ARQUITECTURA ");
  delay (2000);
  lcd.setCursor(3, 1);
  lcd.print("PROCESADORES ");
  delay (2000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" INGENIERIA");
  delay (2000);
  lcd.setCursor(3, 1);
  lcd.print("SEGUI LINEAS");
  delay (3000);
  lcd.clear();


  //CODIGO COLOR DECLARAMOS LA COMPARATIVA
  if (tcs.begin()) {                                              //INICIAMOS EL IF PARA DETECTAR PROBLEMAS CON EL SENSOR DE COLOR
    lcd.setCursor(0, 1);
   lcd.print("INGENIERIA"); 
                              
  } else {                                                        //DE LO CONTRARIO QUE MUESTRE UN ERROR DE SENSOR
    lcd.setCursor(0, 1);
   lcd.print("ERROR");
  ;
    while (1); // halt!
  }
 
  pinMode(redpin, OUTPUT);                                         //ASIGNAMOS COMO SALIDA EL PIN PARA COLOR ROJO
  pinMode(greenpin, OUTPUT);                                       //ASIGNAMOS COMO SALIDA EL PIN PARA COLOR VERDE
  pinMode(bluepin, OUTPUT);                                        //ASIGNAMOS COMO SALIDA EL PIN PARA COLOR AZUL
 
                                                                   // TABLA DE GAMA DE COLORES 
                                                                   // CONVERTIMOS COLORES RGB A COLORES QUE DETECTA EL OJO HUMANO
  for (int i=0; i<256; i++) {
    float x = i;
    x /= 255;
    x = pow(x, 2.5);
    x *= 255;
     
    if (commonAnode) {
      gammatable[i] = 255 - x;
    } else {
      gammatable[i] = x;      
    }                                                               
  }
}
void loop() {   
   lcd.setCursor(0, 0);                                      //LUGAR DONDE ESCRIBIREMOS
   lcd.print("UMG");                                         //MENSAJE
 

  //CODIGO CONTADOR
  valorLDR = analogRead(sensorPinLDR);                          // LEEMOS EL VALOR DE PIN Y LO GUARDAMOS EN LA VARIABLE sensorPinLDR
 
  lcd.setCursor(10, 0);                                          //LUGAR DONDE ESCRIBIREMOS
  lcd.print("CONTEO");                                           //MENSAJE
  lcd.setCursor(13, 1);                                          //LUGAR DONDE ESCRIBIREMOS
  lcd.print(numero);                                             //MENSAJE CON VARIABLE NUMERO DE VUELTAS
  
  auxnumero=0;                                                   //VARIABLE AUXILIAR A CERO PARA PODER COMENZAR CON EL CONTEO
  
  while(valorLDR<600){                                           //ENTRAMOS AL BUCLE MENOR A 600 VUELTAS



    lcd.setCursor(0, 0);                                          //LUGAR DE ESCRITURA
   lcd.print("UMG");                                              //MENSAJE
  

   

//CODIGO SENSOR DE COLORES
uint16_t clear, red, green, blue;                                 //DECLARAMOS LAS VARIABLES PARA LOS COLORES
 
  tcs.setInterrupt(false);                                          //ENCENDEMOS EL LED EN COLOR NEUTRO
 
  delay(60);                                                        // TOMA 50 MILI SEGUNDOS PARA LEER EL COLOR
 
  tcs.getRawData(&red, &green, &blue, &clear);                      //LECTURA DEL SENSOR
  
  tcs.setInterrupt(true);                                           // APAGAMOS LED
                                                                    // CODIGO HEXADECIMAL PARA LA VISUALIZACION
  uint32_t sum = clear;
  float r, g, b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  r *= 256; g *= 256; b *= 256;
 
  analogWrite(redpin, gammatable[(int)r]);                          //PRENDEMOS EL LED ROJO DESPUES DE AVER DETACTADO EL COLOR

  analogWrite(greenpin, gammatable[(int)g]);                        //PRENDEMOS EL LED VERDE DESPUES DE AVER DETECTADO EL COLOR
 
  analogWrite(bluepin, gammatable[(int)b]);                        //PRENDEMOS EL LED AZUL DESPUES DE AVER DETECTADO EL COLOR

  

    valorLDR = analogRead(sensorPinLDR);// Leemos el valor de la LDR y lo guardamos en valorLDR
    if(auxnumero==0){// Entramos en el if si auxnumero es 0. Esto solo ocurre la primera vez que recorremos el while.
    numero++;//Sumamos 1 a la variable numero
    auxnumero=1;//hacemos auxnumero 1, para que solo sume una vez 1 a la variable numero cuando estamos dando vueltas dentro del bucle.
    } 
  }
  } 

       
  
  
