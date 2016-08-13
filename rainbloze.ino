   //--------------------------------------rainbloze--------------------------------//

void ranebloze(){
static int dels;
  if(del_c<dels){
    
  del_c=0;
  
 static uint8_t shibs = 0;
   shibs+=32;
   
 fill_rainbow(leds, NUM_LEDS, shibs);

 FastLED.show();
}//endif delay
del_c++;
dels=map(a2,0,1023,1,40);

  delay(dels);
}
