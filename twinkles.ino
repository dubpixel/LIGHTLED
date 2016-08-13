//////---------------softtwinkles--------------/


void softtwinkles() {
//dim=80;
checkblank();
int DELAY=map(a2,0,1023,0,40);
  for( int i = 0; i < NUM_LEDS; i++) {
    if( !leds[i]) continue; // skip black pixels
    if( leds[i].r & 1) { // is red odd?
      leds[i] -= lightcolor; // darken if red is odd
    } else {
      leds[i] += lightcolor; // brighten if red is even
    }
  }
  
  // Randomly choose a pixel, and if it's black, 'bump' it up a little.
  // Since it will now have an EVEN red component, it will start getting
  // brighter over time.
  if( random8() < DENSITY) {
    int j = random16(NUM_LEDS);
    if( !leds[j] ) leds[j] = lightcolor;
    FastLED.show();
  FastLED.delay(DELAY);

  }
}
