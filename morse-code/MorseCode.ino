int pin = 13;
const int timeunit = 200;
const int time_dash = timeunit*3;
const int time_dot = timeunit;
const int time_sym_space = timeunit;
const int time_ltr_space = timeunit * 3;
const int time_wrd_space = timeunit * 7;

String textToMorseCode = "";
void setup() {
  // put your setup code here, to run once:
  pinMode(pin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter text to morse code");
}

void loop() {
  // check if Serial buffer has content
  if(Serial.available()>0){
    //Then read the string and assign it to textToMorseCode
    textToMorseCode = Serial.readString();
    textToMorseCode.toUpperCase();
    }
  
  //beep the string
  beepWord((textToMorseCode));
  
  delay(4000);
}
void dot_beep(){
  digitalWrite(pin,HIGH);
  delay(time_dot);
  digitalWrite(pin,LOW);
}
void dash_beep(){
  digitalWrite(pin,HIGH);
  
 
  
  digitalWrite(pin,LOW);
}



void beepWord(String str) {
  for (int charIndex = 0; charIndex < str.length(); charIndex++) {
      beep_char(str.charAt(charIndex));
      delay(time_ltr_space);
  }
      

}

void beep_char(char c) {
  switch (c) {
    case 'A' :
      Serial.println("A");
      beepSymbols(".-");
      break;  
    case 'B' :
      Serial.println("B");
      beepSymbols(".---");
      break;
    case 'C':
      Serial.println("C");
      beepSymbols("-.-.");
      break;
    case 'D':
      Serial.println("D");
      beepSymbols("-..");
      break;
    case 'E':
      Serial.println("E");
      beepSymbols(".");
      break;
    case 'F':
      Serial.println("F");
      beepSymbols("--.-");
   
      break;
    case 'G':
      Serial.println("G");
      beepSymbols("--.");
      break;
    case 'H':
      Serial.println("H");
      beepSymbols("....");
      break;
    case 'I':
      Serial.println("I");
      beepSymbols("..");
      break;
    case 'J':
      Serial.println("J");
      beepSymbols(".---");
      break;
    case 'K':
      Serial.println("K");
      beepSymbols("-.-");
      dash_beep();
      break;
    case 'L':
      Serial.println("L");
      beepSymbols(".-..");
      break;
    case 'M':
      Serial.println("M");
      beepSymbols("--");
      break;
    case 'N':
      Serial.println("N");
      beepSymbols("-.");
      break;
    case 'O':
      Serial.println("O");
      beepSymbols("---");
      break;  
    case 'P':
      Serial.println("P");
      beepSymbols(".--.");
      break;
    case 'Q':
      Serial.println("Q");
      beepSymbols("--.-");
      break;
    case 'R':
      Serial.println("R");
      beepSymbols(".-.");
      break;
    case 'S':
      Serial.println("S");
      beepSymbols("...");
      break;
    case 'T':
      Serial.println("T");
      beepSymbols("-");
      break;
    case 'U':
      Serial.println("U");
      beepSymbols("..-");
      break;
    case 'V':
      Serial.println("V");
      beepSymbols("...-");
      break;
    case 'w':
      Serial.println("W");
      beepSymbols(".--");
      break;
    case 'X':
      Serial.println("X");
      beepSymbols("-..-");
      break;
    case 'Y':
      Serial.println("Y");
      beepSymbols("-.--");
      break;
    case 'Z':
      Serial.println("Z");
      beepSymbols("--.");
      break;
  }

  
}

void beepSymbols(String str) {
  //Assume the string will have dots and dashes like .---
  //iterate each charater in the string
  //if it is dot call the dotbeep 
  //it is is dash call the dashbeep
  //Add a delay if more characters are available
  //String str = "-.";
   for (int charIndex = 0; charIndex < str.length(); charIndex++) {
    Serial.print(str.charAt(charIndex));
      if(str.charAt(charIndex) == '.') {
        dot_beep();
      } else if (str.charAt(charIndex) == '-') {
        dash_beep();
      }
      if (charIndex <=str.length() -1) {
        delay(time_sym_space);
      }
   }
   Serial.println("");
}
