
  //--------------------------------------BREATHE--------------------------------//


  int del_c=0;
  int spd_c=0;
  
void breathe(){//int spd, CRGB kolor){

static int p;


  static int dels;

 if(del_c>210){

         
        if(p < 90) { //breath level index
          if(spd_c > dels){
             spd_c= 0;
              p++;
       
        
                   for ( j=0; j< NUM_LEDS; j++){
                      leds[j]=ColorFromPalette( *colorBin[currPAL], (fadelvl[p]/2),240);
                   // leds[j]= CRGB((fadelvl[i]),(fadelvl[i]),(fadelvl[i]));
                   }//end for j

             FastLED.show();
             }//end spd_c 
              spd_c++;
               dels=map(a2,0,1023,1,15);
        
           }//end for i //breathe level index
           
           
           if(p>=90){
            p=0;
            del_c=0;
           }//check to see if i need to start over.
  
 }//end del_c

     del_c++;
    
    
    


    FastLED.delay(1000 / FRAMES_PER_SECOND);

}
