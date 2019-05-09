#ifndef definitions_h
#define definitions_h

#define DISPLAY_WAREHOUSE_SIDE 17
#define WAREHOUSE_CELLS_X 3
#define WAREHOUSE_CELLS_Y 3

#define H_BRIDGE1_PH1_PIN 12
#define H_BRIDGE1_PH2_PIN 11
#define H_BRIDGE1_PH3_PIN 9
#define H_BRIDGE1_PH4_PIN 10

#define H_BRIDGE2_PH1_PIN 42
#define H_BRIDGE2_PH2_PIN 44
#define H_BRIDGE2_PH3_PIN 46
#define H_BRIDGE2_PH4_PIN 48

#define NUMBER_PAD_A_PIN 2
#define NUMBER_PAD_B_PIN 3
#define NUMBER_PAD_C_PIN 4
#define NUMBER_PAD_D_PIN 5
#define NUMBER_PAD_E_PIN 6
#define NUMBER_PAD_F_PIN 7
#define NUMBER_PAD_G_PIN 8

#define AVANT 11
#define ARROW 10

#define ACTUATOR_POS_PIN 38
#define ACTUATOR_NEG_PIN 40

#define FC1_PIN A12
#define FC2_PIN A13
#define FC3_PIN A14
#define FC4_PIN A15

#define UP 0
#define DOWN 1
#define RIGHT 2
#define LEFT 3

#define LOAD 0
#define UNLOAD 1

#define MANUAL 0
#define AUTOMATIC 1
#define INITIALIZATION 2

#define DISTANCE_0to1_COLUMN 950
#define DISTANCE_1to2_COLUMN 950
#define DISTANCE_2to3_COLUMN 950
#define DISTANCE_0to1_ROW 4900
#define DISTANCE_1to2_ROW 4900
#define PALLET_VERTICAL_DISTANCE 500


struct pallet {
  int row;
  int column;
}pallets[]{
  {3, 3}, //pallet N°1
  {3, 3}, //pallet N°2
  {3, 3}, //pallet N°3
  {3, 3}, //pallet N°4
  {3, 3}, //pallet N°5
  {3, 3}, //pallet N°6
  {3, 3}, //pallet N°7
  {3, 3}, //pallet N°8
  {3, 3}, //pallet N°9
};


byte loadCell[2]={0, 3};
byte unloadCell[2]={1, 3};

#define PRINT_MODALITY 0
#define PRINT_RESET 1
#define PRINT_ROW 2
#define PRINT_COLUMN 3

#endif
