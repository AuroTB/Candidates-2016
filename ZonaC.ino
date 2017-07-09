void ZonaC(){  
    adelanteRecto();
    while(getDistance(3)<30){
    }
    delay(350);

    while(2<3){
      izquierda(giros-500);
      digitalWrite(lm1,LOW);
      digitalWrite(rm1,LOW);
      digitalWrite(lm2,HIGH);
      digitalWrite(rm2,HIGH);
      delay(300);
      adelanteRecto();
      while(getDistance(2)>7){
      //avanza
      }
      digitalWrite(lm1,LOW);
      digitalWrite(rm1,LOW);
      digitalWrite(lm2,HIGH);
      digitalWrite(rm2,HIGH);
      delay(300);
    }
}
