#include "gui.h"

#include "../lvgl/lvgl.h"

//
//
//
lv_obj_t *sw2;
lv_obj_t * label1;
 
//
//
//
void event_handler(lv_obj_t * obj, lv_event_t event)
{
//printf("%d ", obj);
  if((obj == sw2) && (event == LV_EVENT_VALUE_CHANGED))
  {
    printf("deze !\n");
    return;
  }
    if(event == LV_EVENT_CLICKED) {
        printf("Clicked\n");
    }
    
    if(event == LV_EVENT_VALUE_CHANGED) {
        printf("Toggled\n");
    }
    
    if(event == LV_EVENT_VALUE_CHANGED) {
        printf("State: %s\n", lv_checkbox_is_checked(obj) ? "Checked" : "Unchecked");
    }
}


//
//
//
void screen()
{
    lv_obj_t * label;

    lv_obj_t * btn1 = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_event_cb(btn1, event_handler);
    lv_obj_align(btn1, NULL, LV_ALIGN_CENTER, 0, -40);

    label1 = lv_label_create(btn1, NULL);
    lv_label_set_text(label1, "Button");

    lv_obj_t * btn2 = lv_btn_create(lv_scr_act(), NULL);
    lv_obj_set_event_cb(btn2, event_handler);
    lv_obj_align(btn2, NULL, LV_ALIGN_CENTER, 0, 40);
    lv_btn_set_checkable(btn2, true);
    lv_btn_toggle(btn2);
    lv_btn_set_fit2(btn2, LV_FIT_NONE, LV_FIT_TIGHT);

    label = lv_label_create(btn2, NULL);
    
    lv_label_set_text(label, "Output");
        /*Create a switch and apply the styles*/
    lv_obj_t *sw1 = lv_switch_create(lv_scr_act(), NULL);
    lv_obj_align(sw1, NULL, LV_ALIGN_CENTER, 50, -100);
    lv_obj_set_event_cb(sw1, event_handler);

    /*Copy the first switch and turn it ON*/
    sw2 = lv_switch_create(lv_scr_act(), sw1);
    lv_switch_on(sw2, LV_ANIM_ON);
    lv_obj_align(sw2, NULL, LV_ALIGN_CENTER, 0, 100);
    lv_obj_set_width(sw2, 150);
    lv_obj_set_height(sw2, 60);
} 