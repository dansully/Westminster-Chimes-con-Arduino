#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978


int melody[] = {
NOTE_E4, NOTE_GS4, NOTE_FS4, NOTE_B3, 0,
NOTE_E4, NOTE_FS4, NOTE_GS4, NOTE_E4, 0,
NOTE_GS4, NOTE_E4, NOTE_FS4, NOTE_B3, 0,
NOTE_B3, NOTE_FS4, NOTE_GS4, NOTE_E4 };

int melody1[] = {
NOTE_GS4, NOTE_FS4, NOTE_E4, NOTE_B3};

int melody2[] = {
NOTE_E4, NOTE_GS4, NOTE_FS4, NOTE_B3, 0,
NOTE_E4, NOTE_FS4, NOTE_GS4, NOTE_E4};

int melody3[] = {
NOTE_GS4, NOTE_E4, NOTE_FS4, NOTE_B3, 0,
NOTE_B3, NOTE_FS4, NOTE_GS4, NOTE_E4, 0,
NOTE_GS4, NOTE_FS4, NOTE_E4, NOTE_B3};



// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
2, 2, 2, 1, 2,
2, 2, 2, 1, 2,
2, 2, 2, 1, 2,
2, 2, 2, 1 };

int noteDurations1[] = {
2, 2, 2, 1 };

int noteDurations2[] = {
2, 2, 2, 1, 2,
2, 2, 2, 1};

int noteDurations3[] = {
2, 2, 2, 1, 2,
2, 2, 2, 1, 2,
2, 2, 2, 1 };




int buzzer=2;
int i=0;
int hours=0;
int mins=0;
int secs=0;
int msecs=0;
int led=4;
bool suonato=true;
int addhours=15;
int addmins=29;
int addsecs=30;
int bottone=5;
int stato;
int secssaved;
int day=2;
int month=9;
int year=2017;
int change;
int mostra;
int mostraver;
int muto=6;
bool mutato=false;
int variabile;
bool fatto=false;



#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
pinMode(buzzer, OUTPUT);
pinMode(led, OUTPUT);
pinMode(3, OUTPUT);
pinMode(bottone, INPUT);
lcd.begin(16, 2);
if(addmins==15||addmins==30||addmins==45||addmins==0){
  suonato=false;
  }
  
}

void loop() {

  
hours=hours+addhours;
addhours=0;
mins=mins+addmins;
addmins=0;
secs=(millis()/1000)-msecs+addsecs;
variabile=digitalRead(muto);
if(variabile==HIGH){
  if(mutato==false){
  mutato=true;
  delay(1000);}
  else{
  mutato=false;
  delay(1000);}
}

  if(mutato==true){
    if(fatto==false){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Orologio in");
    lcd.setCursor(0,1);
    lcd.print("spegnimento...");
    delay(2500);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Ora disponibile");
    lcd.setCursor(0,1);
    lcd.print("solo mentre");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("si suonano anche");
    lcd.setCursor(0,1);
    lcd.print("i quarti");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Orologio");
    lcd.setCursor(0,1);
    lcd.print("disabilitato");
    fatto=true;
    }
  }
  else{

if(secssaved!=secs){
  secssaved=secs;
  change=change+1;
  mostra=mostra+1;
  mostraver=mostraver+1;
  if(change < 7){
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Ora: ");
lcd.setCursor(6, 0);
lcd.print(hours);
lcd.setCursor(8, 0);
lcd.print(":");
lcd.setCursor(9, 0);
lcd.print(mins);
lcd.setCursor(11, 0);
lcd.print(":");
lcd.setCursor(12, 0);
lcd.print(secs);
lcd.setCursor(0, 1);
lcd.print("Prox:");
lcd.setCursor(11, 1);
lcd.print(":00");
  }
  else{
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("Data: ");
lcd.setCursor(6, 0);
lcd.print(day);
lcd.setCursor(8, 0);
lcd.print("/");
lcd.setCursor(9, 0);
lcd.print(month);
lcd.setCursor(11, 0);
lcd.print("/");
lcd.setCursor(12, 0);
lcd.print(year);
if(change>10){
change=0;
}
lcd.setCursor(0, 1);
lcd.print("Prox:");
lcd.setCursor(11, 1);
lcd.print(":00");
    }

if (mostraver>10){
  lcd.setCursor(0, 1);
  lcd.print("Versione:        ");
  delay(1500);
  lcd.setCursor(0, 1);
  lcd.print("01092017-ITA-V2");
  delay(2000);
  mostraver=0;
  }
  else{
if(mins < 15){
lcd.setCursor(6, 1);
lcd.print(hours);
lcd.setCursor(8, 1);
lcd.print(":");
lcd.setCursor(9, 1);
lcd.print("15");

}

else{
if(mins < 30){
lcd.setCursor(6, 1);
lcd.print(hours);
lcd.setCursor(8, 1);
lcd.print(":");
lcd.setCursor(9, 1);
lcd.print("30");
}
else{
if(mins < 45){
lcd.setCursor(6, 1);
lcd.print(hours);
lcd.setCursor(8, 1);
lcd.print(":");
lcd.setCursor(9, 1);
lcd.print("45");
}
else{
if(mins < 60){
lcd.setCursor(6, 1);
lcd.print(hours+1);
lcd.setCursor(8, 1);
lcd.print(":");
lcd.setCursor(9, 1);
lcd.print("00");
}
}
}
}
}
}

 if(secs>59){
  
    msecs=msecs+60;
    mins=mins+1;

  if(mins>59){
 
  hours=hours+1;
  mins=0;}
  

 
  
  }

  if((mins==59 && secs > 34) && suonato==false){
    digitalWrite(led,HIGH);
       lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print("Chiming...");
   lcd.setCursor(0, 1);
   lcd.print("Attendere, prego");
   for (int thisNote = 0; thisNote < 20; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(3, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(3);
  }
  
  if(day==31 && month==12 && hours == 23){
  lcd.clear();
  lcd.print("10");
  delay(1000);
  lcd.clear();
  lcd.print("9");
  delay(1000);
  lcd.clear();
  lcd.print("8");
  delay(1000);
  lcd.clear();
  lcd.print("7");
  delay(1000);
  lcd.clear();
  lcd.print("6");
  delay(1000);
  lcd.clear();
  lcd.print("5");
  delay(1000);
  lcd.clear();
  lcd.print("4");
  delay(1000);
  lcd.clear();
  lcd.print("3");
  delay(1000);
  lcd.clear();
  lcd.print("2");
  delay(1000);
  lcd.clear();
  lcd.print("1");
  delay(1000);
  lcd.clear();
  lcd.print("Buon anno!");
    }
    else{
      delay(10000);
      }

if(hours < 12){
    for (int thisNote = 0; thisNote < hours+1; thisNote++) {
    tone(3,  NOTE_E3, 1000);
    digitalWrite(buzzer, HIGH);
    delay(1000);
   
    noTone(3);
    digitalWrite(buzzer, LOW);
    delay(1000);
 
  }
}
else{
    for (int thisNote = 0; thisNote < hours-11; thisNote++) {
    tone(3,  NOTE_E3, 1000);
    digitalWrite(buzzer, HIGH);
    delay(750);
   
    noTone(3);
    digitalWrite(buzzer, LOW);
    delay(750);
 
  }
 
  }
  suonato=true;
  }

  

  
  
  
  if(mins==15 && suonato==false && secs >0){

    
 digitalWrite(led,HIGH);
    lcd.clear();
  lcd.setCursor(0, 0);
   lcd.print("Chiming...");
   lcd.setCursor(0, 1);
   lcd.print("Attendere, prego");
    for (int thisNote = 0; thisNote < 5; thisNote++) {
    int noteDuration = 1000 / noteDurations1[thisNote];
    tone(3, melody1[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    
    noTone(3);
    
    
  }
  suonato=true;
  }

  if(mins==30 && suonato==false && secs > 0){

    
 digitalWrite(led,HIGH);
    lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print("Chiming...");
   lcd.setCursor(0, 1);
   lcd.print("Attendere, prego");
    for (int thisNote = 0; thisNote < 9; thisNote++) {
    int noteDuration = 1000 / noteDurations2[thisNote];
    tone(3, melody2[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
   
    noTone(3);
 
  }
   suonato=true;

}

  
  if(mins==45 && suonato==false && secs>0){

   digitalWrite(led,HIGH);
   lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print("Chiming...");
   lcd.setCursor(0, 1);
   lcd.print("Attendere, prego");
    for (int thisNote = 0; thisNote < 14; thisNote++) {
    int noteDuration = 1000 / noteDurations3[thisNote];
    tone(3, melody3[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    
    noTone(3);
 

  }
   suonato=true;
  }



 stato=digitalRead(bottone);
 if(stato==HIGH){
  if(secs < 40){
  digitalWrite(led,HIGH);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Chiming...");
  lcd.setCursor(0, 1);
  lcd.print("Attendere prego");
  
  for (int thisNote = 0; thisNote < 20; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(3, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(3);
  }
    
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Chimes a mano");
  lcd.setCursor(0, 1);
  lcd.print("esito favorevole");
  delay(2000);
  
  }
  else{
    if(secs<58){
   lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print("Impossibile suonare");
   lcd.setCursor(0, 1);
   lcd.print("manualmente ora");
   delay(750);
   lcd.clear();
   lcd.setCursor(0, 0);
   lcd.print("Attendere, prego");
   lcd.setCursor(0, 1);
   lcd.print(" ");
   delay(1000);
      }
    }}
 
  
 
  
   digitalWrite(led,LOW);



if(month==2 && (year==2020 || year==2024 || year==2028  || year==2032)){
  if (day > 29){
    day=1;
    month=month+1;}
    }
   else{
    if (month == 2){
    if(day>28){
      day=1;
      month=month+1;}}
   }

if(month==4 || month == 6 || month == 9 || month == 11){
  if (day>30){
    day=1;}
    }
    else{
      if(day>31){
        day=1;
        month=month+1;}
      }


  if(day==25 && month ==12 && mostra > 10){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Buon natale");
  lcd.setCursor(0, 1);
  lcd.print("a tutti!");
  delay(3500);
  mostra=0;}

  if(day==26 && month ==12 && mostra > 10){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Buon Santo Ste-");
  lcd.setCursor(0, 1);
  lcd.print("fano a tutti!");
  delay(3500);
  mostra=0;}

  if(day==1 && month ==5 && mostra > 10){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Buona festa dei");
  lcd.setCursor(0, 1);
  lcd.print("lavoratori!");
  delay(3500);
  mostra=0;}

  if(day==1 && month ==1 && mostra > 10){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Buon anno!");
  lcd.setCursor(0, 1);
  lcd.print("Auguri!");
  delay(3500);
  mostra=0;}

  

if (mins==14||mins==29||mins==44||mins==59){
  suonato=false;
  }
if(hours==24){
  if(millis()>10000){
  hours=0;
  day=day+1;
  }
  }

  if (month >12){
    month=1;
    year=year+1;}
    
  if(fatto==true){
    fatto=false;
    }
  }
  }
