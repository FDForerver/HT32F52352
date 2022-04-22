#include "adc.h"
#include "ht32.h"
#include "ht32_board_config.h"




//void Adc_Init(void)
//{
//  CKCU_PeripClockConfig_TypeDef CKCUClock = {{0}};

//  RETARGET_Configuration();           /* Retarget Related configuration                                     */

//  /* Enable the ADC Interrupts                                                                              */
//  NVIC_EnableIRQ(ADC_IRQn);

//  /* Enable peripheral clock of ADC                                                                         */
//  CKCUClock.Bit.AFIO  = 1;
//  CKCUClock.Bit.ADC   = 1;
//  CKCU_PeripClockConfig(CKCUClock, ENABLE);

//  /* ADCLK frequency is set to CK_AHB/64                                                                    */
//  CKCU_SetADCPrescaler(CKCU_ADCPRE_DIV64);

//  /* Config AFIO mode as ADC function                                                                       */
//  AFIO_GPxConfig(HTCFG_VR_GPIO_ID, HTCFG_VR_AFIO_PIN, AFIO_FUN_ADC);

//  /* Continuous Mode, Length 1, SubLength 1                                                                 */
//  ADC_RegularGroupConfig(HT_ADC, CONTINUOUS_MODE, 1, 1);

//  /* ADC Channel n, Rank 0, Sampling clock is (1.5 + 0) ADCLK
//     Conversion time = (sampling clock + 12.5) / ADCLK = 12.4 uS */
//  ADC_RegularChannelConfig(HT_ADC, HTCFG_VR_ADC_CH, 0);

//  /* Use Software Trigger as ADC trigger source                                                             */
//  ADC_RegularTrigConfig(HT_ADC, ADC_TRIG_SOFTWARE);

//  /* Enable ADC single end of conversion interrupt,
//     The ADC ISR will store the ADC result into global variable gPotentiometerLevel. */
//  ADC_IntConfig(HT_ADC, ADC_INT_SINGLE_EOC, ENABLE);

//  ADC_Cmd(HT_ADC, ENABLE);

//  /* Software trigger to start continuous mode                                                              */
//  ADC_SoftwareStartConvCmd(HT_ADC, ENABLE);
// }
