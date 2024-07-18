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



void setup_scr_Control_Mode(lv_ui *ui)
{
	//Write codes Control_Mode
	ui->Control_Mode = lv_obj_create(NULL);
	lv_obj_set_size(ui->Control_Mode, 320, 240);
	lv_obj_set_scrollbar_mode(ui->Control_Mode, LV_SCROLLBAR_MODE_OFF);

	//Write style for Control_Mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Control_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Control_Mode_cont_1
	ui->Control_Mode_cont_1 = lv_obj_create(ui->Control_Mode);
	lv_obj_set_pos(ui->Control_Mode_cont_1, 0, 0);
	lv_obj_set_size(ui->Control_Mode_cont_1, 320, 240);
	lv_obj_set_scrollbar_mode(ui->Control_Mode_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for Control_Mode_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Control_Mode_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->Control_Mode_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->Control_Mode_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->Control_Mode_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Control_Mode_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Control_Mode_cont_1, lv_color_hex(0xb8b9e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Control_Mode_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Control_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Control_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Control_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Control_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Control_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Control_Mode_label_1
	ui->Control_Mode_label_1 = lv_label_create(ui->Control_Mode_cont_1);
	lv_label_set_text(ui->Control_Mode_label_1, "Motor Control Mode");
	lv_label_set_long_mode(ui->Control_Mode_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Control_Mode_label_1, 43, 2);
	lv_obj_set_size(ui->Control_Mode_label_1, 234, 32);

	//Write style for Control_Mode_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Control_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Control_Mode_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Control_Mode_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Control_Mode_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Control_Mode_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Control_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Control_Mode_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Control_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Control_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Control_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Control_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Control_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Control_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Control_Mode_Control_Home_Button
	ui->Control_Mode_Control_Home_Button = lv_btn_create(ui->Control_Mode_cont_1);
	ui->Control_Mode_Control_Home_Button_label = lv_label_create(ui->Control_Mode_Control_Home_Button);
	lv_label_set_text(ui->Control_Mode_Control_Home_Button_label, "Home");
	lv_label_set_long_mode(ui->Control_Mode_Control_Home_Button_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Control_Mode_Control_Home_Button_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Control_Mode_Control_Home_Button, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Control_Mode_Control_Home_Button_label, LV_PCT(100));
	lv_obj_set_pos(ui->Control_Mode_Control_Home_Button, 12, 199);
	lv_obj_set_size(ui->Control_Mode_Control_Home_Button, 60, 36);

	//Write style for Control_Mode_Control_Home_Button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Control_Mode_Control_Home_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Control_Mode_Control_Home_Button, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Control_Mode_Control_Home_Button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Control_Mode_Control_Home_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_Control_Home_Button, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Control_Mode_Control_Home_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Control_Mode_Control_Home_Button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Control_Mode_Control_Home_Button, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Control_Mode_Control_Home_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Control_Mode_Control_Home_Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Control_Mode_Control_Run_Button
	ui->Control_Mode_Control_Run_Button = lv_btn_create(ui->Control_Mode_cont_1);
	ui->Control_Mode_Control_Run_Button_label = lv_label_create(ui->Control_Mode_Control_Run_Button);
	lv_label_set_text(ui->Control_Mode_Control_Run_Button_label, "Run");
	lv_label_set_long_mode(ui->Control_Mode_Control_Run_Button_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Control_Mode_Control_Run_Button_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Control_Mode_Control_Run_Button, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Control_Mode_Control_Run_Button_label, LV_PCT(100));
	lv_obj_set_pos(ui->Control_Mode_Control_Run_Button, 122, 199);
	lv_obj_set_size(ui->Control_Mode_Control_Run_Button, 60, 36);

	//Write style for Control_Mode_Control_Run_Button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Control_Mode_Control_Run_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Control_Mode_Control_Run_Button, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Control_Mode_Control_Run_Button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Control_Mode_Control_Run_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_Control_Run_Button, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Control_Mode_Control_Run_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Control_Mode_Control_Run_Button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Control_Mode_Control_Run_Button, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Control_Mode_Control_Run_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Control_Mode_Control_Run_Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Control_Mode_Control_Stop_Button
	ui->Control_Mode_Control_Stop_Button = lv_btn_create(ui->Control_Mode_cont_1);
	ui->Control_Mode_Control_Stop_Button_label = lv_label_create(ui->Control_Mode_Control_Stop_Button);
	lv_label_set_text(ui->Control_Mode_Control_Stop_Button_label, "Stop");
	lv_label_set_long_mode(ui->Control_Mode_Control_Stop_Button_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Control_Mode_Control_Stop_Button_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Control_Mode_Control_Stop_Button, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Control_Mode_Control_Stop_Button_label, LV_PCT(100));
	lv_obj_set_pos(ui->Control_Mode_Control_Stop_Button, 232, 199);
	lv_obj_set_size(ui->Control_Mode_Control_Stop_Button, 60, 36);

	//Write style for Control_Mode_Control_Stop_Button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Control_Mode_Control_Stop_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Control_Mode_Control_Stop_Button, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Control_Mode_Control_Stop_Button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Control_Mode_Control_Stop_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_Control_Stop_Button, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Control_Mode_Control_Stop_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Control_Mode_Control_Stop_Button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Control_Mode_Control_Stop_Button, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Control_Mode_Control_Stop_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Control_Mode_Control_Stop_Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Control_Mode_Control_Torque_Slider
	ui->Control_Mode_Control_Torque_Slider = lv_slider_create(ui->Control_Mode_cont_1);
	lv_slider_set_range(ui->Control_Mode_Control_Torque_Slider, -5, 5);
	lv_slider_set_mode(ui->Control_Mode_Control_Torque_Slider, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->Control_Mode_Control_Torque_Slider, 0, LV_ANIM_OFF);
	lv_obj_set_pos(ui->Control_Mode_Control_Torque_Slider, 82, 32);
	lv_obj_set_size(ui->Control_Mode_Control_Torque_Slider, 160, 8);

	//Write style for Control_Mode_Control_Torque_Slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Control_Mode_Control_Torque_Slider, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Control_Mode_Control_Torque_Slider, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Control_Mode_Control_Torque_Slider, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_Control_Torque_Slider, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->Control_Mode_Control_Torque_Slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Control_Mode_Control_Torque_Slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Control_Mode_Control_Torque_Slider, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Control_Mode_Control_Torque_Slider, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Control_Mode_Control_Torque_Slider, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Control_Mode_Control_Torque_Slider, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_Control_Torque_Slider, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for Control_Mode_Control_Torque_Slider, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Control_Mode_Control_Torque_Slider, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Control_Mode_Control_Torque_Slider, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Control_Mode_Control_Torque_Slider, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_Control_Torque_Slider, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes Control_Mode_Control_Speed_Slider
	ui->Control_Mode_Control_Speed_Slider = lv_slider_create(ui->Control_Mode_cont_1);
	lv_slider_set_range(ui->Control_Mode_Control_Speed_Slider, -26, 26);
	lv_slider_set_mode(ui->Control_Mode_Control_Speed_Slider, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->Control_Mode_Control_Speed_Slider, 0, LV_ANIM_OFF);
	lv_obj_set_pos(ui->Control_Mode_Control_Speed_Slider, 82, 65);
	lv_obj_set_size(ui->Control_Mode_Control_Speed_Slider, 160, 8);

	//Write style for Control_Mode_Control_Speed_Slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Control_Mode_Control_Speed_Slider, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Control_Mode_Control_Speed_Slider, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Control_Mode_Control_Speed_Slider, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_Control_Speed_Slider, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->Control_Mode_Control_Speed_Slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Control_Mode_Control_Speed_Slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Control_Mode_Control_Speed_Slider, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Control_Mode_Control_Speed_Slider, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Control_Mode_Control_Speed_Slider, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Control_Mode_Control_Speed_Slider, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_Control_Speed_Slider, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for Control_Mode_Control_Speed_Slider, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Control_Mode_Control_Speed_Slider, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Control_Mode_Control_Speed_Slider, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Control_Mode_Control_Speed_Slider, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_Control_Speed_Slider, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes Control_Mode_Control_Position_Slider
	ui->Control_Mode_Control_Position_Slider = lv_slider_create(ui->Control_Mode_cont_1);
	lv_slider_set_range(ui->Control_Mode_Control_Position_Slider, -720, 720);
	lv_slider_set_mode(ui->Control_Mode_Control_Position_Slider, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->Control_Mode_Control_Position_Slider, 0, LV_ANIM_OFF);
	lv_obj_set_pos(ui->Control_Mode_Control_Position_Slider, 82, 98);
	lv_obj_set_size(ui->Control_Mode_Control_Position_Slider, 160, 8);

	//Write style for Control_Mode_Control_Position_Slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Control_Mode_Control_Position_Slider, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Control_Mode_Control_Position_Slider, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Control_Mode_Control_Position_Slider, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_Control_Position_Slider, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->Control_Mode_Control_Position_Slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Control_Mode_Control_Position_Slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Control_Mode_Control_Position_Slider, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Control_Mode_Control_Position_Slider, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Control_Mode_Control_Position_Slider, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Control_Mode_Control_Position_Slider, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_Control_Position_Slider, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for Control_Mode_Control_Position_Slider, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Control_Mode_Control_Position_Slider, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Control_Mode_Control_Position_Slider, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Control_Mode_Control_Position_Slider, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_Control_Position_Slider, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes Control_Mode_Control_Kp_Slider
	ui->Control_Mode_Control_Kp_Slider = lv_slider_create(ui->Control_Mode_cont_1);
	lv_slider_set_range(ui->Control_Mode_Control_Kp_Slider, 0, 100);
	lv_slider_set_mode(ui->Control_Mode_Control_Kp_Slider, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->Control_Mode_Control_Kp_Slider, 0, LV_ANIM_OFF);
	lv_obj_set_pos(ui->Control_Mode_Control_Kp_Slider, 82, 131);
	lv_obj_set_size(ui->Control_Mode_Control_Kp_Slider, 160, 8);

	//Write style for Control_Mode_Control_Kp_Slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Control_Mode_Control_Kp_Slider, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Control_Mode_Control_Kp_Slider, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Control_Mode_Control_Kp_Slider, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_Control_Kp_Slider, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->Control_Mode_Control_Kp_Slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Control_Mode_Control_Kp_Slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Control_Mode_Control_Kp_Slider, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Control_Mode_Control_Kp_Slider, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Control_Mode_Control_Kp_Slider, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Control_Mode_Control_Kp_Slider, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_Control_Kp_Slider, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for Control_Mode_Control_Kp_Slider, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Control_Mode_Control_Kp_Slider, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Control_Mode_Control_Kp_Slider, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Control_Mode_Control_Kp_Slider, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_Control_Kp_Slider, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes Control_Mode_Control_Kd_Slider
	ui->Control_Mode_Control_Kd_Slider = lv_slider_create(ui->Control_Mode_cont_1);
	lv_slider_set_range(ui->Control_Mode_Control_Kd_Slider, 0, 100);
	lv_slider_set_mode(ui->Control_Mode_Control_Kd_Slider, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->Control_Mode_Control_Kd_Slider, 0, LV_ANIM_OFF);
	lv_obj_set_pos(ui->Control_Mode_Control_Kd_Slider, 82, 164);
	lv_obj_set_size(ui->Control_Mode_Control_Kd_Slider, 160, 8);

	//Write style for Control_Mode_Control_Kd_Slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Control_Mode_Control_Kd_Slider, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Control_Mode_Control_Kd_Slider, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Control_Mode_Control_Kd_Slider, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_Control_Kd_Slider, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->Control_Mode_Control_Kd_Slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Control_Mode_Control_Kd_Slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Control_Mode_Control_Kd_Slider, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Control_Mode_Control_Kd_Slider, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Control_Mode_Control_Kd_Slider, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Control_Mode_Control_Kd_Slider, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_Control_Kd_Slider, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for Control_Mode_Control_Kd_Slider, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Control_Mode_Control_Kd_Slider, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Control_Mode_Control_Kd_Slider, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Control_Mode_Control_Kd_Slider, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_Control_Kd_Slider, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes Control_Mode_label_2
	ui->Control_Mode_label_2 = lv_label_create(ui->Control_Mode_cont_1);
	lv_label_set_text(ui->Control_Mode_label_2, "Torque");
	lv_label_set_long_mode(ui->Control_Mode_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Control_Mode_label_2, -4, 29);
	lv_obj_set_size(ui->Control_Mode_label_2, 100, 32);

	//Write style for Control_Mode_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Control_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Control_Mode_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Control_Mode_label_2, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Control_Mode_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Control_Mode_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Control_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Control_Mode_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Control_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Control_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Control_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Control_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Control_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Control_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Control_Mode_label_3
	ui->Control_Mode_label_3 = lv_label_create(ui->Control_Mode_cont_1);
	lv_label_set_text(ui->Control_Mode_label_3, "Speed");
	lv_label_set_long_mode(ui->Control_Mode_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Control_Mode_label_3, -4, 62);
	lv_obj_set_size(ui->Control_Mode_label_3, 100, 32);

	//Write style for Control_Mode_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Control_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Control_Mode_label_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Control_Mode_label_3, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Control_Mode_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Control_Mode_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Control_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Control_Mode_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Control_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Control_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Control_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Control_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Control_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Control_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Control_Mode_label_4
	ui->Control_Mode_label_4 = lv_label_create(ui->Control_Mode_cont_1);
	lv_label_set_text(ui->Control_Mode_label_4, "Position");
	lv_label_set_long_mode(ui->Control_Mode_label_4, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Control_Mode_label_4, -4, 95);
	lv_obj_set_size(ui->Control_Mode_label_4, 100, 32);

	//Write style for Control_Mode_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Control_Mode_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Control_Mode_label_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Control_Mode_label_4, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Control_Mode_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Control_Mode_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Control_Mode_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Control_Mode_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Control_Mode_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Control_Mode_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Control_Mode_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Control_Mode_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Control_Mode_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Control_Mode_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Control_Mode_label_5
	ui->Control_Mode_label_5 = lv_label_create(ui->Control_Mode_cont_1);
	lv_label_set_text(ui->Control_Mode_label_5, "Kp");
	lv_label_set_long_mode(ui->Control_Mode_label_5, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Control_Mode_label_5, -4, 128);
	lv_obj_set_size(ui->Control_Mode_label_5, 100, 32);

	//Write style for Control_Mode_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Control_Mode_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Control_Mode_label_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Control_Mode_label_5, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Control_Mode_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Control_Mode_label_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Control_Mode_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Control_Mode_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Control_Mode_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Control_Mode_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Control_Mode_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Control_Mode_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Control_Mode_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Control_Mode_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Control_Mode_label_6
	ui->Control_Mode_label_6 = lv_label_create(ui->Control_Mode_cont_1);
	lv_label_set_text(ui->Control_Mode_label_6, "Kd");
	lv_label_set_long_mode(ui->Control_Mode_label_6, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Control_Mode_label_6, -4, 161);
	lv_obj_set_size(ui->Control_Mode_label_6, 100, 32);

	//Write style for Control_Mode_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Control_Mode_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Control_Mode_label_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Control_Mode_label_6, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Control_Mode_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Control_Mode_label_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Control_Mode_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Control_Mode_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Control_Mode_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Control_Mode_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Control_Mode_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Control_Mode_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Control_Mode_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Control_Mode_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Control_Mode_Torque_Label
	ui->Control_Mode_Torque_Label = lv_label_create(ui->Control_Mode_cont_1);
	lv_label_set_text(ui->Control_Mode_Torque_Label, "0");
	lv_label_set_long_mode(ui->Control_Mode_Torque_Label, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Control_Mode_Torque_Label, 229, 29);
	lv_obj_set_size(ui->Control_Mode_Torque_Label, 100, 32);

	//Write style for Control_Mode_Torque_Label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Control_Mode_Torque_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_Torque_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Control_Mode_Torque_Label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Control_Mode_Torque_Label, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Control_Mode_Torque_Label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Control_Mode_Torque_Label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Control_Mode_Torque_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Control_Mode_Torque_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Control_Mode_Torque_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Control_Mode_Torque_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Control_Mode_Torque_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Control_Mode_Torque_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Control_Mode_Torque_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Control_Mode_Torque_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Control_Mode_Speed_Label
	ui->Control_Mode_Speed_Label = lv_label_create(ui->Control_Mode_cont_1);
	lv_label_set_text(ui->Control_Mode_Speed_Label, "0");
	lv_label_set_long_mode(ui->Control_Mode_Speed_Label, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Control_Mode_Speed_Label, 229, 62);
	lv_obj_set_size(ui->Control_Mode_Speed_Label, 100, 32);

	//Write style for Control_Mode_Speed_Label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Control_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Control_Mode_Speed_Label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Control_Mode_Speed_Label, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Control_Mode_Speed_Label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Control_Mode_Speed_Label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Control_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Control_Mode_Speed_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Control_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Control_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Control_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Control_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Control_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Control_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Control_Mode_Position_Label
	ui->Control_Mode_Position_Label = lv_label_create(ui->Control_Mode_cont_1);
	lv_label_set_text(ui->Control_Mode_Position_Label, "0");
	lv_label_set_long_mode(ui->Control_Mode_Position_Label, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Control_Mode_Position_Label, 229, 95);
	lv_obj_set_size(ui->Control_Mode_Position_Label, 100, 32);

	//Write style for Control_Mode_Position_Label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Control_Mode_Position_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_Position_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Control_Mode_Position_Label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Control_Mode_Position_Label, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Control_Mode_Position_Label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Control_Mode_Position_Label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Control_Mode_Position_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Control_Mode_Position_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Control_Mode_Position_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Control_Mode_Position_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Control_Mode_Position_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Control_Mode_Position_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Control_Mode_Position_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Control_Mode_Position_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Control_Mode_Kp_Label
	ui->Control_Mode_Kp_Label = lv_label_create(ui->Control_Mode_cont_1);
	lv_label_set_text(ui->Control_Mode_Kp_Label, "0");
	lv_label_set_long_mode(ui->Control_Mode_Kp_Label, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Control_Mode_Kp_Label, 229, 128);
	lv_obj_set_size(ui->Control_Mode_Kp_Label, 100, 32);

	//Write style for Control_Mode_Kp_Label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Control_Mode_Kp_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_Kp_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Control_Mode_Kp_Label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Control_Mode_Kp_Label, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Control_Mode_Kp_Label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Control_Mode_Kp_Label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Control_Mode_Kp_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Control_Mode_Kp_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Control_Mode_Kp_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Control_Mode_Kp_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Control_Mode_Kp_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Control_Mode_Kp_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Control_Mode_Kp_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Control_Mode_Kp_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Control_Mode_Kd_Label
	ui->Control_Mode_Kd_Label = lv_label_create(ui->Control_Mode_cont_1);
	lv_label_set_text(ui->Control_Mode_Kd_Label, "0");
	lv_label_set_long_mode(ui->Control_Mode_Kd_Label, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Control_Mode_Kd_Label, 229, 161);
	lv_obj_set_size(ui->Control_Mode_Kd_Label, 100, 32);

	//Write style for Control_Mode_Kd_Label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Control_Mode_Kd_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Control_Mode_Kd_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Control_Mode_Kd_Label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Control_Mode_Kd_Label, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Control_Mode_Kd_Label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Control_Mode_Kd_Label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Control_Mode_Kd_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Control_Mode_Kd_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Control_Mode_Kd_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Control_Mode_Kd_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Control_Mode_Kd_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Control_Mode_Kd_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Control_Mode_Kd_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Control_Mode_Kd_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of Control_Mode.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->Control_Mode);

	//Init events for screen.
	events_init_Control_Mode(ui);
}
