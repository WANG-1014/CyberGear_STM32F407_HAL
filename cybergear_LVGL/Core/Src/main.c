/* USER CODE BEGIN Header */
/***********************************************************************************************************************************
 ** 【代码编写】  魔女开发板团队
 ** 【淘    宝】  魔女开发板       https://demoboard.taobao.com
 ***********************************************************************************************************************************
 ** 【实验名称】  LVGL 移植测试
 **
 ** 【适用平台】  STM32F407 + keil5 + HAL库
 **
 ** 【移植说明】  1- 本示例，已移植完成LVGL
 **               2- 本示例，可作为LVGL的基础模板，在其上再进行其它功能的添加、Gui Guider的移植
 **
 ** 【LVGL重点】  新手使用LVGL时，就四项重点：
 **               1- LVGL的移植，管理内存和显存的修改;
 **               2- 控件的添加、对齐
 **               3- 添加事件
 **               4- 事件回调函数编写
 **               5- 屏幕切换
 **               6- Gui Guider的使用、移植
 **
 ** 【更新记录】  2024-04-08  完善font.h数组命名; 完善注释
 **
 ** 【备注说明】  版权归魔女科技所有，限于学习测试，切勿商用，谢谢！
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
/* 所有用户代码，必须写在配对的BEGIN与END注释行之间，否则重新生成时会被删除 */
#include "bsp_UART.h"            // 串口驱动   
#include "bsp_LCD_ILI9341.h"     // LCD驱动
#include "bsp_XPT2046.h"         // 触屏驱动
#include "bsp_W25Q128.h"         // 外部Flash, 存有触屏的校准数据

#include "lvgl.h"                // 它为整个LVGL提供了更完整的头文件引用
#include "lv_port_disp.h"        // LVGL的显示支持
#include "lv_port_indev.h"       // LVGL的触屏支持

#include "gui_guider.h"
#include "events_init.h"
lv_ui guider_ui;


#include "bsp_UART.h"            // 串口底层文件; 已重写好初始化、收发，调用函数即可使用串口
#include "bsp_CAN.h"             // CAN通信的自定义文件，包插：发送函数、筛选器配置、中断回调函数
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
/* 所有用户代码，必须写在配对的BEGIN与END注释行之间，否则重新生成时会被删除 */


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
    /* 所有用户代码，必须写在配对的BEGIN与END注释行之间，否则重新生成时会被删除 */

    UART1_Init(115200);                                                           // 初始化UART1

    printf("\r\r\r=========== STM32F407 外设初始报告 ===========\r");             // 注意，printf函数，必须重定向后才能使用，否则程序会卡死; 本示例已重写fputc, 在main.c的底部附近
    printf("系统运行时钟：           %d MHz\r", SystemCoreClock / 1000000);       // 输出系统运行时钟的频率，以检查是否配置正常

    HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, GPIO_PIN_RESET);              // LED控制引脚置高电平，红亮灭

    W25Q128_Init();                                                               // 外部Flash 初始化; 存有触屏的校准数据、裸机用汉字字模数据

    LCD_Init();                                                                   // LCD ILI9341 初始化
    LCD_SetDir(1);                                                                // 设置显示方向：0-竖屏、1-横屏

    XPT2046_Init(xLCD.width, xLCD.height, xLCD.dir);                              // 触摸检测 初始化

    lv_init();                                                                    // LVGL 初始化
    lv_port_disp_init();                                                          // LVGL 显示
    lv_port_indev_init();                                                         // LVGL 触屏   
    
    HAL_TIM_Base_Start_IT(&htim6);                                                // 启动TIM6并使能中断;  每个周期结束后触发中断，硬件自动调用中断服务函数，继而调用回调函数HAL_TIM_PeriodElapsedCallback()，它已手动编写在main.c的下方

    //myLvglDemo();                                                                 // 调用自定义的函数，完成LVGL界面设计
		setup_ui(&guider_ui);
		events_init(&guider_ui);


		can_bsp_init();
		HAL_Delay(1000);
		
		init_cybergear(&mi_motor[1], 0x01, Motion_mode);//小米电机 运动模式
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
        /* 所有用户代码，必须写在配对的BEGIN与END注释行之间，否则重新生成时会被删除 */

        /** 1ms延时 **/
        HAL_Delay(1 - 1);                                                  // 延时函数，参数：ms; 注意：CubeMX生成的HAL_Delay(), 函数内部为避免无效操作，会对传入参数+1，因此，如果只需要几ms延时建议传入参数时-1，如果需要大几百ms的非精准延时，那参数不-1也影响不大

        /** UART1 是否接收到数据 **/
        if (UART1_GetRxNum())                                              // 如果接收字节数>0, 即为接收到新一帧数据
        {
            if (strstr((char *)UART1_GetRxData(), "XPT2046"))              // 判断是否收到"XPT2046", 调用触摸屏重新校准函数
            {
                XPT2046_ReCalibration();                                   // 进入触摸屏校准
            }
            UART1_ClearRx();                                               // 清0本次接收
        }
        
        /** 每5ms 检测一次LVGL任务 **/
        static uint8_t msLVGL = 0;                                         // 用于LVGL周期任务计时
        if (msLVGL++ >= 5)                                                 // 每5ms执行一次
        {
            lv_timer_handler();                                            // 调用LVGL的周期性任务函数，它的作用是检查所有已注册任务的时间戳，执行那些已到期的任务
            msLVGL = 0;                                                    // 计数清0
        }

        /** 每500ms闪烁一次蓝色LED **/
        static uint16_t msLED = 0;
        if (++msLED == 500)                                                // 每500ms执行一次
        {
            msLED = 0;                                                     // 计数清0
            HAL_GPIO_TogglePin(LED_BLUE_GPIO_Port, LED_BLUE_Pin);          // 规律地闪烁蓝色LED，方便外部观察系统是否正常运行
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
/* 所有用户代码，必须写在配对的BEGIN与END注释行之间，否则重新生成时会被删除 */

/******************************************************************************
 * 函  数： HAL_GPIO_EXTI_Callback
 * 功  能： EXTI中断回调函数
 * 参  数： uint16_t  GPIO_Pin    引脚编号，参数范围：GPIO_Pin_0 ~ GPIO_Pin_15
 * 返回值： 无
 * 备  注： CubeMX生成的代码在思维和风格上，与使用标准库编写时有很大的区别：
 *          1：这个是回调函数，不是中断服务函数。完整的调用：EXTIx_IRQHandler() > HAL_GPIO_EXTI_IRQHandler(GPIO_PIN_x) > HAL_GPIO_EXTI_Callback(GPIO_PIN_x)
 *          2：必须使用这个函数名称，因为它在CubeMX生成时，已被写好了各种函数调用、函数弱定义(在stm32xx_hal_gpio.c的底部); 不建议在原弱定义中增添代码，而是重写本函数
 *          3：中断条件触发后，本函数被自动调用，无需进行人工调用; 也无需进行中断标志的清理，因为HAL_GPIO_EXTI_IRQHandler()函数中已有操作;
 *          4：生成的所有EXTI中断服务函数，都统一调用这个函数，以引脚编号作参数
 *          5：判断参数传进来的引脚编号，即可知道是哪个外部中断线产生的中断信号
******************************************************************************/
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == KEY_1_Pin)                                  // 按键1 产生的中断信号：KEY_1、PA0、闲时下拉、按下时高电平、上升沿触发
    {
        HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);     // 反转红色LED灯
        XPT2046_ReCalibration();                                // 触摸屏重新校准
    }

    if (GPIO_Pin == KEY_2_Pin)                                  // 按键2 产生的中断信号：KEY_2、PA1、闲时上拉、按下时低电平、下降沿触发
    {
        HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);     // 反转红色LED灯
        printf("KEY_2 按下\r");                                 // 通过串口助手输出提示
    }

    if (GPIO_Pin == KEY_3_Pin)                                  // 按键3 产生的中断信号：KEY_3、PA4、闲时上拉、按下低高电平、下降沿触发
    {
        HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);     // 反转红色LED灯
        printf("KEY_3 按下\r");                                 // 通过串口助手输出提示
    }
}



/******************************************************************************
 * 函  数： HAL_TIM_PeriodElapsedCallback
 * 功  能： 周期更新回调函数
 * 备  注： 本函数是TIM的CNT溢出中断回调函数。
 *          当TIM的计数器CNT，完成1周期计数时触发(向上计数：CNT==ARR、向下计数：CNT==0);
 *          上述中断触发后，硬件自动调用相关中断服务函数，继而调用本函数。
 *          所有TIM的周期更新中断，都是调用本函数，因此需要在函数内判断是哪一个TIM触发的中断;
 * 参  数： TIM_HandleTypeDef   *htim
 * 返回值： 无
******************************************************************************/
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM6)                     // 判断是哪个TIM产生的中断
    {
        lv_tick_inc(1);                             // 给LVGL提供1ms的心跳时期

        static uint16_t ledTimes = 0;               // 用于LED闪烁计时
        if (ledTimes++ >= 500)                      // 每500ms执行一次LED闪烁
        {
            HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_5);  // 反转LED引脚的电平，即闪烁LED
            ledTimes = 0;                           // 计时清0
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
