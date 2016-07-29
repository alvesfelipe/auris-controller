#include "sendsignalbeagle.h"

//Empty constructor
SendSignalBeagle::SendSignalBeagle(){}

void SendSignalBeagle::setGpioPins(){

	//GPIO = {30, 60, 31, 40, 48, 51, 04, 05, 03, 02, 49, 15}
	//Pins = {11, 12, 13, 14, 15, 16, 17, 18, 21, 22, 23, 24}
	this->gpioPins.push_back(30); 
	this->gpioPins.push_back(60);
	this->gpioPins.push_back(31);
	this->gpioPins.push_back(04);//problem with pin 14(troquei 40 pelo 05)
	this->gpioPins.push_back(48);
	this->gpioPins.push_back(51);
	this->gpioPins.push_back(04);
	this->gpioPins.push_back(05);
	this->gpioPins.push_back(03);
	this->gpioPins.push_back(02);
	this->gpioPins.push_back(49);
	this->gpioPins.push_back(15);
}

int SendSignalBeagle::getGpioPin(int pos){

	return this->gpioPins[pos];
}

void SendSignalBeagle::setPinOn(int gpioPin, int timeBound){

	sprintf(this->gpioPinHigh, "high");
	char auxDirection[50];

	//set pin to export
	sprintf(this->gpioPinDirection , "%d", gpioPin);
	do{
		this->outPinFile = fopen("/sys/class/gpio/export", "w");
	}while(this->outPinFile == NULL);
	fwrite(this->gpioPinDirection, 1, sizeof(this->gpioPinDirection), this->outPinFile);
	fclose (this->outPinFile);

	//write pin high
	sprintf(auxDirection, "/sys/class/gpio/gpio%d/direction", gpioPin);
	do{
		this->pinDirection = fopen (auxDirection, "w");
	}while(this->pinDirection == NULL);
	fwrite(this->gpioPinHigh, 1, sizeof(this->gpioPinHigh), this->pinDirection);
	fclose(this->pinDirection);
	usleep(timeBound * 1000);	
}

void SendSignalBeagle::setPinOff(int gpioPin){

	sprintf(this->gpioPinLow, "low");
	char auxDirection[50];

	//set pin to export
	sprintf(this->gpioPinDirection , "%d", gpioPin);
	do{
		this->outPinFile = fopen("/sys/class/gpio/export", "w");
	}while(this->outPinFile == NULL);
	fwrite(this->gpioPinDirection, 1, sizeof(this->gpioPinDirection), this->outPinFile);
	fclose (this->outPinFile);

	//write pin low
	sprintf(auxDirection, "/sys/class/gpio/gpio%d/direction", gpioPin);
	do{
		this->pinDirection = fopen (auxDirection, "w");
	}while(this->pinDirection == NULL);
	fwrite(this->gpioPinLow, 1, sizeof(this->gpioPinLow), this->pinDirection);
	fclose(this->pinDirection);

	//remove pin of export
	do{
		this->outPinFile = fopen("/sys/class/gpio/unexport", "w");
	}while(this->outPinFile == NULL);	
	fwrite(this->gpioPinDirection, 1, sizeof(this->gpioPinDirection), this->outPinFile);
	fclose(this->outPinFile);
}

//Set all pins off
void SendSignalBeagle::setAllPinsOff(){
	this->setGpioPins();
	for(int i=0; i < this->gpioPins.size(); i++){
		this->setPinOff(this->gpioPins[i]);
	}
}

//Destructor
SendSignalBeagle::~SendSignalBeagle(){}
