#define A 3
#define B 5
#define C 6
#define D 7
#define E 8
#define F 9
#define G 10

#define s1 11
#define s2 12
#define s3 13
#define s4 2

int pines[]   = {A , B , C , D , E , F , G , s1 , s2 , s3 , s4 };
int estado[]  = {1 , 1 , 1 , 1 , 1 , 1 , 1 ,  0 ,  0 ,  0 ,  0 };

int binario[4]; 


//	pines[]	      A   B   C   D   E   F   G


int numCERO[]   = {0, 0, 0, 0, 0, 0, 1};
int numUNO[]    = {1, 0, 0, 1, 1, 1, 1};
int numDOS[]    = {0, 0, 1, 0, 0, 1, 0};
int numTRES[]   = {0, 0, 0, 0, 1, 1, 0};
int numCUATRO[] = {1, 0, 0, 1, 1, 0, 0};
int numCINCO[]  = {0, 1, 0, 0, 1, 0, 0};
int numSEIS[]   = {0, 1, 0, 0, 0, 0, 0};
int numSIETE[]  = {0, 0, 0, 1, 1, 1, 1};
int numOCHO[]   = {0, 0, 0, 0, 0, 0, 0};
int numNUEVE[]  = {0, 0, 0, 0, 1, 0, 0};

int numA[]      = {0, 0, 0, 1, 0, 0, 0};
int numB[]      = {0, 0, 0, 0, 0, 0, 0};
int numC[]      = {0, 1, 1, 0, 0, 0, 1};
int numD[]      = {0, 0, 0, 0, 0, 0, 1};
int numE[]      = {0, 1, 1, 0, 0, 0, 0};
int numF[]      = {0, 1, 1, 1, 0, 0, 0};

//int* numeros[] = {numUNO,numSIETE,numOCHO,numNUEVE};
int* numeros[] = {numCERO,numUNO,numDOS,numTRES,numCUATRO,numCINCO,numSEIS,numSIETE,numOCHO,numNUEVE,numA,numB,numC,numD,numE,numF};

void setup()
{
  	Serial.begin(9600);
  
  	for(int i = 0; i < (sizeof(pines)/sizeof(int)); i++)
    {
  		pinMode( pines[i] , estado[i]);
	} 
  
	Serial.println((sizeof(pines)/sizeof(int)));
}

void loop()
{
  	binario[3] = digitalRead(s1);
  	binario[2] = digitalRead(s2);
    binario[1] = digitalRead(s3);
    binario[0] = digitalRead(s4);

  	
  // 2^3  2^2  2^1  2^0
  //  8    4    2    1
  
  //  1    0    1    0   = 2
  //  8  + 0  + 2    0   = 10
	int dec = 0;
  	for(int i = 3; i >= 0; i--)
    {
      //pow => raiz   pow(base, expo)   ->  numero float
      //round()  -> redondeo arriba  7.6  => 8.0
      // (int) -> casteo   =>  (7.6 -> 7)   (8.0 -> 8)
      dec = dec + (binario[i] * (int)round(pow(2, i)));
    }
    Serial.println(dec);
  
  	for(int i = 0; i < 7; i++)
	{      
    	digitalWrite(pines[i], numeros[dec][i]);
  	}   
}