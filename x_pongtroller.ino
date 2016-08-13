  
  //---------------------------------------PONGTROLLER------------------------------------//
  
  void pongtroller(int wdt, CRGB kolor){
   
 
   leds[P_POS-1]=(0);
   leds[P_POS]=(0);
   leds[(P_POS+1)]=(0);

   P_POS=map(b2,0,1023,0,NUM_LEDS-2);
   leds[P_POS-1]=(kolor);
   leds[P_POS]=(kolor);
   leds[(P_POS+1)]=(kolor);
   FastLED.show();
   delay(10);
   
   
  }//end pong
  
