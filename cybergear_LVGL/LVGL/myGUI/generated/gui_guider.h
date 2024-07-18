/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *Zero_Mode;
	bool Zero_Mode_del;
	lv_obj_t *Zero_Mode_cont_1;
	lv_obj_t *Zero_Mode_label_1;
	lv_obj_t *Zero_Mode_Home_Button;
	lv_obj_t *Zero_Mode_Home_Button_label;
	lv_obj_t *Zero_Mode_Run_Zero_Button;
	lv_obj_t *Zero_Mode_Run_Zero_Button_label;
	lv_obj_t *Zero_Mode_Set_Zero_Button;
	lv_obj_t *Zero_Mode_Set_Zero_Button_label;
	lv_obj_t *Position_Mode;
	bool Position_Mode_del;
	lv_obj_t *Position_Mode_cont_1;
	lv_obj_t *Position_Mode_Position_Home_Button;
	lv_obj_t *Position_Mode_Position_Home_Button_label;
	lv_obj_t *Position_Mode_Position_Run_Button;
	lv_obj_t *Position_Mode_Position_Run_Button_label;
	lv_obj_t *Position_Mode_Position_Stop_Button;
	lv_obj_t *Position_Mode_Position_Stop_Button_label;
	lv_obj_t *Position_Mode_label_1;
	lv_obj_t *Position_Mode_Position_Speed_Slider;
	lv_obj_t *Position_Mode_Position_Position_Slider;
	lv_obj_t *Position_Mode_Speed_Label;
	lv_obj_t *Position_Mode_Position_Label;
	lv_obj_t *Position_Mode_label_2;
	lv_obj_t *Position_Mode_label_3;
	lv_obj_t *Speed_Mode;
	bool Speed_Mode_del;
	lv_obj_t *Speed_Mode_cont_1;
	lv_obj_t *Speed_Mode_label_1;
	lv_obj_t *Speed_Mode_Speed_Speed_Slider;
	lv_obj_t *Speed_Mode_Speed_Current_Slider;
	lv_obj_t *Speed_Mode_label_2;
	lv_obj_t *Speed_Mode_label_3;
	lv_obj_t *Speed_Mode_Speed_Label;
	lv_obj_t *Speed_Mode_Current_Label;
	lv_obj_t *Speed_Mode_Speed_Home_Button;
	lv_obj_t *Speed_Mode_Speed_Home_Button_label;
	lv_obj_t *Speed_Mode_Speed_Run_Button;
	lv_obj_t *Speed_Mode_Speed_Run_Button_label;
	lv_obj_t *Speed_Mode_Speed_Stop_Button;
	lv_obj_t *Speed_Mode_Speed_Stop_Button_label;
	lv_obj_t *Current_Mode;
	bool Current_Mode_del;
	lv_obj_t *Current_Mode_cont_1;
	lv_obj_t *Current_Mode_label_1;
	lv_obj_t *Current_Mode_Current_Current_Slider;
	lv_obj_t *Current_Mode_label_2;
	lv_obj_t *Current_Mode_Current_Stop_Button;
	lv_obj_t *Current_Mode_Current_Stop_Button_label;
	lv_obj_t *Current_Mode_Current_Run_Button;
	lv_obj_t *Current_Mode_Current_Run_Button_label;
	lv_obj_t *Current_Mode_Current_Home_Button;
	lv_obj_t *Current_Mode_Current_Home_Button_label;
	lv_obj_t *Current_Mode_Current_Label;
	lv_obj_t *Control_Mode;
	bool Control_Mode_del;
	lv_obj_t *Control_Mode_cont_1;
	lv_obj_t *Control_Mode_label_1;
	lv_obj_t *Control_Mode_Control_Home_Button;
	lv_obj_t *Control_Mode_Control_Home_Button_label;
	lv_obj_t *Control_Mode_Control_Run_Button;
	lv_obj_t *Control_Mode_Control_Run_Button_label;
	lv_obj_t *Control_Mode_Control_Stop_Button;
	lv_obj_t *Control_Mode_Control_Stop_Button_label;
	lv_obj_t *Control_Mode_Control_Torque_Slider;
	lv_obj_t *Control_Mode_Control_Speed_Slider;
	lv_obj_t *Control_Mode_Control_Position_Slider;
	lv_obj_t *Control_Mode_Control_Kp_Slider;
	lv_obj_t *Control_Mode_Control_Kd_Slider;
	lv_obj_t *Control_Mode_label_2;
	lv_obj_t *Control_Mode_label_3;
	lv_obj_t *Control_Mode_label_4;
	lv_obj_t *Control_Mode_label_5;
	lv_obj_t *Control_Mode_label_6;
	lv_obj_t *Control_Mode_Torque_Label;
	lv_obj_t *Control_Mode_Speed_Label;
	lv_obj_t *Control_Mode_Position_Label;
	lv_obj_t *Control_Mode_Kp_Label;
	lv_obj_t *Control_Mode_Kd_Label;
	lv_obj_t *Menu;
	bool Menu_del;
	lv_obj_t *Menu_cont_1;
	lv_obj_t *Menu_label_1;
	lv_obj_t *Menu_Zero_Mode_Button;
	lv_obj_t *Menu_Zero_Mode_Button_label;
	lv_obj_t *Menu_Position_Mode_Button;
	lv_obj_t *Menu_Position_Mode_Button_label;
	lv_obj_t *Menu_Speed_Mode_Button;
	lv_obj_t *Menu_Speed_Mode_Button_label;
	lv_obj_t *Menu_Current_Mode_Button;
	lv_obj_t *Menu_Current_Mode_Button_label;
	lv_obj_t *Menu_Control_Mode_Button;
	lv_obj_t *Menu_Control_Mode_Button_label;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_move_animation(void * var, int32_t duration, int32_t delay, int32_t x_end, int32_t y_end, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_scale_animation(void * var, int32_t duration, int32_t delay, int32_t width, int32_t height, lv_anim_path_cb_t path_cb,
                        uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                        lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_zoom_animation(void * var, int32_t duration, int32_t delay, int32_t zoom, lv_anim_path_cb_t path_cb,
                           uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                           lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void ui_img_rotate_animation(void * var, int32_t duration, int32_t delay, lv_coord_t x, lv_coord_t y, int32_t rotate,
                   lv_anim_path_cb_t path_cb, uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time,
                   uint32_t playback_delay, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);

void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);


extern lv_ui guider_ui;


void setup_scr_Zero_Mode(lv_ui *ui);
void setup_scr_Position_Mode(lv_ui *ui);
void setup_scr_Speed_Mode(lv_ui *ui);
void setup_scr_Current_Mode(lv_ui *ui);
void setup_scr_Control_Mode(lv_ui *ui);
void setup_scr_Menu(lv_ui *ui);

LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_14)


#ifdef __cplusplus
}
#endif
#endif
