#include "apps.h"
#include "finput.h"
#include "mainmenu.h"
#include "spectrum.h"
#include "still.h"
#include "test.h"

AppType_t gCurrentApp = APP_TEST;

const App apps[5] = {
    {"Test", TEST_Init, TEST_Update, TEST_Render, TEST_Key},
    {"Spectrum", SPECTRUM_init, SPECTRUM_update, SPECTRUM_render, SPECTRUM_key},
    {"Still", STILL_init, STILL_update, STILL_render, STILL_key},
    {"FInput", FINPUT_init, NULL, FINPUT_render, FINPUT_key},
    {"MainMenu", MAINMENU_init, NULL, MAINMENU_render, MAINMENU_key},
    /* {"Scanlist", NULL, SCANLIST_update, SCANLIST_render, SCANLIST_key},
    {"A to B scanner", ABSCANNER_init, ABSCANNER_update, ABSCANNER_render,
     ABSCANNER_key}, */
};

void APPS_key(KEY_Code_t Key, bool bKeyPressed, bool bKeyHeld) {
  if (apps[gCurrentApp].key) {
    apps[gCurrentApp].key(Key, bKeyPressed, bKeyHeld);
  }
}
void APPS_init(AppType_t app) {
  if (apps[app].init) {
    apps[app].init();
  }
}
void APPS_update(void) {
  if (apps[gCurrentApp].update) {
    apps[gCurrentApp].update();
  }
}
void APPS_render(void) {
  if (apps[gCurrentApp].render) {
    apps[gCurrentApp].render();
  }
}
void APPS_run(AppType_t app) {
  APPS_init(app);
  gCurrentApp = app;
}