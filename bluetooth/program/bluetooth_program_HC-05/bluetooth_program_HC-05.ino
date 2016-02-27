#include <SoftwareSerial.h>
int txPin = 11;
int rxPin = 10;
SoftwareSerial bluetooth(rxPin, txPin); // RX, TX
void setup()
{
  Serial.begin(9600);
  pinMode(9,OUTPUT); digitalWrite(9,HIGH);
  bluetooth.begin(38400);
  Serial.println("Comunicazione inizializzata, Lista comandi per modulo HC-06:");
  Serial.println("AT              Se la comunicazione funziona il modulo risponde OK");
  Serial.println("AT+VERSION      Restituisce la versione del firmware");
  Serial.println("AT+BAUDx        Imposta il Baudrate, al posto di x mettere 1 per 1200 bps, 2=2400, 3=4800, 4=9600, 5=19200, 6=38400, 7=57600, 8=115200, 9=230400, A=460800, B=921600, C=1382400");
  Serial.println("AT+NAMEstring   Al posto di string mettere il nome che vuoi dare al modulo (massimo 20 caratteri)");
  Serial.println("AT+PINxxxx      Imposta il pincode del modulo bluetooth (es.1234)");
}
void loop()
{
  if (bluetooth.available())
  {  
    Serial.write(bluetooth.read());
  }
  if (Serial.available())
  {
   String str = Serial.readString();
int str_len = str.length() + 1; 
char char_array[str_len];
str.toCharArray(char_array, str_len);
  Serial.write(char_array);
    if(str=="pin2\r\n"){
        Serial.write("invio pin due ");
       char pin[8]= {0};
      pin[0] = 0x41;
pin[1] = 0x54; 
pin[2] = 0x2B; 
pin[3] = 0x50; 
pin[4] = 0x53; 
pin[5] = 0x57; 
pin[6] = 0x44;
pin[7] = 0x3D;

int8_t xpin[6]= {0};
xpin[0] = 0x2F;
xpin[1] = 0x70;
xpin[2] = 0x42;
xpin[3] = 0x1a;
xpin[4] = 0x5A;
xpin[5] = 0x00;
//at+pair=5a,1a,42702f,15
int8_t x1pin[6]= {0};
x1pin[5] =0x00;
x1pin[4] =0x5A;
x1pin[3] = 0x1a;
x1pin[2] = 0x42;
x1pin[1] =  0x70;
x1pin[0] =  0x2F;

int8_t xpin2[6]= {0};
     xpin2[0] = 0x34;
      xpin2[1] = 0x96;
      xpin2[2] = 0x36;
      xpin2[3] = 0xd3;
      xpin2[4] = 0x98;
      xpin2[5] = 0x00;

      int8_t x2pin2[6]= {0};
    
      x2pin2[0] = 0x98;
      x2pin2[1] =  0xd3;
      x2pin2[2] =0x36;
       x2pin2[3] = 0x00;
      x2pin2[4] = 0x96;
      x2pin2[5] = 0x34;

char res =hci_connect(x2pin2);
//pin[5] = 0x0d;
//pin[6] = 0x0a;




       Serial.write(pin);
       Serial.print(res);
       Serial.println("fine \n");
     bluetooth.write(pin);
     bluetooth.write(res);
      bluetooth.write("\r\n");
      
    }
    
    if(str.equals("pin\r\n")){
       Serial.write("invio pin uno");
      char pin[15];
      pin[0] = 0x41;
pin[1] = 0x54; 
pin[2] = 0x2B; 
pin[3] = 0x50; 
pin[4] = 0x53; 
pin[5] = 0x57; 
pin[6] = 0x44;

pin[7] = 0x3D;

      pin[8] = 0x34;
      pin[9] = 0x96;
      pin[10] = 0x36;
      pin[11] = 0xd3;
      pin[12] = 0x98;
    
      
      pin[13] = 0x0d; 
      pin[14] = 0x0a;

Serial.write(pin);
      bluetooth.write(pin);
    }else{
    bluetooth.write(char_array);
    }
  }
}

int8_t hci_connect(int8_t *bdaddr) {
    int8_t xbuf[6] = {0};

    xbuf[0] = *(bdaddr + 5); // 6 octet bluetooth address
    xbuf[1] = *(bdaddr + 4);
    xbuf[2] = *(bdaddr + 3);
    xbuf[3] = *(bdaddr + 2);
    xbuf[4] = *(bdaddr + 1);
    xbuf[5] = *bdaddr;
 //  xbuf[6] = 0x18; // DM1 or DH1 may be used
 //   xbuf[7] = 0xCC; // DM3, DH3, DM5, DH5 may be used
  //  xbuf[8] = 0x01; // page repetition mode R1
 //  xbuf[9] = 0x00; // always 0
 //   xbuf[10] = 0x00; // clock offset
//    xbuf[11] = 0x00; // invalid clock offset
//    xbuf[12] = 0x00; // do not allow role switch

    return *xbuf; //HCI_Command(16, buf);
}
