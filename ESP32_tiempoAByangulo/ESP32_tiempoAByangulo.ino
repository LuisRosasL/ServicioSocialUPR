//ESP32- Deteccion de Longitud en resistencia electrica 

//Definiciones 
//Pin ADC para Voltaje
#define pot 36

//Variables Globales 
float valor,aux;//Lectura del voltaje en PIN 36
float ref;
float m,b;//Pendiente y ordenada al origen de la tira 
float y;//Longitud de arco 
int tiempoi,tiempof,tAB,conta,dt;
float ang;



void setup() {
  //Configuracion RS232
  Serial.begin(115200);//Se inicializa el monitor serial a una velocidad de 115200
  Serial.println("Longitud de arco y deteccion de canica");//Se imprime informacion del servo motor


}

void loop() {
  
  valor= float(analogRead(pot)*3.3/4095.0); //Lee el canal 0, analogico
  if(valor>=ref){
    if(conta==0){
      tiempoi=millis();
    }
    conta=1;
    if(valor>aux){
      aux=valor;
    }
    else{
      tiempof=millis();
      tAB=tiempof-tiempoi;
      y=aux*m+b;
      ang=(y*180.0)/(radio*3.1416)
      conta=0;
      Serial.printf(" tA_B= %d [ms] \n",tAB);
      Serial.printf(" ang_sal= %3.2f\n",ang);
      
    }
    delay(dt);
  }

}
