#ifndef Configuration_h_
#define Configuration_h_

/***************************
 *	Configuration.h
 *
 *	This file constains all the default and initial values
 *	necessary for the configuarion of the extruder.
 *
****************************/


/***************************
 *	Pins
****************************/

#define MOTOR_PWM_PIN 4 	//Pin that outputs the PWM control signal (white)
#define MOTOR_LOW_PIN 5 	//Pin that allways is LOW (grey)
#define MOTOR_SF_PIN 6 		//Motor driver status flag (green)

#define MOTOR_ENCODER_1_PIN 3 	//white cable
#define MOTOR_ENCODER_2_PIN 2 	//brown cable

//PWM pins for the heaters
#define HEATER_1_PWM_PIN 11
#define HEATER_2_PWM_PIN 10
#define HEATER_3_PWM_PIN 9
#define HEATER_4_PWM_PIN 12345
#define HEATER_5_PWM_PIN 12345


//Put PWM pins in an array for the constructor to have easy sequential access to them
//Index correspond to heater number (from 1 to 5; 0 is empty)
const char HEATER_PWM_PIN[6] = {0, HEATER_1_PWM_PIN, HEATER_2_PWM_PIN, HEATER_3_PWM_PIN, HEATER_4_PWM_PIN, HEATER_5_PWM_PIN};

//Analog pins for the thermistors
#define HEATER_1_THERMISTOR_PIN 2
#define HEATER_2_THERMISTOR_PIN 1
#define HEATER_3_THERMISTOR_PIN 0
#define HEATER_4_THERMISTOR_PIN 12345
#define HEATER_5_THERMISTOR_PIN 12345

//Put all thermistor pins in an array for the constructor to have easy sequential access to them
//Index correspond to heater number (from 1 to 5; 0 is empty)
const char HEATER_THERMISTOR_PIN[6] = {0, HEATER_1_THERMISTOR_PIN, HEATER_2_THERMISTOR_PIN, HEATER_3_THERMISTOR_PIN, HEATER_4_THERMISTOR_PIN, HEATER_5_THERMISTOR_PIN};


#define PULLER_PIN 12

#define FAN_PIN 12345


/***************************
 *	Drive configuration
****************************/

#define MOTOR_ENCODER_STEPS_PER_REVOLUTION 1200


/***************************
 *	Heater configuration
****************************/

#define NUMBER_OF_HEATERS 3	//library supports by default up to 5 heaters

//Constants used to prevent cold extrusion
#define MELTING_HEATERS 1 				//Number of heaters, starting from (and including) heater 1, in which plastic is in molten state.
#define MELTING_TEMPERATURE 150 		//If the melting heaters are below this temperature, the motor can't be turned on (0 to desactivate feature)

//Maximum and minimun heater temperatures
#define HEATER_MAX_TEMPERATURE 300 	//Celsius
#define HEATER_MIN_TEMPERATURE 0 	//Celsius

//Heater initial temperature setpoints
//Numbering criteria: heater 1 is the one nearest the die, heater 5 is the farthest.
#define HEATER_1_SETPOINT 225
#define HEATER_2_SETPOINT 180
#define HEATER_3_SETPOINT 50
#define HEATER_4_SETPOINT 0 
#define HEATER_5_SETPOINT 0

//Put all the setpoints in an array for the constructor to have easy sequential access to them
//Index correspond to heater number (from 1 to 5; 0 is empty)
const double HEATER_SETPOINT[6] = {0, HEATER_1_SETPOINT, HEATER_2_SETPOINT, HEATER_3_SETPOINT, HEATER_4_SETPOINT, HEATER_5_SETPOINT};

//Heater default PID parameters

#define HEATER_1_K_P 2.0
#define HEATER_1_K_I 5.0
#define HEATER_1_K_D 0

#define HEATER_2_K_P 2.0
#define HEATER_2_K_I 5.0
#define HEATER_2_K_D 0

#define HEATER_3_K_P 2.0
#define HEATER_3_K_I 5.0
#define HEATER_3_K_D 0

#define HEATER_4_K_P 2.0
#define HEATER_4_K_I 5.0
#define HEATER_4_K_D 0

#define HEATER_5_K_P 2.0
#define HEATER_5_K_I 5.0
#define HEATER_5_K_D 0

//Put all PID constants in an array for the constructor to have easy sequential access to them
//Index correspond to heater number (from 1 to 5; 0 is empty)
const double HEATER_K_P[6] = {0, HEATER_1_K_P, HEATER_2_K_P, HEATER_3_K_P, HEATER_4_K_P, HEATER_5_K_P};
const double HEATER_K_I[6] = {0, HEATER_1_K_I, HEATER_2_K_I, HEATER_3_K_I, HEATER_4_K_I, HEATER_5_K_I};
const double HEATER_K_D[6] = {0, HEATER_1_K_D, HEATER_2_K_D, HEATER_3_K_D, HEATER_4_K_D, HEATER_5_K_D};

// Thermistor Look Up Table
// Table generated using custom iPython Notebook that can be found at https://github.com/diegotrap/filament_extruder/blob/master/ipython_notebooks/NTC%20Thermistor.ipynb
// Using AVR PROGMEM macro to store the table in the flash memory
// Using double to make them compatible with the PID library. In Arduino, double has the same byte size as float, so it does't imply increased memory usage.
const double thermistor_lut[] = { 0.00, 2566.98, 1643.64, 1337.12, 1172.89, 1066.79, 990.93, 933.14, 887.14, 849.35, 817.54, 790.25, 766.48, 745.52, 726.83, 710.02, 694.78, 680.88, 668.13, 656.36, 645.45, 635.30, 625.82, 616.93, 608.58, 600.71, 593.27, 586.22, 579.53, 573.17, 567.11, 561.32, 555.78, 550.48, 545.40, 540.52, 535.83, 531.31, 526.96, 522.76, 518.70, 514.78, 510.99, 507.32, 503.77, 500.32, 496.97, 493.72, 490.56, 487.49, 484.50, 481.59, 478.76, 476.00, 473.30, 470.67, 468.11, 465.60, 463.15, 460.76, 458.42, 456.13, 453.89, 451.70, 449.55, 447.44, 445.38, 443.36, 441.37, 439.43, 437.52, 435.64, 433.80, 432.00, 430.22, 428.47, 426.76, 425.07, 423.41, 421.78, 420.18, 418.60, 417.04, 415.51, 414.01, 412.52, 411.06, 409.62, 408.20, 406.80, 405.42, 404.06, 402.72, 401.39, 400.09, 398.80, 397.53, 396.27, 395.03, 393.81, 392.60, 391.41, 390.23, 389.07, 387.92, 386.78, 385.66, 384.55, 383.46, 382.37, 381.30, 380.24, 379.19, 378.16, 377.13, 376.12, 375.11, 374.12, 373.14, 372.17, 371.21, 370.25, 369.31, 368.38, 367.45, 366.54, 365.63, 364.73, 363.84, 362.96, 362.09, 361.23, 360.37, 359.52, 358.68, 357.85, 357.02, 356.20, 355.39, 354.58, 353.79, 353.00, 352.21, 351.43, 350.66, 349.90, 349.14, 348.39, 347.64, 346.90, 346.16, 345.44, 344.71, 343.99, 343.28, 342.58, 341.87, 341.18, 340.49, 339.80, 339.12, 338.45, 337.77, 337.11, 336.45, 335.79, 335.14, 334.49, 333.85, 333.21, 332.57, 331.94, 331.32, 330.70, 330.08, 329.47, 328.86, 328.25, 327.65, 327.05, 326.46, 325.87, 325.28, 324.70, 324.12, 323.55, 322.97, 322.40, 321.84, 321.28, 320.72, 320.16, 319.61, 319.06, 318.52, 317.98, 317.44, 316.90, 316.37, 315.84, 315.31, 314.79, 314.27, 313.75, 313.23, 312.72, 312.21, 311.70, 311.20, 310.70, 310.20, 309.70, 309.21, 308.71, 308.23, 307.74, 307.26, 306.77, 306.29, 305.82, 305.34, 304.87, 304.40, 303.93, 303.47, 303.01, 302.55, 302.09, 301.63, 301.18, 300.72, 300.27, 299.83, 299.38, 298.94, 298.49, 298.05, 297.62, 297.18, 296.75, 296.32, 295.89, 295.46, 295.03, 294.61, 294.18, 293.76, 293.34, 292.93, 292.51, 292.10, 291.68, 291.27, 290.87, 290.46, 290.05, 289.65, 289.25, 288.85, 288.45, 288.05, 287.65, 287.26, 286.87, 286.48, 286.09, 285.70, 285.31, 284.93, 284.54, 284.16, 283.78, 283.40, 283.02, 282.65, 282.27, 281.90, 281.52, 281.15, 280.78, 280.41, 280.05, 279.68, 279.32, 278.95, 278.59, 278.23, 277.87, 277.51, 277.15, 276.80, 276.44, 276.09, 275.74, 275.39, 275.04, 274.69, 274.34, 273.99, 273.65, 273.30, 272.96, 272.62, 272.28, 271.94, 271.60, 271.26, 270.92, 270.59, 270.25, 269.92, 269.59, 269.25, 268.92, 268.59, 268.26, 267.94, 267.61, 267.28, 266.96, 266.64, 266.31, 265.99, 265.67, 265.35, 265.03, 264.71, 264.39, 264.08, 263.76, 263.45, 263.13, 262.82, 262.51, 262.20, 261.89, 261.58, 261.27, 260.96, 260.65, 260.34, 260.04, 259.73, 259.43, 259.13, 258.82, 258.52, 258.22, 257.92, 257.62, 257.32, 257.02, 256.73, 256.43, 256.14, 255.84, 255.55, 255.25, 254.96, 254.67, 254.38, 254.08, 253.79, 253.51, 253.22, 252.93, 252.64, 252.35, 252.07, 251.78, 251.50, 251.21, 250.93, 250.65, 250.37, 250.08, 249.80, 249.52, 249.24, 248.96, 248.68, 248.41, 248.13, 247.85, 247.58, 247.30, 247.03, 246.75, 246.48, 246.20, 245.93, 245.66, 245.39, 245.12, 244.84, 244.57, 244.31, 244.04, 243.77, 243.50, 243.23, 242.97, 242.70, 242.43, 242.17, 241.90, 241.64, 241.37, 241.11, 240.85, 240.59, 240.32, 240.06, 239.80, 239.54, 239.28, 239.02, 238.76, 238.50, 238.24, 237.99, 237.73, 237.47, 237.22, 236.96, 236.70, 236.45, 236.19, 235.94, 235.69, 235.43, 235.18, 234.93, 234.68, 234.42, 234.17, 233.92, 233.67, 233.42, 233.17, 232.92, 232.67, 232.42, 232.17, 231.93, 231.68, 231.43, 231.19, 230.94, 230.69, 230.45, 230.20, 229.96, 229.71, 229.47, 229.22, 228.98, 228.74, 228.49, 228.25, 228.01, 227.77, 227.53, 227.28, 227.04, 226.80, 226.56, 226.32, 226.08, 225.84, 225.60, 225.36, 225.13, 224.89, 224.65, 224.41, 224.18, 223.94, 223.70, 223.47, 223.23, 222.99, 222.76, 222.52, 222.29, 222.05, 221.82, 221.58, 221.35, 221.12, 220.88, 220.65, 220.42, 220.18, 219.95, 219.72, 219.49, 219.26, 219.03, 218.79, 218.56, 218.33, 218.10, 217.87, 217.64, 217.41, 217.18, 216.95, 216.72, 216.50, 216.27, 216.04, 215.81, 215.58, 215.35, 215.13, 214.90, 214.67, 214.45, 214.22, 213.99, 213.77, 213.54, 213.31, 213.09, 212.86, 212.64, 212.41, 212.19, 211.96, 211.74, 211.51, 211.29, 211.06, 210.84, 210.62, 210.39, 210.17, 209.95, 209.72, 209.50, 209.28, 209.05, 208.83, 208.61, 208.39, 208.17, 207.94, 207.72, 207.50, 207.28, 207.06, 206.84, 206.61, 206.39, 206.17, 205.95, 205.73, 205.51, 205.29, 205.07, 204.85, 204.63, 204.41, 204.19, 203.97, 203.75, 203.53, 203.31, 203.09, 202.88, 202.66, 202.44, 202.22, 202.00, 201.78, 201.56, 201.34, 201.13, 200.91, 200.69, 200.47, 200.25, 200.04, 199.82, 199.60, 199.38, 199.17, 198.95, 198.73, 198.51, 198.30, 198.08, 197.86, 197.65, 197.43, 197.21, 196.99, 196.78, 196.56, 196.34, 196.13, 195.91, 195.69, 195.48, 195.26, 195.04, 194.83, 194.61, 194.40, 194.18, 193.96, 193.75, 193.53, 193.31, 193.10, 192.88, 192.67, 192.45, 192.23, 192.02, 191.80, 191.59, 191.37, 191.15, 190.94, 190.72, 190.51, 190.29, 190.07, 189.86, 189.64, 189.43, 189.21, 188.99, 188.78, 188.56, 188.35, 188.13, 187.91, 187.70, 187.48, 187.27, 187.05, 186.83, 186.62, 186.40, 186.18, 185.97, 185.75, 185.54, 185.32, 185.10, 184.89, 184.67, 184.45, 184.24, 184.02, 183.80, 183.59, 183.37, 183.15, 182.93, 182.72, 182.50, 182.28, 182.07, 181.85, 181.63, 181.41, 181.20, 180.98, 180.76, 180.54, 180.32, 180.11, 179.89, 179.67, 179.45, 179.23, 179.01, 178.80, 178.58, 178.36, 178.14, 177.92, 177.70, 177.48, 177.26, 177.04, 176.82, 176.60, 176.38, 176.16, 175.94, 175.72, 175.50, 175.28, 175.06, 174.84, 174.62, 174.40, 174.18, 173.96, 173.73, 173.51, 173.29, 173.07, 172.85, 172.62, 172.40, 172.18, 171.96, 171.73, 171.51, 171.29, 171.06, 170.84, 170.61, 170.39, 170.17, 169.94, 169.72, 169.49, 169.27, 169.04, 168.81, 168.59, 168.36, 168.14, 167.91, 167.68, 167.46, 167.23, 167.00, 166.77, 166.55, 166.32, 166.09, 165.86, 165.63, 165.40, 165.17, 164.94, 164.71, 164.48, 164.25, 164.02, 163.79, 163.56, 163.33, 163.09, 162.86, 162.63, 162.40, 162.16, 161.93, 161.70, 161.46, 161.23, 160.99, 160.76, 160.52, 160.29, 160.05, 159.81, 159.58, 159.34, 159.10, 158.87, 158.63, 158.39, 158.15, 157.91, 157.67, 157.43, 157.19, 156.95, 156.71, 156.47, 156.22, 155.98, 155.74, 155.50, 155.25, 155.01, 154.76, 154.52, 154.27, 154.03, 153.78, 153.53, 153.29, 153.04, 152.79, 152.54, 152.29, 152.04, 151.79, 151.54, 151.29, 151.04, 150.79, 150.53, 150.28, 150.03, 149.77, 149.52, 149.26, 149.01, 148.75, 148.49, 148.24, 147.98, 147.72, 147.46, 147.20, 146.94, 146.68, 146.42, 146.15, 145.89, 145.63, 145.36, 145.10, 144.83, 144.56, 144.30, 144.03, 143.76, 143.49, 143.22, 142.95, 142.68, 142.41, 142.13, 141.86, 141.59, 141.31, 141.04, 140.76, 140.48, 140.20, 139.92, 139.64, 139.36, 139.08, 138.80, 138.51, 138.23, 137.95, 137.66, 137.37, 137.08, 136.79, 136.50, 136.21, 135.92, 135.63, 135.34, 135.04, 134.74, 134.45, 134.15, 133.85, 133.55, 133.25, 132.95, 132.64, 132.34, 132.03, 131.73, 131.42, 131.11, 130.80, 130.49, 130.17, 129.86, 129.54, 129.23, 128.91, 128.59, 128.27, 127.94, 127.62, 127.29, 126.97, 126.64, 126.31, 125.98, 125.65, 125.31, 124.98, 124.64, 124.30, 123.96, 123.62, 123.27, 122.93, 122.58, 122.23, 121.88, 121.53, 121.17, 120.81, 120.46, 120.09, 119.73, 119.37, 119.00, 118.63, 118.26, 117.89, 117.51, 117.13, 116.75, 116.37, 115.99, 115.60, 115.21, 114.82, 114.42, 114.03, 113.63, 113.22, 112.82, 112.41, 112.00, 111.59, 111.17, 110.75, 110.33, 109.90, 109.47, 109.04, 108.60, 108.16, 107.72, 107.27, 106.82, 106.37, 105.91, 105.45, 104.98, 104.51, 104.04, 103.56, 103.07, 102.59, 102.09, 101.60, 101.09, 100.59, 100.08, 99.56, 99.04, 98.51, 97.97, 97.43, 96.89, 96.33, 95.78, 95.21, 94.64, 94.06, 93.47, 92.88, 92.28, 91.67, 91.05, 90.42, 89.79, 89.14, 88.49, 87.82, 87.15, 86.46, 85.77, 85.06, 84.34, 83.61, 82.87, 82.11, 81.34, 80.55, 79.75, 78.93, 78.09, 77.24, 76.36, 75.47, 74.56, 73.62, 72.66, 71.68, 70.67, 69.63, 68.56, 67.46, 66.33, 65.15, 63.94, 62.68, 61.38, 60.02, 58.61, 57.14, 55.60, 53.98, 52.28, 50.48, 48.57, 46.53, 44.35, 42.00, 39.44, 36.64, 33.52, 29.99, 25.94, 21.12, 15.14, 7.13, 0.00 };


#endif