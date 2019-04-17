
int waveLed = D6;
int patLed = D4;


void setup() {
   
    pinMode(waveLed,OUTPUT); 
    pinMode(patLed,OUTPUT);
    // Here we are going to subscribe to your buddy's event using Particle.subscribe
    Particle.subscribe("Deakin_RIOT_SIT210_Photon_Buddy", myHandler);
    // Subscribe will listen for the event Deakin_RIOT_SIT210_Photon_Buddy and, when it finds it, will run the function myHandler()
    // myHandler() is declared later in this app.
}


void loop() 
{
   
}


// Now for the myHandler function, which is called when the cloud tells us that our buddy's event is published.
void myHandler(const char *event, const char *data)
{
    /* Particle.subscribe handlers are void functions, which means they don't return anything.
      They take two variables-- the name of your event, and any data that goes along with your event.
      In this case, the event will be "buddy_unique_event_name" and the data will be "wave" or "pat"

      Since the input here is a char, we can't do
         data=="intact"
        or
         data=="broken"

      chars just don't play that way. Instead we're going to strcmp(), which compares two chars.
      If they are the same, strcmp will return 0.*/
    
    //This event sends two signals, wave and pat.
    //When wave is received, the red LED at D6 will flash 3 times

    if (strcmp(data,"wave")==0)
    {
        digitalWrite(waveLed,HIGH);
        delay(1000);
        digitalWrite(waveLed,LOW);
        delay(1000);
        digitalWrite(waveLed,HIGH);
        delay(1000);
        digitalWrite(waveLed,LOW);
        delay(1000);
        digitalWrite(waveLed,HIGH);
        delay(1000);
        digitalWrite(waveLed,LOW);
    }
    
    //When pat is received, the blue LED at D4 will flash 5 times
    if (strcmp(data,"pat")==0)
    {
        digitalWrite(patLed,HIGH);
        delay(100);
        digitalWrite(patLed,LOW);
        delay(100);
        digitalWrite(patLed,HIGH);
        delay(100);
        digitalWrite(patLed,LOW);
        delay(100);
        digitalWrite(patLed,HIGH);
        delay(100);
        digitalWrite(patLed,LOW);
        delay(100);
        digitalWrite(patLed,HIGH);
        delay(100);
        digitalWrite(patLed,LOW);
        delay(100);
        digitalWrite(patLed,HIGH);
        delay(100);
        digitalWrite(patLed,LOW);
    }

}