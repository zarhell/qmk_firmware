// Generado por gen_cat_sprites.py desde catrun.json - no editar a mano.
#pragma once
#include <stdint.h>
#include "progmem.h"

enum cat_frame {
    CAT_WALK1 = 0,
    CAT_WALK2 = 1,
    CAT_WALK3 = 2,
    CAT_WALK4 = 3,
    CAT_WALK5 = 4,
    CAT_STRETCH = 5,
    CAT_IDLE_STAND = 6,
    CAT_IDLE_SIT = 7,
    CAT_SLEEP1 = 8,
    CAT_SLEEP2 = 9,
    CAT_SLEEP3 = 10,
    CAT_FRAME_COUNT
};

// Filas con contenido de todos los frames, una detras de otra.
static const uint32_t PROGMEM cat_rows[285] = {
    0x00800000UL, // walk1 y4
    0x00C00000UL, // walk1 y5
    0x00A01C00UL, // walk1 y6
    0x0111E400UL, // walk1 y7
    0x010E0408UL, // walk1 y8
    0x01004814UL, // walk1 y9
    0x02008814UL, // walk1 y10
    0x04011014UL, // walk1 y11
    0x04009014UL, // walk1 y12
    0x0DC02014UL, // walk1 y13
    0x198E2014UL, // walk1 y14
    0x100C2014UL, // walk1 y15
    0x10002014UL, // walk1 y16
    0x68082028UL, // walk1 y17
    0x16143C50UL, // walk1 y18
    0x238A0390UL, // walk1 y19
    0x00440020UL, // walk1 y20
    0x00400020UL, // walk1 y21
    0x00800040UL, // walk1 y22
    0x01080020UL, // walk1 y23
    0x0211C420UL, // walk1 y24
    0x04E26210UL, // walk1 y25
    0x03262110UL, // walk1 y26
    0x00141310UL, // walk1 y27
    0x00181290UL, // walk1 y28
    0x00001C90UL, // walk1 y29
    0x000000E0UL, // walk1 y30
    0x02100000UL, // walk2 y5
    0x03180000UL, // walk2 y6
    0x02940000UL, // walk2 y7
    0x02520000UL, // walk2 y8
    0x02710000UL, // walk2 y9
    0x04010000UL, // walk2 y10
    0x08010000UL, // walk2 y11
    0x080080F8UL, // walk2 y12
    0x1000C0E4UL, // walk2 y13
    0x171CC012UL, // walk2 y14
    0x36188009UL, // walk2 y15
    0x60011F05UL, // walk2 y16
    0x6001E085UL, // walk2 y17
    0x3021404DUL, // walk2 y18
    0x4C500039UL, // walk2 y19
    0x97280002UL, // walk2 y20
    0x2090000CUL, // walk2 y21
    0x00800010UL, // walk2 y22
    0x00800010UL, // walk2 y23
    0x01047110UL, // walk2 y24
    0x02088910UL, // walk2 y25
    0x06310488UL, // walk2 y26
    0x04510248UL, // walk2 y27
    0x03920248UL, // walk2 y28
    0x00220248UL, // walk2 y29
    0x001C01F8UL, // walk2 y30
    0x04300000UL, // walk3 y10
    0x063801C0UL, // walk3 y11
    0x052401F8UL, // walk3 y12
    0x04A20034UL, // walk3 y13
    0x0462000AUL, // walk3 y14
    0x04010005UL, // walk3 y15
    0x08011F85UL, // walk3 y16
    0x100120C5UL, // walk3 y17
    0x1000C04DUL, // walk3 y18
    0x16700031UL, // walk3 y19
    0x24600002UL, // walk3 y20
    0x4000000CUL, // walk3 y21
    0x20500010UL, // walk3 y22
    0xD0280010UL, // walk3 y23
    0x2E140090UL, // walk3 y24
    0x43C01090UL, // walk3 y25
    0x00206488UL, // walk3 y26
    0x00244248UL, // walk3 y27
    0x00248248UL, // walk3 y28
    0x004C8248UL, // walk3 y29
    0x007F01F8UL, // walk3 y30
    0x01000000UL, // walk4 y4
    0x01800000UL, // walk4 y5
    0x01407800UL, // walk4 y6
    0x02239000UL, // walk4 y7
    0x021C1000UL, // walk4 y8
    0x0201A0C0UL, // walk4 y9
    0x040620A0UL, // walk4 y10
    0x08012050UL, // walk4 y11
    0x08004048UL, // walk4 y12
    0x0B9CC024UL, // walk4 y13
    0x1B188012UL, // walk4 y14
    0x3000800AUL, // walk4 y15
    0x2000BF0AUL, // walk4 y16
    0xD009C08AUL, // walk4 y17
    0x2C240072UL, // walk4 y18
    0x43920004UL, // walk4 y19
    0x00880018UL, // walk4 y20
    0x00400020UL, // walk4 y21
    0x00400020UL, // walk4 y22
    0x00400C20UL, // walk4 y23
    0x0093E220UL, // walk4 y24
    0x01A43120UL, // walk4 y25
    0x01240910UL, // walk4 y26
    0x02520910UL, // walk4 y27
    0x024A1288UL, // walk4 y28
    0x02861258UL, // walk4 y29
    0x01800E70UL, // walk4 y30
    0x01000000UL, // walk5 y3
    0x01800000UL, // walk5 y4
    0x01407800UL, // walk5 y5
    0x02239018UL, // walk5 y6
    0x021C1014UL, // walk5 y7
    0x0201A014UL, // walk5 y8
    0x04062014UL, // walk5 y9
    0x08012014UL, // walk5 y10
    0x08004012UL, // walk5 y11
    0x0B9CC00AUL, // walk5 y12
    0x1B18800AUL, // walk5 y13
    0x3000870AUL, // walk5 y14
    0x2000B892UL, // walk5 y15
    0xD001C072UL, // walk5 y16
    0x2C2C0004UL, // walk5 y17
    0x43920018UL, // walk5 y18
    0x00880010UL, // walk5 y19
    0x00400410UL, // walk5 y20
    0x00400208UL, // walk5 y21
    0x00420188UL, // walk5 y22
    0x0041FE64UL, // walk5 y23
    0x00290112UL, // walk5 y24
    0x00248099UL, // walk5 y25
    0x00124055UL, // walk5 y26
    0x00164053UL, // walk5 y27
    0x00152060UL, // walk5 y28
    0x000CE000UL, // walk5 y29
    0x00000080UL, // stretch y4
    0x00000140UL, // stretch y5
    0x000000A0UL, // stretch y6
    0x000000A0UL, // stretch y7
    0x000000A0UL, // stretch y8
    0x000000A0UL, // stretch y9
    0x000000B0UL, // stretch y10
    0x00000090UL, // stretch y11
    0x00000050UL, // stretch y12
    0x00000050UL, // stretch y13
    0x00610050UL, // stretch y14
    0x00E30048UL, // stretch y15
    0x01250048UL, // stretch y16
    0x033900C8UL, // stretch y17
    0x02020304UL, // stretch y18
    0x04010C04UL, // stretch y19
    0x08013002UL, // stretch y20
    0x0801C002UL, // stretch y21
    0x48000002UL, // stretch y22
    0x2E780002UL, // stretch y23
    0x90000002UL, // stretch y24
    0x60100002UL, // stretch y25
    0x20480002UL, // stretch y26
    0x18240602UL, // stretch y27
    0x3F001F04UL, // stretch y28
    0x2000E304UL, // stretch y29
    0x1FFF83F8UL, // stretch y30
    0x02004000UL, // idle_stand y5
    0x0300C000UL, // idle_stand y6
    0x04834000UL, // idle_stand y7
    0x047D4000UL, // idle_stand y8
    0x04014008UL, // idle_stand y9
    0x0402800CUL, // idle_stand y10
    0x0800800AUL, // idle_stand y11
    0x1000800AUL, // idle_stand y12
    0x1700800AUL, // idle_stand y13
    0x1638800AUL, // idle_stand y14
    0x3030800AUL, // idle_stand y15
    0x2001000AUL, // idle_stand y16
    0xD021F014UL, // idle_stand y17
    0x2C107E68UL, // idle_stand y18
    0x47480190UL, // idle_stand y19
    0x01240010UL, // idle_stand y20
    0x00900020UL, // idle_stand y21
    0x00800020UL, // idle_stand y22
    0x00800820UL, // idle_stand y23
    0x00601820UL, // idle_stand y24
    0x0051F410UL, // idle_stand y25
    0x004A1A10UL, // idle_stand y26
    0x004A0B10UL, // idle_stand y27
    0x005A1390UL, // idle_stand y28
    0x00B21290UL, // idle_stand y29
    0x00DC0CE0UL, // idle_stand y30
    0x03000000UL, // idle_sit y4
    0x02806000UL, // idle_sit y5
    0x0243A000UL, // idle_sit y6
    0x03FE2000UL, // idle_sit y7
    0x0200A000UL, // idle_sit y8
    0x0400A000UL, // idle_sit y9
    0x0C006000UL, // idle_sit y10
    0x08004000UL, // idle_sit y11
    0x0B384000UL, // idle_sit y12
    0x12304000UL, // idle_sit y13
    0x30004000UL, // idle_sit y14
    0x20208000UL, // idle_sit y15
    0xD090C000UL, // idle_sit y16
    0x2C482000UL, // idle_sit y17
    0x43201030UL, // idle_sit y18
    0x00800828UL, // idle_sit y19
    0x01800424UL, // idle_sit y20
    0x01000212UL, // idle_sit y21
    0x0100020AUL, // idle_sit y22
    0x00C0610AUL, // idle_sit y23
    0x0068810AUL, // idle_sit y24
    0x0028810AUL, // idle_sit y25
    0x00488112UL, // idle_sit y26
    0x009041E6UL, // idle_sit y27
    0x00B1E00CUL, // idle_sit y28
    0x00A30070UL, // idle_sit y29
    0x007DFFC0UL, // idle_sit y30
    0x00000700UL, // sleep1 y10
    0x00000200UL, // sleep1 y11
    0x00000100UL, // sleep1 y12
    0x00000700UL, // sleep1 y13
    0x00000000UL, // sleep1 y14
    0x40002000UL, // sleep1 y15
    0x7000E000UL, // sleep1 y16
    0x4CF12000UL, // sleep1 y17
    0x570EA000UL, // sleep1 y18
    0x48012000UL, // sleep1 y19
    0x48013E00UL, // sleep1 y20
    0x20002180UL, // sleep1 y21
    0x10004040UL, // sleep1 y22
    0x90004820UL, // sleep1 y23
    0x52025020UL, // sleep1 y24
    0x338E6830UL, // sleep1 y25
    0x4800901CUL, // sleep1 y26
    0xB7074FE2UL, // sleep1 y27
    0x20F8B022UL, // sleep1 y28
    0x1071A00EUL, // sleep1 y29
    0x0F8F3FFCUL, // sleep1 y30
    0x0000F000UL, // sleep2 y6
    0x00004000UL, // sleep2 y7
    0x00002000UL, // sleep2 y8
    0x00001000UL, // sleep2 y9
    0x0000F700UL, // sleep2 y10
    0x00000200UL, // sleep2 y11
    0x00000100UL, // sleep2 y12
    0x00000700UL, // sleep2 y13
    0x00000000UL, // sleep2 y14
    0x00000000UL, // sleep2 y15
    0x40002000UL, // sleep2 y16
    0x7000E000UL, // sleep2 y17
    0x4CF12000UL, // sleep2 y18
    0x570EA000UL, // sleep2 y19
    0x48012000UL, // sleep2 y20
    0x48013E00UL, // sleep2 y21
    0x20002180UL, // sleep2 y22
    0x10004040UL, // sleep2 y23
    0x90004820UL, // sleep2 y24
    0x52025020UL, // sleep2 y25
    0x338E6830UL, // sleep2 y26
    0x4800901CUL, // sleep2 y27
    0xB7074FE2UL, // sleep2 y28
    0x20F8B022UL, // sleep2 y29
    0x1071A00EUL, // sleep2 y30
    0x0F8F3FFCUL, // sleep2 y31
    0x007C0000UL, // sleep3 y1
    0x007C0000UL, // sleep3 y2
    0x00400000UL, // sleep3 y3
    0x00700000UL, // sleep3 y4
    0x0018F000UL, // sleep3 y5
    0x000C4000UL, // sleep3 y6
    0x007C2000UL, // sleep3 y7
    0x007C1000UL, // sleep3 y8
    0x0000F700UL, // sleep3 y9
    0x00000200UL, // sleep3 y10
    0x00000100UL, // sleep3 y11
    0x00000700UL, // sleep3 y12
    0x00000000UL, // sleep3 y13
    0x00000000UL, // sleep3 y14
    0x40002000UL, // sleep3 y15
    0x7000E000UL, // sleep3 y16
    0x4CF12000UL, // sleep3 y17
    0x570EA000UL, // sleep3 y18
    0x48012000UL, // sleep3 y19
    0x48013E00UL, // sleep3 y20
    0x20002180UL, // sleep3 y21
    0x10004040UL, // sleep3 y22
    0x90004820UL, // sleep3 y23
    0x52025020UL, // sleep3 y24
    0x338E6830UL, // sleep3 y25
    0x4800901CUL, // sleep3 y26
    0xB7074FE2UL, // sleep3 y27
    0x20F8B022UL, // sleep3 y28
    0x1071A00EUL, // sleep3 y29
    0x0F8F3FFCUL, // sleep3 y30
};

typedef struct { uint8_t y0; uint8_t h; uint16_t off; } cat_meta_t;
// y0 = primera fila con contenido, h = numero de filas, off = indice en cat_rows.
static const cat_meta_t PROGMEM cat_meta[CAT_FRAME_COUNT] = {
    {4, 27, 0}, // walk1
    {5, 26, 27}, // walk2
    {10, 21, 53}, // walk3
    {4, 27, 74}, // walk4
    {3, 27, 101}, // walk5
    {4, 27, 128}, // stretch
    {5, 26, 155}, // idle_stand
    {4, 27, 181}, // idle_sit
    {10, 21, 208}, // sleep1
    {6, 26, 229}, // sleep2
    {1, 30, 255}, // sleep3
};
