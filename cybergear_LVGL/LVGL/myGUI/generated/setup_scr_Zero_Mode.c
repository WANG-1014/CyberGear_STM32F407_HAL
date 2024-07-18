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



void setup_scr_Zero_Mode(lv_ui *ui)
{
	//Write codes Zero_Mode
	ui->Zero_Mode = lv_obj_create(NULL);
	lv_obj_set_size(ui->Zero_Mode, 320, 240);
	lv_obj_set_scrollbar_mode(ui->Zero_Mode, LV_SCROLLBAR_MODE_OFF);

	//Write style for Zero_Mode, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Zero_Mode, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Zero_Mode_cont_1
	ui->Zero_Mode_cont_1 = lv_obj_create(ui->Zero_Mode);
	lv_obj_set_pos(ui->Zero_Mode_cont_1, 0, 0);
	lv_obj_set_size(ui->Zero_Mode_cont_1, 320, 240);
	lv_obj_set_scrollbar_mode(ui->Zero_Mode_cont_1, LV_SCROLLBAR_MODE_OFF);

	//Write style for Zero_Mode_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Zero_Mode_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_opa(ui->Zero_Mode_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_color(ui->Zero_Mode_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_side(ui->Zero_Mode_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Zero_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Zero_Mode_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Zero_Mode_cont_1, lv_color_hex(0xb8b9e6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Zero_Mode_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Zero_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Zero_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Zero_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Zero_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Zero_Mode_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Zero_Mode_label_1
	ui->Zero_Mode_label_1 = lv_label_create(ui->Zero_Mode_cont_1);
	lv_label_set_text(ui->Zero_Mode_label_1, "Motor Zero Mode");
	lv_label_set_long_mode(ui->Zero_Mode_label_1, LV_LABEL_LONG_WRAP);
	lv_obj_set_pos(ui->Zero_Mode_label_1, 46, 2);
	lv_obj_set_size(ui->Zero_Mode_label_1, 213, 32);

	//Write style for Zero_Mode_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_border_width(ui->Zero_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Zero_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Zero_Mode_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Zero_Mode_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Zero_Mode_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_letter_space(ui->Zero_Mode_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_line_space(ui->Zero_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Zero_Mode_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_opa(ui->Zero_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_top(ui->Zero_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_right(ui->Zero_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_bottom(ui->Zero_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_pad_left(ui->Zero_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Zero_Mode_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Zero_Mode_Home_Button
	ui->Zero_Mode_Home_Button = lv_btn_create(ui->Zero_Mode_cont_1);
	ui->Zero_Mode_Home_Button_label = lv_label_create(ui->Zero_Mode_Home_Button);
	lv_label_set_text(ui->Zero_Mode_Home_Button_label, "Home\n");
	lv_label_set_long_mode(ui->Zero_Mode_Home_Button_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Zero_Mode_Home_Button_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Zero_Mode_Home_Button, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Zero_Mode_Home_Button_label, LV_PCT(100));
	lv_obj_set_pos(ui->Zero_Mode_Home_Button, 4, 188);
	lv_obj_set_size(ui->Zero_Mode_Home_Button, 100, 50);

	//Write style for Zero_Mode_Home_Button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Zero_Mode_Home_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Zero_Mode_Home_Button, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Zero_Mode_Home_Button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Zero_Mode_Home_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Zero_Mode_Home_Button, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Zero_Mode_Home_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Zero_Mode_Home_Button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Zero_Mode_Home_Button, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Zero_Mode_Home_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Zero_Mode_Home_Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Zero_Mode_Run_Zero_Button
	ui->Zero_Mode_Run_Zero_Button = lv_btn_create(ui->Zero_Mode_cont_1);
	ui->Zero_Mode_Run_Zero_Button_label = lv_label_create(ui->Zero_Mode_Run_Zero_Button);
	lv_label_set_text(ui->Zero_Mode_Run_Zero_Button_label, "Run Zero\n");
	lv_label_set_long_mode(ui->Zero_Mode_Run_Zero_Button_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Zero_Mode_Run_Zero_Button_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Zero_Mode_Run_Zero_Button, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Zero_Mode_Run_Zero_Button_label, LV_PCT(100));
	lv_obj_set_pos(ui->Zero_Mode_Run_Zero_Button, 108, 188);
	lv_obj_set_size(ui->Zero_Mode_Run_Zero_Button, 100, 50);

	//Write style for Zero_Mode_Run_Zero_Button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Zero_Mode_Run_Zero_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Zero_Mode_Run_Zero_Button, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Zero_Mode_Run_Zero_Button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Zero_Mode_Run_Zero_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Zero_Mode_Run_Zero_Button, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Zero_Mode_Run_Zero_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Zero_Mode_Run_Zero_Button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Zero_Mode_Run_Zero_Button, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Zero_Mode_Run_Zero_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Zero_Mode_Run_Zero_Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//Write codes Zero_Mode_Set_Zero_Button
	ui->Zero_Mode_Set_Zero_Button = lv_btn_create(ui->Zero_Mode_cont_1);
	ui->Zero_Mode_Set_Zero_Button_label = lv_label_create(ui->Zero_Mode_Set_Zero_Button);
	lv_label_set_text(ui->Zero_Mode_Set_Zero_Button_label, "Set Zero\n");
	lv_label_set_long_mode(ui->Zero_Mode_Set_Zero_Button_label, LV_LABEL_LONG_WRAP);
	lv_obj_align(ui->Zero_Mode_Set_Zero_Button_label, LV_ALIGN_CENTER, 0, 0);
	lv_obj_set_style_pad_all(ui->Zero_Mode_Set_Zero_Button, 0, LV_STATE_DEFAULT);
	lv_obj_set_width(ui->Zero_Mode_Set_Zero_Button_label, LV_PCT(100));
	lv_obj_set_pos(ui->Zero_Mode_Set_Zero_Button, 215, 188);
	lv_obj_set_size(ui->Zero_Mode_Set_Zero_Button, 100, 50);

	//Write style for Zero_Mode_Set_Zero_Button, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
	lv_obj_set_style_bg_opa(ui->Zero_Mode_Set_Zero_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_color(ui->Zero_Mode_Set_Zero_Button, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_bg_grad_dir(ui->Zero_Mode_Set_Zero_Button, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_border_width(ui->Zero_Mode_Set_Zero_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_radius(ui->Zero_Mode_Set_Zero_Button, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_shadow_width(ui->Zero_Mode_Set_Zero_Button, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_color(ui->Zero_Mode_Set_Zero_Button, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_font(ui->Zero_Mode_Set_Zero_Button, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_opa(ui->Zero_Mode_Set_Zero_Button, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
	lv_obj_set_style_text_align(ui->Zero_Mode_Set_Zero_Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

	//The custom code of Zero_Mode.
	

	//Update current screen layout.
	lv_obj_update_layout(ui->Zero_Mode);

	//Init events for screen.
	events_init_Zero_Mode(ui);
}
