//Listen for numbers on com port and adjust lef brightness

void setup() {

//Serial speed, very important
Serial.begin(115200);

//led on pin3
pinMode(3,OUTPUT);

Serial.print("Led on\n");
analogWrite(3, 120);
Serial.print("setup Done\n");
delay(1000);
analogWrite(3, 0);
Serial.print("Led off\n");
}

void loop() {
    if (Serial.available() > 0 ) {
        //Read the message
        String msg = Serial.readStringUntil(';');
        //flush the port and wait new data
        Serial.flush();

    //Convert  the message to interger and save it to variables
    uint8_t brightness = msg.toInt();
    //update Led brightness
    analogWrite(3, brightness);
    delayMicroseconds(50);
    }
}