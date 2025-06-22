/*
 * 아두이노 ST7920 시계
 * Mega용
 * https://github.com/alsoduck/advanced-st7920-clock
 * GPL-3.0
 * 
 */
#include <Arduino.h>
#include <U8g2lib.h>
#include <RTClib.h>
RTC_DS3231 rtc;
PROGMEM const uint8_t gulim[340] U8G2_FONT_SECTION("gulim") = 
  "\21\0\3\2\4\4\3\1\5\15\15\0\377\13\377\14\377\0\0\0\0\0\225 \5\0\214\1\60\14\267\215"
  "\265UR\277&Y\66\1\61\10\263\216\65D\375\3\62\13\267\215\265UR\265\237\207!\63\20\267\215\265"
  "U\322\332\16\344@\254&Y\66\1\64\22\267\215\247\212I\230dQ\26\325\242a\10\343\22\0\65\20\267"
  "\215q\211\313\203\24\346@\34\213\321\20\1\66\20\267\215\265UR\71\231\264$\265&Y\66\1\67\15\267"
  "\215q\210\323\70\215\253q\33\0\70\20\267\215\265U\322$\313\266JjM\262l\2\71\20\267\215\265U"
  "Rk\222IK\254&Y\66\1\0\0\0\4\377\377\261D\33\333\245\221C\352\260C:\244\16;\224\14"
  "C\224c\71\226\344X\216\345\340p\306$\31\274\255\67\254q\226#Q\216D\71\222\305\351\260C\71\230"
  "\203\351\360\0\306\324\36\333\245\65hI\32%i\24\15Z\216\15\207$\314\306\64\31\356`\64\14R\16"
  "\16\7\307|\33\333\245\265&Y\250fj\226da\264\346\350p\7\243a\220r,\7\207\3\310\4\35"
  "\333\245\63\14Q\230\206i&\15Y\22F\305$\314\344(\307\222\34\251c\71\70\34\326\304\30\334\245\67"
  "\354\244\341\220\223\206\65\16\343t\330)\303s\16\346`\12\0";

PROGMEM const uint8_t gulim11[420] U8G2_FONT_SECTION("gulim11") = 
  "\32\0\4\3\4\4\2\4\5\12\12\0\377\10\376\11\377\0\0\0\0\0\264 \5\0\42\5(\15\243\36"
  "\225\210\220\210\220lBb\2)\16\243\37\205\230\220\230\220,B\42B\0-\6\25r\205\2\60\13\205"
  "\243\215\211\30\275\211\230\0\61\7\203\243\25\222|\62\12\205\243\215\211\30\231<*\63\17\205\243\215\211\230"
  "\240\210\251 \231\210\11\0\64\20\205\243\25\31\221\210\220\210$\21\65A\21\0\65\15\205\243\5\243 \252"
  " \231\210\11\0\66\16\205\243\215\211\30!\212\30\65\21\23\0\67\14\205\243\205\242\230\240\64AI\0\70"
  "\17\205\243\215\211\30\231\210\211\30\65\21\23\0\71\16\205\243\215\211\30\65\21D\62\21\23\0D\15\206#"
  "\6\222\230\210 \335D\220\0\0\0\0\4\377\377\256\10\23\251\237\15\313\300\270\220\3\321\223\250\220\250\220"
  "\13\0\261D\22\250\237\205\60!\62!\262\210\212\270\210\270@\3\262\245\22\251\237\215\300H\323\3\331\232"
  "\250\220\250\230\22\0\263\304\16\231\243\25\223\300\224V\201\211\16\4\272\251\23\251\237\215\223\250\220\250\220\253"
  "\240\3Q\313\300\10\0\302\30\22\251\237\245\300\60\11\21)y\230\3\241\300D\0\306\324\23\250\237\215\31"
  "\231\10\211\231\213\220\60\303\220\222@\3\307|\24\250\237\215\31\231\20\231\220\210\231\270\10\303\220\222@\3"
  "\321\240\20\231\243\25\223\300\223\300H\253\300\240\3\1\325Y\27\252\236\225\231\310\210\213\230\210\30\211\230\220"
  "\230\231h\323\310\10\0\326T\33\252\236\225\231\310\210\213\230\210\230\220\230\20\211\230\220\230\231\240\24\27\221"
  "\21\0\0";


PROGMEM const uint8_t helv[407] U8G2_FONT_SECTION("helv") = 
  "\15\0\4\4\5\5\4\5\6\20\30\0\0\31\371\30\371\0\0\0\0\1z \6\0`\224\1-\10H"
  "$^\341A\0\60\42\17'\224\253`\252Ed\250\42\62n\310\270\21#\355_\216\30\67d\334\220a"
  "d(Z\225\260\24\0\61\16\10/\224M\324DD\36\234\232\377\177\62 \17'\224\253`\252\65\244\210"
  "\214\33A\320\244\311\301c\307\22\245\262\302\222D\311N<\370\301\7\63(\17'\224\253`\252E\243\306"
  "\214\33\62n\310\270!\343\6\217\35x\320\344a\212MZ\71b\334\20RdV%,\5\0\64&\20"
  "#\224W\364`j\213\232\34\61r\304\300!\343\306\214\33\63l\320\250\71\32\66f\334\230\7\37\14\35"
  "=\67\0\65\42\17'\224\205\15\67\203\247\35<E\261El\10\25\31\67\230\360\304&\15\242\33B\250"
  "\10#u\305\0\66.\17'\224\215$\62E\204&\33\62n\310\340\301\202\307\220\32\201\246I)\22\344"
  "F\20\64ir\204\310\21\3G\214\33\63\212\314\252\204\245\0\67\35\17'\224\341\307c\7\13\36;x"
  "\354\340\261\203\307\16\36;x\332\301\323\16\236\22\0\70+\17'\224\253`\252E\243\210\214\33\62n\310"
  "\270!\343\206\220\42CU\272ckH\21\31\67b\244-\317\15!EfU\302R\0\71+\17'\224"
  "\253`\252\65\204\212\14#An\304\300\223\66<HbX\11')\6\31\31<v\304\300\21\304\210\20"
  "\42\244*a\61\0:\11C\62L\201=\4\14\0\0\0\4\377\377\0";
/*
 * Copyright 1984-1989, 1994 Adobe Systems Incorporated. Copyright 1988, 1994 Digital Equipment Corporation.
 * Adobe is a trademark of Adobe Systems Incorporated which may be registered in certain jurisdictions. Permission to use these trademarks is hereby granted only in association with the images described in this file.
 * Permission to use, copy, modify, distribute and sell this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notices appear in all copies and that both those copyright notices and this permission notice appear in supporting documentation, and that the names of Adobe Systems and Digital Equipment Corporation not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission. Adobe Systems and Digital Equipment Corporation make no representations about the suitability of this software for any purpose. It is provided "as is" without express or implied warranty.
 * Font Copyright Statement: "Copyright (c) 1984, 1987 Adobe Systems Incorporated. All Rights Reserved. Copyright (c) 1988, 1991 Digital Equipment Corporation. All Rights Reserved."
 */

U8G2_ST7920_128X64_F_HW_SPI u8g2(U8G2_R2, /* CS=*/ 53, /* reset=*/ 50);
void setup(void) {
  pinMode(13, OUTPUT);
  u8g2.begin();
  u8g2.enableUTF8Print();
  if (! rtc.begin()) {
    while (1) delay(10);
  }
  if (rtc.lostPower()) {
  }
}

void loop(void) {
  u8g2.clearBuffer();
  // RTC 쿼리 시작
  DateTime now = rtc.now();
  uint16_t _year = now.year();
  uint8_t _month = now.month();
  uint8_t _day = now.day();
  uint8_t _hour24 = now.hour();
  uint8_t _hour12 = now.twelveHour();
  uint8_t _minute = now.minute();
  uint8_t _second = now.second();
  uint8_t _ap = now.isPM(); // 오전 = 0, 오후 = 1
  uint8_t _dow = now.dayOfTheWeek(); // 일요일 = 0, 토요일 = 6
  char _str_year[5];
  char _str_month[3];
  char _str_day[3];
  char _str_hour24[3];
  char _str_hour12[3];
  char _str_minute[3];
  char _str_second[3];
  sprintf(_str_year, "%2d", _year);
  sprintf(_str_month, "%2d", _month);
  sprintf(_str_day, "%2d", _day);
  sprintf(_str_hour24, "%02d", _hour24);
  sprintf(_str_hour12, "%2d", _hour12);
  sprintf(_str_minute, "%02d", _minute);
  sprintf(_str_second, "%02d", _second);
  const char* daysOfWeek[] = {"일", "월", "화", "수", "목", "금", "토"};
  const char* dayStr = daysOfWeek[_dow];
  
  // 수능 디데이 카운터
  const int _counter_pos = 9;
  DateTime suneung(2025, 11, 13, 0, 0, 0);
  TimeSpan remaining = suneung - now;
  u8g2.setFont(gulim11);
  // 버그때문에 나눠서 출력
  u8g2.drawUTF8(0, _counter_pos, "수");
  u8g2.drawUTF8(11, _counter_pos, "능");
  u8g2.drawUTF8(24, _counter_pos, "D-");
  char _str_remain[5];
  sprintf(_str_remain, "%d", remaining.days() + 1);
  u8g2.drawUTF8(38, _counter_pos, _str_remain);
  u8g2.drawLine(0, 11, 127, 11);
  // 큰 시계
  const int _clock_pos = 45;
  const int _hour_offset = 30;
  const int _minute_offset = 75;
  const int _second_offset = 112;
  u8g2.setFont(helv);
  u8g2.drawUTF8(63, _clock_pos, ":");
  u8g2.drawUTF8(_hour_offset, _clock_pos, _str_hour12);
  u8g2.drawUTF8(_minute_offset, _clock_pos, _str_minute);
  u8g2.setFont(gulim);
  u8g2.drawUTF8(_second_offset, _clock_pos, _str_second);
  
  if(_ap == 0){
    // 오전
    u8g2.drawUTF8(0, _clock_pos - 2, "오");
    u8g2.drawUTF8(13, _clock_pos - 2, "전");
    // 버그때문에 나눠서 출력
  }
  else{
    //오후
    u8g2.drawUTF8(0, _clock_pos - 2, "오");
    u8g2.drawUTF8(13, _clock_pos - 2, "후");
    // 버그때문에 나눠서 출력
  }
  
  // 날짜
  const int _date_pos = 63;
  const int _year_offset = 0;
  const int _month_offset = 49;
  const int _day_offset = 81;
  const int _yoil_offset = 113;
  u8g2.setFont(gulim);
  u8g2.drawUTF8(_year_offset, _date_pos, _str_year);
  u8g2.drawUTF8(_month_offset, _date_pos, _str_month);
  u8g2.drawUTF8(_day_offset, _date_pos, _str_day);
  u8g2.setFont(gulim11);
  u8g2.drawUTF8(_yoil_offset, _date_pos, "(");
  u8g2.drawUTF8(_yoil_offset + 11, _date_pos, ")");
  u8g2.setFont(gulim);
  u8g2.drawUTF8(_year_offset + 32, _date_pos, "년");
  u8g2.drawUTF8(_month_offset + 16, _date_pos, "월");
  u8g2.drawUTF8(_day_offset + 16, _date_pos, "일");
  u8g2.setFont(gulim11);
  u8g2.drawUTF8(_yoil_offset + 2, _date_pos, dayStr); 
  u8g2.sendBuffer();
  delay(50);
}
