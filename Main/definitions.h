#ifndef definitions_h
#define definitions_h

#define DISPLAY_WAREHOUSE_SIDE 17
#define WAREHOUSE_CELLS_X 3
#define WAREHOUSE_CELLS_Y 3

#define H_BRIDGE1_PH1_PIN 46
#define H_BRIDGE1_PH2_PIN 48
#define H_BRIDGE1_PH3_PIN 44
#define H_BRIDGE1_PH4_PIN 42

#define H_BRIDGE2_PH1_PIN 11
#define H_BRIDGE2_PH2_PIN 12
#define H_BRIDGE2_PH3_PIN 10
#define H_BRIDGE2_PH4_PIN 9

#define NUMBER_PAD_A_PIN 2
#define NUMBER_PAD_B_PIN 3
#define NUMBER_PAD_C_PIN 4
#define NUMBER_PAD_D_PIN 5
#define NUMBER_PAD_E_PIN 6
#define NUMBER_PAD_F_PIN 7
#define NUMBER_PAD_G_PIN 8

#define AVANT 11
#define ARROW 10

#define ACTUATOR_POS_PIN 43
#define ACTUATOR_NEG_PIN 45

#define FC1_PIN A12
#define FC2_PIN A13
#define FC3_PIN A14
#define FC4_PIN A15

#define UP 0
#define DOWN 1 
#define RIGHT 3
#define LEFT 2 
#define ACTUATOR_FOWARD 4
#define ACTUATOR_BACKWARD 5
#define PALLET_UP_DOWN 6
#define MENU 10

#define LOAD 0
#define UNLOAD 1

#define MANUAL 0
#define AUTOMATIC 1
#define INITIALIZATION 2
#define RESET 1
#define DEBUG 2
#define MEASURES 3
#define SIMULATION 1

//distances in steps
#define DISTANCE_2to3_COLUMN 1350
#define DISTANCE_1to2_COLUMN 1350
#define DISTANCE_0to1_COLUMN 1400
#define DISTANCE_0to1_ROW 4700
#define DISTANCE_1to2_ROW 4700
#define PALLET_VERTICAL_DISTANCE 600

//distance in mm
#define DISTANCE_TO_WAREHOUSE 200

#define PRINT_MODALITY 0
#define PRINT_RESET 1
#define PRINT_ROW 2
#define PRINT_COLUMN 3
#define PRINT_PALLET 4
#define PRINT_DEPOSITO 5
#define PRINT_PRELIEVO 6
#define PRINT_DEBUG 7
#define PRINT_BEGIN 8
#define PRINT_START 9
#define PRINT_MEASURES 10
#define PRINT_OPTIMIZATION 11
#define PRINT_SIMULATION 12

#define TIME_ACTUATOR 12000

#endif
