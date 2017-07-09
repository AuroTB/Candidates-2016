void lab(){
  
  showColor();
  if(getDistance(1)>30){          //Si hay espacio para girar a la derecha, empieza la maniobra para girar a esa dirección
    digitalWrite(lm1,LOW);
    digitalWrite(rm1,LOW);
    digitalWrite(lm2,HIGH);
    digitalWrite(rm2,HIGH);
    delay(300);
    derechaLab(875);
    showColor();
    adelante(laberinto);
    delay(200);
    derechaLab(875);
    showColor();
    adelante(laberinto);
    delay(300);
  }
  if(getDistance(2)<10){          //Si no hay espacio para el frente ni para la derecha, se acomoda y gira hacia la izquierda
    adelante();
    showColor();
    delay(500);
    derecha(300);
    showColor();
    adelante();    
    digitalWrite(lm1,LOW);
    digitalWrite(rm1,LOW);
    digitalWrite(lm2,HIGH);
    digitalWrite(rm2,HIGH);
    delay(300);
    showColor();
    izquierda(giros);
  }else{
      adelante(laberinto);        //Si no pasa ninguno de los asos anteriores, solamente avanza hacia enfrente
      showColor();
  }

  if(negro>=5&&regreso==false){
    regreso=true;
    digitalWrite(lm1,LOW);
    digitalWrite(rm1,LOW);
    digitalWrite(lm2,HIGH);
    digitalWrite(rm2,HIGH);
    delay(300);
    izquierda(giros*2.5);
  }
}
    
