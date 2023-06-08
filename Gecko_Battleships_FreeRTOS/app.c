#include <stdio.h>

#include <FreeRTOS.h>
#include <task.h>
#include <stdlib.h>
#include "em_device.h"
#include "em_chip.h"
#include "em_lcd.h"
#include "segmentlcd.h"
#include "segmentlcd_individual.h"
#include <queue.h>
#include "em_usart.h"
#include <semphr.h>
#include "em_cmu.h"
#include "em_gpio.h"
#include "app.h"
#include "fuggvenyek.h"
#include "szamlalo.h"

#define ido configTICK_RATE_HZ/100

TaskHandle_t handleHi;
TaskHandle_t hTaskUART;

SemaphoreHandle_t guard;
int x = 1, y = 1, i, lovesszam = 0;
volatile uint8_t data;
bool talalat = false;
bool loves2 = false;
bool win = false;
bool kezdes = true;
int alapallas[16];
int sullyedt[16];

void UART0_RX_IRQHandler(void){
  BaseType_t xSwitchRequired;
  USART_IntClear (UART0, USART_IF_RXDATAV);
  data = USART_RxDataGet(UART0);
  USART_Tx(UART0,data);
  xSwitchRequired = xTaskResumeFromISR(hTaskUART);
  portYIELD_FROM_ISR(xSwitchRequired);
}

static void prvTaskinit(void *pvParam){
        if(kezdes){
          xSemaphoreTake(guard,portMAX_DELAY);
          szamlalo(lovesszam);
          elrendezes(alapallas);
          kezdes = false;
          xSemaphoreGive(guard);
        }
        else{
            kurzor(x,y);
        }
    vTaskDelete(NULL);
}

static void prvTaskUART(void *pvParam){
while(1){
   // vTaskDelay(ido);
    //if(USART_StatusGet(UART0) & USART_STATUS_RXDATAV) {
    vTaskSuspend(NULL);
        xSemaphoreTake(guard,portMAX_DELAY);
        //A 'w' �s 's' karakterekkel az y koordin�t�t v�ltoztatjuk
         //uint8_t data = USART_RxDataGet(UART0);
           if(data=='.')
             {
               win = true;
             }
           if(data == 'r')
             {
               NVIC_SystemReset();
             }
           if(data=='w'){
             if(y<13){
                 y++;

             }
             else if(y==13) {y=1;}
           }
           if(data=='s'){
             if(y>1){y--;}
             else if(y==1) {y=13;}
           }
           //A 'd' �s 'a' karakterekkel az x koordin�t�t v�ltoztatjuk
           if(data=='d'){
             if(x<6){x++;}
             else if(x==6) {x=0;}
           }
           if(data=='a'){
             if(x>0){x--;}
             else if(x==0) {x=6;}
           }
           //A 'q' karakterrel l�v�nk
           if(data=='e'){
               loves2=true;
           }
           else{
               loves2 = false;
           }
           xSemaphoreGive(guard);
      //}
  }
}

static void prvTaskkijelzo(void *pvParam){
  while(1){
         vTaskDelay(ido);
         xSemaphoreTake(guard,portMAX_DELAY);
         kurzor(x,y);
         kijelez(sullyedt,i);
         if(win)
           {
             vege_clear();
             vege();
             USART_Tx(UART0,'x');
             __enable_irq();
           }
         while(win){
             if(data == (uint8_t)'r')
               {
                 NVIC_SystemReset();
               }
         }
         xSemaphoreGive(guard);
     }
}



  static void prvTaskloves(void *pvParam){
  while(1){
       __disable_irq();
      bool ez = loves2==true;
      __enable_irq();
      if(ez){

          //vTaskDelay(ido);
          xSemaphoreTake(guard,portMAX_DELAY);
          talalat=loves(alapallas, x, y, sullyedt, i);
          //A l�v�sek sz�m�t mindig n�velj�k �s ezzel friss�tj�k a sz�ml�l�t
          lovesszam++;
          szamlalo(lovesszam);
          loves2 = false;
          if(talalat){
              USART_Tx(UART0,'1');
                   sullyedt[i++]=x;
                   sullyedt[i++]=y;
                 }
          else {
              USART_Tx(UART0,'0');
          }
          if(i==16){
                  win=true;
              }
          xSemaphoreGive(guard);
      }

    }
  }



  void app_init(void)
  {
    SegmentLCD_Init(false);

    guard = xSemaphoreCreateMutex();
    xSemaphoreGive(guard);

    xTaskCreate(
           prvTaskinit,
           "",
           configMINIMAL_STACK_SIZE,
           NULL,
           tskIDLE_PRIORITY + 2,
           NULL
         );

    xTaskCreate(
        prvTaskUART,
        "",
        configMINIMAL_STACK_SIZE,
        NULL,
        tskIDLE_PRIORITY + 2,
        &hTaskUART
      );

    xTaskCreate(
          prvTaskkijelzo,
          "",
          configMINIMAL_STACK_SIZE,
          NULL,
          tskIDLE_PRIORITY + 1,
          NULL
        );


    xTaskCreate(
          prvTaskloves,
          "",
          configMINIMAL_STACK_SIZE,
          NULL,
          tskIDLE_PRIORITY + 1,
          NULL
        );


    CMU->HFPERCLKEN0 |= CMU_HFPERCLKEN0_GPIO;
     // Set PF7 to high
     GPIO_PinModeSet(gpioPortF, 7, gpioModePushPull, 1);
     // Configure UART0
     // (Now use the "emlib" functions whenever possible.)
     // Enable clock for UART0
     CMU_ClockEnable(cmuClock_UART0, true);

     CMU_ClockEnable(cmuClock_GPIO, true);
     //GPIO_PinModeSet(gpioPortF, 7, gpioModePushPull, 1);
     // Initialize UART0 (115200 Baud, 8N1 frame format)
    USART_InitAsync_TypeDef UART0_init = USART_INITASYNC_DEFAULT;
     USART_InitAsync(UART0, &UART0_init);
     // USART0: see in efm32ggf1024.h
     // Set TX (PE0) and RX (PE1) pins as push-pull output and input resp.
     // DOUT for TX is 1, as it is the idle state for UART communication
     GPIO_PinModeSet(gpioPortE, 0, gpioModePushPull, 1);
     // DOUT for RX is 0, as DOUT can enable a glitch filter for inputs,
     // and we are fine without such a filter
     GPIO_PinModeSet(gpioPortE, 1, gpioModeInput, 0);
     // Use PE0 as TX and PE1 as RX (Location 1, see datasheet (not refman))
     // Enable both RX and TX for routing
     UART0->ROUTE |= UART_ROUTE_LOCATION_LOC1;
     // Select "Location 1" as the routing configuration
     UART0->ROUTE |= UART_ROUTE_TXPEN | UART_ROUTE_RXPEN;

     // Megszflag torlese a periferian
     USART_IntClear(UART0, USART_IEN_RXDATAV);
     // Megsz engedelyezese a periferian
     USART_IntEnable(UART0, USART_IEN_RXDATAV);

     // Megsz torlese belul
     NVIC_ClearPendingIRQ(UART0_RX_IRQn);
     // Megsz engedelyezese belul
     NVIC_EnableIRQ(UART0_RX_IRQn);

  }

  /***************************************************************************//**
   * App ticking function.
   ******************************************************************************/
  void app_process_action(void)
  {
  }


