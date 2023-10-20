/*
 * Copyright (c) 2006-2023, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2023-10-19     RT-Thread    first version
 */

#include <rtthread.h>

#define DBG_TAG "main"
#define DBG_LVL DBG_LOG
#include <rtdbg.h>
#include "main.h"

#define THREAD1_PRIORITY                    26      //线程1
#define THREAD_STACK_SIZE                   512     //线程栈的深度
#define THREAD_TIMESLICE                    5       //线程的时间片

#define THREAD2_PRIORITY                    25      //线程2

//rt_device_t u5_dev;

//struct serial_configure u5_configs = RT_SERIAL_CONFIG_T_RH;

char led_flag = 1;
char LED_STA  = 0;
int rt_user_thread_entry(void);

int main(void)
{
//    rt_err_t ret = 0;

    HAL_Init();

    MX_GPIO_Init();
    MX_USART1_UART_Init();
    MX_UART5_Init();

    rt_user_thread_entry();

    LED_STA = 3;

//    u5_dev = rt_device_find("uart5");  //查找串口1设备句柄
//    if (u5_dev == RT_NULL) {
//        rt_kprintf("rt_device_find[uart5] failed... \r\n");
//        return -EINVAL;
//    }
//
//    ret = rt_device_open(u5_dev, RT_DEVICE_OFLAG_RDWR | RT_DEVICE_FLAG_INT_RX); //打开串口设备 （注意要以读写和接收中断的方式打开）
//    if (ret < 0) {
//        rt_kprintf("rt_devvice_open[uart5] failed... \r\n");
//        return ret;
//    }
//
//    rt_device_control(u5_dev, RT_DEVICE_CTRL_CONFIG, (void*)&u5_configs);   //将结构体取地址传入设备控制函数中，并将cmd设置为设备配置模式
//    /*
//     * *配置完成以后 如果我们想要发送数据 需要调用 rt_device_write 函数
//     * *其中第一个参数传入发送的设备
//     * *第二个参数为相对于buffer起始地址的偏移量（起始位置）
//     * *第三个参数为buff（要发送的内容），第四个参数为buff的大小
//     * */
//    rt_device_write(u5_dev, 0, "Uart5 config ... \r\n", rt_strlen("Uart5 config ... \r\n"));

    return RT_EOK;
}

/*
 * LED指示灯线程入口
 * LED模式指示
 * LED_STA = 0:LED0与LED1交替闪烁
 * LED_STA = 1:LED0和LED1灭
 * LED_STA = 2:LED0和LED1亮
 * LED_STA = 3:LED0和LED1同时闪烁
 * */
static void rt_led_state_entry(void *parameter){
    while(1){
        switch(LED_STA){
            case 0:{
                if (led_flag == 1) {
                    rt_kprintf("LED Alternating blinking mode\r\n");
                    led_flag = 0;
                    LED0(0);
                    LED1(1);
                }
                else if (led_flag == 0) {
                    LED0_TOGGLE;
                    LED1_TOGGLE;
                }
                rt_thread_mdelay(500);
            }break;
            case 1:{
                if (led_flag == 1) {
                    rt_kprintf("LED OFF\r\n");
                    led_flag = 0;
                }
                LED0(0);
                LED1(0);
            }break;
            case 2:{
                if (led_flag == 1) {
                    rt_kprintf("LED ON\r\n");
                    led_flag = 0;
                }
                LED0(1);
                LED1(1);
            }break;
            case 3:{
                if (led_flag == 1) {
                    rt_kprintf("LED Flashing at the same time\r\n");
                    led_flag = 0;
                    LED0(0);
                    LED1(0);
                }
                else if (led_flag == 0) {
                    LED0_TOGGLE;
                    LED1_TOGGLE;
                }
                rt_thread_mdelay(500);
            }
        }
    }
}

/*
 * user线程创建
 * */
int rt_user_thread_entry(void){
    static rt_thread_t result = NULL;
    /*创建一个线程，名称是rt_led,入口是rt_led_state_entry*/
    result = rt_thread_create("rt_led", rt_led_state_entry,
            NULL,
            THREAD_STACK_SIZE,
            THREAD1_PRIORITY,
            THREAD_TIMESLICE);
    if (result != RT_NULL){     //线程创建成功
        rt_thread_startup(result);
    }
    else{
        rt_kprintf("\r\nrt_led thread create failed\r\n");
    }
    return 0;
}


