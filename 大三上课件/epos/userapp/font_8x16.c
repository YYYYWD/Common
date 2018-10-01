#include"font_8x16.h"

void lcd_put_ascii(int x, int y, unsigned char c, COLORREF cr)
{
	unsigned char *dots = (unsigned char *)&fontdata_8x16[c * 16];
	//´Ófontdata_8x16[FONTDATAMAX]Êý×éÖÐ»ñµÃµãÕóÆðÊ¼Î»ÖÃ
	int i, b;
	unsigned char byte;

	for (i = 0; i < 16; i++)//µãÕóÓÐ16ÐÐ
	{
		byte = dots[i];
		for (b = 7; b >= 0; b--)//µãÕóÓÐ8ÁÐ
		{
			if (byte & (1 << b))//ÅÐ¶ÏµãÕóÖÐµÄ¸÷¸öµãÊÇ·ñÎª1
			{
				/* show */
				setPixel(x + 7 - b, y + i, cr); /* °× */
			}
			else
			{
				/* hide */
				setPixel(x + 7 - b, y + i, RGB(0, 0, 0)); /* ºÚ */
			}
		}
	}
}
