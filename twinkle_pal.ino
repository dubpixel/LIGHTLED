//CRGB color = ColorFromPalette( *colorBin[currPAL], hue, value, currentBlending)

             //--------------------------------------TWINKLY blue and white--------------------------------//


void tPAL() {

  if (timer >= G_SPD) {
    timer = 0;
   // currentBlending = NOBLEND;
   int i = random(a2);  // A random number. Higher number => fewer twinkles.
    int k = random(500);
    //CRGB kolor;

    //if(k)kolor=CRGB::Blue; else kolor int value = map(k, 0, 3, 0, 255);
    CRGB color = ColorFromPalette( *colorBin[currPAL], k, 255, currentBlending);

                 if (i < NUM_LEDS) leds[i] = color;  // Only the lowest probability twinkles will do. You could even randomize the hue/saturation. .--- CHSV(50, 100, 200)
    for (int j = 0; j < NUM_LEDS; j++) leds[j]--; // Go through the array and reduce each RGB value by 1 (won't reduce RGB value to -1, which is awesome).
    FastLED.show();

    //delay(G_SPD); // Higher number => slower twinkles.



  }//end timer
  G_SPD = map(b2, 0, 1023, 1, 40);
  timer++;
}
  // currentBlending = NOBLEND;

  void tPAL_NB(){
     tPAL();
      currentBlending = NOBLEND;
  }

void tPAL_B(){
   currentBlending = LINEARBLEND;
  tPAL();
}

