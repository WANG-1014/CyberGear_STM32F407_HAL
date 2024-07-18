#include "bsp_CAN.h"
#include "stdio.h"
#include "string.h"



xCAN_InfoDef  xCAN1 = {0};      // 定义一个数据结构体，用于管理收、发的数据和信息

/**
************************************************************************
* @brief:      	can_bsp_init(void)
* @param:       void
* @retval:     	void
* @details:    	CAN 使能
************************************************************************
**/
void can_bsp_init(void)
{
	CAN1_FilterInit();
	HAL_CAN_Start(&hcan1);                               //开启CAN
	HAL_CAN_ActivateNotification(&hcan1, 0);
}





/******************************************************************************
 * 函  数： CAN1_SendData
 * 功  能： CAN发送数据函数
 * 参  数： uint8_t* msgData   需发送数据的地址
 *          uint8_t  len       发送的字节数; 最大值：8
 * 返回值： 发送状态; 成功-0、错误-1、忙错误-2、超时-3   
 ******************************************************************************/
uint8_t CAN1_SendData(uint8_t *msgData, uint8_t len)
{ 
    // 定义两个变量
    static uint32_t TxMailbox = 0;                                                 // 用于记录发送成功时所用的邮箱编号：0~2; 被发送函数HAL_CAN_AddTxMessage()赋值
    static uint32_t txStatus  = 0;                                                 // 用于记录发送状态; 成功-0、错误-1、忙错误-2、超时-3; 同上，被发送函数HAL_CAN_AddTxMessage()赋值
    // 限制字节数
    if(len>8)                                                                      // 判断字节是否超过8字节
        len=8;                                                                     // 如果超过8字节，只发送前8个字节
    // 配置帧信息
    xCAN1.TxHeader.ExtId = CAN_TX_ID;                                              // 帧ID, 在bsp_CAN.h中定义
    xCAN1.TxHeader.IDE   = CAN_ID_EXT;                                             // 帧格式; 标准帧: CAN_ID_STD，注意修改上行为StdID; 扩展帧: CAN_ID_EXT, 注意修改上行为ExtID
    xCAN1.TxHeader.RTR   = CAN_RTR_DATA;                                           // 数据帧; 
    xCAN1.TxHeader.DLC   = len;                                                    // 数据字节数，
    xCAN1.TxHeader.TransmitGlobalTime = DISABLE;                                   // 使能时间戳添加到最后两个字节：Data[6]、Data[7]
    // 等待发送邮箱空闲
    while (HAL_CAN_GetTxMailboxesFreeLevel(&hcan1) == 0);                          // 每次发送前，要等待至有发送邮箱空闲。共有3个发送邮箱。如果返回值为0，即没有发送邮箱空闲，继续等    
    // 发送
    txStatus = HAL_CAN_AddTxMessage(&hcan1, &xCAN1.TxHeader, msgData, &TxMailbox); // 发送   
    // 返回发送状态
    return txStatus;                                                               // 返回发送状态; 成功-0、错误-1、忙错误-2、超时-3   
}





/******************************************************************************
 * 函  数： CAN1_FilterInit
 * 功  能： CAN1筛选器初始化
 * 备  注： 为方便调试，本函数配置为：接收所有数据帧，包括标准帧、扩展帧
 * 参  数： 无
 * 返回值： 无
 ******************************************************************************/
void CAN1_FilterInit(void)
{
      /* USER CODE BEGIN 2 */
	//CAN过滤器初始化
	CAN_FilterTypeDef can_filter_st;
	/*	can_filter_st.FilterActivation = ;
		can_filter_st.FilterBank = ;
		can_filter_st.FilterFIFOAssignment = ;
		can_filter_st.FilterIdHigh = ;
		can_filter_st.FilterIdLow = ;
		can_filter_st.FilterMaskIdHigh = ;
		can_filter_st.FilterMaskIdLow = ;
		can_filter_st.FilterMode = ;
		can_filter_st.FilterScale = ;
		can_filter_st.SlaveStartFilterBank = ;
		
    HAL_CAN_ConfigFilter(&hcan1, &can_filter_st);
	*/	
		
	
	
    can_filter_st.FilterActivation = ENABLE;
    can_filter_st.FilterMode = CAN_FILTERMODE_IDMASK;
    can_filter_st.FilterScale = CAN_FILTERSCALE_32BIT;
    can_filter_st.FilterIdHigh = 0x0000;
    can_filter_st.FilterIdLow = 0x0000;
    can_filter_st.FilterMaskIdHigh = 0x0000;
    can_filter_st.FilterMaskIdLow = 0x0000;
    can_filter_st.FilterBank = 0;
    can_filter_st.FilterFIFOAssignment = CAN_RX_FIFO0;
    can_filter_st.SlaveStartFilterBank = 14;
    HAL_CAN_ConfigFilter(&hcan1, &can_filter_st);
    HAL_CAN_Start(&hcan1);
    HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);
    
    // HAL_TIM_Base_Start_IT(&htim2);//定时中断初始化
  /* USER CODE END 2 */

}



/******************************************************************************
 * 函  数： HAL_CAN_RxFifo0MsgPendingCallback
 * 功  能： CAN接收中断的回调函数
 *          注意：只有在筛选器中，配置接收规则使用FiFO0时，接收到新一帧数据时才会触发此回调函数
 *          如果使用的是FIFO1, 就会触发HAL_CAN_RxFifo1MsgPendingCallback()
 * 参  数： CAN_HandleTypeDef  *CanNum  
 * 返回值： 无
 ******************************************************************************/
/*
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *CanNum)
{    
    memset(xCAN1.RxData, 0, 9);                                                  // 清0; 存放接收有效数据的数组; CAN一帧数据最大有效负载8字节，数组中开辟9个字节，是为了适配以字符串输出调试信息，最后的1字节0='\0'，是字符串结束符;   
    HAL_CAN_GetRxMessage(&hcan1, CAN_RX_FIFO0, &xCAN1.RxHeader, xCAN1.RxData);   // 把收到的数据存放到结构体备用，帧信息：RxHeader，数据：RxData
    xCAN1.RxNum = xCAN1.RxHeader.DLC;                                            // 接收字节数、标志位; 外部判断此值接收字节数是否大于0，以判断是否接收到新一帧数据
}
*/

// 文件结尾，需要保留至少1空行
