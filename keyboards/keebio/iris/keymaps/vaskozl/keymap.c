#include QMK_KEYBOARD_H

enum layers {
    _COLEMAK = 0,
    _QWERTY,
    _FUNCTION,
};

enum custom_keycodes {
    KC_FLIP = SAFE_RANGE,
    KC_FLUP,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_FN   OSL(_FUNCTION)
#define KC_RST  RESET
#define KC_DBUG DEBUG

#define KC_COLE DF(_COLEMAK)
#define KC_QWER DF(_QWERTY)

#define KC_DREC DM_REC1
#define KC_DPLY DM_PLY1
#define KC_DSTP DM_RSTP


// Sticky (One shot) Shift keys by default. They are great.c
#define KC_LSST OSM(MOD_LSFT)
#define KC_RSST OSM(MOD_RSFT)

// Cycle through unicode operating system support (saved in EEPROM)
#define KC_UNIC UNICODE_MODE_FORWARD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC ,  1 ,  2 ,  3 ,  4 ,  5 ,                 6 ,  7 ,  8 ,  9 ,  0 ,GRV ,  
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      TAB, Q  , W  , F  , P  , G,                  J  , L  , U  ,  Y ,SCLN,ENT , 
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSST, A  , R  , S  , T  , D  ,                H  , N  , E  , I  ,  O ,RSST,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     BSLS, Z  , X  , C  , V  , B  ,CAPS,     APP , K  , M  ,COMM,DOT ,SLSH,QUOT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LALT,LCTL,BSPC,         SPC , FN ,LGUI
  //                  `----+----+----'        `----+----+----'
  ),

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC ,  1 ,  2 ,  3 ,  4 ,  5 ,                 6 ,  7 ,  8 ,  9 ,  0 ,GRV ,  
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
      TAB, Q  , W  , E  , R  , T,                  Y  , U  , I  ,  O ,  P ,ENT , 
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,RSFT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     BSLS, Z  , X  , C  , V  , B  ,CAPS,     APP , N  , M  ,COMM,DOT ,SLSH,QUOT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LALT,LCTL,BSPC,         SPC , FN ,LGUI
  //                  `----+----+----'        `----+----+----'
  ),

  [_FUNCTION] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     FLIP,LBRC,LCBR,RCBR,RBRC,VOLU,               PGUP,HOME, UP , END, DEL, INS, 
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     LSFT, EQL,PLUS,UNDS,MINS,VOLD,               PGDN,LEFT,DOWN,RGHT,BSPC,RSFT, 
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     DREC,DSTP,DPLY,COPY,PSTE,MUTE, RST,     QWER,PAUS,PSCR,WBAK,WFWD,WFAV,MUTE, 
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       RALT,RCTL,DEL ,         COLE,    , RGUI
  //                  `----+----+----'        `----+----+----'
  ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_FLIP:
      if (record->event.pressed) {
        send_unicode_string("(╯°□°)╯ ┻━┻");
      }
      return false;
      break;
    case KC_FLUP:
      if (record->event.pressed) {
        send_unicode_string("┬─┬-(º_º)");
      }
      return false;
      break;
  }
  return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {

    switch(biton32(layer_state)){
      case _FUNCTION:
          if (clockwise) {
              tap_code(KC_VOLU);
          } else {
              tap_code(KC_VOLD);
          }
          break;
      default:
          if (clockwise) {
              tap_code(KC_PGDN);
          } else {
              tap_code(KC_PGUP);
          }
          break;
    }
}
