int sequencia;// variavel que equivalerá a tecla pressionada
int x,y; // x e y do teclado matricial
int pinoled = 16; //Pino ligado ao led que será acionado na detecção de presença
int pinopir = 2; //Pino ligado ao sensor PIR
int acionamento; //Variavel para guardar valor do sensor

void setup()
{
  //Pinos ligados aos pinos 1, 2, 3 e 4 do teclado - Linhas
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  //Pinos ligados aos pinos 5, 6, 7 e 8 do teclado - Colunas
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  
  pinMode(14, OUTPUT);//gira
  pinMode(15, OUTPUT);//volta
  
  pinMode(32, OUTPUT);//led 1
  pinMode(34, OUTPUT);//led 2
  pinMode(36, OUTPUT);//led 3
  pinMode(38, OUTPUT);//led 4
  pinMode(40, OUTPUT);//led 5
  pinMode(42, OUTPUT);//led 6
  pinMode(44, OUTPUT);//led 7
  pinMode(46, OUTPUT);//led 8
  pinMode(48, OUTPUT);//led 9
  pinMode(50, OUTPUT);//ventilador1 = 10 #
  pinMode(52, OUTPUT);//ventilador2 = 11 *

  
  //  
  Serial.begin(9600);
  Serial.println("Aguardando acionamento das teclas...");
  Serial.println();

  pinMode(pinoled, OUTPUT); //Define pino ledpresenca como saida
  pinMode(pinopir, INPUT); //Define pino sensor presença como entrada
    
  
}
 
void loop()
{   
   //----- logica teclas
    for (int ti = 3; ti<7; ti++)
    {
    //Alterna o estado dos pinos das linhas
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(ti, HIGH);
    //Verifica se alguma tecla da coluna 1 foi pressionada
    if (digitalRead(8) == HIGH)
    {
      imprime_linha_coluna(ti-2, 1);
      while(digitalRead(8) == HIGH){}
    }
 
    //Verifica se alguma tecla da coluna 2 foi pressionada    
    if (digitalRead(9) == HIGH)
    {
      imprime_linha_coluna(ti-2, 2);
      while(digitalRead(9) == HIGH){};
    }
    
    //Verifica se alguma tecla da coluna 3 foi pressionada
    if (digitalRead(10) == HIGH)
    {
      imprime_linha_coluna(ti-2, 3);
      while(digitalRead(10) == HIGH){}
    }
    
    //Verifica se alguma tecla da coluna 4 foi pressionada
    if (digitalRead(11) == HIGH)
    {
      imprime_linha_coluna(ti-2, 4);
      while(digitalRead(11) == HIGH){} 
    }

   
    
   }

 
   delay(10);

    //----- fim da logica teclas

    


}
 
void imprime_linha_coluna(int x, int y)
{     
      acionamento = digitalRead(pinopir); //Le o valor do sensor PIR
       Serial.print("Linha : ");
       Serial.print(x);
       Serial.print(" x Coluna : ");
       Serial.print(y);
       delay(10);
       Serial.println();

      
     // o led quando detectada presença acionará independente de ser teclado ou não
     
     
     
     
     //----- fim da logica sensor
      
      if (acionamento == LOW) //Sem movimento, mantem led do sensor de presença desligado
      {
          digitalWrite(pinoled, LOW);//pino 16
          Serial.println("Parado");//Mostra no monitor serial que o sensor ta detectando parado
       }
       else //Caso seja detectado um movimento, aciona o "led do sensor"
       {
          digitalWrite(pinoled, HIGH);//pino 16
          //delay(9000);
          Serial.println("Movimento !!!");
        }    
      //----- fim da logica sensor





           

        //Tecla 0
        if(x==1&&y==2){// coordenadas x y correspondente a tecla 0
        
        sequencia=0;
        
        }

        //Tecla 1
        if(x==4&&y==1){// coordenadas x y correspondente a tecla 1
       
        sequencia=1;
        
        }

        //Tecla 2
        if(x==4&&y==2){// coordenadas x y correspondente a tecla 2

        sequencia=2;
        
        }

        //Tecla 3
        if(x==4&&y==3){// coordenadas x y correspondente a tecla 3

        sequencia=3;
        
        }

        //Tecla 4
        if(x==3&&y==1){// coordenadas x y correspondente a tecla 4 
        
        sequencia=4;
        
        }

        //Tecla 5
        if(x==3&&y==2){// coordenadas x y correspondente a tecla 5 

        sequencia=5;
        
        }

        //Tecla 6
        if(x==3&&y==3){// coordenadas x y correspondente a tecla 6 

        sequencia=6;
        
        }

        //Tecla 7
        if(x==2&&y==1){// coordenadas x y correspondente a tecla 7 
        
        sequencia=7;
        
        }

        //Tecla 8
        if(x==2&&y==2){// coordenadas x y correspondente a tecla 8 
        
        sequencia=8;
        
        }

        //Tecla 9
        if(x==2&&y==3){// coordenadas x y correspondente a tecla 9 
        
        sequencia=9;
        
        
        }

        //Tecla A
        if(x==4&&y==4){// coordenadas x y correspondente a tecla A 
        
        sequencia=10;//numero correspondente ao A do teclado matricial
        
        
        }

        //Tecla B
        if(x==3&&y==4){// coordenadas x y correspondente a tecla B
        
        sequencia=11;//numero correspondente ao B do teclado matricial
        
        
        }
        
        //Tecla C
        if(x==2&&y==4){// coordenadas x y correspondente a tecla C
        
        sequencia=12;//numero correspondente ao C do teclado matricial
        
        
        }

        //Tecla D
        if(x==1&&y==4){// coordenadas x y correspondente a tecla D
        
        sequencia=13;//numero correspondente ao D do teclado matricial
        
        
        }


        //Tecla *
        if(x==1&&y==1){// coordenadas x y correspondente a tecla *
        
        sequencia=14;//numero correspondente ao * do teclado matricial
        
        
        }
        
        //Tecla #
        if(x==1&&y==3){// coordenadas x y correspondente a tecla #
        
        sequencia=15;//numero correspondente ao # do teclado matricial
        
        
        } 

        
        Serial.print(sequencia);// mostra no monitor serial a tecla digitada

        
      if(sequencia==0){//Caso o botão 0 esteja pressionado
        

        
       // por enquanto esse botão não tem uma função estabelecida 
         

        
       }


       
      if(sequencia==1){//Caso o botão 1 esteja pressionado
        //led 1
       if(digitalRead(32)==LOW){//Comparação lógica se a porta 32 (porta correspondente ao sinal do botão 1) estava desativa
        digitalWrite(32, HIGH);  // Diz que o pino 32 do arduino está Ligado (Sinal Alto) caso estivesse desligado (Sinal Baixo). Logo LED da porta 32 ON
        
       }
       
       else{
        digitalWrite(32, LOW); // Diz que o pino 32 do arduino está Desligado (Sinal Baixo) caso estivesse ligado (Sinal Alto). Logo LED da porta 32 OFF
       } 
        
        }


       
      if(sequencia==2){//Caso o botão 2 esteja pressionado
        //led 2
       if(digitalRead(34)==LOW){//Comparação lógica se a porta 34 (porta correspondente ao sinal do botão 2) estava desativa
        digitalWrite(34, HIGH);  // Diz que o pino 34 do arduino está Ligado (Sinal Alto) caso estivesse desligado (Sinal Baixo). Logo LED da porta 34 ON
        
       }
       
       else{
        digitalWrite(34, LOW); // Diz que o pino 34 do arduino está Desligado (Sinal Baixo) caso estivesse ligado (Sinal Alto). Logo LED da porta 34 OFF
       } 
        
        }

       
      if(sequencia==3){//Caso o botão 3 esteja pressionado
        //led 3
       if(digitalRead(36)==LOW){//Comparação lógica se a porta 36 (porta correspondente ao sinal do botão 3) estava desativa
        digitalWrite(36, HIGH);  // Diz que o pino 36 do arduino está Ligado (Sinal Alto) caso estivesse desligado (Sinal Baixo). Logo LED da porta 36 ON
        
       }
        
       else{
        digitalWrite(36, LOW); 
       } 
        
        }


        
      if(sequencia==4){//Caso o botão 4 esteja pressionado
        //led 4
       if(digitalRead(38)==LOW){//Comparação lógica se a porta 38 (porta correspondente ao sinal do botão 4) estava desativa
        digitalWrite(38, HIGH);  // Diz que o pino 38 do arduino está Ligado (Sinal Alto) caso estivesse desligado (Sinal Baixo). Logo LED da porta 38 ON
        
       }
       
       else{
        digitalWrite(38, LOW); // Diz que o pino 38 do arduino está Desligado (Sinal Baixo) caso estivesse ligado (Sinal Alto). Logo LED da porta 38 OFF
       } 
        
        }



        
      if(sequencia==5){//Caso o botão 5 esteja pressionado
        //led 5
       if(digitalRead(40)==LOW){//Comparação lógica se a porta 40 (porta correspondente ao sinal do botão 5) estava desativa
        digitalWrite(40, HIGH);  // Diz que o pino 40 do arduino está Ligado (Sinal Alto) caso estivesse desligado (Sinal Baixo). Logo LED da porta 40 ON
        
       }
       else{
        digitalWrite(40, LOW); // Diz que o pino 40 do arduino está Desligado (Sinal Baixo) caso estivesse ligado (Sinal Alto). Logo LED da porta 40 OFF
       } 
        
        }


        
        
      if(sequencia==6){//Caso o botão 6 esteja pressionado
        //led 6
       if(digitalRead(42)==LOW){//Comparação lógica se a porta 42 (porta correspondente ao sinal do botão 6) estava desativa
        digitalWrite(42, HIGH);  // Diz que o pino 42 do arduino está Ligado (Sinal Alto) caso estivesse desligado (Sinal Baixo). Logo LED da porta 42 ON
        
       }
        
       else{
        digitalWrite(42, LOW); // Diz que o pino 42 do arduino está Desligado (Sinal Baixo) caso estivesse ligado (Sinal Alto). Logo LED da porta 42 OFF
       } 
        
        }

        
        
      if(sequencia==7){//Caso o botão 7 esteja pressionado
       //led 7 
       if(digitalRead(44)==LOW){//Comparação lógica se a porta 44 (porta correspondente ao sinal do botão 7) estava desativa
        digitalWrite(44, HIGH);// Diz que o pino 44 do arduino está Ligado (Sinal Alto) caso estivesse desligado (Sinal Baixo). Logo LED da porta 44 ON
        
       }
       
       else{
        digitalWrite(44, LOW); // Diz que o pino 44 do arduino está Desligado (Sinal Baixo) caso estivesse ligado (Sinal Alto). Logo LED da porta 44 OFF
       } 
        
        }

        
        
      if(sequencia==8){//Caso o botão 8 esteja pressionado
       //led 8 
       if(digitalRead(46)==LOW){//Comparação lógica se a porta 46 (porta correspondente ao sinal do botão 8) estava desativa
        digitalWrite(46, HIGH); // Diz que o pino 46 do arduino está Ligado (Sinal Alto) caso estivesse desligado (Sinal Baixo). Logo LED da porta 46 ON
        
       }
        
       else{
        digitalWrite(46, LOW); // Diz que o pino 46 do arduino está Desligado (Sinal Baixo) caso estivesse ligado (Sinal Alto). Logo LED da porta 46 OFF
       } 
        
        }
        
        
      if(sequencia==9){//Caso o botão 9 esteja pressionado
        //led 9
       if(digitalRead(48)==LOW){//Comparação lógica se a porta 48 (porta correspondente ao sinal do botão 9) estava desativa
        digitalWrite(48, HIGH); // Diz que o pino 48 do arduino está Ligado (Sinal Alto) caso estivesse desligado (Sinal Baixo). Logo LED da porta 48 ON
        
       }
        
       else{
        digitalWrite(48, LOW); // Diz que o pino 48 do arduino está Desligado (Sinal Baixo) caso estivesse ligado (Sinal Alto). Logo LED da porta 48 OFF
       } 
        
        }




       if(sequencia==10){//Caso o botão A esteja pressionado
        //A
        if(digitalRead(14)==LOW){//Comparação lógica se a porta 14 (porta correspondente ao sinal do botão A) estava desativada
          digitalWrite(14, HIGH);  // Diz que o pino 14 do arduino está Ligado (Sinal Alto) caso estivesse desligado (Sinal Baixo). Logo Portao gira da porta 14 ON
        
        }
       
        else{
          digitalWrite(14, LOW); // Diz que o pino 14 do arduino está Desligado (Sinal Baixo) caso estivesse ligado (Sinal Alto). Logo Portao gira-contrario da porta 14 OFF
        }
         
        }




       if(sequencia==11){//Caso o botão B esteja pressionado
        
        //A
        if(digitalRead(15)==LOW){//Comparação lógica se a porta 15 (porta correspondente ao sinal do botão B) estava desativada
          digitalWrite(15, HIGH);  // Diz que o pino 15 do arduino está Ligado (Sinal Alto) caso estivesse desligado (Sinal Baixo). Logo Portao gira-contrario da porta 15 ON
        
        }
       
        else{
          digitalWrite(15, LOW); // Diz que o pino 15 do arduino está Desligado (Sinal Baixo) caso estivesse ligado (Sinal Alto). LogoPortao gira-contrario da porta 15 OFF
        }
         
        }



       if(sequencia==12){//Caso o botão C esteja pressionado
        
       
       // por enquanto esse botão não tem uma função estabelecida 
         
       
        //C
        
        }


       if(sequencia==13){//Caso o botão D esteja pressionado
        
       
       // por enquanto esse botão não tem uma função estabelecida 
         
       
        //D
        
        }



       if(sequencia==14){//Caso o botão * esteja pressionado
       
        //* ventilador01

       if(digitalRead(52)==LOW){//Comparação lógica se a porta 44 (porta correspondente ao sinal do botão *) estava desativa
        digitalWrite(52, HIGH);  // Diz que o pino 52 do arduino está Ligado (Sinal Alto) caso estivesse desligado (Sinal Baixo). Logo COOLER da porta 52 ON
        
       }
        
       else{
        digitalWrite(52, LOW); // Diz que o pino 52 do arduino está Desligado (Sinal Baixo) caso estivesse ligado (Sinal Alto). Logo COOLER da porta 52 OFF
       } 
        
        
        }


       if(sequencia==15){//Caso o botão # esteja pressionado
       
        //# ventilador02

       if(digitalRead(50)==LOW){//Comparação lógica se a porta 44 (porta correspondente ao sinal do botão #) estava desativa
        digitalWrite(50, HIGH);  // Diz que o pino 50 do arduino está Ligado (Sinal Alto) caso estivesse desligado (Sinal Baixo). Logo COOLER da porta 50 ON
        
       }
        //
       else{
        digitalWrite(50, LOW); // Diz que o pino 50 do arduino está Desligado (Sinal Baixo) caso estivesse ligado (Sinal Alto). Logo COOLER da porta 50 OFF
       } 
      
        
        }
       
}
