#include "stdint.h"

#include <em_i2c.h>

#include "STC3105.h"
#include "tester.h"

uint16_t Tab_Voltage[2049] = {2,4,7,9,12,14,17,19,21,24,26,29,31,34,36,39,41,43,46,48,51,53,56,58,61,63,65,68,70,73,75,78,80,82,85,87,90,92,95,97,100,102,104,107,109,
		112,114,117,119,122,124,126,129,131,134,136,139,141,143,146,148,151,153,156,158,161,163,165,168,170,173,175,178,180,183,185,187,190,192,195,197,200,202,204,
		207,209,212,214,217,219,222,224,226,229,231,234,236,239,241,244,246,248,251,253,256,258,261,263,265,268,270,273,275,278,280,283,285,287,290,292,295,297,300,
		302,305,307,309,312,314,317,319,322,324,326,329,331,334,336,339,341,344,346,348,351,353,356,358,361,363,366,368,370,373,375,378,380,383,385,387,390,392,395,
		397,400,402,405,407,409,412,414,417,419,422,424,427,429,431,434,436,439,441,444,446,448,451,453,456,458,461,463,466,468,470,473,475,478,480,483,485,488,490,
		492,495,497,500,502,505,507,509,512,514,517,519,522,524,527,529,531,534,536,539,541,544,546,549,551,553,556,558,561,563,566,568,570,573,575,578,580,583,585,
		588,590,592,595,597,600,602,605,607,610,612,614,617,619,622,624,627,629,631,634,636,639,641,644,646,649,651,653,656,658,661,663,666,668,671,673,675,678,680,
		683,685,688,690,692,695,697,700,702,705,707,710,712,714,717,719,722,724,727,729,732,734,736,739,741,744,746,749,751,753,756,758,761,763,766,768,771,773,775,
		778,780,783,785,788,790,793,795,797,800,802,805,807,810,812,814,817,819,822,824,827,829,832,834,836,839,841,844,846,849,851,854,856,858,861,863,866,868,871,
		873,875,878,880,883,885,888,890,893,895,897,900,902,905,907,910,912,915,917,919,922,924,927,929,932,934,936,939,941,944,946,949,951,954,956,958,961,963,966,
		968,971,973,976,978,980,983,985,988,990,993,995,997,1000,1002,1005,1007,1010,1012,1015,1017,1019,1022,1024,1027,1029,1032,1034,1037,1039,1041,1044,1046,1049,
		1051,1054,1056,1058,1061,1063,1066,1068,1071,1073,1076,1078,1080,1083,1085,1088,1090,1093,1095,1098,1100,1102,1105,1107,1110,1112,1115,1117,1119,1122,1124,
		1127,1129,1132,1134,1137,1139,1141,1144,1146,1149,1151,1154,1156,1159,1161,1163,1166,1168,1171,1173,1176,1178,1180,1183,1185,1188,1190,1193,1195,1198,1200,
		1202,1205,1207,1210,1212,1215,1217,1220,1222,1224,1227,1229,1232,1234,1237,1239,1241,1244,1246,1249,1251,1254,1256,1259,1261,1263,1266,1268,1271,1273,1276,
		1278,1281,1283,1285,1288,1290,1293,1295,1298,1300,1302,1305,1307,1310,1312,1315,1317,1320,1322,1324,1327,1329,1332,1334,1337,1339,1342,1344,1346,1349,1351,
		1354,1356,1359,1361,1363,1366,1368,1371,1373,1376,1378,1381,1383,1385,1388,1390,1393,1395,1398,1400,1403,1405,1407,1410,1412,1415,1417,1420,1422,1424,1427,
		1429,1432,1434,1437,1439,1442,1444,1446,1449,1451,1454,1456,1459,1461,1464,1466,1468,1471,1473,1476,1478,1481,1483,1485,1488,1490,1493,1495,1498,1500,1503,
		1505,1507,1510,1512,1515,1517,1520,1522,1525,1527,1529,1532,1534,1537,1539,1542,1544,1546,1549,1551,1554,1556,1559,1561,1564,1566,1568,1571,1573,1576,1578,
		1581,1583,1586,1588,1590,1593,1595,1598,1600,1603,1605,1607,1610,1612,1615,1617,1620,1622,1625,1627,1629,1632,1634,1637,1639,1642,1644,1647,1649,1651,1654,
		1656,1659,1661,1664,1666,1668,1671,1673,1676,1678,1681,1683,1686,1688,1690,1693,1695,1698,1700,1703,1705,1708,1710,1712,1715,1717,1720,1722,1725,1727,1729,
		1732,1734,1737,1739,1742,1744,1747,1749,1751,1754,1756,1759,1761,1764,1766,1769,1771,1773,1776,1778,1781,1783,1786,1788,1790,1793,1795,1798,1800,1803,1805,
		1808,1810,1812,1815,1817,1820,1822,1825,1827,1830,1832,1834,1837,1839,1842,1844,1847,1849,1851,1854,1856,1859,1861,1864,1866,1869,1871,1873,1876,1878,1881,
		1883,1886,1888,1891,1893,1895,1898,1900,1903,1905,1908,1910,1912,1915,1917,1920,1922,1925,1927,1930,1932,1934,1937,1939,1942,1944,1947,1949,1952,1954,1956,
		1959,1961,1964,1966,1969,1971,1973,1976,1978,1981,1983,1986,1988,1991,1993,1995,1998,2000,2003,2005,2008,2010,2013,2015,2017,2020,2022,2025,2027,2030,2032,
		2034,2037,2039,2042,2044,2047,2049,2052,2054,2056,2059,2061,2064,2066,2069,2071,2074,2076,2078,2081,2083,2086,2088,2091,2093,2095,2098,2100,2103,2105,2108,
		2110,2113,2115,2117,2120,2122,2125,2127,2130,2132,2135,2137,2139,2142,2144,2147,2149,2152,2154,2156,2159,2161,2164,2166,2169,2171,2174,2176,2178,2181,2183,
		2186,2188,2191,2193,2196,2198,2200,2203,2205,2208,2210,2213,2215,2217,2220,2222,2225,2227,2230,2232,2235,2237,2239,2242,2244,2247,2249,2252,2254,2257,2259,
		2261,2264,2266,2269,2271,2274,2276,2278,2281,2283,2286,2288,2291,2293,2296,2298,2300,2303,2305,2308,2310,2313,2315,2318,2320,2322,2325,2327,2330,2332,2335,
		2337,2339,2342,2344,2347,2349,2352,2354,2357,2359,2361,2364,2366,2369,2371,2374,2376,2379,2381,2383,2386,2388,2391,2393,2396,2398,2400,2403,2405,2408,2410,
		2413,2415,2418,2420,2422,2425,2427,2430,2432,2435,2437,2440,2442,2444,2447,2449,2452,2454,2457,2459,2461,2464,2466,2469,2471,2474,2476,2479,2481,2483,2486,
		2488,2491,2493,2496,2498,2501,2503,2505,2508,2510,2513,2515,2518,2520,2522,2525,2527,2530,2532,2535,2537,2540,2542,2544,2547,2549,2552,2554,2557,2559,2562,
		2564,2566,2569,2571,2574,2576,2579,2581,2583,2586,2588,2591,2593,2596,2598,2601,2603,2605,2608,2610,2613,2615,2618,2620,2623,2625,2627,2630,2632,2635,2637,
		2640,2642,2644,2647,2649,2652,2654,2657,2659,2662,2664,2666,2669,2671,2674,2676,2679,2681,2684,2686,2688,2691,2693,2696,2698,2701,2703,2705,2708,2710,2713,
		2715,2718,2720,2723,2725,2727,2730,2732,2735,2737,2740,2742,2745,2747,2749,2752,2754,2757,2759,2762,2764,2766,2769,2771,2774,2776,2779,2781,2784,2786,2788,
		2791,2793,2796,2798,2801,2803,2806,2808,2810,2813,2815,2818,2820,2823,2825,2827,2830,2832,2835,2837,2840,2842,2845,2847,2849,2852,2854,2857,2859,2862,2864,
		2867,2869,2871,2874,2876,2879,2881,2884,2886,2888,2891,2893,2896,2898,2901,2903,2906,2908,2910,2913,2915,2918,2920,2923,2925,2928,2930,2932,2935,2937,2940,
		2942,2945,2947,2949,2952,2954,2957,2959,2962,2964,2967,2969,2971,2974,2976,2979,2981,2984,2986,2989,2991,2993,2996,2998,3001,3003,3006,3008,3010,3013,3015,
		3018,3020,3023,3025,3028,3030,3032,3035,3037,3040,3042,3045,3047,3050,3052,3054,3057,3059,3062,3064,3067,3069,3071,3074,3076,3079,3081,3084,3086,3089,3091,
		3093,3096,3098,3101,3103,3106,3108,3111,3113,3115,3118,3120,3123,3125,3128,3130,3132,3135,3137,3140,3142,3145,3147,3150,3152,3154,3157,3159,3162,3164,3167,
		3169,3172,3174,3176,3179,3181,3184,3186,3189,3191,3193,3196,3198,3201,3203,3206,3208,3211,3213,3215,3218,3220,3223,3225,3228,3230,3233,3235,3237,3240,3242,
		3245,3247,3250,3252,3254,3257,3259,3262,3264,3267,3269,3272,3274,3276,3279,3281,3284,3286,3289,3291,3294,3296,3298,3301,3303,3306,3308,3311,3313,3315,3318,
		3320,3323,3325,3328,3330,3333,3335,3337,3340,3342,3345,3347,3350,3352,3355,3357,3359,3362,3364,3367,3369,3372,3374,3376,3379,3381,3384,3386,3389,3391,3394,
		3396,3398,3401,3403,3406,3408,3411,3413,3416,3418,3420,3423,3425,3428,3430,3433,3435,3437,3440,3442,3445,3447,3450,3452,3455,3457,3459,3462,3464,3467,3469,
		3472,3474,3477,3479,3481,3484,3486,3489,3491,3494,3496,3498,3501,3503,3506,3508,3511,3513,3516,3518,3520,3523,3525,3528,3530,3533,3535,3538,3540,3542,3545,
		3547,3550,3552,3555,3557,3559,3562,3564,3567,3569,3572,3574,3577,3579,3581,3584,3586,3589,3591,3594,3596,3599,3601,3603,3606,3608,3611,3613,3616,3618,3620,
		3623,3625,3628,3630,3633,3635,3638,3640,3642,3645,3647,3650,3652,3655,3657,3660,3662,3664,3667,3669,3672,3674,3677,3679,3681,3684,3686,3689,3691,3694,3696,
		3699,3701,3703,3706,3708,3711,3713,3716,3718,3721,3723,3725,3728,3730,3733,3735,3738,3740,3742,3745,3747,3750,3752,3755,3757,3760,3762,3764,3767,3769,3772,
		3774,3777,3779,3782,3784,3786,3789,3791,3794,3796,3799,3801,3803,3806,3808,3811,3813,3816,3818,3821,3823,3825,3828,3830,3833,3835,3838,3840,3843,3845,3847,
		3850,3852,3855,3857,3860,3862,3864,3867,3869,3872,3874,3877,3879,3882,3884,3886,3889,3891,3894,3896,3899,3901,3904,3906,3908,3911,3913,3916,3918,3921,3923,
		3925,3928,3930,3933,3935,3938,3940,3943,3945,3947,3950,3952,3955,3957,3960,3962,3965,3967,3969,3972,3974,3977,3979,3982,3984,3986,3989,3991,3994,3996,3999,
		4001,4004,4006,4008,4011,4013,4016,4018,4021,4023,4026,4028,4030,4033,4035,4038,4040,4043,4045,4047,4050,4052,4055,4057,4060,4062,4065,4067,4069,4072,4074,
		4077,4079,4082,4084,4087,4089,4091,4094,4096,4099,4101,4104,4106,4108,4111,4113,4116,4118,4121,4123,4126,4128,4130,4133,4135,4138,4140,4143,4145,4148,4150,
		4152,4155,4157,4160,4162,4165,4167,4169,4172,4174,4177,4179,4182,4184,4187,4189,4191,4194,4196,4199,4201,4204,4206,4209,4211,4213,4216,4218,4221,4223,4226,
		4228,4230,4233,4235,4238,4240,4243,4245,4248,4250,4252,4255,4257,4260,4262,4265,4267,4270,4272,4274,4277,4279,4282,4284,4287,4289,4291,4294,4296,4299,4301,
		4304,4306,4309,4311,4313,4316,4318,4321,4323,4326,4328,4331,4333,4335,4338,4340,4343,4345,4348,4350,4352,4355,4357,4360,4362,4365,4367,4370,4372,4374,4377,
		4379,4382,4384,4387,4389,4392,4394,4396,4399,4401,4404,4406,4409,4411,4413,4416,4418,4421,4423,4426,4428,4431,4433,4435,4438,4440,4443,4445,4448,4450,4453,
		4455,4457,4460,4462,4465,4467,4470,4472,4474,4477,4479,4482,4484,4487,4489,4492,4494,4496,4499,4501,4504,4506,4509,4511,4514,4516,4518,4521,4523,4526,4528,
		4531,4533,4535,4538,4540,4543,4545,4548,4550,4553,4555,4557,4560,4562,4565,4567,4570,4572,4575,4577,4579,4582,4584,4587,4589,4592,4594,4596,4599,4601,4604,
		4606,4609,4611,4614,4616,4618,4621,4623,4626,4628,4631,4633,4636,4638,4640,4643,4645,4648,4650,4653,4655,4657,4660,4662,4665,4667,4670,4672,4675,4677,4679,
		4682,4684,4687,4689,4692,4694,4697,4699,4701,4704,4706,4709,4711,4714,4716,4718,4721,4723,4726,4728,4731,4733,4736,4738,4740,4743,4745,4748,4750,4753,4755,
		4758,4760,4762,4765,4767,4770,4772,4775,4777,4779,4782,4784,4787,4789,4792,4794,4797,4799,4801,4804,4806,4809,4811,4814,4816,4819,4821,4823,4826,4828,4831,
		4833,4836,4838,4840,4843,4845,4848,4850,4853,4855,4858,4860,4862,4865,4867,4870,4872,4875,4877,4880,4882,4884,4887,4889,4892,4894,4897,4899,4901,4904,4906,
		4909,4911,4914,4916,4919,4921,4923,4926,4928,4931,4933,4936,4938,4941,4943,4945,4948,4950,4953,4955,4958,4960,4962,4965,4967,4970,4972,4975,4977,4980,4982,
		4984,4987,4989,4992,4994,4997,4999};


I2C_TransferSeq_TypeDef i2cTransfertSTC3105;
I2C_TransferReturn_TypeDef statusSTC3105;

void STC3105_INIT_I2C(void)
{
	//I2C_Init_TypeDef i2cInit = I2C_INIT_DEFAULT;
	GPIO_PinModeSet(gpioPortC, 4, gpioModeWiredAndPullUpFilter, 1); //sda pc4 e0
	GPIO_PinModeSet(gpioPortC, 5,gpioModeWiredAndPullUpFilter, 1); //scl pc5 e1
	GPIO_PinOutSet(gpioPortC,4);
	GPIO_PinOutSet(gpioPortC,5);

	CMU_ClockEnable(cmuClock_I2C1,true);
	I2C_Reset(I2C1);

	I2C1->CTRL = (1 << 2) | (1 << 0);           // auto acknowledge, enable I2C module
	I2C1->CMD = (1 << 7) | (1 << 6) | (1 << 5); // Clear pending commands, clear TX buffer and shift reg, issue abort command to clear bus busy bit
	I2C1->CLKDIV = 0x1FF;                          // allows for 100kHz I2C clock
	//					       //                else    I2C1->CLKDIV = 0x0;
	I2C1->ROUTE = 0x03;//I2C_ROUTE_LOCATION_LOC0|I2C_ROUTE_SCLPEN|I2C_ROUTE_SDAPEN;
}

void STC3105_WriteRegister(uint8_t reg, uint8_t value)
{
	uint8_t ui8result = 0;
	uint8_t ui8Deb = 0;
	uint8_t Tab[2];

	Tab[0] = reg;
	Tab[1] = value;

	i2cTransfertSTC3105.addr = STC3105_Address;
	i2cTransfertSTC3105.flags = I2C_FLAG_WRITE_WRITE;     // READ Operation
	i2cTransfertSTC3105.buf[0].data = &Tab;             // buffer
	i2cTransfertSTC3105.buf[0].len = 2;            // Read 2 bytes as the device is 16b


	statusSTC3105 = I2C_TransferInit(I2C1, &i2cTransfertSTC3105);
	while ( statusSTC3105 == i2cTransferInProgress) {
		statusSTC3105 = I2C_Transfer(I2C1);
	}
}

uint8_t STC3105_ReadRegister(uint8_t reg)
{
	uint8_t value =0;
	I2C_TransferReturn_TypeDef I2C_Status;
	I2C_TransferSeq_TypeDef seq;
	STC3105_INIT_I2C();
	uint8_t regid[1];	uint8_t data[1];

	seq.addr = STC3105_Address;
	seq.flags = I2C_FLAG_WRITE_READ;/* Select register to be read */
	regid[0] = reg; seq.buf[0].data = regid; seq.buf[0].len = 1;

		/* Select location/length to place register */
		/* Only 1 byte reg, clear upper 8 bits */
	data[0] = 0;

	seq.buf[1].data=data;seq.buf[1].len = 2;

		  /* Do a polled transfer */
	I2C_Status = I2C_TransferInit(I2C1, &seq);
	while (I2C_Status == i2cTransferInProgress){
		  I2C_Status = I2C_Transfer(I2C1);
	}
	value=data[0];
	return value;
}
uint8_t STC3105_GET_CURRENT_THRES()
{
	uint8_t value = 0;
	I2C_TransferReturn_TypeDef I2C_Status;
	I2C_TransferSeq_TypeDef seq;
	STC3105_INIT_I2C();
	uint8_t regid[1];	uint8_t data[1];

	seq.addr = STC3105_Address;
	seq.flags = I2C_FLAG_WRITE_READ;/* Select register to be read */
	regid[0] = REG_CURRENT_THRES; seq.buf[0].data = regid; seq.buf[0].len = 1;

			/* Select location/length to place register */
			/* Only 1 byte reg, clear upper 8 bits */
	data[0] = 0;

	seq.buf[1].data=data;seq.buf[1].len = 2;

			  /* Do a polled transfer */
	I2C_Status = I2C_TransferInit(I2C1, &seq);
	while (I2C_Status == i2cTransferInProgress){
		  I2C_Status = I2C_Transfer(I2C1);
	}
	value=data[0];

		return value;
}
uint8_t STC3105_GET_ALARM()
{
	uint8_t value = 0;
	I2C_TransferReturn_TypeDef I2C_Status;
	I2C_TransferSeq_TypeDef seq;
	STC3105_INIT_I2C();
	uint8_t regid[1]; uint8_t data[1];
	seq.addr = STC3105_Address;
	seq.flags = I2C_FLAG_WRITE_READ;/* Select register to be read */
	regid[0] = REG_ALARM_VOLTAGE; seq.buf[0].data = regid; seq.buf[0].len = 1;

	/* Select location/length to place register */
	/* Only 1 byte reg, clear upper 8 bits */
	data[0] = 0;

	seq.buf[1].data=data; seq.buf[1].len = 1;

		  /* Do a polled transfer */
		I2C_Status = I2C_TransferInit(I2C1, &seq);
		while (I2C_Status == i2cTransferInProgress){
			  I2C_Status = I2C_Transfer(I2C1);
		}
	value=data[0];
	return value;
}
uint16_t STC3105_GET_CURRENT()
{
	uint16_t vlt = 0;

	I2C_TransferReturn_TypeDef I2C_Status;
	I2C_TransferSeq_TypeDef seq;
	STC3105_INIT_I2C();
	uint8_t regid[1];
	uint8_t data[2];

	seq.addr = STC3105_Address;
	seq.flags = I2C_FLAG_WRITE_READ;
	/* Select register to be read */
	regid[0] = REG_CURRENT_LOW; seq.buf[0].data = regid; seq.buf[0].len = 1;

	/* Select location/length to place register */
	/* Only 1 byte reg, clear upper 8 bits */
	data[0] = 0;
	data[1] = 0;

	seq.buf[1].data=data;
	seq.buf[1].len = 2;

	  /* Do a polled transfer */
	I2C_Status = I2C_TransferInit(I2C1, &seq);
	while (I2C_Status == i2cTransferInProgress){
		  I2C_Status = I2C_Transfer(I2C1);
	}

	vlt= (uint16_t)data[1] << 8 | data[0];
	vlt = ~vlt + 1; // binary code now
	vlt =  12 *  vlt/30;

	return vlt; // mA
}
uint16_t STC3105_GET_VOLTAGE()
{
	uint16_t voltage = 0;

	I2C_TransferReturn_TypeDef I2C_Status;
	I2C_TransferSeq_TypeDef seq;

	STC3105_INIT_I2C();

	 uint8_t regid[1];
	 uint8_t data[2];

	 seq.addr = STC3105_Address;
	 seq.flags = I2C_FLAG_WRITE_READ;
	  /* Select register to be read */
	 regid[0] = REG_VOLTAGE_LOW; seq.buf[0].data = regid; seq.buf[0].len = 1;

	  /* Select location/length to place register */
	    /* Only 1 byte reg, clear upper 8 bits */
	  data[0] = 0;
	  data[1] = 0;

	 seq.buf[1].data=data;
	 seq.buf[1].len = 2;

	  /* Do a polled transfer */
	 I2C_Status = I2C_TransferInit(I2C1, &seq);
	  while (I2C_Status == i2cTransferInProgress){
		  I2C_Status = I2C_Transfer(I2C1);
	    }
	voltage = (uint16_t)data[1]<< 8 |data[0];
	return Tab_Voltage[voltage]; // mV
}
uint16_t STC3105_GET_CHARGE()
{
	uint16_t result = 0;

	I2C_TransferReturn_TypeDef I2C_Status;
	I2C_TransferSeq_TypeDef seq;

	STC3105_INIT_I2C();

	uint8_t regid[1];
	uint8_t data[2];

	seq.addr = STC3105_Address;
	seq.flags = I2C_FLAG_WRITE_READ;
	/* Select register to be read */
	regid[0] = REG_CHARGE_LOW; seq.buf[0].data = regid; seq.buf[0].len = 1;

	/* Select location/length to place register */
	/* Only 1 byte reg, clear upper 8 bits */
	data[0] = 0;
	data[1] = 0;

	seq.buf[1].data=data; seq.buf[1].len = 2;
    /* Do a polled transfer */
	I2C_Status = I2C_TransferInit(I2C1, &seq);

	while (I2C_Status == i2cTransferInProgress){
		I2C_Status = I2C_Transfer(I2C1);
	}

	return result = ((uint16_t)data[1] << 8 | data[0]) * 8;  // uV.h.
}
uint16_t STC3105_GET_COUNTER()
{
	uint16_t data1 = 0;

	I2C_TransferReturn_TypeDef I2C_Status;
	I2C_TransferSeq_TypeDef seq;

	STC3105_INIT_I2C();

	uint8_t regid[1];
	uint8_t data[2];

	seq.addr = STC3105_Address;
	seq.flags = I2C_FLAG_WRITE_READ;
	/* Select register to be read */
	regid[0] = REG_COUNTER_LOW; seq.buf[0].data = regid; seq.buf[0].len = 1;

	/* Select location/length to place register */
	/* Only 1 byte reg, clear upper 8 bits */
	data[0] = 0;data[1] = 0;

	seq.buf[1].data=data; seq.buf[1].len = 2;
	/* Do a polled transfer */
	I2C_Status = I2C_TransferInit(I2C1, &seq);

	while (I2C_Status == i2cTransferInProgress){
		I2C_Status = I2C_Transfer(I2C1);
	}

	data1 = (uint16_t)data[1] << 8 | data[0];

	return data1;
}
uint16_t STC3105_GET_ALARM_SOC()
{
	uint8_t value1=0;
	uint8_t value2=0;
	uint16_t val;

	I2C_TransferReturn_TypeDef I2C_Status;
	I2C_TransferSeq_TypeDef seq;
	STC3105_INIT_I2C();
	uint8_t regid[1];	uint8_t data[2];

	seq.addr = STC3105_Address;
	seq.flags = I2C_FLAG_WRITE_READ;/* Select register to be read */
	regid[0] = REG_ALARM_SOC_LOW; seq.buf[0].data = regid; seq.buf[0].len = 1;

			/* Select location/length to place register */
			/* Only 1 byte reg, clear upper 8 bits */
	data[0] = 0;

	seq.buf[1].data=data;seq.buf[1].len = 2;
			  /* Do a polled transfer */
	I2C_Status = I2C_TransferInit(I2C1, &seq);
	while (I2C_Status == i2cTransferInProgress){
		  I2C_Status = I2C_Transfer(I2C1);
	}

	val = (uint16_t)data[1]<<8 | data[0];
	return val;
}

uint16_t STC3105_GET_SOC_BASE()
{
	uint16_t data =0;
	uint8_t values1 = 0;
	uint8_t values2 = 0;

	//read_byte(REG_SOC_BASE_HIGH,Address_STC3105,&values2);
	//read_byte(REG_SOC_BASE_LOW,Address_STC3105,&values1);
		return ((uint16_t)values2<<8 | values1);
}


void STC3105_SET_ALARM(uint8_t alarm)
{
	//write_byte(REG_ALARM_VOLTAGE,Address_STC3105,alarm);
}
void STC3105_Init_ConfigMode(uint8_t reg, uint8_t config)
{
	//REG_MODE    PWR_SAVE_ACTIVE_MODE | ALM_ENA_ENABLE| GG_RUN_OPERATING_MODE;
	//REG_CTRL     IO_DATA_ALM_ON;

	/*i2cTransfert1.addr = Address_STC3105;
	i2cTransfert1.flags = I2C_FLAG_WRITE_WRITE;

	i2cTransfert1.buf[0].len = 2;
	//i2cTransfert.buf[1].len = 1;

	i2cTransfert1.buf[0].data[0] = &reg;
	i2cTransfert1.buf[0].data[1] = &config ;

	// Start I2C read
	status = I2C_TransferInit(1, &i2cTransfert1);
	while ( status == i2cTransferInProgress) {
		      status = I2C_Transfer(I2C1);*/

	STC3105_WriteRegister(reg,config);
	//write_byte(REG_CTRL,Address_STC3105,IO_DATA_ALM_ON);
}
void STC3105_SET_CURRENT_THRES(uint8_t current_thres)
{
	//write_byte(REG_CURRENT_THRES,Address_STC3105,current_thres);
}
void STC3105_SET_ALARM_SOC(uint16_t value)
{
	uint8_t values1 = 0xFF & value;
	uint8_t values2 = value >>8;

	//write_byte(REG_ALARM_SOC_HIGH,Address_STC3105,values2);
	//write_byte(REG_ALARM_SOC_LOW, Address_STC3105,values1);
}
void STC3105_RESET_ALM()
{
	//The ALM pin remains low (even if the conditions disappear) until the software writes the
	//ALM_VOLT and ALM_SOC bits to 0 to clear the interrupt.
	//REG_CTRL	  IO_DATA_ALM_ON| GG_RST_ON| PORDET_RELEASE_SOFT_RESTART| ALM_SOC_CLEAR| ALM_VOLT_CLEAR

	//write_byte(REG_CTRL,Address_STC3105,IO_DATA_ALM_ON| GG_RST_ON| PORDET_RELEASE_SOFT_RESTART| ALM_SOC_CLEAR| ALM_VOLT_CLEAR);
}
void STC3105_SET_SOC_BASE(uint16_t value)
{
	uint8_t value1 = 0xFF&value;
	uint8_t value2 = value >> 8;

	//write_byte(REG_SOC_BASE_HIGH,Address_STC3105,value2);
	//write_byte(REG_SOC_BASE_LOW,Address_STC3105,value1);
}

