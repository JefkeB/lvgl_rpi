# linux_frame_buffer  
LittlevGL configured to work with /dev/fb0 on Linux  
  
  
---
**NOTE**  
When starting the application a block cursor is visible.
This is from the frambuffer console. To hide this cursor apply the following changes and reboot

edit /boot/cmdline.txt 

replace 
'console=tty1' with 'console=tty3' 
this way  the boot messages will be redirected to the 3rd console

add 
'loglevel=3' 
this disables the non-critical kernel log messages

add 
'vt.global_cursor_default=0' 
this disables the blinking cursor