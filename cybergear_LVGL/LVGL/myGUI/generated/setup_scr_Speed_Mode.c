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



void setup_scr_Speed_Mode(lv_ui *ui)
{
	//Write codes Speed_Mode
	ui->Speed_Mode = lv_obj_create(NULL);
	lv_obj_set_size(ui->Speed_Mode, 320, 240);
	lv_obj_set_scrollbar_mode(ui->Speed_Mode, LV_SCROLLBAR_MODE_OFF);

	//Write style for Speed_Mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Speed_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Speed_Mode_cont_1
	ui->Speed_Mode_cont_1 = lv_obj_create(ui->Speed_Mode);
	lv_obj_set_pos(ui->Speed_Mode_cont_1, 0, 0);
	lv_obj_set_size(ui->Speed_Mode_cont_1, 320, 240);
	lv_obj_set_scrollbar_mode(ui->Speed_Mode_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for Speed_Mode_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Speed_Mode_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->Speed_Mode_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->Speed_Mode_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->Speed_Mode_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Speed_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Speed_Mode_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Speed_Mode_cont_1, lv_color_hex(0xb8b9e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Speed_Mode_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Speed_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Speed_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Speed_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Speed_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Speed_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Speed_Mode_label_1
	ui->Speed_Mode_label_1 = lv_label_create(ui->Speed_Mode_cont_1);
	lv_label_set_text(ui->Speed_Mode_label_1, "Motor Speed Mode");
	lv_label_set_long_mode(ui->Speed_Mode_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Speed_Mode_label_1, 36.5, 3);
	lv_obj_set_size(ui->Speed_Mode_label_1, 247, 32);

	//Write style for Speed_Mode_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Speed_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Speed_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Speed_Mode_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Speed_Mode_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Speed_Mode_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Speed_Mode_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Speed_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Speed_Mode_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Speed_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Speed_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Speed_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Speed_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Speed_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Speed_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Speed_Mode_Speed_Speed_Slider
	ui->Speed_Mode_Speed_Speed_Slider = lv_slider_create(ui->Speed_Mode_cont_1);
	lv_slider_set_range(ui->Speed_Mode_Speed_Speed_Slider, -26, 26);
	lv_slider_set_mode(ui->Speed_Mode_Speed_Speed_Slider, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->Speed_Mode_Speed_Speed_Slider, 0, LV_ANIM_OFF);
	lv_obj_set_pos(ui->Speed_Mode_Speed_Speed_Slider, 71, 68);
	lv_obj_set_size(ui->Speed_Mode_Speed_Speed_Slider, 160, 8);

	//Write style for Speed_Mode_Speed_Speed_Slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Speed_Mode_Speed_Speed_Slider, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Speed_Mode_Speed_Speed_Slider, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Speed_Mode_Speed_Speed_Slider, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Speed_Mode_Speed_Speed_Slider, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->Speed_Mode_Speed_Speed_Slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Speed_Mode_Speed_Speed_Slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Speed_Mode_Speed_Speed_Slider, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Speed_Mode_Speed_Speed_Slider, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Speed_Mode_Speed_Speed_Slider, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Speed_Mode_Speed_Speed_Slider, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Speed_Mode_Speed_Speed_Slider, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for Speed_Mode_Speed_Speed_Slider, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Speed_Mode_Speed_Speed_Slider, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Speed_Mode_Speed_Speed_Slider, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Speed_Mode_Speed_Speed_Slider, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Speed_Mode_Speed_Speed_Slider, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes Speed_Mode_Speed_Current_Slider
	ui->Speed_Mode_Speed_Current_Slider = lv_slider_create(ui->Speed_Mode_cont_1);
	lv_slider_set_range(ui->Speed_Mode_Speed_Current_Slider, -22, 22);
	lv_slider_set_mode(ui->Speed_Mode_Speed_Current_Slider, LV_SLIDER_MODE_NORMAL);
	lv_slider_set_value(ui->Speed_Mode_Speed_Current_Slider, 0, LV_ANIM_OFF);
	lv_obj_set_pos(ui->Speed_Mode_Speed_Current_Slider, 71, 142);
	lv_obj_set_size(ui->Speed_Mode_Speed_Current_Slider, 160, 8);

	//Write style for Speed_Mode_Speed_Current_Slider, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Speed_Mode_Speed_Current_Slider, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Speed_Mode_Speed_Current_Slider, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Speed_Mode_Speed_Current_Slider, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Speed_Mode_Speed_Current_Slider, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_outline_width(ui->Speed_Mode_Speed_Current_Slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Speed_Mode_Speed_Current_Slider, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write style for Speed_Mode_Speed_Current_Slider, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Speed_Mode_Speed_Current_Slider, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Speed_Mode_Speed_Current_Slider, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Speed_Mode_Speed_Current_Slider, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Speed_Mode_Speed_Current_Slider, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

	//Write style for Speed_Mode_Speed_Current_Slider, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Speed_Mode_Speed_Current_Slider, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Speed_Mode_Speed_Current_Slider, lv_color_hex(0x2195f6), LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Speed_Mode_Speed_Current_Slider, LV_GRAD_DIR_NONE, LV_PART_KNOB|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Speed_Mode_Speed_Current_Slider, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

	//Write codes Speed_Mode_label_2
	ui->Speed_Mode_label_2 = lv_label_create(ui->Speed_Mode_cont_1);
	lv_label_set_text(ui->Speed_Mode_label_2, "Speed");
	lv_label_set_long_mode(ui->Speed_Mode_label_2, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Speed_Mode_label_2, 98, 40);
	lv_obj_set_size(ui->Speed_Mode_label_2, 100, 32);

	//Write style for Speed_Mode_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Speed_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Speed_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Speed_Mode_label_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Speed_Mode_label_2, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Speed_Mode_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Speed_Mode_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Speed_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Speed_Mode_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Speed_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Speed_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Speed_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Speed_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Speed_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Speed_Mode_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Speed_Mode_label_3
	ui->Speed_Mode_label_3 = lv_label_create(ui->Speed_Mode_cont_1);
	lv_label_set_text(ui->Speed_Mode_label_3, "Current");
	lv_label_set_long_mode(ui->Speed_Mode_label_3, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Speed_Mode_label_3, 98, 116);
	lv_obj_set_size(ui->Speed_Mode_label_3, 100, 32);

	//Write style for Speed_Mode_label_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Speed_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Speed_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Speed_Mode_label_3, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Speed_Mode_label_3, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Speed_Mode_label_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Speed_Mode_label_3, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Speed_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Speed_Mode_label_3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Speed_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Speed_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Speed_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Speed_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Speed_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Speed_Mode_label_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Speed_Mode_Speed_Label
	ui->Speed_Mode_Speed_Label = lv_label_create(ui->Speed_Mode_cont_1);
	lv_label_set_text(ui->Speed_Mode_Speed_Label, "0");
	lv_label_set_long_mode(ui->Speed_Mode_Speed_Label, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Speed_Mode_Speed_Label, 97, 89);
	lv_obj_set_size(ui->Speed_Mode_Speed_Label, 100, 32);

	//Write style for Speed_Mode_Speed_Label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Speed_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Speed_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Speed_Mode_Speed_Label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Speed_Mode_Speed_Label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Speed_Mode_Speed_Label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Speed_Mode_Speed_Label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Speed_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Speed_Mode_Speed_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Speed_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Speed_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Speed_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Speed_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Speed_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Speed_Mode_Speed_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Speed_Mode_Current_Label
	ui->Speed_Mode_Current_Label = lv_label_create(ui->Speed_Mode_cont_1);
	lv_label_set_text(ui->Speed_Mode_Current_Label, "0");
	lv_label_set_long_mode(ui->Speed_Mode_Current_Label, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Speed_Mode_Current_Label, 96, 161);
	lv_obj_set_size(ui->Speed_Mode_Current_Label, 100, 32);

	//Write style for Speed_Mode_Current_Label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Speed_Mode_Current_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Speed_Mode_Current_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Speed_Mode_Current_Label, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Speed_Mode_Current_Label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Speed_Mode_Current_Label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Speed_Mode_Current_Label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Speed_Mode_Current_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Speed_Mode_Current_Label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Speed_Mode_Current_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Speed_Mode_Current_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Speed_Mode_Current_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Speed_Mode_Current_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Speed_Mode_Current_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Speed_Mode_Current_Label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Speed_Mode_Speed_Home_Button
	ui->Speed_Mode_Speed_Home_Button = lv_btn_create(ui->Speed_Mode_cont_1);
	ui->Speed_Mode_Speed_Home_Button_label = lv_label_create(ui->Speed_Mode_Speed_Home_Button);
	lv_label_set_text(ui->Speed_Mode_Speed_Home_Button_label, "Home");
	lv_label_set_long_mode(ui->Speed_Mode_Speed_Home_Button_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Speed_Mode_Speed_Home_Button_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Speed_Mode_Speed_Home_Button, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Speed_Mode_Speed_Home_Button_label, LV_PCT(100));
	lv_obj_set_pos(ui->Speed_Mode_Speed_Home_Button, 4, 185);
	lv_obj_set_size(ui->Speed_Mode_Speed_Home_Button, 100, 50);

	//Write style for Speed_Mode_Speed_Home_Button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Speed_Mode_Speed_Home_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Speed_Mode_Speed_Home_Button, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Speed_Mode_Speed_Home_Button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Speed_Mode_Speed_Home_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Speed_Mode_Speed_Home_Button, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Speed_Mode_Speed_Home_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Speed_Mode_Speed_Home_Button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Speed_Mode_Speed_Home_Button, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Speed_Mode_Speed_Home_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Speed_Mode_Speed_Home_Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Speed_Mode_Speed_Run_Button
	ui->Speed_Mode_Speed_Run_Button = lv_btn_create(ui->Speed_Mode_cont_1);
	ui->Speed_Mode_Speed_Run_Button_label = lv_label_create(ui->Speed_Mode_Speed_Run_Button);
	lv_label_set_text(ui->Speed_Mode_Speed_Run_Button_label, "Run");
	lv_label_set_long_mode(ui->Speed_Mode_Speed_Run_Button_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Speed_Mode_Speed_Run_Button_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Speed_Mode_Speed_Run_Button, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Speed_Mode_Speed_Run_Button_label, LV_PCT(100));
	lv_obj_set_pos(ui->Speed_Mode_Speed_Run_Button, 108, 185);
	lv_obj_set_size(ui->Speed_Mode_Speed_Run_Button, 100, 50);

	//Write style for Speed_Mode_Speed_Run_Button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Speed_Mode_Speed_Run_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Speed_Mode_Speed_Run_Button, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Speed_Mode_Speed_Run_Button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Speed_Mode_Speed_Run_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Speed_Mode_Speed_Run_Button, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Speed_Mode_Speed_Run_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Speed_Mode_Speed_Run_Button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Speed_Mode_Speed_Run_Button, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Speed_Mode_Speed_Run_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Speed_Mode_Speed_Run_Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Speed_Mode_Speed_Stop_Button
	ui->Speed_Mode_Speed_Stop_Button = lv_btn_create(ui->Speed_Mode_cont_1);
	ui->Speed_Mode_Speed_Stop_Button_label = lv_label_create(ui->Speed_Mode_Speed_Stop_Button);
	lv_label_set_text(ui->Speed_Mode_Speed_Stop_Button_label, "Stop");
	lv_label_set_long_mode(ui->Speed_Mode_Speed_Stop_Button_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Speed_Mode_Speed_Stop_Button_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Speed_Mode_Speed_Stop_Button, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Speed_Mode_Speed_Stop_Button_label, LV_PCT(100));
	lv_obj_set_pos(ui->Speed_Mode_Speed_Stop_Button, 214, 185);
	lv_obj_set_size(ui->Speed_Mode_Speed_Stop_Button, 100, 50);

	//Write style for Speed_Mode_Speed_Stop_Button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Speed_Mode_Speed_Stop_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Speed_Mode_Speed_Stop_Button, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Speed_Mode_Speed_Stop_Button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Speed_Mode_Speed_Stop_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Speed_Mode_Speed_Stop_Button, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Speed_Mode_Speed_Stop_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Speed_Mode_Speed_Stop_Button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Speed_Mode_Speed_Stop_Button, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Speed_Mode_Speed_Stop_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Speed_Mode_Speed_Stop_Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of Speed_Mode.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->Speed_Mode);

	//Init events for screen.
	events_init_Speed_Mode(ui);
}
