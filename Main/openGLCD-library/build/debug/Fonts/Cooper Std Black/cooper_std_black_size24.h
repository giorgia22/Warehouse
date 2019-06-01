

/*
 *
 * new Font
 *
 * created with GLCDFontCreator
 * original framework by F. Maximilian Thiele
 * Modified By Siddharth Kaul
 *
 *
 * File Name           : cooper_std_black_size24.h
 * Date                : 10.11.2012
 * Font size in bytes  : 34188
 * Font width          : 10
 * Font height         : 26
 * Font first char     : 32
 * Font last char      : 128
 * Font used chars     : 96
 *
 * The font data are defined as
 *
 * struct _FONT_ {
 *     uint16_t   font_Size_in_Bytes_over_all_included_Size_it_self;
 *     uint8_t    font_Width_in_Pixel_for_fixed_drawing;
 *     uint8_t    font_Height_in_Pixel_for_all_characters;
 *     unit8_t    font_First_Char;
 *     uint8_t    font_Char_Count;
 *
 *     uint8_t    font_Char_Widths[font_Last_Char - font_First_Char +1];
 *                  // for each character the separate width in pixels,
 *                  // characters < 128 have an implicit virtual right empty row
 *
 *     uint8_t    font_data[];
 *                  // bit field of all characters
 */

#include <inttypes.h>
#include <avr/pgmspace.h>

#ifndef NEW_FONT_H
#define NEW_FONT_H

#define NEW_FONT_WIDTH 10
#define NEW_FONT_HEIGHT 26

static uint8_t new_Font[] PROGMEM = {
    0x85, 0x8C, // size
    0x0A, // width
    0x1A, // height
    0x20, // first char
    0x60, // char count
    
    // char widths
    0x00, 0x05, 0x0C, 0x09, 0x0C, 0x14, 0x16, 0x05, 0x0A, 0x0A, 
    0x09, 0x0B, 0x06, 0x07, 0x05, 0x0C, 0x0D, 0x0D, 0x0E, 0x0F, 
    0x0F, 0x0E, 0x0E, 0x0E, 0x0E, 0x0D, 0x05, 0x06, 0x0C, 0x0C, 
    0x0C, 0x0B, 0x11, 0x14, 0x11, 0x11, 0x12, 0x10, 0x10, 0x13, 
    0x13, 0x09, 0x0F, 0x14, 0x0F, 0x16, 0x14, 0x12, 0x10, 0x12, 
    0x14, 0x0F, 0x12, 0x14, 0x15, 0x1A, 0x14, 0x13, 0x11, 0x09, 
    0x0C, 0x09, 0x0C, 0x0C, 0x07, 0x0D, 0x0F, 0x0C, 0x0F, 0x0C, 
    0x0A, 0x0E, 0x11, 0x08, 0x07, 0x12, 0x08, 0x18, 0x0F, 0x0E, 
    0x10, 0x10, 0x0D, 0x0A, 0x0B, 0x10, 0x0F, 0x18, 0x0F, 0x0F, 
    0x0D, 0x09, 0x03, 0x09, 0x0B, 0x0C, 
    
    // font data
    0xF0, 0xF8, 0xF8, 0xF8, 0xF0, 0x01, 0x8F, 0x9F, 0x8F, 0x03, 0x07, 0x0F, 0x0F, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, // 33
    0xF0, 0xF8, 0xF8, 0xF8, 0xF0, 0x00, 0x00, 0xF0, 0xF8, 0xF8, 0xF8, 0xF0, 0x01, 0x07, 0x0F, 0x07, 0x01, 0x00, 0x00, 0x01, 0x07, 0x0F, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 34
    0x00, 0x00, 0x00, 0xC0, 0x40, 0x00, 0xC0, 0xC0, 0x00, 0xCC, 0xCC, 0xFC, 0xFF, 0xCC, 0xFC, 0xFF, 0xCD, 0xCC, 0x00, 0x0E, 0x0F, 0x00, 0x08, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 35
    0x00, 0x80, 0xC0, 0xC0, 0xF0, 0xF0, 0xF0, 0xC0, 0xC0, 0xC0, 0xC0, 0x00, 0x8F, 0x3F, 0x3F, 0x7F, 0x7F, 0xFC, 0xFC, 0xF8, 0xF9, 0xF3, 0xE3, 0xC3, 0x07, 0x0F, 0x1E, 0x1C, 0x7C, 0x7C, 0x7C, 0x1F, 0x1F, 0x0F, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 36
    0xC0, 0xF0, 0xF0, 0xF8, 0x18, 0x38, 0xF8, 0xF0, 0xF0, 0xE0, 0x00, 0x80, 0xE0, 0x70, 0x38, 0x08, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x07, 0x0F, 0x0F, 0x0E, 0x87, 0xC7, 0x73, 0x3D, 0xCE, 0xF7, 0xF1, 0xF8, 0x18, 0x38, 0xF8, 0xF0, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0E, 0x07, 0x01, 0x00, 0x00, 0x01, 0x07, 0x07, 0x0F, 0x0F, 0x0E, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 37
    0x00, 0x00, 0xE0, 0xF0, 0xF8, 0xF8, 0xFC, 0x1C, 0x1C, 0x1C, 0x38, 0x38, 0x00, 0x00, 0x00, 0x20, 0xB0, 0xF8, 0xF8, 0xF8, 0xF0, 0xE0, 0x70, 0xFC, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xC7, 0x07, 0x02, 0x70, 0x3C, 0x1E, 0x1F, 0x9F, 0xFF, 0xFF, 0xFF, 0xF7, 0x63, 0x01, 0x00, 0x00, 0x01, 0x03, 0x03, 0x07, 0x07, 0x07, 0x0F, 0x0F, 0x0F, 0x0E, 0x0E, 0x0E, 0x07, 0x07, 0x07, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 38
    0xF0, 0xF8, 0xF8, 0xF8, 0xF0, 0x01, 0x07, 0x0F, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 39
    0x00, 0xE0, 0xF8, 0xFC, 0xFE, 0x7E, 0x0F, 0x07, 0x07, 0x07, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0F, 0x1F, 0x3F, 0x3F, 0x78, 0x70, 0x70, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 40
    0x07, 0x07, 0x07, 0x0F, 0x7E, 0xFE, 0xFC, 0xF8, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x70, 0x70, 0x70, 0x78, 0x3F, 0x3F, 0x1F, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 41
    0x60, 0xE0, 0xE0, 0xF8, 0xF8, 0xC0, 0xE0, 0xE0, 0x40, 0x04, 0x0E, 0x07, 0x03, 0x07, 0x0F, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 42
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x70, 0x70, 0x70, 0xFF, 0xFF, 0xFF, 0x70, 0x70, 0x70, 0x70, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 43
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xC0, 0xC0, 0x00, 0x01, 0x07, 0xCF, 0xFF, 0x7F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 44
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 45
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xC0, 0x80, 0x80, 0x07, 0x0F, 0x0F, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, // 46
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF8, 0x78, 0x18, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF8, 0x7E, 0x1F, 0x07, 0x01, 0x00, 0x00, 0x60, 0x78, 0x7E, 0x3F, 0x0F, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 47
    0x00, 0x00, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x78, 0xFF, 0xFF, 0xFF, 0xFF, 0xC3, 0x03, 0x0F, 0xFF, 0xFF, 0xFF, 0xFE, 0x78, 0x00, 0x01, 0x03, 0x07, 0x07, 0x0F, 0x0F, 0x0F, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 48
    0x00, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0x40, 0x00, 0x00, 0x01, 0x01, 0x01, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x02, 0x06, 0x06, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 49
    0x00, 0x00, 0x80, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x80, 0x00, 0x00, 0x04, 0x07, 0x07, 0x83, 0xC3, 0xE3, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x1F, 0x87, 0x80, 0x0C, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x1F, 0x1F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 50
    0x00, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0x03, 0xE1, 0xE1, 0xF3, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0xE0, 0xC0, 0x80, 0x20, 0x30, 0x70, 0x70, 0x70, 0x70, 0x70, 0x78, 0x7F, 0x3F, 0x3F, 0x3F, 0x1F, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 51
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0x70, 0x18, 0x0C, 0x06, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x7F, 0x7F, 0x7F, 0x7F, 0x7F, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 52
    0x00, 0x00, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x70, 0xFE, 0xFF, 0xFF, 0xFF, 0xFB, 0xF3, 0xF3, 0xF3, 0xF3, 0xE3, 0xE3, 0xC3, 0x81, 0x18, 0x30, 0x70, 0x70, 0x70, 0x79, 0x7F, 0x7F, 0x3F, 0x3F, 0x3F, 0x1F, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 53
    0x00, 0x00, 0x80, 0xE0, 0xF0, 0xF0, 0xE0, 0x60, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0x1F, 0x1C, 0x1C, 0x3E, 0xFE, 0xFC, 0xFC, 0xF8, 0xF0, 0x00, 0x03, 0x07, 0x07, 0x07, 0x0F, 0x0E, 0x0E, 0x0E, 0x07, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 54
    0x80, 0xC0, 0xE0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x0F, 0x0F, 0x0F, 0x07, 0x07, 0x07, 0x07, 0x87, 0xE7, 0xFF, 0xFF, 0x7F, 0x0F, 0x01, 0x00, 0x00, 0x00, 0x00, 0x60, 0x78, 0x7E, 0xFF, 0x7F, 0x1F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 55
    0x00, 0x00, 0xC0, 0xE0, 0xE0, 0xF0, 0xF0, 0x70, 0x70, 0x70, 0xE0, 0xE0, 0xE0, 0xC0, 0xC0, 0xE7, 0xFF, 0xFF, 0x3F, 0x3F, 0x3F, 0x3E, 0x7E, 0xFC, 0xFF, 0xFF, 0xFF, 0xE7, 0x00, 0x03, 0x07, 0x07, 0x07, 0x0F, 0x0E, 0x0E, 0x0E, 0x0F, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 56
    0x00, 0x00, 0x80, 0x80, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0x80, 0x80, 0x00, 0x00, 0x3C, 0xFF, 0xFF, 0xFF, 0xFF, 0xE3, 0xC3, 0xC7, 0xFF, 0xFF, 0xFF, 0xFF, 0x7C, 0x00, 0x00, 0x00, 0x21, 0x31, 0x79, 0x7F, 0x3F, 0x1F, 0x0F, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 57
    0x00, 0x80, 0x80, 0x80, 0x00, 0x0F, 0x9F, 0xDF, 0x9F, 0x0F, 0x07, 0x0F, 0x0F, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, // 58
    0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x0F, 0x9F, 0xDF, 0xDF, 0xCF, 0x02, 0x01, 0x07, 0xCF, 0xFF, 0x7F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 59
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xF0, 0xF0, 0xF8, 0xF8, 0xDC, 0x9C, 0x9C, 0x8E, 0x0E, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x03, 0x07, 0x07, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 60
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9C, 0x9C, 0x9C, 0x9C, 0x9C, 0x9C, 0x9C, 0x9C, 0x9C, 0x9C, 0x9C, 0x9C, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 61
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x0E, 0x8E, 0x9C, 0x9C, 0xDC, 0xF8, 0xF8, 0xF0, 0xF0, 0x70, 0x0E, 0x07, 0x07, 0x03, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 62
    0xC0, 0xE0, 0xF0, 0xF0, 0x78, 0x38, 0xF8, 0xF8, 0xF0, 0xE0, 0xC0, 0x01, 0x03, 0x01, 0x81, 0x9C, 0xBE, 0x1F, 0x0F, 0x07, 0x03, 0x01, 0x00, 0x00, 0x07, 0x0F, 0x0F, 0x0F, 0x07, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 63
    0x00, 0x80, 0xC0, 0x60, 0x30, 0x30, 0x10, 0x18, 0x18, 0x18, 0x18, 0x30, 0xB0, 0x30, 0xE0, 0xC0, 0x00, 0x7E, 0xFF, 0x80, 0xF0, 0xF8, 0xFE, 0xFE, 0x4F, 0xF3, 0xFE, 0xFF, 0x7F, 0x63, 0x70, 0x38, 0x1F, 0x07, 0x00, 0x01, 0x03, 0x07, 0x06, 0x0E, 0x0C, 0x0C, 0x0C, 0x0C, 0x06, 0x06, 0x02, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 64
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xF8, 0xF8, 0xF8, 0xF8, 0xF0, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xF8, 0xFF, 0xFF, 0xE3, 0xE3, 0xE7, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xF8, 0xE0, 0x80, 0x00, 0x00, 0x0C, 0x0E, 0x0F, 0x0F, 0x0F, 0x0C, 0x08, 0x00, 0x00, 0x00, 0x04, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 65
    0x10, 0x38, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x38, 0x38, 0x78, 0xF8, 0xF8, 0xF0, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1C, 0x1C, 0x3E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF9, 0xF0, 0xE0, 0x04, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x0E, 0x0E, 0x0F, 0x0F, 0x0F, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 66
    0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF0, 0x70, 0x38, 0x38, 0x38, 0x78, 0x78, 0xF0, 0xF0, 0xF0, 0xF0, 0xE0, 0x3E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xC0, 0x80, 0x80, 0x00, 0x00, 0x00, 0x83, 0x83, 0xC3, 0x81, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 67
    0x10, 0x38, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x38, 0x38, 0x38, 0x78, 0xF8, 0xF0, 0xF0, 0xE0, 0xE0, 0xC0, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x81, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3E, 0x0E, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x0E, 0x0E, 0x0F, 0x0F, 0x07, 0x07, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 68
    0x30, 0x78, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x38, 0x38, 0x38, 0x38, 0x38, 0x78, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1C, 0x1C, 0x7F, 0x7F, 0x3E, 0x00, 0x00, 0xC0, 0x80, 0x0C, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0F, 0x0F, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 69
    0x10, 0x38, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x78, 0x38, 0x38, 0x38, 0x38, 0x78, 0x78, 0xF8, 0xF0, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1C, 0x1C, 0x3C, 0x7F, 0x7F, 0x3E, 0x00, 0x01, 0x01, 0x0C, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x0C, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 70
    0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF0, 0xF0, 0x78, 0x38, 0x38, 0x38, 0x78, 0x78, 0xF8, 0xF8, 0xF8, 0xE0, 0x00, 0x00, 0x3E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x80, 0x00, 0x20, 0x30, 0x38, 0xF8, 0xF8, 0xF9, 0xF9, 0xF8, 0x38, 0x30, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x0F, 0x0F, 0x0E, 0x0E, 0x0F, 0x07, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 71
    0x20, 0x30, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x38, 0x30, 0x00, 0x10, 0x38, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x38, 0x10, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1C, 0x1C, 0x1C, 0x1C, 0x1C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x04, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x06, 0x04, 0x00, 0x04, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 72
    0x30, 0x38, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x38, 0x10, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x04, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 73
    0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x30, 0x78, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x38, 0x10, 0xC0, 0xE0, 0xE0, 0xE0, 0xC0, 0x00, 0x00, 0x80, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x0F, 0x0E, 0x0E, 0x0F, 0x0F, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 74
    0x30, 0x78, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x38, 0x20, 0x80, 0xF0, 0xF8, 0xF8, 0x78, 0x78, 0x38, 0x38, 0x30, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7E, 0x7F, 0x7F, 0xFF, 0xFF, 0xFD, 0xF8, 0xF0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x04, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x04, 0x00, 0x00, 0x03, 0x07, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 75
    0x30, 0x38, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xC0, 0x80, 0x0C, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x0E, 0x0E, 0x0F, 0x0F, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 76
    0x10, 0x38, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x80, 0xE0, 0xF0, 0xF8, 0xF8, 0xF8, 0xF8, 0x38, 0x10, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x0F, 0x1F, 0x7F, 0xFF, 0xFF, 0xFE, 0xFC, 0x7E, 0x1F, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x04, 0x0E, 0x0F, 0x0F, 0x0F, 0x0E, 0x04, 0x00, 0x01, 0x07, 0x07, 0x01, 0x00, 0x04, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 77
    0x30, 0x78, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x10, 0x38, 0xF8, 0xF8, 0xF8, 0x38, 0x10, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x0F, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF, 0xFE, 0xFE, 0xFC, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x04, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x04, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 78
    0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF0, 0xF0, 0x78, 0x78, 0xF8, 0xF8, 0xF0, 0xF0, 0xF0, 0xE0, 0xC0, 0x80, 0x00, 0x1E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xC0, 0x80, 0x00, 0x01, 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3C, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 79
    0x30, 0x38, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x38, 0x38, 0x38, 0x78, 0xF8, 0xF0, 0xF0, 0xE0, 0x80, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x38, 0x38, 0x38, 0x3C, 0x3F, 0x1F, 0x1F, 0x0F, 0x03, 0x04, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 80
    0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF0, 0xF0, 0x78, 0x78, 0xF8, 0xF8, 0xF0, 0xF0, 0xE0, 0xE0, 0xC0, 0x80, 0x00, 0x3C, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0x80, 0x00, 0x00, 0x01, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7C, 0x18, 0x1C, 0x1D, 0x1F, 0x3F, 0x3F, 0x7F, 0x7F, 0x7F, 0x7E, 0xFE, 0xFF, 0xFF, 0xE7, 0xE3, 0x63, 0x61, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 81
    0x10, 0x38, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x38, 0x38, 0x38, 0x78, 0xF8, 0xF8, 0xF8, 0xF0, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x1C, 0x1C, 0x1C, 0x3E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF3, 0xE1, 0xC0, 0x00, 0x00, 0x04, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x0C, 0x00, 0x00, 0x00, 0x07, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 82
    0x80, 0xE0, 0xF0, 0xF0, 0xF0, 0xF8, 0xF8, 0x38, 0x38, 0x38, 0x78, 0xF8, 0xF8, 0xF0, 0xC0, 0xE3, 0xCF, 0x9F, 0x1F, 0x3F, 0x3F, 0x3F, 0x7F, 0xFE, 0xFE, 0xFE, 0xFC, 0xFC, 0xF9, 0xF0, 0x03, 0x07, 0x07, 0x0F, 0x0F, 0x0E, 0x0E, 0x0E, 0x0F, 0x0F, 0x07, 0x07, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 83
    0x80, 0xF0, 0xF8, 0xF8, 0x78, 0x38, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x38, 0x38, 0xF8, 0xF8, 0xF0, 0xE0, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 84
    0x10, 0x38, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x38, 0x10, 0x00, 0x00, 0x00, 0x10, 0x38, 0xF8, 0xF8, 0xF8, 0x38, 0x10, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x80, 0x80, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x07, 0x07, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 85
    0x30, 0x30, 0x78, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x10, 0x00, 0x00, 0x00, 0x10, 0xF8, 0xF8, 0xF8, 0xF8, 0x38, 0x18, 0x18, 0x00, 0x00, 0x00, 0x03, 0x0F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xF8, 0xFC, 0x7F, 0x1F, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0F, 0x0F, 0x0F, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 86
    0x30, 0x78, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x00, 0x10, 0x38, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x00, 0x00, 0x10, 0xF8, 0xF8, 0xF8, 0x78, 0x10, 0x00, 0x00, 0x03, 0x0F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xFC, 0x7F, 0x1F, 0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0xFE, 0x3F, 0x0F, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0F, 0x0F, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0F, 0x0F, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 87
    0x10, 0x30, 0x78, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x80, 0x90, 0xF8, 0xF8, 0x78, 0x38, 0x38, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0xE3, 0xF7, 0xFF, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xF9, 0xF0, 0xE0, 0xC0, 0x80, 0x00, 0x00, 0x06, 0x0E, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x06, 0x00, 0x04, 0x07, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 88
    0x18, 0x38, 0x78, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x00, 0x00, 0xF8, 0xF8, 0xF8, 0xF8, 0x38, 0x38, 0x18, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 89
    0xE0, 0xF0, 0xF8, 0x78, 0x38, 0x38, 0x38, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0xF8, 0x3C, 0x08, 0x00, 0x01, 0x01, 0x81, 0xE0, 0xF0, 0xFC, 0xFF, 0xFF, 0xFF, 0x7F, 0x1F, 0x0F, 0x03, 0x00, 0xC0, 0xC0, 0xC0, 0x0C, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x0E, 0x0E, 0x0F, 0x0F, 0x0F, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 90
    0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x07, 0x07, 0x06, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x3F, 0x7F, 0x7F, 0x7F, 0x7F, 0x70, 0x70, 0x70, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 91
    0x18, 0x78, 0xF8, 0xF0, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0F, 0x3F, 0x7E, 0xF8, 0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x1F, 0x7F, 0x7C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 92
    0x06, 0x07, 0x07, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x30, 0x70, 0x70, 0x70, 0x7F, 0x7F, 0x7F, 0x7F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 93
    0x00, 0x00, 0x00, 0x80, 0xE0, 0xF0, 0xF0, 0xE0, 0x80, 0x00, 0x00, 0x00, 0xC0, 0xF0, 0xFE, 0x3F, 0x0F, 0x03, 0x03, 0x0F, 0x3F, 0xFE, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 94
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 95
    0x08, 0x1C, 0x1C, 0x3C, 0x3C, 0x30, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 96
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xCC, 0xCE, 0xEE, 0xE7, 0x63, 0x63, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0x00, 0x03, 0x07, 0x0F, 0x0F, 0x0F, 0x0E, 0x06, 0x07, 0x0F, 0x0F, 0x0F, 0x0F, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 97
    0x40, 0x60, 0xF0, 0xF0, 0xF0, 0xF0, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0E, 0x0F, 0x1F, 0xFF, 0xFF, 0xFE, 0xFE, 0x78, 0x00, 0x00, 0x03, 0x03, 0x03, 0x07, 0x0F, 0x0E, 0x0E, 0x0F, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 98
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFC, 0xFE, 0xFE, 0xFE, 0xCF, 0x87, 0x07, 0x1F, 0x3E, 0xBE, 0x1C, 0x00, 0x03, 0x07, 0x07, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 99
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x30, 0xF0, 0xF8, 0xF8, 0xF8, 0xF8, 0x00, 0xF0, 0xFC, 0xFE, 0xFE, 0xFF, 0x0F, 0x07, 0x07, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x03, 0x07, 0x0F, 0x0F, 0x0F, 0x0E, 0x06, 0x07, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 100
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xF8, 0xFC, 0xFE, 0xFF, 0x77, 0x77, 0x7F, 0x7E, 0x7E, 0x7C, 0x78, 0x00, 0x03, 0x07, 0x07, 0x0F, 0x0F, 0x0E, 0x0E, 0x06, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 101
    0xC0, 0xF0, 0xF0, 0xF8, 0x38, 0x38, 0x78, 0xF8, 0xF0, 0xF0, 0x1D, 0x1F, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0x1C, 0x1C, 0x00, 0x04, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 102
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x38, 0x7C, 0xFE, 0xFE, 0xFF, 0xC3, 0xC3, 0xFF, 0x7F, 0x7F, 0x3F, 0x1F, 0x03, 0x30, 0x7F, 0x7F, 0xFF, 0xFF, 0xDE, 0xDE, 0xDE, 0xDE, 0xFE, 0x7E, 0x7E, 0x3E, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 103
    0x40, 0x70, 0xF0, 0xF0, 0xF8, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x04, 0x04, 0x06, 0x0F, 0xFF, 0xFF, 0xFF, 0xFE, 0xFC, 0x00, 0x04, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x04, 0x00, 0x00, 0x0C, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 104
    0x60, 0x70, 0x70, 0x70, 0x78, 0x70, 0x30, 0x00, 0x04, 0x0E, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0x00, 0x04, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 105
    0x60, 0x70, 0x70, 0x70, 0x78, 0x70, 0x30, 0x08, 0x0E, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x60, 0xE0, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 106
    0x40, 0x60, 0xF0, 0xF0, 0xF0, 0xF0, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x78, 0xF8, 0xFE, 0xFF, 0xFF, 0xFF, 0xC7, 0x87, 0x02, 0x00, 0x00, 0x04, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x06, 0x00, 0x03, 0x07, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 107
    0x20, 0x70, 0xF0, 0xF8, 0xF8, 0xF8, 0xF8, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x04, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 108
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x06, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0x0C, 0x06, 0x0E, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x0C, 0x06, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x00, 0x04, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x06, 0x00, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x06, 0x00, 0x06, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 109
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0x0C, 0x0E, 0x1F, 0xFF, 0xFF, 0xFE, 0xFE, 0xF8, 0x00, 0x0C, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x04, 0x00, 0x0C, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 110
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xF8, 0xFC, 0xFE, 0xFE, 0x87, 0x07, 0x0F, 0x1F, 0xFF, 0xFE, 0xFE, 0xFC, 0xF0, 0x00, 0x03, 0x07, 0x07, 0x0F, 0x0F, 0x0F, 0x0E, 0x0E, 0x07, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 111
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x08, 0x1C, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0x0F, 0x0F, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xF8, 0x20, 0x70, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xEE, 0x4E, 0x0F, 0x0F, 0x0F, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 112
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xFC, 0xFE, 0xFE, 0xFE, 0xFF, 0x0F, 0x07, 0x07, 0x0F, 0xFF, 0xFE, 0xFE, 0xFF, 0xFF, 0x00, 0x00, 0x03, 0x07, 0x07, 0x0F, 0x0F, 0x0F, 0x4E, 0x6E, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 113
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x0E, 0x1F, 0x1F, 0x1F, 0x1F, 0x0E, 0x04, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 114
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x98, 0xBE, 0x7E, 0x7F, 0xFF, 0xF7, 0xE7, 0xEF, 0xDF, 0x9E, 0x07, 0x0F, 0x0F, 0x0E, 0x0E, 0x0F, 0x0F, 0x0F, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 115
    0x00, 0x00, 0x80, 0xC0, 0xC0, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x06, 0x07, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x07, 0x07, 0x07, 0x07, 0x00, 0x00, 0x03, 0x07, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 116
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x06, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x04, 0x06, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0F, 0x0F, 0x0F, 0x0E, 0x06, 0x07, 0x0F, 0x0F, 0x0F, 0x0F, 0x07, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 117
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x1F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xF2, 0xE0, 0x7B, 0x3F, 0x0F, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0F, 0x0F, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 118
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x07, 0x1F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFE, 0xF0, 0xE2, 0xF7, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xF0, 0xE0, 0x7B, 0x1F, 0x07, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0F, 0x0F, 0x07, 0x01, 0x00, 0x00, 0x03, 0x07, 0x0F, 0x0F, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 119
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x07, 0x8F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xF8, 0xFF, 0xDF, 0x07, 0x03, 0x03, 0x0C, 0x0C, 0x0F, 0x0F, 0x0F, 0x00, 0x04, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 120
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x07, 0x0F, 0x3F, 0xFF, 0xFF, 0xFF, 0xFF, 0xF2, 0xE0, 0xF2, 0x7F, 0x0F, 0x07, 0x03, 0x10, 0x78, 0xF8, 0xF8, 0xF0, 0xE3, 0x7F, 0x7F, 0x3F, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 121
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1C, 0x1F, 0x8F, 0xC7, 0xF7, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x1F, 0x87, 0x80, 0x04, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0E, 0x0E, 0x0F, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 122
    0x00, 0x00, 0xF8, 0xFC, 0xFE, 0xFE, 0xFE, 0x06, 0x06, 0x18, 0x18, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x00, 0x00, 0x00, 0x00, 0x1F, 0x3F, 0x7F, 0x7F, 0x7F, 0x60, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 123
    0xFC, 0xFC, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xC0, 0xC0, 0xC0, // 124
    0x06, 0x06, 0xFE, 0xFE, 0xFE, 0xFC, 0xF8, 0x00, 0x00, 0x00, 0x00, 0xE7, 0xFF, 0xFF, 0xFF, 0xFF, 0x18, 0x18, 0x60, 0x60, 0x7F, 0x7F, 0x7F, 0x3F, 0x1F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 125
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xF0, 0xF0, 0x70, 0x70, 0x60, 0xE0, 0xE0, 0xF0, 0xF0, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // 126
    0xF8, 0x38, 0x68, 0x88, 0x08, 0x08, 0x08, 0x08, 0x88, 0x68, 0x38, 0xF8, 0xFF, 0x00, 0x00, 0xC1, 0x63, 0x1C, 0x1C, 0x63, 0xC1, 0x00, 0x00, 0xFF, 0x0F, 0x0E, 0x0B, 0x08, 0x08, 0x08, 0x08, 0x08, 0x08, 0x0B, 0x0E, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 // 127
    
};

#endif
