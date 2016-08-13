//---------------------------------------PONGTROLLER FD------------------------------------// 
  void pongtrollerFD(int wdt, CRGB kolor){
  
  
  // leds[P_POS-1]=(0);
  // leds[P_POS]=(0);
 //  leds[(P_POS+1)]=(0);
   
   int poop=(NUM_LEDS/G_TAIL)/256;
    for (int j = 0; j <NUM_LEDS; j++) {
   //  leds[j]-=CRGB((255/(NUM_LEDS/G_TAIL)),(255/(NUM_LEDS/G_TAIL)),(255/(NUM_LEDS/G_TAIL)));
      leds[j].nscale8(256-(NUM_LEDS/G_TAIL));
      
      
             }

   P_POS=map(b2,0,1023,0,NUM_LEDS-2);
   leds[P_POS-1]=(kolor);
   leds[P_POS]=(kolor);
   leds[(P_POS+1)]=(kolor);
   FastLED.show();
   delay(10);
   
        
   
     }//end patt

