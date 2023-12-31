// ------------------------------------------------------------
// ライブラリインクルード部 Library include section.
// ------------------------------------------------------------
#include "Arduino.h"        // M5StickC 用ライブラ
#include <WiFi.h>           // Wifi制御用ライブラリ
#include <Preferences.h>    // 不揮発静メモリ制御ライブラリ

// ------------------------------------------------------------
// 定数/変数　定義部　Constant / variable definition section.
// ------------------------------------------------------------ 
Preferences preferences;
char ssid[33];        // アクセスポイント情報（SSID）の格納用 
char password[65];    // アクセスポイント情報（パスワード）の格納用

// ------------------------------------------------------------
// Setup 関数　Setup function.
// ------------------------------------------------------------ 
void setup() {
  // シリアルコンソールの開始　Start serial console.
  Serial.begin(115200); 
  delay(500); 

  // Wi-Fiアクセスポイント情報取得
  preferences.begin("AP-info", true);                           // 名前空間"AP-info"の指定と読み込みモード（true) 
  preferences.getString("ssid", ssid, sizeof(ssid));            // ssidの値を指定
  preferences.getString("pass", password, sizeof(password));    // passwordの値を指定 
  preferences.end();
 
  // Wi-Fi接続 We start by connecting to a WiFi network 
  Serial.println(); // シリアルポート経由でPCのシリアルモニタに出力 
  Serial.println(); 
  Serial.print("Connecting to "); 
  Serial.println(ssid); 
  
  WiFi.begin(ssid, password); // Wi-Fi接続開始
  // Wi-Fi接続の状況を監視（WiFi.statusがWL_CONNECTEDになるまで繰り返し 
  while (WiFi.status() != WL_CONNECTED) { 
    delay(500); 
    Serial.print("."); } 
  
  // Wi-Fi接続結果をシリアルモニタへ出力 
  Serial.println(""); 
  Serial.println("WiFi connected"); 
  Serial.println("IP address: "); 
  Serial.println(WiFi.localIP()); 
} 

void loop() { 
  delay(5000);
  if (WiFi.status() == WL_CONNECTED) {
    //Wi-Fiからの切断
    Serial.println("Disconnect from WiFi"); 
    WiFi.disconnect();

    // Wi-Fi接続の状況を監視（WiFi.statusがWL_DISCONNECTEDになるまで繰り返し
    while (WiFi.status() !=WL_DISCONNECTED) {
      delay(500);
      Serial.print(".");}

    // Wi-Fi切断結果をシリアルモニタへ出力
    Serial.println("");
    Serial.println("WiFi disconnected");
  }
}
