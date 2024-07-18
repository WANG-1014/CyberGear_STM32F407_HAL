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



void setup_scr_Position_Mode(lv_ui *ui)
{
	//Write codes Position_Mode
	ui->Position_Mode = lv_obj_create(NULL);
	lv_obj_set_size(ui->Position_Mode, 320, 240);
	lv_obj_set_scrollbar_mode(ui->Position_Mode, LV_SCROLLBAR_MODE_OFF);

	//Write style for Position_Mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Position_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Position_Mode_cont_1
	ui->Position_Mode_cont_1 = lv_obj_create(ui->Position_Mode);
	lv_obj_set_pos(ui->Position_Mode_cont_1, 0, 0);
	lv_obj_set_size(ui->Position_Mode_cont_1, 320, 240);
	lv_obj_set_scrollbar_mode(ui->Position_Mode_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for Position_Mode_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Position_Mode_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->Position_Mode_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->Position_Mode_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->Position_Mode_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Position_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Position_Mode_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Position_Mode_cont_1, lv_color_hex(0xb8b9e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Position_Mode_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Position_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Position_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Position_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Position_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Position_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Position_Mode_Position_Home_Button
	ui->Position_Mode_Position_Home_Button = lv_btn_create(ui->Position_Mode_cont_1);
	ui->Position_Mode_Position_Home_Button_label = lv_label_create(ui->Position_Mode_Position_Home_Button);
	lv_label_set_text(ui->Position_Mode_Position_Home_Button_label, "Home");
	lv_label_set_long_mode(ui->Position_Mode_Position_Home_Button_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Position_Mode_Position_Home_Button_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Position_Mode_Position_Home_Button, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Position_Mode_Position_Home_Button_label, LV_PCT(100));
	lv_obj_set_pos(ui->Position_Mode_Position_Home_Button, 2, 178);
	lv_obj_set_size(ui->Position_Mode_Position_Home_Button, 100, 50);

	//Write style for Position_Mode_Position_Home_Button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Position_Mode_Position_Home_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Position_Mode_Position_Home_Button, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Position_Mode_Position_Home_Button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Position_Mode_Position_Home_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Position_Mode_Position_Home_Button, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Position_Mode_Position_Home_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Position_Mode_Position_Home_Button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Position_Mode_Position_Home_Button, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Position_Mode_Position_Home_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Position_Mode_Position_Home_Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Position_Mode_Position_Run_Button
	ui->Position_Mode_Position_Run_Button = lv_btn_create(ui->Position_Mode_cont_1);
	ui->Position_Mode_Position_Run_Button_label = lv_label_create(ui->Position_Mode_Position_Run_Button);
	lv_label_set_text(ui->Position_Mode_Position_Run_Button_label, "Run");
	lv_label_set_long_mode(ui->Position_Mode_Position_Run_Button_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Position_Mode_Position_Run_Button_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Position_Mode_Position_Run_Button, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Position_Mode_Position_Run_Button_label, LV_PCT(100));
	lv_obj_set_pos(ui->Position_Mode_Position_Run_Button, 107, 178);
	lv_obj_set_size(ui->Position_Mode_Position_Run_Button, 100, 50);

	//Write style for Position_Mode_Position_Run_Button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Position_Mode_Position_Run_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Position_Mode_Position_Run_Button, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Position_Mode_Position_Run_Button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Position_Mode_Position_Run_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Position_Mode_Position_Run_Button, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Position_Mode_Position_Run_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Position_Mode_Position_Run_Button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Position_Mode_Position_Run_Button, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Position_Mode_Position_Run_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Position_Mode_Position_Run_Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Position_Mode_Position_Stop_Button
	ui->Position_Mode_Position_Stop_Button = lv_btn_create(ui->Position_Mode_cont_1);
	ui->Position_Mode_Position_Stop_Button_label = lv_label_create(ui->Position_Mode_Position_Stop_Button);
	lv_label_set_text(ui->Position_Mode_Position_Stop_Button_label, "Stop");
	lv_label_set_long_mode(ui->Position_Mode_Position_Stop_Button_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Position_Mode_Position_Stop_Button_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Position_Mode_Position_Stop_Button, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Position_Mode_Position_Stop_Button_label, LV_PCT(100));
	lv_obj_set_pos(ui->Position_Mode_Position_Stop_Button, 212, 178);
	lv_obj_set_size(ui->Position_Mode_Position_Stop_Button, 100, 50);

	//Write style for Position_Mode_Position_Stop_Button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Position_Mode_Position_Stop_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Position_Mode_Position_Stop_Button, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Position_Mode_Position_Stop_Button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Position_Mode_Position_Stop_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Position_Mode_Position_Stop_Button, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Position_Mode_Position_Stop_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Position_Mode_Position_Stop_Button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Position_Mode_Position_Stop_Button, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Position_Mode_Position_Stop_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Position_Mode_Position_Stop_Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Position_Mode_label_1
	ui->Position_Mode_label_1 = lv_label_create(ui->Position_Mode_cont_1);
	lv_label_set_text(ui->Position_Mode_label_1, "Motor Position Mode\n");
	lv_label_set_long_mode(ui->Position_Mode_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Position_Mode_label_1, 47, 2);
	lv_obj_set_size(ui->Position_Mode_label_1, 226, 32);

	//Write style for Position_Mode_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Position_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Position_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Position_Mode_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Position_Mode_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Position_Mode_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Position_Mode_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Position_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Position_Mode_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Position_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Position_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Position_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Position_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Position_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Position_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Position_Mode_Position_Speed_Slider
	ui->Position_Mode_Position_Speed_Slider = lv_slider_create(ui->Position_Mode_cont_1);
	lv_slider_set_range(ui->Position_Mode_Position_Speed_Slider, 0, 26);
	lv_slider_set_mode(ui->Position_Mode_Position_Speed_Slider, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->Position_Mode_Position_Speed_Slider, 0, LV_ANIM_OFF);
	lv_obj_set_pos(ui->Position_Mode_Position_Speed_Slider, 77, 54);
	lv_obj_set_size(ui->Position_Mode_Position_Speed_Slider, 160, 8);

	//Write style for Position_Mode_Position_Speed_Slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Position_Mode_Position_Speed_Slider, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Position_Mode_Position_Speed_Slider, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Position_Mode_Position_Speed_Slider, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Position_Mode_Position_Speed_Slider, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->Position_Mode_Position_Speed_Slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Position_Mode_Position_Speed_Slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Position_Mode_Position_Speed_Slider, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Position_Mode_Position_Speed_Slider, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Position_Mode_Position_Speed_Slider, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Position_Mode_Position_Speed_Slider, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Position_Mode_Position_Speed_Slider, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for Position_Mode_Position_Speed_Slider, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Position_Mode_Position_Speed_Slider, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Position_Mode_Position_Speed_Slider, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Position_Mode_Position_Speed_Slider, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Position_Mode_Position_Speed_Slider, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes Position_Mode_Position_Position_Slider
	ui->Position_Mode_Position_Position_Slider = lv_slider_create(ui->Position_Mode_cont_1);
	lv_slider_set_range(ui->Position_Mode_Position_Position_Slider, -720, 720);
	lv_slider_set_mode(ui->Position_Mode_Position_Position_Slider, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->Position_Mode_Position_Position_Slider, 0, LV_ANIM_OFF);
	lv_obj_set_pos(ui->Position_Mode_Position_Position_Slider, 77, 121);
	lv_obj_set_size(ui->Position_Mode_Position_Position_Slider, 160, 8);

	//Write style for Position_Mode_Position_Position_Slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Position_Mode_Position_Position_Slider, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Position_Mode_Position_Position_Slider, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Position_Mode_Position_Position_Slider, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Position_Mode_Position_Position_Slider, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->Position_Mode_Position_Position_Slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Position_Mode_Position_Position_Slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Position_Mode_Position_Position_Slider, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Position_Mode_Position_Position_Slider, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Position_Mode_Position_Position_Slider, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Position_Mode_Position_Position_Slider, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Position_Mode_Position_Position_Slider, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for Position_Mode_Position_Position_Slider, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Position_Mode_Position_Position_Slider, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Position_Mode_Position_Position_Slider, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Position_Mode_Position_Position_Slider, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Position_Mode_Position_Position_Slider, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes Position_Mode_Speed_Label
	ui->Position_Mode_Speed_Label = lv_label_create(ui->Position_Mode_cont_1);
	lv_label_set_text(ui->Position_Mode_Speed_Label, "0");
	lv_label_set_long_mode(ui->Position_Mode_Speed_Label, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Position_Mode_Speed_Label, 107, 74);
	lv_obj_set_size(ui->Position_Mode_Speed_Label, 100, 32);

	//Write style for Position_Mode_Speed_Label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Position_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Position_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Position_Mode_Speed_Label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Position_Mode_Speed_Label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Position_Mode_Speed_Label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Position_Mode_Speed_Label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Position_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Position_Mode_Speed_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Position_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Position_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Position_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Position_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Position_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Position_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Position_Mode_Position_Label
	ui->Position_Mode_Position_Label = lv_label_create(ui->Position_Mode_cont_1);
	lv_label_set_text(ui->Position_Mode_Position_Label, "0");
	lv_label_set_long_mode(ui->Position_Mode_Position_Label, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Position_Mode_Position_Label, 107, 142);
	lv_obj_set_size(ui->Position_Mode_Position_Label, 100, 32);

	//Write style for Position_Mode_Position_Label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Position_Mode_Position_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Position_Mode_Position_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Position_Mode_Position_Label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Position_Mode_Position_Label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Position_Mode_Position_Label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Position_Mode_Position_Label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Position_Mode_Position_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Position_Mode_Position_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Position_Mode_Position_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Position_Mode_Position_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Position_Mode_Position_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Position_Mode_Position_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Position_Mode_Position_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Position_Mode_Position_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Position_Mode_label_2
	ui->Position_Mode_label_2 = lv_label_create(ui->Position_Mode_cont_1);
	lv_label_set_text(ui->Position_Mode_label_2, "Speed");
	lv_label_set_long_mode(ui->Position_Mode_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Position_Mode_label_2, 107, 30);
	lv_obj_set_size(ui->Position_Mode_label_2, 100, 32);

	//Write style for Position_Mode_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Position_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Position_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Position_Mode_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Position_Mode_label_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Position_Mode_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Position_Mode_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Position_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Position_Mode_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Position_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Position_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Position_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Position_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Position_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Position_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Position_Mode_label_3
	ui->Position_Mode_label_3 = lv_label_create(ui->Position_Mode_cont_1);
	lv_label_set_text(ui->Position_Mode_label_3, "Position");
	lv_label_set_long_mode(ui->Position_Mode_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Position_Mode_label_3, 107, 99);
	lv_obj_set_size(ui->Position_Mode_label_3, 100, 32);

	//Write style for Position_Mode_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Position_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Position_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Position_Mode_label_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Position_Mode_label_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Position_Mode_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Position_Mode_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Position_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Position_Mode_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Position_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Position_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Position_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Position_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Position_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Position_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of Position_Mode.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->Position_Mode);

	//Init events for screen.
	events_init_Position_Mode(ui);
}
