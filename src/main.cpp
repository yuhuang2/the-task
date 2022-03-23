#include <math.h>
#include <M5Core2.h>
#include <Arduino.h>

float accX = 0.0F; // Define variables for storing inertial sensor data
float accY = 0.0F; //定义存储惯性传感器相关数据的相关变量
float accZ = 0.0F;

/* After M5Core2 is started or reset
the program in the setUp () function will be run, and this part will only be run once.
在 M5Core2 启动或者复位后，即会开始执行setup()函数中的程序，该部分只会执行一次。 */
void setup()
{
  M5.begin();    // Init M5Core.  初始化 M5Core
  M5.IMU.Init(); // Init IMU sensor.  初始化惯性传感器
  M5.IMU.SetAccelFsr(AFS_4G);
  M5.Lcd.fillScreen(BLACK);        // Set the screen background color to black. 设置屏幕背景色为黑色
  M5.Lcd.setTextColor(RED, BLACK); // Sets the foreground color and background color of the displayed text.  设置显示文本的前景颜色和背景颜色
  M5.Lcd.setTextSize(2);           // Set the font size.  设置字体大小
}

void loop()
{
  // Serial.println("Looping");

  M5.IMU.getAccelData(&accX, &accY, &accZ); // Stores the triaxial accelerometer.  存储三轴加速度计数据

  // Accelerometer output is related
  //加速度计输出相关
  M5.Lcd.setCursor(0, 30);
  M5.Lcd.printf("accX,   accY,  accZ");
  M5.Lcd.setCursor(0, 52);
  M5.Lcd.printf("%5.2f  %5.2f  %5.2f G", accX, accY, accZ);
  Serial.printf("accX: %1.2f, accY: %1.2f  accZ: %1.2f\n", accX, accY, accZ);

  delay(250); // Delay 1s.
}