/* SPDX-License-Identifier: GPL-2.0-only OR MIT */

/*
 * This file is created based on MT8189_EINT_Datasheet
 * Chapter number: 1
 */

#include <commonlib/bsd/helpers.h>
#include <soc/gpio_eint_v2.h>

const struct eint_info eint_data[] = {
	[0] = { EINT_E, 0 },
	[1] = { EINT_E, 1 },
	[2] = { EINT_E, 2 },
	[3] = { EINT_E, 3 },
	[4] = { EINT_E, 4 },
	[5] = { EINT_E, 5 },
	[6] = { EINT_E, 6 },
	[7] = { EINT_E, 7 },
	[8] = { EINT_E, 8 },
	[9] = { EINT_E, 9 },
	[10] = { EINT_E, 10 },
	[11] = { EINT_E, 11 },
	[12] = { EINT_S, 0 },
	[13] = { EINT_S, 1 },
	[14] = { EINT_S, 2 },
	[15] = { EINT_S, 3 },
	[16] = { EINT_S, 4 },
	[17] = { EINT_S, 5 },
	[18] = { EINT_E, 12 },
	[19] = { EINT_E, 13 },
	[20] = { EINT_E, 14 },
	[21] = { EINT_E, 15 },
	[22] = { EINT_E, 16 },
	[23] = { EINT_E, 17 },
	[24] = { EINT_E, 18 },
	[25] = { EINT_W, 0 },
	[26] = { EINT_W, 1 },
	[27] = { EINT_S, 6 },
	[28] = { EINT_S, 7 },
	[29] = { EINT_W, 2 },
	[30] = { EINT_S, 8 },
	[31] = { EINT_S, 9 },
	[32] = { EINT_S, 10 },
	[33] = { EINT_S, 11 },
	[34] = { EINT_S, 12 },
	[35] = { EINT_S, 13 },
	[36] = { EINT_S, 14 },
	[37] = { EINT_S, 15 },
	[38] = { EINT_S, 16 },
	[39] = { EINT_S, 17 },
	[40] = { EINT_S, 18 },
	[41] = { EINT_S, 19 },
	[42] = { EINT_S, 20 },
	[43] = { EINT_S, 21 },
	[44] = { EINT_E, 19 },
	[45] = { EINT_E, 20 },
	[46] = { EINT_E, 21 },
	[47] = { EINT_E, 22 },
	[48] = { EINT_W, 3 },
	[49] = { EINT_W, 4 },
	[50] = { EINT_W, 5 },
	[51] = { EINT_E, 23 },
	[52] = { EINT_E, 24 },
	[53] = { EINT_E, 25 },
	[54] = { EINT_E, 26 },
	[55] = { EINT_W, 6 },
	[56] = { EINT_W, 7 },
	[57] = { EINT_S, 22 },
	[58] = { EINT_S, 23 },
	[59] = { EINT_S, 24 },
	[60] = { EINT_S, 25 },
	[61] = { EINT_S, 26 },
	[62] = { EINT_S, 27 },
	[63] = { EINT_S, 28 },
	[64] = { EINT_S, 29 },
	[65] = { EINT_E, 27 },
	[66] = { EINT_E, 28 },
	[67] = { EINT_E, 29 },
	[68] = { EINT_E, 30 },
	[69] = { EINT_S, 30 },
	[70] = { EINT_S, 31 },
	[71] = { EINT_S, 32 },
	[72] = { EINT_S, 33 },
	[73] = { EINT_S, 34 },
	[74] = { EINT_S, 35 },
	[75] = { EINT_S, 36 },
	[76] = { EINT_S, 37 },
	[77] = { EINT_E, 31 },
	[78] = { EINT_E, 32 },
	[79] = { EINT_E, 33 },
	[80] = { EINT_E, 34 },
	[81] = { EINT_S, 38 },
	[82] = { EINT_S, 39 },
	[83] = { EINT_S, 40 },
	[84] = { EINT_E, 35 },
	[85] = { EINT_E, 36 },
	[86] = { EINT_E, 37 },
	[87] = { EINT_E, 38 },
	[88] = { EINT_W, 8 },
	[89] = { EINT_W, 9 },
	[90] = { EINT_W, 10 },
	[91] = { EINT_W, 11 },
	[92] = { EINT_W, 12 },
	[93] = { EINT_W, 13 },
	[94] = { EINT_W, 14 },
	[95] = { EINT_W, 15 },
	[96] = { EINT_W, 16 },
	[97] = { EINT_W, 17 },
	[98] = { EINT_W, 18 },
	[99] = { EINT_W, 19 },
	[100] = { EINT_W, 20 },
	[101] = { EINT_W, 21 },
	[102] = { EINT_W, 22 },
	[103] = { EINT_E, 39 },
	[104] = { EINT_E, 40 },
	[105] = { EINT_E, 41 },
	[106] = { EINT_E, 42 },
	[107] = { EINT_E, 43 },
	[108] = { EINT_E, 44 },
	[109] = { EINT_E, 45 },
	[110] = { EINT_E, 46 },
	[111] = { EINT_E, 47 },
	[112] = { EINT_E, 48 },
	[113] = { EINT_E, 49 },
	[114] = { EINT_E, 50 },
	[115] = { EINT_S, 41 },
	[116] = { EINT_S, 42 },
	[117] = { EINT_S, 43 },
	[118] = { EINT_S, 44 },
	[119] = { EINT_S, 45 },
	[120] = { EINT_S, 46 },
	[121] = { EINT_S, 47 },
	[122] = { EINT_S, 48 },
	[123] = { EINT_S, 49 },
	[124] = { EINT_S, 50 },
	[125] = { EINT_S, 51 },
	[126] = { EINT_S, 52 },
	[127] = { EINT_S, 53 },
	[128] = { EINT_S, 54 },
	[129] = { EINT_S, 55 },
	[130] = { EINT_S, 56 },
	[131] = { EINT_S, 57 },
	[132] = { EINT_S, 58 },
	[133] = { EINT_S, 59 },
	[134] = { EINT_S, 60 },
	[135] = { EINT_S, 61 },
	[136] = { EINT_S, 62 },
	[137] = { EINT_S, 63 },
	[138] = { EINT_S, 64 },
	[139] = { EINT_S, 65 },
	[140] = { EINT_S, 66 },
	[141] = { EINT_S, 67 },
	[142] = { EINT_S, 68 },
	[143] = { EINT_S, 69 },
	[144] = { EINT_S, 70 },
	[145] = { EINT_S, 71 },
	[146] = { EINT_S, 72 },
	[147] = { EINT_S, 73 },
	[148] = { EINT_S, 74 },
	[149] = { EINT_S, 75 },
	[150] = { EINT_S, 76 },
	[151] = { EINT_S, 77 },
	[152] = { EINT_S, 78 },
	[153] = { EINT_S, 79 },
	[154] = { EINT_S, 80 },
	[155] = { EINT_S, 81 },
	[156] = { EINT_W, 23 },
	[157] = { EINT_W, 24 },
	[158] = { EINT_W, 25 },
	[159] = { EINT_N, 0 },
	[160] = { EINT_W, 26 },
	[161] = { EINT_W, 27 },
	[162] = { EINT_W, 28 },
	[163] = { EINT_N, 1 },
	[164] = { EINT_W, 29 },
	[165] = { EINT_W, 30 },
	[166] = { EINT_N, 2 },
	[167] = { EINT_W, 31 },
	[168] = { EINT_S, 82 },
	[169] = { EINT_S, 83 },
	[170] = { EINT_S, 84 },
	[171] = { EINT_S, 85 },
	[172] = { EINT_S, 86 },
	[173] = { EINT_S, 87 },
	[174] = { EINT_N, 3 },
	[175] = { EINT_N, 4 },
	[176] = { EINT_N, 5 },
	[177] = { EINT_N, 6 },
	[178] = { EINT_N, 7 },
	[179] = { EINT_N, 8 },
	[180] = { EINT_W, 32 },
	[181] = { EINT_W, 33 },
	[182] = { EINT_C, 0 },
	[183] = { EINT_C, 1 },
	[184] = { EINT_C, 2 },
	[185] = { EINT_C, 3 },
	[186] = { EINT_C, 4 },
	[187] = { EINT_C, 5 },
	[188] = { EINT_C, 6 },
	[189] = { EINT_C, 7 },
	[190] = { EINT_C, 8 },
	[191] = { EINT_C, 9 },
	[192] = { EINT_C, 10 },
	[193] = { EINT_C, 11 },
	[194] = { EINT_C, 12 },
	[195] = { EINT_C, 13 },
	[196] = { EINT_C, 14 },
	[197] = { EINT_C, 15 },
	[198] = { EINT_C, 16 },
	[199] = { EINT_C, 17 },
	[200] = { EINT_C, 18 },
	[201] = { EINT_C, 19 },
	[202] = { EINT_C, 20 },
	[203] = { EINT_C, 21 },
	[204] = { EINT_C, 22 },
	[205] = { EINT_C, 23 },
	[206] = { EINT_C, 24 },
	[207] = { EINT_C, 25 },
	[208] = { EINT_C, 26 },
	[209] = { EINT_C, 27 },
};
_Static_assert(ARRAY_SIZE(eint_data) == 210, "Incorrect eint_data size");

const size_t eint_data_len = ARRAY_SIZE(eint_data);
