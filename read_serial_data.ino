//Listen for numbers on com port and adjust lef brightness

void setup() {

//Serial speed, very important
Serial.begin(115200);

//led on pin3
pinMode(3,Output);
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
    analogWrite(33, brightness);
    }
}