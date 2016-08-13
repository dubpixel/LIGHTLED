  //--------------------------------------SOLID COLOR--------------------------------//
void setcolor(CRGB kolor){
  
  
    for ( j=0; j< NUM_LEDS; j++){
      
       
      
  //     leds[j]= setHue(G_HUE);
      leds[j] = kolor;
      
    }//end for j
    

   // delay(10);

    
 
}//end

void solidWhite(){
  setcolor(CRGB::White);
  FastLED.show();
     //delay(10);
}

void solidInc(){
  setcolor(CRGB::FairyLight);
   FastLED.show();

}

void testColor(){

  CRGB color(8*25,5*25,1*25);
  setcolor(color);
   FastLED.show();
}



