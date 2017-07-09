void adelante(){                            //Método para avanzar en la línea
analogWrite(lms,150);
analogWrite(rms,150);
digitalWrite(lm2,LOW);
digitalWrite(rm2,LOW);
digitalWrite(lm1,LOW);
digitalWrite(rm1,LOW);
digitalWrite(lm1,HIGH);
digitalWrite(rm1,HIGH);
}

void adelanteRecto(){                       //Método para ir adelante a toda velocidad en Zona C
analogWrite(lms,250);
analogWrite(rms,255);
digitalWrite(lm2,LOW);
digitalWrite(rm2,LOW);
digitalWrite(lm1,LOW);
digitalWrite(rm1,LOW);
digitalWrite(lm1,HIGH);
digitalWrite(rm1,HIGH);
}

void adelante(int a){                       //Método para ir hacia adelante en el laberinto
analogWrite(lms,200);
analogWrite(rms,a);
digitalWrite(lm2,LOW);
digitalWrite(rm2,LOW);
digitalWrite(lm1,LOW);
digitalWrite(rm1,LOW);
digitalWrite(lm1,HIGH);
digitalWrite(rm1,HIGH);
}

void izquierda(int i){                       //Método para girar hacia la izquierda
analogWrite(lms,200);
analogWrite(rms,200);
digitalWrite(lm1,LOW);
digitalWrite(rm1,LOW);
digitalWrite(lm2,LOW);
digitalWrite(rm2,LOW);
digitalWrite(lm2,HIGH);
digitalWrite(rm1,HIGH);
delay(i);
digitalWrite(lm2,LOW);
digitalWrite(rm1,LOW);
}

void derecha(int i){                         //Método para girar hacia la derecha
analogWrite(lms,200);
analogWrite(rms,200);
digitalWrite(lm1,LOW);
digitalWrite(rm1,LOW);
digitalWrite(lm2,LOW);
digitalWrite(rm2,LOW);
digitalWrite(lm1,HIGH);
digitalWrite(rm2,HIGH);
delay(i);
digitalWrite(lm1,LOW);
digitalWrite(rm2,LOW); 
}

void derechaLab(int i){                       //Método especial de giro hacia la derecha en laberinto               
analogWrite(lms,255);
analogWrite(rms,50);
digitalWrite(lm1,LOW);
digitalWrite(rm1,LOW);
digitalWrite(lm2,LOW);
digitalWrite(rm2,LOW);
digitalWrite(lm1,HIGH);
digitalWrite(rm2,HIGH);
delay(i);
}
