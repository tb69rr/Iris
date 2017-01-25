

#include <avr/interrupt.h>
#include <stdint.h>

#define MODE_SEARCH 0
#define MODE_LEARN 1

volatile uint8_t found;
volatile uint8_t cap;
volatile uint16_t val;
uint8_t mode;

typedef struct {
  char *name;
  uint16_t low;
  uint16_t high;
  uint8_t thresh;
} pulse_t;

#define PHONE_COUNT (sizeof(phones) / sizeof(pulse_t))

pulse_t phones[] = {
  {"phone 3", 15970, 15980, 40},
  {"phone 13", 15615, 15630, 40},
  {"phone 7", 16050, 16070, 40},
};

uint8_t counts[PHONE_COUNT] = {0};

ISR(TIMER1_OVF_vect)
{
  digitalWrite(13, LOW);
  uint8_t i;
  for(i = 0; i < PHONE_COUNT; i++)
  {
    counts[i] = 0;
  }
  found = 0;
}

ISR(TIMER1_CAPT_vect)
{
  TCNT1 = 0;
  digitalWrite(13, HIGH);
  if(cap == 0)
  {
    cap = 1;
    val = ICR1;
  }
}

void setup() {
  // put your setup code here, to run once:

  // Setup the counter to count from 0 to 0xFFFF at CLK / 64 (at 16 MHz)
  // 1 count == 4 microseconds, max timer value is ~250 ms
  // Interrupt enabled on input capture event
  TCCR1A = 0x00;
  TCCR1B = 0x03;
  TIMSK1 = 0x21;
  
  Serial.begin(115200);

  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);

  pinMode(2, INPUT);
  digitalWrite(2, HIGH);

  mode = MODE_SEARCH;
  
  cap = 0;
  found = 0;
  sei();

  Serial.print("Number of Phones: ");
  Serial.println(PHONE_COUNT);
  
}

void loop() {
  while(cap == 0) {}

  if(digitalRead(2) == LOW)
  {
    if(mode == MODE_SEARCH)
    {
      Serial.println("Switching to learning mode");
      mode = MODE_LEARN;
    }
    else
    {
      Serial.println("Switching to search mode");
      mode = MODE_SEARCH;
    }
    delay(1000);


 }

  if(mode == MODE_SEARCH)
  {
    if(found == 0)
    {
      uint8_t i;
      for(i = 0; i < PHONE_COUNT; i++)
      {
        if(val > phones[i].low && phones[i].high > val)
        {
          counts[i] += 1;
          if(counts[i] > phones[i].thresh)
          {
            found = 1;
            Serial.print("Found: ");
            Serial.println(phones[i].name);
            break;
          }
        }
      }
    }
  }
  else
  {
    Serial.println(val);
  }
  
  cap = 0;
}
