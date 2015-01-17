#ifndef INPUT_H
#define INPUT_H

#include "includes.h"
#include "usb.h"

// Opens input device
int inputopen(usbdevice* kb);
// Closes input device
void inputclose(usbdevice* kb);

// Updates keypresses on input device
void inputupdate(usbdevice* kb);
// Read LEDs from the event device and update them (if needed).
void updateindicators(usbdevice* kb, int force);

// Initializes key bindings for a device
void initbind(keybind* bind, const key* keymap);
// Frees key binding data for a device
void closebind(keybind* bind);

// Binds a key
void cmd_bind(usbmode* mode, const key* keymap, int dummy, int keyindex, const char* to);
// Unbinds a key
void cmd_unbind(usbmode* mode, const key* keymap, int dummy, int keyindex, const char* ignored);
// Resets a key binding
void cmd_rebind(usbmode* mode, const key* keymap, int dummy, int keyindex, const char* ignored);
// Creates or updates a macro
void cmd_macro(usbmode* mode, const key* keymap, const char* keys, const char* assignment);
// Clears all macros
void cmd_macroclear(usbmode* mode);


// OS-specific event handlers

// Generate a keypress event
void os_keypress(usbdevice* kb, int scancode, int down);
// Synchronize key input (called after sending key presses)
void os_kpsync(usbdevice* kb);
// Updates indicator state. Should read state, update ileds (applying mask for current mode as appropriate) and send control message to keyboard
void os_updateindicators(usbdevice* kb, int force);

#endif
