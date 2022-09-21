/**
  ******************************************************************************
  * @file 	: proj_uart.cpp
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

#include "proj_uart.hpp"



/**
  * @brief	Class object
  */
Project::PROJECT project(&Serial);



namespace Project
{



/**
  * @brief 		Default constructor
  * @param[in]  void
  * @return 	void
  */
PROJECT::PROJECT(HardwareSerial *uart_handle):
uart(uart_handle)
{ }



/**
  * @brief 		Initialize function, runs only once
  * @param[in]  void
  * @return 	void
  */
void PROJECT::initialize(void)
{ 
  uart->begin(9600);
}



/**
  * @brief 		Scheduler function, runs periodically
  * @param[in]  void
  * @return 	void
  */
void PROJECT::scheduler(void)
{ 
  uint8_t buf[9] = {0};

  int len = readFromBuffer(buf, sizeof(buf));

  if(len > 0)
  {
    writeToBuffer(buf, sizeof(buf));
  }
}



/**
  * @brief 		Write data to UART Buffer
  * @param[in]  uint8_t buffer[] : Data buffer
  * @param[in]  uint16_t size : Size of the buffer
  * @return 	void
  */
void PROJECT::writeToBuffer(uint8_t buffer[], uint16_t size)
{
	uart->write(buffer, size);
}



/**
  * @brief 		Read data from Uart Buffer
  * @param[out] uint8_t buffer[] : Data buffer
  * @param[in]  uint16_t size_limit : Size limit of the buffer
  * @return 	uint8_t : Size of the buffer
  */
uint16_t PROJECT::readFromBuffer(uint8_t buffer[], uint16_t size_limit)
{
	uint16_t result = 0;

	result = uart->readBytes(buffer, size_limit);

	return result;
}



/**
  * @brief 		Default copy constructor
  * @param[in]  void
  * @return 	void
  */
PROJECT::PROJECT(const PROJECT& orig)
{ }



/**
  * @brief 		Default destructor
  * @param[in]  void
  * @return 	void
  */
PROJECT::~PROJECT()
{ }



} /* namespace Project */


/********************************* END OF FILE *********************************/