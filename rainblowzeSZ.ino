
     //--------------------------------------SIEZURE COLOR/fast rainbloze--------------------------------//

void raneblozeSZ(){
 
  
  
    
 int shibs_up = map(a2 ,0,1023,1,40);
  static uint8_t shibs = 0;
  shibs+=shibs_up;
   
 fill_rainbow(leds, NUM_LEDS, shibs);

 FastLED.show();
 

  
   // delay(dels);
}
  

