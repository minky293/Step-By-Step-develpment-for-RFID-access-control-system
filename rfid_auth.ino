#include <FS.h>
#include <LittleFS.h>

void setup() {
  Serial.begin(115200);
  
  // LittleFS ကို စတင်ခြင်း
  if(!LittleFS.begin(true)){
    Serial.println("LittleFS Mount လုပ်ရာတွင် အမှားဖြစ်သွားပါပြီ");
    return;
  }
  
  Serial.println("LittleFS ကို အောင်မြင်စွာ စတင်နိုင်ပါပြီ");

  // data ထဲက ဖိုင်တစ်ခုကို ဖတ်ရန် ဖွင့်ခြင်း
  File file = LittleFS.open("/whitelist.txt","r");
  if(!file){
    Serial.println("ဖိုင်ကို ရှာမတွေ့ပါ။ (သို့) မဖွင့်နိုင်ပါ။");
    return;
  }
  
  Serial.println("--- ဖိုင်ထဲပါသော အချက်အလက်များ ---");
  while(file.available()){
    Serial.write(file.read());
  }
  file.close();
}

void loop() {
  // ဘာမှမလုပ်ပါ
}