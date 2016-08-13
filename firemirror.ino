//-----FIRE KODE--------------//



// Fire2012 by Mark Kriegsman, July 2012  
  //modified for 2801 by JBF 
  
// as part of "Five Elements" shown here: http://youtu.be/knWiGsmgycY
//// 
// This basic one-ensional 'fire' simulation works roughly as follows:
// There's a underlying array of 'heat' cells, that model the g_Ainerature
// at each point along the line.  Every cycle through the simulation, 
// four steps are performed:
//  1) All cells cool down a little bit, losing heat to the air
//  2) The heat from each cell drifts 'up' and diffuses a little
//  3) Sometimes randomly new 'sparks' of heat are added at the bottom
//  4) The heat from each cell is rendered as a color into the leds array
//     The heat-to-color mapping uses a black-body radiation approximation.
//
// g_Ainerature is in arbitrary units from 0 (cold black) to 255 (white hot).
//
// This simulation scales it self a bit depending on NUM_LEDS; it should look
// "OK" on anywhere from 20 to 100 LEDs without too much tweaking. 
//
// I recommend running this simulation at anywhere from 30-100 frames per second,
// meaning an interframe delay of about 10-35 milliseconds.
//
// Looks best on a high-density LED setup (60+ pixels/meter).
//
//
// There are two main parameters you can play with to control the look and
// feel of your fire: COOLING (used in step 1 above), and SPARKING (used
// in step 3 above).
//
// COOLING: How much does the air cool as it rises?
// Less cooling = taller flames.  More cooling = shorter flames.
// Default 50, suggested range 20-100 
#define COOLING  55

// SPARKING: What chance (out of 255) is there that a new spark will be lit?
// Higher chance = more roaring fire.  Lower chance = more flickery fire.
// Default 120, suggested range 50-200.

void FireSplitFan(){
 checkblank();
  Fire2012h(0,(NUM_LEDS/2), true, true, false);
  //Fire2012(((NUM_LEDS/2)),((NUM_LEDS/2)),false,false,false);
  
}

void Fire2012_n(){
  Fire2012h(0,NUM_LEDS, false,false, false);
}

void Fire2012h(uint16_t Lstart,  int numled, boolean inverted, boolean doubled, boolean mFlip)
{
 int SPARKING=0;
  SPARKING=map(a2,0,1023,0,500);
  random16_add_entropy( random());
// Array of temperature readings at each simulation cell
  
  
  // Step 1.  Cool down every cell a little
    for( int i = Lstart; i < (numled+Lstart); i++) {
      heat[i] = qsub8( heat[i], random8(0, (((COOLING * 10) / numled) + 2)));
      //Serial.print("heati:");
      //Serial.println(i);
    }
  
    // Step 2.  Heat from each cell drifts 'up' and diffuses a little
    for( int k= ((numled+Lstart)); k >= (Lstart+2); k--) {
      heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
    //   Serial.print("heati:");
      //Serial.println(k);
    }
    
    // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
    if( random8() < SPARKING ) {
      int y = random8(Lstart,(Lstart+6));
      heat[y] = qadd8( heat[y], random8(160,255) );
    }

    // Step 4.  Map from heat cells to LED colors
    for( int j = Lstart; j < (numled+Lstart); j++) {
       int t;
       
     if((!inverted)){t=j;} //regular
     if((inverted)  && (!doubled)){ t=SLDO(j); ;} //invert
    
          //  leds[t] = HeatColor( heat[j]);
             
               //new palette method
               byte colorindex = scale8( heat[j], 240);
             leds[t] = ColorFromPalette( *colorBin[currPAL], colorindex);
        
     if ((!inverted)&&(doubled)){ //if we're doubling up 


          //this just basically shifts by numled
          //   leds[((j+numled)%NUM_LEDS)]=HeatColor( heat[j]); 

         //this just basically shifts by numled, but with new palette shit
         
         byte colorindex = scale8( heat[j], 240);
         leds[((j+numled)%NUM_LEDS)] = ColorFromPalette( *colorBin[currPAL], colorindex);
          
          }
          
        if(inverted&&doubled && !mFlip){ //flop and double (mirror)

             byte colorindex = scale8( heat[j], 240);
             
              leds[j] = ColorFromPalette( *colorBin[currPAL], colorindex);
            
            
           
            
          
            
            ;
             
             leds[SLDO(j)] = ColorFromPalette( *colorBin[currPAL], colorindex);
            
          
        }
        
        
        
          if (inverted&&doubled && mFlip){
            
                byte colorindex = scale8( heat[j], 240);
                 //do one thats offset
                
                
                //leds[(j+numled)] = HeatColor( heat[j]);//(xf(j+numled)%NUM_LEDS)
                  
                  leds[(j+numled)] = ColorFromPalette( *colorBin[currPAL], colorindex);//(xf(j+numled)%NUM_LEDS)

                
                
                
                //this is the wraparound for mirrored function, but translated back towards start
                leds[(SLDO(j)-numled)] = ColorFromPalette( *colorBin[currPAL], colorindex);
            }
        
      
    }
    
    FastLED.show(); // display this frame 
    FastLED.delay((1000 / FRAMES_PER_SECOND));
    
}

