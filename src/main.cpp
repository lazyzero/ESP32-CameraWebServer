#include <Arduino.h>
#include <App.hpp>
#include <SimpleWiFi.h>
#include <CameraSetup.h>
#include <CameraServer.h>

#define LED_PWM_CHANNEL 7

void setup() {
  pinMode( BOARD_LED, OUTPUT );
  ledcSetup(LED_PWM_CHANNEL, 5000, 8);
  ledcAttachPin( FLASH_LED, LED_PWM_CHANNEL );
  digitalWrite( BOARD_LED, true );
  ledcWrite( LED_PWM_CHANNEL, 0 );
  Serial.begin(115200);
  delay( 3000 ); // wait for serial monitor
  Serial.setDebugOutput(true);
  Serial.println( "\n\n\n" APP_NAME " - Version " APP_VERSION );
  Serial.println( "Build date: " __DATE__ " " __TIME__ "\n");

  Serial.println();
  Serial.printf("CPU Frequency       : %dMHz\n", ESP.getCpuFreqMHz() );
  Serial.println();

  initializeCamera();

  ledcWrite( LED_PWM_CHANNEL, 10 );
  disableWiFi();
  ledcWrite( LED_PWM_CHANNEL, 0 );
  connectWiFi();

  startCameraServer();

  Serial.print("Camera Ready! Use 'http://");
  Serial.print(WiFi.localIP());
  Serial.println("' to connect");
}

void loop()
{
  if( WiFi.isConnected() == false )
  {
    connectWiFi();
  }
  delay(10000);
}
