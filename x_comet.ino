//---------------------------------------COMET------------------------------------//
void comet(int HEADwait, CRGB kolor, boolean isCLEN, boolean isCHUE , boolean rev){
  //set static speed for now
  G_SPD=120;
  
  if (timer>G_SPD){//this takes place of delay
  timer=0  ;
  //settng colors or length from pot
          //G_HUE=kolor;
        //updae hue/lengths
          if(isCHUE){ G_HUE = map(b2, 0, 1023, 0, 255);}
          if(isCLEN){ G_TAIL = map(b2, 0, 1023, 0, 12);}
          if((!isCHUE)&&(!isCLEN)){G_HUE=kolor;G_TAIL=7;}
          
          
       
    //if the head is running, set the current led to color, and increment
    
  if (HEADrunning==true){
    
  
       // if  leds[currLed] = kolor;
        leds[currLed].setHue(G_HUE);
        
        //if fwd/back inc/dec
        if (!rev) currLed++;
        if (rev) currLed--;
          
       
               }//end if head
         
       
        //if forward check for out of bounds
        if ((currLed>NUM_LEDS-1)&& (!rev)){
          currLed=0;
          HEADrunning=false; 
           
           }//endif
                       
                       
                       
         //if reverse check for out of bounds
         if ((currLed<0)&& (rev)){
          currLed=NUM_LEDS-1;
          HEADrunning=false;  
       
           }//endif
         
         
        
      if(HEADrunning!=true){
              HEADcount=HEADcount+1;
            }
            
       
      if (HEADcount>HEADwait){
          HEADrunning=true;
          HEADcount=0;
        }

      //show those LEDS
       FastLED.show();
      // Wait a little bit
    //  delay(50);
  //  FastLED.delay(1000 / FRAMES_PER_SECOND);

   //  fade everyone regardless
      for (int j = 0; j <NUM_LEDS; j++) {
      leds[j]-=CRGB((255/(NUM_LEDS/G_TAIL)),(255/(NUM_LEDS/G_TAIL)),(255/(NUM_LEDS/G_TAIL)));
      
      
             }
   FastLED.delay(1000 / FRAMES_PER_SECOND);
   
}//end timer
 timer++;
 
}







