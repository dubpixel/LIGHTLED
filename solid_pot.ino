//--------------------------------------SOLID COLOR w/pot--------------------------------//

  
  void setcolorS(){
  

   G_HUE = map(a2, 0, 1023, 0, 255);
    for ( j=0; j< NUM_LEDS; j++){
      
       
      
       leds[j].setHue(G_HUE);
    //  leds[j]= CRGB
      
    }//end for j
    
    FastLED.show();
    delay(10);

    

}//end
