/* USER CODE BEGIN Header */
/***********************************************************************************************************************************
 ** �������д��  ħŮ�������Ŷ�
 ** ����    ����  ħŮ������       https://demoboard.taobao.com
 ***********************************************************************************************************************************
 ** ��ʵ�����ơ�  CAN1ͨ��_500Kbps
 **
 ** ������ƽ̨��  STM32F407 + keil5 + HAL�� 
 **
 ** �� CubeMX ��  1- ʹ��CubeMX����CAN��
 **               2- ��CAN1�Ĳ���ҳ�棬���ò�����Ϊ500Kbps: Prescaler-6��BS1-4��BS2-2��SJW-1; ����ģʽOperating Mode: Normal;
 **               3- ��CAN1���ж�ҳ�棬���жϣ�CAN1 RX0 interrupts
 **               4- CAN1������Ĭ������ΪPA11+PA12, �޸�ΪPB8_RX��PB9_TX
 **
 ** ��bsp_CAN��   CubeMX����CAN1���������ɺ󣬻�����can.c��can.h������main.c�е�����MX_CAN1_Init(), �����������š�CAN���ã��������˳�ʼ����
 **               �û���Ҫ��CubeMX���ɵĴ�������ϣ��������ӱ�д���͡����յĴ�����롣
 **               ���ǰ�����CANͨ�ŵ��Զ�����룬д���������½���bsp_CAN.h��bsp_CAN.c�ļ���; ���������ô��ж���
 **               1- ʹ�����ֱ��: �ײ����ô���ԭ�ⲻ����can.c��h��, ��Ӧ�ô�������bsp_CAN.c��h��;
 **               2- ��������Ĺ��̣�CubeMXû��ʹ��CAN���������ɺ��ɾ��can.c��h�ļ���������Զ���ͨ�Ŵ���д�����У�Ҳ�����ļ���ɾ���������ڴ����պ��ٴ�ʹ��;
 **
 ** ����ֲ˵����  1- ���Ʊ����̵�CAN�ļ��У���Ŀ�깤���ļ�����;
 **               2- ���ͷ�ļ�·���� Keil > Option > C/C++ > Include Paths;
 **               3- ���C�ļ�������: Keil > ��๤�̹�������˫��Ŀ���ļ��� > ѡ�� bsp_CAN.c;
 **               4- ����ļ�����:    #include "bsp_CAN.h�������ĸ��ļ�����Ҫʹ���亯�����ܣ�����������ļ������������;
 **
 ** ������ʹ�á�  1- ��ʼ���Ĵ���: CubeMX�����ɺ��ˣ����������޸ġ���ɾ;
 **               2- ɸѡ��������: ��bsp_CAN.c�У���д��һ��ʾ�����������ü��ɣ�������������֡��������׼֡����չ֡
 **               3- ���뿪��CAN1: ����HAL���� HAL_CAN_Start(&hcan1) �����������������Զ����ɸѡ�������е���;
 **               4- ���ͣ���д��һ���Զ���ķ��ͺ������ں��������ñ��ĸ�ʽ����Ҫ����ʱ���ݣ����ú����������ݼ���, �ɰ����޸�;
 **               5- ���գ���д���Զ�����жϽ��ջص���������bsp_CAN.c�С��ڽ��յ���֡�������Զ�ת�浽xCAN1�ṹ�壬�ⲿֻ����xCAN1.RXNum > 0����ʾ�ѽ��յ������ݣ�ʹ�÷������main.c��ʹ��ʾ����
 **               6- ɸѡ�������ã���CANͨ���бȽ������Ĺؼ��㣡�б�ģʽ������ģʽ����ʮ��ƪ����ɸѡ�����õ����£��������͸����
 **
 ** ���� �� �㡿  CAN1���������ţ�Ĭ�ϵ�PA11+PA12��PB8+PB9, ע�ⲻҪѡ����;
 **               �ܶ������Ⲩ���ʵļ�����⡣���ֲ���̫�����乫ʽ��ԭ��ֱ����csdn�����¡����������ɡ�����ȥȥ�����Ǽ������ò������ˣ�û��Ҫ��ʱ�䡣
 **               ���ڷ��ͣ��ܶ�̳̻ὲ�ⷢ�������ʹ�ã������ǣ�д��֡��ʽ��ֱ�ӵ��÷��ͺ������ˣ�����������ưɣ�
 **               ���ڽ��գ�ͬ�ϣ��ܶ�̳̻Ứ������ʱ�佲�������������FIFO��ԭ��, �����ǣ�ֻ����ɸѡ���о������ĸ�FIFO, �յ����ݺ�Ѹ�ٴ����ɡ� 
 **               ɸѡ����������ã�����CANͨ��ѧϰ�е�����֮�أ��Ƚ�����⣬�������csdn���£�����Ҫ���͸����
 **               ���ڴ���֡���Զ����ߴ������߻��ѵȣ��ⷽ�����±Ƚ��١�������Ŀ����Ҫ���ʹ��CANʱ������Ҫ�ټĴ������������ˣ������и�����⡣
 **
 *******************************************************************************/
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "can.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* �û����룬����д����Ե�BEGIN��END֮�䣬����CubeMX�������ɺ󣬻ᱻɾ���� */

#include "stdio.h"               // ����sprintf�Ⱥ���
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
  MX_USART1_UART_Init();
  MX_CAN1_Init();
  /* USER CODE BEGIN 2 */
    /* �û����룬����д����Ե�BEGIN��END֮�� */

    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);       // �����øߵ�ƽ��������

    UART1_Init(115200);                                                    // ��ʼ�� ����1; ��д�õײ㣬����h�еĺ�������ʹ��; ����(PA9 +PA10)��������-None-8-1; ���ʹ��CubeMX���ã���ʹ��ǰ�����ţ�������Ҫ��MX�Ͻ����жϼ�DMA���ã������ͻ

    can_bsp_init();
		// CAN1_FilterInit();                                                     // ��ʼ��CAN1��ɸѡ��; Ϊ������ԣ�����������Ϊ��������������֡��������׼֡����չ֡
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	
	HAL_Delay(1000);
	// init_cybergear(&mi_motor[1], 0x01, Motion_mode);//С�׵�� �˿�ģʽ
	init_cybergear(&mi_motor[1], 0x01, Position_mode);//С�׵�� λ��ģʽ
	// init_cybergear(&mi_motor[1], 0x01, Speed_mode);//С�׵�� �ٶ�ģʽ
	// init_cybergear(&mi_motor[1], 0x01, Current_mode);//С�׵�� ����ģʽ
	
    while (1)
    {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
			
			/*�˿�ģʽ*/
			//motor_controlmode(&mi_motor[1], 0, 1.5, 1, 5, 0.5);  
			//HAL_Delay(300);
			//motor_controlmode(&mi_motor[1], 0, 0, 1, 5, 0.5);  
			//HAL_Delay(1000);
			
			/*λ��ģʽ*/
			set_position_cybergear(&mi_motor[1], 10.0, 5, 8, 40);
			HAL_Delay(3000);
			set_position_cybergear(&mi_motor[1], -10.0, 5, 8, 40);
			HAL_Delay(3000);
			
			/*�ٶ�ģʽ*/
			//set_speed_cybergear(&mi_motor[1], 2.0);
			//HAL_Delay(500);
			//set_speed_cybergear(&mi_motor[1], -2.0);
			//HAL_Delay(500);
    
			/*����ģʽ*/
			//set_current_cybergear(&mi_motor[1], 0.4);
			//HAL_Delay(6000);
			//set_current_cybergear(&mi_motor[1], -0.4);
			//HAL_Delay(6000);
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
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 168;
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
/* �����û����룬����д����Ե�BEGIN��END֮�� */

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
        printf("KEY_1 ����\r");                                 // ͨ���������������ʾ
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
    /* User can add his own implementation to report the file name and linerxNumber,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
