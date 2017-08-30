/**
 * \file   
 * \author Philipp Johannes 
 * \date   Februar 2017
 * \brief Headerfile Kommandos
 */

enum UART_STATE{
  UART_BEG = 1,
  UART_CMD,
  UART_DATA_IN,
  UART_END
};

enum UART_ERR{
ERROR_BEGINNING = 0x10,              
ERROR_CMD       = 0x11,    
ERROR_SEP       = 0x12,  
ERROR_END       = 0x13
};

enum BT_CMD{
  BT_TEMP_SENSOR_1     = 0x30,
  BT_TEMP_SENSOR_2     = 0x31,
  BT_TEMP_SENSOR_3     = 0x32,
  BT_TEMP_SENSOR_4     = 0x33,
  BT_TEMP_SENSOR_TOP   = 0x34,
  BT_WRITE_HEIGHT      = 0x40,
  BT_WRITE_AUTO        = 0x41,
  BT_WRITE_FANR        = 0x42,
  BT_WRITE_FANL        = 0x43,
  BT_WRITE_SSID        = 0x50,
  BT_WRITE_PWD         = 0x51,
  BT_WRITE_KEY_MGMT    = 0x52,
  BT_NEW_DATA          = 0x87,
  BT_GET_FRAME         = 0x88,
  BT_USER_DISCONNECT   = 0x89,
  BT_DEVICE_CONNECT    = 0x90,
  BT_DEVICE_DISCONNECT = 0x91,
  BT_USER_ID           = 0x92,
  BT_SHUTDOWN          = 0x93,
  BT_STARTUP           = 0x94
};

enum CMD_RPI{
  READ_SENSOR_DATA  = 0x20,
  READ_SHUTDOWN     = 0x21,
  READ_BT_DOWN      = 0x22,
  READ_BT_UP        = 0x23,
  WRITE_SHUTDOWN    = 0x25,
  WRITE_HEARTBEAT	  = 0x26
};

enum SYMBOL_POS
{
  BEG_POS = 0,
  CMD_POS = 1,
  END_POS = 1
};

#define SYMBOL_BEGIN 0x7B
#define SYMBOL_SEP   0xDE
#define SYMBOL_END   0x7D