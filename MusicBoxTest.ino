// Notes' Frequencies
const float C4 = 261.6;
const float D4 = 293.7;
const float E4 = 329.6;
const float F4 = 349.2;
const float G4 = 392.0;
const float A4 = 440.0;
const float B4 = 493.9;
const float C4 = 523.3;
const float silence = 0.0;
// Time Measure
int bpm;
float rond;
float rondDot;
float white;
float whiteDot;
float black;
float blackDot;
float half;
float halfDot;
// Figures
const int ROND = 1;
const int ROND_DOT = 2;
const int WHITE = 3;
const int WHITE_DOT = 4;
const int BLACK = 5;
const int BLACK_DOT = 6;
const int HALF = 7;
const int HALF_DOT = 8;

const int ROND_S = 9;
const int ROND_DOT_S = 10;
const int WHITE_S = 11;
const int WHITE_DOT_S = 12;
const int BLACK_S = 13;
const int BLACK_DOT_S = 14;
const int HALF_S = 15;
const int HALF_DOT_S = 16;
// Frequency Names
char c = 'C';
char d = 'D';
char e = 'E';
char f = 'F';
char g = 'G';
char a = 'A';
char b = 'B';
char n0 = '0';
char n1 = '1';
char n2 = '2';
char n3 = '3';
char n4 = '4';
char n5 = '5';
char n6 = '6';
char n7 = '7';
char n8 = '8';
// Buzzer Port
int buzzer = 8;

void setup(){
  setTimings(100);
}

void loop(){

}

// This is a placeholder Melody
void playMelody(){
  playNote(BLACK, D);
  printNote(d, false);
  playNote(BLACK, G);
  printNote(g, false);
  playNote(BLACK, A);
  printNote(a, false);
  playNote(BLACK_DOT, C2);
  printNote(c, true);
  playNote(BLACK_DOT, B);
  printNote(b, false);
  playNote(HALF, A);
  printNote(a, false);
  playNote(HALF, G);
  printNote(g, false);
  playNote(WHITE, A);
  printNote(a, false);
  playNote(WHITE_DOT, D);
  printNote(d, false);
  playNote(BLACK_S, silence);
  printNote('\\', false);
}

void setTimings(int BPM){
  bpm = BPM;

  //black = (60/bpm) * 1000;
  black = 600;
  blackDot = black * 1.5;
  rond = black * 4;
  rondDot = rond * 1.5;
  white = black * 2;
  whiteDot = white * 1.5;
  half = black / 2;
  halfDot = half * 1.5;
}

void playNote(int fig, float note){
  // Function tone plays the note.
  tone(8, note);

  // Switch statement decides for how long it plays depending on the figure.
  switch(fig){
    case ROND: delay(rond); break;
    case ROND_DOT: delay(rondDot); break;
    case ROND_S: delay(rond); break;
    case ROND_DOT_S: delay(rondDot); break;
    case WHITE: delay(white); break;
    case WHITE_DOT: delay(whiteDot); break;
    case WHITE_S: delay(white); break;
    case WHITE_DOT_S: delay(whiteDot); break;
    case BLACK: delay(black); break;
    case BLACK_DOT: delay(blackDot); break;
    case BLACK_S: delay(black); break;
    case BLACK_DOT_S: delay(blackDot); break;
    case HALF: delay(half); break;
    case HALF_DOT: delay(halfDot); break;
    case HALF_S: delay(half); break;
    case HALF_DOT_S: delay(halfDot); break;
  }
}

void imSinging(){
    for(int ii = 0; ii < 8 ; ii++){
    tone(8, cScale[ii]);
    lcd.setCursor(7, 0);
    if (ii == 7){
       lcd.print(chars[0]);
       lcd.setCursor(8, 0);
       lcd.print(chars[ii]);
       delay(750);
    } else {
       lcd.print(chars[ii]);
    }
    delay(200);
    lcd.setCursor(8, 0);
    lcd.print(" ");

    lcd.setCursor(7, 0);
    lcd.print(" ");
  }
  lcd.clear();
}

void printNote(char note, boolean primeC){
  lcd.setCursor(7, 0);
  if (!primeC){
    lcd.print(note);
    lcd.print(' ');
  } else {
    lcd.print(note);
    lcd.setCursor(8, 0);
    lcd.print(prime);
  }
  //TODO: Think of an animation or something.
}
