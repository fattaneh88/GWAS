// N = 200 in the paper actually corresponds to N = 100 in the program, and all inputes are 0..100 when N = 100 in the program.
public int N = 100;
public int size = 10000;

void HWE_TEST()
{
    public int<4> threshold = 7;
	public int i;
	
	private int<15> B[size];
	private int<16> A[size],C[size];
	private int<16> M1[3*size];
	private int<8> M2[3*size];
	private int<49> S[size];
	private int<49> X1[4*size];
        private int<16> X2[4*size];
	smcinput(A,1,size);
	smcinput(B,1,size);
	smcinput(C,1,size);
	for(i = 0; i < size; i++)
	{
		M1[i] = 2*A[i] + B[i]; //N_A
		M1[size+i] = 2*C[i]+B[i];//N_a
		M1[2*size+i] = M1[i];//N_A
		M2[i] = M1[i]; //N_A
		M2[size+i] = M1[size+i];//N_a
		M2[2*size+i] = M1[size+i];//N_a
		A[i] = 4 * A[i] * N;//N_AA * N * 4
		B[i] = 2 * B[i] * N;// N_Aa * N * 2
		C[i] = 4 * C[i] * N;// N_aa * N * 4
		
	}
	for(i = 0; i < 3 * size; i++)
	[
		M1[i] = M1[i] * M2[i];
	]
	
	for(i = 0; i < size; i++)
	{
		X1[i] = A[i] - M1[i];
		X1[size+i] = C[i] - M1[size+i];
		X1[2*size+i] = B[i] - M1[2*size+i];
        X1[3*size+i] = M1[i];
        
        X2[i] = X1[i];
        X2[size+i] = X1[size+i];
        X2[2*size+i] = X1[2*size+i];
        X2[3*size+i] = M1[size+i];
	}
	
	for(i = 0; i < 4 * size; i++)
	[
		X1[i] = X1[i] * X2[i];
        ]
       
        for (i = 0; i < size; i++)
	{
        	X1[2*size+i] = 2*X1[2*size+i];
        	X1[3*size+i] = 4* N* threshold* X1[3*size+i];
	}

    for(i = 0; i < size; i++)
    {
        X2[i] = M1[size+i];
        X2[size+i] = M1[i];
        X2[2*size+i] = M1[2*size+i];
    }
    
    for(i = 0; i < 3 * size; i++)
    [
         X1[i] = X1[i] * X2[i];
    ]
        
	for(i = 0; i < size; i++)
	{
		S[i] = X1[i] + X1[size+i] + X1[2*size+i];
	}
   
    private int<1> output[size];
    for (i = 0; i < size; i++)
    [
        output[i] = (S[i] < X1[3*size+i]);
    ]

	smcoutput(output,1,size);
}

void main()
{
	HWE_TEST();	
}
