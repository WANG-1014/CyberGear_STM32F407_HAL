/*
* Copyright 2024 NXP
* NXP Confidential and Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"
#include "cybergear.h"

#if LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif


uint8_t position_speed_value;
int16_t position_position_value;
int8_t speed_speed_value;
int8_t speed_current_value;
int8_t current_current_value;
int8_t control_torque_value;
int8_t control_speed_value;
int16_t control_position_value;
uint8_t control_kp_value;
uint8_t control_kd_value;
static void Zero_Mode_Home_Button_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		stop_cybergear(&mi_motor[1], 0);
		ui_load_scr_animation(&guider_ui, &guider_ui.Menu, guider_ui.Menu_del, &guider_ui.Zero_Mode_del, setup_scr_Menu, LV_SCR_LOAD_ANIM_MOVE_BOTTOM, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}
static void Zero_Mode_Run_Zero_Button_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		set_mode_cybergear(&mi_motor[1], Position_mode);
		set_position_cybergear(&mi_motor[1], 0, 5, 8, 40);
		break;
	}
	default:
		break;
	}
}
static void Zero_Mode_Set_Zero_Button_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		stop_cybergear(&mi_motor[1], 0);
		set_zeropos_cybergear(&mi_motor[1]);
		break;
	}
	default:
		break;
	}
}
void events_init_Zero_Mode(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Zero_Mode_Home_Button, Zero_Mode_Home_Button_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Zero_Mode_Run_Zero_Button, Zero_Mode_Run_Zero_Button_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Zero_Mode_Set_Zero_Button, Zero_Mode_Set_Zero_Button_event_handler, LV_EVENT_ALL, ui);
}
static void Position_Mode_Position_Home_Button_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		stop_cybergear(&mi_motor[1], 0);
		ui_load_scr_animation(&guider_ui, &guider_ui.Menu, guider_ui.Menu_del, &guider_ui.Position_Mode_del, setup_scr_Menu, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}
static void Position_Mode_Position_Run_Button_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		set_position_cybergear(&mi_motor[1], position_position_value, position_speed_value, 8, 40);
		break;
	}
	default:
		break;
	}
}
static void Position_Mode_Position_Stop_Button_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		stop_cybergear(&mi_motor[1], 0);
		HAL_Delay(10);
		set_mode_cybergear(&mi_motor[1], Position_mode);//小米电机 位置模式
		break;
	}
	default:
		break;
	}
}
static void Position_Mode_Position_Speed_Slider_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		lv_obj_t *slider=lv_event_get_target(e);
	position_speed_value=lv_slider_get_value(slider);
	char buf[8];
	lv_snprintf(buf, sizeof(buf), "%d", position_speed_value);
	lv_label_set_text(guider_ui.Position_Mode_Speed_Label, buf);
		break;
	}
	default:
		break;
	}
}
static void Position_Mode_Position_Position_Slider_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		lv_obj_t *slider=lv_event_get_target(e);
	position_position_value=lv_slider_get_value(slider);
	char buf[8];
	lv_snprintf(buf, sizeof(buf), "%d", position_position_value);
	lv_label_set_text(guider_ui.Position_Mode_Position_Label, buf);
		break;
	}
	default:
		break;
	}
}
void events_init_Position_Mode(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Position_Mode_Position_Home_Button, Position_Mode_Position_Home_Button_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Position_Mode_Position_Run_Button, Position_Mode_Position_Run_Button_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Position_Mode_Position_Stop_Button, Position_Mode_Position_Stop_Button_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Position_Mode_Position_Speed_Slider, Position_Mode_Position_Speed_Slider_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Position_Mode_Position_Position_Slider, Position_Mode_Position_Position_Slider_event_handler, LV_EVENT_ALL, ui);
}
static void Speed_Mode_Speed_Speed_Slider_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		lv_obj_t *slider=lv_event_get_target(e);
	speed_speed_value=lv_slider_get_value(slider);
	char buf[8];
	lv_snprintf(buf, sizeof(buf), "%d", speed_speed_value);
	lv_label_set_text(guider_ui.Speed_Mode_Speed_Label, buf);
		break;
	}
	default:
		break;
	}
}
static void Speed_Mode_Speed_Current_Slider_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		lv_obj_t *slider=lv_event_get_target(e);
	speed_current_value=lv_slider_get_value(slider);
	char buf[8];
	lv_snprintf(buf, sizeof(buf), "%d", speed_current_value);
	lv_label_set_text(guider_ui.Speed_Mode_Current_Label, buf);
		break;
	}
	default:
		break;
	}
}
static void Speed_Mode_Current_Label_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		ui_load_scr_animation(&guider_ui, &guider_ui.Menu, guider_ui.Menu_del, &guider_ui.Speed_Mode_del, setup_scr_Menu, LV_SCR_LOAD_ANIM_OVER_TOP, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}
static void Speed_Mode_Speed_Home_Button_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		stop_cybergear(&mi_motor[1], 0);
		ui_load_scr_animation(&guider_ui, &guider_ui.Menu, guider_ui.Menu_del, &guider_ui.Speed_Mode_del, setup_scr_Menu, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}
static void Speed_Mode_Speed_Run_Button_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		set_speed_cybergear(&mi_motor[1], speed_speed_value);
		break;
	}
	default:
		break;
	}
}
static void Speed_Mode_Speed_Stop_Button_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		stop_cybergear(&mi_motor[1], 0);
		HAL_Delay(10);
		set_mode_cybergear(&mi_motor[1], Speed_mode);//小米电机 速度模式
		break;
	}
	default:
		break;
	}
}
void events_init_Speed_Mode(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Speed_Mode_Speed_Speed_Slider, Speed_Mode_Speed_Speed_Slider_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Speed_Mode_Speed_Current_Slider, Speed_Mode_Speed_Current_Slider_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Speed_Mode_Current_Label, Speed_Mode_Current_Label_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Speed_Mode_Speed_Home_Button, Speed_Mode_Speed_Home_Button_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Speed_Mode_Speed_Run_Button, Speed_Mode_Speed_Run_Button_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Speed_Mode_Speed_Stop_Button, Speed_Mode_Speed_Stop_Button_event_handler, LV_EVENT_ALL, ui);
}
static void Current_Mode_Current_Current_Slider_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		lv_obj_t *slider=lv_event_get_target(e);
	current_current_value=lv_slider_get_value(slider);
	char buf[8];
	lv_snprintf(buf, sizeof(buf), "%d", current_current_value);
	lv_label_set_text(guider_ui.Current_Mode_Current_Label, buf);
		break;
	}
	default:
		break;
	}
}
static void Current_Mode_Current_Stop_Button_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		stop_cybergear(&mi_motor[1], 0);
		HAL_Delay(10);
		set_mode_cybergear(&mi_motor[1], Current_mode);//小米电机 电流模式
		break;
	}
	default:
		break;
	}
}
static void Current_Mode_Current_Run_Button_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		set_current_cybergear(&mi_motor[1], current_current_value);
		break;
	}
	default:
		break;
	}
}
static void Current_Mode_Current_Home_Button_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		stop_cybergear(&mi_motor[1], 0);
		ui_load_scr_animation(&guider_ui, &guider_ui.Menu, guider_ui.Menu_del, &guider_ui.Current_Mode_del, setup_scr_Menu, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}
void events_init_Current_Mode(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Current_Mode_Current_Current_Slider, Current_Mode_Current_Current_Slider_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Current_Mode_Current_Stop_Button, Current_Mode_Current_Stop_Button_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Current_Mode_Current_Run_Button, Current_Mode_Current_Run_Button_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Current_Mode_Current_Home_Button, Current_Mode_Current_Home_Button_event_handler, LV_EVENT_ALL, ui);
}
static void Control_Mode_Control_Home_Button_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		stop_cybergear(&mi_motor[1], 0);
		ui_load_scr_animation(&guider_ui, &guider_ui.Menu, guider_ui.Menu_del, &guider_ui.Control_Mode_del, setup_scr_Menu, LV_SCR_LOAD_ANIM_OVER_BOTTOM, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}
static void Control_Mode_Control_Run_Button_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		motor_controlmode(&mi_motor[1], control_torque_value, control_position_value, control_speed_value, control_kp_value, control_kd_value);
		break;
	}
	default:
		break;
	}
}
static void Control_Mode_Control_Stop_Button_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		stop_cybergear(&mi_motor[1], 0);
		HAL_Delay(10);
		set_mode_cybergear(&mi_motor[1], Motion_mode);//小米电机 Motion_mode模式
		break;
	}
	default:
		break;
	}
}
static void Control_Mode_Control_Torque_Slider_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		lv_obj_t *slider=lv_event_get_target(e);
	control_torque_value=lv_slider_get_value(slider);
	char buf[8];
	lv_snprintf(buf, sizeof(buf), "%d", control_torque_value);
	lv_label_set_text(guider_ui.Control_Mode_Torque_Label, buf);
		break;
	}
	default:
		break;
	}
}
static void Control_Mode_Control_Speed_Slider_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		lv_obj_t *slider=lv_event_get_target(e);
	control_speed_value=lv_slider_get_value(slider);
	char buf[8];
	lv_snprintf(buf, sizeof(buf), "%d", control_speed_value);
	lv_label_set_text(guider_ui.Control_Mode_Speed_Label, buf);
		break;
	}
	default:
		break;
	}
}
static void Control_Mode_Control_Position_Slider_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		lv_obj_t *slider=lv_event_get_target(e);
	control_position_value=lv_slider_get_value(slider);
	char buf[8];
	lv_snprintf(buf, sizeof(buf), "%d", control_position_value);
	lv_label_set_text(guider_ui.Control_Mode_Position_Label, buf);
		break;
	}
	default:
		break;
	}
}
static void Control_Mode_Control_Kp_Slider_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		lv_obj_t *slider=lv_event_get_target(e);
	control_kp_value=lv_slider_get_value(slider);
	char buf[8];
	lv_snprintf(buf, sizeof(buf), "%d", control_kp_value);
	lv_label_set_text(guider_ui.Control_Mode_Kp_Label, buf);
		break;
	}
	default:
		break;
	}
}
static void Control_Mode_Control_Kd_Slider_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_VALUE_CHANGED:
	{
		lv_obj_t *slider=lv_event_get_target(e);
	control_kd_value=lv_slider_get_value(slider);
	char buf[8];
	lv_snprintf(buf, sizeof(buf), "%d", control_kd_value);
	lv_label_set_text(guider_ui.Control_Mode_Kd_Label, buf);
		break;
	}
	default:
		break;
	}
}
void events_init_Control_Mode(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Control_Mode_Control_Home_Button, Control_Mode_Control_Home_Button_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Control_Mode_Control_Run_Button, Control_Mode_Control_Run_Button_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Control_Mode_Control_Stop_Button, Control_Mode_Control_Stop_Button_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Control_Mode_Control_Torque_Slider, Control_Mode_Control_Torque_Slider_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Control_Mode_Control_Speed_Slider, Control_Mode_Control_Speed_Slider_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Control_Mode_Control_Position_Slider, Control_Mode_Control_Position_Slider_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Control_Mode_Control_Kp_Slider, Control_Mode_Control_Kp_Slider_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Control_Mode_Control_Kd_Slider, Control_Mode_Control_Kd_Slider_event_handler, LV_EVENT_ALL, ui);
}
static void Menu_Zero_Mode_Button_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		set_mode_cybergear(&mi_motor[1], Position_mode);//小米电机 位置模式
		ui_load_scr_animation(&guider_ui, &guider_ui.Zero_Mode, guider_ui.Zero_Mode_del, &guider_ui.Menu_del, setup_scr_Zero_Mode, LV_SCR_LOAD_ANIM_MOVE_TOP, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}
static void Menu_Position_Mode_Button_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		set_mode_cybergear(&mi_motor[1], Position_mode);//小米电机 位置模式
		ui_load_scr_animation(&guider_ui, &guider_ui.Position_Mode, guider_ui.Position_Mode_del, &guider_ui.Menu_del, setup_scr_Position_Mode, LV_SCR_LOAD_ANIM_OVER_TOP, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}
static void Menu_Speed_Mode_Button_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		set_mode_cybergear(&mi_motor[1], Speed_mode);//小米电机 速度模式
		ui_load_scr_animation(&guider_ui, &guider_ui.Speed_Mode, guider_ui.Speed_Mode_del, &guider_ui.Menu_del, setup_scr_Speed_Mode, LV_SCR_LOAD_ANIM_OVER_TOP, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}
static void Menu_Current_Mode_Button_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		set_mode_cybergear(&mi_motor[1], Current_mode);//小米电机 电流模式
		ui_load_scr_animation(&guider_ui, &guider_ui.Current_Mode, guider_ui.Current_Mode_del, &guider_ui.Menu_del, setup_scr_Current_Mode, LV_SCR_LOAD_ANIM_OVER_TOP, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}
static void Menu_Control_Mode_Button_event_handler (lv_event_t *e)
{
	lv_event_code_t code = lv_event_get_code(e);

	switch (code) {
	case LV_EVENT_CLICKED:
	{
		set_mode_cybergear(&mi_motor[1], Motion_mode);//小米电机 Motion_mode模式
		ui_load_scr_animation(&guider_ui, &guider_ui.Control_Mode, guider_ui.Control_Mode_del, &guider_ui.Menu_del, setup_scr_Control_Mode, LV_SCR_LOAD_ANIM_OVER_TOP, 200, 200, false, true);
		break;
	}
	default:
		break;
	}
}
void events_init_Menu(lv_ui *ui)
{
	lv_obj_add_event_cb(ui->Menu_Zero_Mode_Button, Menu_Zero_Mode_Button_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Menu_Position_Mode_Button, Menu_Position_Mode_Button_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Menu_Speed_Mode_Button, Menu_Speed_Mode_Button_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Menu_Current_Mode_Button, Menu_Current_Mode_Button_event_handler, LV_EVENT_ALL, ui);
	lv_obj_add_event_cb(ui->Menu_Control_Mode_Button, Menu_Control_Mode_Button_event_handler, LV_EVENT_ALL, ui);
}

void events_init(lv_ui *ui)
{

}
