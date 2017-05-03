#define motor_steps_resolution 200

#define motor_en
#define motor_dir
#define motor_pulse


int prev_rpm=0;
int new_rpm=0;

void moveSteps(int numOfSteps,int rpm,int accel,int jerk,int dir)
{
  digitalWrite(motor_en,0);  // Enable the motor
  digitalWrite(motor_dir,dir);  // Set direction
  new_rpm=rpm;
  
  int x=(60*1000)/(rpm*motor_steps_resolution);
  
  
  while(numOfSteps--)
  {
    digitalWrite(motor_pulse,1);
    delay(1);  // for forming a pulse
    digitalWrite(motor_pulse,0);
    delay(x);
  }
  prev_rpm=rpm;
}


void init_stepperMotor(int motor_pulse,int motor_dir,int motor_en)
{
  pinMode(motor_pulse,OUTPUT);
  pinMode(motor_dir,OUTPUT);
  pinMode(motor_en,OUTPUT);

  digitalWrite(motor_en,1);
}

void setup()
{
  init_stepperMotor(motor_x_pulse.motor_x_dir,motor_x_en);
  delay(500);
}

void loop()
{
   moveSteps(100,50,10,10,1);
   delay(500);
   moveSteps(100,50,10,10,0);
   delay(500);
}
