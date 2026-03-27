#define TAPPING_TERM 200

// When the user holds a key after tapping it, the tapping function is repeated by default, rather than activating the hold function. This allows keeping the ability to auto-repeat the tapping function of a dual-role key. QUICK_TAP_TERM enables fine tuning of that ability. If set to 0, it will remove the auto-repeat ability and activate the hold function instead.
#define QUICK_TAP_TERM 120 // https://docs.qmk.fm/tap_hold#quick-tap-term

//This mode makes tap and hold keys (like Layer-Tap) work better for fast typists, or for high TAPPING_TERM settings. Compared to the "permissive hold" mode, this mode selects the hold action in more cases.
//If you press a dual-role key, press another key, and then release the dual-role key, all within the tapping term, by default the dual-role key will perform its tap action. If the HOLD_ON_OTHER_KEY_PRESS option is enabled, the dual-role key will perform its hold action instead.
// #define HOLD_ON_OTHER_KEY_PRESS // https://docs.qmk.fm/tap_hold#hold-on-other-key-press
