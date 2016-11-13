#include "Nextion.h"
#include "DHT.h"
#define DHTPIN 2
void t0PopCallback(void *ptr);
void t1PopCallback(void *ptr);
/*
void temp_1PopCallback(void *ptr);
void temp_2PopCallback(void *ptr);
void temp_3PopCallback(void *ptr);

void hum_1PopCallback(void *ptr);
void hum_2PopCallback(void *ptr);
void hum_3PopCallback(void *ptr);

void svet_1PopCallback(void *ptr);
void svet_2PopCallback(void *ptr);
void svet_3PopCallback(void *ptr);

void pochva_1PopCallback(void *ptr);
void pochva_2PopCallback(void *ptr);
void pochva_3PopCallback(void *ptr);

void time_last_poliv_1(void *ptr);
void time_last_poliv_2(void *ptr);
void time_last_poliv_3(void *ptr);
*/
void button_teplica_1PopCallback(void *ptr);
void button_teplica_2PopCallback(void *ptr);
void button_teplica_3PopCallback(void *ptr);
void backPopCallback(void *ptr);

NexText date_text = NexText(0 , 2 , "t0");
NexText time_text = NexText(0 , 1 , "t2");
NexText teplica_id_text = NexText(0 , 13 , "t13");

NexText temp_1 = NexText(0 , 6 , "t6");
NexText temp_2 = NexText(0 , 13 , "t13");
NexText temp_3 = NexText(0 , 18 , "t18");

NexText hum_1 = NexText(0 , 7 , "t7");
NexText hum_2 = NexText(0 , 14 , "t14");
NexText hum_3 = NexText(0 , 19 , "t19");

NexText svet_1 = NexText(0 , 8 , "t8");
NexText svet_2 = NexText(0 , 15 , "t15");
NexText svet_3 = NexText(0 , 20 , "t20");

NexText pochva_1 = NexText(0 , 9 , "t9");
NexText pochva_2 = NexText(0 , 16 , "t16");
NexText pochva_3 = NexText(0 , 21 , "t21");

NexText time_last_poliv_1 = NexText(0 , 10 , "t10");
NexText time_last_poliv_2 = NexText(0 , 17 , "t17");
NexText time_last_poliv_3 = NexText(0 , 17 , "t22");

NexButton button_teplica_1 = NexButton(10 , 2 , "b0");
NexButton button_teplica_2 = NexButton(10 , 3 , "b1");
NexButton button_teplica_3 = NexButton(10 , 4 , "b2");
NexButton back = NexButton(0 , 7 , "b7");

NexPage page_teplica = NexPage(11 , 0 ,"page 11");

char buffer[100] = {0};
char buffer2[100] = {0};
long last_display_refresh = 0;
int second = 0;
int minute = 0;
int hour = 0;
int day = 12;
int month = 2;
int year = 2016;
int screen = 0;
bool b = 0;
//DHT dht_1( 2 , DHT11);

class teplica 
{
  DHT dht_1;
  public: 
  //const dht_pin = 2;
  int pochva_pin = 0;
  int osvet_pin = 0 ;
  long time_last_poliv = 0;
  long time_svet = 0;
  long time_in_svet[10] = {0};
  long time_poliv = 0;
  long time_in_poliv[10] = {0};
  
  teplica(int dht_pin) : dht_1( dht_pin , DHT11)
  {
    
    pinMode(pochva_pin,INPUT);
    pinMode(osvet_pin,INPUT);  
    dht_1.begin();
  }
  void init()
  {
   // DHT dht(dht_pin, DHT11);
    
    //dht.begin();
    
  }
  
  int get_temp()
  {
    return dht_1.readTemperature();
  }

  int get_hum()
  {
    return dht_1.readHumidity();
  }

  int get_pochva()
  {
    return map(analogRead(pochva_pin) , 0 , 1024 , 0 , 100);
  }

  int get_osvet()
  {
    return map(analogRead(osvet_pin) , 0 , 1024 , 0 , 100);
  }
  
  void poliv()
  {
    
  }

  void svet_on()
  {
    
  }

  void svet_off()
  {
    
  }
  
  private:
};
teplica teplica_1(2);
teplica teplica_2(3);
teplica teplica_3(4);
NexTouch *nex_listen_list[] =
{
  &date_text,
  &time_text,
  &button_teplica_1,
  &button_teplica_2,
  &button_teplica_3,
  &page_teplica,
  NULL
};

void date_textPopCallback(void *ptr)
{
  
}

void time_textPopCallback(void *ptr)
{
  
}

void button_teplica_1PopCallback(void *ptr)
{
  screen = 1;
 // digitalWrite(13,HIGH);
  page_teplica.show();
  refresh_display();
}

void button_teplica_2PopCallback(void *ptr)
{
  screen = 2;
  page_teplica.show();
  refresh_display();
}

void button_teplica_3PopCallback(void *ptr)
{
  screen = 3;
  page_teplica.show();
  refresh_display();
}

void second_update()
{
  refresh_display();
}

void refresh_display()
{
  //date update
  itoa(day , buffer , 10);
  itoa(month , buffer2 , 10);
  strcat(buffer , ".");
  strcat(buffer , buffer2);
  memset(buffer2 , 0 , sizeof(buffer2));
  itoa(year , buffer2 , 10);
  strcat(buffer , ".");
  strcat(buffer , buffer2);
  date_text.setText(buffer);
  memset(buffer2 , 0 , sizeof(buffer2));
  memset(buffer , 0 , sizeof(buffer));
  //date updae
  //time update
  itoa(hour , buffer , 10);
  itoa(minute , buffer2 , 10);
  strcat(buffer , ":");
  strcat(buffer , buffer2);
  time_text.setText(buffer);
  memset(buffer2 , 0 , sizeof(buffer2));
  memset(buffer , 0 , sizeof(buffer));
  //time update
  /*temp_1.setText("temp");
  temp_2.setText("temp");
  temp_3.setText("temp");*/
  /*itoa(teplica_1.get_temp(), buffer , 10);
     temp_1.setText(buffer);
     memset(buffer , 0 , sizeof(buffer));
     itoa(teplica_1.get_hum() , buffer , 10);
     hum_1.setText(buffer);*/
  switch(screen)
  {
    case 0:
    break;

    case 1:
     teplica_id_text.setText("1");
     itoa(teplica_1.get_temp(), buffer , 10);
     temp_1.setText(buffer);
     memset(buffer , 0 , sizeof(buffer));
     itoa(teplica_1.get_hum() , buffer , 10);
     hum_1.setText(buffer);
     memset(buffer , 0 , sizeof(buffer));
    break;

    case 2:
     teplica_id_text.setText("2");
     itoa(teplica_2.get_temp(), buffer , 10);
     temp_1.setText(buffer);
     memset(buffer , 0 , sizeof(buffer));
     itoa(teplica_2.get_hum() , buffer , 10);
     hum_1.setText(buffer);
     memset(buffer , 0 , sizeof(buffer));
    break;
    
    case 3:
     teplica_id_text.setText("3");
     itoa(teplica_3.get_temp(), buffer , 10);
     temp_1.setText(buffer);
     memset(buffer , 0 , sizeof(buffer));
     itoa(teplica_3.get_hum() , buffer , 10);
     hum_1.setText(buffer);
     memset(buffer , 0 , sizeof(buffer));
    break;
  }
  
}

void setup() {
  nexInit();
  date_text.attachPop(date_textPopCallback);
  time_text.attachPop(time_textPopCallback);
  button_teplica_1.attachPop(button_teplica_1PopCallback);
  button_teplica_2.attachPop(button_teplica_2PopCallback);
  button_teplica_3.attachPop(button_teplica_3PopCallback);
}

void loop() {
  nexLoop(nex_listen_list);
  if(millis() > last_display_refresh + 1000)
  {
    second_update();
    last_display_refresh = millis();
  }
}
