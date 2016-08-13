//---------------------------------------PONGTROLLER FD RD------------------------------------// 
  void pongtrollerFDRD(int wdt, CRGB kolor){
    int O_POS=0;
    
    
     //  if P_POS != O_POS
   
    if((P_POS>(O_POS+WIG_BUF))||((P_POS<(O_POS-WIG_BUF)))){ 
   int hueee=random(256);
     leds[P_POS-1].setHue(hueee);
     leds[P_POS].setHue(hueee);
     leds[(P_POS+1)].setHue(hueee);
     leds[P_POS-1].nscale8(64);
     leds[(P_POS+1)].nscale8(64);
   


    
       }
         
    

 
    for (int j = 0; j <NUM_LEDS; j++) {
 
      leds[j].nscale8(256-(NUM_LEDS/G_TAIL));
       }
      O_POS=P_POS; 

   P_POS=map(b2,0,1023,0,NUM_LEDS-2);//map position
   
   O_POS=P_POS;
  
  
   
   
   FastLED.show();
   delay(10);
   
            
   
     }//end patt
   
 
