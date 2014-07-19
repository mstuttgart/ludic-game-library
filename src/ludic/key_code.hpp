/////////////////////////////////////////////////////////////////////////////
//                                                                         //
//   Ludic Game Library                                                    //
//   Copyright (C)2014 - Michell Stuttgart Faria                           //
//                       Paulo Vicente Gomes dos Santos                    //
//                       Alfredo José de Paula Barbosa                     //
//                                                                         //
//   Ludic is FREE SOFTWARE released under the BSD License.                //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////
#pragma once

#include "sgl.hpp"
#include <cstdint>

namespace Ludic {

//////////////////////////////////////////////////////////////

enum class KeyCode : std::uint8_t {

    KEY_A = 	ALLEGRO_KEY_A,
    KEY_B = 	ALLEGRO_KEY_B,
    KEY_C = 	ALLEGRO_KEY_C,
    KEY_D = 	ALLEGRO_KEY_D,
    KEY_E =	ALLEGRO_KEY_E,
    KEY_F =	ALLEGRO_KEY_F,
    KEY_G =	ALLEGRO_KEY_G,
    KEY_H =	ALLEGRO_KEY_H,
    KEY_I =	ALLEGRO_KEY_I,
    KEY_J =	ALLEGRO_KEY_J,
    KEY_K =	ALLEGRO_KEY_K,
    KEY_L =	ALLEGRO_KEY_L,
    KEY_M =	ALLEGRO_KEY_M,
    KEY_N =	ALLEGRO_KEY_N,
    KEY_O =	ALLEGRO_KEY_O,
    KEY_P =	ALLEGRO_KEY_P,
    KEY_Q =	ALLEGRO_KEY_Q,
    KEY_R =	ALLEGRO_KEY_R,
    KEY_S =	ALLEGRO_KEY_S,
    KEY_T =	ALLEGRO_KEY_T,
    KEY_U =	ALLEGRO_KEY_U,
    KEY_V =	ALLEGRO_KEY_V,
    KEY_W =	ALLEGRO_KEY_W,
    KEY_X =	ALLEGRO_KEY_X,
    KEY_Y =	ALLEGRO_KEY_Y,
    KEY_Z =	ALLEGRO_KEY_Z,

    KEY_0 =	ALLEGRO_KEY_0,
    KEY_1 =	ALLEGRO_KEY_1,
    KEY_2 =	ALLEGRO_KEY_2,
    KEY_3 =	ALLEGRO_KEY_3,
    KEY_4 =	ALLEGRO_KEY_4,
    KEY_5 =	ALLEGRO_KEY_5,
    KEY_6 =	ALLEGRO_KEY_6,
    KEY_7 =	ALLEGRO_KEY_7,
    KEY_8 =	ALLEGRO_KEY_8,
    KEY_9 =	ALLEGRO_KEY_9,

    KEY_PAD_0 = ALLEGRO_KEY_PAD_0,
    KEY_PAD_1 =	ALLEGRO_KEY_PAD_1,
    KEY_PAD_2 =	ALLEGRO_KEY_PAD_2,
    KEY_PAD_3 =	ALLEGRO_KEY_PAD_3,
    KEY_PAD_4 =	ALLEGRO_KEY_PAD_4,
    KEY_PAD_5 =	ALLEGRO_KEY_PAD_5,
    KEY_PAD_6 =	ALLEGRO_KEY_PAD_6,
    KEY_PAD_7 =	ALLEGRO_KEY_PAD_7,
    KEY_PAD_8 =	ALLEGRO_KEY_PAD_8,
    KEY_PAD_9 =	ALLEGRO_KEY_PAD_9,

    KEY_F1 = ALLEGRO_KEY_F1,
    KEY_F2 = ALLEGRO_KEY_F2,
    KEY_F3 = ALLEGRO_KEY_F3,
    KEY_F4 = ALLEGRO_KEY_F4,
    KEY_F5 = ALLEGRO_KEY_F5,
    KEY_F6 = ALLEGRO_KEY_F6,
    KEY_F7 = ALLEGRO_KEY_F7,
    KEY_F8 = ALLEGRO_KEY_F8,
    KEY_F9 = ALLEGRO_KEY_F9,
    KEY_F10 = ALLEGRO_KEY_F10,
    KEY_F11 = ALLEGRO_KEY_F11,
    KEY_F12 = ALLEGRO_KEY_F12,

    KEY_ESCAPE      =	ALLEGRO_KEY_ESCAPE,
    KEY_TILDE       =	ALLEGRO_KEY_TILDE,
    KEY_MINUS       =	ALLEGRO_KEY_MINUS,
    KEY_EQUALS      =	ALLEGRO_KEY_EQUALS,
    KEY_BACKSPACE   =	ALLEGRO_KEY_BACKSPACE,
    KEY_TAB         =	ALLEGRO_KEY_TAB,
    KEY_OPENBRACE   =	ALLEGRO_KEY_OPENBRACE,
    KEY_CLOSERBRACE =	ALLEGRO_KEY_CLOSEBRACE,
    KEY_ENTER       =	ALLEGRO_KEY_ENTER,
    KEY_SEMICOLON   =	ALLEGRO_KEY_SEMICOLON,
    KEY_QUOTE       =	ALLEGRO_KEY_QUOTE,
    KEY_BACKSLASH   =	ALLEGRO_KEY_BACKSLASH,
    KEY_BACKSLASH2  =	ALLEGRO_KEY_BACKSLASH2,
    KEY_COMMA       =	ALLEGRO_KEY_COMMA,
    KEY_FULLSTOP    =	ALLEGRO_KEY_FULLSTOP,
    KEY_SLASH       =	ALLEGRO_KEY_SLASH,
    KEY_SPACE       =	ALLEGRO_KEY_SPACE,

    KEY_INSERT 	=	ALLEGRO_KEY_INSERT,
    KEY_DELETE 	=	ALLEGRO_KEY_DELETE,
    KEY_HOME 	=	ALLEGRO_KEY_HOME,
    KEY_END 	=	ALLEGRO_KEY_END,
    KEY_PGUP 	=	ALLEGRO_KEY_PGUP,
    KEY_PGDN 	=	ALLEGRO_KEY_PGDN,
    KEY_LEFT 	=	ALLEGRO_KEY_LEFT,
    KEY_RIGHT 	=	ALLEGRO_KEY_RIGHT,
    KEY_UP 		=	ALLEGRO_KEY_UP,
    KEY_DOWN 	=	ALLEGRO_KEY_DOWN,

    KEY_PAD_SLASH 		=	ALLEGRO_KEY_PAD_SLASH,
    KEY_PAD_ASTERISK 	=	ALLEGRO_KEY_PAD_ASTERISK,
    KEY_PAD_MINUS 		=	ALLEGRO_KEY_PAD_MINUS,
    KEY_PAD_PLUS 		=	ALLEGRO_KEY_PAD_PLUS,
    KEY_PAD_DELETE 		=	ALLEGRO_KEY_PAD_DELETE,
    KEY_PAD_ENTER 		=	ALLEGRO_KEY_PAD_ENTER,

    KEY_PRINTSCREEN 	=	ALLEGRO_KEY_PRINTSCREEN,
    KEY_PAUSE 			=	ALLEGRO_KEY_PAUSE,

    KEY_ABNT_C1 	=	ALLEGRO_KEY_ABNT_C1,
    KEY_YEN 		=	ALLEGRO_KEY_YEN,
    KEY_KANA 		=	ALLEGRO_KEY_KANA,
    KEY_CONVERT 	=	ALLEGRO_KEY_CONVERT,
    KEY_NOCONVERT 	=	ALLEGRO_KEY_NOCONVERT,
    KEY_AT 			=	ALLEGRO_KEY_AT,
    KEY_CIRCUMFLEX 	=	ALLEGRO_KEY_CIRCUMFLEX,
    KEY_COLON2 		=	ALLEGRO_KEY_COLON2,
    KEY_KANJI 		=	ALLEGRO_KEY_KANJI,

    KEY_PAD_EQUALS 	=	ALLEGRO_KEY_PAD_EQUALS,  /* MacOS X */
    KEY_BACKQUOTE 	=	ALLEGRO_KEY_BACKQUOTE,   /* MacOS X */
    KEY_SEMICOLON2 	=	ALLEGRO_KEY_SEMICOLON2,  /* MacOS X -- TODO: ask lillo what this should be */
    KEY_COMMAND 	=	ALLEGRO_KEY_COMMAND,     /* MacOS X */
    KEY_UNKNOWN 	=	ALLEGRO_KEY_UNKNOWN,

    /* All codes up to before KEY_MODIFIERS can be freely
     * assignedas additional unknown keys, like various multimedia
     * and application keys keyboards may have.
     */

    KEY_MODIFIERS =	ALLEGRO_KEY_MODIFIERS,

    KEY_LSHIFT 	=	ALLEGRO_KEY_LSHIFT,
    KEY_RSHIFT 	=	ALLEGRO_KEY_RSHIFT,
    KEY_LCTRL 	=	ALLEGRO_KEY_LCTRL,
    KEY_RCTRL	=	ALLEGRO_KEY_RCTRL,
    KEY_ALT	 	=	ALLEGRO_KEY_ALT,
    KEY_ALTGR  	=	ALLEGRO_KEY_ALTGR,
    KEY_LWIN  	=	ALLEGRO_KEY_LWIN,
    KEY_RWIN  	=	ALLEGRO_KEY_RWIN,
    KEY_MENU  	=	ALLEGRO_KEY_MENU,
    KEY_SCROLLLOCK 	=	ALLEGRO_KEY_SCROLLLOCK,
    KEY_NUMLOCK		=	ALLEGRO_KEY_NUMLOCK,
    KEY_CAPSLOCK	=	ALLEGRO_KEY_CAPSLOCK,

    KEY_MAX	 =	ALLEGRO_KEY_MAX
};

//////////////////////////////////////////////////////////////

enum class KeyMod: std::uint16_t {
    KEYMOD_SHIFT       = ALLEGRO_KEYMOD_SHIFT,
    KEYMOD_CTRL        = ALLEGRO_KEYMOD_CTRL,
    KEYMOD_ALT         = ALLEGRO_KEYMOD_ALT,
    KEYMOD_LWIN        = ALLEGRO_KEYMOD_LWIN,
    KEYMOD_RWIN        = ALLEGRO_KEYMOD_RWIN,
    KEYMOD_MENU        = ALLEGRO_KEYMOD_MENU,
    KEYMOD_ALTGR       = ALLEGRO_KEYMOD_ALTGR,
    KEYMOD_COMMAND     = ALLEGRO_KEYMOD_COMMAND,
    KEYMOD_SCROLLLOCK  = ALLEGRO_KEYMOD_SCROLLLOCK,
    KEYMOD_NUMLOCK     = ALLEGRO_KEYMOD_NUMLOCK,
    KEYMOD_CAPSLOCK    = ALLEGRO_KEYMOD_CAPSLOCK,
    KEYMOD_INALTSEQ    = ALLEGRO_KEYMOD_INALTSEQ,
    KEYMOD_ACCENT1     = ALLEGRO_KEYMOD_ACCENT1,
    KEYMOD_ACCENT2     = ALLEGRO_KEYMOD_ACCENT2,
    KEYMOD_ACCENT3     = ALLEGRO_KEYMOD_ACCENT3,
    KEYMOD_ACCENT4     = ALLEGRO_KEYMOD_ACCENT4
};


//////////////////////////////////////////////////////////////

} /* namespace */
