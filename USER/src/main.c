#include "main.h"
#include "headfile.h"
int abs(int a){
	if(a>=0){
		return a;
	}
	else{
		return -a;
	}
}

void pwm_jt(){
		l9110s_backward(left, 1500);
		l9110s_forward(right, 1500);
}
void pwm_jt1(){
		l9110s_backward(right, 1500);
		l9110s_forward(left, 1500);
}

void ren1(){
	car_stop();
	car_both_rgb_on(red, 1000);
	car_both_rgb_on(green, 500);
	car_both_rgb_off();
}

void ren3(){
	car_stop();
	car_turnright1(); 
	car_right_rgb_flash(green, 3, 390);
	pwm_jt();
	delay_1ms(150);
	car_stop();
}

void ren4(){
	car_stop();
	car_both_rgb_on(red, 1000);
	car_turnright1();
	delay_1ms(600);
	car_forward();
	delay_1ms(600);
	car_stop();
	car_turnleft1();
	delay_1ms(600);
	car_stop();
	car_turnright1();
	delay_1ms(600);
	car_stop();
	car_both_rgb_off();
}
void ren5(){
	car_stop();
	car_turnleft1();
	car_left_rgb_flash(green, 3, 400);
	pwm_jt1();
	delay_1ms(150);
	car_stop();
}
void ren6(void){
	car_stop();
	car_both_rgb_on(red, 1000);
	car_turnleft1();
	delay_1ms(600);
	car_forward();
	delay_1ms(600);
	car_stop();
	car_turnright1();
	delay_1ms(600);
	car_stop();
	car_turnleft1();
	delay_1ms(600);
	car_stop();
	car_both_rgb_off();
}



  extern unsigned char g_reed_flag;

int main(void)
{
    /* 此处声明需要用到的局部变量 */
	
		int cibiao = 1, za = 1, distance_value, out = 0;
	
		int left_p, right_p, bs = 6200, p, p_old = 0, p_old2 = 0, old2 = 0, adc_value[3], last = 0;
	
		int ren = 0, ren2 = 0, ren2_js = 0, ren3_b = 0, ren3_js = 0 , ren5_b = 0, ren5_js = 0;
	
		g_reed_flag = 0;
		
		float kp = 0, kd = 0, ks = 1.0;
		
		
    car_init();							//智能车初始化

				car_both_rgb_flash(white, 3, 400);
				//old2 = adc_mean_filter(ADC_CH_04,5);
				//adc_value[1] = 0;
				while(1){
					car_both_rgb_off();
					
					adc_value[0] = ((adc_mean_filter(ADC_CH_05,5)*1.0)/4095)*100;
					adc_value[2] = ((adc_mean_filter(ADC_CH_01,5)*1.0)/4095)*100;
					//adc_value[1] = adc_mean_filter(ADC_CH_04,5);
					
					//distance_value = ultra_get_distance();
					
					p = ((adc_value[0] - adc_value[2])*100)/(adc_value[0] + adc_value[2]+1);
					if(p>100) p=100;
					if(p<-100) p=-100;
					
						kp = 1.0 + (p*p*1.0)* 0.0036;
					
					
					if(abs(p) >= 20){
						ks = 0.4;
					}
					else {
						ks = 1.0 - (abs(p)/(40*1.0));
					}
					
					if(abs(p) >= 6){ 
						kd = 1.8;
					}
					else {
						kd = 5.0;
					}
					
					out = (kp * p + kd * (p*1.0 - (p_old*0.7 + p_old2*0.3)))*50;
					
					left_p=bs - out;
					right_p=bs + out;
					p_old2 = p_old;
					p_old = p;
					
					if(left_p>10000)left_p = 10000;
					if(left_p<0)left_p = 0;
					if(right_p>10000)right_p = 10000;
					if(right_p<0)right_p = 0;
				
					l9110s_forward(left, (int)(left_p * ks));
					l9110s_forward(right, (int)(right_p * ks));
					
				/*
				if(ren == 1){
					if(ren2 == 1){
						if(ren2_js > 10)ren2 = 0;
						if(ren2_js%5 == 0){
							car_both_rgb_on(yellow, 10);
						}
						ren2_js++;
						continue;
					}
					
					if(ren3_b == 1){
						if(ren3_js > 9){
							l9110s_backward(left, 1500);
							l9110s_backward(right, 1500);
							delay_1ms(150);
							ren3();
							ren3_b = 0;
						}
						else ren3_js++;
						continue;
					}
					
					if(ren5_b == 1){
						if(ren5_js > 9){
							l9110s_backward(left, 1500);
							l9110s_backward(right, 1500);
							delay_1ms(170);
							ren5();
							ren5_b = 0;
						}
						else ren5_js++;
						continue;
					}
					ren = 0;
				}
				
					reed_check();
				
					if(g_reed_flag == 1){
						if(cibiao == 1){
							ren1();
							cibiao++;
						}
						else if(cibiao == 2){
							ren2 = 1;
							ren = 1;
							cibiao++;
						}
						else if(cibiao == 3){
							ren3_b = 1;
							ren = 1;
							cibiao++;
						}
						else if(cibiao == 4){
							ren5_b = 1;
							ren = 1;
							cibiao++;
						}
						else if(cibiao == 5){
							car_stop();
							return 0;
						}
					}
					if(0){
						if(za == 1){
							ren4();
							za++; 
						}
						else if(za == 2){
							ren6();
							za++;
						}
					}
					*/
					
				}
}
