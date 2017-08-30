/**
 * \file   
 * \author Philipp Johannes	
 * \date   Juni 2017
 * \brief  Dateitypen für die Kommunikation
 */

#ifndef DATA_H
#define DATA_H

//GRILLSTATUS
#define DOORCLOSED 		0x8000
#define POWERSUPPLY 	0x4000
#define	POWERACCU 		0x2000
#define MOTORSTOCK 		0x1000
#define FANRIGHT_ERROR	0x0800
#define FANLEFT_ERROR 	0x0400
#define	RPI_ERROR 		0x0200
#define AUTOMATIC_ON 	0x0100
#define BLUETOOTH_CTR	0x0080
#define ACCUSTATE 		0x000F

//WLANSTATUS
#define LOGIN_ERROR		0x80
#define NO_NETWORK	 	0x40

#define AUTH_ERROR		0x01
#define NO_SERVER		0x02

typedef struct{
	char wlanSSID[33];
	uint8_t keyMgmt;  	
	char wlanPWD[64]; 
}WLAN;

typedef struct {
	uint8_t fanLeft;
	uint8_t fanRight;
	uint8_t heightActual;
	uint8_t heightTarget;
}MECHANIC;

typedef struct {
	uint16_t tempSensor1;
	uint16_t tempSensor2;
	uint16_t tempSensor3;
	uint16_t tempSensor4;
	uint16_t tempSensorTop;
}SENSOR;

/*typedef union 
{
	struct{
		uint8_t door_open:1;    	//0
		uint8_t power_supply:1;		//1
		uint8_t accu:1;				//2
		uint8_t free1:1;			//3
		uint8_t motor_error:1;		//4
		uint8_t motor_stck:1;		//5
		uint8_t fan_r_error:1;		//6
		uint8_t fan_l_error:1;		//7
		uint8_t rpi_error:1;		//8
		uint8_t automation:1;		//9
		uint8_t bt_ctr:1;			//10
		uint8_t free6:1;			//11
		uint8_t free7:1;			//12
		uint8_t accu_state:3;		//13,14,15
	}bit_state;
	uint16_t state;
}GRILLSTATE;*/

typedef union 
{
	struct{
		uint8_t door_open:1;    	//0
		uint8_t power_supply:1;		//1
		uint8_t accu:1;				//2
		uint8_t motor_stck:1;		//3
		uint8_t fan_r_error:1;		//4
		uint8_t fan_l_error:1;		//5
		uint8_t sys_error:1;		//6
		uint8_t automation:1;		//7
		uint8_t bt_ctr:1;			//8
		uint8_t access_token:1;		//9
		uint8_t free5:1;			//10
		uint8_t free6:1;			//11
		uint8_t free7:1;			//12
		uint8_t accu_state:3;		//13,14,15
	}bit_state;
	uint16_t state;
}GRILLSTATE;

typedef union 
{
	struct{
		uint8_t login_error:1;    	//0
		uint8_t no_network:1;		//1
		uint8_t admin_connection:1;	//2
		uint8_t wlan_config:1;		//3
		uint8_t com_error:4;		//4-7
	}bit_state;
	uint8_t state;
}WLANSTATE;

typedef union
{
	struct{
		uint8_t ip3;
		uint8_t ip2;
		uint8_t ip1;
		uint8_t ip0;
	}ip_segment;
	uint32_t ip_full;
}WLAN_IP;

typedef union
{
	struct{
		uint8_t BT_down:1;
		uint8_t BT_up:1;
		uint8_t wlan_timeout:1;
	}bit_state;
	uint16_t state;
}INTERNAL;

typedef struct {
	WLANSTATE 	wlanStatus;
	uint8_t		automatic;
	GRILLSTATE	grillStatus;
	MECHANIC 	control;
	SENSOR 		temperature;
	SENSOR 		limit;
	WLAN_IP		ip;
	uint32_t	user_id;
	INTERNAL	intern;
}FRAME;

#endif