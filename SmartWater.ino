// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       SmartWater.ino
    Created:	6/2/2019 9:24:51 PM
    Author:     DESKTOP-GM8VG8R\RyanC
*/

// Define User Types below here or use a .h file
//
class WaterSensor {	
	private:
		int pinNum = NULL;
	private:
		int lastReading = 0;
	private:
		int threshold = 0;
	private:
		bool thirsty = false;
	public:
		WaterSensor(int, int); 
	public:
		int read() { 
			lastReading = analogRead(pinNum);

			return lastReading ;
		};
	public: 
		bool isThirsty() {
		if (read() < threshold) {
			thirsty = false;
		}
		else {
			thirsty = true;
		}
		return thirsty;
	}
};

WaterSensor::
	WaterSensor(int pin, int thres) {
	pinNum = pin;
	threshold = thres;
}

class TempSensor {
private:
	int pinNum = NULL;
private:
	float lastReading = 0.00;
private:
	float temp = 0.00;
private:
	bool hot = false;
private:
	bool cold = false;
private:
	bool normal = false;
private: 
	bool isFarenhite = false;
private:
	float hotThreshold = 0.00;
private:
	float coldThreshold = 0.00;
public:
	TempSensor(int, int, int, bool);
public:
	float read() {
		lastReading = analogRead(pinNum);
		temp = lastReading;
	};
public:
	bool isTooCold() {
		float th = coldThreshold;
		if (isFarenhite) {
			th = convert(th);
		}
		if (getRawTemp() < th) {
			cold = true;
		}
		else {
			cold = false;
		}
		return cold;
	}
public:
	bool isTooHot() {
		float th = hotThreshold;
		if (isFarenhite) {
			th = convert(th);
		}
		if (getRawTemp() < th) {
			hot = false;
		}
		else {
			hot = true;
		}
		return hot;
	}
public:
	bool isNormal() {
		if (!isTooCold() || !isTooHot()) {
			normal = true;
		}
		else {
			normal = false;
		}
		return normal;
	}
public:
	float getRawTemp() {
		 temp = read();
		 float tmp = temp;
		if (isFarenhite) {
			tmp = convert(temp);
		}
		return tmp;
	};
public:
	String getFormatedTemp(unsigned decimals = 2) {
		return String(getRawTemp(), decimals);
	};
private:
	float convert(float cel) {
		return float((cel * (9 / 5)) + 32);
	};
};

TempSensor::
TempSensor(int pin, int coldThres, int hotThres, bool feren = false) {
	pinNum = pin;
    isFarenhite = feren;
	coldThreshold = coldThres;
	hotThreshold = hotThres;
	read();
}

//Constents
const int THRESH = 500;
const int WATER_PIN1 = PIN0;
const int WATER_PIN2 = PIN1;
const int TEMP_PIN = PIN2;
const float COLD_T = 40;
const float HOT_T = 95;

//Objects
WaterSensor ws1 = WaterSensor(WATER_PIN1, THRESH);
WaterSensor ws2 = WaterSensor(WATER_PIN2, THRESH);
TempSensor ts1 = TempSensor(TEMP_PIN, COLD_T, HOT_T, true);

// The setup() function runs once each time the micro-controller starts
void setup()
{


}

// Add the main program code into the continuous loop() function
void loop()
{


}
