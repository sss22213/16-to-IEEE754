#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
int	hex_to_bin1(char);
int	main()
{	
	char a[616]="";	/*��J���r��*/ 		
	int	count_sum=0;	/*�@�X���*/ 
	int count_int=0;	/*��Ʀ��*/
	int	count_float=0;	/*�p�Ʀ��*/ 
	char all[616]="";		//�G�i�� 
	char al0[616]="";		//�G�i�� 
	char *point;			/*���p���I��m/���o���t��*/ 
	int	k=0;
	char int_to[308]="";	/*���*/
	char float_to[308]="";	/*�p��*/ 
	/*16_TO_10�ܼƫŧi*/
	double	sum_int=0.0;
	double	sum_float=0.0;
	double	sum=0.0;
	int	i=0;
	int	t=0;
	int	t1=0;
	/******************/
	/*10_TO_2�ܼƫŧi*/
	double	ten_int=0;
	double	ten_float=0.0;
	char	ten_string_int[308]="";
	char	ten_string_float[308]="";
	char	ten_string_int_01[308]="";
	int	int_mod=1;
	float float_mod=1.0;
	int ten001=0;
	/*****************/ 
	/*IEEE754���*/
	int	s=0;	//���t��S 
	int	E=0;	//E
	int	M=0;	//M
	/**/ 
	scanf("%s",&a);
	point=strstr(a,"-");
	if(point==NULL)
	{
		s=1;
	}
	else
	{
		s=0;
	point[0]='0';
	}
	count_sum=strlen(a); /*�����*/

	point=strstr(a,".");
	
	if(point==NULL)	/*�p�G�O���*/
	{
		count_int=count_sum;
		count_float=0;
		float_to[0]='0';
		strncpy(int_to,a,count_int);	/*�N��ƨ��X��*/ 
		
	}
	else
	{
		count_float=strlen(point)-1;
		count_int=count_sum-count_float-1;
		
		strncpy(int_to,a,count_sum-count_float-1);	/*�N��ƨ��X��*/ 
		strcpy(float_to,point+1);	/*�N�p�ƨ��X��*/ 
		
		
	}
	
	/*16_to_10�}�l�ഫ*/
	/*��Ƴ���*/
	for (i=0;i<count_int;i++)
	{
	
	sum_int=(hex_to_bin1(int_to[i]))*pow(16,count_int-i-1)+sum_int;
	
	}
	
	/*�p�Ƴ���*/
	for (i=0;i<count_float;i++)
	{
	
	sum_float=(hex_to_bin1(float_to[i]))*pow(16.0,(-1.0)*(i+1))+sum_float;
	
	}
	sum=sum_int+sum_float;	/*�Q�i��*/
	/*10_to_2�}�l�ഫ*/
	ten_int=floor(sum);
	ten_float=sum-ten_int;
	/*��Ƴ���*/ 
	ten001=(int)ten_int;
	
	while(ten001>0)
	{
		
		int_mod=ten001%2;
		
		ten001=(int)ten001/2;
		al0[k]=int_mod+'0';
		k++;
		
	}
	t=k;
	for(i=0;i<t;i++)
	{
		all[i]=al0[t-i-1];

	}
	E=k+127-1;
	/*�p�Ƴ���*/ 
	all[k]='.';
	for(i=0;i<51;i++)
	{
		k++;
		ten_float=ten_float*2;
		
		if(floor(ten_float)>0)
		{
			ten_float-=floor(ten_float);
			all[k]=1+'0';
		}
		else
		{
			all[k]=0+'0';
		}
		
		
		 
	}
	/*IEEE754�ഫ*/
	point=strstr(all,".");
	/*�ഫE*/
	
	printf("�G�i��Ʀr:%s\n",all);
	printf("IEEE754:\n");
	printf("S=%d\n",s);
	printf("E=%d\n",E);
	printf("M=%s\n",point+1);
	system("PAUSE");
} 

int hex_to_bin1(char hex1)
{
	int to_bin1=0;
	
	switch(hex1)
	{
		case 'A':
		to_bin1=10;
		break;
		case 'B':
		to_bin1=11;
		break;
		case 'C':
		to_bin1=12;
		break;
		case 'D':
		to_bin1=13;
		break;
		case 'E':
		to_bin1=14;
		break;
		case 'F':
		to_bin1=15;
		break;
		default:	to_bin1=hex1-'0';
		break;
	}
	return	to_bin1;	
	
	
}


