#include QMK_KEYBOARD_H

enum layers {
    _COLEMAK = 0,
    _QWERTY,
    _FUNCTION,
    _UNICODE,
};

enum custom_keycodes {
    KC_FLIP = SAFE_RANGE,
    KC_FLUP,
};

#define KC_ KC_TRNS
#define _______ KC_TRNS

#define KC_FN   MO(_FUNCTION)
#define KC_RST  RESET
#define KC_DBUG DEBUG

#define KC_UN   MO(_UNICODE)

#define KC_COLE DF(_COLEMAK)
#define KC_QWER DF(_QWERTY)

#define KC_DREC DM_REC1
#define KC_DPLY DM_PLY1
#define KC_DSTP DM_RSTP


//#define UC_ UC(0x00AB) // «	
//#define UC_ UC(0x00AF) // ¯	
//#define UC_ UC(0x00BB) // »	
//#define UC_ UC(0x00D7) // ×	
//#define UC_ UC(0x00F7) // ÷	
//#define UC_ UC(0x2018) // ‘	
//#define UC_ UC(0x2019) // ’	
//#define UC_ UC(0x201A) // ‚	
//#define UC_ UC(0x201C) // “	
//#define UC_ UC(0x201D) // ”	
//#define UC_ UC(0x201E) // „	
//#define UC_ UC(0x2026) // …	
//#define UC_ UC(0x207A) // ⁺	
//#define UC_ UC(0x207B) // ⁻	
//#define UC_ UC(0x2212) // −	
//#define UC_ UC(0x2216) // ∖	
//#define UC_ UC(0x2218) // ∘	
//#define UC_ UC(0x2245) // ≅	
//#define UC_ UC(0x2260) // ≠	
//#define UC_ UC(0x2261) // ≡	
//#define UC_ UC(0x2262) // ≢	
//#define UC_ UC(0x2264) // ≤	
//#define UC_ UC(0x2265) // ≥	
//#define UC_ UC(0x2282) // ⊂	
//#define UC_ UC(0x2283) // ⊃	
//#define UC_ UC(0x2284) // ⊄	
//#define UC_ UC(0x2285) // ⊅	
//#define UC_ UC(0x2286) // ⊆	
//#define UC_ UC(0x2287) // ⊇	
//#define UC_ UC(0x2288) // ⊈	
//#define UC_ UC(0x2289) // ⊉	
//#define UC_ UC(0x228D) // ⊍	
//#define UC_ UC(0x228E) // ⊎	

enum unicode_names {
    INF,
    PI,
    TAU,
    ELEM,
    NELE,
    CONT,
    NCON,
    SET,
    SSD,
    DI0,
    DI1,
    DI2,
    DI3,
    DI4,
    DI5,
    DI6,
    DI7,
    DI8,
    DI9,
    QL,
    QR,
    GUIL,
    GUIR,
    INTER,
    UNION,
    SUBS, 
    NSUBS,
    SUPS, 
    NSUPS,
};

const uint32_t PROGMEM unicode_map[] = {
    [INF] = 0x221E, // ∞	
    
    [PI] = 0x03C0, // π	
    [TAU] = 0x03C4, // τ	
    
    [ELEM] = 0x2208, // ∈	
    [NELE] = 0x2209, // ∉	
    
    [CONT] = 0x220B, // ∋	
    [NCON] = 0x220C, // ∌	
    
    [SET] = 0x2205, // ∅ Empty set	
    
    [SSD] = 0x2296, // ⊖ Symetric Set difference
    
    [DI0] = 0x2070, // ⁰	
    [DI1] = 0x00B9, // ¹	
    [DI2] = 0x00B2, // ²	
    [DI3] = 0x00B3, // ³	
    [DI4] = 0x2074, // ⁴	
    [DI5] = 0x2075, // ⁵	
    [DI6] = 0x2076, // ⁶	
    [DI7] = 0x2077, // ⁷	
    [DI8] = 0x2078, // ⁸	
    [DI9] = 0x2079, // ⁹	
    [QL] = 0xFF62, // ｢	
    [QR] = 0xFF63, // ｣	
    
    [GUIL] = 0xAB, // «
    [GUIR] = 0xBB, // »

    [INTER] = 0x2229, //∩
    [UNION] = 0x222A, //∪

    [SUBS] = 0x2282, //⊂
    [SUPS] = 0x2283, //⊃
    [NSUBS] = 0x2284, //⊄
    [NSUPS] = 0x2285, //⊅
};


// Sticky (One shot) Shift keys by default. They are great.
//#define KC_LSST OSM(MOD_LSFT)
//#define KC_RSST OSM(MOD_RSFT)

// Cycle through unicode operating system support (saved in EEPROM)
#define KC_UNIC UNICODE_MODE_FORWARD

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_COLEMAK] = LAYOUT(
     KC_ESC , KC_1  , KC_2 ,  KC_3 ,  KC_4 ,  KC_5 ,                 KC_6,    KC_7, KC_8, KC_9 ,KC_0 ,  KC_GRV ,  
     KC_TAB , KC_Q  , KC_W  , KC_F  , KC_P  , KC_G,                  KC_J  ,  KC_L, KC_U, KC_Y ,KC_SCLN,KC_ENT , 
     KC_LSFT, KC_A  , KC_R  , KC_S  , KC_T  , KC_D  ,                KC_H  ,  KC_N, KC_E, KC_I ,KC_O ,  KC_RSFT,
     KC_BSLS, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  , KC_LGUI,     KC_RGUI , KC_K  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_QUOT,
                       KC_LALT,KC_LCTL,KC_BSPC,                       KC_SPC , KC_FN ,KC_UN  
  ),

  [_QWERTY] = LAYOUT(
     KC_ESC ,  KC_1 ,  KC_2 ,  KC_3 ,  KC_4 ,  KC_5 ,                 KC_6 ,  KC_7 ,  KC_8 ,  KC_9 ,  KC_0 ,KC_GRV ,  
      KC_TAB, KC_Q  , KC_W  , KC_E  , KC_R  , KC_T,                  KC_Y  , KC_U  , KC_I  ,  KC_O ,  KC_P ,KC_ENT , 
     KC_LSFT, KC_A  , KC_S  , KC_D  , KC_F  , KC_G  ,                KC_H  , KC_J  , KC_K  , KC_L  ,KC_SCLN,KC_RSFT,
     KC_BSLS, KC_Z  , KC_X  , KC_C  , KC_V  , KC_B  ,KC_CAPS,     KC_APP , KC_N  , KC_M  ,KC_COMM,KC_DOT ,KC_SLSH,KC_QUOT,
                       KC_LALT,KC_LCTL,KC_BSPC,         KC_SPC , KC_FN ,KC_UN
  ),

  [_FUNCTION] = LAYOUT(
     KC_F12 , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                KC_F6 , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
     KC_TAB ,KC_LBRC,KC_LCBR,KC_RCBR,KC_RBRC,KC_VOLU,               KC_PGUP,KC_HOME, KC_UP , KC_END, KC_DEL, KC_INS, 
     KC_LSFT, KC_EQL,KC_PLUS,KC_UNDS,KC_MINS,KC_VOLD,               KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT,KC_BSPC,KC_RSFT, 
     KC_DREC,KC_DSTP,KC_DPLY,KC_COPY,KC_PSTE,KC_MUTE, KC_RST,     KC_QWER,KC_PAUS,KC_PSCR,KC_WBAK,KC_WFWD,KC_WFAV,KC_MUTE, 
                       KC_RALT,KC_RCTL,KC_DEL ,         KC_COLE,KC_TRNS, KC_UN
  ),

  [_UNICODE] = LAYOUT(
     X(DI1)  , X(DI1) , X(DI2) , X(DI3) , X(DI4) , X(DI5) ,                X(DI6) , X(DI7) , X(DI8) , X(DI9) ,X(DI0) ,X(DI1) ,
     KC_UNIC,X(QL)  ,X(QL)  ,X(QR)  ,X(PI)  ,KC_VOLU,               KC_PGUP,KC_HOME, XP(UNION,INTER) , KC_END, KC_DEL, KC_INS, 
     KC_LSFT, KC_EQL,KC_PLUS,KC_UNDS,X(TAU) ,KC_VOLD,               KC_PGDN,X(NELE),XP(ELEM,NELE),X(INF) ,KC_BSPC,KC_RSFT, 
     KC_DREC,KC_DSTP,KC_DPLY,XP(CONT,NCON),KC_PSTE,KC_MUTE, KC_RST,     KC_QWER,KC_PAUS,XP(SUBS,NSUBS),X(GUIL),X(GUIR),XP(SUPS,NSUPS),KC_MUTE,
                       KC_RALT,KC_RCTL,KC_DEL ,         KC_COLE,KC_TRNS,KC_UN
  ),

};

/*
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

*/
