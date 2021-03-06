#ifndef DS3231_h
#define DS3231_h

#include <Arduino.h>
#include <Wire.h>

class DS3231 {
	
	private :
		
		bool detected;

    uint8_t decToBcd(uint8_t val);
    uint8_t bcdToDec(uint8_t val);
	
	public :
		
		const uint8_t I2C_ADRESS=0x68;
	
		DS3231();
	
  	inline bool isDetected(){return detected;}
	
		uint8_t getSecond();
		uint8_t getMinute();
		uint8_t getHour(bool *mode12h, bool *pm);
		int getCurrentTime(bool *mode12h, bool *pm, uint8_t *hour, uint8_t *minute, uint8_t *second);
	
		bool setSecond(const uint8_t second);
		bool setMinute(const uint8_t minute);
		bool setHour(const uint8_t hour, const bool mode12h, const bool pm);
	
		uint8_t getDayOfWeek();
		uint8_t getDayOfMonth();
		uint8_t getMonth();
		uint8_t getYear();
		int getDate(uint8_t *dayOfWeek, uint8_t *dayOfMonth, uint8_t *month, uint8_t *year);
		
		bool setDayOfMonth(const uint8_t dayOfMonth);
		bool setMonth(const uint8_t month);
		bool setYear(const uint8_t year);
};

#endif
