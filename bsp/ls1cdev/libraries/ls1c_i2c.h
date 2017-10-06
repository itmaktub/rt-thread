/*
 * File      : ls1c_i2c.h
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2006 - 2012, RT-Thread Development Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2017-09-06     ��Ϊ��       first version
 */


// Ӳ��i2c�ӿڵ�ͷ�ļ�

#ifndef __OPENLOONGSON_I2C_H
#define __OPENLOONGSON_I2C_H



// I2C��ʱ��Ƶ��
#define LS1C_I2C_CLOCK_DEFAULT              (100000)  // Hz. Ĭ��Ƶ��
#define LS1C_I2C_CLOCK_MAX                  (400000)  // Hz, max 400 Kbits/sec


// I2Cģ����
typedef enum
{
    LS1C_I2C_0 = 0,
    LS1C_I2C_1,
    LS1C_I2C_2
}ls1c_i2c_t;


// I2C���ݴ��䷽��
typedef enum
{
    LS1C_I2C_DIRECTION_WRITE = 0,       // ������ӻ�д��Ϣ
    LS1C_I2C_DIRECTION_READ,            // ������ӻ�����Ϣ
}ls1c_i2c_direction_t;


// Ӳ��I2C��Ϣ
typedef struct
{
    ls1c_i2c_t I2Cx;                    // i2cģ����
    unsigned long clock;                // i2cʱ��Ƶ�ʣ���λhz
}ls1c_i2c_info_t;


// I2CӦ��
typedef enum
{
    LS1C_I2C_ACK = 0,                   // �յ�Ӧ��
    LS1C_I2C_NACK = 1,                  // û�յ�Ӧ��
}ls1c_i2c_ack_t;


// ��������ֵ
typedef enum
{
    LS1C_I2C_RET_OK = 0,                // OK
    LS1C_I2C_RET_TIMEOUT,               // ��ʱ
}ls1c_i2c_ret_t;



/*
 * ��ʼ��ָ��i2cģ��
 * @i2c_info_p ĳ��i2cģ�����Ϣ
 */
void i2c_init(ls1c_i2c_info_t *i2c_info_p);


/*
 * (�ٷ���һ���ֽ�����֮��)���մӻ����͵�ACK�ź�
 * @i2c_info_p i2cģ����Ϣ
 * @ret LS1C_I2C_ACK or LS1C_I2C_NACK
 */
ls1c_i2c_ack_t i2c_receive_ack(ls1c_i2c_info_t *i2c_info_p);


/*
 * ��������
 * @i2c_info_p i2cģ����Ϣ
 * @buf ���ݻ���
 * @len ���������ݵĳ���
 */
ls1c_i2c_ret_t i2c_receive_data(ls1c_i2c_info_t *i2c_info_p, unsigned char *buf, int len);



/*
 * ����START�źź͵�ַ
 * @i2c_info_p i2cģ����Ϣ
 * @slave_addr �ӻ���ַ
 * @direction ���ݴ��䷽��(����д)
 */
ls1c_i2c_ret_t i2c_send_start_and_addr(ls1c_i2c_info_t *i2c_info_p, 
                                       unsigned char slave_addr,
                                       ls1c_i2c_direction_t direction);


/*
 * ��������
 * @i2c_info_p i2cģ����Ϣ
 * @data �����͵�����
 * @len ���������ݵĳ���
 */
ls1c_i2c_ret_t i2c_send_data(ls1c_i2c_info_t *i2c_info_p, unsigned char *data, int len);


/*
 * ����STOP�ź�
 * @i2c_info_p i2cģ����Ϣ
 */
void i2c_send_stop(ls1c_i2c_info_t *i2c_info_p);



#endif
