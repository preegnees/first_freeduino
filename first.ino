using namespace std;

uint8_t pin = 13;
double time_low = 10.0;
double time_high = 0.0;

void setup() {
  pinMode(pin, OUTPUT);
}

void loop() {
  sig(2, 20, 1); // 2 40 1
}

void sig(int a, int b, int c)
{
  for(int i = a; i < b; i++)
  {
    signaliz(i);
  }
  for(int i = b; i >= a; i--)
  {
    signaliz(i);
  }
  signaliz(c);
}

void signaliz(int speed)
{
  for (double i = 0; i <= time_low; i += 0.05*speed)
  {
      if (digitalRead(pin) == HIGH)
        {
          digitalWrite(pin, LOW);
          delay(time_low - i);
        } 
        else 
        {
          digitalWrite(pin, HIGH);
          delay(time_high + i);
        }  
  }

  for (double i = time_low; i >= 0; i -= 0.05*speed)
  {
      if (digitalRead(pin) == HIGH)
        {
          digitalWrite(pin, LOW);
          delay(time_low - i);
        } 
        else 
        {
          digitalWrite(pin, HIGH);
          delay(time_high + i);
        }  
  }
}



void migren()
{
  int time_s = 50;
  for (int i = 0; i < 10; i ++)
  {
    if (digitalRead(pin) == HIGH)
    {
      digitalWrite(pin, LOW);
      delay(time_s);
    } 
    else 
    {
      digitalWrite(pin, HIGH);
      delay(time_s/20);
    } 
  }
}
