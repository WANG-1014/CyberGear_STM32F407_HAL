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



void setup_scr_Menu(lv_ui *ui)
{
	//Write codes Menu
	ui->Menu = lv_obj_create(NULL);
	lv_obj_set_size(ui->Menu, 320, 240);
	lv_obj_set_scrollbar_mode(ui->Menu, LV_SCROLLBAR_MODE_ON);

	//Write style for Menu, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Menu, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Menu_cont_1
	ui->Menu_cont_1 = lv_obj_create(ui->Menu);
	lv_obj_set_pos(ui->Menu_cont_1, 0, 0);
	lv_obj_set_size(ui->Menu_cont_1, 320, 240);
	lv_obj_set_scrollbar_mode(ui->Menu_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for Menu_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Menu_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->Menu_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->Menu_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->Menu_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Menu_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Menu_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Menu_cont_1, lv_color_hex(0xb8b9e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Menu_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Menu_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Menu_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Menu_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Menu_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Menu_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Menu_label_1
	ui->Menu_label_1 = lv_label_create(ui->Menu_cont_1);
	lv_label_set_text(ui->Menu_label_1, "Motor Control System");
	lv_label_set_long_mode(ui->Menu_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Menu_label_1, 49.5, 3);
	lv_obj_set_size(ui->Menu_label_1, 221, 32);

	//Write style for Menu_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Menu_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Menu_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Menu_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Menu_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Menu_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Menu_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Menu_Zero_Mode_Button
	ui->Menu_Zero_Mode_Button = lv_btn_create(ui->Menu_cont_1);
	ui->Menu_Zero_Mode_Button_label = lv_label_create(ui->Menu_Zero_Mode_Button);
	lv_label_set_text(ui->Menu_Zero_Mode_Button_label, "Zero Mode");
	lv_label_set_long_mode(ui->Menu_Zero_Mode_Button_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Menu_Zero_Mode_Button_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Menu_Zero_Mode_Button, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Menu_Zero_Mode_Button_label, LV_PCT(100));
	lv_obj_set_pos(ui->Menu_Zero_Mode_Button, 36, 42);
	lv_obj_set_size(ui->Menu_Zero_Mode_Button, 100, 50);

	//Write style for Menu_Zero_Mode_Button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Menu_Zero_Mode_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Menu_Zero_Mode_Button, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Menu_Zero_Mode_Button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Menu_Zero_Mode_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Menu_Zero_Mode_Button, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Menu_Zero_Mode_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Menu_Zero_Mode_Button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Menu_Zero_Mode_Button, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Menu_Zero_Mode_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Menu_Zero_Mode_Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Menu_Position_Mode_Button
	ui->Menu_Position_Mode_Button = lv_btn_create(ui->Menu_cont_1);
	ui->Menu_Position_Mode_Button_label = lv_label_create(ui->Menu_Position_Mode_Button);
	lv_label_set_text(ui->Menu_Position_Mode_Button_label, "Position Mode");
	lv_label_set_long_mode(ui->Menu_Position_Mode_Button_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Menu_Position_Mode_Button_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Menu_Position_Mode_Button, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Menu_Position_Mode_Button_label, LV_PCT(100));
	lv_obj_set_pos(ui->Menu_Position_Mode_Button, 36, 112);
	lv_obj_set_size(ui->Menu_Position_Mode_Button, 100, 50);

	//Write style for Menu_Position_Mode_Button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Menu_Position_Mode_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Menu_Position_Mode_Button, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Menu_Position_Mode_Button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Menu_Position_Mode_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Menu_Position_Mode_Button, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Menu_Position_Mode_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Menu_Position_Mode_Button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Menu_Position_Mode_Button, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Menu_Position_Mode_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Menu_Position_Mode_Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Menu_Speed_Mode_Button
	ui->Menu_Speed_Mode_Button = lv_btn_create(ui->Menu_cont_1);
	ui->Menu_Speed_Mode_Button_label = lv_label_create(ui->Menu_Speed_Mode_Button);
	lv_label_set_text(ui->Menu_Speed_Mode_Button_label, "Speed Mode");
	lv_label_set_long_mode(ui->Menu_Speed_Mode_Button_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Menu_Speed_Mode_Button_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Menu_Speed_Mode_Button, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Menu_Speed_Mode_Button_label, LV_PCT(100));
	lv_obj_set_pos(ui->Menu_Speed_Mode_Button, 36, 182);
	lv_obj_set_size(ui->Menu_Speed_Mode_Button, 100, 50);

	//Write style for Menu_Speed_Mode_Button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Menu_Speed_Mode_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Menu_Speed_Mode_Button, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Menu_Speed_Mode_Button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Menu_Speed_Mode_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Menu_Speed_Mode_Button, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Menu_Speed_Mode_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Menu_Speed_Mode_Button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Menu_Speed_Mode_Button, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Menu_Speed_Mode_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Menu_Speed_Mode_Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Menu_Current_Mode_Button
	ui->Menu_Current_Mode_Button = lv_btn_create(ui->Menu_cont_1);
	ui->Menu_Current_Mode_Button_label = lv_label_create(ui->Menu_Current_Mode_Button);
	lv_label_set_text(ui->Menu_Current_Mode_Button_label, "Current Mode");
	lv_label_set_long_mode(ui->Menu_Current_Mode_Button_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Menu_Current_Mode_Button_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Menu_Current_Mode_Button, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Menu_Current_Mode_Button_label, LV_PCT(100));
	lv_obj_set_pos(ui->Menu_Current_Mode_Button, 168, 40);
	lv_obj_set_size(ui->Menu_Current_Mode_Button, 100, 50);

	//Write style for Menu_Current_Mode_Button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Menu_Current_Mode_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Menu_Current_Mode_Button, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Menu_Current_Mode_Button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Menu_Current_Mode_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Menu_Current_Mode_Button, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Menu_Current_Mode_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Menu_Current_Mode_Button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Menu_Current_Mode_Button, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Menu_Current_Mode_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Menu_Current_Mode_Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Menu_Control_Mode_Button
	ui->Menu_Control_Mode_Button = lv_btn_create(ui->Menu_cont_1);
	ui->Menu_Control_Mode_Button_label = lv_label_create(ui->Menu_Control_Mode_Button);
	lv_label_set_text(ui->Menu_Control_Mode_Button_label, "Control Mode");
	lv_label_set_long_mode(ui->Menu_Control_Mode_Button_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Menu_Control_Mode_Button_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Menu_Control_Mode_Button, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Menu_Control_Mode_Button_label, LV_PCT(100));
	lv_obj_set_pos(ui->Menu_Control_Mode_Button, 168, 115);
	lv_obj_set_size(ui->Menu_Control_Mode_Button, 100, 50);

	//Write style for Menu_Control_Mode_Button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Menu_Control_Mode_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Menu_Control_Mode_Button, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Menu_Control_Mode_Button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Menu_Control_Mode_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Menu_Control_Mode_Button, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Menu_Control_Mode_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Menu_Control_Mode_Button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Menu_Control_Mode_Button, &lv_font_montserratMedium_14, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Menu_Control_Mode_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Menu_Control_Mode_Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of Menu.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->Menu);

	//Init events for screen.
	events_init_Menu(ui);
}
