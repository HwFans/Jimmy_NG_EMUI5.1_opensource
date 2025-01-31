/*
 * Copyright (C) 2015 MediaTek Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 */

#ifndef _CUST_BATTERY_METER_TABLE_H
#define _CUST_BATTERY_METER_TABLE_H


/* ============================================================
// define
// ============================================================*/
#define BAT_NTC_10 1
#define BAT_NTC_47 0

#if (BAT_NTC_10 == 1)
#define RBAT_PULL_UP_R             16900
#endif

#if (BAT_NTC_47 == 1)
#define RBAT_PULL_UP_R             61900
#endif

#define RBAT_PULL_UP_VOLT          1800

#define BIF_NTC_R 16000

/* multiple battery profile compile options */
#define MTK_GET_BATTERY_ID_BY_AUXADC
#define BATTERY_ID_CHANNEL_NUM 14
#define TOTAL_BATTERY_NUMBER 2
/*#define MTK_GET_BATTERY_ID_BY_GPIO*/

/* ============================================================
// ENUM
// ============================================================*/

/* ============================================================
// structure
// ============================================================*/

/* ============================================================
// typedef
// ============================================================*/
typedef struct _BATTERY_PROFILE_STRUCT {
	signed int percentage;
	signed int voltage;
	} BATTERY_PROFILE_STRUCT,*BATTERY_PROFILE_STRUCT_P;

typedef struct _R_PROFILE_STRUCT {
	signed int resistance; /* Ohm*/
	signed int voltage;
} R_PROFILE_STRUCT,*R_PROFILE_STRUCT_P;

typedef enum {
	T1_0C,
	T2_25C,
	T3_50C
} PROFILE_TEMPERATURE;

/* ============================================================
// External Variables
// ============================================================*/

/* ============================================================
// External function
// ============================================================*/

/* ============================================================
// <DOD,Battery_Voltage> Table
// ============================================================*/

/* Qmax for battery  */
signed int g_Q_MAX_POS_50[TOTAL_BATTERY_NUMBER] = {2903, 2889};
signed int g_Q_MAX_POS_25[TOTAL_BATTERY_NUMBER] = {2820, 2770};
signed int g_Q_MAX_POS_0[TOTAL_BATTERY_NUMBER] = {2043, 2037};
signed int g_Q_MAX_NEG_10[TOTAL_BATTERY_NUMBER] = {1406, 1428};

signed int g_Q_MAX_POS_50_H_CURRENT[TOTAL_BATTERY_NUMBER] = {2833, 2900};
signed int g_Q_MAX_POS_25_H_CURRENT[TOTAL_BATTERY_NUMBER] = {2795, 2850};
signed int g_Q_MAX_POS_0_H_CURRENT[TOTAL_BATTERY_NUMBER] = {2002, 1996};
signed int g_Q_MAX_NEG_10_H_CURRENT[TOTAL_BATTERY_NUMBER] = {1378, 1399};
signed int g_Q_MAX_SYS_VOLTAGE[TOTAL_BATTERY_NUMBER] = {3350, 3350};
signed int g_BATTERYPSEUDO1[TOTAL_BATTERY_NUMBER] = {4, 4};

/* 0~0.5V for battery 0,0.5~1V for battery 1,1~1.5V for battery 2,-1 for the last one (battery 3) */
struct battery_id_voltage
{
	char *vendor_name;
	int id_voltage_low;//mv
	int id_voltage_high;
};
struct battery_id_voltage g_battery_id_voltage[TOTAL_BATTERY_NUMBER] =
{
    {
		.vendor_name="xinwangda",
		.id_voltage_low= 684,
		.id_voltage_high=784
    },
    {
        .vendor_name="desay",
        .id_voltage_low= 1420,
        .id_voltage_high=1800
    }
};
#if (BAT_NTC_10 == 1)
BATT_TEMPERATURE Batt_Temperature_Table[TOTAL_BATTERY_NUMBER][17] = {
{
    {-20,68237},
    {-15,53650},
    {-10,42506},
    { -5,33892},
    {  0,27219},
    {  5,22021},
    { 10,17926},
    { 15,14674},
    { 20,12081},
    { 25,10000},
    { 30,8315},
    { 35,6948},
    { 40,5834},
    { 45,4917},
    { 50,4161},
    { 55,3535},
    { 60,3014}
},
{
    {-20,68237},
    {-15,53650},
    {-10,42506},
    { -5,33892},
    {  0,27219},
    {  5,22021},
    { 10,17926},
    { 15,14674},
    { 20,12081},
    { 25,10000},
    { 30,8315},
    { 35,6948},
    { 40,5834},
    { 45,4917},
    { 50,4161},
    { 55,3535},
    { 60,3014}
}
};
#endif

#if (BAT_NTC_47 == 1)
BATT_TEMPERATURE Batt_Temperature_Table[TOTAL_BATTERY_NUMBER][17] = {
{
    {-20,483954},
    {-15,360850},
    {-10,271697},
    { -5,206463},
    {  0,158214},
    {  5,122259},
    { 10,95227},
    { 15,74730},
    { 20,59065},
    { 25,47000},
    { 30,37643},
    { 35,30334},
    { 40,24591},
    { 45,20048},
    { 50,16433},
    { 55,13539},
    { 60,11210}
},
{
    {-20,483954},
    {-15,360850},
    {-10,271697},
    { -5,206463},
    {  0,158214},
    {  5,122259},
    { 10,95227},
    { 15,74730},
    { 20,59065},
    { 25,47000},
    { 30,37643},
    { 35,30334},
    { 40,24591},
    { 45,20048},
    { 50,16433},
    { 55,13539},
    { 60,11210}
}
};
#endif

/* T0 -10C */
BATTERY_PROFILE_STRUCT xinwangda_battery_profile_t0[] =
{
	{0,4290},
	{3,4266},
	{6,4245},
	{9,4225},
	{11,4206},
	{14,4188},
	{17,4171},
	{20,4156},
	{23,4139},
	{26,4116},
	{29,4078},
	{31,4025},
	{34,3992},
	{37,3967},
	{40,3947},
	{43,3932},
	{46,3920},
	{49,3909},
	{51,3899},
	{54,3890},
	{57,3880},
	{60,3871},
	{63,3863},
	{66,3855},
	{69,3847},
	{71,3840},
	{74,3833},
	{77,3826},
	{80,3820},
	{83,3814},
	{86,3807},
	{89,3801},
	{91,3796},
	{94,3789},
	{97,3783},
	{100,3776},
	{103,3769},
	{106,3762},
	{109,3753},
	{111,3744},
	{114,3735},
	{117,3725},
	{120,3717},
	{123,3712},
	{126,3707},
	{129,3702},
	{131,3692},
	{134,3671},
	{137,3623},
	{140,3547},
	{141,3471},
	{143,3424},
	{143,3386},
	{144,3354},
	{144,3330},
	{144,3311},
	{144,3296},
	{144,3284},
	{144,3274},
	{144,3265},
	{144,3258},
	{144,3253},
	{144,3249},
	{144,3244},
	{144,3240},
	{144,3236},
	{144,3233},
	{144,3230},
	{144,3227},
	{144,3225},
	{144,3223},
	{144,3221},
	{146,3218},
	{146,3215},
	{146,3212},
	{146,3208},
	{146,3205},
	{146,3201},
	{146,3197},
	{146,3197},
	{146,3197},
	{146,3197},
	{146,3197},
	{146,3197},
	{146,3197},
	{146,3197},
	{146,3197},
	{146,3197},

};

BATTERY_PROFILE_STRUCT desay_battery_profile_t0[] =
{
	{0,4253},
	{3,4215},
	{5,4183},
	{8,4156},
	{12,4134},
	{13,4115},
	{17,4101},
	{20,4088},
	{22,4072},
	{25,4050},
	{28,4026},
	{30,4004},
	{33,3986},
	{37,3970},
	{40,3957},
	{42,3945},
	{45,3932},
	{48,3919},
	{50,3905},
	{53,3893},
	{57,3881},
	{58,3871},
	{62,3862},
	{65,3854},
	{67,3846},
	{70,3839},
	{73,3832},
	{75,3826},
	{78,3821},
	{82,3816},
	{83,3811},
	{87,3807},
	{90,3804},
	{92,3801},
	{95,3798},
	{98,3796},
	{100,3793},
	{103,3791},
	{107,3788},
	{110,3785},
	{112,3781},
	{115,3777},
	{118,3772},
	{120,3767},
	{123,3760},
	{127,3753},
	{128,3746},
	{132,3738},
	{135,3730},
	{137,3721},
	{140,3713},
	{143,3706},
	{145,3699},
	{148,3693},
	{152,3687},
	{153,3679},
	{157,3662},
	{160,3629},
	{162,3567},
	{163,3513},
	{165,3468},
	{167,3430},
	{167,3395},
	{167,3364},
	{168,3335},
	{168,3310},
	{168,3287},
	{168,3267},
	{168,3249},
	{168,3234},
	{168,3218},
	{168,3204},
	{168,3194},
	{170,3183},
	{170,3174},
	{170,3174},
	{170,3174},
	{170,3174},
	{170,3174},
	{170,3174},
	{170,3174},
	{170,3174},
	{170,3174},
	{170,3174},
	{170,3174},
	{170,3174},
	{170,3174},
	{170,3174},

};
BATTERY_PROFILE_STRUCT *battery_profile_t0[TOTAL_BATTERY_NUMBER] =
{
    xinwangda_battery_profile_t0,
    desay_battery_profile_t0
};
int battery_profile_t0_size[TOTAL_BATTERY_NUMBER]=
{
    sizeof(xinwangda_battery_profile_t0)/sizeof(BATTERY_PROFILE_STRUCT),
    sizeof(desay_battery_profile_t0)/sizeof(BATTERY_PROFILE_STRUCT)
};

/* T1 0C */
BATTERY_PROFILE_STRUCT xinwangda_battery_profile_t1[] =
{
	{0,4343},
	{3,4320},
	{4,4301},
	{6,4279},
	{8,4220},
	{10,4185},
	{11,4166},
	{14,4150},
	{15,4134},
	{18,4119},
	{19,4105},
	{22,4092},
	{24,4080},
	{25,4067},
	{28,4052},
	{29,4031},
	{32,4011},
	{33,3995},
	{35,3983},
	{37,3972},
	{39,3961},
	{41,3948},
	{43,3934},
	{46,3919},
	{47,3905},
	{49,3891},
	{51,3880},
	{53,3871},
	{54,3861},
	{57,3854},
	{58,3846},
	{61,3839},
	{62,3832},
	{65,3826},
	{67,3820},
	{68,3815},
	{71,3810},
	{72,3805},
	{75,3800},
	{76,3796},
	{78,3792},
	{80,3789},
	{82,3786},
	{84,3784},
	{86,3781},
	{89,3779},
	{90,3775},
	{92,3772},
	{94,3767},
	{96,3762},
	{97,3758},
	{100,3752},
	{101,3745},
	{104,3737},
	{106,3729},
	{108,3720},
	{110,3710},
	{111,3701},
	{114,3696},
	{115,3693},
	{118,3689},
	{119,3682},
	{122,3658},
	{123,3597},
	{125,3500},
	{127,3403},
	{128,3332},
	{128,3269},
	{128,3216},
	{128,3178},
	{128,3155},
	{128,3136},
	{128,3125},
	{128,3116},
	{128,3109},
	{128,3101},
	{128,3097},
	{128,3090},
	{128,3084},
	{128,3084},
	{128,3084},
	{128,3084},
	{128,3084},
	{128,3084},
	{128,3084},
	{128,3084},
	{128,3084},
	{128,3084},

};

BATTERY_PROFILE_STRUCT desay_battery_profile_t1[] =
{
	{0,4307},
	{3,4276},
	{4,4255},
	{6,4236},
	{8,4219},
	{10,4203},
	{12,4188},
	{14,4173},
	{16,4158},
	{18,4143},
	{19,4128},
	{22,4114},
	{23,4101},
	{26,4090},
	{27,4080},
	{30,4068},
	{31,4049},
	{34,4024},
	{35,4002},
	{38,3985},
	{39,3971},
	{42,3958},
	{43,3947},
	{45,3934},
	{47,3921},
	{49,3907},
	{51,3895},
	{53,3884},
	{55,3875},
	{57,3866},
	{58,3858},
	{61,3850},
	{62,3843},
	{65,3836},
	{66,3830},
	{69,3824},
	{70,3819},
	{73,3813},
	{74,3808},
	{77,3804},
	{78,3799},
	{81,3795},
	{82,3792},
	{84,3788},
	{86,3786},
	{88,3784},
	{90,3781},
	{92,3779},
	{95,3775},
	{96,3771},
	{99,3765},
	{100,3759},
	{103,3751},
	{104,3743},
	{107,3732},
	{108,3721},
	{110,3713},
	{112,3706},
	{114,3702},
	{116,3698},
	{118,3694},
	{120,3689},
	{122,3677},
	{123,3650},
	{126,3601},
	{127,3530},
	{130,3428},
	{131,3330},
	{131,3253},
	{131,3190},
	{132,3137},
	{132,3100},
	{132,3073},
	{132,3057},
	{132,3046},
	{132,3038},
	{132,3031},
	{132,3026},
	{132,3021},
	{132,3021},
	{132,3021},
	{132,3021},
	{132,3021},
	{132,3021},
	{132,3021},
	{132,3021},
	{132,3021},
	{132,3021},

};
BATTERY_PROFILE_STRUCT *battery_profile_t1[TOTAL_BATTERY_NUMBER] =
{
    xinwangda_battery_profile_t1,
    desay_battery_profile_t1
};
int battery_profile_t1_size[]=
{
    sizeof(xinwangda_battery_profile_t1)/sizeof(BATTERY_PROFILE_STRUCT),
    sizeof(desay_battery_profile_t1)/sizeof(BATTERY_PROFILE_STRUCT)
};


/* T2 25C*/
BATTERY_PROFILE_STRUCT xinwangda_battery_profile_t2[] =
{
    {0,4361},
    {1,4342},
    {3,4325},
    {4,4309},
    {6,4293},
    {7,4277},
    {8,4261},
    {10,4246},
    {11,4229},
    {12,4214},
    {14,4198},
    {15,4183},
    {17,4167},
    {18,4152},
    {19,4138},
    {21,4123},
    {22,4108},
    {24,4093},
    {25,4080},
    {26,4069},
    {28,4055},
    {29,4040},
    {31,4026},
    {32,4012},
    {33,3999},
    {35,3987},
    {36,3976},
    {37,3965},
    {39,3955},
    {40,3941},
    {42,3923},
    {43,3905},
    {44,3891},
    {46,3881},
    {47,3871},
    {49,3863},
    {51,3855},
    {52,3848},
    {54,3841},
    {55,3835},
    {57,3829},
    {58,3823},
    {59,3818},
    {61,3813},
    {62,3808},
    {63,3803},
    {65,3799},
    {66,3795},
    {68,3791},
    {69,3788},
    {70,3784},
    {72,3779},
    {73,3774},
    {75,3768},
    {76,3763},
    {77,3758},
    {79,3752},
    {80,3747},
    {81,3744},
    {83,3739},
    {84,3731},
    {86,3723},
    {87,3716},
    {88,3706},
    {90,3696},
    {91,3693},
    {93,3691},
    {94,3690},
    {95,3686},
    {97,3672},
    {98,3620},
    {100,3542},
    {101,3419},
    {102,3165},
    {102,3121},
    {102,3101},
    {103,3089},
    {103,3079},
    {103,3070},
    {103,3070},
    {103,3070},
    {103,3070},
    {103,3070},
    {103,3070},
    {103,3070},
    {103,3070},
    {103,3070},
    {103,3070}

};
BATTERY_PROFILE_STRUCT desay_battery_profile_t2[] =
{
    {0,4365},
    {1,4348},
    {3,4332},
    {4,4317},
    {6,4301},
    {7,4286},
    {8,4270},
    {10,4255},
    {11,4240},
    {13,4224},
    {14,4209},
    {15,4194},
    {17,4180},
    {18,4165},
    {20,4151},
    {21,4136},
    {22,4122},
    {24,4108},
    {26,4094},
    {28,4081},
    {29,4070},
    {30,4064},
    {32,4049},
    {33,4026},
    {35,4006},
    {36,3991},
    {37,3982},
    {39,3975},
    {40,3965},
    {42,3949},
    {43,3929},
    {44,3912},
    {46,3899},
    {47,3889},
    {49,3880},
    {50,3871},
    {51,3864},
    {53,3856},
    {54,3849},
    {56,3842},
    {57,3836},
    {58,3830},
    {60,3824},
    {61,3819},
    {63,3814},
    {64,3809},
    {65,3804},
    {67,3800},
    {68,3795},
    {70,3791},
    {71,3786},
    {72,3781},
    {74,3776},
    {76,3770},
    {78,3764},
    {79,3758},
    {80,3751},
    {82,3746},
    {83,3739},
    {85,3729},
    {86,3718},
    {87,3706},
    {89,3695},
    {90,3692},
    {92,3690},
    {93,3690},
    {94,3689},
    {96,3686},
    {97,3676},
    {98,3634},
    {100,3567},
    {101,3475},
    {103,3329},
    {104,3043},
    {104,2991},
    {104,2971},
    {104,2956},
    {104,2939},
    {105,2926},
    {105,2926},
    {105,2926},
    {105,2926},
    {105,2926},
    {105,2926},
    {105,2926},
    {105,2926},
    {105,2926},
    {105,2926}

};
BATTERY_PROFILE_STRUCT *battery_profile_t2[TOTAL_BATTERY_NUMBER] =
{
    xinwangda_battery_profile_t2,
    desay_battery_profile_t2
};
int battery_profile_t2_size[]=
{
    sizeof(xinwangda_battery_profile_t2)/sizeof(BATTERY_PROFILE_STRUCT),
    sizeof(desay_battery_profile_t2)/sizeof(BATTERY_PROFILE_STRUCT)
};


/* T3 50C*/
BATTERY_PROFILE_STRUCT xinwangda_battery_profile_t3[] =
{
    {0,4374},
    {1,4356},
    {3,4340},
    {4,4324},
    {5,4307},
    {7,4292},
    {8,4276},
    {10,4259},
    {11,4243},
    {12,4227},
    {14,4212},
    {15,4196},
    {16,4181},
    {18,4165},
    {19,4150},
    {21,4135},
    {22,4120},
    {23,4106},
    {25,4091},
    {26,4077},
    {27,4063},
    {29,4050},
    {30,4038},
    {31,4024},
    {33,4011},
    {34,3999},
    {36,3988},
    {37,3977},
    {38,3966},
    {40,3954},
    {41,3943},
    {42,3928},
    {44,3908},
    {45,3892},
    {47,3881},
    {48,3872},
    {49,3863},
    {52,3855},
    {53,3848},
    {54,3841},
    {56,3835},
    {57,3828},
    {58,3822},
    {60,3816},
    {61,3811},
    {63,3806},
    {64,3802},
    {65,3797},
    {67,3793},
    {68,3789},
    {69,3785},
    {71,3781},
    {72,3775},
    {74,3764},
    {75,3756},
    {76,3750},
    {78,3744},
    {79,3738},
    {80,3732},
    {82,3728},
    {83,3723},
    {85,3716},
    {86,3708},
    {87,3700},
    {89,3692},
    {90,3681},
    {91,3679},
    {93,3677},
    {94,3676},
    {95,3672},
    {97,3656},
    {98,3604},
    {100,3528},
    {101,3413},
    {102,3167},
    {103,3069},
    {103,3008},
    {103,2967},
    {103,2948},
    {103,2948},
    {103,2948},
    {103,2948},
    {103,2948},
    {103,2948},
    {103,2948},
    {103,2948},
    {103,2948},
    {103,2948}

};
BATTERY_PROFILE_STRUCT desay_battery_profile_t3[] =
{
    {0,4379},
    {1,4364},
    {3,4351},
    {4,4336},
    {5,4322},
    {7,4307},
    {8,4292},
    {10,4277},
    {11,4261},
    {12,4246},
    {14,4231},
    {15,4215},
    {16,4201},
    {18,4186},
    {19,4171},
    {21,4156},
    {22,4141},
    {23,4127},
    {25,4113},
    {26,4099},
    {27,4085},
    {29,4071},
    {30,4058},
    {31,4045},
    {33,4032},
    {34,4020},
    {36,4008},
    {37,3996},
    {38,3985},
    {40,3973},
    {41,3960},
    {42,3945},
    {44,3926},
    {45,3910},
    {47,3897},
    {48,3887},
    {49,3877},
    {52,3869},
    {53,3861},
    {54,3854},
    {56,3846},
    {57,3840},
    {59,3833},
    {60,3827},
    {61,3821},
    {63,3816},
    {64,3810},
    {65,3806},
    {67,3801},
    {68,3796},
    {70,3791},
    {71,3784},
    {72,3774},
    {74,3766},
    {75,3760},
    {76,3754},
    {78,3747},
    {79,3740},
    {80,3734},
    {82,3727},
    {83,3720},
    {85,3709},
    {86,3698},
    {87,3685},
    {89,3677},
    {90,3676},
    {91,3675},
    {93,3674},
    {94,3673},
    {96,3667},
    {97,3640},
    {98,3586},
    {100,3511},
    {101,3401},
    {102,3206},
    {103,2962},
    {103,2901},
    {103,2875},
    {103,2863},
    {104,2863},
    {104,2863},
    {104,2863},
    {104,2863},
    {104,2863},
    {104,2863},
    {104,2863},
    {104,2863},
    {104,2863}

};
BATTERY_PROFILE_STRUCT *battery_profile_t3[TOTAL_BATTERY_NUMBER] =
{
    xinwangda_battery_profile_t3,
    desay_battery_profile_t3
};
int battery_profile_t3_size[] =
{
    sizeof(xinwangda_battery_profile_t3)/sizeof(BATTERY_PROFILE_STRUCT),
    sizeof(desay_battery_profile_t3)/sizeof(BATTERY_PROFILE_STRUCT)
};


/* battery profile for actual temperature. The size should be the same as T1,T2 and T3*/
BATTERY_PROFILE_STRUCT battery_profile_temperature[TOTAL_BATTERY_NUMBER][100] = {
    {
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0},
    {0,0}
    }
};
/* ============================================================
// <Rbat,Battery_Voltage> Table
// ============================================================*/
/* T0 -10C*/

R_PROFILE_STRUCT xinwangda_r_profile_t0[] =
{
    {885 , 4290},
    {885 , 4266},
    {918 , 4245},
    {928 , 4225},
    {943 , 4206},
    {945 , 4188},
    {943 , 4171},
    {945 , 4156},
    {960 , 4139},
    {963 , 4116},
    {963 , 4078},
    {1058, 4025},
    {1228, 3992},
    {1290, 3967},
    {1323, 3947},
    {1333, 3932},
    {1335, 3920},
    {1333, 3909},
    {1323, 3899},
    {1325, 3890},
    {1328, 3880},
    {1328, 3871},
    {1320, 3863},
    {1333, 3855},
    {1325, 3847},
    {1328, 3840},
    {1338, 3833},
    {1330, 3826},
    {1343, 3820},
    {1350, 3814},
    {1343, 3807},
    {1353, 3801},
    {1363, 3796},
    {1373, 3789},
    {1370, 3783},
    {1380, 3776},
    {1388, 3769},
    {1403, 3762},
    {1408, 3753},
    {1425, 3744},
    {1440, 3735},
    {1450, 3725},
    {1468, 3717},
    {1495, 3712},
    {1523, 3707},
    {1555, 3702},
    {1588, 3692},
    {1615, 3671},
    {1648, 3623},
    {1688, 3547},
    {1680, 3471},
    {1560, 3424},
    {1468, 3386},
    {1390, 3354},
    {1333, 3330},
    {1280, 3311},
    {1248, 3296},
    {1210, 3284},
    {1188, 3274},
    {1175, 3265},
    {1153, 3258},
    {1140, 3253},
    {1123, 3249},
    {1120, 3244},
    {1113, 3240},
    {1115, 3236},
    {1095, 3233},
    {1088, 3230},
    {1090, 3227},
    {1075, 3225},
    {1075, 3223},
    {1075, 3221},
    {1080, 3218},
    {1083, 3215},
    {1088, 3212},
    {1085, 3208},
    {1088, 3205},
    {1093, 3201},
    {1090, 3197},
    {1013, 3197},
    {1013, 3197},
    {1013, 3197},
    {1013, 3197},
    {1013, 3197},
    {1013, 3197},
    {1013, 3197},
    {1013, 3197},
    {1013, 3197}
};
R_PROFILE_STRUCT desay_r_profile_t0[] =
{
    {970 , 4253},
    {970 , 4215},
    {1035, 4183},
    {1073, 4156},
    {1090, 4134},
    {1105, 4115},
    {1118, 4101},
    {1140, 4088},
    {1145, 4072},
    {1143, 4050},
    {1130, 4026},
    {1120, 4004},
    {1115, 3986},
    {1113, 3970},
    {1120, 3957},
    {1128, 3945},
    {1125, 3932},
    {1120, 3919},
    {1115, 3905},
    {1115, 3893},
    {1105, 3881},
    {1113, 3871},
    {1105, 3862},
    {1108, 3854},
    {1110, 3846},
    {1115, 3839},
    {1110, 3832},
    {1123, 3826},
    {1123, 3821},
    {1133, 3816},
    {1133, 3811},
    {1140, 3807},
    {1153, 3804},
    {1155, 3801},
    {1170, 3798},
    {1183, 3796},
    {1195, 3793},
    {1208, 3791},
    {1230, 3788},
    {1245, 3785},
    {1268, 3781},
    {1288, 3777},
    {1310, 3772},
    {1333, 3767},
    {1363, 3760},
    {1393, 3753},
    {1418, 3746},
    {1440, 3738},
    {1475, 3730},
    {1508, 3721},
    {1550, 3713},
    {1593, 3706},
    {1628, 3699},
    {1675, 3693},
    {1720, 3687},
    {1765, 3679},
    {1813, 3662},
    {1840, 3629},
    {1883, 3567},
    {1785, 3513},
    {1675, 3468},
    {1578, 3430},
    {1490, 3395},
    {1418, 3364},
    {1343, 3335},
    {1283, 3310},
    {1220, 3287},
    {1175, 3267},
    {1135, 3249},
    {1085, 3234},
    {1060, 3218},
    {1025, 3204},
    {988 , 3194},
    {970 , 3183},
    {950 , 3174},
    {943 , 3174},
    {943 , 3174},
    {943 , 3174},
    {943 , 3174},
    {943 , 3174},
    {943 , 3174},
    {943 , 3174},
    {943 , 3174},
    {943 , 3174},
    {943 , 3174},
    {943 , 3174},
    {943 , 3174},
    {943 , 3174}
};
R_PROFILE_STRUCT *r_profile_t0[TOTAL_BATTERY_NUMBER] = {
    xinwangda_r_profile_t0,
    desay_r_profile_t0
};
int r_profile_t0_size[TOTAL_BATTERY_NUMBER] = {
    sizeof(xinwangda_r_profile_t0)/sizeof(R_PROFILE_STRUCT),
    sizeof(desay_r_profile_t0)/sizeof(R_PROFILE_STRUCT)
};

/* T1 0C*/
R_PROFILE_STRUCT xinwangda_r_profile_t1[] =
{
    {370 , 4343},
    {370 , 4320},
    {380 , 4301},
    {383 , 4279},
    {355 , 4220},
    {543 , 4185},
    {570 , 4166},
    {575 , 4150},
    {585 , 4134},
    {585 , 4119},
    {590 , 4105},
    {603 , 4092},
    {608 , 4080},
    {615 , 4067},
    {625 , 4052},
    {615 , 4031},
    {610 , 4011},
    {610 , 3995},
    {620 , 3983},
    {623 , 3972},
    {618 , 3961},
    {615 , 3948},
    {610 , 3934},
    {605 , 3919},
    {595 , 3905},
    {585 , 3891},
    {585 , 3880},
    {595 , 3871},
    {593 , 3861},
    {593 , 3854},
    {600 , 3846},
    {600 , 3839},
    {603 , 3832},
    {613 , 3826},
    {613 , 3820},
    {615 , 3815},
    {625 , 3810},
    {628 , 3805},
    {630 , 3800},
    {640 , 3796},
    {640 , 3792},
    {650 , 3789},
    {653 , 3786},
    {665 , 3784},
    {670 , 3781},
    {680 , 3779},
    {693 , 3775},
    {700 , 3772},
    {710 , 3767},
    {725 , 3762},
    {740 , 3758},
    {753 , 3752},
    {763 , 3745},
    {780 , 3737},
    {808 , 3729},
    {828 , 3720},
    {853 , 3710},
    {885 , 3701},
    {925 , 3696},
    {968 , 3693},
    {1033, 3689},
    {1108, 3682},
    {1205, 3658},
    {1303, 3597},
    {1470, 3500},
    {1510, 3403},
    {1333, 3332},
    {1173, 3269},
    {1050, 3216},
    {958 , 3178},
    {890 , 3155},
    {865 , 3136},
    {833 , 3125},
    {805 , 3116},
    {780 , 3109},
    {768 , 3101},
    {745 , 3097},
    {750 , 3090},
    {733 , 3084},
    {748 , 3084},
    {748 , 3084},
    {748 , 3084},
    {748 , 3084},
    {748 , 3084},
    {748 , 3084},
    {748 , 3084},
    {748 , 3084},
    {748 , 3084}
};
R_PROFILE_STRUCT desay_r_profile_t1[] =
{
    {503 , 4307},
    {503 , 4276},
    {533 , 4255},
    {540 , 4236},
    {548 , 4219},
    {555 , 4203},
    {563 , 4188},
    {563 , 4173},
    {568 , 4158},
    {570 , 4143},
    {575 , 4128},
    {578 , 4114},
    {578 , 4101},
    {590 , 4090},
    {605 , 4080},
    {618 , 4068},
    {608 , 4049},
    {595 , 4024},
    {585 , 4002},
    {583 , 3985},
    {580 , 3971},
    {580 , 3958},
    {580 , 3947},
    {575 , 3934},
    {568 , 3921},
    {555 , 3907},
    {550 , 3895},
    {548 , 3884},
    {550 , 3875},
    {548 , 3866},
    {550 , 3858},
    {553 , 3850},
    {553 , 3843},
    {555 , 3836},
    {558 , 3830},
    {563 , 3824},
    {565 , 3819},
    {570 , 3813},
    {575 , 3808},
    {580 , 3804},
    {580 , 3799},
    {585 , 3795},
    {593 , 3792},
    {595 , 3788},
    {600 , 3786},
    {613 , 3784},
    {620 , 3781},
    {630 , 3779},
    {640 , 3775},
    {655 , 3771},
    {665 , 3765},
    {680 , 3759},
    {698 , 3751},
    {718 , 3743},
    {735 , 3732},
    {753 , 3721},
    {780 , 3713},
    {810 , 3706},
    {848 , 3702},
    {888 , 3698},
    {948 , 3694},
    {1013, 3689},
    {1075, 3677},
    {1133, 3650},
    {1193, 3601},
    {1273, 3530},
    {1380, 3428},
    {1325, 3330},
    {1138, 3253},
    {980 , 3190},
    {843 , 3137},
    {750 , 3100},
    {693 , 3073},
    {653 , 3057},
    {623 , 3046},
    {598 , 3038},
    {585 , 3031},
    {565 , 3026},
    {565 , 3021},
    {560 , 3021},
    {560 , 3021},
    {560 , 3021},
    {560 , 3021},
    {560 , 3021},
    {560 , 3021},
    {560 , 3021},
    {560 , 3021},
    {560 , 3021}
};
R_PROFILE_STRUCT *r_profile_t1[TOTAL_BATTERY_NUMBER] = {
    xinwangda_r_profile_t1,
    desay_r_profile_t1
};
int r_profile_t1_size[TOTAL_BATTERY_NUMBER] = {
    sizeof(xinwangda_r_profile_t1)/sizeof(R_PROFILE_STRUCT),
    sizeof(desay_r_profile_t1)/sizeof(R_PROFILE_STRUCT)
};

/* T2 25C*/
R_PROFILE_STRUCT xinwangda_r_profile_t2[] = {
    {148 , 4361},
    {148 , 4342},
    {148 , 4325},
    {150 , 4309},
    {153 , 4293},
    {153 , 4277},
    {153 , 4261},
    {155 , 4246},
    {153 , 4229},
    {155 , 4214},
    {155 , 4198},
    {158 , 4183},
    {158 , 4167},
    {158 , 4152},
    {163 , 4138},
    {165 , 4123},
    {165 , 4108},
    {165 , 4093},
    {168 , 4080},
    {173 , 4069},
    {175 , 4055},
    {178 , 4040},
    {180 , 4026},
    {183 , 4012},
    {183 , 3999},
    {185 , 3987},
    {188 , 3976},
    {188 , 3965},
    {190 , 3955},
    {185 , 3941},
    {170 , 3923},
    {155 , 3905},
    {148 , 3891},
    {145 , 3881},
    {143 , 3871},
    {143 , 3863},
    {143 , 3855},
    {143 , 3848},
    {143 , 3841},
    {145 , 3835},
    {145 , 3829},
    {148 , 3823},
    {148 , 3818},
    {150 , 3813},
    {153 , 3808},
    {153 , 3803},
    {155 , 3799},
    {155 , 3795},
    {155 , 3791},
    {160 , 3788},
    {158 , 3784},
    {155 , 3779},
    {153 , 3774},
    {150 , 3768},
    {148 , 3763},
    {148 , 3758},
    {145 , 3752},
    {145 , 3747},
    {150 , 3744},
    {153 , 3739},
    {150 , 3731},
    {150 , 3723},
    {153 , 3716},
    {153 , 3706},
    {148 , 3696},
    {150 , 3693},
    {155 , 3691},
    {165 , 3690},
    {175 , 3686},
    {183 , 3672},
    {178 , 3620},
    {193 , 3542},
    {223 , 3419},
    {920 , 3165},
    {815 , 3121},
    {778 , 3101},
    {735 , 3089},
    {725 , 3079},
    {713 , 3070},
    {700 , 3070},
    {700 , 3070},
    {700 , 3070},
    {700 , 3070},
    {700 , 3070},
    {700 , 3070},
    {700 , 3070},
    {700 , 3070},
    {700 , 3070}
};
R_PROFILE_STRUCT desay_r_profile_t2[] =
{
    {125 , 4365},
    {125 , 4348},
    {125 , 4332},
    {128 , 4317},
    {125 , 4301},
    {128 , 4286},
    {128 , 4270},
    {128 , 4255},
    {130 , 4240},
    {130 , 4224},
    {130 , 4209},
    {130 , 4194},
    {135 , 4180},
    {135 , 4165},
    {138 , 4151},
    {138 , 4136},
    {143 , 4122},
    {145 , 4108},
    {145 , 4094},
    {148 , 4081},
    {150 , 4070},
    {165 , 4064},
    {163 , 4049},
    {158 , 4026},
    {160 , 4006},
    {160 , 3991},
    {168 , 3982},
    {173 , 3975},
    {168 , 3965},
    {158 , 3949},
    {138 , 3929},
    {125 , 3912},
    {118 , 3899},
    {118 , 3889},
    {118 , 3880},
    {118 , 3871},
    {120 , 3864},
    {120 , 3856},
    {123 , 3849},
    {123 , 3842},
    {125 , 3836},
    {128 , 3830},
    {130 , 3824},
    {130 , 3819},
    {133 , 3814},
    {135 , 3809},
    {135 , 3804},
    {138 , 3800},
    {138 , 3795},
    {138 , 3791},
    {138 , 3786},
    {135 , 3781},
    {135 , 3776},
    {133 , 3770},
    {130 , 3764},
    {130 , 3758},
    {125 , 3751},
    {130 , 3746},
    {133 , 3739},
    {130 , 3729},
    {130 , 3718},
    {130 , 3706},
    {123 , 3695},
    {125 , 3692},
    {130 , 3690},
    {145 , 3690},
    {158 , 3689},
    {168 , 3686},
    {173 , 3676},
    {163 , 3634},
    {173 , 3567},
    {198 , 3475},
    {253 , 3329},
    {613 , 3043},
    {478 , 2991},
    {430 , 2971},
    {393 , 2956},
    {360 , 2939},
    {325 , 2926},
    {320 , 2926},
    {320 , 2926},
    {320 , 2926},
    {320 , 2926},
    {320 , 2926},
    {320 , 2926},
    {320 , 2926},
    {320 , 2926},
    {320 , 2926}
};
R_PROFILE_STRUCT *r_profile_t2[TOTAL_BATTERY_NUMBER] = {
    xinwangda_r_profile_t2,
    desay_r_profile_t2
};
int r_profile_t2_size[TOTAL_BATTERY_NUMBER] = {
    sizeof(xinwangda_r_profile_t2)/sizeof(R_PROFILE_STRUCT),
    sizeof(desay_r_profile_t2)/sizeof(R_PROFILE_STRUCT)
};

/* T3 50C*/
R_PROFILE_STRUCT xinwangda_r_profile_t3[] = {
    {95  , 4374},
    {95  , 4356},
    {95  , 4340},
    {95  , 4324},
    {93  , 4307},
    {95  , 4292},
    {98  , 4276},
    {95  , 4259},
    {95  , 4243},
    {95  , 4227},
    {98  , 4212},
    {95  , 4196},
    {98  , 4181},
    {98  , 4165},
    {100 , 4150},
    {100 , 4135},
    {100 , 4120},
    {103 , 4106},
    {103 , 4091},
    {103 , 4077},
    {103 , 4063},
    {105 , 4050},
    {110 , 4038},
    {110 , 4024},
    {113 , 4011},
    {113 , 3999},
    {115 , 3988},
    {120 , 3977},
    {123 , 3966},
    {125 , 3954},
    {128 , 3943},
    {123 , 3928},
    {108 , 3908},
    {98  , 3892},
    {98  , 3881},
    {95  , 3872},
    {93  , 3863},
    {95  , 3855},
    {95  , 3848},
    {95  , 3841},
    {98  , 3835},
    {98  , 3828},
    {98  , 3822},
    {98  , 3816},
    {100 , 3811},
    {100 , 3806},
    {105 , 3802},
    {105 , 3797},
    {105 , 3793},
    {110 , 3789},
    {110 , 3785},
    {110 , 3781},
    {108 , 3775},
    {98  , 3764},
    {100 , 3756},
    {100 , 3750},
    {100 , 3744},
    {100 , 3738},
    {98  , 3732},
    {100 , 3728},
    {100 , 3723},
    {100 , 3716},
    {100 , 3708},
    {98  , 3700},
    {100 , 3692},
    {95  , 3681},
    {98  , 3679},
    {100 , 3677},
    {105 , 3676},
    {113 , 3672},
    {110 , 3656},
    {108 , 3604},
    {118 , 3528},
    {140 , 3413},
    {378 , 3167},
    {675 , 3069},
    {560 , 3008},
    {468 , 2967},
    {370 , 2948},
    {393 , 2948},
    {393 , 2948},
    {393 , 2948},
    {393 , 2948},
    {393 , 2948},
    {393 , 2948},
    {393 , 2948},
    {393 , 2948},
    {393 , 2948}
};
R_PROFILE_STRUCT desay_r_profile_t3[] =
{
    {70  , 4379},
    {70  , 4364},
    {73  , 4351},
    {70  , 4336},
    {73  , 4322},
    {73  , 4307},
    {73  , 4292},
    {75  , 4277},
    {73  , 4261},
    {75  , 4246},
    {78  , 4231},
    {78  , 4215},
    {80  , 4201},
    {80  , 4186},
    {80  , 4171},
    {83  , 4156},
    {83  , 4141},
    {85  , 4127},
    {88  , 4113},
    {88  , 4099},
    {90  , 4085},
    {90  , 4071},
    {93  , 4058},
    {93  , 4045},
    {95  , 4032},
    {98  , 4020},
    {100 , 4008},
    {103 , 3996},
    {108 , 3985},
    {108 , 3973},
    {110 , 3960},
    {105 , 3945},
    {90  , 3926},
    {80  , 3910},
    {75  , 3897},
    {75  , 3887},
    {73  , 3877},
    {75  , 3869},
    {75  , 3861},
    {78  , 3854},
    {78  , 3846},
    {80  , 3840},
    {80  , 3833},
    {83  , 3827},
    {85  , 3821},
    {88  , 3816},
    {88  , 3810},
    {93  , 3806},
    {93  , 3801},
    {93  , 3796},
    {93  , 3791},
    {90  , 3784},
    {80  , 3774},
    {80  , 3766},
    {83  , 3760},
    {83  , 3754},
    {83  , 3747},
    {80  , 3740},
    {80  , 3734},
    {80  , 3727},
    {80  , 3720},
    {78  , 3709},
    {78  , 3698},
    {78  , 3685},
    {73  , 3677},
    {75  , 3676},
    {80  , 3675},
    {85  , 3674},
    {90  , 3673},
    {88  , 3667},
    {85  , 3640},
    {95  , 3586},
    {105 , 3511},
    {120 , 3401},
    {183 , 3206},
    {408 , 2962},
    {255 , 2901},
    {198 , 2875},
    {163 , 2863},
    {158 , 2863},
    {158 , 2863},
    {158 , 2863},
    {158 , 2863},
    {158 , 2863},
    {158 , 2863},
    {158 , 2863},
    {158 , 2863},
    {158 , 2863}
};
R_PROFILE_STRUCT *r_profile_t3[TOTAL_BATTERY_NUMBER] = {
    xinwangda_r_profile_t3,
    desay_r_profile_t3
};
int r_profile_t3_size[TOTAL_BATTERY_NUMBER] = {
    sizeof(xinwangda_r_profile_t3)/sizeof(R_PROFILE_STRUCT),
    sizeof(desay_r_profile_t3)/sizeof(R_PROFILE_STRUCT)
};

/* r-table profile for actual temperature. The size should be the same as T1,T2 and T3*/
R_PROFILE_STRUCT r_profile_temperature[TOTAL_BATTERY_NUMBER][100] = {
{
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0},
	{0,0}
   }
};
/* ============================================================
// function prototype
// ============================================================*/
int fgauge_get_saddles(void);
BATTERY_PROFILE_STRUCT_P fgauge_get_profile(unsigned int temperature);

int fgauge_get_saddles_r_table(void);
R_PROFILE_STRUCT_P fgauge_get_profile_r_table(unsigned int temperature);

#endif

