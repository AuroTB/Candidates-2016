int getDistance(int face){             //Método para obtener la distancia entre el robot y la pared;
  duration=0.0;
  cm=0;
  switch(face){                        
    case 1:                            //Si recibe un 1: obtiene mediciones del ultrasónico de la derecha      
      digitalWrite(trig1, LOW); 
      delayMicroseconds(2);
      digitalWrite(trig1, HIGH); 
      delayMicroseconds(10); 
      digitalWrite(trig1, LOW);
      duration = pulseIn(echo1, HIGH);
      cm = duration/58;
      digitalWrite(trig1, LOW);
      delay(100);
      break;
    
    case 2:                             //Si recibe un 2: obtiene mediciones del ultrasónico frontal
      digitalWrite(trig2, LOW); 
      delayMicroseconds(2);
      digitalWrite(trig2, HIGH); 
      delayMicroseconds(10); 
      digitalWrite(trig2, LOW);
      duration = pulseIn(echo2, HIGH); 
      cm = duration/58;
      digitalWrite(trig2, LOW);
      delay(100);
      break;

    case 3:                             //Si recibe un 3: obtiene mediciones del ultrasónico izquierdo
      digitalWrite(trig3, LOW); 
      delayMicroseconds(2);
      digitalWrite(trig3, HIGH); 
      delayMicroseconds(10); 
      digitalWrite(trig3, LOW);
      duration = pulseIn(echo3, HIGH); 
      cm = duration/58;
      digitalWrite(trig3, LOW);
      delay(100);
      break;
  }
  if(cm>120||cm<0){
    return 0;
  }else{
  return cm;
  }
}
void showColor()
{ 
  if(getColor()==1){
    digitalWrite(rgbA,LOW);
    digitalWrite(rgbR,LOW);
    digitalWrite(rgbG,LOW);
    Serial.println("Blanco");
  }else if(getColor()==0){
    digitalWrite(rgbA,HIGH);
    digitalWrite(rgbR,HIGH);
    digitalWrite(rgbG,HIGH);
    Serial.println("Negro");
  }else if(getColor()==2){
    digitalWrite(rgbA,LOW);
    digitalWrite(rgbR,HIGH);
    digitalWrite(rgbG,LOW);
    Serial.println("Rojo");
  }else if(getColor()==3){
    digitalWrite(rgbA,HIGH);
    digitalWrite(rgbR,LOW);
    digitalWrite(rgbG,LOW);
    Serial.println("Azul");
  }else if(getColor()==4&&verde<30){
    digitalWrite(rgbA,LOW);
    digitalWrite(rgbR,LOW);
    digitalWrite(rgbG,HIGH);
    Serial.println("Verde");
  }
}

int getColor(){
  readColor();

  if(red<45&&blue<45&&green<45){                                                //Blanco
    return 1;
    //negro=0;
   }else if( (red>193 && red<222) && (green>119 && green<149) && (blue>55 && blue<92) ){  //Azul
    return 3;
    //negro=0;
  }else if( (red>52 && red<82) && (green>184 && green<214) && (blue>122 && blue<152)){   //Rojo
    return 2;
    //negro=0;
  }else if( (red>70 && red<98) && (green>49 && green<79) && (blue>72 && blue<102) ){         //Verde
    return 4;
    //negro=0;
  }else if(red>150&&blue>150&&green>150){
     negro++;
    return 0;
  }
}

void readColor(){   
  digitalWrite(S2,LOW);                           //Red
  digitalWrite(S3,LOW);
  red = pulseIn(sensorOut, LOW);
  //red = map(red,18,37,0,255);
  Serial.print(red);
  Serial.print("    ");
                                                  //Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  green = pulseIn(sensorOut, LOW);
  //green = map(green,22,35,0,255);
  Serial.print(green);
  Serial.print("    ");
  
  digitalWrite(S2,LOW);                           //Blue
  digitalWrite(S3,HIGH);
  blue = pulseIn(sensorOut, LOW);
  //blue = map(blue,18,45,0,255);
  Serial.print(blue);
  Serial.println("    ");
}
