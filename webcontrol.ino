// 動手做16-4：從瀏覽器控制遠端的燈光開關
// 詳細的程式說明，請參閱第十六章，16-28頁。
//MEGA2560 大台24+1路+16溫度
#include "SPI.h"
#include "Ethernet.h"
#include "WebServer.h"
#include "Streaming.h"
#include <math.h>


static byte mac[] = { 0x00, 0x7B, 0xCB, 0x4B, 0x7C, 0x9A };
IPAddress ip(192, 168, 1, 123);
IPAddress subnet(255, 255, 255, 0);
IPAddress gateway(192, 168, 1, 1);

WebServer webserver("", 1234);

P(htmlHead) =
 "<!doctype html><html>"
 "<head><meta charset=\"utf-8\">"
 "<title>Arduino micro</title>"
 "</head><body>" ;

 P(htmlHeadb) =
 "<!doctype html><html>"
 "<head><meta charset=\"utf-8\">"
 "<title>Arduino micro2</title>"
 "<meta http-equiv=\"refresh\" content=\"1;url=form.html\">"
 "</head><body>" ;

P(htmlHeadt) =
 "<!doctype html><html>"
 "<head><meta charset=\"utf-8\">"
 "<title>Arduino micro2</title>"
 "<meta http-equiv=\"refresh\" content=\"1\">"
 "</head><body>" ;
 
P(htmlFoot) = 
"<a href = />home</a><br>"
"<a href = /form.html>switch config</a><br>"
"<a href = /temp.html>temp</a>"
"</body></html>";

P(homePage) = 
"REMOTE CONTROL<br>"

;

void defaultCmd(WebServer &server, WebServer::ConnectionType type)
{
  server.httpSuccess();
  
  if (type != WebServer::HEAD) 
  {
    server.printP(htmlHead);
    server.printP(homePage);
    server.printP(htmlFoot);
  }
}



P(FORM) =
"<form method=\"post\" action=\"sw\">";
  

void formCmd(WebServer &server, WebServer::ConnectionType type)
{
  server.httpSuccess();

  if (type != WebServer::HEAD)
  {
    server.printP(htmlHead);
    server.printP(FORM);
    
  if ((digitalRead (8)) == HIGH) {
  server << "light d8:<input name=\"lightd8\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd8\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d8:<input name=\"lightd8\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd8\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
  if ((digitalRead (22)) == HIGH) {
  server << "light d22:<input name=\"lightd22\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd22\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d22:<input name=\"lightd22\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd22\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
  if ((digitalRead (23)) == HIGH) {
  server << "light d23:<input name=\"lightd23\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd23\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d23:<input name=\"lightd23\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd23\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
  if ((digitalRead (24)) == HIGH) {
  server << "light d24:<input name=\"lightd24\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd24\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d24:<input name=\"lightd24\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd24\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
  if ((digitalRead (25)) == HIGH) {
  server << "light d25:<input name=\"lightd25\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd25\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d25:<input name=\"lightd25\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd25\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
  if ((digitalRead (26)) == HIGH) {
  server << "light d26:<input name=\"lightd26\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd26\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d26:<input name=\"lightd26\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd26\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
  if ((digitalRead (27)) == HIGH) {
  server << "light d27:<input name=\"lightd27\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd27\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d27:<input name=\"lightd27\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd27\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
  if ((digitalRead (28)) == HIGH) {
  server << "light d28:<input name=\"lightd28\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd28\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d28:<input name=\"lightd28\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd28\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
  if ((digitalRead (29)) == HIGH) {
  server << "light d29:<input name=\"lightd29\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd29\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d29:<input name=\"lightd29\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd29\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
  if ((digitalRead (30)) == HIGH) {
  server << "light d30:<input name=\"lightd30\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd30\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d30:<input name=\"lightd30\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd30\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
  if ((digitalRead (31)) == HIGH) {
  server << "light d31:<input name=\"lightd31\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd31\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d31:<input name=\"lightd31\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd31\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
  if ((digitalRead (32)) == HIGH) {
  server << "light d32:<input name=\"lightd32\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd32\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d32:<input name=\"lightd32\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd32\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
  if ((digitalRead (33)) == HIGH) {
  server << "light d33:<input name=\"lightd33\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd33\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d33:<input name=\"lightd33\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd33\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
  if ((digitalRead (34)) == HIGH) {
  server << "light d34:<input name=\"lightd34\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd34\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d34:<input name=\"lightd34\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd34\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
  if ((digitalRead (35)) == HIGH) {
  server << "light d35:<input name=\"lightd35\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd35\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d35:<input name=\"lightd35\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd35\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
  if ((digitalRead (36)) == HIGH) {
  server << "light d36:<input name=\"lightd36\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd36\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d36:<input name=\"lightd36\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd36\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
  if ((digitalRead (37)) == HIGH) {
  server << "light d37:<input name=\"lightd37\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd37\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d37:<input name=\"lightd37\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd37\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
  if ((digitalRead (38)) == HIGH) {
  server << "light d38:<input name=\"lightd38\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd38\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d38:<input name=\"lightd38\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd38\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
  if ((digitalRead (39)) == HIGH) {
  server << "light d39:<input name=\"lightd39\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd39\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d39:<input name=\"lightd39\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd39\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
  if ((digitalRead (40)) == HIGH) {
  server << "light d40:<input name=\"lightd40\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd40\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d40:<input name=\"lightd40\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd40\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
  if ((digitalRead (41)) == HIGH) {
  server << "light d41:<input name=\"lightd41\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd41\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d41:<input name=\"lightd41\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd41\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
  if ((digitalRead (42)) == HIGH) {
  server << "light d42:<input name=\"lightd42\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd42\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d42:<input name=\"lightd42\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd42\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
  if ((digitalRead (43)) == HIGH) {
  server << "light d43:<input name=\"lightd43\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd43\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d43:<input name=\"lightd43\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd43\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
  if ((digitalRead (44)) == HIGH) {
  server << "light d44:<input name=\"lightd44\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd44\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d44:<input name=\"lightd44\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd44\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
  if ((digitalRead (45)) == HIGH) {
  server << "light d45:<input name=\"lightd45\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd45\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d45:<input name=\"lightd45\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd45\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
/*if ((digitalRead (46)) == HIGH) {
  server << "light d46:<input name=\"lightd46\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd46\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d46:<input name=\"lightd46\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd46\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }*/
/*if ((digitalRead (47)) == HIGH) {
  server << "light d47:<input name=\"lightd47\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd47\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d47:<input name=\"lightd47\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd47\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }*/
/*if ((digitalRead (48)) == HIGH) {
  server << "light d48:<input name=\"lightd48\" type=\"radio\" value=\"ON\" checked> ON";
  server << "<input name=\"lightd48\" type=\"radio\" value=\"OFF\" > OFF<br>";
  }else{
  server << "light d48:<input name=\"lightd48\" type=\"radio\" value=\"ON\" > ON";
  server << "<input name=\"lightd48\" type=\"radio\" value=\"OFF\"checked > OFF<br>";
  }
*/
  
  server << "<br><br><input type=\"submit\" name=\"button\" value=\"sent\">";
  server << "</form>";
    
    server.printP(htmlFoot);
  }
}

void postCmd(WebServer &server, WebServer::ConnectionType type)
{
  char name[16], value[16];
  server.httpSuccess();

  if (type == WebServer::POST)
  {
    server.printP(htmlHeadb);
    while (server.readPOSTparam(name, 16, value, 16)){
      if (strcmp(name, "msg") == 0) {
        server << "<h1>" << value << "</h1>";
      }
      
      if (strcmp(name, "lightd8") == 0) {
        
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(8, HIGH);
        } else {
          
          digitalWrite(8, LOW);
        }
      }
      if (strcmp(name, "lightd22") == 0) {
        
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(22, HIGH);
        } else {
          
          digitalWrite(22, LOW);
        }
      }
      if (strcmp(name, "lightd23") == 0) {
        
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(23, HIGH);
        } else {
          
          digitalWrite(23, LOW);
        }
      }
      if (strcmp(name, "lightd24") == 0) {
        
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(24, HIGH);
        } else {
          
          digitalWrite(24, LOW);
        }
      }
      if (strcmp(name, "lightd25") == 0) {
        
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(25, HIGH);
        } else {
          
          digitalWrite(25, LOW);
        }
      }
      if (strcmp(name, "lightd26") == 0) {
        
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(26, HIGH);
        } else {
          
          digitalWrite(26, LOW);
        }
      }
      if (strcmp(name, "lightd27") == 0) {
        
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(27, HIGH);
        } else {
          
          digitalWrite(27, LOW);
        }
      }
      if (strcmp(name, "lightd28") == 0) {
        
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(28, HIGH);
        } else {
          
          digitalWrite(28, LOW);
        }
      }
      if (strcmp(name, "lightd29") == 0) {
        
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(29, HIGH);
        } else {
          
          digitalWrite(29, LOW);
        }
      }
      if (strcmp(name, "lightd30") == 0) {
        
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(30, HIGH);
        } else {
          
          digitalWrite(30, LOW);
        }
      }
      if (strcmp(name, "lightd31") == 0) {
        
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(31, HIGH);
        } else {
          
          digitalWrite(31, LOW);
        }
      }
      if (strcmp(name, "lightd32") == 0) {
        
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(32, HIGH);
        } else {
          
          digitalWrite(32, LOW);
        }
      }
      if (strcmp(name, "lightd33") == 0) {
        
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(33, HIGH);
        } else {
          
          digitalWrite(33, LOW);
        }
      }
      if (strcmp(name, "lightd34") == 0) {
        
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(34, HIGH);
        } else {
          
          digitalWrite(34, LOW);
        }
      }
      if (strcmp(name, "lightd35") == 0) {
        
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(35, HIGH);
        } else {
          
          digitalWrite(35, LOW);
        }
      }
      if (strcmp(name, "lightd36") == 0) {
        
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(36, HIGH);
        } else {
          
          digitalWrite(36, LOW);
        }
      }
      if (strcmp(name, "lightd37") == 0) {
        
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(37, HIGH);
        } else {
          
          digitalWrite(37, LOW);
        }
      }
      if (strcmp(name, "lightd38") == 0) {
        
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(38, HIGH);
        } else {
          
          digitalWrite(38, LOW);
        }
      }
      if (strcmp(name, "lightd39") == 0) {
        
        if (strcmp(value, "ON") == 0) {
         
          digitalWrite(39, HIGH);
        } else {
        
          digitalWrite(39, LOW);
        }
      }
      if (strcmp(name, "lightd40") == 0) {
        
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(40, HIGH);
        } else {
          
          digitalWrite(40, LOW);
        }
      }
      if (strcmp(name, "lightd41") == 0) {
        
        if (strcmp(value, "ON") == 0) {
         
          digitalWrite(41, HIGH);
        } else {
          
          digitalWrite(41, LOW);
        }
      }
      if (strcmp(name, "lightd42") == 0) {
        
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(42, HIGH);
        } else {
          
          digitalWrite(42, LOW);
        }
      }
      if (strcmp(name, "lightd43") == 0) {
       
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(43, HIGH);
        } else {
         
          digitalWrite(43, LOW);
        }
      }
      if (strcmp(name, "lightd44") == 0) {
       
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(44, HIGH);
        } else {
         
          digitalWrite(44, LOW);
        }
      }
      if (strcmp(name, "lightd45") == 0) {
       
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(45, HIGH);
        } else {
         
          digitalWrite(45, LOW);
        }
      }
/*    if (strcmp(name, "lightd46") == 0) {
       
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(46, HIGH);
        } else {
         
          digitalWrite(46, LOW);
        }
      }*/
/*    if (strcmp(name, "lightd47") == 0) {
       
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(47, HIGH);
        } else {
         
          digitalWrite(47, LOW);
        }
      }*/
 /*   if (strcmp(name, "lightd48") == 0) {
       
        if (strcmp(value, "ON") == 0) {
          
          digitalWrite(48, HIGH);
        } else {
         
          digitalWrite(48, LOW);
        }
      }
      */
    }
    server.printP(htmlFoot);
  }
}


void tempCmd(WebServer &server, WebServer::ConnectionType type)
{
  server.httpSuccess();

  if (type != WebServer::HEAD)
  {
    server.printP(htmlHeadt);
    server << "<p>temp0:" << Thermistor(analogRead(0)) << "&deg;C    ";
    server << "   temp8:" << Thermistor(analogRead(8)) << "&deg;C</p>";
    server << "<p>temp1:" << Thermistor(analogRead(1)) << "&deg;C    ";
    server << "   temp9:" << Thermistor(analogRead(9)) << "&deg;C</p>";
    server << "<p>temp2:" << Thermistor(analogRead(2)) << "&deg;C    ";
    server << "   temp10:" << Thermistor(analogRead(10)) << "&deg;C</p>";
    server << "<p>temp3:" << Thermistor(analogRead(3)) << "&deg;C    ";
    server << "   temp11:" << Thermistor(analogRead(11)) << "&deg;C</p>";
    server << "<p>temp4:" << Thermistor(analogRead(4)) << "&deg;C    ";
    server << "   temp12:" << Thermistor(analogRead(12)) << "&deg;C</p>";
    server << "<p>temp5:" << Thermistor(analogRead(5)) << "&deg;C    ";
    server << "   temp13:" << Thermistor(analogRead(13)) << "&deg;C</p>";
    server << "<p>temp6:" << Thermistor(analogRead(6)) << "&deg;C    ";
    server << "   temp14:" << Thermistor(analogRead(14)) << "&deg;C</p>";
    server << "<p>temp7:" << Thermistor(analogRead(7)) << "&deg;C    ";
    server << "   temp15:" << Thermistor(analogRead(15)) << "&deg;C</p>";

    server.printP(htmlFoot);
  }
}


void setup() {
  pinMode(8, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(29, OUTPUT);
  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(38, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(42, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(44, OUTPUT);
  pinMode(45, OUTPUT);
/*pinMode(46, OUTPUT);*/
/*pinMode(47, OUTPUT);*/
/*pinMode(48, OUTPUT);*/
  Ethernet.begin(mac, ip, gateway, subnet);
  webserver.setDefaultCommand(&defaultCmd);     // 處理「首頁」請求
  webserver.addCommand("sw", &postCmd);         // 處理「sw表單處理頁面」請求
  webserver.addCommand("form.html", &formCmd);  // 處理「表單頁面」請求
  webserver.addCommand("temp.html", &tempCmd);
  webserver.begin();
}

double Thermistor(float RawADC) {
 double Temp;
 Temp = log(10000.0*((1024.0/RawADC-1)));
//         =log(10000.0/(1024.0/RawADC-1)) // for pull-up configuration
 Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
 Temp = Temp - 273.15;            // Convert Kelvin to Celcius
 
 return Temp;
}

void loop() {
  webserver.processConnection();
  
}
