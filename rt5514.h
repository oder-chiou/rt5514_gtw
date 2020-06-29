/*
 * rt5514.h  --  RT5514 ALSA SoC audio driver
 *
 * Copyright 2015 Realtek Microelectronics
 * Author: Oder Chiou <oder_chiou@realtek.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __RT5514_H__
#define __RT5514_H__

#include <linux/clk.h>
#include <sound/rt5514.h>

#define RT5514_DEVICE_ID			0x10ec5514

#define RT5514_RESET				0x2000
#define RT5514_PWR_ANA1				0x2004
#define RT5514_PWR_ANA2				0x2008
#define RT5514_I2S_CTRL1			0x2010
#define RT5514_I2S_CTRL2			0x2014
#define RT5514_VAD_CTRL6			0x2030
#define RT5514_EXT_VAD_CTRL			0x206c
#define RT5514_DIG_IO_CTRL			0x2070
#define RT5514_PAD_CTRL1			0x2080
#define RT5514_DMIC_DATA_CTRL			0x20a0
#define RT5514_DIG_SOURCE_CTRL			0x20a4
#define RT5514_SRC_CTRL				0x20ac
#define RT5514_DOWNFILTER2_CTRL1		0x20d0
#define RT5514_PLL_SOURCE_CTRL			0x2100
#define RT5514_CLK_CTRL1			0x2104
#define RT5514_CLK_CTRL2			0x2108
#define RT5514_PLL3_CALIB_CTRL1			0x2110
#define RT5514_PLL3_CALIB_CTRL4			0x2120
#define RT5514_PLL3_CALIB_CTRL5			0x2124
#define RT5514_PLL3_CALIB_CTRL6			0x2128
#define RT5514_DELAY_BUF_CTRL1			0x2140
#define RT5514_DELAY_BUF_CTRL3			0x2148
#define RT5514_ASRC_IN_CTRL1			0x2180
#define RT5514_DOWNFILTER0_CTRL1		0x2190
#define RT5514_DOWNFILTER0_CTRL2		0x2194
#define RT5514_DOWNFILTER0_CTRL3		0x2198
#define RT5514_DOWNFILTER1_CTRL1		0x21a0
#define RT5514_DOWNFILTER1_CTRL2		0x21a4
#define RT5514_DOWNFILTER1_CTRL3		0x21a8
#define RT5514_ANA_CTRL_LDO10			0x2200
#define RT5514_ANA_CTRL_LDO18_16		0x2204
#define RT5514_ANA_CTRL_ADC12			0x2210
#define RT5514_ANA_CTRL_ADC21			0x2214
#define RT5514_ANA_CTRL_ADC22			0x2218
#define RT5514_ANA_CTRL_ADC23			0x221c
#define RT5514_ANA_CTRL_MICBST			0x2220
#define RT5514_ANA_CTRL_ADCFED			0x2224
#define RT5514_ANA_CTRL_INBUF			0x2228
#define RT5514_ANA_CTRL_VREF			0x222c
#define RT5514_ANA_CTRL_PLL3			0x2240
#define RT5514_ANA_CTRL_PLL2_1			0x2250
#define RT5514_ANA_CTRL_PLL2_2			0x2254
#define RT5514_ANA_CTRL_PLL1_1			0x2260
#define RT5514_ANA_CTRL_PLL1_2			0x2264
#define RT5514_DMIC_LP_CTRL			0x2e00
#define RT5514_MISC_CTRL_DSP			0x2e04
#define RT5514_DSP_CTRL1			0x2f00
#define RT5514_DSP_CTRL3			0x2f08
#define RT5514_DSP_CTRL4			0x2f10
#define RT5514_VENDOR_ID1			0x2ff0
#define RT5514_VENDOR_ID2			0x2ff4

#define RT5514_DSP_MAPPING			0x18000000

/* RT5514_PWR_ANA1 (0x2004) */
#define RT5514_POW_LDO18_IN			(0x1 << 5)
#define RT5514_POW_LDO18_IN_BIT			5
#define RT5514_POW_LDO18_ADC			(0x1 << 4)
#define RT5514_POW_LDO18_ADC_BIT		4
#define RT5514_POW_LDO21			(0x1 << 3)
#define RT5514_POW_LDO21_BIT			3
#define RT5514_POW_BG_LDO18_IN			(0x1 << 2)
#define RT5514_POW_BG_LDO18_IN_BIT		2
#define RT5514_POW_BG_LDO21			(0x1 << 1)
#define RT5514_POW_BG_LDO21_BIT			1

/* RT5514_PWR_ANA2 (0x2008) */
#define RT5514_POW_PLL2				(0x1 << 22)
#define RT5514_POW_PLL2_BIT			22
#define RT5514_POW_PLL2_LDO			(0x1 << 20)
#define RT5514_POW_PLL2_LDO_BIT			20
#define RT5514_POW_PLL1				(0x1 << 18)
#define RT5514_POW_PLL1_BIT			18
#define RT5514_POW_PLL1_LDO			(0x1 << 16)
#define RT5514_POW_PLL1_LDO_BIT			16
#define RT5514_POW_BG_MBIAS			(0x1 << 15)
#define RT5514_POW_BG_MBIAS_BIT			15
#define RT5514_POW_MBIAS			(0x1 << 14)
#define RT5514_POW_MBIAS_BIT			14
#define RT5514_POW_VREF2			(0x1 << 13)
#define RT5514_POW_VREF2_BIT			13
#define RT5514_POW_VREF1			(0x1 << 12)
#define RT5514_POW_VREF1_BIT			12
#define RT5514_POWR_LDO16			(0x1 << 11)
#define RT5514_POWR_LDO16_BIT			11
#define RT5514_POWL_LDO16			(0x1 << 10)
#define RT5514_POWL_LDO16_BIT			10
#define RT5514_POW_ADC2				(0x1 << 9)
#define RT5514_POW_ADC2_BIT			9
#define RT5514_POW_INPUT_BUF			(0x1 << 8)
#define RT5514_POW_INPUT_BUF_BIT		8
#define RT5514_POW_ADC1_R			(0x1 << 7)
#define RT5514_POW_ADC1_R_BIT			7
#define RT5514_POW_ADC1_L			(0x1 << 6)
#define RT5514_POW_ADC1_L_BIT			6
#define RT5514_POW2_BSTR			(0x1 << 5)
#define RT5514_POW2_BSTR_BIT			5
#define RT5514_POW2_BSTL			(0x1 << 4)
#define RT5514_POW2_BSTL_BIT			4
#define RT5514_POW_BSTR				(0x1 << 3)
#define RT5514_POW_BSTR_BIT			3
#define RT5514_POW_BSTL				(0x1 << 2)
#define RT5514_POW_BSTL_BIT			2
#define RT5514_POW_ADCFEDR			(0x1 << 1)
#define RT5514_POW_ADCFEDR_BIT			1
#define RT5514_POW_ADCFEDL			(0x1 << 0)
#define RT5514_POW_ADCFEDL_BIT			0

/* RT5514_I2S_CTRL1 (0x2010) */
#define RT5514_TDM_MODE2			(0x1 << 30)
#define RT5514_TDM_MODE2_SFT			30
#define RT5514_TDM_MODE				(0x1 << 28)
#define RT5514_TDM_MODE_SFT			28
#define RT5514_I2S_LR_MASK			(0x1 << 26)
#define RT5514_I2S_LR_SFT			26
#define RT5514_I2S_LR_NOR			(0x0 << 26)
#define RT5514_I2S_LR_INV			(0x1 << 26)
#define RT5514_I2S_BP_MASK			(0x1 << 25)
#define RT5514_I2S_BP_SFT			25
#define RT5514_I2S_BP_NOR			(0x0 << 25)
#define RT5514_I2S_BP_INV			(0x1 << 25)
#define RT5514_I2S_DF_MASK			(0x7 << 16)
#define RT5514_I2S_DF_SFT			16
#define RT5514_I2S_DF_I2S			(0x0 << 16)
#define RT5514_I2S_DF_LEFT			(0x1 << 16)
#define RT5514_I2S_DF_PCM_A			(0x2 << 16)
#define RT5514_I2S_DF_PCM_B			(0x3 << 16)
#define RT5514_TDMSLOT_SEL_RX_MASK		(0x3 << 10)
#define RT5514_TDMSLOT_SEL_RX_SFT		10
#define RT5514_TDMSLOT_SEL_RX_4CH		(0x1 << 10)
#define RT5514_TDMSLOT_SEL_RX_6CH		(0x2 << 10)
#define RT5514_TDMSLOT_SEL_RX_8CH		(0x3 << 10)
#define RT5514_CH_LEN_RX_MASK			(0x3 << 8)
#define RT5514_CH_LEN_RX_SFT			8
#define RT5514_CH_LEN_RX_16			(0x0 << 8)
#define RT5514_CH_LEN_RX_20			(0x1 << 8)
#define RT5514_CH_LEN_RX_24			(0x2 << 8)
#define RT5514_CH_LEN_RX_32			(0x3 << 8)
#define RT5514_TDMSLOT_SEL_TX_MASK		(0x3 << 6)
#define RT5514_TDMSLOT_SEL_TX_SFT		6
#define RT5514_TDMSLOT_SEL_TX_4CH		(0x1 << 6)
#define RT5514_TDMSLOT_SEL_TX_6CH		(0x2 << 6)
#define RT5514_TDMSLOT_SEL_TX_8CH		(0x3 << 6)
#define RT5514_CH_LEN_TX_MASK			(0x3 << 4)
#define RT5514_CH_LEN_TX_SFT			4
#define RT5514_CH_LEN_TX_16			(0x0 << 4)
#define RT5514_CH_LEN_TX_20			(0x1 << 4)
#define RT5514_CH_LEN_TX_24			(0x2 << 4)
#define RT5514_CH_LEN_TX_32			(0x3 << 4)
#define RT5514_I2S_DL_MASK			(0x3 << 0)
#define RT5514_I2S_DL_SFT			0
#define RT5514_I2S_DL_16			(0x0 << 0)
#define RT5514_I2S_DL_20			(0x1 << 0)
#define RT5514_I2S_DL_24			(0x2 << 0)
#define RT5514_I2S_DL_8				(0x3 << 0)

/* RT5514_DIG_SOURCE_CTRL (0x20a4) */
#define RT5514_AD1_DMIC_INPUT_SEL		(0x1 << 1)
#define RT5514_AD1_DMIC_INPUT_SEL_SFT		1
#define RT5514_AD0_DMIC_INPUT_SEL		(0x1 << 0)
#define RT5514_AD0_DMIC_INPUT_SEL_SFT		0

/* RT5514_PLL_SOURCE_CTRL (0x2100) */
#define RT5514_PLL_1_SEL_MASK			(0x7 << 12)
#define RT5514_PLL_1_SEL_SFT			12
#define RT5514_PLL_1_SEL_SCLK			(0x3 << 12)
#define RT5514_PLL_1_SEL_MCLK			(0x4 << 12)
#define RT5514_PLL_2_SEL_MASK			(0x7 << 8)
#define RT5514_PLL_2_SEL_SFT			8
#define RT5514_PLL_2_SEL_SCLK			(0x3 << 8)
#define RT5514_PLL_2_SEL_MCLK			(0x4 << 8)

/* RT5514_CLK_CTRL1 (0x2104) */
#define RT5514_CLK_AD_ANA1_EN			(0x1 << 31)
#define RT5514_CLK_AD_ANA1_EN_BIT		31
#define RT5514_CLK_AD1_EN			(0x1 << 24)
#define RT5514_CLK_AD1_EN_BIT			24
#define RT5514_CLK_AD0_EN			(0x1 << 23)
#define RT5514_CLK_AD0_EN_BIT			23
#define RT5514_CLK_DMIC_OUT_SEL_MASK		(0x7 << 8)
#define RT5514_CLK_DMIC_OUT_SEL_SFT		8
#define RT5514_CLK_AD_ANA1_SEL_MASK		(0xf << 0)
#define RT5514_CLK_AD_ANA1_SEL_SFT		0

/* RT5514_CLK_CTRL2 (0x2108) */
#define RT5514_CLK_AD1_ASRC_EN			(0x1 << 17)
#define RT5514_CLK_AD1_ASRC_EN_BIT		17
#define RT5514_CLK_AD0_ASRC_EN			(0x1 << 16)
#define RT5514_CLK_AD0_ASRC_EN_BIT		16
#define RT5514_CLK_SYS_DIV_OUT_MASK		(0x7 << 8)
#define RT5514_CLK_SYS_DIV_OUT_SFT		8
#define RT5514_SEL_ADC_OSR_MASK			(0x7 << 4)
#define RT5514_SEL_ADC_OSR_SFT			4
#define RT5514_CLK_SYS_PRE_SEL_MASK		(0x3 << 0)
#define RT5514_CLK_SYS_PRE_SEL_SFT		0
#define RT5514_CLK_SYS_PRE_SEL_MCLK		(0x2 << 0)
#define RT5514_CLK_SYS_PRE_SEL_PLL		(0x3 << 0)

/*  RT5514_DOWNFILTER_CTRL (0x2190 0x2194 0x21a0 0x21a4) */
#define RT5514_AD_DMIC_MIX			(0x1 << 11)
#define RT5514_AD_DMIC_MIX_BIT			11
#define RT5514_AD_AD_MIX			(0x1 << 10)
#define RT5514_AD_AD_MIX_BIT			10
#define RT5514_AD_AD_MUTE			(0x1 << 7)
#define RT5514_AD_AD_MUTE_BIT			7
#define RT5514_AD_GAIN_MASK			(0x3f << 1)
#define RT5514_AD_GAIN_SFT			1

/*  RT5514_ANA_CTRL_MICBST (0x2220) */
#define RT5514_SEL_BSTL_MASK			(0xf << 4)
#define RT5514_SEL_BSTL_SFT			4
#define RT5514_SEL_BSTR_MASK			(0xf << 0)
#define RT5514_SEL_BSTR_SFT			0

/*  RT5514_ANA_CTRL_PLL1_1 (0x2260) */
#define RT5514_PLL_K_MAX			0x1f
#define RT5514_PLL_K_MASK			(RT5514_PLL_K_MAX << 16)
#define RT5514_PLL_K_SFT			16
#define RT5514_PLL_N_MAX			0x1ff
#define RT5514_PLL_N_MASK			(RT5514_PLL_N_MAX << 7)
#define RT5514_PLL_N_SFT			4
#define RT5514_PLL_M_MAX			0xf
#define RT5514_PLL_M_MASK			(RT5514_PLL_M_MAX << 0)
#define RT5514_PLL_M_SFT			0

/*  RT5514_ANA_CTRL_PLL1/2_2 (0x2254 0x2264) */
#define RT5514_PLL_M_BP				(0x1 << 2)
#define RT5514_PLL_M_BP_SFT			2
#define RT5514_PLL_K_BP				(0x1 << 1)
#define RT5514_PLL_K_BP_SFT			1
#define RT5514_EN_LDO_PLL			(0x1 << 0)
#define RT5514_EN_LDO_PLL_BIT			0

#define RT5514_PLL_INP_MAX			40000000
#define RT5514_PLL_INP_MIN			256000

#define RT5514_FIRMWARE1	"rt5514_dsp_fw1.bin"
#define RT5514_FIRMWARE2	"rt5514_dsp_fw2.bin"
#define RT5514_FIRMWARE3	"rt5514_dsp_fw3.bin"
#define RT5514_FIRMWARE4	"rt5514_dsp_fw4.bin"

#define RT5514P_FIRMWARE1	"rt5514p_dsp_fw1.bin"
#define RT5514P_FIRMWARE2	"rt5514p_dsp_fw2.bin"
#define RT5514P_FIRMWARE3	"rt5514p_dsp_fw3.bin"
#define RT5514P_FIRMWARE4	"rt5514p_dsp_fw4.bin"

#define AMBIENT_COMMON_MAX_PAYLOAD_BUFFER_SIZE (128)

/* System Clock Source */
enum {
	RT5514_SCLK_S_MCLK,
	RT5514_SCLK_S_PLL,
};

/* PLL Source */
enum {
	RT5514_PLL_S_MCLK,
	RT5514_PLL_S_BCLK,
};

enum {
	RT5514_DSP_WOV_BOTH,
	RT5514_DSP_WOV_HOTWORD,
	RT5514_DSP_WOV_MUSDET,
	RT5514_DSP_WOV_NON,
};

enum {
	RT5514_DSP_FUNC_WOV,
	RT5514_DSP_FUNC_WOV_SENSOR,
	RT5514_DSP_FUNC_WOV_I2S,
	RT5514_DSP_FUNC_WOV_I2S_SENSOR,
	RT5514_DSP_FUNC_SUSPEND,
	RT5514_DSP_FUNC_I2S,
};

typedef struct _payload_st {
	unsigned int size;
	unsigned int status;
	char data[AMBIENT_COMMON_MAX_PAYLOAD_BUFFER_SIZE];
} RT5514_PAYLOAD;

typedef struct _dsp_fw_ver_st {
	unsigned short chip_id;
	unsigned short feature_id;
	unsigned short version;
	unsigned short sub_version;
} RT5514_DSP_FW_VER;

typedef struct _dsp_mem_st {
	unsigned int iram;
	unsigned int dram;
} RT5514_DSP_MEM;

struct rt5514_priv {
	struct rt5514_platform_data pdata;
	struct snd_soc_codec *codec;
	struct regmap *i2c_regmap, *regmap;
	struct clk *mclk;
	struct gpio_desc *gpiod_reset;
	const struct firmware *fw[4];
	int sysclk;
	int sysclk_src;
	int lrck;
	int bclk;
	int pll_src;
	int pll_in;
	int pll_out;
	int dsp_enabled, dsp_enabled_last, dsp_test;
	int dsp_adc_enabled, dsp_buffer_channel;
	u8 *hotword_model_buf, *musdet_model_buf;
	unsigned int hotword_model_len, musdet_model_len;
	RT5514_PAYLOAD payload;
	bool v_p;
	char *fw_name[4];
	unsigned int fw_addr[4];
	bool is_streaming;
	unsigned int sound_model_addr[2];
};

int rt5514_set_gpio(int gpio, bool output);
void rt5514_watchdog_handler(void);
extern struct regmap *rt5514_g_i2c_regmap;

#endif /* __RT5514_H__ */
