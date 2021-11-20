/* Arduino SdSpi Library
 * Copyright (C) 2013 by William Greiman
 *
 * This file is part of the Arduino SdSpi Library
 *
 * This Library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This Library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the Arduino SdSpi Library.  If not, see
 * <http://www.gnu.org/licenses/>.
 */
 /**
 * \file
 * \brief SdSpi class for V2 SD/SDHC cards
 */
#ifndef ILI_SdSpi_h
#define ILI_SdSpi_h

#include "ILI_SdFatConfig.h"

#if !ILI_USE_ARDUINO_SPI_LIBRARY
// AVR Arduinos
#ifdef __AVR__
#if ILI_AVR_SOFT_SPI
#define ILI_USE_SOFTWARE_SPI 1
#elif ILI_LEONARDO_SOFT_SPI && defined(__AVR_ATmega32U4__) && !defined(CORE_TEENSY)
#define ILI_USE_SOFTWARE_SPI 1
#elif ILI_MEGA_SOFT_SPI && (defined(__AVR_ATmega1280__)\
      ||defined(__AVR_ATmega2560__))
#define ILI_USE_SOFTWARE_SPI 1
#else  // ILI_USE_SOFTWARE_SPI
#define ILI_USE_NATIVE_AVR_SPI 1
#endif  // ILI_USE_SOFTWARE_SPI
#endif  // __AVR__
// Due
#if defined(__arm__) && !defined(CORE_TEENSY)
#if ILI_DUE_SOFT_SPI
#define ILI_USE_SOFTWARE_SPI 1
#else  // ILI_DUE_SOFT_SPI
/** Nonzero - use native SAM3X SPI */
#define ILI_USE_NATIVE_SAM3X_SPI 1
#endif  // ILI_DUE_SOFT_SPI
#endif  // defined(__arm__) && !defined(CORE_TEENSY)
// Teensy 3.0
#if defined(__arm__) && defined(CORE_TEENSY)
#if ILI_TEENSY3_SOFT_SPI
#define ILI_USE_SOFTWARE_SPI 1
#else  // ILI_TEENSY3_SOFT_SPI
/** Nonzero - use native MK20DX128 SPI */
#define ILI_USE_NATIVE_TEENSY3_SPI 1
#endif  // ILI_TEENSY3_SOFT_SPI
#endif  // defined(__arm__) && defined(CORE_TEENSY)
#endif  // !ILI_USE_ARDUINO_SPI_LIBRARY

#ifndef ILI_USE_SOFTWARE_SPI
#define ILI_USE_SOFTWARE_SPI 0
#endif  //  ILI_USE_SOFTWARE_SPI

#ifndef ILI_USE_NATIVE_AVR_SPI
#define ILI_USE_NATIVE_AVR_SPI 0
#endif

#ifndef ILI_USE_NATIVE_SAM3X_SPI
#define ILI_USE_NATIVE_SAM3X_SPI 0
#endif  // ILI_USE_NATIVE_SAM3X_SPI

#ifndef ILI_USE_NATIVE_TEENSY3_SPI
#define ILI_USE_NATIVE_TEENSY3_SPI 0
#endif  // ILI_USE_NATIVE_TEENSY3_SPI

//------------------------------------------------------------------------------
/**
 * \class SdSpi
 * \brief SPI class for access to SD and SDHC flash memory cards.
 */
class ILI_SdSpi {
 public:
  /** Initialize the SPI bus */
  void begin();
  /** Set SPI options for access to SD/SDHC cards.
   * 
   * \param[in] spiDivisor SCK clock divider relative to the system clock.
   */
  void init(uint8_t spiDivisor);
  /** Receive a byte. 
   *
   * \return The byte.
   */
  uint8_t read();
  /** Receive multiple bytes.
   *
   * \param[out] buf Buffer to receive the data.   
   * \param[in] n Number of bytes to receive.
   *
   * \return Zero for no error or nonzero error code.
   */   
  uint8_t read(uint8_t* buf, size_t n);
  /** Send a byte.
   *
   * \param[in] data Byte to send
   */
  void write(uint8_t data, U8 cspin = 0);
   /** Send multiple bytes.
   *
   * \param[in] buf Buffer for data to be sent.   
   * \param[in] n Number of bytes to send.
   */   
  void write(const uint8_t* buf, size_t n, U8 cspin = 0);
};



extern ILI_SdSpi SPI;
#endif  // ILI_SdSpi_h

