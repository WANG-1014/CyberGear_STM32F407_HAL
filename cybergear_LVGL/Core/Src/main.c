/* USER CODE BEGIN Header */
/***********************************************************************************************************************************
 ** �������д��  ħŮ�������Ŷ�
 ** ����    ����  ħŮ������       https://demoboard.taobao.com
 ***********************************************************************************************************************************
 ** ��ʵ�����ơ�  LVGL ��ֲ����
 **
 ** ������ƽ̨��  STM32F407 + keil5 + HAL��
 **
 ** ����ֲ˵����  1- ��ʾ��������ֲ���LVGL
 **               2- ��ʾ��������ΪLVGL�Ļ���ģ�壬�������ٽ����������ܵ���ӡ�Gui Guider����ֲ
 **
 ** ��LVGL�ص㡿  ����ʹ��LVGLʱ���������ص㣺
 **               1- LVGL����ֲ�������ڴ���Դ���޸�;
 **               2- �ؼ�����ӡ�����
 **               3- ����¼�
 **               4- �¼��ص�������д
 **               5- ��Ļ�л�
 **               6- Gui Guider��ʹ�á���ֲ
 **
 ** �����¼�¼��  2024-04-08  ����font.h��������; ����ע��
 **
 ** ����ע˵����  ��Ȩ��ħŮ�Ƽ����У�����ѧϰ���ԣ��������ã�лл��
 **               https://demoboard.taobao.com
 **
 *******************************************************************************/
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "can.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* �����û����룬����д����Ե�BEGIN��ENDע����֮�䣬������������ʱ�ᱻɾ�� */
#include "bsp_UART.h"            // ��������   
#include "bsp_LCD_ILI9341.h"     // LCD����
#include "bsp_XPT2046.h"         // ��������
#include "bsp_W25Q128.h"         // �ⲿFlash, ���д�����У׼����

#include "lvgl.h"                // ��Ϊ����LVGL�ṩ�˸�������ͷ�ļ�����
#include "lv_port_disp.h"        // LVGL����ʾ֧��
#include "lv_port_indev.h"       // LVGL�Ĵ���֧��

#include "gui_guider.h"
#include "events_init.h"
lv_ui guider_ui;


#include "bsp_UART.h"            // ���ڵײ��ļ�; ����д�ó�ʼ�����շ������ú�������ʹ�ô���
#include "bsp_CAN.h"             // CANͨ�ŵ��Զ����ļ������壺���ͺ�����ɸѡ�����á��жϻص�����
#include "cybergear.h"    


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* �����û����룬����д����Ե�BEGIN��ENDע����֮�䣬������������ʱ�ᱻɾ�� */


/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_TIM6_Init();
  MX_CAN1_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
    /* �����û����룬����д����Ե�BEGIN��ENDע����֮�䣬������������ʱ�ᱻɾ�� */

    UART1_Init(115200);                                                           // ��ʼ��UART1

    printf("\r\r\r=========== STM32F407 �����ʼ���� ===========\r");             // ע�⣬printf�����������ض�������ʹ�ã��������Ῠ��; ��ʾ������дfputc, ��main.c�ĵײ�����
    printf("ϵͳ����ʱ�ӣ�           %d MHz\r", SystemCoreClock / 1000000);       // ���ϵͳ����ʱ�ӵ�Ƶ�ʣ��Լ���Ƿ���������

    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);              // LED���������øߵ�ƽ��������

    W25Q128_Init();                                                               // �ⲿFlash ��ʼ��; ���д�����У׼���ݡ�����ú�����ģ����

    LCD_Init();                                                                   // LCD ILI9341 ��ʼ��
    LCD_SetDir(1);                                                                // ������ʾ����0-������1-����

    XPT2046_Init(xLCD.width, xLCD.height, xLCD.dir);                              // ������� ��ʼ��

    lv_init();                                                                    // LVGL ��ʼ��
    lv_port_disp_init();                                                          // LVGL ��ʾ
    lv_port_indev_init();                                                         // LVGL ����   
    
    HAL_TIM_Base_Start_IT(&htim6);                                                // ����TIM6��ʹ���ж�;  ÿ�����ڽ����󴥷��жϣ�Ӳ���Զ������жϷ��������̶����ûص�����HAL_TIM_PeriodElapsedCallback()�������ֶ���д��main.c���·�

    //myLvglDemo();                                                                 // �����Զ���ĺ��������LVGL�������
		setup_ui(&guider_ui);
		events_init(&guider_ui);


		can_bsp_init();
		HAL_Delay(1000);
		
		init_cybergear(&mi_motor[1], 0x01, Motion_mode);//С�׵�� �˶�ģʽ
		HAL_Delay(500);
		stop_cybergear(&mi_motor[1], 0);
		HAL_Delay(500);
		set_zeropos_cybergear(&mi_motor[1]);
		HAL_Delay(500);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
    while (1)
    {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
        /* �����û����룬����д����Ե�BEGIN��ENDע����֮�䣬������������ʱ�ᱻɾ�� */

        /** 1ms��ʱ **/
        HAL_Delay(1 - 1);                                                  // ��ʱ������������ms; ע�⣺CubeMX���ɵ�HAL_Delay(), �����ڲ�Ϊ������Ч��������Դ������+1����ˣ����ֻ��Ҫ��ms��ʱ���鴫�����ʱ-1�������Ҫ�󼸰�ms�ķǾ�׼��ʱ���ǲ�����-1ҲӰ�첻��

        /** UART1 �Ƿ���յ����� **/
        if (UART1_GetRxNum())                                              // ��������ֽ���>0, ��Ϊ���յ���һ֡����
        {
            if (strstr((char *)UART1_GetRxData(), "XPT2046"))              // �ж��Ƿ��յ�"XPT2046", ���ô���������У׼����
            {
                XPT2046_ReCalibration();                                   // ���봥����У׼
            }
            UART1_ClearRx();                                               // ��0���ν���
        }
        
        /** ÿ5ms ���һ��LVGL���� **/
        static uint8_t msLVGL = 0;                                         // ����LVGL���������ʱ
        if (msLVGL++ >= 5)                                                 // ÿ5msִ��һ��
        {
            lv_timer_handler();                                            // ����LVGL�������������������������Ǽ��������ע�������ʱ�����ִ����Щ�ѵ��ڵ�����
            msLVGL = 0;                                                    // ������0
        }

        /** ÿ500ms��˸һ����ɫLED **/
        static uint16_t msLED = 0;
        if (++msLED == 500)                                                // ÿ500msִ��һ��
        {
            msLED = 0;                                                     // ������0
            HAL_GPIO_TogglePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin);          // ���ɵ���˸��ɫLED�������ⲿ�۲�ϵͳ�Ƿ���������
        }



    }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
/* �����û����룬����д����Ե�BEGIN��ENDע����֮�䣬������������ʱ�ᱻɾ�� */

/******************************************************************************
 * ��  ���� HAL_GPIO_EXTI_Callback
 * ��  �ܣ� EXTI�жϻص�����
 * ��  ���� uint16_t  GPIO_Pin    ���ű�ţ�������Χ��GPIO_Pin_0 ~ GPIO_Pin_15
 * ����ֵ�� ��
 * ��  ע�� CubeMX���ɵĴ�����˼ά�ͷ���ϣ���ʹ�ñ�׼���дʱ�кܴ������
 *          1������ǻص������������жϷ������������ĵ��ã�EXTIx_IRQHandler() > HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_x) > HAL_GPIO_EXTI_Callback(GPIO_PIN_x)
 *          2������ʹ������������ƣ���Ϊ����CubeMX����ʱ���ѱ�д���˸��ֺ������á�����������(��stm32xx_hal_gpio.c�ĵײ�); ��������ԭ��������������룬������д������
 *          3���ж����������󣬱��������Զ����ã���������˹�����; Ҳ��������жϱ�־��������ΪHAL_GPIO_EXTI_IRQHandler()���������в���;
 *          4�����ɵ�����EXTI�жϷ���������ͳһ������������������ű��������
 *          5���жϲ��������������ű�ţ�����֪�����ĸ��ⲿ�ж��߲������ж��ź�
******************************************************************************/
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == KEY_1_Pin)                                  // ����1 �������ж��źţ�KEY_1��PA0����ʱ����������ʱ�ߵ�ƽ�������ش���
    {
        HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);     // ��ת��ɫLED��
        XPT2046_ReCalibration();                                // ����������У׼
    }

    if (GPIO_Pin == KEY_2_Pin)                                  // ����2 �������ж��źţ�KEY_2��PA1����ʱ����������ʱ�͵�ƽ���½��ش���
    {
        HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);     // ��ת��ɫLED��
        printf("KEY_2 ����\r");                                 // ͨ���������������ʾ
    }

    if (GPIO_Pin == KEY_3_Pin)                                  // ����3 �������ж��źţ�KEY_3��PA4����ʱ���������µ͸ߵ�ƽ���½��ش���
    {
        HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);     // ��ת��ɫLED��
        printf("KEY_3 ����\r");                                 // ͨ���������������ʾ
    }
}



/******************************************************************************
 * ��  ���� HAL_TIM_PeriodElapsedCallback
 * ��  �ܣ� ���ڸ��»ص�����
 * ��  ע�� ��������TIM��CNT����жϻص�������
 *          ��TIM�ļ�����CNT�����1���ڼ���ʱ����(���ϼ�����CNT==ARR�����¼�����CNT==0);
 *          �����жϴ�����Ӳ���Զ���������жϷ��������̶����ñ�������
 *          ����TIM�����ڸ����жϣ����ǵ��ñ������������Ҫ�ں������ж�����һ��TIM�������ж�;
 * ��  ���� TIM_HandleTypeDef   *htim
 * ����ֵ�� ��
******************************************************************************/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM6)                     // �ж����ĸ�TIM�������ж�
    {
        lv_tick_inc(1);                             // ��LVGL�ṩ1ms������ʱ��

        static uint16_t ledTimes = 0;               // ����LED��˸��ʱ
        if (ledTimes++ >= 500)                      // ÿ500msִ��һ��LED��˸
        {
            HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_5);  // ��תLED���ŵĵ�ƽ������˸LED
            ledTimes = 0;                           // ��ʱ��0
        }
    }
}



/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1)
    {
    }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
