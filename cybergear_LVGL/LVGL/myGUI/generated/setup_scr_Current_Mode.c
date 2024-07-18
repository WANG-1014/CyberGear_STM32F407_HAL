/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



void setup_scr_Current_Mode(lv_ui *ui)
{
	//Write codes Current_Mode
	ui->Current_Mode = lv_obj_create(NULL);
	lv_obj_set_size(ui->Current_Mode, 320, 240);
	lv_obj_set_scrollbar_mode(ui->Current_Mode, LV_SCROLLBAR_MODE_OFF);

	//Write style for Current_Mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Current_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Current_Mode_cont_1
	ui->Current_Mode_cont_1 = lv_obj_create(ui->Current_Mode);
	lv_obj_set_pos(ui->Current_Mode_cont_1, 0, 0);
	lv_obj_set_size(ui->Current_Mode_cont_1, 320, 240);
	lv_obj_set_scrollbar_mode(ui->Current_Mode_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for Current_Mode_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Current_Mode_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->Current_Mode_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->Current_Mode_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->Current_Mode_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Current_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Current_Mode_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Current_Mode_cont_1, lv_color_hex(0xb8b9e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Current_Mode_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Current_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Current_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Current_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Current_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Current_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Current_Mode_label_1
	ui->Current_Mode_label_1 = lv_label_create(ui->Current_Mode_cont_1);
	lv_label_set_text(ui->Current_Mode_label_1, "Motor Current Mode");
	lv_label_set_long_mode(ui->Current_Mode_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Current_Mode_label_1, 54, 3);
	lv_obj_set_size(ui->Current_Mode_label_1, 206, 32);

	//Write style for Current_Mode_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Current_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Current_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Current_Mode_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Current_Mode_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Current_Mode_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Current_Mode_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Current_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Current_Mode_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Current_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Current_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Current_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Current_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Current_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Current_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Current_Mode_Current_Current_Slider
	ui->Current_Mode_Current_Current_Slider = lv_slider_create(ui->Current_Mode_cont_1);
	lv_slider_set_range(ui->Current_Mode_Current_Current_Slider, -22, 22);
	lv_slider_set_mode(ui->Current_Mode_Current_Current_Slider, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->Current_Mode_Current_Current_Slider, 0, LV_ANIM_OFF);
	lv_obj_set_pos(ui->Current_Mode_Current_Current_Slider, 72, 90);
	lv_obj_set_size(ui->Current_Mode_Current_Current_Slider, 160, 8);

	//Write style for Current_Mode_Current_Current_Slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Current_Mode_Current_Current_Slider, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Current_Mode_Current_Current_Slider, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Current_Mode_Current_Current_Slider, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Current_Mode_Current_Current_Slider, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->Current_Mode_Current_Current_Slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Current_Mode_Current_Current_Slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Current_Mode_Current_Current_Slider, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Current_Mode_Current_Current_Slider, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Current_Mode_Current_Current_Slider, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Current_Mode_Current_Current_Slider, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Current_Mode_Current_Current_Slider, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for Current_Mode_Current_Current_Slider, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Current_Mode_Current_Current_Slider, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Current_Mode_Current_Current_Slider, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Current_Mode_Current_Current_Slider, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Current_Mode_Current_Current_Slider, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes Current_Mode_label_2
	ui->Current_Mode_label_2 = lv_label_create(ui->Current_Mode_cont_1);
	lv_label_set_text(ui->Current_Mode_label_2, "Current");
	lv_label_set_long_mode(ui->Current_Mode_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Current_Mode_label_2, 104, 56);
	lv_obj_set_size(ui->Current_Mode_label_2, 100, 32);

	//Write style for Current_Mode_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Current_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Current_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Current_Mode_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Current_Mode_label_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Current_Mode_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Current_Mode_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Current_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Current_Mode_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Current_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Current_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Current_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Current_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Current_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Current_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Current_Mode_Current_Stop_Button
	ui->Current_Mode_Current_Stop_Button = lv_btn_create(ui->Current_Mode_cont_1);
	ui->Current_Mode_Current_Stop_Button_label = lv_label_create(ui->Current_Mode_Current_Stop_Button);
	lv_label_set_text(ui->Current_Mode_Current_Stop_Button_label, "Stop");
	lv_label_set_long_mode(ui->Current_Mode_Current_Stop_Button_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Current_Mode_Current_Stop_Button_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Current_Mode_Current_Stop_Button, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Current_Mode_Current_Stop_Button_label, LV_PCT(100));
	lv_obj_set_pos(ui->Current_Mode_Current_Stop_Button, 211, 184);
	lv_obj_set_size(ui->Current_Mode_Current_Stop_Button, 100, 50);

	//Write style for Current_Mode_Current_Stop_Button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Current_Mode_Current_Stop_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Current_Mode_Current_Stop_Button, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Current_Mode_Current_Stop_Button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Current_Mode_Current_Stop_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Current_Mode_Current_Stop_Button, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Current_Mode_Current_Stop_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Current_Mode_Current_Stop_Button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Current_Mode_Current_Stop_Button, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Current_Mode_Current_Stop_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Current_Mode_Current_Stop_Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Current_Mode_Current_Run_Button
	ui->Current_Mode_Current_Run_Button = lv_btn_create(ui->Current_Mode_cont_1);
	ui->Current_Mode_Current_Run_Button_label = lv_label_create(ui->Current_Mode_Current_Run_Button);
	lv_label_set_text(ui->Current_Mode_Current_Run_Button_label, "Run");
	lv_label_set_long_mode(ui->Current_Mode_Current_Run_Button_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Current_Mode_Current_Run_Button_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Current_Mode_Current_Run_Button, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Current_Mode_Current_Run_Button_label, LV_PCT(100));
	lv_obj_set_pos(ui->Current_Mode_Current_Run_Button, 109, 184);
	lv_obj_set_size(ui->Current_Mode_Current_Run_Button, 100, 50);

	//Write style for Current_Mode_Current_Run_Button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Current_Mode_Current_Run_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Current_Mode_Current_Run_Button, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Current_Mode_Current_Run_Button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Current_Mode_Current_Run_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Current_Mode_Current_Run_Button, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Current_Mode_Current_Run_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Current_Mode_Current_Run_Button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Current_Mode_Current_Run_Button, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Current_Mode_Current_Run_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Current_Mode_Current_Run_Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Current_Mode_Current_Home_Button
	ui->Current_Mode_Current_Home_Button = lv_btn_create(ui->Current_Mode_cont_1);
	ui->Current_Mode_Current_Home_Button_label = lv_label_create(ui->Current_Mode_Current_Home_Button);
	lv_label_set_text(ui->Current_Mode_Current_Home_Button_label, "Home");
	lv_label_set_long_mode(ui->Current_Mode_Current_Home_Button_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Current_Mode_Current_Home_Button_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Current_Mode_Current_Home_Button, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Current_Mode_Current_Home_Button_label, LV_PCT(100));
	lv_obj_set_pos(ui->Current_Mode_Current_Home_Button, 7, 184);
	lv_obj_set_size(ui->Current_Mode_Current_Home_Button, 100, 50);

	//Write style for Current_Mode_Current_Home_Button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Current_Mode_Current_Home_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Current_Mode_Current_Home_Button, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Current_Mode_Current_Home_Button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Current_Mode_Current_Home_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Current_Mode_Current_Home_Button, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Current_Mode_Current_Home_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Current_Mode_Current_Home_Button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Current_Mode_Current_Home_Button, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Current_Mode_Current_Home_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Current_Mode_Current_Home_Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Current_Mode_Current_Label
	ui->Current_Mode_Current_Label = lv_label_create(ui->Current_Mode_cont_1);
	lv_label_set_text(ui->Current_Mode_Current_Label, "0");
	lv_label_set_long_mode(ui->Current_Mode_Current_Label, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Current_Mode_Current_Label, 104, 116);
	lv_obj_set_size(ui->Current_Mode_Current_Label, 100, 32);

	//Write style for Current_Mode_Current_Label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Current_Mode_Current_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Current_Mode_Current_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Current_Mode_Current_Label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Current_Mode_Current_Label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Current_Mode_Current_Label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Current_Mode_Current_Label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Current_Mode_Current_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Current_Mode_Current_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Current_Mode_Current_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Current_Mode_Current_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Current_Mode_Current_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Current_Mode_Current_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Current_Mode_Current_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Current_Mode_Current_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of Current_Mode.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->Current_Mode);

	//Init events for screen.
	events_init_Current_Mode(ui);
}
