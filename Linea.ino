void linea(){
  //showColor();
  ii=analogRead(A0);                //Lee de los dos sensores
  dd=analogRead(A1);

  if(ii>=400){                      //Si el sensor de la izquierda detecta linea negra, gira hacia la izquierda
    verde=0;
    izquierda(250);
    adelante();
  }else if(dd>=400){                //Si el sensor de la derecha detecta linea negra, gira hacia la derecha
    verde=0;
    derecha(250);
    adelante();
  }
}

