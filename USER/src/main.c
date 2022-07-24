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
	car_right_rgb_flash(green, 3, 287);
	pwm_jt();
	delay_1ms(100);
	car_stop();
}

void ren4(int p){
	int i,j,z;
	i = 25, j = 20, z=23;
	car_stop();
	car_both_rgb_on(red, 1000);
	car_turnright1();
	delay_1ms(320+i-(int)(p*0.05));
	pwm_jt();
	delay_1ms(100);
	car_stop();
	delay_1ms(50);
	
	car_forward();
	delay_1ms(510+j);
	car_stop();
	delay_1ms(50);
	
	car_turnleft1();
	delay_1ms(500+i+(int)(p*0.05)+z);
	pwm_jt1();
	delay_1ms(100);
	car_stop();
	delay_1ms(50);
	
	car_forward();
	delay_1ms(310+j-(int)(p*0.04));
	car_both_rgb_off();
	car_stop();
	delay_1ms(10);
	
	l9110s_backward(left, 1500);
	l9110s_backward(right, 1500);
	delay_1ms(150);
}
void ren5(){
	car_stop();
	car_turnleft1();
	car_left_rgb_flash(green, 3, 295);//000000
	pwm_jt1();
	delay_1ms(60);
	car_stop();
}
void ren6(int d){
	int i,j;
	if(d>=4000)i = 20, j = 55;
	else if(d>=3000)i = 35, j = 25;
	else if(d>=2000)i = 40, j = -5;
	else i = 50, j = -10;
	car_stop();
	car_both_rgb_on(red, 1000);
	car_turnleft1();
	delay_1ms(320+i);
	pwm_jt1();
	delay_1ms(100);
	car_stop();
	delay_1ms(50);
	
	car_forward();
	delay_1ms(510+j);
	car_stop();
	delay_1ms(50);
	
	car_turnright1();
	delay_1ms(503+i+10);
	pwm_jt();
	delay_1ms(100);
	car_stop();
	delay_1ms(50);
	
	car_forward();
	delay_1ms(310+j);
	car_both_rgb_off();
	car_stop();
	delay_1ms(10);
	
	l9110s_backward(left, 1500);
	l9110s_backward(right, 1500);
	delay_1ms(150);
}


  extern unsigned char g_reed_flag;

int main(void)
{
    /* 此处声明需要用到的局部变量 */
	
		int cibiao = 1, za = 1, out = 0;
	
		unsigned int distance_value = 0;
	
		int left_p, right_p, bs =7000, p, p_old = 0, p_old2 = 0, adc_value[3];
	
		int ren = 0, ren2 = 0, ren2_js = 0, ren3_b = 0, ren5_b = 0,b = 1;
	
		g_reed_flag = 0;
		
		float kp = 0, kd = 7.7, ks = 4.0;
		
		
    car_init();							//智能车初始化

				car_both_rgb_flash(white, 3, 400);
				//old2 = adc_mean_filter(ADC_CH_04,5);
				//adc_value[1] = 0;
				while(1){
					car_both_rgb_off();
					
					adc_value[0] = ((adc_mean_filter(ADC_CH_05,5)*1.0)/3500)*100;
					adc_value[2] = ((adc_mean_filter(ADC_CH_01,5)*1.0)/3500)*100;
					//adc_value[1] = adc_mean_filter(ADC_CH_04,5);
					
					//distance_value = ultra_get_distance();
					
					p = ((adc_value[0] - adc_value[2])*100)/(adc_value[0] + adc_value[2]+1);
					if(p>100) p=100;
					if(p<-100) p=-100;
					
					kp = 2 + (p*p*1.0)* 0.0036;
					
					if(b == 1){
						if(abs(p) >= 20){
							ks = 0.4;
						}
						else {
							ks = 0.9 - (abs(p)/(40*1.0));
						}
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
					
					if(ren == 1){
						if(ren2 == 1){
							if(ren2_js > 10)ren2 = 0;
							if(ren2_js%5 == 0){
								car_both_rgb_on(yellow, 15);
							}
							ren2_js++;
							continue;
						}
						
						if(ren3_b == 1){
							l9110s_backward(left, 1500);
							l9110s_backward(right, 1500);
							delay_1ms(150);
							ren3();
							ren3_b = 0;
							ren = 0;
							kd = 25.5;
						}
					
						if(ren5_b == 1){
							l9110s_backward(left, 1500);
							l9110s_backward(right, 1500);
							delay_1ms(150);
							ren5();
							ren5_b = 0;
							ren = 0;
							continue;
						}
					}
				
					reed_check();
					if(g_reed_flag == 1){
						if(cibiao == 1){
							ren1();
							cibiao++;
							continue;
						}
						else if(cibiao == 2){
							ren2 = 1;
							ren = 1;
							cibiao++;
							continue;
						}
						else if(cibiao == 3){
							ren3_b = 1;
							ren = 1;
							cibiao++;
							continue;
						}
						else if(cibiao == 4){
							ren5_b = 1;
							ren = 1;
							cibiao++;
							ultra_init();
							continue;
						}
						else if(cibiao == 5){
							car_stop();
							return 0;
						}
					}
					
					if((cibiao == 4 && za == 1)||(cibiao == 5 && za == 2)){
						distance_value = ultra_get_distance();
						if(distance_value <=5300&&distance_value>=3400){
							b = 0;
							if(cibiao == 4)ks = 0.3;
							else ks = 0.4;
							continue;
						}
						else if(distance_value < 3400){
							if(za == 1){
								l9110s_backward(left, 1500);
								l9110s_backward(right, 1500);
								delay_1ms(370);
								int pp = ((adc_convert(ADC_CH_05) - adc_convert(ADC_CH_01))*100)/(adc_value[0] + adc_value[2]+1);
								ren4(pp);
								za++; 
								kd = 7.7;
								b = 1;
							}
							else if(za == 2){
								l9110s_backward(left, 1500);
								l9110s_backward(right, 1500);
								delay_1ms(235);
								int d = ultra_get_distance();
								ren6(d);
								za++;
								b = 0;
								ks = 0.5;
							}
						}
					}
					
					
				}
}
