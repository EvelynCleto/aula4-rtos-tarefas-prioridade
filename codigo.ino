#include <Arduino.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void TaskHigh(void *pvParameters)
{
  while (true)
  {
    Serial.println("Task HIGH executando");
    vTaskDelay(pdMS_TO_TICKS(500));
  }
}

void TaskLow(void *pvParameters)
{
  while (true)
  {
    Serial.println("Task LOW executando");
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

void setup()
{
  Serial.begin(115200);

  xTaskCreate(
    TaskHigh,
    "THigh",
    2048,
    NULL,
    2,
    NULL
  );

  xTaskCreate(
    TaskLow,
    "TLow",
    2048,
    NULL,
    1,
    NULL
  );
}

void loop()
{
}