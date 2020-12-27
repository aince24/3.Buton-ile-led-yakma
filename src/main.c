

/* Includes */
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

GPIO_InitTypeDef LED ;

 void config(){


	 RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	 RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	 //led config
	 LED.GPIO_Mode= 0x01;
	 LED.GPIO_OType=0x00;
	 LED.GPIO_Pin=GPIO_Pin_12 |GPIO_Pin_13 |GPIO_Pin_14 |GPIO_Pin_15 ;
	 LED.GPIO_PuPd= 0x00;
	 LED.GPIO_Speed= 0x03;

	 GPIO_Init(GPIOD, &LED);

	 //buton config
	 LED.GPIO_Mode=0x00;
	 LED.GPIO_OType=GPIO_OType_PP;
	 LED.GPIO_Pin=GPIO_Pin_0;
	 LED.GPIO_PuPd=GPIO_PuPd_DOWN ;
	 LED.GPIO_Speed=0x03;

	 GPIO_Init(GPIOA, &LED);

 }
 // gecikme fonksiyonu
 void delay(uint32_t time){
	 while (time--){}
 }
int main(void)
{
   int sayac=0;
   config();
  while (1)
  {
	int ButonDurum= GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0);

	if (ButonDurum){
	 delay(1680000); //10ms bekle(buton çatýrdamalarý için)
	 sayac++;
	 switch(sayac){
	 case 1:
		 GPIO_SetBits(GPIOD, GPIO_Pin_12  );
	 break;

	 case 2:
		 GPIO_SetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13);
     break;

	 case 3:
		 GPIO_SetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14);
     break;

	 case 4:
		 GPIO_SetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
	 break;

	 case 5:
	    GPIO_ResetBits(GPIOD, GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
     break;
	 }

	}

  }
}



void EVAL_AUDIO_TransferComplete_CallBack(uint32_t pBuffer, uint32_t Size){
  /* TODO, implement your code here */
  return;
}

uint16_t EVAL_AUDIO_GetSampleCallBack(void){
  /* TODO, implement your code here */
  return -1;
}
