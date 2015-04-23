#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
// つなげる場所により変えよう

const int BUTTON1 = 4;
const int BUTTON2 = 6;
const int BUTTON3 = 7;
const int BUTTON4 = 8;
const int BUTTON5 = 10;
const int BUTTON6 = 12;
const int BUTTON7 = 13;
// 回路の抵抗度合いなどに応じて数値は調整しよう
#define note_MIN 0
#define note_MAX 127
#define vol_MIN 200 // volume保護用に抵抗で分圧してる関係上
#define vol_MAX 1023

// これもCdSを手で覆った時だけ使いたいのでこんな値
// 明るさによって変わるので調整しよう
#define cds_MIN 820
#define cds_MAX 1023

// pitchbendは本当は -8192 - 8191 だけど
// 元々の値が荒いので、ベンド幅を1/4にしとく。
// これだとあまり変わらないので、もっと増やしてもいいかも。
// そのへんは好みでw
#define pb_MIN -2048
#define pb_MAX 2048

// 初期化処理です
void setup(){

  pinMode(BUTTON1,INPUT);
  pinMode(BUTTON2, INPUT);
  pinMode(BUTTON3,INPUT);
  pinMode(BUTTON4, INPUT);
  pinMode(BUTTON5,INPUT);
  pinMode(BUTTON6, INPUT);
  pinMode(BUTTON7,INPUT);
  MIDI.begin(1);                // Launch MIDI with default options
}

// これはセンサー入力のフラつき対策
boolean checkChange(int val1,int val2, int range){
  int l,h;
  l = val2-range;
  h = val2+range;
  if((l > val1)||(h < val1)){
   return true;
  }
  return false;
} 

int button1 = 0;
int button2 = 0;
int button3 = 0;
int button4 = 0;
int button5 = 0;
int button6 = 0;
int button7 = 0;


void loop(){
  int nowbutton1;
  int nowbutton2;
  int nowbutton3;
  int nowbutton4; 
  int nowbutton5;
  int nowbutton6; 
  int nowbutton7;



  // Button (Note ON/OFF)
  nowbutton1 = digitalRead(BUTTON1);
  if(nowbutton1 != button1){
    if(nowbutton1 == HIGH) {
      MIDI.sendNoteOn(89,100,1);
    
    }else{
      MIDI.sendNoteOff(89,0,1);
    
    }
    delay(50);
  }
  button1= nowbutton1;
  
    nowbutton2 = digitalRead(BUTTON2);
  if(nowbutton2 != button2){
    if(nowbutton2 == HIGH) {
      MIDI.sendNoteOn(91,100,1);
    
    }else{
      MIDI.sendNoteOff(91,0,1);
    
    }
    delay(50);
  }
  button2 = nowbutton2;

  nowbutton3 = digitalRead(BUTTON3);
  if(nowbutton3 != button3){
    if(nowbutton3 == HIGH) {
      MIDI.sendNoteOn(93,100,1);
    
    }else{
      MIDI.sendNoteOff(93,0,1);
    
    }
    delay(50);
  }
  button3= nowbutton3;
  
  nowbutton4 = digitalRead(BUTTON4);
  if(nowbutton4 != button4){
    if(nowbutton4 == HIGH) {
      MIDI.sendNoteOn(95,100,1);
    
    }else{
      MIDI.sendNoteOff(95,0,1);
    
    }
    delay(50);
  }
  button4= nowbutton4;
  
  nowbutton5 = digitalRead(BUTTON5);
  if(nowbutton5 != button5){
    if(nowbutton5 == HIGH) {
      MIDI.sendNoteOn(96,100,1);
    
    }else{
      MIDI.sendNoteOff(96,0,1);
    
    }
    delay(50);
  }
  button5= nowbutton5;
  
  nowbutton6 = digitalRead(BUTTON6);
  if(nowbutton6 != button6){
    if(nowbutton6 == HIGH) {
      MIDI.sendNoteOn(98,100,1);
    
    }else{
      MIDI.sendNoteOff(98,0,1);
    
    }
    delay(50);
  }
  button6= nowbutton6;
  
  nowbutton7 = digitalRead(BUTTON7);
  if(nowbutton7 != button7){
    if(nowbutton7 == HIGH) {
      MIDI.sendNoteOn(100,100,1);
    
    }else{
      MIDI.sendNoteOff(100,0,1);
    
    }
    delay(50);
  }
  button7= nowbutton7;
}
