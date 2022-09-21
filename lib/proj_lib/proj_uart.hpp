/**
  ******************************************************************************
  * @file	  : proj_uart.hpp
  * @brief	: Uart Driver
  * @author	: Muhammed Emin CELIK
  * @date	  : 14.09.2022
  * @version: 0.1.0
 *******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 COMPANY A.S.,
  * All Rights Reserved </center></h2>
  *
  * All  information  contained  herein is,  and  remains  the property of
  * COMPANY A.S.  The intellectual and technical concepts contained herein
  * are proprietary  to  COMPANY A.S.  and are protected  by  trade secret
  * or copyright law.  Dissemination of this  information or  reproduction
  * of this material is strictly forbidden unless prior written permission
  * is obtained from   COMPANY A.S.    Access to the source code contained
  * herein is  hereby forbidden  to  anyone  except current   COMPANY A.S.
  * employees, managers or contractors  who have executed  Confidentiality
  * and Non-disclosure agreements explicitly covering such access.
  *
 *******************************************************************************
  */

#ifndef PROJ_UART_HPP
#define PROJ_UART_HPP


#include <HardwareSerial.h>



namespace Project
{


/**
  * @brief PROJ Class
  */
class PROJECT
{
	public:
		PROJECT(HardwareSerial *uart_handle);

    void initialize(void);
    void scheduler(void);
    void writeToBuffer(uint8_t buffer[], uint16_t size);
    uint16_t readFromBuffer(uint8_t buffer[], uint16_t size_limit);

		PROJECT(const PROJECT& orig);
		virtual ~PROJECT();

	protected:

	private:
    HardwareSerial *uart;

};



} /* namespace Project */

extern Project::PROJECT project;

#endif /* PROJ_UART_HPP */

/********************************* END OF FILE *********************************/