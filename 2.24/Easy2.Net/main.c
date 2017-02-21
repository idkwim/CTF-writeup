#include <stdio.h>
int main(void)
{
	int i;

	char StrangeString[]="9pMaVs5DxiOPGe8JETXYmg3lbudro6Qk1WLKwyhfnS4Iv0ABtjUCc7RZz2NFHqHv8VzYa5b1FMGNODW4kwX9L3hK6SqsTtyxoE0Z7fPJIgrCAQiljBuenRcp2dUmfgnCw4HPJRdXKIq31YNDZMS82OjA7eUxpozasVmykiQrTFLW6htGb9B0lEcvu5jxLaZdWYngAfKGNhzTcXQU7Jy9sFbp0eRI1ECrv23PSw846oH5MBVtlDiOqumkU0tnl9bVK4iB2LzZXy7PaCHcAI5pOsSfjgqkr1vuRTFEo8Dxmhw3QGdeJM6WYNgWYN9w4LuPjxJl1MhOkniQy8CBUXr6THaKDctEdb0Imp32VfFZGvAS5ezqsR7owj3J9fL8QY2kArXKgOEzmSdqHpcMsn1ahGWxCe7yPIlTuDRb6F40oZtiUBvV5NKfeROdEILJs5W6D1m4XFtH7YbwgrUConPuqQBcSxT092zljv8yMAGhpZN3akVi8vxekVPpYlsXDAujWoJEingTGf3mCh59LROt6cdUNMb41zH7Kr0yS2BIFZqawQ";
	int chicken[]={144,207,93,170,111,25,130,144,21,152,172,-3,113,164,-24,94,117,-25,173,106,77,169,119,15,135,127,9,111,123,-12,109,218,61,155,98,50,199,131,-2,168,205,75,169,164,24,139,116,95,127,113,71,102,141,-18,152,153,28,111,131,74,207,201,-21,174,155,74,138,164,-7,179,215,94,187,142,55,147,99,64,176,117,25,193,177,47,135,111,-5,108,137,-8,132,120};
	int egg[]={210,209,22,126,188,29,212,101,24,125,145,-22,180,134,-30,162,107,18,142,210,8,185,95,-23,221,123,54,183,180,39,103,145,57,141,181,56,141,138,-25,124,133};

	for(i=0;i<sizeof(chicken)/4;i++)
	{
		if(i%3==0)
			chicken[i]-=94;
		else if(i%3==1)
			chicken[i]-=95;
		else if(i%3==2)
			chicken[i]+=31;
	} //changeNum complete
	
	for(i=0;i<sizeof(chicken)/4;i++)
	{
		chicken[i]^=StrangeString[i+10];
	}

	for(i=sizeof(chicken)/4-1;i>=0;i--)
	{
		printf("%c",chicken[i]);
	}

	for(i=0;i<sizeof(egg)/4;i++)
	{
		if(i%3==0)
			egg[i]-=94;
		else if(i%3==1)
			egg[i]-=95;
		else if(i%3==2)
			egg[i]+=31;
	} //changeNum complete
	
	for(i=0;i<sizeof(egg)/4;i++)
	{
		egg[i]^=StrangeString[i+10];
	}

	for(i=sizeof(egg)/4-1;i>=0;i--)
	{
		printf("%c",egg[i]);
	}
	return 0;
}