/*
 * button.c
 *
 *  Created on: Oct 28, 2022
 *      Author: ASUS
 */

#include "button.h"


int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;
int button4_flag = 0;
int button5_flag = 0;

//KeyReg trong qua trinh rung
int KeyReg0_1 = NORMAL_STATE;
int KeyReg1_1 = NORMAL_STATE;
int KeyReg2_1 = NORMAL_STATE;

//KeyReg cua qua trinh on dinh truoc day
int KeyReg3_1 = NORMAL_STATE;


//Thoi gian cua nhan de'
int TimerforKeyPRESS1 = 200;

int isButton1Pressed(){
	if (button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	else return 0;
}
//
void getKeyInput1(){
	KeyReg0_1 = KeyReg1_1;
	KeyReg1_1 = KeyReg2_1;
	KeyReg2_1 = HAL_GPIO_ReadPin(BUTTON1_GPIO_Port, BUTTON1_Pin);

	if (KeyReg0_1 == KeyReg1_1 && KeyReg1_1 == KeyReg2_1){

		if (KeyReg2_1 != KeyReg3_1){					//Nhan doi trang thai
			KeyReg3_1 = KeyReg2_1;
			if (KeyReg2_1 == PRESSED_STATE){			//Neu dang nhan
				button1_flag = 1;
			}
			else{									//Luc truoc thi nhan, bay gio dang tha ra
				button1_flag = 0;
				TimerforKeyPRESS1 = 200;				//khi release thi RESET nhan de 1 giay
													//neu nhan lai trong 1 giay thi tinh la nhan de
			}

		}
		else{										//Nhan de
			if(KeyReg2_1 == PRESSED_STATE){			// Neu dang nhan de
				TimerforKeyPRESS1--;
				if (TimerforKeyPRESS1 == 0){			// Nhan de thanh cong
					TimerforKeyPRESS1 = 100;			// Moi 1s nhan de thi RETURN button_flag 1 lan
					button1_flag = 1;
				}
			}
		}


	}

}




///////-------------------------------------------------------


//KeyReg trong qua trinh rung
int KeyReg0_2 = NORMAL_STATE;
int KeyReg1_2 = NORMAL_STATE;
int KeyReg2_2 = NORMAL_STATE;

//KeyReg cua qua trinh on dinh truoc day
int KeyReg3_2 = NORMAL_STATE;


//Thoi gian cua nhan de'
int TimerforKeyPRESS2 = 200;



int isButton2Pressed(){
	if (button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	else return 0;
}
//
void getKeyInput2(){
	KeyReg0_2 = KeyReg1_2;
	KeyReg1_2 = KeyReg2_2;
	KeyReg2_2 = HAL_GPIO_ReadPin(BUTTON2_GPIO_Port, BUTTON2_Pin);


	if (KeyReg0_2 == KeyReg1_2 && KeyReg1_2 == KeyReg2_2){

		if (KeyReg2_2 != KeyReg3_2){					//Nhan doi trang thai
			KeyReg3_2 = KeyReg2_2;
			if (KeyReg2_2 == PRESSED_STATE){			//Neu dang nhan
				button2_flag = 1;
			}
			else{									//Luc truoc thi nhan, bay gio dang tha ra
				button2_flag = 0;
				TimerforKeyPRESS2 = 100;				//khi release thi RESET nhan de 1 giay
													//neu nhan lai trong 1 giay thi tinh la nhan de
			}

		}
		else{										//Nhan de
			if(KeyReg2_2 == PRESSED_STATE){			// Neu dang nhan de
				TimerforKeyPRESS2--;
				if (TimerforKeyPRESS2 == 0){			// Nhan de thanh cong
					TimerforKeyPRESS2 = 50;			// Moi 1s nhan de thi RETURN button_flag 1 lan
					button2_flag = 1;
				}
			}
		}


	}

}






///////////////////------------------------------







//KeyReg trong qua trinh rung
int KeyReg0_3 = NORMAL_STATE;
int KeyReg1_3 = NORMAL_STATE;
int KeyReg2_3 = NORMAL_STATE;

//KeyReg cua qua trinh on dinh truoc day
int KeyReg3_3 = NORMAL_STATE;


//Thoi gian cua nhan de'
int TimerforKeyPRESS3 = 200;



int isButton3Pressed(){
	if (button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	else return 0;
}
//
void getKeyInput3(){
	KeyReg0_3 = KeyReg1_3;
	KeyReg1_3 = KeyReg2_3;
	KeyReg2_3 = HAL_GPIO_ReadPin(BUTTON3_GPIO_Port, BUTTON3_Pin);


	if (KeyReg0_3 == KeyReg1_3 && KeyReg1_3 == KeyReg2_3){

		if (KeyReg2_3 != KeyReg3_3){					//Nhan doi trang thai
			KeyReg3_3 = KeyReg2_3;
			if (KeyReg2_3 == PRESSED_STATE){			//Neu dang nhan
				button3_flag = 1;
			}
			else{									//Luc truoc thi nhan, bay gio dang tha ra
				button3_flag = 0;
				TimerforKeyPRESS3 = 100;				//khi release thi RESET nhan de 1 giay
													//neu nhan lai trong 1 giay thi tinh la nhan de
			}

		}
		else{										//Nhan de
			if(KeyReg2_3 == PRESSED_STATE){			// Neu dang nhan de
				TimerforKeyPRESS3--;
				if (TimerforKeyPRESS3 == 0){			// Nhan de thanh cong
					TimerforKeyPRESS3 = 50;			// Moi 1s nhan de thi RETURN button_flag 1 lan
					button3_flag = 1;
				}
			}
		}


	}

}





//USER BUTTON
//KeyReg trong qua trinh rung
int KeyReg0_4 = NORMAL_STATE;
int KeyReg1_4 = NORMAL_STATE;
int KeyReg2_4 = NORMAL_STATE;

//KeyReg cua qua trinh on dinh truoc day
int KeyReg3_4 = NORMAL_STATE;

//Thoi gian cua nhan de'
int TimerforKeyPRESS4 = 200;

int isButton4Pressed(){
	if (button4_flag == 1){
		button4_flag = 0;
		return 1;
	}
	else return 0;
}
//
void getKeyInput4(){
	KeyReg0_4 = KeyReg1_4;
	KeyReg1_4 = KeyReg2_4;
	//KeyReg2_4 = HAL_GPIO_ReadPin(BUTTONUSER_GPIO_Port,BUTTONUSER_Pin);
	KeyReg2_4 = HAL_GPIO_ReadPin(B1_GPIO_Port,B1_Pin);


	if (KeyReg0_4 == KeyReg1_4 && KeyReg1_4 == KeyReg2_4){

		if (KeyReg2_4 != KeyReg3_4){					//Nhan doi trang thai
			KeyReg3_4 = KeyReg2_4;
			if (KeyReg2_4 == PRESSED_STATE){			//Neu dang nhan
				button4_flag = 1;
			}
			else{									//Luc truoc thi nhan, bay gio dang tha ra
				button4_flag = 0;
				TimerforKeyPRESS4 = 100;				//khi release thi RESET nhan de 1 giay
														//neu nhan lai trong 1 giay thi tinh la nhan de
			}

		}
		else{										//Nhan de
			if(KeyReg2_4 == PRESSED_STATE){			// Neu dang nhan de
				TimerforKeyPRESS4--;
				if (TimerforKeyPRESS4 == 0){			// Nhan de thanh cong
					TimerforKeyPRESS4 = 50;			// Moi 1s nhan de thi RETURN button_flag 1 lan
					button4_flag = 1;
				}
			}
		}


	}

}






