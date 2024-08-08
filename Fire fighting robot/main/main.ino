#include "PS2X_lib.h" // Include the correct library name
#include <Servo.h>

PS2X ps2x; // Create PS2 Controller Class
Servo myservo; // Create Servo object

// Definitions for servo pins and other settings
int error = 0;
byte type = 0;
byte vibrate = 0;

// Pin mapping according to schematics
int RightMotor = 9;
int LeftMotor = 10;
int Rdir = 8;
int Ldir = 12;

void Right(unsigned int Pwm) {
  digitalWrite(Rdir, LOW);
  digitalWrite(Ldir, HIGH);
  analogWrite(RightMotor, Pwm);
}

void Left(unsigned int Pwm) {
  digitalWrite(Rdir, HIGH);
  digitalWrite(Ldir, LOW);
  analogWrite(LeftMotor, Pwm);
}

void Forward(unsigned int Pwm) {
  digitalWrite(Rdir, LOW);
  digitalWrite(Ldir, LOW);
  analogWrite(RightMotor, Pwm);
  analogWrite(LeftMotor, Pwm);
}

void Backward(unsigned int Pwm) {
  digitalWrite(Rdir, HIGH);
  digitalWrite(Ldir, HIGH);
  analogWrite(RightMotor, Pwm);
  analogWrite(LeftMotor, Pwm);
}

void Stop() {
  analogWrite(RightMotor, 0);
  analogWrite(LeftMotor, 0);
}

void setup() {
  Serial.begin(115200);
  error = ps2x.config_gamepad(7, 5, 6, 4, false, false); // Setup pins and settings: GamePad, (clock, command, attention, data, Pressures?, Rumble?) check for error

  if (error == 0) {
    Serial.println("Found Controller, configured successful");
    Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder");
    Serial.println("Holding L1 or R1 will print out the Analog stick values.");
  } else if (error == 1) {
    Serial.println("No controller found, check wiring, see readme.txt to enable debug.");
  } else if (error == 2) {
    Serial.println("Controller found but not accepting commands. See readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips.");
  } else if (error == 3) {
    Serial.println("Controller refusing to enter Pressures mode, may not support it.");
  }

  type = ps2x.readType();
  switch (type) {
    case 0:
      Serial.println("Controller type: DualShock");
      break;
    case 1:
      Serial.println("Controller type: DualShock 2");
      break;
    case 2:
      Serial.println("Controller type: PS3");
      break;
    case 3:
      Serial.println("Controller type: PS4");
      break;
    default:
      Serial.println("Unknown Controller Type");
      break;
  }

  // Set pin modes for motors and servo
  pinMode(RightMotor, OUTPUT);
  pinMode(LeftMotor, OUTPUT);
  pinMode(Rdir, OUTPUT);
  pinMode(Ldir, OUTPUT);

  // Attach servo to pin A0 and set initial position
  myservo.attach(A0);
  myservo.write(0);
}

void loop() {
  ps2x.read_gamepad(false, vibrate); // Read controller and set large motor to spin at 'vibrate' speed
  
  if (ps2x.Button(PSB_L2)) {
    Serial.println("L2 pressed");
  }
  if (ps2x.Button(PSB_R2)) {
    Serial.println("R2 pressed");
  }
  if (ps2x.Button(PSB_PAD_UP)) {
    Serial.println("UP is being held");
    Forward(255);
  } else if (ps2x.Button(PSB_PAD_RIGHT)) {
    Serial.println("Right is being held");
    Right(255);
  } else if (ps2x.Button(PSB_PAD_LEFT)) {
    Serial.println("LEFT is being held");
    Left(255);
  } else if (ps2x.Button(PSB_PAD_DOWN)) {
    Serial.println("DOWN is being held");
    Backward(255);
  } else if (ps2x.Button(PSB_R1)) {
    Serial.println("R1 Pressed");
    myservo.write(60);
  } else if (ps2x.Button(PSB_R2)) {
    Serial.println("R2 Pressed");
    myservo.write(0);
  }
  
  delay(50); // Short delay for stability
}
