// PWM charge controller code for 12v battery system 
// this system has over-voltage and under-voltage protection system
// futher features would be stated in the code when imp;emented using library and co ...

// declaration of variables
const int pwmPin = 9;
const int batteryPin = A0;

//declaration of battery parameters
const float maxVoltage = 12.6;  // in this case our battery is bilt in 3s configuration, for a 12v lithium system, maxVoltage is 12.6v
const float minVoltage = 10.0;  // the minimum voltage of the battery;
const float overChargeVoltage = 12.7; // battery-full/cut-off

//pwm valves/ parameters
const int pwmMax = 255;
const int pwmMin = 0;

bool chargingEnabled = true; // global variable to track charging state;

int calculatePWM(float voltage){
  if(voltage < minVoltage){
    return pwmMin;
  }
  else if (voltage >= maxVoltage) {
    return pwmMin;
  }
  else{
    return map (voltage * 100, minVoltage * 100, maxVoltage * 100, pwmMax, pwmMin);
  }
}

void setup(){
  pinMode (pwmPin, OUTPUT);
  Serial.begin(9600);  //note: this is because we are using serial monitor
}

void loop(){
  // we want to read battery voltage first
  //note that the sensor value is caliberated using voltage divider rule, using 5v as 12v, cause sending 12v directly would spoil the micro-contoller
  // note the sensorvalue is the output voltage of the voltage divider, whose max voltage is designed to give 5v irrespective of the battery source voltage, as long as battery source voltage is greater than 5v.
  float sensorValue = analogRead(batteryPin);  
  float batteryVoltage = (sensorValue / 1023.0) * 5.0;

  // display
  Serial.print("battery voltage: ");
  Serial.println(batteryVoltage);

  //check for batteryfull/overcharge
  if (batteryVoltage >= overChargeVoltage ){
    chargingEnabled = false;
    Serial.println("battery fully charged");
  }
  else if(batteryVoltage <= 12.4){
    chargingEnabled = true; // resumes chrging when voltage drops below 12.4v
  }

  // undervoltage protection
  if (batteryVoltage < minVoltage){
    chargingEnabled = false;
    Serial.print("battery voltage too low");
  }
  else if(batteryVoltage >= minVoltage){
    chargingEnabled = true;
  }
  // set pwm output based on charging state
  if(chargingEnabled){
    int pwmValue = calculatePWM(batteryVoltage);
    analogWrite(pwmPin, pwmValue);
  }
  else{
    analogWrite(pwmPin, pwmMin); // stop charging 
  }

  delay(100);
}